#!/usr/bin/env python

import gzip
import json
import os
import shutil
import time

lttng_rotate='lttng rotate\n'
snapshot_start='lttng snapshot record\n'
snapshot_stop='lttng stop\nlttng start\n'
get_time_nano='date +"%T.%9N"'
oldtime = 0
check='True'

def OpenTraceFile(file_path, mode):
  if file_path.endswith('.gz'):
    return gzip.open(file_path, mode + 'b')
  else:
    return open(file_path, mode + 't')

def FindJank(filename):
  with OpenTraceFile(filename, 'r') as f:
    data = json.loads(f.read().decode('utf-8'))
    # Find the browser main thread
    browser_main_thread = -1
    for event in data['traceEvents']:
      if event['ph'] == 'M':
        if (event['name'] == 'thread_name'
        and 'name' in event['args']
        and event['args']['name'] == "CrBrowserMain"):
          browser_main_thread = event['tid']
    if browser_main_thread == -1:
      return

   # Find jank on the main thread
    for event in data['traceEvents']:
        if 'tid' in event and event['tid'] == browser_main_thread and 'dur' in event and event['dur'] > 100000:
	  print "%s  ==  Event '%s' last '%d'" % (filename, event["name"], event["dur"])
	  if 'src_func' in event['args']:
	    print (event['args']['src_func'])
	  if 'src_file' in event['args']:
	    print (event['args']['src_file'])
	  os.system(get_time_nano)
  shutil.move(filename,'./bk')	    
while True:
    for root, dirs, files in os.walk("out"):
      if check == True:
          oldtime = time.time()
	  check = False
      for filename in files:
        FindJank(os.path.join(root, filename))
# checking if 5 seconds has been passed
      '''if time.time() - oldtime > 4:
          os.system(lttng_rotate)
	  check = True'''

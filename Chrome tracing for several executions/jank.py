#!/usr/bin/env python

import gzip
import json
import os
import shutil

snapshot_start='lttng snapshot record\n'
snapshot_stop='lttng stop\nlttng start\n'
get_time_nano='date +"%T.%9N"'

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
        os.system(snapshot_start)
	os.system(get_time_nano)
        print "%s  ==  Event '%s' last '%d'" % (filename, event["name"], event["dur"])
        os.system(snapshot_stop)
  shutil.move(filename,'./bk')	    
while True:
    for root, dirs, files in os.walk("out"):  
      for filename in files:
        FindJank(os.path.join(root, filename))

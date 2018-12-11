import argparse
import BaseHTTPServer
import cgi
import os
import socket
import SocketServer
import uuid

PORT = 8080
TRACE_FIELD = 'trace'

class HTTPUploadHandler(BaseHTTPServer.BaseHTTPRequestHandler):

  def do_POST(self):
    form = cgi.FieldStorage(
            fp=self.rfile,
            headers=self.headers,
            environ={'REQUEST_METHOD':'POST',
                     'CONTENT_TYPE':self.headers['Content-Type'],
                     })

    if not form.has_key(TRACE_FIELD):
      print 'Received POST without trace; dropping request.'
      return

    fileitem = form[TRACE_FIELD]
    if not fileitem.file:
      print 'Received empty trace; dropping request.'
      return

    trace_uuid = str(uuid.uuid4())

    output_file = os.path.join(self.server.output_path, '%s.gz' % trace_uuid)
    print 'Receiving %s...' % output_file
    with open(output_file, 'wb') as file:
      while True:
          chunk = fileitem.file.read(100000)
          if not chunk:
            break
          file.write(chunk)

    self.send_header('Content-type', 'text/json')
    self.send_response(200, 'OK')
    self.end_headers()
    print 'Done.'

def Main():
  parser = argparse.ArgumentParser(description='Receive traces')
  parser.add_argument('output_path', help='Output path')
  args = parser.parse_args()

  output_path = os.path.abspath(args.output_path)

  httpd = BaseHTTPServer.HTTPServer(('', PORT), HTTPUploadHandler)
  httpd.output_path = output_path

  print "Listening at port %s" % PORT
  try:
      httpd.serve_forever()
  except KeyboardInterrupt:
      pass

if __name__ == '__main__':
  Main()

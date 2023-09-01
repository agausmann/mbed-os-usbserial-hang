# pip install pyserial
import serial
from serial.tools import list_ports
import time

# USB VID:PID 1f00:2012
ports = list(list_ports.grep('1f00:2012'))
print(ports)

conn = serial.Serial(ports[0].device)
conn.timeout = 1
i = 0
while True:
    conn.write(b'a')

    # "Read until an expected sequence is found  ... or until timeout occurs.
    # If a timeout is set it may return fewer characters than requested"
    buf = conn.read_until(b'\n')

    if not buf.endswith(b'\n'):
        print('TIMEOUT')
        
    print(i, buf)
    i += 1
    time.sleep(0.1)

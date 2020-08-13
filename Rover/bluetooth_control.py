#!/usr/bin/env python3
import time
import bluetooth

print("Searching for devices...")

#Create an array with all the MAC
#addresses of the detected devices
nearby_devices = bluetooth.discover_devices()
"""

print("Searching for devices...")

#Create an array with all the MAC
#addresses of the detected devices
nearby_devices = bluetooth.discover_devices()
#Run through all the devices found and list their name
num = 0
print ("Select your device by entering its coresponding number...")
for i in nearby_devices:
    num+=1
    print("{}: {}".format(num,bluetooth.lookup_name( i )))

#Allow the user to select their Arduino
#bluetooth module. They must have paired
#it before hand.
selection = int(input("> ")) - 1
print ("You have selected {} ({})".format(bluetooth.lookup_name(nearby_devices[selection]), nearby_devices[selection]))
bd_addr = nearby_devices[selection]
"""
bd_addr = "00:13:EF:00:7B:13"
port = 1

sock = bluetooth.BluetoothSocket( bluetooth.RFCOMM )
sock.connect((bd_addr, port))

while True:
    command = input("> ")
    command = command.strip()
    if command == 'q':
        break
    sock.send(command)

sock.close()
print("All done")


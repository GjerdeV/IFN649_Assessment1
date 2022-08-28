import paho.mqtt.client as mqtt
import serial
import time
import string

ser = serial.Serial("/dev/rfcomm0", 9600)

# Function for connecting to the client and subscribing for a specifc
# topic.
def on_connect(client, userdata, flags, rc): # func for making connection
	print("Connected to MQTT")
	print("Connection returned result: " + str(rc) )
	client.subscribe("test")

# Function for sending message payload. Currently, when the LED_ON command
# is sent, the sensor's measurement will come in simultanously
def on_message(client, userdata, msg):
	print(msg.topic+" "+str(msg.payload))
	print(msg.payload.decode('UTF-8'))
	print(msg.payload.decode('UTF-8') == "LED_ON")
	print(msg.payload.decode('UTF-8') == "LED_OFF")
	if msg.payload.decode('UTF-8') == "LED_ON":
		ser.write(str.encode("LED_ON"))
		rawserial = ser.readline()
		cookedserial = rawserial.decode('utf-8').strip('\r\n')
		print(cookedserial)
	else:
		ser.write(str.encode("LED_OFF"))
	

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

client.connect("13.211.202.230", 1883, 60)

client.loop_forever()


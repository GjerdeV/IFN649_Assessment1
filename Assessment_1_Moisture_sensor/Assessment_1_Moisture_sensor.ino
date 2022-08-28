/* Analog Input Example, Teensyduino Tutorial #4
   http://www.pjrc.com/teensy/tutorial4.html

   After uploading this to your board, use Serial Monitor
   to view the message.  When Serial is selected from the
   Tools > USB Type menu, the correct serial port must be
   selected from the Tools > Serial Port AFTER Teensy is
   running this code.  Teensy only becomes a serial device
   while this code is running!  For non-Serial types,
   the Serial port is emulated, so no port needs to be
   selected.

   This example code is in the public domain.
*/

const int ledPin =11;
const int soilPin = 21;

void setup()
{                
  Serial.begin(38400);
  Serial1.begin(9600); 
  pinMode(LEDPIN, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

int val;

void loop()                     
{
  val = analogRead(soilPin);
  Serial.print("analog 0 is: ");
  Serial.println(val);
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(100);
}

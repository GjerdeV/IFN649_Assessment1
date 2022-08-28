const int soilPin = 21;
int ledPin = 11;

void setup()
{                
  //Serial.begin(38400);
  Serial.begin(9600);
  Serial1.begin(9600); 
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

int val;

void loop()                     
{
    String str = Serial1.readString().substring(0); 
    Serial.println(str);

    // Sending commands to turn on or off the LED
    if(str == "LED_ON"){
      digitalWrite(ledPin, HIGH);
      Serial.println("LED ON");
    }
    else if(str == "LED_OFF"){
      digitalWrite(ledPin, LOW);
      Serial.println("LED OFF");
    }
    val = analogRead(soilPin);
    Serial.print("analog 0 is: ");
    Serial.println(val);
    Serial1.print("analog 0 is: ");
    Serial1.println(val);
    delay(2000);
}

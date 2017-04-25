int brightness = 0;
int fadeAmount = 35;
int counter = 0;
int ledPin1 = 11;
float pulse = 0.7;
bool check = false;

void setup() {
  Serial.begin(115200);
  Serial.println(".");
  Serial.println("..");
  Serial.println("...");
  Serial.println("....");
  Serial.println("...");
  Serial.println("..");
  Serial.println(".");
  Serial.println("PUOK Insegna for the win!");
  Serial.println(".");
  Serial.println("..");
  Serial.println("...");
  Serial.println("....");
  Serial.println("...");
  Serial.println("..");
  Serial.println(".");
  pinMode(ledPin1, OUTPUT);
  brightness = 255;
}



void loop() {
  analogWrite(ledPin1, 255);
if (check == true) {
   
  pulsa();
  }
 // Serial.println(brightness);
  while (Serial.available() > 0)  {
    char c = Serial.read();  
    if (c == 'c') {
      analogWrite(ledPin1, 0);
  delay(200);
      check = true;
    }
  }
}

void pulsa() {

  analogWrite(ledPin1, brightness);
  brightness = brightness - (fadeAmount * pulse);
  if (brightness <= 10 && counter == 0) {
    brightness = 255 ;
    counter = 1;
    fadeAmount = 5;
  }
  else if (brightness <= 1 && counter == 1) {
    delay(32 * 10);
    brightness = 255;
    counter = 0;
    fadeAmount = 35;
    check = false;
  }
  delay(2 * 10);

}



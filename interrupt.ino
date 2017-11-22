const byte ledPin = 8;
const byte interruptPin = 2; //(1 или 3)

volatile boolean state = true;

void setup() {
  pinMode(ledPin, OUTPUT);
  
  pinMode(interruptPin, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(interruptPin), Off, CHANGE );
  attachInterrupt(digitalPinToInterrupt(3), On, CHANGE );
  
  Serial.begin(9600);
  Serial.println("Init");
}

void loop() {
  if (state)
  {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);
  }
  else
  {
     digitalWrite(ledPin, LOW);
  }  
}

void Off() {  
  Serial.println("Прерывание: -");
  state = false;
}

void On() {  
  Serial.println("Прерывание: +");
  state = true;
}

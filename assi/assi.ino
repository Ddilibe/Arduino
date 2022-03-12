const int led1 = 13;
const int led2 = 12;
const int led3 = 11;
const int ldrpin = A0;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(ldrpin,INPUT);
}

void loop() {
  int ldrstatus = analogRead(ldrpin);
  // the next line is to chech whether our conditionals is wright or wrong
  // serial.println(ldrstatus);
  // The first conditional is mainly for high light intensity
  // It is going to return a 0 value 
  if (ldrstatus > 400){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  } 
  // The second conditionals is going to turn on one led
  else if ((ldrstatus > 200) && (ldrstatus < 401)){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  // The third conditional would turn on two led because it is dim
  else if ((ldrstatus > 100) && (ldrstatus < 201)){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  }
  // The last one would turn on all the lights because the ldr said it is dark
  else {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  }
}

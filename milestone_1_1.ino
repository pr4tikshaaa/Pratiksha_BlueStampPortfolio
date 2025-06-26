
const int flexPin = 26;
const int flexBuzzer = 33;
const int num = 10; // sampling every 10 data points

void setup() {
  Serial.begin(9600);
  pinMode(flexPin, INPUT);
  pinMode(flexBuzzer, OUTPUT);
}

void loop() {
  int sum = 0;
  for (int i = 0; i < num; i++) {
    sum += analogRead(flexPin);
    delay(10);
  }

  int flexADC = sum/num; // find average of values to determinee more accuratee data points

  if (flexADC < 620) { // threshold will be made more accurate in next milestone
    tone(flexBuzzer, 1000); // buzzer plays
  } else {
    noTone(flexBuzzer);
  }

  Serial.println(flexADC); // print values of flex sensor

  delay(500);
}
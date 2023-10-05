int ledPin = 13; // LED가 연결된 핀 (예: 13 핀)
char receivedChar;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    receivedChar = Serial.read();
    if (receivedChar == '1') {
      digitalWrite(ledPin, HIGH); // 스마트폰으로부터 '1'을 받으면 LED를 켭니다.
    } else if (receivedChar == '0') {
      digitalWrite(ledPin, LOW); // 스마트폰으로부터 '0'을 받으면 LED를 끕니다.
    }
  }
}
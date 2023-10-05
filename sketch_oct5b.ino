int ledPin = 7; // LED가 연결된 핀 (예: 7 핀)
int speakerPin = 4; // 피에조 스피커가 연결된 핀 (예: 4 핀)
char receivedChar;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    receivedChar = Serial.read();
    if (receivedChar == '1') {
      digitalWrite(ledPin, HIGH); // 스마트폰으로부터 '1'을 받으면 LED를 켭니다.
    } else if (receivedChar == '0') {
      digitalWrite(ledPin, LOW); // 스마트폰으로부터 '0'을 받으면 LED를 끕니다.
    } else if (receivedChar >= '1' && receivedChar <= '8') {
      playNote(receivedChar - '0'); // '1'부터 '8'까지의 숫자를 받으면 해당 음을 재생합니다.
    }
  }
}

void playNote(int note) {
  // 음계와 해당 주파수 (Hz)를 매핑합니다.
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};

  int duration = 500; // 음을 재생할 시간 (밀리초)

  tone(speakerPin, frequencies[note - 1], duration);
  delay(duration + 50); // 재생이 끝날 때까지 대기
  noTone(speakerPin); // 스피커 중지
}
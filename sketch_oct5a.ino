#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "Your_SSID";         // 여기에 WiFi 네트워크 SSID를 입력하세요
const char* password = "Your_Password"; // 여기에 WiFi 네트워크 비밀번호를 입력하세요
const char* serverAddress = "http://your-server-address.com"; // 여기에 서버 주소를 입력하세요

const int switchPin = 2; // 스위치 연결 핀 (예: D2 핀)

void setup() {
  Serial.begin(115200);
  pinMode(switchPin, INPUT_PULLUP); // 내부 풀업 저항을 사용하여 스위치 핀 설정
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // 아두이노 코드의 루프에서 1초에 1회씩 스위치 상태를 서버로 전송
  // 이 코드를 원하는 동작에 맞게 수정할 수 있습니다.
}

void loop() {
  int switchState = digitalRead(switchPin);
  Serial.print("Switch State: ");
  Serial.println(switchState);

  if (switchState == HIGH) {
    // 스위치가 눌려져 있지 않은 상태
    // 서버로 0을 전송할 수 있습니다.
    // HTTP POST 요청을 사용하여 서버로 데이터를 전송하는 코드를 여기에 추가하세요.
  } else {
    // 스위치가 눌려져 있는 상태
    // 서버로 1을 전송할 수 있습니다.
    // HTTP POST 요청을 사용하여 서버로 데이터를 전송하는 코드를 여기에 추가하세요.
  }

  delay(1000); // 1초에 1번만 전송하도록 대기
}
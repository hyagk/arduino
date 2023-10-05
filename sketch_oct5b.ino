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
//App Inventor 컴포넌트:

Web 컴포넌트: 서버와 통신하기 위한 웹 컴포넌트입니다.
Notifier 컴포넌트: 화면에 알림을 표시하기 위한 컴포넌트입니다.
Screen 컴포넌트: 앱의 화면을 관리하기 위한 컴포넌트입니다.
App Inventor 블록 코드:

앱의 초기화 작업을 위한 블록:

Web.Initialize 블록: 웹 컴포넌트 초기화.
Web.GotText 이벤트 블록: 서버로부터 데이터를 받을 때 호출되는 이벤트 핸들러.
Screen.Initialize 블록: 화면 초기화.
웹 컴포넌트를 사용하여 서버로부터 데이터를 받고, 받은 데이터에 따라 화면의 색을 변경하는 블록:

Web.Get 블록: 서버에서 데이터 가져오기. 서버 주소와 엔드포인트를 설정하세요.
Web.GotText 이벤트 블록: 서버로부터 데이터를 성공적으로 받았을 때 호출되는 이벤트 핸들러입니다. 이 블록에서 서버로부터 받은 데이터를 파싱하고, 데이터에 따라 화면의 배경 색을 변경합니다.
Screen.BackgroundColor 블록: 화면의 배경 색상 변경.
서버로 데이터를 요청하는 블록:

Button.Click 이벤트 블록: 화면에서 버튼을 클릭할 때, 서버에 데이터를 요청하기 위한 블록입니다. Web.Get 블록을 사용하여 서버로 데이터를 요청합니다.
알림을 사용하여 사용자에게 결과를 표시하는 블록:

Notifier.ShowMessageDialog 블록: 서버로부터 받은 데이터를 기반으로 사용자에게 결과를 알림으로 표시합니다.

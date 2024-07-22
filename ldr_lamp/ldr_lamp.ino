/*
 * Author: JuwonBang(github.com/apwlq)
 * Description: 아두이노 코드 - LDR(광저항) 값을 읽어 LED를 제어합니다.
 */

#define LDR_ON_THRESHOLD  250  // LDR 값이 켜질 임계값 설정
#define LDR_OFF_THRESHOLD 200  // LDR 값이 꺼질 임계값 설정

int ldrValue = 0;      // LDR 센서의 값을 저장할 변수
int ledState = 0;      // LED의 상태를 저장할 변수 (켜짐/꺼짐)

// 설정 함수, 프로그램 시작 시 호출됨
void setup() {
  pinMode(12, OUTPUT);     // 핀 12를 출력으로 설정 (LED 제어)
  pinMode(A0, INPUT_PULLUP); // 아날로그 핀 A0을 입력으로 설정, 내부 풀업 저항 활성화
}

void loop() {
  ldrValue = analogRead(A0);  // 아날로그 핀 A0에서 LDR 값을 읽어와 ldrValue에 저장
  
  // LDR 값에 따라 LED 상태를 설정
  if (ldrValue < LDR_OFF_THRESHOLD) {
    ledState = 0;  // LDR 값이 꺼질 임계값 이하이면 LED OFF
  } else if (ldrValue > LDR_ON_THRESHOLD) {
    ledState = 1;  // LDR 값이 켜질 임계값 이상이면 LED ON
  }

  // LED 상태에 따라 핀 12의 출력을 설정
  digitalWrite(12, ledState == 1 ? HIGH : LOW); // 삼항 연산자를 사용해 LED 상태 설정

  delay(50);  // 50ms 대기
}

#include <Keypad.h>
#include <Servo.h>   

Servo servo_motor;

int LED_pin=12;
  
const byte ROWS = 4;    // 행(rows) 개수
const byte COLS = 4;    // 열(columns) 개수
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
 
byte rowPins[ROWS] = {6, 7, 8, 9};   // R1, R2, R3, R4 단자가 연결된 아두이노 핀 번호
byte colPins[COLS] = {5, 4, 3, 2};   // C1, C2, C3, C4 단자가 연결된 아두이노 핀 번호
 
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
 
void setup() {
  Serial.begin(9600);
  servo_motor.attach(10); 
  (LED_pin,OUTPUT);
}
  
void loop() {
  char key = keypad.getKey();
  
  if (key) {
    switch(key) {
      case 'A': 
        
        servo_motor.write(120);
        break;
      case 'B': 
        
        servo_motor.write(-360);
        break;

      case 'C':
      digitalWrite(LED_pin,HIGH);
      break;

      case 'D':
      digitalWrite(LED_pin,LOW);
      break;

      case '*':
       servo_motor.write(-120);
        break;
      
      default:
        Serial.println(key);
        break;
    }
  }
}

// A  B  C  D  E  F  G  P  
// 13 12 11 10 9  8  7  6  

byte segmente[10] = {
  B11111100,  // 0
  B01100000,  // 1
  B11011010,  // 2
  B11110010,  // 3
  B01100110,  // 4
  B10110110,  // 5
  B10111110,  // 6
  B11100000,  // 7
  B11111110,  // 8
  B11110110}; // 9

void disp_digit(int num){
  for (int i = 6; i < 14; i++){
    /* schreibe fuer auf jeden der Pins einen Wert. */
    /* der ternaere Operator ?: funktioniert so: s?a:b */
    /* s ist eine Boolscher Wert, wenn er wahr ist gib a zurueck */
    /* wenn nicht gib b zurueck */
    digitalWrite(i,bitRead(segmente[num],i - 6) == 1?HIGH:LOW);
  }
}

void setup() {
  // setze alle noetigen Pins auf output
  for (int i = 13; i > 5; i--){
    pinMode(i,OUTPUT);
  }
}

void loop(){
  for (int i = 0; i < 10; i++) {
    disp_digit(i);
    delay(500);
  }
}

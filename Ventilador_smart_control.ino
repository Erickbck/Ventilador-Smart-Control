#include <IRremote.h>
#include <IRremoteInt.h>

#define receptor 6
#define motorpino1 9
#define motorpino2 10
#define ledverd 2
#define ledverm 3

IRrecv receptorIR(receptor);
decode_results resultado;

void setup() {

  pinMode(motorpino1,OUTPUT);
  pinMode(motorpino2,OUTPUT);
  Serial.begin(9600);
  receptorIR.enableIRIn(); 

}

void loop() {
  if (receptorIR.decode(&resultado)){
      Serial.println(resultado.value,HEX);
    switch(resultado.value){
      case 0xFF6897:
      apaga();
      break;

      case 0xFF30CF:
      liga();
      break;
      
    }
    receptorIR.resume();
  }
}
  void liga(){
    digitalWrite(motorpino1,1);
    digitalWrite(motorpino2,0);
    digitalWrite(ledverd, HIGH);
    digitalWrite(ledverm, LOW);
  }

    void apaga(){
    digitalWrite(motorpino1,0);
    digitalWrite(motorpino2,0);
    digitalWrite(ledverm, HIGH);
    digitalWrite(ledverd, LOW);
    
  }


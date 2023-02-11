//variables and const
byte BTN1 = 2;
byte dato;
boolean btn1; 


void setup() {
  // devices intput data or output data
  pinMode(BTN1,INPUT);
  Serial.begin(9600);
}

void loop() {

  //code to put a status an button 
  if (digitalRead(BTN1) == 1) {
    if(!btn1){
      btn1 = true;
    }else{
      btn1 = false;
    }
  }
  delay(400);

  if (btn1) {
    dato = 2; 
  }else{
    dato = 0;
  }

  //print data
  Serial.println(dato);
  Serial.println(btn1);


}

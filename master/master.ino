int PIN_SCK = 19;
int PIN_SDA = 18;

const int delayvalue = 10;
uint8_t val;

void setup(){
  digitalRead(PIN_SCK);
  digitalRead(PIN_SDA);

  pinMode(PIN_SCK, INPUT); // then turn them on
  pinMode(PIN_SDA, INPUT);
  Serial.begin(9600);
  

  delay(1000);
}

void loop(){

  takevalue(PIN_SDA,PIN_SCK);
}

void takevalue(uint8_t datapin, uint8_t clockpin){

  uint8_t i;
 
  for (i = 0; i < 8; i++)  {

    if (clockpin == 0)
    val =((1 << (7 - i)) & digitalRead(datapin));
    }

  digitalWrite(PIN_SCK,0);
  Serial.println(val);
  
}

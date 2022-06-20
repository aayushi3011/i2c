int PIN_SCK = 19;
int PIN_SDA = 18;

const int delayvalue = 10;

void setup(){
    digitalWrite(PIN_SCK, 1); // I can first declare the state
    digitalWrite(PIN_SDA, 1);
    pinMode(PIN_SCK, OUTPUT); // then turn them on
    pinMode(PIN_SDA, OUTPUT);
    Serial.begin(9600);

    delay(1000);

    digitalWrite(PIN_SDA, 0); // start bit

    shift_out(PIN_SDA, PIN_SCK, 0x08);
    shift_out(PIN_SDA, PIN_SCK, 0xA9);

    digitalWrite(PIN_SDA, 1); // stop bit

}

void loop(){

}
// uint8_t is the same as 8 bits aka one byte
void shift_out(uint8_t datapin, uint8_t clockpin, uint8_t val){
    uint8_t i;

    for (i = 0; i < 8; i++)  {
        digitalWrite(datapin, !!(val & (1 << (7 - i))));
        delay(1);
        digitalWrite(clockpin, 0);
        delay(delayvalue);
        digitalWrite(clockpin, 1);
        delay(delayvalue);
    }

    digitalWrite(datapin, 0); // to enable stop bit
    delay(100); // wait fro aknowledgement

}

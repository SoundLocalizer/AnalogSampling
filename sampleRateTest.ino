#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))     //included for seting prescale to 16 resulting in 77khz cycle time for ADC conversion
#define sbi(sfr, bit)


int i = 0;
const int analogPin = A0;
int amplitude;

void setup() {
  // set prescale to 16
  sbi(ADCSRA,ADPS2) ;
  cbi(ADCSRA,ADPS1) ;
  cbi(ADCSRA,ADPS0) ;
  Serial.begin(9600);
}
    

void loop() {
  while(i<1000){
    amplitude = analogRead(analogPin); //read analog value from pin A0
    Serial.println(amplitude);  //print analog value read from A0
    i++;
  }
} 

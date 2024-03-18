//Begin - Led - 1 - second
int timer1_counter;
int flag=1;
int count=0;
int contor_global=0;

int return_globalcontor() 
{
  return contor_global;
}

ISR(TIMER0_COMPA_vect)        // interrupt service routine 
{
  //TCNT0 = timer1_counter;   // preload timer
  count++;
  if(count>2000)
  {
    contor_global++;
  if(flag==1)
  {
  PORTB|=0x08;

    flag=0;
  }
  else
  {
    PORTB&=~0x08;
    flag=1;
  }
  count=0;
  }
}//End - Led-1-second

//Begin - Citire A/S

#include <avr/io.h>      // Contains all the I/O Register Macros
#include <util/delay.h>  // Generates a Blocking Delay

#define USART_BAUDRATE 9600 // Desired Baud Rate
#define BAUD_PRESCALER (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

#define ASYNCHRONOUS (0<<UMSEL00) // USART Mode Selection

#define DISABLED    (0<<UPM00)
#define EVEN_PARITY (2<<UPM00)
#define ODD_PARITY  (3<<UPM00)
#define PARITY_MODE  DISABLED // USART Parity Bit Selection

#define ONE_BIT (0<<USBS0)
#define TWO_BIT (1<<USBS0)
#define STOP_BIT ONE_BIT      // USART Stop Bit Selection

#define FIVE_BIT  (0<<UCSZ00)
#define SIX_BIT   (1<<UCSZ00)
#define SEVEN_BIT (2<<UCSZ00)
#define EIGHT_BIT (3<<UCSZ00)
#define DATA_BIT   EIGHT_BIT  // USART Data Bit Selection

void USART_Init()
{
  // Set Baud Rate
  UBRR0H = BAUD_PRESCALER >> 8;
  UBRR0L = BAUD_PRESCALER;
  
  // Set Frame Format
  UCSR0C = ASYNCHRONOUS | PARITY_MODE | STOP_BIT | DATA_BIT;
  
  // Enable Receiver and Transmitter
  UCSR0B = (1<<RXEN0) | (1<<TXEN0);
}



void USART_TransmitPolling(uint8_t DataByte)
{
  while (( UCSR0A & (1<<UDRE0)) == 0) {}; // Do nothing until UDR is ready
  UDR0 = DataByte;
}

uint8_t USART_Receive()
{
  uint8_t DataByte;
  while (( UCSR0A & (1<<RXC0)) == 0) {}; // Do nothing until data have been received
  DataByte = UDR0 ;
  return DataByte;
}

//End - Citire A/S 

//Begin - PWM
int var=0;
//SEMNAL PWM NU MERGE
volatile unsigned char z;

 void init_timer1_PWM()
 {
  cli();
    TCCR1A |= (1<<COM1A1); //clear OCR1A on compare match
    TCCR1A |= (1<<WGM12) | (1<<WGM10); //fast PWM 8 bit
    TCCR1B |= (1<<CS11) | (1<<WGM12) ; //set prescaler value = 8
    OCR1A = 1; 
   
    DDRB |= 0x02;
    sei();
 }

int i;
//End - PWM

//Begin - Temperature
#include "DHT.h"

#define DHTPIN 13    // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);
//End - Temperature

//Begin - 7 segment
#include <ShiftRegister74HC595.h>
#define SDI 7
#define SCLK 6
#define LOAD 5
#define DIGITS 2
int var_old=0;
int cnt=0;
int k=0;
// create shift register object (number of shift registers, data pin, clock pin, latch pin)
ShiftRegister74HC595<1> sr (SDI, SCLK, LOAD); 


int value,digit1,digit2,digit3,digit4; 
uint8_t  digits[] = {
                      B1000111,//L
                      B1001000,//M
                      B0001100,//P
                      B0001000//R
                     };
                        
void showNumber(int num)
{
    digit2=num % 10 ;
    digit1=(num / 10) % 10 ;
    //Send them to 7 segment displays
    uint8_t numberToPrint[]= {digits[digit2],digits[digit1]};
  sr.setAll(numberToPrint);  
}
//End - 7 segment

void setup() 
{
  // Begin - Led - 1 - second
  count=0;
  cli();//stop interrupts
  DDRB|=0x08;
  //set timer0 interrupt at 2kHz
  TCCR0A = 0;// set entire TCCR0A register to 0
  TCCR0B = 0;// same for TCCR0B
  TCNT0  = 0;//initialize counter value to 0
  // set compare match register for 2khz increments
  OCR0A = 124;// = (16*10^6) / (2000*64) - 1 (must be <256)
  // turn on CTC mode
  TCCR0A |= (1 << WGM01);
  // Set CS01 and CS00 bits for 64 prescaler
  TCCR0B |= (1 << CS01) | (1 << CS00);   
  // enable timer compare interrupt
  TIMSK0 |= (1 << OCIE0A);
  sei();
  //End - Led - 1 - second

  //Begin - Citire A/S
  Serial.begin(9600);
  USART_Init();
    DDRB |= 0x04;
  //End - Citire A/S

  //Begin - Temperature
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
  //End - Temperature
}

void loop()
{
  //Begin - Citire A/S
  // Configuring PB5 / D13 as Output
  char LocalData;
    LocalData = USART_Receive();
    if (LocalData == 'A')
    {
      PORTB |= 0x04;    // Writing HIGH to glow LED
    }
    else if(LocalData=='S')
    {
      PORTB &= ~(0x04); // Writing LOW
    }
    //End - Citire A/S 

    //Begin - PWM
     for(z=0; z<253;z++){
    OCR1A = z;
    _delay_ms(4);
  }
  
  var=return_globalcontor();
  while(var==return_globalcontor())
  {
    OCR1A=z;
  }
   var=return_globalcontor();
  while(var==return_globalcontor())
  {
    OCR1A=z;
  }
  
  
  for(z=254; z>0;z--){
    OCR1A = z;
    _delay_ms(4);
  }

  var=return_globalcontor();
  while(var==return_globalcontor())
  {
    OCR1A=z;
  }
    //End - PWM

    //Begin - Temperature
     // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
  if(t >= 35)
    PORTB |= 0x01;
  else
    PORTB &=~(0x01);
    //End - Temperature

    //Begin - 7 segment
    if(return_globalcontor()!=var_old)
{
  var_old=return_globalcontor();
  if(cnt>6)
    cnt=0;
  showNumber(cnt);
  cnt++;
}
    //End - 7 segment
}

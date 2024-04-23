/* This program si designed to have a zero center meter moving back and forth as a variable rate
 *  when the pot is adjusted, the swing is changed.  When both sides of the meter have the same voltage,
 *  the meter stops swinging
 *  * an output will be pulsed on and off causing the meter too swing.
 *  * it will go through different rates
 *  

*/

const int meter_pin = 4;
const int loop_length = 20;
const int num_changes_in_speed = 5;
const int delay_time = 100;
const int delay_time_increment = 50;

void setup() 
{
  
  pinMode(meter_pin,OUTPUT);
  //Serial.begin(9600); // open the serial port at 9600 bps:
}

void loop() 
{
  int j = 0;
  int i = 0;
  for (j=0; j<num_changes_in_speed; j++)
  { 
  for (i=0; i<loop_length; i++)
    {
      digitalWrite(meter_pin, HIGH);
      delay(delay_time+j*delay_time_increment);
      digitalWrite(meter_pin, LOW);
      delay(1000);//delay_time+j*delay_time_increment);
    } // end i loop
  }  //  end j loop
  

}

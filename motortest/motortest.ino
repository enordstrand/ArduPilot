/*     Simple Stepper Motor Control Exaple Code
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */
// defines pins numbers
const int stepPin = 3; 
const int dirPin = 4; 
 
void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
}
void loop() {
  // 600 = No go
  // 700 = 53RPM (sliter litt)
  // 750 = 49RPM (bråker)
  // 777 = 48RPM
  // 800 = 46RPM
  // 900 = 41RPM
  int speed = 777;
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(speed); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(speed); 
  }
  delay(500); // One second delay

  digitalWrite(dirPin,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 2000; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(speed); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(speed); 
  }
  delay(500); // One second delay
}

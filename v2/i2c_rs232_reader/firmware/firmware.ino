#include <Wire.h>
// #define human 0x01
char data_buffer[255], i = 0;

void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  SerialUSB.begin(115200);  // start serial for output
}

void loop() {
  Wire.requestFrom(0x03,250);    // request 6 bytes from slave device #8
  i = 0x00;
  while (Wire.available()) { // slave may send less than requested
    data_buffer[i] = Wire.read(); // receive a byte as character
    /*SerialUSB.print(data_buffer[i],HEX);*/ 
    i++;
  }

#ifdef human
  SerialUSB.print(data_buffer[0],HEX);         // print the character
  SerialUSB.print(data_buffer[1],HEX);         // print the character
  SerialUSB.print(" ");
  if (data_buffer[2] < 0x10)
      SerialUSB.print('0');         // print the character
  SerialUSB.print(data_buffer[2],HEX);         // print the character
  SerialUSB.print(" ");
  for (i=3; i < data_buffer[2] + 5; i++)
  {
      if (data_buffer[i] < 0x10)
      {
          SerialUSB.print('0');         // print the character
      }
      SerialUSB.print(data_buffer[i],HEX);         // print the character
  }
  SerialUSB.print("\n\r");  
  
#endif
#ifndef human
  SerialUSB.print(data_buffer[0]);         // print the character
  SerialUSB.print(data_buffer[1]);         // print the character
  SerialUSB.print(data_buffer[2]);         // print the character
  for (i=3; i < data_buffer[2] + 5; i++)
  {
      SerialUSB.print(data_buffer[i]);         // print the character
  }
#endif  
  delay(30000);
}

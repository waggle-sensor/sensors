#ifdef ALPHASENSE_INCLUDE
void alphasense_on() 
{
    SPI.beginTransaction(set1);
    digitalWrite(PIN_ALPHASENSE_SLAVE, LOW);
    delay(100);

    val1 = SPI.transfer(0x03);
    delay(100);
    val2 = SPI.transfer(0x00);
    delay(100);
    
    digitalWrite(PIN_ALPHASENSE_SLAVE, HIGH);
    SPI.endTransaction();

#ifdef ALPHA_DEBUG
    SerialUSB.println("Powering OPC ON");
    SerialUSB.println(val1, HEX);
    SerialUSB.println(val2, HEX);
#endif
}

void alphasense_off()
{
    //** POWER OFF
    SPI.beginTransaction(set1);
    digitalWrite(PIN_ALPHASENSE_SLAVE, LOW);
    delay(100);

	val1 = SPI.transfer(0x03);
	delay(100);
    val2 = SPI.transfer(0x01);
    delay(100);

	digitalWrite(PIN_ALPHASENSE_SLAVE, HIGH);
    SPI.endTransaction();

#ifdef ALPHA_DEBUG
    SerialUSB.println("Powering OPC OFF");
    SerialUSB.println(val1, HEX);
    SerialUSB.println(val2, HEX);
#endif
}

void alphasense_serial()
{
    alpha_serial[1] = (1 << 7) | LENGTH_ALPHA_SERIAL;

    
    
    #ifdef ALPHA_DEBUG
    
    SPI.beginTransaction(set1);
    digitalWrite(PIN_ALPHASENSE_SLAVE, LOW);
    delay(100);
    
    SerialUSB.println("Serial Number String 60 Bytes:");
    
    SPI.transfer(0x10); 
    delay(100);
    
    
    for ( byte i = 0x00; i < 60; i ++ )
    {
        SerialUSB.write(SPI.transfer(0x10));
        delay(1);
    }
    
    SerialUSB.print("\n");
    
    
    
    digitalWrite(PIN_ALPHASENSE_SLAVE, HIGH);
    SPI.endTransaction();
    #endif
    
/*
    for (i = 0; i < 20; i++)
    {
        alpha_firmware[i + 2] = SPI.transfer(0x10);
        delay(100);
    }

   

#ifdef ALPHA_DEBUG
    SerialUSB.println("OPC FW:");
    for (i = 10; i < 20; i++)
        SerialUSB.write(alpha_firmware[i]);
    SerialUSB.println("");
#endif*/
}


#ifdef ALPHA_DEBUG
void alphasense_info_string()
{
    SPI.beginTransaction(set1);
    digitalWrite(PIN_ALPHASENSE_SLAVE, LOW);
    delay(100);
    
    SerialUSB.println("OPC Info String:");
    SPI.transfer(0x3F);  
    delay(100);

    for ( byte i = 0x00; i < 60; i ++ )
    {
        SerialUSB.write(SPI.transfer(0x3F));
        delay(1);
    }
    
    SerialUSB.println("");

    digitalWrite(PIN_ALPHASENSE_SLAVE, HIGH);
    SPI.endTransaction();
}

#endif



void alphasense_firmware()
{
    alpha_firmware[1] = (1 << 7) | LENGTH_ALPHA_FIRMWARE;

	//** Get firmware    
    SPI.beginTransaction(set1);
    digitalWrite(PIN_ALPHASENSE_SLAVE, LOW);
    delay(100);
    
    SPI.transfer(0x12);  
    delay(100);
    alpha_firmware[2] = SPI.transfer(0x12);
    delay(100);
    alpha_firmware[3] = SPI.transfer(0x12);
    delay(100);

    digitalWrite(PIN_ALPHASENSE_SLAVE, HIGH);
    SPI.endTransaction();

#ifdef ALPHA_DEBUG
    SerialUSB.println("OPC FW Version:");
    SerialUSB.print(alpha_firmware[0], HEX);
    SerialUSB.print(" ");
    SerialUSB.println(alpha_firmware[1], HEX);
#endif
}


void alphasense_histo()
{
    unsigned int checksum = 0;
    byte data_this;
    
    alpha_histogram[1] = (1 << 7) | LENGTH_ALPHA_HISTOGRAM;

    SPI.beginTransaction(set1);
    digitalWrite(PIN_ALPHASENSE_SLAVE, LOW);
    delay(100);

    SPI.transfer(0x30);  
    delay(10);
    SerialUSB.print("Bins: ");
    for (byte i = 0x00; i < 62; i++)
    {
        data_this = SPI.transfer(0x30);
        SerialUSB.print(data_this, HEX);
        SerialUSB.print(" ");
        delay(1);
        
//         data_this = SPI.transfer(0x30);
//         checksum = checksum + data_this;
//         if(i == 35)
//         {
//             SerialUSB.println(checksum & 0xffff, HEX);   
//         }
//         SerialUSB.print(i+1, DEC);
//         SerialUSB.print(" : ");
//         SerialUSB.print(data_this, HEX);
//         if ( i % 5 == 0)
//         {
//             SerialUSB.println("");
//             
//         }
//         
//         else 
//         {
//             SerialUSB.print(" ; ");   
//         }
//         
//         delay(1);
    }
    

    digitalWrite(PIN_ALPHASENSE_SLAVE, HIGH);
    SPI.endTransaction();
    SerialUSB.println("");
    

//     for (byte i = 0; i < 48; i++)
//         
//     {
//         checksum = checksum + alpha_histogram[i+2];
//     }
//     
//     checksum = checksum & 0xffff;
//     
//     SerialUSB.println(checksum, HEX);
    
//     for (byte i=0x00; i < 62; i++)
//     {
//         SerialUSB.print(i, HEX);
//         SerialUSB.print(" : ");
//         SerialUSB.println(alpha_histogram[i+2], HEX);
//     }
    
}



void alphasense_read_fan_laser_power()
{
    unsigned int checksum = 0;
    byte data_this;
    
    alpha_histogram[1] = (1 << 7) | LENGTH_ALPHA_HISTOGRAM;
    
    SPI.beginTransaction(set1);
    digitalWrite(PIN_ALPHASENSE_SLAVE, LOW);
    delay(100);
    
    SPI.transfer(0x13);  
    delay(10);
    
    SerialUSB.println("Fan and Laser Power: ");
    for (byte i = 0x00; i < 0x04; i++)
    {
        data_this = SPI.transfer(0x13);
        SerialUSB.print(i+1, DEC);
        SerialUSB.print(" : ");
        SerialUSB.println(data_this, HEX);
        delay(1);
    }
    
    
    digitalWrite(PIN_ALPHASENSE_SLAVE, HIGH);
    SPI.endTransaction();
    
}

void alphasense_config()
{
    alpha_config_a[1] = (1 << 7) | LENGTH_ALPHA_CONFIG_A;
    alpha_config_b[1] = (1 << 7) | LENGTH_ALPHA_CONFIG_B;
    alpha_config_c[1] = (1 << 7) | LENGTH_ALPHA_CONFIG_C;
    alpha_config_d[1] = (1 << 7) | LENGTH_ALPHA_CONFIG_D;

    
    
    #ifdef ALPHA_DEBUG
    SerialUSB.println("OPC Config:");
    
    
    SPI.beginTransaction(set1);
    digitalWrite(PIN_ALPHASENSE_SLAVE, LOW);
    delay(100);

    SPI.transfer(0x3C);   // 0xF3
    delay(10);
    
    for ( byte i = 0x00; i <= 0xfe; i ++ )
    {
        SerialUSB.print(i, HEX);
        SerialUSB.print(" : ");
        SerialUSB.println(SPI.transfer(0x3c), HEX);
        delay(1);
    }
    
    SerialUSB.print(255, HEX);
    SerialUSB.print(" : ");
    SerialUSB.println(SPI.transfer(0x3c), HEX);
    delay(1);
    
    SerialUSB.println("");
    
    
//     for (byte i = 0; i < 64; i++)
//     {
//         alpha_config_a[i + 2] = SPI.transfer(0x3C);
//         delay(1);
//     }
// 
//     for (byte i = 0; i < 64; i++)
//     {
//         alpha_config_b[i + 2] = SPI.transfer(0x3C);
//         delay(1);
//     }
// 
//     for (byte i = 0; i < 64; i++)
//     {
//         alpha_config_c[i + 2] = SPI.transfer(0x3C);
//         delay(1);
//     }
// 
//     for (byte i = 0; i < 64; i++)
//     {
//         alpha_config_d[i + 2] = SPI.transfer(0x3C);
//         delay(1);
//     }

//     for (i = 0; i < 64; i++)
//         SerialUSB.print(alpha_config_a[i], HEX);
//     SerialUSB.println(" ");
//     for (i = 0; i < 64; i++)
//         SerialUSB.print(alpha_config_b[i], HEX);
//     SerialUSB.println(" ");
//     for (i = 0; i < 64; i++)
//         SerialUSB.print(alpha_config_c[i], HEX);
//     SerialUSB.println(" ");
//     for (i = 0; i < 64; i++)
//         SerialUSB.print(alpha_config_d[i], HEX);
//     SerialUSB.println(" ");

    digitalWrite(PIN_ALPHASENSE_SLAVE, HIGH);
    SPI.endTransaction();
    
    #endif
    
}

#endif

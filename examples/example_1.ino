/*
**  Author: Aniket Biswas
**  Github: https://github.com/aniket-hpp
**  
**  Example for TFT_eSPI_Scroll library
**
**  Contribute to improve the library
*/

#include <Arduino.h>
#include <TFT_eSPI.h>
#include <TFT_eSPI_Scroll.h>
#include <colors/4bit.h>

TFT_eSPI tft;
TFT_eSPI_Scroll scroll;
int count = 1;

void setup(){
    // Initializing tft_espi
    tft.init();    
    Serial.begin(9600);

    // Initializing the tft_espi_scroll int 1bit B/W
    if(scroll.init(&tft, 4) != NO_ERROR){
        Serial.println("Failed... Reseting...");        
        return;
    }

    String data;

    for(int i = 1; i <= 100; i++){
        data = String("Count: ") + String(i); 
        scroll.write(data);
     
        //must be called for longer loops
        //otherwise watchdog will reset the mcu
        yield(); 
    }

    delay(2000);

    // reseting
    scroll.reset();

    // for 4bit
    scroll.init(&tft, 4, 4);
    scroll.setColor(COLOR_BLUE_4B, COLOR_RED_4B);
}

void loop(){
    scroll.write("2 x " + String(count) + " = " + String(2*count++));
    delay(100);
}
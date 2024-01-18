#include <Arduino.h>
#include <TFT_eSPI.h>
#include <TFT_eSPI_Scroll.h>

TFT_eSPI tft;
TFT_eSPI_Scroll scroll;
int count = 1;

void setup(){
    // Initializing tft_espi
    // setting a fontsize
    tft.init();    
    tft.setTextFont(4);
    
    // Initializing the tft_espi_scroll
    scroll.init(&tft, 4);
    String data;

    for(int i = 1; i <= 100; i++){
        data = String("Count: ") + String(i); 
        scroll.write(data);
     
        //must be called for longer loops
        //otherwise watchdog will reset the mcu
        yield(); 
    }

    delay(2000);

    scroll.reset();
    scroll.init(&tft, 4, TFT_BLUE, TFT_RED);
}

void loop(){
    scroll.write("2 x " + String(count) + " = " + String(2*count++));
    delay(100);
}
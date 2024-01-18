/*
**  Author: Aniket Biswas
**  Github: https://github.com/aniket-hpp
**  
**  Library to add Vertical text Scrolling functionality to TFT_eSPI library by bodmer.
**  TFT_eSPI: https://github.com/Bodmer/TFT_eSPI
**
**  Contribute to improve the library
*/

/*
**  SEE examples for usage
*/

#ifndef _TFT_ESPI_SCROLL_H_
#define _TFT_ESPI_SCROLL_H_

#include <Arduino.h>
#include <TFT_eSPI.h>

/*
** TFT_eSPI_Scroll
** Enables text scrolling
*/

class TFT_eSPI_Scroll{
public:

    // Constructor
    TFT_eSPI_Scroll();
    // Destructor
    ~TFT_eSPI_Scroll();

    /*
    ** @name init
    ** @brief Initializes the class with neccessary datas
    ** @param TFT_eSPI*
    ** @param text_font
    ** @param background_color
    ** @param foreground_color
    */
    void init(TFT_eSPI *tft_espi, uint16_t font_height, uint16_t background_color = TFT_BLACK, uint16_t foreground_color = TFT_WHITE);
    
    /*
    ** @name write
    ** @brief Writes a line to the screen while scrolling.
    ** @param text
    */
    void write(String text);

    /*
    ** @name reset
    ** @brief Resets configs, init must be called 
    ** @param text
    */ 
    void reset();

private:
    // Scrolls the screen by shifting all lines by -1
    void shift(int text_width);

    int width, height; //screen size
    int font_height, cursor;

    //stroing the lines in display 
    std::vector<String> buffer;
    TFT_eSPI *tft; //tft_espi display driver
    uint16_t bg_color; //background color
};

#endif
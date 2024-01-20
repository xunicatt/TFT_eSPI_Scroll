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

#define TFT_eSPI_Scroll_Version "1.0.2"

/*
**  Error Handeling
**  Returns NO_ERROR if everthing is ok
*/
enum TFT_eSPI_Scroll_Error{
    NO_ERROR,
    ERROR_NO_TFT,
    ERROR_SPRITE_MEMORY_ALLOCATION_FAILED
};


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
    ** @brief Initializes the class with neccessary datas.
    ** @brief It is recommended to use default 1-bit color_depth [B/W] for flickerless screen refresh & low ram usage
    ** @param TFT_eSPI*
    ** @param text_font
    ** @param color_depth
    */
    TFT_eSPI_Scroll_Error init(TFT_eSPI *tft_espi, uint16_t text_font, uint8_t color_depth = 1);
    
    /*
    ** @name write
    ** @brief Writes a line to the screen while scrolling.
    ** @param text
    */
    TFT_eSPI_Scroll_Error write(String text);

    /*
    ** @name setColor
    ** @brief Sets an background and foreground color
    ** @brief It is recommended to use default 1-bit color settings [B/W] for flickerless screen refresh & low ram usage.
    ** @brief Color depth must be set accordingly.
    ** @param background_color
    ** @param foreground_color
    */
    void setColor(uint16_t background_color, uint16_t forground_color);

    /*
    ** @name reset
    ** @brief Resets configs, init must be called 
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
    TFT_eSprite *sprite; //sprite for flicker less update
    uint16_t bg_color;
};

#endif
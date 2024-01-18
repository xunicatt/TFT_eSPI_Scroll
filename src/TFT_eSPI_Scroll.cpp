/*
**  Author: Aniket Biswas
**  Github: https://github.com/aniket-hpp
**  
**  Library to add Vertical text Scrolling functionality to TFT_eSPI library by bodmer.
**  Header File: TFT_eSPI_Scroll.h
**  TFT_eSPI: https://github.com/Bodmer/TFT_eSPI
*/

#include <TFT_eSPI.h>
#include "../include/TFT_eSPI_Scroll.h"

// Constructor
TFT_eSPI_Scroll::TFT_eSPI_Scroll(){
    this->cursor = 0;
}

// Destructor
TFT_eSPI_Scroll::~TFT_eSPI_Scroll(){buffer.clear();}

/*
** @name init
** @brief Initializes the class with neccessary datas
** @param TFT_eSPI*
** @param text_font
** @param bg_color
** @param fg_color
*/
void TFT_eSPI_Scroll::init(TFT_eSPI *tft_espi, uint16_t text_font, uint16_t bg_color, uint16_t fg_color){
    if(tft_espi == NULL) return;

    tft = tft_espi;
    this->width = tft->width();
    this->height = tft->height();
    this->font_height = tft->fontHeight(text_font);
    this->bg_color = bg_color;
    tft->fillScreen(bg_color);
    tft->setTextColor(fg_color);
}

/*
** @name write
** @brief Writes a line to the screen while scrolling.
** @param text
*/
void TFT_eSPI_Scroll::write(String text){
    // if init is not called then return
    if(!tft) return;
    // computes the text-width and text-height
    int text_height = font_height, text_width = tft->textWidth(text);
    if(text_width > width) text_height = ceil(text_width/(float)width) * font_height;
    // if the text cannot be fitted in the screen then we shift the texts in screen
    // to make room
    if(cursor + text_height >= height){shift(text_height);}
    
    // after shifting, previous string is filled with a rect
    // then text gets printed to the screen
    tft->fillRect(0, cursor, width, text_height, bg_color);
    tft->setCursor(0, cursor);
    tft->print(text);

    // stroing current string in buffer vector
    buffer.push_back(text);

    // preparing the cursor for the next line
    cursor += text_height;
}

/*
** @name shift
** @brief Shift the whole screen by -1
** @param text_height
*/
void TFT_eSPI_Scroll::shift(int text_height){
    int line_width, line_height;

    // making the room for the new string at the bottom
    // by removing texts from the top of the screen
    for(String &line : buffer){
        if(cursor + text_height < height) break;
        
        line_height = (ceil(tft->textWidth(line)/(float)width) * font_height);
        buffer.erase(buffer.begin());
        
        cursor -= line_height;
    }


    int extra_cursor = 0;

    // reprinting the whole text buffer after covering the previous texts
    // with rect
    for(String &line : buffer){
        line_height = font_height;
        line_width = tft->textWidth(line);
        if(line_width > width) line_height = (ceil(line_width/(float)width) * font_height);
        
        tft->fillRect(0, extra_cursor, (line_width<width)?line_width:width, line_height, bg_color);            
        tft->setCursor(0, extra_cursor);
        tft->print(line);

        extra_cursor += line_height;
    }
}

/*
** @name reset 
** @brief Resets scroll 
** @param text
*/
void TFT_eSPI_Scroll::reset(){
    buffer.clear();
    cursor = 0;
}
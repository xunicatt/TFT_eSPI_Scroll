# TFT_eSPI_Scroll

TFT_eSPI_Scroll library adds text scroll functionality to the existing [TFT_eSPI](https://github.com/Bodmer/TFT_eSPI/) library. This library by default uses 1-bit color-depth which makes it perform very fast & flickerless with very minimum ram usages. The color-depth can be changed accordingly to match required performances. This library supports all the processors that [TFT_eSPI](https://github.com/Bodmer/TFT_eSPI/) library supports. Available in [PlatformIO Registry](https://registry.platformio.org/libraries/xunicatt/TFT_eSPI_Scroll) and [Arduino Library Manager](https://www.arduino.cc/reference/en/libraries/tft_espi_scroll/).

# Installation

### Platform IO:

1. Open `platformio.ini`, a project configuration file located in the root of PlatformIO project.
2. Add the following line to the lib_deps option of [env:] section:

```
xunicatt/TFT_eSPI_Scroll@^1.0.1
```

3. Build a project, PlatformIO will automatically install dependencies.

### Arduino:

1. Open the Arduino IDE.
2. With the editor open, let's take a look at the left column. Here, we can see a couple of icons. Let's click the on the "library" icon.
3. A list will now appear of all available libraries, search for `TFT_eSPI_Scroll`.
4. Select a version and Click Install.

# Include

TFT_eSPI_Scroll library provides the following header files that can be included in your project.

```cpp
#include <TFT_eSPI_Scroll.h>
```

# Usage

### Object Creation:-

```cpp
#include <TFT_eSPI.h>
#include <TFT_eSPI_Scroll.h>

TFT_eSPI tft;
TFT_eSPI_Scroll scroll;
```

### Initialization:-

> [!WARNING]
> Note it is important to initialize the "TFT_eSPI" library before using "TFT_eSPI_Scroll".

Using this method the "TFT_eSPI_Scroll" library initializes in 1-bit color-depth mode. Only black and white color is available in this color-depth. Though 1-bit color-depth is limited to B/W colors, it is not only fast but also memory efficient and renders without any flickering or glitches.

```cpp
int textFont = 4;

void setup(){
    tft.init();
    if(scroll.init(&tft, textFont) != NO_ERROR){
        // memory allocation failed
    }

    // rest of the code
}
```

To set other color-depths, intialize the library with:

```cpp
// previous codes

int colorDepth = 4; // 4-bit color depth

if(scroll.init(&tft, textFont, colorDepth) != NO_ERROR){
    // memory allocation failed
}

// rest of the code
```

### Writing to display:-

```cpp
int count = 0;

void loop(){
    scroll.write("Count: " + String(count++));
}
```

### Changing the background & foreground color:-

> [!WARNING]
> Note in order to apply proper colors (excluding 1-Bit default), proper color-depth must be selected during initialization.

```cpp
// bg & fg {8-bit}
scroll.setColor(TFT_BLUE, TFT_YELLOW);

// bg & fg {4-bit} COLOR_<name>_4B
scroll.setColor(COLOR_BLUE_4B, COLOR_YELLOW_4B);

// bg & fg {1-bit} COLOR_<name>_1B
scroll.setColor(COLOR_WHITE_1B, COLOR_BLACK_1B);
```

### Reseting the library while freeing up spaces:-

```cpp
scroll.reset();
```

# Version

> 1.0.5

/*
  Display library for 16x16 led matrix
  By Emil
*/
#ifndef Dmat_h
#define Dmat_h

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <FastLED.h>

class Dmat
{
  public:
    Dmat(int W, int H, CRGB* leds);
    void show();
    void dot(int x, int y, CHSV color);
    void square(int x, int y, int width, int height, CHSV color);
    void squareFill(int x, int y, int width, int height, CHSV color);
    void fastledInit();
    void drawLetter(char letter, CHSV color);
    void sphere(float x, float y, int radius, int intensity, CHSV color);
    CHSV* getColor(int x, int y);
    
  private:
  
    int _W;
    int _H;

    CRGB* _leds;
    CHSV** _mat;

    bool _alphabet[26][5][3] = {
      {{0, 1, 0},   //A
       {1, 0, 1},
       {1, 1, 1},
       {1, 0, 1},
       {1, 0, 1}},

      {{1, 1, 0},   //B
       {1, 0, 1},
       {1, 1, 0},
       {1, 0, 1},
       {1, 1, 0}},

      {{0, 1, 1},   //C
       {1, 0, 0},
       {1, 0, 0},
       {1, 0, 0},
       {0, 1, 1}},

      {{1, 1, 0},   //D
       {1, 0, 1},
       {1, 0, 1},
       {1, 0, 1},
       {1, 1, 0}},

      {{1, 1, 1},   //E
       {1, 0, 0},
       {1, 1, 0},
       {1, 0, 0},
       {1, 1, 1}},

      {{1, 1, 1},   //F
       {1, 0, 0},
       {1, 1, 0},
       {1, 0, 0},
       {1, 0, 0}},

      {{1, 1, 1},   //G
       {1, 0, 0},
       {1, 0, 1},
       {1, 0, 1},
       {1, 1, 1}},

      {{1, 0, 1},   //H
       {1, 0, 1},
       {1, 1, 1},
       {1, 0, 1},
       {1, 0, 1}},

      {{1, 1, 1},   //I
       {0, 1, 0},
       {0, 1, 0},
       {0, 1, 0},
       {1, 1, 1}},

      {{1, 1, 1},   //J
       {0, 0, 1},
       {0, 0, 1},
       {1, 0, 1},
       {0, 1, 0}},

      {{1, 0, 1},   //K
       {1, 0, 1},
       {1, 1, 0},
       {1, 0, 1},
       {1, 0, 1}},

      {{1, 0, 0},   //L
       {1, 0, 0},
       {1, 0, 0},
       {1, 0, 0},
       {1, 1, 1}},

      {{1, 0, 1},   //M
       {1, 1, 1},
       {1, 0, 1},
       {1, 0, 1},
       {1, 0, 1}},

      {{1, 0, 1},   //N
       {1, 1, 1},
       {1, 1, 1},
       {1, 1, 1},
       {1, 0, 1}},

      {{0, 1, 0},   //O
       {1, 0, 1},
       {1, 0, 1},
       {1, 0, 1},
       {0, 1, 0}},

      {{1, 1, 1},   //P
       {1, 0, 1},
       {1, 1, 0},
       {1, 0, 0},
       {1, 0, 0}},

      {{0, 1, 0},   //Q
       {1, 0, 1},
       {1, 0, 1},
       {1, 0, 1},
       {1, 1, 1}},

      {{1, 1, 1},   //R
       {1, 0, 1},
       {1, 1, 0},
       {1, 0, 1},
       {1, 0, 1}},

      {{0, 1, 1},   //S
       {1, 0, 0},
       {0, 1, 0},
       {0, 0, 1},
       {1, 1, 0}},

      {{1, 1, 1},   //T
       {0, 1, 0},
       {0, 1, 0},
       {0, 1, 0},
       {0, 1, 0}},

      {{1, 0, 1},   //U
       {1, 0, 1},
       {1, 0, 1},
       {1, 0, 1},
       {1, 1, 1}},

      {{1, 0, 1},   //V
       {1, 0, 1},
       {1, 0, 1},
       {1, 0, 1},
       {0, 1, 0}},

      {{1, 0, 1},   //W
       {1, 0, 1},
       {1, 0, 1},
       {1, 1, 1},
       {1, 0, 1}},

      {{1, 0, 1},   //X
       {1, 0, 1},
       {0, 1, 0},
       {1, 0, 1},
       {1, 0, 1}},

      {{1, 0, 1},   //Y
       {1, 0, 1},
       {0, 1, 0},
       {0, 1, 0},
       {0, 1, 0}},

      {{1, 1, 1},   //Z
       {0, 0, 1},
       {0, 1, 0},
       {1, 0, 0},
       {1, 1, 1}}
    };

    bool checkDims(int x, int y);
    int getIdx(int x, int y);
};

#endif
/*
  Dmat.cpp
  Display library for 16x16 led matrix
  By Emil
*/

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "Dmat.h"
#include <FastLED.h>
#include <math.h>


Dmat::Dmat(int W, int H, CRGB* leds){
  _H = H;
  _W = W;

  _leds = leds;

  _mat = new int*[_W];
  for(int i = 0; i < _W; ++i)
    _mat[i] = new int[_H];
}

void Dmat::dot(int x, int y, CHSV color){
  if (checkDims(x, y)){
    _mat[x][y] = color;
  }else{
    //Serial.println("Error, point out of display");
  }
}

void Dmat::square(int x, int y, int width, int height, CHSV color){
  for (int i = x; i < (x + width); i++){
    dot(i, y, color);
    dot(i, y + height, color);
  }
  for (int j = y; j <= (y + height); j++){
    dot(x, j, color);
    dot(x + width, j, color);
  }
}

void Dmat::sphere(float x, float y, int radius, int intensity, CHSV color){
  float distanza = 0;
  int elevation = 0;
  for (int i = x - radius; i <= ceil(x) + radius; i++){
    for (int j = y - radius; j <= ceil(y) + radius; j++){

      distanza = sqrt(pow(x - i, 2) + pow(y - j, 2));
      elevation = color.v - distanza*intensity;
      if (elevation > 255){
        elevation = 255;
      }
      if (elevation < 0){
        elevation = 0;
      }

      dot(i, j, CHSV(color.h, color.s, elevation));
    }
  }
}


void Dmat::squareFill(int x, int y, int width, int height, CHSV color){
  for (int i = x; i < (x + width); i++){
    for (int j = y; j < (y + height); j++){
      dot(i, j, color);
    }
  }
}


void Dmat::drawLetter(char letter, CHSV color){
  int index = int(letter) - 97;
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 5; j++){
      if (_alphabet[index][j][i]){
        dot(i, j, color);
      }
    }
  }
}


CRGB* Dmat::getColor(int x, int y){
  return &_mat[x][y];
}


int Dmat::getIdx(int x, int y){
  int idx = 0;
  if (y % 2 == 0){
    idx = ((_H - 1) - x) + (y * _H);
  }else{
    idx = x + (y * _H);
  }
  return idx;
}

bool Dmat::checkDims(int x, int y){
  if (((x < _W) && (y < _H)) && ((x >= 0) && (y >= 0))){
    return true;
  }else{
    return false;
  }
}

void Dmat::show(){

  for (int i = 0; i < _W; i++){
    for (int j = 0; j < _H; j++){
      CHSV pixel = _mat[i][j];
      _leds[getIdx(i, j)].setHSV(pixel.h, pixel.s, pixel.v);
    }
  }

  FasLED.show();

}
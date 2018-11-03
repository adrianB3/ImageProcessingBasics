//
// Created by adrianb3 on 11.09.2018.
//

#include "Image.h"

Image::Image(int numRows, int numCols, int grayLevels) {
    /*
     * Image initialization
     */
    this->rows = numRows;
    this->cols = numCols;
    this->graylevels = grayLevels;

    pixelValues = new int *[rows];
    for(int i = 0; i < rows; i++){
        pixelValues[i] = new int[cols];
        for(int j = 0; j < cols; j++){
            pixelValues[i][j] = 0;
        }
    }
}

Image::Image() {
    this->rows = 0;
    this->cols = 0;
    this->graylevels = 0;

    this->pixelValues = nullptr;
}

Image::~Image() {
    this->rows = 0;
    this->cols = 0;
    this->graylevels = 0;

    for(int i = 0; i < rows; i++){
        delete pixelValues[rows];
    }

    delete pixelValues;
}

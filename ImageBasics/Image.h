//
// Created by adrianb3 on 11.09.2018.
//

#ifndef IMAGEBASICS_IMAGE_H
#define IMAGEBASICS_IMAGE_H


#include <iostream>

class Image {
private:
    int rows;
    int cols;
    int graylevels;
    int **pixelValues;
public:
    Image(); // default constructor
    Image(int numRows, int numCols, int grayLevels); // constructor
    ~Image();
    Image(const Image& oldImage); // copy constructor
    void operator=(const Image& otherImage); // equal operator overload
    void setImageInfo(int numRows, int numCols, int maxVal);
    void getImageInfo(int &numRows, int &numCols, int &maxVal);
    int getPixelValue(int row, int col);
    void setPixelValue(int row, int col, int value);
    bool inBounds(int row, int col);
    void rotateImage(int theta, Image& oldImage);
};


#endif //IMAGEBASICS_IMAGE_H

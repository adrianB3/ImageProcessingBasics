//
// Created by adrianb3 on 16.09.2018.
//

#ifndef IMAGEBASICS_IMAGEIO_H
#define IMAGEBASICS_IMAGEIO_H


#include <iostream>
#include <fstream>
#include "Image.h"

class ImageIO {
public:
    void readImage(std::string fileName, Image &img);
    void writeImage(std::string fileName);
};


#endif //IMAGEBASICS_IMAGEIO_H

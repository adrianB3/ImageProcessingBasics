//
// Created by adrianb3 on 14.10.2018.
//

#ifndef TUTORIAL_PPMIMAGE_H
#define TUTORIAL_PPMIMAGE_H


#include <fstream>
#include "Image.h"

class PPMImage {
public:
    Image readPPM(const char *filename);
    void savePPM(const Image &img, const char *filename);
};


#endif //TUTORIAL_PPMIMAGE_H

//
// Created by adrianb3 on 16.09.2018.
//

#include "ImageIO.h"

void ImageIO::readImage(std::string fileName, Image &img) {
    char header[100], *ptr;
    int rows, cols, graylevels;
    std::ifstream ifs; // input file stream
    ifs.open(fileName, std::ios::in | std::ios::binary);

    if(!ifs){
        std::cout << "Error opening file" << std::endl;
        exit(1);
    }

    ifs.getline(header, 100, '\n');
    if((header[0] != 80) || (header[1] != 53)){ // if the magic number is not P5
        std::cout << "Image " + fileName + " not a PGM file." << std::endl;
        exit(1);
    }

    ifs.getline(header, 100, '\n');
    while (header[0] == '#'){
        ifs.getline(header, 100, '\n');
    }

    rows = std::strtol(header, &ptr, 0);
    cols = std::atoi(ptr);

    ifs.getline(header, 100, '\n');
    graylevels = std::strtol(header, &ptr, 0);


}

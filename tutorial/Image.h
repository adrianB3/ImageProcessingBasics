//
// Created by adrianb3 on 14.10.2018.
//

#ifndef TUTORIAL_IMAGE_H
#define TUTORIAL_IMAGE_H


#include <cstring>

class Image {
public:
    struct Rgb{
        float r, g, b;

        Rgb() : r(0), g(0), b(0) {}; // default constructor
        explicit Rgb(float c) : r(c), g(c), b(c) {}; // single param. constructor
        Rgb(float _r, float _g, float _b) : r(_r), g(_g), b(_b) {}; // parametrized constructor

        bool operator !=(const Rgb &other) const;
        Rgb& operator *=(const Rgb &rgb);
        Rgb& operator +=(const Rgb &rgb);
        //friend float& operator +=(float &f, Rgb rgb);
    };

    Image() : width(0), height(0), pixels(nullptr) {};
    Image(const unsigned int &_w, const unsigned int &_h, const Rgb &c = kBlack);
    Image(const Image &img);

    const Rgb& operator [](const unsigned int &i) const;
    Rgb& operator [] (const unsigned int &i);
    Image operator + (const Image &img);

    ~Image() {
        if(pixels != NULL)
            delete [] pixels;
    }

    unsigned int width, height;
    Rgb *pixels; // array that will hold the image
    static const Rgb kBlack, kWhite, kRed, kGreen, kBlue; // Preset colors
};


#endif //TUTORIAL_IMAGE_H

//
// Created by adrianb3 on 14.10.2018.
//

#include "Image.h"

bool Image::Rgb::operator!=(const Image::Rgb &other) const {
    return other.r != r || other.g != g || other.b != b;
}

Image::Rgb &Image::Rgb::operator*=(const Image::Rgb &rgb) {
    r *= rgb.r;
    g *= rgb.g;
    b *= rgb.b;

    return *this;
}

Image::Rgb &Image::Rgb::operator+=(const Image::Rgb &rgb) {
    r += rgb.r;
    g += rgb.g;
    b += rgb.b;

    return *this;
}

//float &operator+=(float &f, const Image::Rgb rgb) {
//    f += (rgb.r + rgb.g + rgb.b) / 3.f;
//    return f;
//}

Image::Image(const unsigned int &_w, const unsigned int &_h, const Image::Rgb &c) :
    width(_w), height(_h), pixels(nullptr)
{
    pixels = new Rgb[width * height];
    for(int i = 0; i < width * height; ++i){
        pixels[i] = c;
    }
}

const Image::Rgb &Image::operator[](const unsigned int &i) const {
    return pixels[i];
}

Image::Rgb &Image::operator[](const unsigned int &i) { return pixels[i]; }

Image::Image(const Image &img) :width(img.width), height(img.height), pixels(nullptr){
    pixels = new Rgb[width*height];
    memcpy(pixels, img.pixels, sizeof(Rgb)*width*height);
}

Image Image::operator+(const Image &img) {
    Image tmp(*this);
    for(int i = 0; i < width * height; ++i){
        tmp.pixels[i] += img.pixels[i];
    }

    return tmp;
}

const Image::Rgb Image::kBlack = Image::Rgb(0);
const Image::Rgb Image::kWhite = Image::Rgb(1);
const Image::Rgb Image::kRed = Image::Rgb(1,0,0);
const Image::Rgb Image::kGreen = Image::Rgb(0,1,0);
const Image::Rgb Image::kBlue = Image::Rgb(0,0,1);


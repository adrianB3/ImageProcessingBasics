//
// Created by adrianb3 on 14.10.2018.
//

#include "PPMImage.h"

Image PPMImage::readPPM(const char *filename) {
    std::ifstream ifs;
    ifs.open(filename, std::ios::binary);

    Image src;

    try {
        if(ifs.fail()) {
            throw "Can't open file";
        }

        std::string header;
        int width, height, b;

        ifs >> header;
        if(header != "P6"){
            throw "Can't read input file";
        }

        ifs >> width >> height >> b;
        src.width = static_cast<unsigned int>(width);
        src.height = static_cast<unsigned int>(height);
        src.pixels = new Image::Rgb[width * height];
        ifs.ignore(256, '\n');
        unsigned char pix[3];

        for(int i = 0; i < width*height; ++i){
            ifs.read(reinterpret_cast<char *>(pix), 3);
            src.pixels[i].r = pix[0] / 255.f;
            src.pixels[i].g = pix[1] / 255.f;
            src.pixels[i].b = pix[2] / 255.f;
        }

        ifs.close();
    }
    catch (const char *err){
        fprintf(stderr, "%s\n", err);
        ifs.close();
    }

    return src;
}

void PPMImage::savePPM(const Image &img, const char *filename) {
    if(img.width == 0 || img.height == 0){
        fprintf(stderr, "Can't save an empty image\n");
    }

    std::ofstream ofs;

    try {
        ofs.open(filename, std::ios::binary);
        if(ofs.fail()) throw "Can't open file";
        ofs << "P6\n" << img.width << " " << img.height << "\n255\n";
        unsigned char r, g, b;
        for(int i = 0; i < img.width * img.height; ++i){
            r = static_cast<unsigned char>(std::min(1.f, img.pixels[i].r) * 255);
            g = static_cast<unsigned char>(std::min(1.f, img.pixels[i].g) * 255);
            b = static_cast<unsigned char>(std::min(1.f, img.pixels[i].b) * 255);
            ofs << r << g << b;
        }
        ofs.close();
    }
    catch (const char *err){
        fprintf(stderr, "&s\n", err);
        ofs.close();
    }

}

#include <iostream>
#include "Image.h"
#include "PPMImage.h"

int main(int argc, char** argv) {

    PPMImage ppm;
    try {
        Image lenna = ppm.readPPM("./lenna.ppm");
        Image pepper = ppm.readPPM("./lenna.ppm");
        Image c(lenna.width, lenna.height);
        c = lenna + pepper;
        ppm.savePPM(c, "./comb.ppm");
    }
    catch (const std::exception &e){
        fprintf(stderr, "Error: %s\n", e.what());
    }
    return 0;
}
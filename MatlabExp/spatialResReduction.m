clear all
close all
factor = 2;
I = imread('cameraman.png');

I2 = I(1:factor:end, 1:factor:end);
I3 = imresize(I, 0.5);
imshow(I2, [])
figure
imshow(I3, [])

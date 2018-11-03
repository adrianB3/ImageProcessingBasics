I = imread('mar.TIF');
I = double(I);
F = fft2(I);

imshow(log(abs(fftshift(F))), [])
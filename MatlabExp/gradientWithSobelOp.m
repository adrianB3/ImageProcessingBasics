I = imread('mar.TIF');
I = double(I);

% sobel operators
hy = [-1 -2 -1; 0 0 0; 1 2 1];
hx = hy';
Ix = imfilter(I, hx);
Iy = imfilter(I, hy);

figure;
subplot(1,2,1), imshow(Ix, [])
subplot(1,2,2), imshow(Iy, [])

% gradient magnitude
Ig = (Ix .^ 2 + Iy .^ 2) .^ 0.5;
figure;
imshow(Ig, [])

%gradient direction
Iang = atan2(Iy, Ix);
figure, imshow(Iang, [])

%where gradient magnitude is high
Mask = (Ig > 100);
figure, imshow(double(Mask) .* Iang, [])
colormap hsv
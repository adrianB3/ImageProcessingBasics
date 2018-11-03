I = imread('tesla.png');
In = 255 - I; % negative image

Ig = double(I)/255;
Ig = power(Ig, 0.3); % gamma transform, darker areas more visible at the expense of lighter areas as 
% the exponent is closing to 0
% above 1 image gets darker
imshow(Ig, [])


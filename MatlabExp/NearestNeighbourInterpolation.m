clear all
close all

I = imread('cameraman.png');

M = size(I, 1); % number of rows
N = size(I, 2); % number of cols

% Output size

M1 = 300;
N1 = 100;

I1 = zeros(M1, N1);

cx = N1/N;
cy = M1/M;

for x=1:N1
    for y=1:M1
        v = x/cx;
        w = y/cy;
        
        v = round(v);
        w = round(w);
        
        I1(y,x) = I(w,v);
    end
end

imshow(I, []);
figure
imshow(I1, []);
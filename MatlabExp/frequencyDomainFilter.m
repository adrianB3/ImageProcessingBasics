f = imread('mar.TIF'); 
F = fft2(double(f));
N = 20;
h = ones(N, N)/(N*N);
h(size(f,1), size(f,2)) = 0;
H = fft2(h);
figure, imshow(log(abs(fftshift(H))), [])
G = F .* H;
g = real(ifft2(G));
figure, imshow(g, [])
f = double(imread('mar.TIF'));
h = size(f,1);
w = size(f,2);

R = 100;  %cutoff freq
H = zeros(h,w);
for v=1:h
    for u=1:w
        if (v-h/2)^2 + (u-w/2)^2 < R^2
            H(v,u) = 1;
        end
    end
end
figure, imshow(H, [])

H = ifftshift(H);
figure, imshow(H, []);

F = fft2(f);
G = H .* F;
g = real(ifft2(G));

figure, imshow(g, [])
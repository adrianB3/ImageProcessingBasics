img=imread('tesla.png');
figure, imshow(img,[]);
img=img(:,:,1);
figure, imshow(img,[]);

L = medfilt2(img,[3 3]);

L=im2double(L);
[A,H,V,D]=dwt2(L,'haar');

A=zeros(size(A));


Q1 = idwt2(A,H,V,D,'haar');

figure, imshow(Q1,[]);
figure, imshow(-Q1, []);
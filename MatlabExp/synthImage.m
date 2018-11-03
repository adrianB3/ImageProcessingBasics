clear all
close all

img = zeros(768,1024);
for row=1:768
    for col=1:1024
        img(row,col) = col-row;
    end
end

imshow(img, [])

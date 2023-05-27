%% Esercizio 2. Sharpening
%
% - Applicare il filtraggio di sharpening all'immagine Pavone
%   corrotta con rumore Gaussiano
% - Provare ad applicarlo direttamente all'immagine con rumore
%   oppure dopo aver applicato un filtraggio media o gaussiano.
%   Che differenza si nota?

clear all; close all; clc

I = rgb2gray(imread('peacock.jpg'));
figure, imshow(I); set(gcf,'name','Originale');

J = imnoise(I,'gaussian',0.01);
figure, imshow(J); set(gcf,'name','Rumore Gaussiano');

I = double(I);
J = double(J);

% Filtro sharpening
Hlap = fspecial('laplacian',0.5);
Kl = imfilter(J,Hlap);
cost = -1;
Klfinal = double(J) + cost*double(Kl);
figure; set(gcf,'name','Pavone sharpened ');
imshow(uint8(Klfinal),[]); colorbar;


% Filtro smoothing media e poi sharpening
H = fspecial('average',9);
Km = imfilter(J,H);
Hlap = fspecial('laplacian',0.5);
Kml = imfilter(Km,Hlap);
cost = -1;
Kmfinal = double(Km) + cost*double(Kml);
figure; set(gcf,'name','Pavone media smoothing: sharpened ');
imshow(uint8(Kmfinal),[]); colorbar;

% Filtro smoothing gaussiano e poi sharpening
Msize = 9;
sigma = Msize/5;
H = fspecial('gaussian',9,sigma);
Km = imfilter(J,H);
Kgl = imfilter(Km,Hlap);
cost = -1;
Kgfinal = double(Km) + cost*double(Kgl);
figure;
set(gcf,'name','Pavone gaussian smoothing: sharpened ');
imshow(uint8(Kgfinal),[]); colorbar;
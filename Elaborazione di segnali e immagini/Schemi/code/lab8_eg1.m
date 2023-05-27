%% Esempio - 
%  Trasformata di Fourier discreta 2D in immagini reali ---- 
% In questo esempio vedremo come calcolare la trasformata di
% Fourier per un'immagine, visualizzare lo spettro delle ampiezze
% e lo spettro di fase e come ricostruire l'immagine a partire
% dalle frequenze 

clear all
close all
clc

imdata = imread('imageA1.png');
imdata = rgb2gray(imdata);
figure(1); imshow(imdata), title('Original Image');

% Calcolo la trasformata di Fourier dell'immagine 
F = fft2(imdata);

% FFT dell'immagine: spettro di ampiezza
S = abs(F);
figure(2);imshow(S,[20 100000]), 
title('Magnitude Spectrum');

% Centro lo spettro delle ampiezze per aiutare la visualizzazione 
Fsh = fftshift(F);
figure(3);imshow(abs(Fsh),[20 100000]), 
title('Centered Magnitude Spectrum'); 

% Applico il logaritmo 
S2 = log10(1+abs(Fsh));
figure(4);imshow(S2,[]), 
title('Log transformed Magnitude Spectrum');

% FFT dell'immagine: spettro di fase
figure(5);imshow(angle(fftshift(F)),[-pi pi]), 
title('Phase Spectrum');

% Ricostruzione dell'immagine a partire dalle frequenze 
F = ifftshift(Fsh);
f = ifft2(F);
f = real(f);
figure(6);imshow(f,[]),
title('Reconstructed Image');
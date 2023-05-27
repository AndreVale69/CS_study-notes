%% Esempio 4 -  Filtraggio Locale: Sharpening ---
% Esempio di applicazione di sharpening.

clear all; close all; clc

A = imread('moon.tif');
figure; imshow(A); title ('Immagine partenza')

alpha = 0.2; %valore di default
H = fspecial('laplacian',alpha);
B = imfilter(A,H);
figure; imshow(B); title (['Filtraggio sharpening con Laplaciano Alpha = ', num2str(alpha)])

% Basic highpass spatial filtering
% L'immagine finale e' l'immagine originale
% sommata con l'immagine filtrata con il laplaciano
cost = -1; % valore centrale di H e' negativo
C = double(A) + cost*double(B);
figure; imagesc(uint8(C)), colormap gray, axis image; title('Immagine finale (basic highpass)')
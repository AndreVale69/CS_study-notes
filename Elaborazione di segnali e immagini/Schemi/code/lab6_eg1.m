%% Operazione puntuale: Negativo
% Caricare l'immagine "FLAIR.png" e una volta convertita in scala
% di grigi da RGB farne il negativo. Visualizzare in un'unica
% figura con piu' subplot le due immagini e i corrispondenti
% istogrammi.

clear all;
close all;
clc;

MRI = imread('FLAIR.png');
MRI = rgb2gray(MRI);
MRI_neg = 255-MRI;

figure;
subplot(221);imshow(MRI); colorbar, title ('Immagine Originale')
subplot(222);imshow(MRI_neg);colorbar, title ('Immagine Negativo')
subplot(223);imhist(MRI); title ('Hist Immagine Originale')
subplot(224);imhist(MRI_neg); title ('Hist Immagine Negativo')
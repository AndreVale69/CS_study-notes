%% Esercizio 3. Caso di studio reale
%
% - Riuscire a migliorare il piu' possibile la qualita' della
%   scrittura nel file hand.png, utilizzando gli strumenti
%   visti fino ad ora;
% - Suggerimento: ragionare sull'istogramma, e utilizzare
%   sia operatori puntuali (lezione scorsa) che operatori
%   locali (questa lezione).

clear all; close all; clc

img = imread('hand.png');

figure(1);
imshow(img); title('Originale')


figure(2)
set(gcf,'name','Analisi scrittura a mano: istogrammi');
subplot(221); imhist(img); title('Originale')


% stretching
Cmin = 90;
Cmax = 240;
Cs = imadjust(img,[Cmin, Cmax]./255,[0,1]);
figure;
figure(3), imshow(Cs); title('Stretched')
figure(2), subplot(222); imhist(Cs); title('Stretched');

% sharpening
H = fspecial('laplacian',1);
Csl = imfilter(Cs,H);
cost = -1;
Cfinal = double(Cs) + cost*double(Csl);
figure;
figure(4),imshow(uint8(Cfinal)); title('Sharpened')
figure(2), subplot(223); imhist(uint8(Cfinal)); title('Sharpened')
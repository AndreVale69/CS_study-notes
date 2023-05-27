%% Esercizio 1
% - Caricare l'immagine 'imageA1.png'
% - Visualizzare lo spettro delle ampiezze centrato 
%   (e visualizzato con il logaritmo),
% - Estrarre una sola porzione delle frequenze e ricostruire l'immagine a 
%   partire da queste frequenze selezionate. 
% - Osservare cosa succede se cambiamo il contenuto in frequenza scelto. 
%   In particolare: cosa succede se escludo le basse frequenze? E se escludo
%   le alte?
%
% Suggerimento per selezionare le frequenze:
% - creare una matrice, della stessa dimensione della fft2, contenente tutti 
%   zeri; 
% - copiare nella posizione della porzione considerata le frequenze 
%   corrispondenti dalla matrice della fft2
%
% Porzioni da considerare (sulla trasformata shiftata):
% 1) righe: 260-360, colonne: 410-520
% 2) righe: 150-460, colonne: 270-670
% 3) righe: 105-310, colonne: 175-460
% 4) ...
% 
% Nota: provare anche ad usare getrect per selezionare la porzione: 
%    (La funzione getrect serve per estrarre un rettangolo da un'immagine, 
%     si veda l'help della funzione)


clear all
close all
clc

imdata = imread('imageA1.png');
imdata = rgb2gray(imdata);

% Calcolo FFT2 e visualizzo lo spettro di ampiezza centrato (con logaritmo)
F = fft2(imdata);
Fsh = fftshift(F);
figure(1);imshow(log10(1+abs(Fsh)),[]); 

% Seleziono la porzione di frequenze.

% Selezione manuale (decommentare e mettere i valori giusti)
% 1) righe: 260-360, colonne: 410-520
% 2) righe: 150-460, colonne: 270-670
% 3) righe: 105-310, colonne: 175-460
% 4) ...
rangeX = 260:360;
rangeY = 410:520;

% Selezione con getrect 
% rect = getrect;
% x = int32(rect(2));
% X = int32(rect(2)+rect(4));
% rangeX = x:X;
% y = int32(rect(1));
% Y = int32(rect(1)+rect(3));
% rangeY = y:Y;

% creo un'immagine delle stesse dimensioni della trasformata:
croppedSection = zeros(size(Fsh));
croppedSection(rangeX,rangeY) = Fsh(rangeX,rangeY);

figure (2), imshow(log10(1+abs(croppedSection)),[])
axis image off
colormap gray
title('Section')

% Ricostruisco immagine a partire dalla sola selezione di frequenze fatta
Test = ifft2(ifftshift(croppedSection));

% Visualizzo le due immagini
figure(3), imshowpair(imdata, real(Test),'montage')
%% Operazione puntuale: Binarizzazione ---
% Produce una immagine che ha solo due livelli: nero e bianco.
% Si ottiene scegliendo una soglia T e mettendo a nero tutti i pixel
% il cui valore e' minore a T e a bianco tutti gli altri.
% La difficolta' risiede nel saper scegliere la soglia T
% piu' ragionevole.
% Ci sono metodi per scegliere automaticamente la
% soglia (Metodo di Otsu)
clear all;
close all;
clc;


I = imread('coins.png');
figure
set(gcf,'name','Binarizzazione di immagini')
subplot(121); imshow(I); title('Immagine originale');


T = 80; % soglia
BW = zeros(size(I)); % immagine binaria
BW(I>T) = 1;
subplot(122); imshow(BW);title('Immagine binarizzata');

% Nota: si puo' ottenere lo stesso risultato utilizzando
% il comando imbinarize.
% La soglia deve essere tra 0 e 1
% Si veda doc imbinarize

% BW2 = imbinarize(I,T/255);
% % check che siano uguali
% sum(abs(BW-BW2),'all')
% % ans =
%   %  0
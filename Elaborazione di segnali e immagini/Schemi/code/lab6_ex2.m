%% Esercizio 2
% - Caricare l'immagine 'noisy.png'
% - Visualizzare l'immagine e il relativo istogramma
% - Cercare di migliorare l'immagine riducendo il rumore
%   con un'operazione puntuale: 
% 	qual'e' l'operazione piu' adatta?

clear all
close all
clc



I = imread('noisy.png');
figure, imshow(I), title('Immagine originale')

% Soluzione: clamping
% Visualizzo l'istogramma per capire i limiti
figure, imhist(I), title('Istogramma Immagine originale')

a = 40;
b = 100;
LUT=[];
for i = 0:255
    r = i;
    if r<a
        LUT(i+1) = a;
    elseif r<=b & r>=a
        LUT(i+1) = r;
    elseif r>b
        LUT(i+1) = b;
    end
end
% visualizzo la LUT
figure;
plot([0:255],LUT), xlim([0 255]), grid on

% clamping
I_clip = uint8(LUT(I+1));
% visualizzo l'immagine risultante
figure;
imshow(I_clip)

% NOTA: il risultato non e' perfetto, vedremo nella lezione
% sulle operazioni locali che esiste un metodo migliore
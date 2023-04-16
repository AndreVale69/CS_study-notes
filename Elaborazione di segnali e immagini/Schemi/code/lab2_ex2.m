% Carico immagine
clear all
close all
clc

I  = imread('moon.tif');

% visualizzo l'immagine
figure(1)
imshow(I ,[]), colorbar
title ('Immagine a livelli di grigi')

% estraggo le dimensioni
[m,n] = size(I);

% versione piu' lunga: scorro l'immagine
% inizializzo il vettore di conteggio
count = zeros(256,1); %256 livelli di grigio, da 0 a 255
for i = 1:m
    for j = 1:n
        val = I(i,j);
        count(val+1) = count(val+1) +1;
        % devo mettere "+1" perche' in matlab 
        % gli indici dei vettori partono da 1
    end
end
figure(2)
bar(count)
xlabel('Valori')
ylabel('Numero di pixels') 

% VERSIONE PIU' EFFICIENTE: scorro il vettore 
% dei livelli di grigio
% 256 livelli di grigio, da 0 a 255
vettore_count = zeros(256,1);
for index = 0:1:255
    r = find(I(:)==index);
    vettore_count(index+1,1) = length(r);
    % devo mettere "+1" perche' in matlab 
    % gli indici dei vettori partono da 1
end

figure(3)
bar(vettore_count)
xlabel('Valori')
ylabel('Numero di pixels')
%% Esercizio 1
% Matching 2D
% Usare la cross correlazione 2D per trovare la posizione
% del template nell'immagine
% In particolare si richiede di calcolare di quanto
% (righe-colonne) il template e' stato traslato rispetto
% all'angolo in alto a sinistra dell'immagine
%
% Suggerimento: calcolare la cross correlazione (xcorr2)
% e il template (kernel), estrarre le coordinate del massimo e 
% recuperare la posizione del kernel 
% 
% Controllare anche l'help della funzione xcorr2

clear all
close all

% Template: una croce
template = 0.2*ones(55);
template(29:31,15:45) = 0.6;
template(15:45,29:31) = 0.6;


% Immagine: si posiziona il template con un offset 
immagine = 0.2*ones(111);
offset = [10 40];
immagine(offset(1):offset(1)+size(template,1)-1, ...
         offset(2):offset(2)+size(template,2)-1) = template;

figure
imshow(template,[])
title('Template')

figure
imshow(immagine,[])
title('Immagine')


cc = xcorr2(immagine,template);
figure, imagesc(cc)


% si trovano le coordinate del massimo
maxcc = max(cc(:)); % massimo
[r,c] = find(cc == maxcc); % coordinate del massimo


% la posizione 1,1 del kernel si trova
% Riga: r-R2+1
% Colonna: c-C2+1

[R2,C2] = size(template);
corr_offset = [r-R2+1, c-C2+1];

fprintf('Offset originale: %d-%d\n',offset)
fprintf('Offset calcolato con la cross-correlazione: %d-%d\n',corr_offset)
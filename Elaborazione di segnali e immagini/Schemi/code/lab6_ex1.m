%% Esercizio 1
% Implementare l'operazione puntuale di stretching/shrinking e
% applicarla all'immagine presente nel file "fog.mat"
% - caricare il file "fog.mat" (auto nella nebbia)
% - visualizzare l'immagine e il corrispondente istogramma  
% - individuare i limiti rmin rmax per l'operazione
%   di stretching/shrinking
% - costruire la LUT (Look Up Table) corrispondente
% - applicare la LUT all'immagine originale e visualizzare
%   il risultato ottenuto: come cambia? Si riesce a
%   visualizzare meglio i numeri della targa?
% - visualizzare l'istorgramma dell'immagine risultato:
%   come cambia rispetto all'istogramma dell'immagine
%   originale?
% 
% Suggerimento: fare attenzione che in MATLAB gli array partono  
% da 1, mentre i livelli di grigio vanno da 0 a 255 (La LUT e' un 
% array con elementi in posizione da 1 a 256 ma con valori 
% da 0 a 255).


clear all;
close all;
clc;

% Auto nella nebbia:
% come fare a visualizzare meglio i numeri della targa?
% Data l'operazione puntuale costruita, visualizzarne la
% Look Up Table (LUT)
load fog;
figure; set(gcf,'name','Immagine originale auto nella nebbia')
imshow(img); colorbar, title('Immagine originale')
figure; set(gcf,'name','Istogramma originale auto nella nebbia')
imhist(img); title ('Istogramma')

% Individuo i limiti massimo e minimo dell'istogramma,
% noto che tali limiti non sono dovuti al rumore (non sono elementi
% distaccati dal corpo principale dell'istogramma)
r_max = double(max(img(:))); % 153
r_min = double(min(img(:)));% 128
% voglio usare tutti i livelli di grigio a disposizione, ovvero 256
a = 0;
b = 255;

% Creo una LUT per operazione di stretching
LUT=[];
for i = 0:255
    r = i;
    if r<=r_max & r>=r_min
        s = ((r-r_min)/(r_max-r_min))*(b-a)+a;
    else
        s = r; % fuori dal range non ho modifiche
    end
    LUT(i+1) = s;
end


newimg = LUT(img+1); % come prima: applico la LUT
newimg = uint8(newimg); % rounding
figure; set(gcf,'name','Immagine auto nella nebbia trattata')
imshow(newimg);colorbar; title('Immagine con stretching')
figure; set(gcf,'name','Istogramma auto nella nebbia trattata')
imhist(newimg); title('Istogramma stretchato')

% NOTA IMPORTANTE: l'operazione di stretching si pue' fare con
% imadjust vedi doc imadjust
% L'operazione fatta sopra si ottiene come:
% newimg2 = imadjust(img,[r_min,r_max]./255,[a,b]./255);
% % check
% sum(abs(newimg-newimg2),'all')
% % ans =
% %    0
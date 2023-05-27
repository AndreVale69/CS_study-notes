%% Operazione puntuale: Clamping
% Caricare l'immagine di saturno ("saturn2") dal file "imdemos.mat"
% (il file contiene una serie di immagini in B/N, e si trova dentro
% l'image processing toolbox)
% Fare l'operazione di clamping e visualizzare la LUT 
% relativa a questa operazione.
% Infine, visualizzare le due immagini (originale/modificata) e i
% corrispondenti istogrammi
clear all;
close all;
clc;
load ('imdemos.mat','saturn2')
I = saturn2;

% Creo una LUT per operazione di clamping e la visualizzo
a = 110;
b = 190;
LUT=[];
for i = 0:255
    r = i;
    if r<a
        LUT(i+1) = a; % MATLAB inizia l'indicizzazione a 1,
                      % mentre le intensita' iniziano da 0
    elseif r<=b & r>=a
        LUT(i+1) = r;
    elseif r>b
        LUT(i+1) = b;
    end
end

figure;
plot([0:255],LUT), xlim([0 255]), grid on, title ('Clamping LUT')
xlabel('Valori originali')
ylabel('Valori per Clamping LUT')

% Applico la LUT e visualizzo l'immagine dopo
% l'operazione di clamping
[r,c] = size(I);
Inew = zeros(size(I));
for i = 1:r
    for j = 1:c
        ldg = I(i,j);
        newldg = LUT(ldg+1);% MATLAB inizia l'indicizzazione a 1, 
                            % mentre le intensita' iniziano da 0
        Inew(i,j) = newldg;
    end
end
Inew = uint8(Inew);
% I due cicli for si possono scrivere in forma compatta:
Inew2 = uint8(LUT(I+1)); % MATLAB inizia l'indicizzazione a 1,
                         % mentre le intensita' iniziano da 0
% % To check
% sum(abs(Inew2-Inew),'all')
% % ans =
% %      0

figure;
subplot(221);imshow(saturn2); colorbar, title ('Immagine Originale')
subplot(223);imhist(saturn2); title ('Istogramma')
hold on; plot([a a],[0 max(imhist(saturn2))]);
plot([b b],[0 max(imhist(saturn2))])
subplot(222);imshow(Inew); colorbar, title ('Immagine Clamping')
subplot(224);imhist(Inew); title ('Istogramma')
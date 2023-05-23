%%
%%% ESERCIZIO 2
% Cross-correlazione su segnali audio: riconoscimento
% del suono attraverso la cross-correlazione.
% 
% - Caricare i primi 20 secondi dei segnali audio
%   'funky.mp3','lost.mp3', 'Diana.mp3',
%   'never.mp3', 'T69.mp3'
% - Caricare il segnale audio 'Test.wav'
% - Confrontate l'esempio di test con le varie canzoni della
%   galleria usando la cross correlazione:
%   da quale canzone proviene? 
% - Suggerimento: cercare il segnale che contiene la
%   crosscorrelazione piu' grande

clear all
close all
clc

[Y1,fs1] = audioread('funky.mp3',[1,96000*20]);
[Y2,fs2] = audioread('lost.mp3',[1,96000*20]);
[Y3,fs3] = audioread('Diana.mp3',[1,96000*20]);
[Y4,fs4] = audioread('never.mp3',[1,96000*20]);
[Y5,fs5] = audioread('T69.mp3',[1,96000*20]);

test = audioread('Test.wav');

figure; set(gcf,'name','Dataset canzoni','IntegerHandle','off');
subplot(2,3,1); plot(Y1(1:96000*3,1));
subplot(2,3,2); plot(Y2(1:96000*3,1));
subplot(2,3,3); plot(Y3(1:96000*3,1));
subplot(2,3,4); plot(Y4(1:96000*3,1));
subplot(2,3,5); plot(Y5(1:96000*3,1));
subplot(2,3,6); plot(test(1:96000*3,1));

% Nota: segnale audio ha due canali (stereo),
% per la cross correlazione consideriamo solo il primo
% Array di celle: un metodo piu'veloce per raccogliere sequenze 
% di lunghezza diversa.
gallery{1}=Y1(:,1);
gallery{2}=Y2(:,1);
gallery{3}=Y3(:,1);
gallery{4}=Y4(:,1);
gallery{5}=Y5(:,1);

maxcc = zeros(5,1);
for g=1:5
    [xc{g},lagc{g}]= xcorr(gallery{g},test(:,1));
    maxcc(g) = max(abs(xc{g}));
end

figure; set(gcf,'name','Risultati di matching', ...
    'IntegerHandle','off');
for g=1:5
    subplot(2,3,g); plot(lagc{g},xc{g});
end

% trovo il segnale con la miglior cross correlazione
[maxcorr,bestmatch]=max(maxcc);

% trovo il lag della massima correlazione nel segnale
% col match migliore
[~,maxli]=max(xc{bestmatch});

% visualizzo il segnale originale
figure
plot(test(:,1),'-r','LineWidth',2);
hold on 
% visualizzo il best match
plot(gallery{bestmatch} ...
    (lagc{bestmatch}(maxli)+1:lagc{bestmatch}(maxli)+480001,1), ...
    '-k','LineWidth',1);
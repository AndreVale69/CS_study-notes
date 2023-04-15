% vettore riga
vec = [1:2:30];            
vec_media = MYmean(vec);    
media_Matlab = mean(vec);   
confronto = [vec_media; media_Matlab];   

% vettore colonna
vec1 = [2:2:30]';            
vec_media1 = MYmean(vec1);    
media_Matlab1 = mean(vec1);   
confronto1 = [vec_media1; media_Matlab1];

% matrice
A = [vec' vec1];            
mat_media = MYmean(A);
media_Matlab = mean(A);   
confronto1 = [mat_media; media_Matlab];
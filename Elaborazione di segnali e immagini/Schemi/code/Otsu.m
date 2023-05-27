function [weight,var] = Otsu(m,n,H,Index)

% Calcolo dei pesi

weight = sum(H(m:n))/sum(H);
    
% Calcolo della media

valore = H(m:n).*Index(m:n);
totale = sum(valore);
mean = totale/sum(H(m:n));

if(isnan(mean) == 1)  
    mean = 0;   
end

% Calcolo della varianza

valore2 = (Index(m:n)-mean).^2;
numer = sum(valore2.*H(m:n));
var = numer/sum(H(m:n));

if(isnan(var) == 1) 
    var = 0;  
end

    


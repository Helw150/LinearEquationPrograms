
function [a,o,s,n,k] =  partialp(a,o,s,n,k);

p=k;
maxim=abs(a(o(k),k)/s(o(k))); % the current largest entry

for ii = k+1:n
    holder=abs(a(o(ii),k)/s(o(ii))); %create a placeholder variable for the next location
    if holder > maxim
        maxim=holder;
        p=ii;
    end
end 


holder=o(p);     %perform the row swap
o(p) = o(k);  
o(k) = holder;   


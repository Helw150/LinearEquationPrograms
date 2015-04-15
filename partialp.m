
function [a, b] =  partialp(a, b)

p=k;
maxim=abs(a(k,k); % the current largest entry

for ii = k+1:N
    tmp=abs(a(ii,k)); %create a placeholder variable for the next location
    if tmp > maxim
        maxim=tmp;
        p=ii;
    end
end 

tmp=ab(p,:);     %perform the row swap
ab(p,:) = ab(k,:);  
ab(k) = tmp;   


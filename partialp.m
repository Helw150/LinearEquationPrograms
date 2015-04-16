
function [ab] =  partialp(ab,j,M)
p=j;
maxim=abs(ab(j,j)); % the first entry 
for i = j+1:M
    tmp=abs(ab(i,j)); %create a placeholder variable for the next location
    if tmp > maxim
       maxim=tmp;
       p=i;
    end
end 

tmp=ab(p,:);     %perform the row swap
ab(p,:) = ab(j,:);  
ab(j,:) = tmp;   

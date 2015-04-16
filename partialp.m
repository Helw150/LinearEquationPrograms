
function ab =  partialp(a,b)
ab = [a,b]
[M,N] = size(ab)
for j = 1:M-1
    p=j;
    maxim=abs(a(j,j)); % the first entry 

    for i = j+1:M
        tmp=abs(a(i,j)); %create a placeholder variable for the next location
        if tmp > maxim
           maxim=tmp;
           p=i;
        end
    end 

    tmp=ab(p,:);     %perform the row swap
    ab(p,:) = ab(j,:);  
    ab(j,:) = tmp;   
end

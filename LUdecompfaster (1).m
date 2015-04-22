function[L, U, P] = LUdecomp(A)
N = length(A);
P = eye(N)
U = A
for j = 1:M-1
    p = j;
    maxim = abs(U(j,j)); % the first entry 
    for i = j+1:M
        tmp = abs(ab(i,j));
        if tmp > maxim
           maxim = tmp;
           p = i;
        end
    end

    tmp = U(p,:);     %perform the row swap on U
    U(p,:) = U(j,:);  
    U(j,:) = tmp;
    tmp = P(p,:);     %perform the row swap on P
    P(p,:) = P(j,:);  
    P(j,:) = tmp;
    
     for k = j+1:N
        L(k,j) = U(k,j)/U(j,j);
        U(k,:) = U(k,:)-L(k,j)*U(j,:);
    end
end
endfunction
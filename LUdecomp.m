function[L, U, P] = LUdecomp(A)
N = length(A);
P = eye(N);
U = zeros(N);
L = zeros(N);
for j = 1:N
    p = j;
    maxim = abs(A(j,j)); % the first entry 
    for i = j+1:N
        tmp = abs(A(i,j));
        if tmp > maxim
           maxim = tmp;
           p = i;
        end
    end

    tmp = A(p,:);     %perform the row swap on U
    A(p,:) = A(j,:);  
    A(j,:) = tmp;
    tmp = P(p,:);     %perform the row swap on P
    P(p,:) = P(j,:);  
    P(j,:) = tmp;
   
    for i = 1:j 
           L(i,1) = A(i,1); 
	   U(i,i) = 1;
    end
    for i = 2:j
	U(1,i)= A(1,i)/L(1,1);
    end
    for k = 2:j 
        L(j,k)=A(j,k)-L(j,1:k-1)*U(1:k-1,k); 
    end 
    for k = j+1:N
        U(j,k)=(A(j,k)-L(j,1:j-1)*U(1:j-1,k))/L(j,j); 
    end
end
return;
disp("Permutation");
disp(P);
disp("Lower");
disp(L);
disp("Upper");
disp(U);
endfunction

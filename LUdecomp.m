function [L, U] = Decomposition(A)


M = length(A);
for i = 1:M
    L(i,1) = A(i,1); % Creates function for lower
    U(i,i) = 1; % Creates function for upper
end
for j = 2:M 
    U(1,j)= A(1,j)/L(1,1); % make the diagonal unit
end
for i = 2:M 
    for j = 2:i 
        L(i,j)=A(i,j)-L(i,1:j-1)*U(1:j-1,j);  % Creating Lower triangular matrix
    end 
    for j = i+1:M 
        U(i,j)=(A(i,j)-L(i,1:i-1)*U(1:i-1,j))/L(­i,i); % creating unit upper Matrix
    end
end
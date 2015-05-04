function [L, U, P] = luop(A)
U = A;
n = size(U, 1);
P = [1:n];
L = eye(n);
for (i = 1:n-1)
    m = i;
    maxim = abs(A(P(i),i));
    for j = i+1:n
	tmp = abs(A(P(j),i));
	if tmp > maxim
	   maxim = tmp;
	   m = j;
	end
    end
    tmp = P(m);
    P(m) = P(i);
    P(i) = tmp;
    tmp = U(m,:);
    U(m,:) = U(i,:);
    U(i,:) = tmp;
    L(i+1:n, i) = U(i+1:n,i)/U(i,i);
    U(i+1:n, i+1:n) = U(i+1:n,i+1:n) - L(i+1:n,i)*U(i,i+1:n);
    U(i+1:n, i) = 0;
end
endfunction

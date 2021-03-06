function x = Gauss(a,b)
ab = [a,b] 
[M, N] = size(ab); 
for j = 1:M-1 
   ab = partialp(ab,j,M)
% forward elimination

    for i = j+1:M
        ab(i,j:N) = ab(i,j:N)-ab(i,j)/ab(j,j)*ab(j,j:N)
    end
end
% bacjwards substitution
x = zeros(M,1);
x(M) = ab(M,N)/ab(M,M);
for i = M-1:-1:1
    x(i)=(ab(i,N)-ab(i,i+1:M)*x(i+1:M))/ab(i,i);
end

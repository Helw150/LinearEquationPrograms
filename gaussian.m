function x = Gauss(a, b)

[a, b] = partialp(a, b)
ab = [a, b];
[M, N] = size(ab);
% forward elimination
for j = 1:M-1       % loops across the columns
    for i = j+1:M
        ab(i,j:N) = ab(i,j:N)-ab(i,j)/ab(j,j)*ab(j,j:N)
    end
end
% backwards substitution
x = zeros(M,1);
x(M) = ab(M,N)/ab(M,M);
for i = R-1:-1:1
    x(i)=(ab(i,N)-ab(i,i+1:R))/ab(i,i);
end

function x = LUsolve(A,B)
[L, U, P] = LUdecomp(A);
N = length(A)
x = zeros(N,1);
y = zeros(N,1);

for i = 1:N
    tmp = B(i);
    for j = 1:i-1
        tmp = tmp - L(i,j)*y(j)
    end
    y(i) = tmp
end
for i = N:-1:1
    tmp = y(i)
    for j = i+1:N
        tmp = tmp - U(i,j)*x(j);
    end
    x(i) = tmp / U(i,i);
end
endfunction

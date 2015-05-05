function x = LUsolve(A,b)
[L, U, P] = luop(A);
n = length(A)
x = zeros(n,1);

for i = 2 : n
    sum=b(P(i));
    for j=1: i-1
        sum=sum - L(i, j)*b(P(j));
    end
    b(P(i))=sum;
end
x(n)=b(P(n))/U(n,n);

for i = n-1 :-1 :1
    sum=0;
    for j = i+1:n
        sum=sum+U(i,j)*x(j);
    end
    x(i)=(b(P(i))-sum)/U(i,i);
end
endfunction


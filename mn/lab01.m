clc;
clear all;
close all;

A = input('Podaj wspolrzedne [x1 y1; x2 y2; ...; xn yn]: ');

X=A(:,1);
x=X(1):0.1:X(length(X));

Y=A(:,2);

plot(X,Y,'or')
hold on;

for i=1:length(X)
    for j=1:length(Y)
        V(i,j)=X(i).^(j-1);
    end
end

A=inv(V)*Y;

y=A(1);
t=sprintf('L(x)=%0.4f', A(1));
for i=2:length(A)
    y=y+A(i)*x.^(i-1);
    if A(i)>0
        t=sprintf('%s+%0.4f*x^%d', t, A(i), i-1);
    else 
        t=sprintf('%s-%0.4f*x^%d', t, A(i), i-1);
    end
end

title(t);
plot(x,y,'b')
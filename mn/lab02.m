clc;
clear all;
close all;

A = input('Podaj wspolrzedne [x1 y1; x2 y2; ...; xn yn]: ');
n = input('Podaj N: ');

X=A(:,1);
x=X(1):0.1:X(length(X));

if n>length(X)
    disp('Zle n');
    return;
end

Y=A(:,2);

plot(X,Y,'or')
hold on;

P=zeros(n+1);
F=zeros(n+1,1);
for j=1:length(X)
    for a=1:n+1
        for b=1:n+1
            P(a,b)=P(a,b)+X(j)^(a+b-2);
        end
        F(a)=F(a)+X(j)^(a-1)*Y(j);
    end
end

A=inv(P)*F;

y=A(1);
t=sprintf('W(x)=%0.4f', A(1));
for i=2:length(A)
    y=y+A(i)*x.^(i-1);
    if A(i)>0
        t=sprintf('%s+%0.4f*x^%d', t, A(i), i-1);
    else 
        t=sprintf('%s%0.4f*x^%d', t, A(i), i-1);
    end
end

title(t);
plot(x,y,'b')
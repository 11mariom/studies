clc;
clear all;
close all;

F = input('WprowadŸ wzór funkcji: ', 's');
a = input('Podaj a: ');
b = input('Podaj b: ');
x = a:0.01:b;

y=inline(F);

plot(x,y(x))
hold on;

n = 0;
x = (a+b)/2;
i = 0;
while b-a >= 0.001
    if y(x) == 0
        b = a;
    elseif y(a)*y(x) < 0
        b = x;
    else
        a = x;
    end
    i = i+1;
    x = (a+b)/2;
end

title(sprintf('Rozwiazanie rownania %s=0 to %0.4f, liczba iteracji: %d', F, x, i));
plot(x,0,'*')
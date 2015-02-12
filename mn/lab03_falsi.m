clc;
clear all;
close all;

disp('Regu³a falsi')
F = input('WprowadŸ wzór funkcji: ', 's');
y = inline(F);

x = -2:0.01:2;
plot(x,y(x));
grid on

a = input('Podaj a: ');
b = input('Podaj b: ');
x = a:0.01:b;

close all;
plot(x,y(x))
hold on;

n = 0;
x(1) = (a*y(b)-b*y(a))./(y(b)-y(a));
i = 1;
d = 1;
while d >= 0.001
    if y(a)*y(x(i)) < 0
        x(i+1) = (x(i)*y(a)-a*y(x(i)))./(y(a)-y(x(i)));
    else
        x(i+1) = (x(i)*y(b)-b*y(x(i)))./(y(b)-y(x(i)));
    end
    i = i+1;
    d = abs(x(i)-x(i-1));
end

title(sprintf('Rozwi¹zanie równania %s=0 to %0.4f, liczba iteracji: %d', F, x(i), i));
plot(x(i),0,'*r')
grid on
disp(sprintf('%s=0 dla x=%0.4f', F, x(i)))

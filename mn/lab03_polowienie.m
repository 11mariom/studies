clc;
clear all;
close all;

disp('Metoda po³owienia')
F = input('WprowadŸ wzór funkcji: ', 's');
y = inline(F);

x = -10:0.01:10;
plot(x,y(x));

a = input('Podaj a: ');
b = input('Podaj b: ');
x = a:0.01:b;

close all;
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

title(sprintf('Rozwi¹zanie równania %s=0 to %0.4f, liczba iteracji: %d', F, x, i));
plot(x,0,'*r')
grid on
disp(sprintf('%s=0 dla x=%0.4f', F, x))
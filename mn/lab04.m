clc;
clear all;
close all;

%F = input('WprowadŸ wzór funkcji: ', 's');
F = 'x.^sin(x)';
y = inline(F);
a = 0;
b = 2*pi;
%a = input('Podaj a: ');
%b = input('Podaj b: ');

x = a:0.01:b;
plot(x,y(x),'k');
%grid on;
hold on;

n = 20;
h = (b-a)/n; % dok³adnoœæ

% wolfram
% d/dx(x^(sin(x))) = x^(sin(x)-1) (sin(x)+x log(x) cos(x))
f1 = x.^(sin(x)-1).*(sin(x)+x.*log(x).*cos(x));
plot(x,f1,'c');
hold on;

% wzór 2-punktowy
f2 = (y(x+h)-y(x))/h;
plot(x,f2,'r');
hold on;

% wzór 3-punktowy
f3 = (y(x+h)-y(x-h))/(2*h);
plot(x,real(f3),'b');
hold on;

% wzór 5-punktowy
f5 = (y(x-2*h)-8.*y(x-h)+8.*y(x+h)-y(x+2*h))/(12*h);
plot(x,real(f5),'g');
hold on;

legend('x^s^i^n^(^x^)', 'wolfram', '2-punktowy', '3-punktowy', '5-punktowy');

% ca³ki:
% metoda prostok¹tów
j1 = 0;
for i=a:h:(b-h)
    j1 = j1 + y(i);
end
j1 = j1 * h;

fprintf('Metoda prostok¹tów: %0.8f\n', j1)

% metoda trapezów
j2 = y(a)/2+y(b)/2;
for i=(a+h):h:(b-h)
    j2 = j2 + y(i);
end
j2 = j2 * h;

fprintf('Metoda trapezów: %0.8f\n', j2)

% metoda Simpsona
j3 = y(a) + y(b);
j3p = 0;
j3n = 0;
for i=(a+h):(h*2):(b-h)
    j3p = j3p + y(i);
end
j3 = j3 + 4*j3p;

for i=(a+2*h):(h*2):(b-2*h)
    j3n = j3n + y(i);
end
j3 = j3 + 2*j3n;
j3 = (h/3) * j3;

fprintf('Metoda Simpsona: %0.8f\n', j3)

% quad
fprintf('Funkcja quad: %0.8f\n', quad(y,a,b))

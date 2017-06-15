function[] = F74056069_hw3_prob2()
%prob1
figure(1);
m = 1.200*(10^3);
k = 58.00*(10^3);
b = 4.000*(10^3);
N = 10^4;   %set the steps in a second
h = 1/N;    %the length of each step
x0 = 10;
x = 10;
xx = 0;
xxx = 0; %F/m
g = 9.8;
get = 0;
hold on;
for i = 0:1:5*N
    xxx = (-k*x - b*xx - m*g)/m;
    xx = xx + h*(xxx);
    x = x + h*(xx) + ((h^2)/2)*(xxx);
    plot(i/N, x, '.B');
    if((h*(xx) + ((h^2)/2)*(xxx)) > 0 && get == 0)
        fprintf('frequency = %.5fHz\n', 1/(i*2/N));
        get = 1;
    end
end
hold off;
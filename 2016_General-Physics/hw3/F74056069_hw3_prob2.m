function[] = F74056069_hw3_prob2()
%prob(a)
figure(1);
title('Fig.1');
ylabel('x(t)');
xlabel('t(s)');
m = 1.200*(10^3);
k = 58.00*(10^3);
b = 4.000*(10^3);
N = 10^3;   %set the steps in a second
h = 1/N;    %the length of each step
x = 10;
xx = 0; %x'
xxx = 0; %F/m
g = 9.8; %x"
get = 0; 
hold on;
for i = 0:1:5*N
    xxx = (-k*x - b*xx - m*g)/m;
    xx = xx + h*(xxx);
    x = x + h*(xx) + ((h^2)/2)*(xxx);
    plot(i/N, x, '.B');
    if((h*(xx) + ((h^2)/2)*(xxx)) > 0 && get == 0)
        %because the slope of the graphic starts in negative number, and
        %will turn to positive at the point of half the wave, so we double
        %the time at the point, then we get the period of a wave
        fprintf('prob2_b:\n\nfrequency = %.5fHz\n', 1/(i*2/N));
        get = 1;
    end
end
hold off;
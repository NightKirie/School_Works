function[] = F74056069_quiz7_prob2()

g = 9.8;
N = 10^3;
h = 1/N;
y = 1.5;
yy = 20;
y1 = 0;
t = h;
figure(2);
title('Prob2');
xlabel('Time(s)');
ylabel('Height(m)');
grid on;
hold on;
for i = 1:1:3*N %0~3 second
    y1 = y + h*yy + (h^2)/2*(-g);
    plot(t, y1, '.B');
	yy = yy + h*(-g);
    y = y1;
    t = t + h;
end
hold off;
fprintf('Prob2:\ny(3) = %.4fm/s\n', y);
fprintf('y¡¦(3) = %.4fm/s\n', yy);
fprintf('Step size h = 0.001m\n');
fprintf('Using Second order Taylor¡¦s Method\n');
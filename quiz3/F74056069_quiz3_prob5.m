x = -1:0.001:1;
y1 = 2 * pi * cos(2 * pi * x) - (sin(2 * pi * (x + 0.1)) - sin(2 * pi * (x - 0.1))) / 0.2;
y2 = 2 * pi * cos(2 * pi * x) - (sin(2 * pi * (x + 0.01)) - sin(2 * pi * (x - 0.01))) / 0.02;
y3 = 2 * pi * cos(2 * pi * x) - (sin(2 * pi * (x + 0.001)) - sin(2 * pi * (x - 0.001))) / 0.002;
y4 = 2 * pi * cos(2 * pi * x) - (sin(2 * pi * (x + 0.0001)) - sin(2 * pi * (x - 0.0001))) / 0.0002;
semilogy(x, abs(y1), x, abs(y2), x, abs(y3), x, abs(y4));
title('Figure 5');
xlabel('x=[-1,1]');
ylabel('log(g`(x)) = log(sin(x*pi*x)`)');
legend('h=0.1','h=0.01','h=0.001','h=0.0001');
x = -1:0.001:1;
y1 = (sin(2 * pi * (x + 0.1)) - sin(2 * pi * x)) / 0.1;
y2 = (sin(2 * pi * (x + 0.01)) - sin(2 * pi * x)) / 0.01;
y3 = (sin(2 * pi * (x + 0.001)) - sin(2 * pi * x)) / 0.001;
y4 = (sin(2 * pi * (x + 0.0001)) - sin(2 * pi * x)) / 0.0001;
y5 = 2 * pi * cos(2 * pi * x);
plot(x, y1, x, y2, x, y3, x, y4, x, y5);
title('Figure 2');
xlabel('x=[-1,1]');
ylabel('g`(x) = sin(x*pi*x)`')
legend('h=0.1','h=0.01','h=0.001','h=0.0001', 'f`(x)');
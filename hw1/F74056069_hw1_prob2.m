function[] = F74056069_hw1_prob2()

k = 9 * 10^9;
[x,y] = meshgrid(-5:5,-5:5);
r = x.^2 + y.^2;
figure;
title('Electrical Field');
xlabel('x');
ylabel('y');
hold on;
quiver(x, y, (k./r) .* (x./r), (k./r) .* (y./r));
plot(0,0, 'Bo');
hold off;

x = -5:0.01:5;
figure;
hold on;
title('Electric Potential');
xlabel('x');
ylabel('V(x)');
plot(x, (k./abs(x+1) - k./abs(x-1)));
hold off;

h = 10^(-6);
figure;
hold on;
title('Electrical Field');
xlabel('x');
ylabel('E(x)');
plot(x, ((k./abs(x+1-h) - k./abs(x+1+h))./(2*h) - (k./abs(x-1-h) - k./abs(x-1+h))./(2*h)));
hold off;
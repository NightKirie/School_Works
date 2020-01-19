%% section 1
x = -5:0.1:5;
p = [3 -4 -1];
f = polyint(p, 2);
r = roots(f);
figure(1);
hold on;
plot(r, polyval(f, r), 'ro');
plot(x, polyval(f, x), 'b');
hold off;
grid on;

%% section 2
syms x;
i = 12:0.1:15;
f = exp(2*x) + 3*(x^2);
F = int(f, x);
solve

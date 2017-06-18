function[] = F74056069_hw1_prob3()

t = 0:0.001:10;
figure;
hold on;
title('V-t');
xlabel('t');
ylabel('V(t)');
plot(t, -20 .* exp(-0.01 .* (t.^2)) .* sin(20 .* pi .* t + 2 * pi / 5));
hold off;

t = 0:0.001:10;
figure;
hold on;
title('F-t');
xlabel('t');
ylabel('F(t)');
plot(t, 5 .* (-0.4 .* t .* exp(-0.01 .* (t.^2)) .* sin(20 .* pi .* t + 2 * pi / 5) - 400 .* pi .* exp(-0.01 .* (t.^2)) .* cos(20 .* pi .* t + 2 * pi / 5)));
hold off;

t=8;
fprintf('F(8) = %.6f\n',5 .* (-0.4 .* t .* exp(-0.01 .* (t.^2)) .* sin(20 .* pi .* t + 2 * pi / 5) - 400 .* pi .* exp(-0.01 .* (t.^2)) .* cos(20 .* pi .* t + 2 * pi / 5)));

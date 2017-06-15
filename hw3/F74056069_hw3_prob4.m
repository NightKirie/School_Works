function[] = F74056069_hw3_prob4()

%prob(b)
figure(5);
title('Prob4(b)');
ylabel('V');
xlabel('t(ms)');
L = 2*10^(-3);
R = 8;
C = 5*(10^(-6));
N = 10^3;
h = 1/N;
Vs = 0;
Vr = 0;
iii = 0;
ii = 0;
i = 0;  %I(t) = 0, I'(t) = 0, I"(t) = 0
hold on;
for j = 0:h:10
    t = j/N; 
    Vs = cos(6000*t);
    iii = (-6000*sin(6000*t) - i/C - R*ii)/L;
    ii = (-6000*sin(6000*t) - i/C - L*iii)/R;
    i = i + h*ii;
    plot(j, i, '.B');
end

hold off;
legend('Vs', 'Vr');


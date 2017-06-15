function[] = F74056069_hw3_prob4()

%prob(b)
figure(5);
title('Prob4(b)');
ylabel('V');
xlabel('t(ms)');
L = 2*10^(-3);
R = 8;
C = 5*(10^(-6));
N = 10^2;
h = 1/N;
Vs = 0;
Vr = 0;
iii = 0;
ii = 0;
i = 0;  %I(t) = 0, I'(t) = 0, I"(t) = 0
hold on;
for j = 0:h:10
    t = j/1000; 
    Vs = cos(6000*t);
    iii = (-6000*sin(6000*t) - i/C - R*ii)/L;
    ii = ii + iii*h/1000;
    i = i + h/1000*ii;
    plot(j, Vs, '.R', j, i*R, '.B');
    
end
hold off;
legend('Vs', 'Vr');

%prob(c)
figure(6);
title('Prob4(c)');
ylabel('V');
xlabel('t(ms)');
L = 2*10^(-3);
R = 8;
C = 5*(10^(-6));
N = 10^2;
h = 1/N;
Vs = 0;
Vr = 0;
iii = 0;
ii = 0;
i = 0;  %I(t) = 0, I'(t) = 0, I"(t) = 0
hold on;
for j = 0:h:10
    t = j/1000; 
    Vs = cos(10000*t);
    iii = (-10000*sin(10000*t) - i/C - R*ii)/L;
    ii = ii + iii*h/1000;
    i = i + h/1000*ii;
    plot(j, Vs, '.R', j, i*R, '.B');    
end
hold off;
legend('Vs', 'Vr');

%prob(d)
figure(7);
title('Prob4(b)');
ylabel('V');
xlabel('t(ms)');
L = 2*10^(-3);
R = 8;
C = 5*(10^(-6));
N = 10^2;
h = 1/N;
Vs = 0;
Vr = 0;
iii = 0;
ii = 0;
i = 0;  %I(t) = 0, I'(t) = 0, I"(t) = 0
hold on;
for j = 0:h:10
    t = j/1000; 
    Vs = cos(20000*t);
    iii = (-20000*sin(20000*t) - i/C - R*ii)/L;
    ii = ii + iii*h/1000;
    i = i + h/1000*ii;
    plot(j, Vs, '.R', j, i*R, '.B');
    
end
hold off;
legend('Vs', 'Vr');

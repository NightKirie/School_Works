function[] = F74056069_hw3_prob4()

%prob(a)
fprintf('Prob4_a:\n\n');
fprintf('Vs - Vc - VR - VL = 0(By KVL)\n');
fprintf('And because in Vc, Vc = Q/C, also, dQ/dt = I\n');
fprintf('In VR, VR = IR\n');
fprintf('In VL, VL = L(dI/dt)\n');
fprintf('So we differentiate the KVL with t, then we get dVs/dt = L(d^2(I)/dt^2) + R(dI/dt) + I/C\n');

%prob(b)
figure(5);
title('Fig.5');
ylabel('V');
xlabel('t(ms)');
L = 2*10^(-3);
R = 8;
C = 5*(10^(-6));
N = 4*10^2; %set total sample point in the period
h = 1/N;
Vs = 0;
Vr = 0;
iii = 0;
ii = 0;
i = 0;  %I(t) = 0, I'(t) = 0, I"(t) = 0
hold on;
for j = 0:h:10  %from 0~10 ms, h = 1/N ms
    t = j/1000; %t = j/1000 ms
    Vs = cos(6000*t);
    iii = (-6000*sin(6000*t) - i/C - R*ii)/L;
    ii = ii + iii*h/1000;
    i = i + h/1000*ii + (h/1000)^2/2*iii;
    plot(j, Vs, '.R', j, i*R, '.B');
    
end
hold off;
legend('Vs', 'Vr');

%prob(c)
figure(6);
title('Fig.6');
ylabel('V');
xlabel('t(ms)');
L = 2*10^(-3);
R = 8;
C = 5*(10^(-6));
N = 4*10^2; %set total sample point in the period
h = 1/N;
Vs = 0;
Vr = 0;
iii = 0;
ii = 0;
i = 0;  %I(t) = 0, I'(t) = 0, I"(t) = 0
hold on;
for j = 0:h:10  %from 0~10 ms, h = 1/N ms
    t = j/1000; %t = j/1000 ms
    Vs = cos(10000*t);
    iii = (-10000*sin(10000*t) - i/C - R*ii)/L;
    ii = ii + iii*h/1000;
    i = i + h/1000*ii + (h/1000)^2/2*iii;
    plot(j, Vs, '.R', j, i*R, '.B');    
end
hold off;
legend('Vs', 'Vr');

%prob(d)
figure(7);
title('Fig.7');
ylabel('V');
xlabel('t(ms)');
L = 2*10^(-3);
R = 8;
C = 5*(10^(-6));
N = 4*10^2; %set total sample point in the period
h = 1/N;
Vs = 0;
Vr = 0;
iii = 0;
ii = 0;
i = 0;  %I(t) = 0, I'(t) = 0, I"(t) = 0
hold on;
for j = 0:h:10  %from 0~10 ms, h = 1/N ms
    t = j/1000; %t = j/1000 ms
    Vs = cos(20000*t);
    iii = (-20000*sin(20000*t) - i/C - R*ii)/L;
    ii = ii + iii*h/1000;
    i = i + h/1000*ii + (h/1000)^2/2*iii;
    plot(j, Vs, '.R', j, i*R, '.B');
    
end
hold off;
legend('Vs', 'Vr');

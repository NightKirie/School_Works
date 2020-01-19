function[] = F74056069_quiz7_prob1()

N1 = 10^3;
h1 = 1/N1;
%R*c = 1 so ignore
E = 5;
Vc = 0.5;
Vcc = 4.5;
Vc1 = 0;
t = 0;
figure(1);
title('Prob1-1');
xlabel('Time(s)');
ylabel('Vc(t1) - Vc(t0)');
grid on;
hold on;
for i = 0:1:5*N1    %t = 10^(-5)second
    Vc1 = Vc + h1*(E - Vc) + (h1^2)/2*(E - Vc - Vcc);
    t = t + h1;
    plot(t, Vc1 - Vc,'.R');
    Vc = Vc1;
    Vcc = E - Vc;
end
hold off;
fprintf('Prob1_1:\nUsing Second order Taylor¡¦s Method with h = 0.001 and t = 0~5 second\n\n');
Vc = 0.5;
Vcc = 4.5;
Vc1 = 0;
t = 0;
while(t < 0.5)
    Vc1 = Vc + h1*(E - Vc) + (h1^2)/2*(E - Vc - Vcc);
    t = t + h1;
    Vc = Vc1;
    Vcc = E - Vc;
end
fprintf('Prob1_2:\nThe capacitor¡¦s voltage at t = 0.5 sec =  %.4fV\n\n', Vc);
Vc = 0.5;
Vcc = 4.5;
Vc1 = 0;
t = 0;
while(Vc < 3.5)
    Vc1 = Vc + h1*(E - Vc) + (h1^2)/2*(E - Vc - Vcc);
    t = t + h1;
    Vc = Vc1;
    Vcc = E - Vc;
end
fprintf('Prob1_3:\nIt takes %.4f second to charge up to 3.5V\n\n', t);


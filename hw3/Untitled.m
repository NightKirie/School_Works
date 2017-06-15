%prob(d)
figure(4);
N = 10^6;   %set the steps in a second
h = 1/N;    %length of each step
E = 0;
t = 0;
s = 0.5;
Vc = 0;
Vcc = 0;
Vccc = 0;
RC = 10^(-4);
title('Prob3(d)');
ylabel('Vc(t)');
xlabel('t(s)');
hold on;
for i = 0:1:N/100*6
    Vcc = (E - Vc)/RC;
    Vccc = (s - (E - Vc)/RC)/RC;
    Vc = Vc + h*Vcc + ((h^2)/2)*Vccc; 
    Vr = E - Vc;
    plot(t,E - Vc,'.B');
    t = t + h;
    if(rem(floor((i + N/100)/(N/50)),2) == 1)
        E = E - 500/N;
        s = -500/N;
    elseif(rem(floor((i + N/100)/(N/50)),2) == 0)   
        E = E + 500/N;
        s = 500/N;
    end
end
hold off;

%prob(d)
figure(5);
N = 10^4;   %set the steps in a second
h = 1/N;    %length of each step
E = 0;
t = 0;
s = 0.5;
Vc = 0;
Vcc = 0;
Vccc = 0;
RC = 10^(-4);
title('Prob3(d)');
ylabel('Vc(t)');
xlabel('t(s)');
hold on;
for i = 0:1:N/100*6
    Vcc = (E - Vc)/RC;
    Vccc = (s - (E - Vc)/RC)/RC;
    Vc = Vc + h*Vcc + ((h^2)/2)*Vccc; 
    plot(t,E - Vc,'.B');
    t = t + h;
    if(rem(floor((i + N/100)/(N/50)),2) == 1)
        E = E - 500/N;
        s = -500/N;
    elseif(rem(floor((i + N/100)/(N/50)),2) == 0)   
        E = E + 500/N;
        s = 500/N;
    end
end
hold off;

%prob(d)
figure(4);
N = 10^3;   %set the steps in a second
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
for i = 0:1:50
    Vcc = (E - Vc)/RC;
    Vccc = (s - (E - Vc)/RC)/RC;
    vc = Vc + h*Vcc + ((h^2)/2)*Vccc; 
    plot(t,E - Vc,'.B');
    t = t + h;
    if(rem(floor((i+10)/20),2) == 1)
        E = E - 0.5;
        s = -0.5;
    elseif(rem(floor((i+10)/20),2) == 0)   
        E = E + 0.5;
        s = 0.5;
    end
end
hold off;

%prob(d)
figure(5);
N = 10^3;   %set the steps in a second
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
for i = 0:1:50
    Vcc = (E - Vc)/RC;
    Vccc = (s - (E - Vc)/RC)/RC;
    vc = Vc + h*Vcc; 
    plot(t,E - Vc,'.B');
    t = t + h;
    if(rem(floor((i+10)/20),2) == 1)
        E = E - 0.5;
        s = -0.5;
    elseif(rem(floor((i+10)/20),2) == 0)   
        E = E + 0.5;
        s = 0.5;
    end
end
hold off;
%prob(d)
figure(6);
N = 10^5;   %set the steps in a second
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
for i = 0:1:50
    Vcc = (E - Vc)/RC;
    Vccc = (s - (E - Vc)/RC)/RC;
    vc = Vc + h*Vcc; 
    plot(t,E - Vc,'.B');
    t = t + h;
    if(rem(floor((i+10)/20),2) == 1)
        E = E - 0.5;
        s = -0.5;
    elseif(rem(floor((i+10)/20),2) == 0)   
        E = E + 0.5;
        s = 0.5;
    end
end
hold off;
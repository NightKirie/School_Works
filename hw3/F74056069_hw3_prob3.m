function[] = F74056069_hw3_prob3()

%prob(a)
fprintf('Prob3_a:\n\n')
fprintf('£`(t) - CR(d(Vc(t))/dt) - Vc(t) = 0\n');    %I = dQ/dt = C(d(Vc(t))/dt) & KVL

%prob(b)
figure(2);
N = 10^3;   %set the steps in a second
h = 1/N;    %length of each step
t = 0;
Vc = 0;
Vcc = 0;
Vccc = 0;
%RC = 1
title('Prob3(b)');
ylabel('Vc(t)');
xlabel('t(s)');
hold on;
for i = 0:1:5*N
    Vc = Vc + h*Vcc + ((h^2)/2)*Vccc; 
    plot(t,Vc, 'B.');
    t = t + h;
    Vccc = 100*cos(20*pi*t) - 5*sin(20*pi*t) + Vc;
    Vcc = 5*sin(20*pi*t) - Vc;
end
hold off;

%prob(c)
figure(3);
N = 10^3;   %set the steps in a second
h = 1/N;    %length of each step
E = 5;
Vc = 0;
Vcc = 0;
Vccc = 0;
%RC = 1
title('Prob3(c)');
ylabel('Vc(t)');
xlabel('t(s)');
hold on;
for i = 0:1:20*N
    Vcc = E - Vc;
    Vccc = Vc - E;
    Vc = Vc + h*Vcc + ((h^2)/2)*Vccc; 
    plot(i/N,Vc,'.B');
    if(rem(i,20) < 10)
        E = 5;
    elseif(rem(i,20) >= 10)
        E = -5;
    end
end
hold off;

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
for i = 0:1:N
    Vcc = (E - Vc) 
    vc = Vc + h*((E - Vc)/RC)+((h^2)/2)*(((Vc - E)/RC)/RC); 
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
for i = 0:1:N
    Vc = Vc + h*((E - Vc)/RC)+((h^2)/2)*(((Vc - E)/RC)/RC); 
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
for i = 0:1:N
    Vc = Vc + h*((E - Vc)/RC)+((h^2)/2)*(((Vc - E)/RC)/RC); 
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








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
Vcc = 0;    %Vc'(t)
Vccc = 0;   %Vc"(t)
%RC = 1
title('Prob3(b)');
ylabel('Vc(t)');
xlabel('t(s)');
hold on;
for i = 0:1:5*N     %time period from 0~5 second
    Vc = Vc + h*Vcc + ((h^2)/2)*Vccc; 
    plot(t,Vc, 'B.');
    t = t + h;
    Vccc = 100*cos(20*pi*t) - 5*sin(20*pi*t) + Vc; 
    Vcc = 5*sin(20*pi*t) - Vc;  
end
hold off;

%prob(c)
figure(3);
N = 10^4;   %set the steps in a second
h = 1/N;    %length of each step
E = 5;
t = 0;
Vc = 0;
Vcc = 0;    %Vc'(t)
Vccc = 0;   %Vc"(t)
%RC = 1
title('Prob3(c)');
ylabel('Vc(t)');
xlabel('t(s)');
hold on;
for i = 0:1:N/20    %time period from 0~50 ms    
    %set the E meets the graphic that given
    if(rem(floor(i/(N/100)),2) == 1)
        E = -5;
    elseif(rem(floor(i/(N/100)),2) == 0)
        E = 5;
    end
    Vcc = E - Vc;
    Vccc = Vc - E;
    Vc = Vc + h*Vcc + ((h^2)/2)*Vccc; 
    plot(t,Vc,'.B');
    t = t + h;
end
hold off;

%prob(d)
figure(4);
N = 10^5;   %set the steps in a second
h = 1/N;    %length of each step
E = 0;
t = 0;
s = 0.5;
Vc = 0;
Vcc = 0;    %Vc'(t)
Vccc = 0;   %Vc"(t)
RC = 10^(-4);
title('Prob3(d)');
ylabel('Vc(t)');
xlabel('t(s)');
hold on;
for i = 0:1:N/100*6     %time period from 0~60 ms
    Vcc = (E - Vc)/RC;  
    Vccc = (s - (E - Vc)/RC)/RC;
    Vc = Vc + h*Vcc + ((h^2)/2)*Vccc; 
    plot(t,E - Vc,'.B');
    t = t + h;
    %set the E meets the graphic that given
    %And set the slope for E'
    if(rem(floor((i + N/100)/(N/50)),2) == 1)   
        E = E - 500/N;
        s = -500/N;
    elseif(rem(floor((i + N/100)/(N/50)),2) == 0)   
        E = E + 500/N;
        s = 500/N;
    end
end
hold off;







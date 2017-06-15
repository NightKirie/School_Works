v0 = 0;
t0 = 0;
C = 10^-4;
R = 10000;
figure
hold on
for t = 0:0.00001:0.05
if rem(t*1000,20) < 10               %when t%20 < 10   e = 5
    e = 5;
else
    e = -5;                         %when t%20 > 10   e = -5
end
v = v0 + (((e/(C*R))-(v0/(C*R)))*(t-t0)) + ((-(e/((C*R)^2)) + (v0/((C*R)^2)))*((t-t0)^2)/2);
%v = v0 + (((e)-(v0))*(t-t0)) + ((-(e) + (v0))*((t-t0)^2)/2);
t0 = t;
v0 = v;
plot(t,v,'b.');
end
hold off
title('Prob3(3)');
xlabel('t(s)');
ylabel('Vc(t)');

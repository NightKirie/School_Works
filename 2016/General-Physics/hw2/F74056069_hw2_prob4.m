function[] = F74056069_hw2_prob4()
%For (a)
%Plot the graph to find the section
figure(1);
x1 = -4:0.001:1.5;
y1 = 1/2 + (1/4).*x1 - x1.*sin(x1) - (1/2).*cos(2.*x1);
plot(x1,y1);
grid on;

%Find the largest negative root by Newton Raphson Method
p1 = 1;
while(abs(1/2 + (1/4)*p1 - p1*sin(p1) - (1/2)*cos(2*p1)) > 10^(-8)) %To get the 8 digits precision
    p1 = p1 - ((1/2 + (1/4)*p1 - p1*sin(p1) - (1/2)*cos(2*p1))/(1/4 - sin(p1) - p1*cos(p1) + sin(2*p1)));
end
%Find the smallest positive root by Newton Raphson Method
p2 = -4;
while(abs(1/2 + (1/4)*p2 - p2*sin(p2) - (1/2)*cos(2*p2)) > 10^(-8)) %To get the 8 digits precision
    p2 = p2 - ((1/2 + (1/4)*p2 - p2*sin(p2) - (1/2)*cos(2*p2))/(1/4 - sin(p2) - p2*cos(p2) + sin(2*p2)));
end
fprintf('The smallest positive root of Prob.4(a) is %.9f\n', p1);
fprintf('The largest negative root of Prob.4(a) is %.9f\n', p2);

%For (b)
%Plot the graph to find the section
figure(2);
x2 = -0.6:0.001:1;
y2 = exp(3.*x2) - 27.*(x2.^6) + 27.*(x2.^4).*exp(x2) - 9.*(x2.^2).*exp(2.*x2);
plot(x2,y2);
grid on;

%Find the largest negative root by Newton Raphson Method
p = 0.8;
p1 = (exp(3*p) - 27*(p^6) + 27*(p^4)*exp(p) - 9*(p^2)*exp(2*p));
while(abs(p-p1) > 10^(-8)) %To get the 8 digits precision
    p = p1;
    p1 = p - ((exp(3*p) - 27*(p^6) + 27*(p^4)*exp(p) - 9*(p^2)*exp(2*p))/(3*exp(3*p) - 162*(p^5) + 108*(p^3)*exp(p) + 27*(p^4)*exp(p) - 18*(p^2)*exp(2*p) - 18*(p^2)*exp(2*p)));
end
%Find the smallest positive root by Newton Raphson Method
p2 = -0.6;
while(abs(exp(3*p2) - 27*(p2^6) + 27*(p2^4)*exp(p2) - 9*(p2^2)*exp(2*p2)) > 10^(-8)) %To get the 8 digits precision
    p2 = p2 - ((exp(3*p2) - 27*(p2^6) + 27*(p2^4)*exp(p2) - 9*(p2^2)*exp(2*p2))/(3*exp(3*p2)-162*(p2^5) + 108*(p2^3)*exp(p2) + 27*(p2^4)*exp(p2) - 18*(p2^2)*exp(2*p2) - 18*(p2^2)*exp(2*p2)));
end
fprintf('The smallest positive root of Prob.4(b) is %.9f\n', p1);
fprintf('The largest negative root of Prob.4(b) is %.9f\n', p2);

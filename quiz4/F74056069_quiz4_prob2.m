function[] = F74056069_quiz4_prob2
figure
temp3 = 0;
NN = 10^(3);
hh = 2 / NN;
for i = 0:2:NN-1
    temp3 = temp3 + hh.*((1/3).*(exp(-((i.*hh)^2))) + (4/3).*(exp(-(((i+1).*hh)^2))) + (1/3).*(exp(-(((i+2).*hh)^2))));
end
for x = 1:1:4
    N = 10^(x);
    temp2 = 0;
    h = 2 / N;
    for i = 0:1:N-1
        temp2 = temp2 + h.*0.5.*(((exp(-(i.*h)^2))) + (exp(-(((i+1).*h)^2))));
    end
        y1 = abs(temp2 - temp3);
        loglog(h,y1,'b.');
        hold on; 

end
fprintf('the ans of using Trapezoid Method = %.9f\n', temp2);
fprintf('the ans of using Simpson¡¦s Method = %.9f\n', temp3);
fprintf('the optimal choice of h of Trapezoid method = 10^(-4)\n');
fprintf('the optimal choice of h of Simpson¡¦s Method = 10^(-2)\n');
fprintf('the real ans = %.9f\n',pi^(1/2)/2*erf(2));
hold off;

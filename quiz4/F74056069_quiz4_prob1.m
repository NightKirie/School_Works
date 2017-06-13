function[] = F74056069_quiz4_prob1
figure
   
for x = 8:1:9
    N = 10^(x);
    y0 = sin(pi * 0.5) - sin(pi * 0.25);
    temp1 = 0;
    temp2 = 0;
    h = 0.25 / N;
    for i = 0:N-1
        temp1 = temp1 + h.*(pi * cos(pi * (0.25 + i.*h)));
        temp2 = temp2 + h.*0.5.*((pi * cos(pi * (0.25 + i.*h))) + (pi * cos(pi * (0.25 + (i+1).*h))));
    end
        y1 = abs(temp1 - y0);
        y2 = abs(temp2 - y0);
        loglog(h,y1,'b.');
        hold on; 
        loglog(h,y2,'r.');

end
fprintf('the ans of using Riemman Sum = %.9f\n', temp1);
fprintf('the ans of using Trapezoid method = %.9f\n', temp2);
fprintf('the ans of using integral = %.9f\n', y0);
fprintf('the optimal choice of h of Riemman Sum = 10^(-9)\n');
fprintf('the optimal choice of h of Trapezoid method = 10^(-4)\n');
hold off;

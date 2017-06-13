function [] = F74056069_quiz5_prob1()

x = -1:0.01:1;
y = 3.*(x.^2) - exp(x);
plot(x, y);
grid on;

a1 = -0.6;
b1 = -0.4;
root1 = 1;
i1 = 0;
while(root1 > 10^(-6))
    c1 = (a1 + b1) / 2;
    if((3*(a1^2) - exp(a1)) * (3*(c1^2) - exp(c1)) < 0)
        b1 = c1;
        root1 = abs((a1 - b1) / a1);
    else
        a1 = c1;
        root1 = abs((a1 - b1) / a1);
    end
    i1 = i1 + 1;
end
fprintf('Prob1_a:\nthe largest negative root Multiple Partition Method = %.7f\ntotal run time = %d\n\n', (a1+b1)/2, i1);

p1 = 0.9;
p = p1 - ((3*(p1^2) - exp(p1)) / ((6*p1) - exp(p1)));
i2 = 0;
while(3*(p^2) - exp(p) > 10^(-10))
    p1 = p;
    p = p1 - ((3*(p1^2) - exp(p1)) / ((6*p1) - exp(p1)));
    i2 = i2 + 1;
end

fprintf('Prob1_b:\nthe smallest positive root using Newton¡¦s Method = %.11f\ntotal run time = %d\n\n', p, i2);
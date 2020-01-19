function[] = F74056069_quiz5_prob2()

x = 2.6:0.001:3;
y = x + 3*cos(x);
plot(x,y);
grid on;

p1 = 2.65;
p = p1 - ((p1 + 3*cos(p1))/(1 - 3*sin(p1)));
i1 = 1;
while(abs(p1 - p) > 10^(-6))
   p1 = p;
   p = p1 - ((p1 + 3*cos(p1))/(1 - 3*sin(p1)));
   i1 = i1 + 1;
end    
fprintf('Prob2_a:\none of the solution using Newton¡¦s Method	= %.7f\ntotal run time = %d\n\n', p, i1);

s1 = 2.65;
s2 = 2.7;
s = s2 - (((s2 + 3*cos(s2))*(s2 - s1)) / ((s2 + 3*cos(s2)) - (s1 + 3*cos(s1))));
i2 = 1;
while(abs(s1 - s2) > 10^(-8))
    s1 = s2;
    s2 = s;  
    s = s2 - (((s2 + 3*cos(s2))*(s2 - s1)) / ((s2 + 3*cos(s2)) - (s1 + 3*cos(s1))));
    i2 = i2 + 1;
end    
fprintf('Prob2_b:\nthe medium solution using Secant method = %.9f\ntotal run time = %d\n\n', s, i2);
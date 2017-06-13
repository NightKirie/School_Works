function[] = F74056069_quiz6_prob2()

%For (a)
fprintf('(a) Jacobi Method\n');

%For (b)
T = [0 1/4 -1/4 1/4; 1/4 0 -1/4 -1/4; -1/5 -1/5 0 1/5; 1/3 -1/3 1/3 1/3];
c = [-2/4; -1/4; 0; 1/3];
fprintf('(b) x = Tx + c\n');
T
c

%For (c)
fprintf('(c) initial (x1, x2, x3, x4) = (0, 0, 0, 0)\n');

%For (d)
x10 = 0;
x20 = 0;
x30 = 0;
x40 = 0;
x11 = (1/4)*(-x20 + x30 - x40 - 2);
x21 = (1/4)*(-x10 + x30 + x40 - 1);
x31 = (1/5)*(x10 + x20 - x40);
x41 = (1/3)*(-x10 + x20 - x30 + 1);
count = 1;
while((abs(x11 - x10) > 10^(-8)) || (abs(x21 - x20)  > 10^(-8)) || (abs(x31 - x30) > 10^(-8)) || (abs(x41 - x40) > 10^(-8)))
    x10 = x11;
    x20 = x21;
    x30 = x31;
    x40 = x41;
    x11 = (1/4)*(-x20 + x30 - x40 - 2);
    x21 = (1/4)*(-x10 + x30 + x40 - 1);
    x31 = (1/5)*(x10 + x20 - x40);
    x41 = (1/3)*(-x10 + x20 - x30 + 1); 
    count = count + 1;
end
fprintf('(d) We need %d iterations\nx1 = %.8f\nx2 = %.8f\nx3 = %.8f\nx4 = %.8f\n', count, x10, x20, x30, x40);
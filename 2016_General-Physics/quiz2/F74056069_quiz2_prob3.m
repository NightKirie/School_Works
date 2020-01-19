function [a] = F74056069_quiz2_prob3
disp('PRO3-2');
x = 0.01;
b = sprintf('A(3,0.01)');
disp(b);
a = 0;
for i=0:3
    a = a + (x^i)/factorial(i);
end
a = 1/a;
b = sprintf('%.8f',a);
disp(b);
a = sprintf('B(3,0.01)');
disp(a);
a = 0;
x = 0.01;
for i=0:3
    a = a + ((-1)^i)*(x^i)/factorial(i);
end
b = sprintf('%.8f',a);
disp(b);
a = sprintf('EXP(-0.01)');
disp(a);
a = exp(-0.01);
b = sprintf('%.8f',a);
disp(b);
b = sprintf(' it require 4 terms to	converge with accuracy up to 8 significant digits');
disp(b);


disp('PRO3-3');

x = 1;
b = sprintf('A(10,1)');
disp(b);
a = 0;
for i=0:10
    a = a + ((x^i)/factorial(i));
end
a = 1/a;
b = sprintf('%.8f',a);
disp(b);
a = sprintf('B(11,1)');
disp(a);
a = 0;
x = 1;
for i=0:11
    a = a + ((-1)^i)*(x^i)/factorial(i);
end
b = sprintf('%.8f',a);
disp(b);
a = sprintf('EXP(-1)');
disp(a);
a = exp(-1);
b = sprintf('%.8f',a);
disp(b);
b = sprintf(' it require 11  terms for A to	converge with accuracy up to 8 significant digits');
disp(b);
b = sprintf(' it require 12 terms for B to	converge with accuracy up to 8 significant digits');
disp(b);




disp('PRO3-4');
for k=16:22
    x = 20;
    b = sprintf('A(%d,20)',k);
    disp(b);
    a = 0;
    for i=0:25
       a = a + ((x^i)/factorial(i));
    end
    a = 1/a;
    b = sprintf('%.8f',a);
    disp(b);
    a = sprintf('B(&d,20)',k);
    disp(a);
    a = 0;
    x = 20;
    for i=0:25
        a = a + ((-1)^i)*(x^i)/factorial(i);
    end
    b = sprintf('%.8f',a);
    disp(b);
    a = sprintf('EXP(-%d)',k);
    disp(a);
    a = exp(-20);
    b = sprintf('%.8f',a);
    disp(b);

end

disp('B會爆炸');
disp('泰勒展開式的收斂區間為1~-1');
disp('A is a good precision')

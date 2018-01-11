%% Section 1(a)
h = 0.1;
x = 0:h:0.5;
xn = x;
num = numel(x);
syms x;
syms y;
f = @(x,y)(x^2 + y^2);
a(1) = 1;
for i = 1:num-1
    a(i+1) = a(i) + h*subs(f,[x,y], [1+h*(i-1), a(i)]);
end
result = [xn' a']

%% Section 1(b)
h = 0.1;
xn = 0:h:0.5;
num = numel(xn);
yn = zeros(1,num);
yyn = zeros(1,num);
yn(1) = -2;
yyn(1) = 1;
syms x;
syms y;
syms yy;
f = 4*yy - 4*y;
for i = 1:num-1
    yn(i+1) = yn(i) + h*yyn(i);
    yyn(i+1) = yyn(i) + h*subs(f,[yy, y], [yyn(i), yn(i)]);
end
result = [xn' yn']

%% Section 2(a)

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

%% Section 2(a)

%% Section 2(b)

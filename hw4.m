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
    a(i+1) = a(i) + h*subs(f,[x,y], [xn(i), a(i)]);
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
h = 0.1;
xn = 0:h:0.5;
num = numel(xn);
syms x;
syms y;
f = 2*x- 3*y + 1;
Ad = zeros(1, num);
yn = zeros(1, num);
Ad(1) = 1;

for i = 1:4
    k1=subs(f,[x,y],[xn(i),Ad(i)]);
    k2=subs(f,[x,y],[xn(i)+h/2,Ad(i)+h/2*k1]);
    k3=subs(f,[x,y],[xn(i)+h/2,Ad(i)+h/2*k2]);
    k4=subs(f,[x,y],[xn(i)+h,Ad(i)+h*k3]);
    Ad(i+1)=Ad(i)+h*(k1+2*k2+2*k3+k4)/6; 
end

for i = 5:num-1
    yn(i)=subs(f,[x,y],[xn(i),Ad(i)]); 
    ynstar= Ad(i) + h*(55*yn(i)-59*yn(i-1)+37*yn(i-2)-9*yn(i-3))/24;  
    yn(i+1)=subs(f,[x,y],[xn(i+1),ynstar]);
    Ad(i+1)=Ad(i)+h*(9*yn(i+1)+19*yn(i)-5*yn(i-1)+yn(i-2))/24;
end
[xn' Ad']


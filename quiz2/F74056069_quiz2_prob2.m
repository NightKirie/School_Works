function [a] = F74056069_quiz2_prob2
disp('PRO2');
disp('prob2-1');
for i= 2:2:10
    k = 10^(-i);
    a = sprintf('k=10^-%d',i);
    disp(a);
    x = ((500+k)+sqrt(((500+k)^2)-2000*k))/2;
    a = sprintf('未有理化\n    %.16f',x);
    disp(a);
    x = ((500+k)-sqrt((500+k)^2-2000*k))/2;
    a = sprintf('    %.16f',x);
    disp(a);
    x = 1000*k/((500+k)-sqrt(((500+k)^2)-2000*k));
    a = sprintf('有理化\n     %.16f',x);
    disp(a);
    x = 1000*k/((500+k)+sqrt(((500+k)^2)-2000*k));
    a = sprintf('     %.16f',x);
    disp(a);
end
disp('prob2-2');
y = ((-30.0003)+sqrt(((30.0003)^2)-4*0.0001*90))/0.0002;
a = sprintf('未有理化\n    %.16f',y);
disp(a);
y = ((-30.0003)-sqrt(((30.0003)^2)-4*0.0001*90))/0.0002;
a = sprintf('    %.16f',y);
disp(a);
y = (4*0.0001*90)/(0.0002*((-30.0003)-sqrt((30.0003^2)-4*0.0001*90)));
a = sprintf('有理化\n     %.16f',y);
disp(a);
y = (4*0.0001*90)/(0.0002*((-30.0003)+sqrt((30.0003^2)-4*0.0001*90)));
a = sprintf('     %.16f',y);
disp(a);
disp('prob2-3');
z = ((-300003)+sqrt(((300003)^2)-4*1*900000))/2;
a = sprintf('未有理化\n    %.16f',z);
disp(a);
z = ((-300003)-sqrt(((300003)^2)-4*1*900000))/2;
a = sprintf('    %.16f',z);
disp(a);
z = (4*1*900000)/(2*((-300003)-sqrt((300003^2)-4*1*900000)));
a = sprintf('有理化\n     %.16f',z);
disp(a);
z = (4*1*900000)/(2*((-300003)+sqrt((300003^2)-4*1*900000)));
a = sprintf('     %.16f',z);
disp(a);
disp('prob2-4');
u = (10^152)*((302)+sqrt(((302)^2)+24))/2;
a = sprintf('未有理化\n      %.16f',u);
disp(a);
u = (10^152)*((302)-sqrt(((302)^2)+24))/2;
a = sprintf('     %.16f',u);
disp(a);
u = (10^152)*(-24)/(2*((302)-sqrt((302^2)+24)));
a = sprintf('有理化\n     %.16f',u);
disp(a);
u = (10^152)*(-24)/(2*((302)+sqrt((302^2)+24)));
a = sprintf('     %.16f',u);
disp(a);
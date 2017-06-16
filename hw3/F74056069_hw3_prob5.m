function[] = F74056069_hw3_prob5()

R = 1.5*(10^11);
Ms = 2*(10^30);
Mp = 6*(10^24);
G = 6.67*(10^(-11));
%prob(a)
fprintf('Prob5_a:\n\n(d^2(Xp))/dt^2 = -GMsXp/(Xp^2 + Yp^2)^(3/2)\n');
fprintf('(d^2(Yp))/dt^2 = -GMsYp/(Xp^2 + Yp^2)^(3/2)\n\n');

%prob(b)
V = sqrt(G*Ms/R);
fprintf('Prob5_b:\n\nVc = %.2fm/s\n\n', V);
%F = GMsMp/R^2 = MpV^2/R
%V = (GMs/R)^(1/2)

%prob(c)
figure(8);
title('Fig.8');
xlabel('x(m)');
ylabel('y(m)');
x = R;
y = 0;
Vx = 0;
Vy = V;
ax = 0;
ay = 0;
h = 3600;
hold on;
for t = 1:h:40000000
    ax = -(G*Ms*x/((x^2 + y^2)^(3/2)));
    ay = -(G*Ms*y/((x^2 + y^2)^(3/2)));
    Vx = Vx + h*ax;
    Vy = Vy + h*ay;
    x = x + h*Vx + (h^2)/2*ax;
    y = y + h*Vy + (h^2)/2*ay;
    plot(x,y,'.B');
end
hold off;
figure(9);
title('Fig.9');
xlabel('t(s)');
ylabel('x(m)');
x = R;
y = 0;
Vx = 0;
Vy = V;
ax = 0;
ay = 0;
h = 3600;
hold on;
for t = 1:h:40000000
    ax = -(G*Ms*x/((x^2 + y^2)^(3/2)));
    ay = -(G*Ms*y/((x^2 + y^2)^(3/2)));
    Vx = Vx + h*ax;
    Vy = Vy + h*ay;
    x = x + h*Vx + (h^2)/2*ax;
    y = y + h*Vy + (h^2)/2*ay;
    plot(t,x,'.B');
end
hold off;
figure(10);
title('Fig.10');
xlabel('t(s)');
ylabel('y(m)');
x = R;
y = 0;
Vx = 0;
Vy = V;
ax = 0;
ay = 0;
h = 3600;
hold on;
for t = 1:h:40000000
    ax = -(G*Ms*x/((x^2 + y^2)^(3/2)));
    ay = -(G*Ms*y/((x^2 + y^2)^(3/2)));
    Vx = Vx + h*ax;
    Vy = Vy + h*ay;
    x = x + h*Vx + (h^2)/2*ax;
    y = y + h*Vy + (h^2)/2*ay;
    plot(t,y,'.B');
end
hold off;
%for find the period of the planet
x = R;
y = 0;
Vx = 0;
Vy = V;
ax = 0;
ay = 0;
h = 1;
get = 0;
hold on;
for t = 1:h:40000000
    ax = -(G*Ms*x/((x^2 + y^2)^(3/2)));
    ay = -(G*Ms*y/((x^2 + y^2)^(3/2)));
    Vx = Vx + h*ax;
    Vy = Vy + h*ay;
    x = x + h*Vx + (h^2)/2*ax;
    y = y + h*Vy + (h^2)/2*ay;
    if(h*Vx + (h^2)/2*ax > 0 && get == 0)   %the point that x start to increase is half the period of the planet
        fprintf('Prob5_c:\n\nThe period of the planet is %ds\n\n', t*2);
        get = 1;
    end
end
hold off;

%prob(d)
figure(11);
title('Fig.11');
xlabel('x(m)');
ylabel('y(m)');
x = R;
y = 0;
Vx = 0;
Vy = 0.7*V;
ax = 0;
ay = 0;
h = 1000;
hold on;
for t = 1:h:40000000
    ax = -(G*Ms*x/((x^2 + y^2)^(3/2)));
    ay = -(G*Ms*y/((x^2 + y^2)^(3/2)));
    Vx = Vx + h*ax;
    Vy = Vy + h*ay;
    x = x + h*Vx + (h^2)/2*ax;
    y = y + h*Vy + (h^2)/2*ay;
    plot(x,y,'.B');
end
hold off;
figure(12);
title('Fig.12');
xlabel('t(s)');
ylabel('x(m)');
x = R;
y = 0;
Vx = 0;
Vy = 0.7*V;
ax = 0;
ay = 0;
h = 1000;
hold on;
for t = 1:h:40000000
    ax = -(G*Ms*x/((x^2 + y^2)^(3/2)));
    ay = -(G*Ms*y/((x^2 + y^2)^(3/2)));
    Vx = Vx + h*ax;
    Vy = Vy + h*ay;
    x = x + h*Vx + (h^2)/2*ax;
    y = y + h*Vy + (h^2)/2*ay;
    plot(t,x,'.B');
end
hold off;
figure(13);
title('Fig.13');
xlabel('t(s)');
ylabel('y(m)');
x = R;
y = 0;
Vx = 0;
Vy = 0.7*V;
ax = 0;
ay = 0;
h = 1000;
hold on;
for t = 1:h:40000000
    ax = -(G*Ms*x/((x^2 + y^2)^(3/2)));
    ay = -(G*Ms*y/((x^2 + y^2)^(3/2)));
    Vx = Vx + h*ax;
    Vy = Vy + h*ay;
    x = x + h*Vx + (h^2)/2*ax;
    y = y + h*Vy + (h^2)/2*ay;
    plot(t,y,'.B');
end
hold off;

%prob(e)
x = R;
y = 0;
Vx = 0;
Vy = 0.7*V;
ax = 0;
ay = 0;
h = 1;
get = 0;
C1x = 0;
C1y = 0;
C2x = 0;
C2y = 0;
for t = 1:h:40000000
    ax = -(G*Ms*x/((x^2 + y^2)^(3/2)));
    ay = -(G*Ms*y/((x^2 + y^2)^(3/2)));
    Vx = Vx + h*ax;
    Vy = Vy + h*ay;
    x = x + h*Vx + (h^2)/2*ax;
    y = y + h*Vy + (h^2)/2*ay;
    if(h*Vx + (h^2)/2*ax > 0 && get == 0)   %the point that x start to increase is half the period of the planet
        fprintf('Prob5_e:\n\nThe period of the planet is %ds\n', t*2);
        C2x = R - abs(0-x);
        C2y= y;
        if(floor(sqrt(x^2 + y^2) + sqrt((x-C2x)^2 + (y-C2y)^2) / sqrt((R-x)^2 + (0 - y)^2)))
            fprintf('The trajectory is a ellipse\n\n');
        end
        get = 1;
    end
end

%prob(f)
figure(14)
title('Fig.14');
xlabel('N*V(x)');
ylabel('T^2/R^3(K)');
hold on;
for i = 0.2:0.001:1
x = R;
y = 0;
Vx = 0;
Vy = i*V;
ax = 0;
ay = 0;
h = 60;
for t = 1:h:40000000
    ax = -(G*Ms*x/((x^2 + y^2)^(3/2)));
    ay = -(G*Ms*y/((x^2 + y^2)^(3/2)));
    Vx = Vx + h*ax;
    Vy = Vy + h*ay;
    x = x + h*Vx + (h^2)/2*ax;
    y = y + h*Vy + (h^2)/2*ay;
    if(h*Vx + (h^2)/2*ax > 0)   %the point that x start to increase is half the period of the planet
        plot(i, ((R-x)^3)/(t^2)/10^21, '.b');
        break;
    end
end
end
hold off;





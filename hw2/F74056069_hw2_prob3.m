function[] = F74056069_hw2_prob3()

N = 10^3; %set total sections
k = 9*(10^9);
q = 1;

%For (1)
a1 = -0.5;
h = abs(a1*2)/N;    %set the dx & dy
sum1 = 0;
%calculate the intergration by Simpson's Method
for i = 0:N
    for j = 0:2:N-2
        sum1 = sum1 + ((h.^2)/3).*(((k*q*abs(a1))./((a1^2 + (a1 + i.*h).^2 + (a1 + j.*h).^2).^(3/2))) + 4.*((k*q*abs(a1))./((a1^2 + (a1 + i.*h).^2 + (a1 + (j + 1).*h).^2).^(3/2))) + ((k*q*abs(a1))./((a1^2 + (a1 + i.*h).^2 + (a1 + (j + 2).*h).^2).^(3/2))));
    end
end
fprintf('(1) The total flux is %.10f (Volt.m)\n', sum1*6);

%For (2)
a2 = -1;
h = abs(a2*2)/N;    %set the dx & dy
sum1 = 0;
%calculate the intergration by Simpson's Method
for i = 0:N
    for j = 0:2:N-2
        sum1 = sum1 + ((h.^2)/3).*(((k*q*abs(a2))./((a2^2 + (a2 + i.*h).^2 + (a2 + j.*h).^2).^(3/2))) + 4.*((k*q*abs(a2))./((a2^2 + (a2 + i.*h).^2 + (a2 + (j + 1).*h).^2).^(3/2))) + ((k*q*abs(a2))./((a2^2 + (a2 + i.*h).^2 + (a2 + (j + 2).*h).^2).^(3/2))));
    end
end
fprintf('(2) The total flux is %.10f (Volt.m)\n', sum1*6);

%For (3)
a3 = -1;
h = abs(a3*2)/N;    %set the dx & dy
sum3 = 0;
%calculate the intergration by Simpson's Method
for i = 0:N
    for j = 0:2:N-2
        sum3 = sum3 + ((h.^2)/3).*(((k*q*abs(a3 + 0.4))./(((a3 + 0.4)^2 + ((a3 - 0.4) + i.*h).^2 + ((a3 - 0.4) + j.*h).^2).^(3/2))) + 4.*((k*q*abs(a3 + 0.4))./(((a3 + 0.4)^2 + ((a3 - 0.4) + i.*h).^2 + ((a3 - 0.4) + (j + 1).*h).^2).^(3/2))) + ((k*q*abs(a3 + 0.4))./(((a3 + 0.4)^2 + ((a3 - 0.4) + i.*h).^2 + ((a3 - 0.4) + (j + 2).*h).^2).^(3/2))));
    end
end
for i = 0:N
    for j = 0:2:N-2
        sum3 = sum3 + ((h.^2)/3).*(((k*q*abs(a3 - 0.4))./(((a3 - 0.4)^2 + ((a3 - 0.4) + i.*h).^2 + ((a3 - 0.4) + j.*h).^2).^(3/2))) + 4.*((k*q*abs(a3 - 0.4))./(((a3 - 0.4)^2 + ((a3 - 0.4) + i.*h).^2 + ((a3 - 0.4) + (j + 1).*h).^2).^(3/2))) + ((k*q*abs(a3 - 0.4))./(((a3 - 0.4)^2 + ((a3 - 0.4) + i.*h).^2 + ((a3 - 0.4) + (j + 2).*h).^2).^(3/2))));
    end
end
fprintf('(3) The total flux is %.10f (Volt.m)\n', sum3*3);

%For (4)
a4 = -1;
h = abs(a4*2)/N;    %set the dx & dy
sum4 = 0;
%calculate the intergration by Simpson's Method
for i = 0:N
    for j = 0:2:N-2
        sum4 = sum4 + ((h.^2)/3).*(((k*q*abs(a4 + 2))./(((a4 + 2)^2 + ((a4 - 2) + i.*h).^2 + ((a4 - 2) + j.*h).^2).^(3/2))) + 4.*((k*q*abs(a4 + 2))./(((a4 + 2)^2 + ((a4 - 2) + i.*h).^2 + ((a4 - 2) + (j + 1).*h).^2).^(3/2))) + ((k*q*abs(a4 + 2))./(((a4 + 2)^2 + ((a4 - 2) + i.*h).^2 + ((a4 - 2) + (j + 2).*h).^2).^(3/2))));
    end
end
for i = 0:N
    for j = 0:2:N-2
        sum4 = sum4 + ((h.^2)/3).*(((k*q*abs(a4 + 2))./(((a4 + 2)^2 + ((a4 - 2) + i.*h).^2 + ((a4 - 2) + j.*h).^2).^(3/2))) + 4.*((k*q*abs(a4 + 2))./(((a4 + 2)^2 + ((a4 - 2) + i.*h).^2 + ((a4 - 2) + (j + 1).*h).^2).^(3/2))) + ((k*q*abs(a4 + 2))./(((a4 + 2)^2 + ((a4 - 2) + i.*h).^2 + ((a4 - 2)+ (j + 2).*h).^2).^(3/2))));
    end
end
fprintf('(4) The total flux is %.10f (Volt.m)\n', sum4*3);
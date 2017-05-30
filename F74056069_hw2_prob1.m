function [] = F74056069_hw2_prob1()

N1 = 10^(3);    %set the total points of using Simpson¡¦s Method
N2 = 10^(5);    %set the total points of using Trapezoid Method

%For (i)
h1 = pi / N1;   
h2 = pi / N2;
sum1 = 0;
sum2 = 0;

%count the answer of intergration by Simpson¡¦s Method.
%The answer will always be 2.1565156475 for any number bigger than N1
for i = 0:2:N1-2
    sum1 = sum1 + (h1/3) .* ((1./(1 + 2.*sin(i.*h1)).^(1/2)) + 4.*(1./(1 + 2.*sin((i + 1).*h1)).^(1/2)) + (1./(1 + 2.*sin((i + 2).*h1)).^(1/2)));
end

%count the answer of intergration by Trapezoid Method
for i = 0:N2-1
   sum2 = sum2 + (h2/2).*((1./(1 + 2.*sin(i.*h2)).^(1/2)) + (1./(1 + 2.*sin((i + 1).*h2)).^(1/2))); 
end

%set two numbers smaller than 1
temp1 = sum1;
temp2 = sum2;
while(temp1 >= 1 && temp2 >=1)
    temp1 = temp1 / 10;
    temp2 = temp2 / 10;
end

%check if the answer is at least 8 significant digits
if(temp1 - temp2 < 10^(-8))   
    fprintf('(i)%.10f\n', sum1);
end    

%For (ii)
h1 = 1/N1;
h2 = 1/N2;
sum1 = 0;
sum2 = 0;

%count the answer of intergration by Simpson¡¦s Method.
%The answer will always be 2.1565156475 for any number bigger than N1
for i = 0:2:N1-2
    sum1 = sum1 + (h1/3).*(((sin(50.*i.*h1))./(1 + (i.*h1).^2)) + 4.*((sin(50.*(i + 1).*h1))./(1 + ((i + 1).*h1).^2)) + ((sin(50.*(i + 2).*h1))./(1 + ((i + 2).*h1).^2)));
end

%count the answer of intergration by Trapezoid Method    
for i = 0:N2-1
    sum2 = sum2 + (h2/2).*(((sin(50.*i.*h2))./(1 + (i.*h2).^2)) + ((sin(50.*(i + 1).*h2))./(1 + ((i + 1).*h2).^2)));
end    

%set two numbers smaller than 1
temp1 = sum1;
temp2 = sum2;
while(temp1 >= 1 && temp2 >=1)
    temp1 = temp1 / 10;
    temp2 = temp2 / 10;
end

%check if the answer is at least 8 significant digits
if(temp1 - temp2 < 10^(-8))   
    fprintf('(ii)%.10f\n', sum1);
end    
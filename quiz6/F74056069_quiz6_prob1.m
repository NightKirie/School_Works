function[] = F74056069_quiz6_prob1()

a = [pi -exp(1) sqrt(2) -sqrt(3) sqrt(11); pi^2 exp(1) -exp(2) 3/7 0; sqrt(5) -sqrt(6) 1 -sqrt(2) pi; pi^3 exp(2) -sqrt(7) 1/9 sqrt(2)];
n = 2;
for i = 1:3
    for j = n:4
        a(j,:) = a(j,:) - (a(j,i)/a(i,i) .* a(i,:));
    end
    n = n + 1;
end

x4 = a(4,5) / a(4,4);
x3 = (a(3,5) - a(3,4)*x4) / a(3,3);
x2 = (a(2,5) - a(2,4)*x4 - a(2,3)*x3) / a(2,2);
x1 = (a(1,5) - a(1,4)*x4 - a(1,3)*x3 - a(1,2)*x2) / a(1,1);

fprintf('x1 = %.8f\nx2 = %.8f\nx3 = %.8f\nx4 = %.8f\n', x1 ,x2 ,x3, x4);
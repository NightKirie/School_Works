function[] = F74056069_quiz4_prob3
n = 0;
test = 10^(9);
for i = 1:test
    x = 8 * rand - 4;
    y = 4 * rand - 2;
    if(x^2 + 4*(y^2) <= 16)
        n = n + 1;
    end
end
fprintf('the area of Oval = %.5f\n', n/test*32);

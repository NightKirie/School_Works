function[] = F74056069_quiz6_prob3()

a = [1 -1 0 0 1; -3 5 -1 -1 0; 0 -1 8 -1 0; 0 -1 -1 11 0]; 
n = 2;
for i = 1:3
    for j = n:4
        a(j,:) = a(j,:) - (a(j,i)/a(i,i) .* a(i,:));
    end
    n = n + 1;
end

i4 = a(4,5) / a(4,4);
i3 = (a(3,5) - a(3,4)*i4) / a(3,3);
i2 = (a(2,5) - a(2,4)*i4 - a(2,3)*i3) / a(2,2);
i1 = (a(1,5) - a(1,4)*i4 - a(1,3)*i3 - a(1,2)*i2) / a(1,1);

I = i1;
R = 30/I;
fprintf('Total current = %.8f A\nTotal resistance = %.8f ohm\n', I, R);
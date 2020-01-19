function[] = F74056069_hw3_prob1()

%for prob1
fprintf('Prob1_1:\n\n');
fprintf('By mesh current:\n');
%I1 is the currnet in E-R1-R2 loop
%I2 is the current in R1-R2-R5 loop
%I3 is the current in R5-R4-R3 loop
fprintf('R1(I1 - I2) + R3(I1 - I3) - 15 = 0\n');    
fprintf('R1(I2 - I1) + R2I2 + R5(I2 - I3) = 0\n');
fprintf('R3(I3 - I1) + R4I3 + R5(I3 - I2) = 0\n');
fprintf('R1 = 12ohm, R2 = 18ohm, R3 = 6ohm, R4 = 6ohm, R5 = 24ohm\n\n');

%for prob2
fprintf('Prob1_2:\n\n');
fprintf('Using Gauss elimination:\n');
M = [6 -4 -2 5; -2 9 -4 0; -1 -4 6 0];  %the matrix make by the equation above
row = 3;
for i = 1:1:row-1   %pick the first no-zero number in the row, assume the first nozero number in n-row is Mni
    for j = i+1:1:row   %calculate the elimination of j row 
        M(j,:) = M(j,:) - (M(j,i)./M(i,i).*M(i,:)); 
    end
end
I3 = M(3,4)/M(3,3);
I2 = (M(2,4) - I3*M(2,3))/M(2,2);
I1 = (M(1,4) - I3*M(1,3) - I2*M(1,2))/M(1,1);
%I5 = |I3 _ I2|
fprintf('I5 = %.5fA\n', abs(I3 - I2));






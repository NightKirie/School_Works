function [] = F74056069_hw2_prob5()

%For (a)
fprintf('L1 = (Rmsme*(1 - (Me/(3*Me + 3*Ms))^(1/3)), 0)\n');
fprintf('L2 = (Rmsme*(1 - (Me/(3*Me + 3*Ms))^(1/3)), 0)\n');
fprintf('L3 = (-Rmsme*(1 + (5/12)*(Me/(Ms + Me))), 0)\n');

%For (b)
Ms = 198892*(10^25);
Me = 597219*(10^19);
x1 = 1 - ((Me/(3*Me + 3*Ms))^(1/3));
x2 = 1 + ((Me/(3*Me + 3*Ms))^(1/3));
x3 = 1 + (5/12)*(Me/(Ms + Me));
fprintf('The distance ratio of L1: %.7f\n', x1);
fprintf('The distance ratio of L2: %.7f\n', x2);
fprintf('The distance ratio of L3: %.7f\n', x3);

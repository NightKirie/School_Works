function [] = F74056069_hw2_prob2()

%set the number of total random points
N = 10^8;

count = 0;
for i = 1:1:N  
    x = rand*4 - 2; %set the x range
    y = rand*2 - 1; %set the y range
    z = rand*6 - 3; %set the z range
    if(9 * (x^2) + 36 * (y^2) +  4 * (z^2) <= 36)   %the number of points in the  ellipsoid 
        count = count + 1;
    end
end
fprintf('A total of %d random points are used; the volume of the ellipsoid is %.10f.\n', N, count / N * 48);

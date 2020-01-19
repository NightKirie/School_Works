A = zeros(4,20);
for j = 1:20
    A(1,j) = j * 2 * pi / 10;
end
for j = 1:20
    A(2,j) = cos(A(1,j));
end
for j = 1:20
    A(3,j) = sin(A(1,j));
end
for j = 1:20
    A(4,j) = 1 / sqrt(2) * (A(2,j) + A(3,j));
end
disp(A(:,10));
figure(1);
x1 = [A(1,1)];
for j = 2:20
    x1 = [x1,A(1,j)];
end
y1 = [A(2,1)];
for j = 2:20
    y1 = [y1,A(2,j)];
end
plot(x1,y1);
xlabel('Time(s)');
ylabel('Amplitude(m)');
figure(2);
y2 = [A(3,1)];
for j = 2:20
    y2 = [y2,A(3,j)];
end
y3 = [A(4,1)];
for j = 2:20
    y3 = [y3,A(4,j)];
end
plot(x1,y1,x1,y2,x1,y3);
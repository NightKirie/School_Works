fprintf('The binary representation of 123.456 is');
fprintf(' [');
array = NumToSngBin(123.456);
for i = 1:32
    if(i == 32) 
        fprintf('%d',array(i)); 
    end
    if(i < 32) 
        fprintf('%d ',array(i)); 
    end
end
fprintf(']\n');

fprintf('The decimal representation of [0 1 0 0 0 0 1 0 1 1 1 1 0 1 1 0 1 1 1 0 1 0 0 1 0 1 1 1 1 0 0 0] is');
disp(SngBinToNum([0 1 0 0 0 0 1 0 1 1 1 1 0 1 1 0 1 1 1 0 1 0 0 1 0 1 1 1 1 0 0 0]));

fprintf('The binary representation of 0.05 is');
fprintf(' [');
array = NumToSngBin(0.05);
for i = 1:32
    if(i == 32) 
        fprintf('%d',array(i)); 
    end
    if(i < 32) 
        fprintf('%d ',array(i)); 
    end    
end
fprintf(']\n');

fprintf('The decimal representation of [0 0 1 1 1 1 0 1 0 1 0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 0 0] is');
disp(SngBinToNum([0 0 1 1 1 1 0 1 0 1 0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 0 0]));

fprintf('The binary representation of -94.87 is');
fprintf(' [');
array = NumToSngBin(-94.87);
for i = 1:32
    if(i == 32) 
        fprintf('%d',array(i)); 
    end
    if(i < 32) 
        fprintf('%d ',array(i)); 
    end
end    
fprintf(']\n');

fprintf('The decimal representation of [1 1 0 0 0 0 1 0 1 0 1 1 1 1 0 1 1 0 1 1 1 1 0 1 0 1 1 1 0 0 0 0] is');
disp(SngBinToNum([1 1 0 0 0 0 1 0 1 0 1 1 1 1 0 1 1 0 1 1 1 1 0 1 0 1 1 1 0 0 0 0]));
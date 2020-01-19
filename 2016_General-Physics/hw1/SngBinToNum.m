function[float] = SngBinToNum(array)
    
    %get exponent from array[2]~array[9]
    x = 7;
    exp = 0;
    for i = 2:9
       exp = exp + array(i) * (2^x);
       x = x - 1;
    end
    
    %let p = exponent - bias
    p = exp - 127;
    
    %get integer part
    if(p >= 0)
        x = (p-1);
        sum = 2^p;
        for i = 10:9+p
            sum = sum + array(i) * (2^x);
            x = x - 1;
        end
    
        %get decimal places
        x = 1;
        for i = 10+p:32
            sum = sum + array(i) * ((1/2)^x);
            x = x + 1;
        end
    end
    if(p < 0)
        x = abs(p - 1);
        sum = 2^p;
        for i = 10:32
            sum = sum + array(i) * ((1/2)^x);
            x = x + 1;
        end    
    end
    
    %get positive or negative
    if(array(1) == 0)
        float = sum;
    end
    if(array(1) == 1)
        float = sum * (-1);
    end

end

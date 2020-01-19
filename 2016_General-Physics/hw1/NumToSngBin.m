function[array] = NumToSngBin(float)
    array = [0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]; 
    %get sign part
    if(float >= 0) 
        array(1) = 0;
    end
    if(float <  0) 
        array(1) = 1;
        float = float * (-1);
    end
    
    %get integer part
    int = floor(float);
    inttemp = int;
    %get decimal places
    deci = float - int; 
    decitemp = deci;
    
    %get exponent in decimal
    exp = 0;
    if(int == 0)
        exp = 1;
        while(decitemp < 1)
            exp = exp - 1;
            decitemp = decitemp * 2;
        end    
    end    
    if(int > 0)
        while(inttemp > 0)
            exp = exp + 1;
            inttemp = floor(inttemp / 2);
        end
    end
    exp = exp + 126;
    exptemp = exp;
    
    %get binary of exponent
    for i = 2:9
        array(11 - i) = exp - floor(exp / 2) * 2;
        i = i + 1;
        exp = floor(exp / 2);
    end
    
    %get binary of integer part
    i = exptemp - 118;
    while(int > 0 && i >= 10)        
        array(i) = int - floor(int / 2) * 2;
        int = floor(int / 2);
        i = i - 1;
    end
    while(float < 1)
        float = float * 2;
        exptemp = exptemp + 1;
        deci = deci * 2 - floor(deci * 2);
    end    
    %get binary of decimal places
    for i = exptemp-117:32
       array(i) = floor(deci * 2);
       deci = deci * 2 - floor(deci * 2);
    end
    
end
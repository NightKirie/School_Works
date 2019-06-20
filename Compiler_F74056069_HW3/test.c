void main(){
    int a = 1;
    int b = a++ + a++;
    while (a < 6){
        print(a);
        a++;
    }
    print(b);
    return;
}


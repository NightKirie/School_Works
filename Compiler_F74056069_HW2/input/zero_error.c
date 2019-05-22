/*
 * 2019 Spring Compiler Course Assignment 2 
 */

float c = 1.5; //set

//void printout();
int printout() {
    int a;
}
bool loop(int n, int m, int k);
bool loop(int n, int m, int k) {
    while (n > m) {
        n--;
    }
    return true;    //test
}

int main() {
    // Declaration
    int x;
    int i;
    int a = 5;
    string y = "She is a girl";

    print(y); // print

    // if condition
    if (a + 2 > 10) {
        x += a;
        print(x);
    } else {
        x = a % 10 + 10 * 7; /* Arithmetic */
        print(x + 3 * a);
    }
    loop(x, i);
    int c = 3 * loop(a, x, i);
    print("Hello World");
    if (x + 2 == 0)
        print(x);
    return 0; 
}

#include <stdio.h>

extern int mySquare();
extern int myPythonInC();
extern int myPattern();
extern int graphic();

int main(int argc, char *argv[]) {
    int a,b,n,fact;
    printf("Enter an integer you want square of: ");
    scanf("%d", &a);
    printf("Enter an integer you want factorial of: ");
    scanf("%d", &n);
    b= mySquare(a);
    fact=myPattern(n);
    printf("%d\n",b);
    printf("%d\n",fact);
    myPythonInC(1,argv);
    graphic(1,argv);
}

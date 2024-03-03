// a) Implement a function "int factorial(int x)" to calculate the factorial of x.
// b) Implement a function "double sine(double x, int qt)" to calculate the sine of x using the Taylor series with qt terms.
// How to use:
// $ make 1.exe
// $ ./1.out

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const double PI = 3.141592653589793;

double degreesToRadians(double degrees);
int factorial(int x);
double sine (double x, int qt);

int main(){
    double X[] = {30.0, 45.0, 60.0};
    for(int i = 0; i < sizeof(X)/sizeof(double); i++){
        double radians = degreesToRadians(X[i]);
        printf("Sine(%lf°)=%lf - Using 3 terms;\n", X[i], sine(radians, 3));
        printf("Sine(%lf°)=%lf - Using 6 terms;\n", X[i], sine(radians, 6));
        printf("Sine(%lf°)=%lf - Using std sin() terms;\n\n", X[i], sin(radians));
    }
}

double degreesToRadians(double degrees){
    return degrees*PI/180;
}

int factorial(int x){
    int product = 1;
    for(int i = 2; i <= x; i++){
        product *= i;
    }
    return product;
}

double sine(double x, int qt){
    double value = 0;
    for(int i = 0; i < qt; i++){
        int aux = 2*i+1;
        int signal = (i&1) == 0?1:-1;
        double term_value = pow(x, (double) aux)/factorial(aux);
        value += signal*term_value;
   }
   return value;
}



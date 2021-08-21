#include <stdio.h>
#include <math.h>


int getVar(double* a) {
    *a = 0;
    char ch = getchar();
    short int sign = 1;
    if (ch == '-') {
        sign = -1;
        ch = getchar();
    }

    while (ch <= '9' && ch >= '0') {
        (*a) = (*a) * 10.0 + (double)(ch - '0');
        ch = getchar();
    }

    if (!(ch == '.' || ch == '\n' || ch == ' ')) {
        *a = NAN;
        return 0;
    }

    if (ch == '.') {
        double exp = 10.0;
        ch = getchar();
        while (ch <= '9' && ch >= '0') {
            (*a) = (*a) + (double)(ch - '0') / exp;
            exp = exp * 10;
            ch = getchar();
        }

        if (!(ch == '\n' || ch == ' ')) {
            *a = NAN;
            return 0;
        }
    }

    (*a) = (*a) * sign;
    return 1;
}


int getVars(double* a, double* b, double* c) {
    int res = getVar(a) && getVar(b) && getVar(c);
    return res;
}


int solve(double a, double b, double c) {
    printf("%lf %lf %lf\n", a, b, c);
    
    if (a == 0) {
        if (b == 0) {
            printf("rewrite coefs");
            return 0;
        }
        printf("Root for linear equation: %lf", c / b);
        return 1;
    }
    int real = 1;
    double D;
    D = b * b - 4 * a * c;
    if (D < 0) {
        real = 0;
        printf("Roots are complex\n");
        D = -D;
    }
    else {
        printf("Roots are real\n");
    }
    D = sqrt(D);

    if (real) {
        double x1 = (-b - D) / (2 * a);
        double x2 = (-b + D) / (2 * a);
        if (x1 != x2)
            printf("Roots: x1 = %lf and x2 = %lf", x1, x2);
        else
            printf("Root: x = %lf", x1);
    }
    else {
        printf("Complex Roots: x1 = %lf - %lf" "i and x2 = %lf + %lf" "i", -b / (2 * a), D / (2 * a), -b / (2 * a), D / (2 * a));
    }
    return 1;
}

void equation(double* a, double* b, double* c) {
    printf("Please, enter the coefficients.\nExample: For equation 2x^2 + 4x + 5 = 0\nWrite: 2 4 5.\n");
    
    while (!getVars(a, b, c) || !solve(*a, *b, *c)) {
        printf("rewrite variables");
    }
    
    
    return;
}

int main() {
    double a = NAN, b = NAN, c = NAN, d = NAN;
    equation(&a, &b, &c);
    getchar();
    return 0;
}
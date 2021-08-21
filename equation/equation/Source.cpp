#include <stdio.h>
#include <math.h>


int getVar(double* a) {
    char ch;
    short int sign = 1;
    ch = getchar();
    if (ch == '-') {
        sign = -1;
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0') {
        (*a) = (*a) * 10.0 + (double)(ch - '0');
        ch = getchar();
    }
    if (!(ch == '.' || ch == '\n' || ch == ' ')) {
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
            return 0;
        }
    }
    (*a) = (*a) * sign;
    return 1;
}


int getVars(double* a, double* b, double* c) {
    return getVar(a) && getVar(b) && getVar(c);
}


int main() {
    double a = 0, b = 0, c = 0, d;
    int real = 1;
    printf("Please, enter the coefficients.\nExample: For equation 2x^2 + 4x + 5 = 0\nWrite: 2 4 5.\n");
    while (!getVars(&a, &b, &c)) {
        printf("rewrite variables");
    }
    printf("%lf %lf %lf\n", a, b, c);

    d = b * b - 4 * a * c;
    if (d < 0) {
        real = 0;
        printf("Roots are complex\n");
        d = -d;
    } else {
        printf("Roots are real\n");
    }
    d = sqrt(d);

    if (real) {
        double x1 = (-b - d) / (2 * a);
        double x2 = (-b + d) / (2 * a);
        if (x1 != x2)
            printf("Roots: x1 = %lf and x2 = %lf", x1, x2);
        else
            printf("Root: x = %lf", x1);
    } else {
        printf("Complex Roots: x1 = %lf - %lf" "i and x2 = %lf + %lf" "i", -b / (2 * a), d / (2 * a), -b / (2 * a), d / (2 * a));
    }

    getchar();
    return 0;
}
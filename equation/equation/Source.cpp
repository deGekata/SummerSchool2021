#include <stdio.h>
#include <math.h>


int getVar(double* a) {
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
    int res = getVar(a) && getVar(b) && getVar(c);
    if (*a == 0) {
        return 0;
    }
    return res;
}


int solve(double a, double b, double c) {
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
        printf("Complex Roots: x1 = %lf - %lf" "i and x2 = %lf + %lf" "i", -b / (2 * a), d / (2 * a), -b / (2 * a), d / (2 * a));
    }

}

void equation(double* a, double* b, double* c) {
    printf("Please, enter the coefficients.\nExample: For equation 2x^2 + 4x + 5 = 0\nWrite: 2 4 5.\n");
    while (!getVars(a, b, c)) {
        if (a == 0) {
            printf("first coefficient must not be equal to zero\n");
        }
        printf("rewrite variables");
    }
    printf("%lf %lf %lf\n", a, b, c);
    solve(*a, *b, *c);
}

int main() {
    double a = NAN, b = NAN, c = NAN, d = NAN;
    equation(&a, &b, &c);
    getchar();
    return 0;
}
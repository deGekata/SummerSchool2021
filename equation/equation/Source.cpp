#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int getVar (double* a) {
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


int getVars (double* a, double* b, double* c) {
    int res = getVar(a) && getVar(b) && getVar(c);
    return res;
}

void solveLinear(double b, double c, double* mem, int* roots_cnt) {
    if (b == 0) {
        if (c == 0) {
            (*mem) = NAN;
            (*roots_cnt) = 1;
            return;
        }
        roots_cnt = 0;
        return;
    }
    (*mem) = c / b;
    (*roots_cnt) = 1;
    return;
}

void solve (double a, double b, double c, double* mem, int* is_real, int* roots_cnt) {
    printf("%lf %lf %lf\n", a, b, c);
    
    

    if (a == 0) {
        solveLinear(b, c, mem, roots_cnt);
        return;
    }

    *is_real = 1;
    double D = b * b - 4 * a * c;
    if (D < 0) {
        *roots_cnt = 4;
        *is_real = 0;
        D = -D;
    }
    else {
        *roots_cnt = 2;
    }

    D = sqrt(D);

    if (*is_real) {
        double x1 = (-b - D) / (2 * a);
        double x2 = (-b + D) / (2 * a);
        if (x1 != x2) {
            *mem = x1;
            *(mem + 1) = x2;
        }
        else {
            *mem = x1;
            *roots_cnt = 1;
        }
    }
    else {
        *(mem) = -b / (2 * a);
        *(mem + 1) = D / (2 * a);
        *(mem + 2) = -b / (2 * a);
        *(mem + 3) = D / (2 * a)
    }
    return;
}

void printRoots(double* mem, int roots_cnt, int is_real) {
    printf("Solve for equation (%lf)*x^2 + (%lf)*x + (c) = 0 is:\n");
    if (roots_cnt == 0) {
        printf("No roots");
        return;
    }

    if (roots_cnt == 1 && isnan(*mem)) {
        printf("x belongs to R\n");
        return;
    }

    if (!is_real) {
        printf("Complex Roots: x1 = %lf - %lf" "i and x2 = %lf + %lf" "i\n", *mem, *(mem + 1), *(mem + 2), *(mem + 3));
        return;
    }

    for (int it = 0; it < roots_cnt; ++it) {
        printf("%lf ", mem[it]);
    }
    return;
}

void equation() {
    double* mem = (double*) calloc(4, sizeof(double));
    int is_real = 1, roots_cnt = 0;
    double a = NAN, b = NAN, c = NAN;
    printf ("Please, enter the coefficients.\n"
            "Example: For equation 2x^2 + 4x + 5 = 0\n"
            "Write: 2 4 5.\n");
    
    while (!getVars (&a, &b, &c)) {
        printf ("rewrite variables");
    }
    solve (a, b, c, mem, &is_real, &roots_cnt);
    printRoots (mem, roots_cnt, is_real);
    return;
}

int main() {
    equation ();
    getchar ();
    return 0;
}
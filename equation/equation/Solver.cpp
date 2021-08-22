#include "Solver.h"

struct Roots {
    int is_real = 1;
    int roots_cnt = 0;
    double* mem = ( double* ) calloc (4, sizeof (double));
    void init () {
        mem = ( double* ) calloc (4, sizeof (double));
        is_real = 1;
        roots_cnt = 0;
    }
};

struct Params {
    double a = NAN, b = NAN, c = NAN;
};

Params* readVars () {
    Params* vars = (Params*) calloc(1, sizeof(Params));
    printf ("Please, enter the coefficients.\n"
        "Example: For equation 2x^2 + 4x + 5 = 0\n"
        "Write: 2 4 5.\n");
    while (scanf ("%lf%lf%lf", &(*vars).a, &(*vars).b, &(*vars).c) != 3) {
        while (getchar () != '\n');
        printf ("rewrite variables\n");
    }
    return vars;
}

int equalToZero (double inp) {
    if (fabs (inp) < ___EPSILON) {
        return 1;
    }
    return 0;
}

int getVar (double* a) {
    *a = 0;
    char ch = getchar ();
    short int sign = 1;
    if (ch == '-') {
        sign = -1;
        ch = getchar ();
    }

    while (ch <= '9' && ch >= '0') {
        (*a) = (*a) * 10.0 + ( double ) (ch - '0');
        ch = getchar ();
    }

    if (!(ch == '.' || ch == '\n' || ch == ' ')) {
        *a = NAN;
        return 0;
    }

    if (ch == '.') {
        double exp = 10.0;
        ch = getchar ();
        while (ch <= '9' && ch >= '0') {
            (*a) = (*a) + ( double ) (ch - '0') / exp;
            exp = exp * 10;
            ch = getchar ();
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
    int res = getVar (a) && getVar (b) && getVar (c);
    return res;
}

void solveLinear (double b, double c, double* mem, int* roots_cnt) {
    if (equalToZero (b)) {
        if (equalToZero (c)) {
            (*mem) = NAN;
            (*roots_cnt) = 1;
            return;
        }
        roots_cnt = 0;
        return;
    }
    (*mem) = -c / b;
    (*roots_cnt) = 1;
    return;
}

void solveQuadratic (double a, double b, double c, int* is_real, double* mem,
    int* roots_cnt) {
    *is_real = 1;
    double D = b * b - 4 * a * c;
    a = a * 2; // optimization for -b +- D / 2a

    if (equalToZero (D)) {
        *mem = (-b - D) / a;
        *roots_cnt = 1;
        return;
    }

    *roots_cnt = 2;

    if (D < 0) {
        *roots_cnt = 4;
        *is_real = 0;
        D = -D;
    }

    D = sqrt (D); // optimization for -b +- sqrt(D) / 2a
    if (*is_real) {
        *mem = (-b - D) / a;
        *(mem + 1) = (-b + D) / a;
    } else {
        *(mem) = -b / a;
        *(mem + 1) = D / a;
        *(mem + 2) = -b / a;
        *(mem + 3) = D / a;
    }
    return;
}

void solve (double a, double b, double c, double* mem, int* is_real,
    int* roots_cnt) {

    if (equalToZero (a)) {
        solveLinear (b, c, mem, roots_cnt);
    } else {
        solveQuadratic (a, b, c, is_real, mem, roots_cnt);
    }

    return;
}

void printRoots (double* mem, int roots_cnt, int is_real, Params* params, FILE* thread) {
    fprintf (thread, "Solve for equation (%.14lf)*x^2 + (%.14lf)*x + (%.14lf) = 0 is:\n", (*params).a, (*params).b, (*params).c);
    if (roots_cnt == 0) {
        fprintf (thread, "No roots\n\n");
        return;
    }
    
    if (roots_cnt == 1 && isnan (*mem)) {
        fprintf (thread, "x belongs to R\n\n");
        return;
    }

    if (!is_real) {
        fprintf (thread, "Complex Roots: x1 = %.14lf - %.14lf"
            "i and x2 = %.14lf + %.14lf"
            "i\n\n",
            *mem, *(mem + 1), *(mem + 2), *(mem + 3));
        return;
    }

    for (int it = 0; it < roots_cnt; ++it) {
        fprintf (thread, "%.14lf ", mem[it]);
    }
    fprintf (thread, "\n\n");
    return;
}


Roots* equation (Params* params) {
    Roots* res = ( Roots* ) malloc (sizeof (Roots));
    (*res).init();
    for (int i = 0; i < 4; ++i) {
        (*res).mem[i] = NAN;
    }
    solve ((*params).a, (*params).b, (*params).c, (*res).mem, &(*res).is_real, &(*res).roots_cnt);

    return res;
}


int testAll () {
    
    int counter = 0;
    FILE* fp_in = fopen ("test.txt", "r");
    FILE* fp_out = fopen("log.txt", "w+");
    double a = 0, b = 0, c = 0;
   
    Roots* roots;
    for(int rep = 0; rep < 4; ++rep){
        fgetc (fp_in);
        char buff[100];
        fgets (buff, 100, fp_in);
        fscanf (fp_in, "%d", &counter);
        printf ("%d\n", counter);
        printf ("%s", buff);

        for (int it = 0; it < counter; ++it) {
            Params param;
            int last_dot = 0;
            fscanf (fp_in, "%lf%lf%lf", &(param.a), &(param.b), &(param.c));
            
            roots = equation(&param);
            int prev_pos = 0, n_pos = 0;
            n_pos = 80 * ( double ) (it + 1) / counter + 1;
            if (n_pos != prev_pos) {
                printf ("\r[");
                for (int stars = 80 * ( double ) (it + 1) / counter + 1; stars >= 0; --stars) {
                    printf ("*");
                }
                for (int stars = 80 - 80 * (it + 1) / counter; stars > 0; --stars) {
                    printf ("-");
                }
                printf ("]");
                printf (" %d / %d", it + 1, counter);
            }
            if (checkEquation (param.a, param.b, param.c, roots)) {
                fprintf (fp_out, "ERROR: ");
                printRoots ((*roots).mem, (*roots).roots_cnt, (*roots).is_real, &param, fp_out);
            }
        }

        printf ("\rCompleted                                                                                   \n\n");
    }
    fclose (fp_in);
    fclose (fp_out);
    return 1;
}

int checkEquation (double a, double b, double c, Roots* roots) {
    if (checkXAny (a, b, c, roots)) {
        return 1;
    }

    if (checkNoneRoots (a, b, c, roots)) {
        return 1;
    }

    if ((*roots).is_real == 1) {
        if (checkLinearQuadratic (a, b, c, roots)) {
            return 1;
        }
    } else {
        if(checkComplex (a, b, c, roots)) {
            return 1;
        }
    }
    return 0;
}

int checkXAny (double a, double b, double c, Roots* roots) {
    if (equalToZero (a) &&
        equalToZero (b) &&
        equalToZero (c) &&
        (*roots).roots_cnt == 1 &&
        isnan ((*roots).mem[0])) {
        return 1;
    }
    return 0;
}

int checkNoneRoots (double a, double b, double c, Roots* roots) {
    if (equalToZero (a) &&
        equalToZero (b) &&
        (*roots).roots_cnt == 0) {
        return 1;
    }
    return 0;
}

int checkComplex (double a, double b, double c, Roots* roots) {
    int iters = (*roots).roots_cnt / 2;
    for (int it = 0; it < iters; ++it) {
        //optimization for a*(m + ki)^2 + b*(m + ki) + c
        if (!equalToZero ((*roots).mem[it * 2 + 1] * (b + 2 * (*roots).mem[it * 2] * a)) ||
            !equalToZero (
            ((*roots).mem[it * 2] - (*roots).mem[it * 2 + 1]) * ((*roots).mem[it * 2] + (*roots).mem[it * 2 + 1]) * a +
            (*roots).mem[it * 2] * b +
            c
            )) {
            return 0;
        }
    }
    return 1;
}

int checkLinearQuadratic (double a, double b, double c, Roots* roots) {
    for (int it = 0; it < (*roots).roots_cnt; ++it) {
        if (!equalToZero (a * (*roots).mem[it] * (*roots).mem[it] +
            b * (*roots).mem[it] +
            c)) {
            return 0;
        }
    }
    return 1;
}
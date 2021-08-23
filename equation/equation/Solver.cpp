#include "Solver.h"

enum RootsType {
    InfRoots = -1,
    NoRoots = 0,
    OneRoot = 1,
    TwoRoots = 2,
    ComplexRoots = 3
};


struct ComplexRoot {
    double x = NAN;
    double xi = NAN;
};

void makeComplexRoot (ComplexRoot* mem, double x_inp, double xi_inp) {
    struct ComplexRoot root = ComplexRoot();
    root.x = x_inp;
    root.xi = xi_inp;
    (*mem) = root;
    return;
}


struct Roots {
    RootsType type;
    ComplexRoot* mem;
};

void init (Roots* roots) {
    roots->mem = ( ComplexRoot* ) calloc (2, sizeof (ComplexRoot));
    roots->type = NoRoots;
    for (int i = 0; i < 2; ++i) {
        roots->mem[i].x = NAN;
        roots->mem[i].xi = NAN;
    }
}

void freeRoots (Roots* roots) {
    free(roots->mem);
    free(roots);
    return;
}


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

void solveLinear (Params* params, Roots* roots) {
    if (equalToZero (params->b)) {
        if (equalToZero (params->c)) {
            roots->type = InfRoots;
            return;
        }
        roots->type = NoRoots;
        return;
    }

    makeComplexRoot (&roots->mem[0], -params->c / params->b, 0);
    roots->type = OneRoot;
    return;
}

void solveQuadratic (Params* params, Roots* roots) {
    double D = params->b * params->b - 4 * params->a * params->c;
    double a = params->a * 2; // optimization for -b +- D / 2a

    if (equalToZero (D)) {
        makeComplexRoot(&roots->mem[1], -params->b / params->a, 0);
        roots->type = OneRoot;
        return;
    }

    roots->type = TwoRoots;

    if (D < 0) {
        roots->type = ComplexRoots;
        D = -D;
    }

    D = sqrt (D); // optimization for -b +- sqrt(D) / 2a
    if (roots->type == TwoRoots) {
        makeComplexRoot (&roots->mem[0], (-params->b - D) / a, 0);
        makeComplexRoot (&roots->mem[1], (-params->b + D) / a, 0);
    } else {
        makeComplexRoot (&roots->mem[0], -params->b / a, D / a);
        makeComplexRoot (&roots->mem[1], -params->b / a, -D / a);
    }
    return;
}

void solve (Params* param, Roots* roots) {

    if (equalToZero (param->a)) {
        solveLinear (param, roots);
    } else {
        solveQuadratic (param, roots);
    }

    return;
}

void printRoots (Roots* roots, Params* params, FILE* thread) {
    fprintf (thread, "Solve for equation (%.14lf)*x^2 + (%.14lf)*x + (%.14lf) = 0 is:\n", (*params).a, (*params).b, (*params).c);
    if (roots->type == NoRoots) {
        fprintf (thread, "No roots\n\n");
        return;
    }
    
    if (roots->type == InfRoots) {
        fprintf (thread, "x belongs to R\n\n");
        return;
    }

    if (roots->type == ComplexRoots) {
        fprintf (thread, "Complex Roots: x1 = %.14lf - %.14lf"
                         "i and x2 = %.14lf + %.14lf"
                         "i\n\n",
                         roots->mem[0].x, roots->mem[0].xi, roots->mem[1].x, roots->mem[1].xi);
        return;
    }
    int roots_cnt = roots->type;
    for (int root_it = 0; root_it < roots_cnt; ++root_it) {
        fprintf (thread, "%.14lf ", roots->mem[root_it].x);
    }
    fprintf (thread, "\n\n");
    return;
}


Roots* equation (Params* params) {
    Roots* res = ( Roots* ) malloc (sizeof (Roots));
    init(res);

    solve(params, res);

    return res;
}


int testAll () {
    
    int counter = 0;
    FILE* fp_in = fopen ("test.txt", "r");
    FILE* fp_out = fopen("log.txt", "w+");
    double a = 0, b = 0, c = 0;
   
    Roots* roots;
    for(int rep = 0; rep < 4; ++rep){
        fgetc (fp_in);//passes \r in \n\r
        char buff[100] = {};
        fgets (buff, 100, fp_in);
        fscanf (fp_in, "%d", &counter);
        printf ("%d\n", counter);
        printf ("%s", buff);//writes 

        for (int it = 0; it < counter; ++it) {
            Params param;
            int last_dot = 0;
            fscanf (fp_in, "%lf%lf%lf", &(param.a), &(param.b), &(param.c));
            
            roots = equation(&param);
            int prev_pos = 0, n_pos = 0;
            //begin
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
            if (!checkEquation (&param, roots)) {
                fprintf (fp_out, "ERROR: ");
                fprintf (stdout, "ERROR: \n");
                printRoots (roots, &param, fp_out);
            }
            freeRoots(roots);
        }

        printf ("\rCompleted                                                                                   \n\n");
    }
    fclose (fp_in);
    fclose (fp_out);

    return 1;
}

int checkEquation (Params* param, Roots* roots) {
    if (checkXAny (param, roots)) {
        return 1;
    }

    if (checkNoneRoots (param, roots)) {
        return 1;
    }

    if(checkComplex (param, roots)) {
        return 1;
    }

    return 0;
}

int checkXAny (Params* param, Roots* roots) {
    if (equalToZero (param->a) &&
        equalToZero (param->b) &&
        equalToZero (param->c) &&
        roots->type == InfRoots) {
        return 1;
    }
    return 0;
}

int checkNoneRoots (Params* param, Roots* roots) {
    if (equalToZero (param->a) &&
        equalToZero (param->b) &&
        roots->type == NoRoots) {
        return 1;
    }
    return 0;
}

int checkComplex (Params* param, Roots* roots) {
    int iters = roots->type;
    if (roots->type == ComplexRoots) {
        iters = 2;
    }
    for (int it = 0; it < iters; ++it) {
        //optimization for a*(m + ki)^2 + b*(m + ki) + c
        if (!equalToZero (roots->mem[it].xi * (param->b + 2 * roots->mem[it].x * param->a)) ||
            !equalToZero (
            (roots->mem[it].x - roots->mem[it].xi) * (roots->mem[it].x + roots->mem[it].xi) * param->a 
            + roots->mem[it].x * param->b
            + param->c
            )) {
            return 0;
        }
    }
    return 1;
}

int checkLinearQuadratic (Params* param, Roots* roots) {
    for (int it = 0; it < roots->type; ++it) {
        if (!equalToZero (param->a * roots->mem[it].x * roots->mem[it].x +
            param->b * roots->mem[it].xi +
            param->c)) {
            return 0;
        }
    }
    return 1;
}
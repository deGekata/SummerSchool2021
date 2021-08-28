/*!
 * \file Solver.cpp
 * \brief Realisation for Solver.h
 * \details Solves equation with power less than 2
 */
#include "pch.h"
#include "Solver.h"

/*!
* \details InfRoots - X belongs to R \n 
*   NoRoots - No roots \n 
*   OneRoot - one real root \n 
*   ComplexRoots - two complex roots \n 
*   TwoRoots - two real roots \n 

*/
enum RootsType {
    InfRoots     = -1,
    NoRoots      =  0,
    OneRoot      =  1,
    TwoRoots     =  2,
    ComplexRoots =  3
};


struct ComplexRoot {
    double real = NAN;
    double im   = NAN;
};

void makeComplexRoot (ComplexRoot* mem, double real_inp, double im_inp) {
    assert (mem);
    mem->real = real_inp;
    mem->im = im_inp;
    return;
}


struct Roots {
    RootsType type = NoRoots; /// \brief Contain type of roots. See RootsType
    ComplexRoot* mem = NULL;
};

void freeRoots (Roots* roots) {
    assert (roots);

    free (roots->mem);
    free (roots);
    return;
}

void init (Roots* roots) {
    assert (roots);
    
    roots->mem = ( ComplexRoot* ) calloc (2, sizeof (ComplexRoot));
    roots->type = NoRoots;

    for (int i = 0; i < 2; ++i) {
        roots->mem[i].real = NAN;
        roots->mem[i].im = NAN;
    }
}

struct Params {
    double a = NAN, b = NAN, c = NAN;
};

Params* readVars () {
    Params* vars = ( Params* ) calloc (1, sizeof (Params));
    
    printf ("Please, enter the coefficients.\n"
            "Example: For equation 2x^2 + 4x + 5 = 0\n"
            "Write: 2 4 5.\n");
    
    while (scanf ("%lf%lf%lf", &vars->a, &vars->b, &vars->c) != 3) {
        while (getchar () != '\n') {};//pass input buffer
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

void solveLinear (const Params* params, Roots* roots) {
    assert (params);
    assert (roots);

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

void solveQuadratic (const Params* params, Roots* roots) {
    assert (params);
    assert (roots);

    double D = params->b * params->b - 4 * params->a * params->c;
    double a = params->a * 2; // optimization for -b +- D / 2a
    init(roots);

    if (equalToZero (D)) {
        makeComplexRoot (&roots->mem[1], -params->b / params->a, 0);
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
        makeComplexRoot (&roots->mem[0], -params->b / a, +D / a);
        makeComplexRoot (&roots->mem[1], -params->b / a, -D / a);
    }
    return;
}

void solve (const Params* param, Roots* roots) {
    assert (param);
    assert (roots);

    if (equalToZero (param->a)) {
        solveLinear (param, roots);
    } else {
        solveQuadratic (param, roots);
    }

    return;
}

void printRoots (const Roots* roots, const Params* params, FILE* thread) {
    assert (params);
    assert (roots);
    assert (thread);

    fprintf (thread, "Solve for equation (%.14lf)*x^2 + (%.14lf)*x + (%.14lf) = 0 is:\n", params->a, params->b, params->c);
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
            roots->mem[0].real, roots->mem[0].im, roots->mem[1].real, roots->mem[1].im);
        return;
    }
    int roots_cnt = roots->type;
    for (int root_it = 0; root_it < roots_cnt; ++root_it) {
        fprintf (thread, "x%d=%.14lf ", root_it, roots->mem[root_it].real);
    }
    fprintf (thread, "\n\n");
    return;
}


Roots* equation (const Params* params) {
    assert (params);

    Roots* res = ( Roots* ) calloc (1, sizeof (Roots));
    init (res);

    solve (params, res);

    return res;
}

void beatyPrint (int prev_pos, int test_num, int test_count) {
    int n_pos = 80 * ( double ) (test_num + 1) / test_count + 1;
    
    if (n_pos != prev_pos) 
        {
        printf ("\r[");
        for (int stars =      80.0 * (test_num + 1) / test_count + 1; stars >= 0; --stars) printf ("*");
        for (int stars = 80 - 80   * (test_num + 1) / test_count;     stars >  0; --stars) printf ("-");
        printf ("]");

        printf (" %d / %d", test_num + 1, test_count);
    }
}

int testAll () {
    int counter = 0;
    FILE* fp_in = fopen ("test.txt", "r");
    if (fp_in == NULL) {
        return 0;
    }

    FILE* fp_out = fopen ("log.txt", "w+");
    double a = 0, b = 0, c = 0;

    Roots* roots = NULL;
    //count of test groups
    for (int repeat = 0; repeat < 4; ++repeat) {
        fgetc (fp_in); // passes \r in \n\r

        char buff[100] = {};
        fgets (buff, sizeof (buff) / sizeof (buff[0]), fp_in);
        
        fscanf (fp_in, "%d", &counter);
        printf ("%d\n", counter);
        printf ("%s", buff); // writes 

        int prev_pos = 0;
        for (int it = 0; it < counter; ++it) {
            Params param = {};
            int last_dot = 0;
            if (fscanf (fp_in, "%lf%lf%lf", &(param.a), &(param.b), &(param.c)) != 3) {
                return 0;
            }

            roots = equation (&param);

            beatyPrint(prev_pos, it, counter);

            if (!checkEquation (&param, roots)) {
                fprintf (fp_out, "ERROR: ");
                fprintf (stdout, "ERROR: \n");
                printRoots (roots, &param, fp_out);
            }
            freeRoots (roots);
        }

        printf ("\rCompleted %*c \n\n", 200, ' ');
    }
    fclose (fp_in);
    fclose (fp_out);

    return 1;
}

int checkEquation (const Params* param, const Roots* roots) {
    assert (param);
    assert (roots);

    if (checkXAny (param, roots)) {
        return 1;
    }

    if (checkNoneRoots (param, roots)) {
        return 1;
    }

    if (checkComplex (param, roots)) {
        return 1;
    }

    return 0;
}

int checkXAny (const Params* param, const Roots* roots) {
    assert (param);
    assert (roots);

    if (equalToZero (param->a) &&
        equalToZero (param->b) &&
        equalToZero (param->c) &&
        roots->type == InfRoots) {
        return 1;
    }
    return 0;
}

int checkNoneRoots (const Params* param, const  Roots* roots) {
    assert (param);
    assert (roots);

    if (equalToZero (param->a) &&
        equalToZero (param->b) &&
        roots->type == NoRoots) {
        return 1;
    }
    return 0;
}

int checkComplex (const Params* param, const Roots* roots) {
    assert (param);
    assert (roots);

    int iters = roots->type;
    if (roots->type == ComplexRoots) {
        iters = 2;
    }
    for (int it = 0; it < iters; ++it) {
        //optimization for a*(m + ki)^2 + b*(m + ki) + c
        if (!equalToZero ( roots->mem[it].im * (param->b + 2 * roots->mem[it].real * param->a)) ||
            !equalToZero ((roots->mem[it].real - roots->mem[it].im) * (roots->mem[it].real + roots->mem[it].im) * param->a
            + roots->mem[it].real * param->b
            + param->c
            )) {
            return 0;
        }
    }
    return 1;
}

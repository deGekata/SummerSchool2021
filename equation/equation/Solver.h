#pragma once
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const double ___EPSILON = 1e-7;

struct ComplexRoot;
struct Roots;
struct Params;


Params* readVars();

int equalToZero (double inp);

int getVar (double* a);

int getVars (double* a, double* b, double* c);

void solveLinear (Params* params, Roots* roots);

void solveQuadratic (Params* params, Roots* roots);

void solve (Params* params, Roots* roots);

void printRoots (Roots* roots, Params* param, FILE* thread);

Roots* equation (Params* params);

int testAll ();

int checkXAny (Params* param, Roots* roots);

int checkNoneRoots (Params* param, Roots* roots);

int checkComplex (Params* param, Roots* roots);

int checkLinearQuadratic (Params* param, Roots* roots);


int checkEquation (Params* param, Roots* roots);


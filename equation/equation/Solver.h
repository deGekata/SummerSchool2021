#pragma once
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const double ___EPSILON = 1e-7;

struct Roots;
struct Params;

Params* readVars();

int equalToZero (double inp);

int getVar (double* a);

int getVars (double* a, double* b, double* c);

void solveLinear (double b, double c, double* mem, int* roots_cnt);

void solve (double a, double b, double c, double* mem, int* is_real, int* roots_cnt);

void printRoots (double* mem, int roots_cnt, int is_real, Params* param, FILE* thread);

Roots* equation (Params* params);

int testAll ();

int checkXAny (double a, double b, double c, Roots* roots);

int checkNoneRoots (double a, double b, double c, Roots* roots);

int checkComplex (double a, double b, double c, Roots* roots);

int checkLinearQuadratic (double a, double b, double c, Roots* roots);


int checkEquation (double a, double b, double c, Roots* roots);

void writeLog();
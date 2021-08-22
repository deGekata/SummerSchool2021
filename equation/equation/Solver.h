#pragma once
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const double EPSILON = 1e-9;

struct ans;

int equalToZero(double inp);

int getVar(double* a);

int getVars(double* a, double* b, double* c);

void solveLinear(double b, double c, double* mem, int* roots_cnt);

void solve(double a, double b, double c, double* mem, int* is_real, int* roots_cnt);

void printRoots(double* mem, int roots_cnt, int is_real);

void equation();
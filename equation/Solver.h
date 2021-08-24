/*!
 * \file Solver.h
 * \author Gekata
 * Solves quadratic equation
 */



#pragma once
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "pch.h"
#include < string.h >
 /// Accuracy of methods
const double ___EPSILON = 1e-7;


/*!
    \brief Struct for complex root
*/
struct ComplexRoot;

/// \brief Contains roots
struct Roots;
struct Params;


Params* readVars ();

/*!
    \brief  Checks if inp equals to zero with ___EPSILON accuracy
*/
int equalToZero (double inp);


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

/*!
    \brief test
    \warning lol
*/
int checkEquation (Params* param, Roots* roots);


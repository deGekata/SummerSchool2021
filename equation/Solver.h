/*!
 * \file Solver.h
 * \author Gekata
 * \brief Solves quadratic equation
 */

#pragma once
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "pch.h"

 /// Accuracy of methods
const double ___EPSILON = 1e-7;

/*!
*   \brief Complex root with real and imaginari part
*   \details default values are NAN
*/
struct ComplexRoot;

/*!
*   \brief Contains two ComplexRoots and their type
*   \details default values are NAN
*/
struct Roots;

/*!
*   \brief Contains parameters for quadric equation
*   \details default values are NAN
*/
struct Params;

/*!
*   \brief Read coefficients for quadratic equation
*   \details Returns Params filled with a, b, c
*/
Params* readVars ();

/*!
    \brief  Checks if inp equals to zero with ___EPSILON accuracy
*/
int equalToZero (double inp);

/*!
*   \brief Solves linear equation
*   \details writes roots to "roots" argument
*/
void solveLinear (const Params* params, Roots* roots);


/*!
*   \brief Solves quadratic equation
*   \details writes roots to "roots" argument
*/
void solveQuadratic (const Params* params, Roots* roots);


/*!
*   \brief Solves equation
*   \details Solves quadratic equation with power less than 2 \n 
*    writes roots to "roots" argument
*   @param[in] params Params of quadratic equation for solving
*   @param[out] roots Returns filled roots
*/
void solve (const Params* params, Roots* roots);

/*!
*   \brief Prints equation and roots
*   \details Prints equation and roots to a certain thread
*   @param[in] roots Are used for printing
*   @param[in] param Are used for printing
*   @param[in, out] thread Print roots to certain thread
*
*/
void printRoots (const Roots* roots, const Params* param, FILE* thread);

/*!
*   \brief Solves equation
*   \details Solves equation and returns pointer to Roots
*   @param[in] params Equation coefficients
*
*/
Roots* equation (const Params* params);

/*!
*   \brief Prints progress bar
*   \details Prints progress bar with loader and number of passed tests
*   @param[in] prev_pos last position of * in progress bar
*   @param[in] test_num Number of last passed test
*   @param[in] test_count Total count of tests
*/
void beatyPrint (int prev_pos, int test_num, int test_count);

/*!
*   \brief Test equations from test.txt file
*/
int testAll ();

/*!
*   \brief Check if X belongs to R
*   @param[in] param Equation parameters
*   @param[in] roots Possible roots of equation
*/
int checkXAny (const Params* param, const  Roots* roots);

/*!
*   \brief Check if roots dont exist
*   @param[in] param Equation parameters
*   @param[in] roots Possible roots of equation
*/
int checkNoneRoots (const Params* param, const Roots* roots);

/*!
*   \brief Check if Complex roots fit equation
*   @param[in] param Equation parameters
*   @param[in] roots Possible roots of equation
*/
int checkComplex (const Params* param, const Roots* roots);

/*!
*   \brief Check all cases above
*   @param[in] param Equation parameters
*   @param[in] roots Possible roots of equation
*/
int checkEquation (const Params* param, const Roots* roots);


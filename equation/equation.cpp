#include "pch.h"
#include "Solver.h"

/*!
* \file equation.cpp
* \brief main file
*/


/*!
* \brief its used for choosing run method
* \details use this for solve method
*/
//#define SOLVE

/*!
* \brief its used for choosing run method
* \details use this for test method
*/
#define TEST



int main () {

#ifdef SOLVE
    Params* params = readVars();
    Roots* roots = equation (params);
    printRoots(roots, params, stdout);
#endif // SOLVE

#ifdef TEST
    testAll ();
#endif // TestAll

    getchar ();
    return 0;
}

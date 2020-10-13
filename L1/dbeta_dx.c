/******************************************************************************
 *                      Code generated with sympy 1.6.2                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                  This file is part of 'symbolic_methods'                   *
 ******************************************************************************/
#include "dbeta_dx.h"
#include <math.h>

double dbeta_dx(double t, double x, double y) {

   double dbeta_dx_result;
   dbeta_dx_result = ((1.0/3.0)*pow(t, 2)*pow(t, y)*pow(x, 2)*y - 1.0/3.0*pow(t, 2)*pow(t, y)*x*(t - 2*x*y))*exp(-1.0/6.0*pow(t, 2)*pow(t, y)*pow(x, 2)*(t - 2*x*y));
   return dbeta_dx_result;

}

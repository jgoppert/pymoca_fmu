#include <iostream>
#include <stdio.h>
#include <idas/idas.h>
#include <idas/idas_dense.h>
#include <sundials/sundials_math.h>

#define casadi_int int
#define casadi_real double
#define CASADI_PRINTF printf

extern "C" {
    casadi_int f_x_rhs(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, void* mem);
}

casadi_int main(casadi_int argc, char* argv[]) {
    casadi_int *iw = 0;
    casadi_real w[9];
    const casadi_real* arg[8] = {w+0, w+1, w+3, w+3, w+3, w+5, w+6, w+6};
    casadi_real* res[1] = {w+6};
    casadi_int j;
    casadi_real* a = w;
    for (j=0; j<6; ++j) scanf("%lf", a++);
    casadi_int flag = f_x_rhs(arg, res, iw, w+8, 0);
    if (flag) return flag;
    const casadi_real* r = w+6;
    for (j=0; j<2; ++j) CASADI_PRINTF("%g ", *r++);
    CASADI_PRINTF("\n");


    void * mem;
    // https://github.com/certik/sundials/blob/master/examples/idas/serial/idasSlCrank_FSA_dns.c
    mem = IDACreate();
    flag = IDAInit(mem, ressc, TBEGIN, yy, yp);

    return 0;
}




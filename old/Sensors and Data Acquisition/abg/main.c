#include "abg.h"
#include <stdio.h>

void dumpState(State);

int main(int argc, char ** argv)
{
  double measurements[] = {30160,30365,30890,31050,31785,32215,33130,34510,36010,37265};//Test measurements
  const int imax = 10;
  State est;
  State pre;

  pre.n  = 1;
  pre.m = 0;
  pre.x0 = 30250;
  pre.x1 = 50;
  pre.x2 = 0;
  pre.alpha = 0.5;
  pre.beta = 0.4;
  pre.gamma = 0.1;

//  pre = predictState(pre,5);

  for (int i = 0; i < imax; i++)
  {
    est = updateState(pre, measurements[i], 5);
    printf("\nestimate:\n");
    dumpState(est);
    pre = predictState(est, 5);    
    printf("\nprediction:\n");
    dumpState(pre);
  }
}


void dumpState(State s)
{
  printf("dump state:%d,%d\nx: %.2f\nx': %.2f\nx'': %.2f\n",s.n,s.m,s.x0,s.x1,s.x2);
}

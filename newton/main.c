#include <stdio.h>
#include <math.h>
#include "header.h"

int main(void){
  double error, x, x_n;
  int i, max;
  x=1.0;
  error=1e-6;
  max=100;

  double (*f1)(double);
  double (*f1_d)(double);
  f1 = func1;
  f1_d = func1_d;

  double (*f2)(double);
  double (*f2_d)(double);
  f2 = func2;
  f2_d = func2_d;

  for(i=0; i<max; i++){
    x_n = x- (*f1)(x)/(*f1_d)(x);
    if(fabs(x_n-x)<error){
      break;
    }
    x = x_n;
  }
  if(i<max){
    printf("OK %f\n", x);
  }else{
    printf("NG");
  }

  for(i=0; i<max; i++){
    x_n = x- (*f2)(x)/(*f2_d)(x);
    if(fabs(x_n-x)<error){
      break;
    }
    x = x_n;
  }
  if(i<max){
    printf("OK %f\n", x);
  }else{
    printf("NG");
  }
  return 0;
}

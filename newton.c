#include <math.h>
#include <stdio.h>

double func1(double x){
  double y;
  y = x - 1.2*exp(-x);
  return y;
}

double func1_d(double x){
  double y;
  y = 1 + 1.2*exp(-x);
  return y;
}

double func2(double x){
  double y;
  y = x * sin(x) + log(x);
  return y;
}

double func2_d(double x){
  double y;
  y = sin(x) + x * cos(x) + 1/x;
  return y;
}

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

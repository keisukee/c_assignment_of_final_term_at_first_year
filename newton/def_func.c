#include <math.h>

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

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 4

int main(void) {
  double** a;
  double* x;
  double* b;
  double r;


  a = (double**)malloc(sizeof(double*) * N);
  for(int i=0; i<N; i++){
    a[i] = malloc(sizeof(double) * N);
  }
  x = (double*)malloc(sizeof(double) * N);
  b = (double*)malloc(sizeof(double) * N);

  a[0][0] = 2 ;  a[0][1] = 4 ;  a[0][2] = 1 ; a[0][3] = -3 ; b[0] = 0;
  a[1][0] = -1 ;  a[1][1] = -2 ;  a[1][2] = 2 ; a[1][3] = 4 ; b[1] = 10;
  a[2][0] = 4 ;  a[2][1] = 2 ;  a[2][2] = -3 ; a[2][3] = 5 ; b[2] = 2;
  a[3][0] = 5 ;  a[3][1] = -4 ;  a[3][2] = -3 ; a[3][3] = 1 ; b[3] = 6;

  for(int k = 0; k < N; k++){
    int p;
    double pmax;
    p = k;
    pmax = fabs(a[k][k]);
    for(int i = k+1; i < N; i++){
      if(fabs( a[i][k] ) > pmax){
        p = i;
        pmax = fabs(a[i][k]);
      }
    }

    if(p != k){
      double tmp;
      for(int i = k; i < N; i++){
        tmp = a[k][i];
        a[k][i] = a[p][i];
        a[p][i] = tmp;
      }
      tmp = b[k];
      b[k] = b[p];
      b[p] = tmp;
    }
  }

  for(int k=0; k<N; k++ ){
   for(int j=k+1; j<N; j++){
     r = a[j][k]/a[k][k] ;
     for(int i=k+1; i<N; i++){
       a[j][i] = a[j][i] - a[k][i] * r;
     }
     b[j] = b[j] - r * b[k];
   }
 }

 for(int i=0; i<N; i++){
   for(int j=0; j<N; j++){
     printf("%f\t", a[j][i]);
   }
     printf("%f\n", b[i]);
 }

 x[2] = b[2] / a[2][2];
 x[1] = (b[1]  - a[1][2]*x[2])/ a[1][1];
 x[0] = (b[0] - a[0][1]*x[1]- a[0][2]*x[2])/ a[0][0] ;

 printf("%f %f %f \n", x[0], x[1], x[2]);
 return 0;
}

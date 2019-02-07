#include <stdio.h>

int main(){
  int a[7];
  char *cp;
  a[0] = 176849379;
  a[1] = 179476199;
  a[2] = 176980707;
  a[3] = 177776614;
  a[4] = 178749923;
  a[5] = 177701347;
  a[6] = 178225635;

  cp = (char*)a;
  for(int i=0; i< sizeof(a); i++, cp++){
    printf("%c", *cp);
  }
  return 0;
}

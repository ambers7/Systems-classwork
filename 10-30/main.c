#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int printvalid(int x, int y, int z) {//1 if valid, 0 if not
  if (((x+y)>z&&abs(x-y)<z) ||
  ((x+z)>y&&abs(x-z)<y) ||
  ((y+z)>x&&abs(y-z)<x)) {
    printf("%d %d %d: Valid\n",x,y,z); //COMMENT OUT LATER
    return 1;
  } else {
    printf("%d %d %d: Not valid\n",x,y,z); //COMMENT OUT LATER
    return 0;
  }
}
int main(int argc, char* argv[]) {
    for (int i = 0;i<argc;i++) {
      printf("i: %d %s\n",i,argv[i]);
    }
    if (strcmp(argv[1],"user")==0) {
      int c = 0;
      char st[100];
      while(fgets(st,100,stdin)) {
        int x; int y; int z;
        sscanf(st,"%d %d %d",&x,&y,&z);
        if (printvalid(x,y,z)==1) c++;
      }
      printf("Number of valid triangles: %d\n", c);
    }
  else if (strcmp(argv[1],"horizontal")==0) {
    int count = 0;
    char s[100];
    FILE * f = fopen("./input.txt","r");
    while(fgets(s,100,f)) {
      int x; int y; int z;
      sscanf(s,"%d %d %d",&x,&y,&z);
      if (printvalid(x,y,z)==1) count++;
    }
    printf("Number of valid triangles: %d\n", count);
  } else {
      printf("Directions: Pass in number and string(\"user or horizontal\") after ./a.out\n");
  }
}

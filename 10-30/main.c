#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int printvalid(int x, int y, int z) {//1 if valid, 0 if not
  if (((x+y)>z&&abs(x-y)<z) ||
  ((x+z)>y&&abs(x-z)<y) ||
  ((y+z)>x&&abs(y-z)<x)) {
    // printf("%d %d %d: Valid\n",x,y,z); //COMMENT OUT LATER
    return 1;
  } else {
    // printf("%d %d %d: Not valid\n",x,y,z); //COMMENT OUT LATER
    return 0;
  }
}
int main(int argc, char* argv[]) {
  if (argv[1]!=NULL) {
    if (strcmp(argv[1],"user")==0) {
      // printf("%d %d %d\n",100,25,30);
      int c = 0;
      char st[12];
      int x; int y; int z;
      fgets(st,12,stdin);
      sscanf(st,"%d %d %d",&x,&y,&z);
      if (printvalid(x,y,z)==1) printf("Valid\n");
      else printf("Not Valid\n");
    } else if (strcmp(argv[1],"horizontal")==0) {
      int count = 0;
      char s[100];
      FILE * f = fopen("./input.txt","r");
      int x; int y; int z;
      while(fgets(s,100,f)) {
        int x; int y; int z;
        sscanf(s,"%d %d %d",&x,&y,&z);
        if (printvalid(x,y,z)==1) count++;
      }
      printf("Number of valid triangles: %d\n", count);
    } else { //put in wrong input
      printf("Directions: Pass in \"user\" or \"horizontal\" after ./a.out\nuser will read from stdin, horizontal will read from input.txt\n");
    }
  } else { //blank after a.out
    printf("Directions: Pass in \"user\" or \"horizontal\" after ./a.out\nuser will read from stdin, horizontal will read from input.txt\n");
  }
}

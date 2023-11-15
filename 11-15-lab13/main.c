#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <sys/wait.h>
int err(){
    printf("errno %d\n",errno);
    printf("%s\n",strerror(errno));
    exit(1);
}
int main() {
    srand(time(NULL));
    pid_t c1; pid_t c2;
    c1 = fork();
    if (c1==-1) err();
    if (c1<0) { 
        printf("Fork failed\n");
    } else if (c1==0) { //child  1
        int pid = getpid();
        int r = rand()%5 + 1; //number b/t 1 and 5
        printf("Child PID: %d, %d seconds\n",getpid(),r);
        sleep(r);
        printf("%d finished after %d seconds\n",getpid(),r);
        exit(1);
    } else {
        c2=fork();
        if (c2==-1) err();
        if (c2==0) {
            int pid = getpid();
            int r = rand()%5 + 1; //number b/t 1 and 5
            printf("Child PID: %d, %d seconds\n",getpid(),r);
            sleep(r);
            printf("%d finished after %d seconds\n",getpid(),r);
            exit(1);
        } else { //parent 
            waitpid(c1,MACRO(WIFEXITED),0);
        }
    }
}
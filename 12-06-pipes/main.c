#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#define READ 0
#define WRITE 1
int err(){
    printf("errno %d\n",errno);
    printf("%s\n",strerror(errno));
    exit(1);
}
int main() {
    int fds[2];
    pipe(fds);
    char line[100];
    int f = fork();
    if (f==0) { //child
        printf("pid %d: Enter text: \n",getpid());
        close(fds[READ]);
        if (!fgets(line,sizeof(line),stdin)) err();
        write(fds[WRITE],line,sizeof(line));
    } else { //parent 
        close(fds[WRITE]);
        read(fds[READ],line,sizeof(line));
        printf("pid: %d: Received message: %s",getpid(),line);
    }

}
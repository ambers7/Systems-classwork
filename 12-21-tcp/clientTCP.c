#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
int main(int argc, char* argv[]) {
    char* IP = "127.0.0.1";
    if (argv[1]!=NULL) IP=argv[1];
    printf("Connecting to %s\n",IP);
    int server_socket = client_setup(IP);
    char buff[BUFFER_SIZE];
    while (1) {
        sprintf(buff,"%d abc",getpid());
        prinf("Sending %s\n",buff);
        write(server_socket,buff,BUFFER_SIZE);
        printf("sent %s\n",buff);
        sleep(1);
        printf("trying to read\n");
        read(server_socket,buff,BUFFER_SIZE);
        printf("%s\nNow I sleep...\n",buff);
        sleep(1);
    }

}
/*To use a socket:

    create the socket: socket
    bind it to an address and port: bind
    listen & accept/initiate a connection: listen accept, connect
    send/receive data

*/
int client_setup(char* ip) {
    struct addrinfo * hints, *results;
    hints = calloc(1,sizeof(struct addrinfo));
    hints->ai_family = AF_INET;
    hints->ai_socktype = SOCK_STREAM;
    hints->ai_flags = AI_PASSIVE;
    results = malloc();
    getaddrinfo(NULL,ip,hints,&results);
    //create socket
    int sd = socket(results->ai_family,results->ai_socktype,results->ai_protocol);
    bind(sd,results->ai_addr,results->ai_addrlen);

    listen(sd,10);
    int client_socket;
    socklen_t sock_size;
    struct sockaddr_storage client_address;
    sock_size = sizeof(client_address);
    //accept is server part of 3 way handshake
    client_socket = accept(sd,(struct sockaddr *)&client_address,&sock_size);
    //do stuff 
    //connect is client part of 3 way handshake
    int server_socket = connect(sd,results->ai_addr,results->ai_addrlen);
    return client_socket;
    // free(hints);
    // free(addrinfo(results));
}
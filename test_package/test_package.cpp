#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <libmill.h>

int main(int argc, char *argv[]) {

    int port = 5555;
    if(argc > 1)
        port = atoi(argv[1]);

    ipaddr addr = iplocal(NULL, port, 0);
    tcpsock ls = tcplisten(addr, 10);
    if(!ls) {
        perror("Can't open listening socket");
        return 1;
    }

    while(1) {
        tcpsock as = tcpaccept(ls, -1);
        printf("New connection!\n");
        tcpclose(as);
    }
}

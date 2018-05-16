#ifndef CLIENT_H
#define CLIENT_H
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

class client
{
public:
    client(int port);
    int test();
#define PORT;

};

#endif // CLIENT_H

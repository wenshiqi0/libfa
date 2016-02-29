#ifndef _TCP_H_
#define _TCP_H_

#include "header.h"

extern int initTCP(uint32_t host, u_short port, int *sockfd, struct sockaddr_in *addr);

extern int bindTCP(int sockfd, struct sockaddr_in *addr);

extern int listenTCP(int sockfd, int backlog);

extern int acceptTCP(int sockfd, struct sockaddr *client_addr, socklen_t *size);

extern int connectTCP(int sockfd, struct sockaddr *serv_addr);

extern ssize_t sendTCP(int remote_sockfd, const unsigned char* buffer, int len, unsigned int flags);

extern ssize_t recvTCP(int remote_sockfd, unsigned char* buffer, int max_len, unsigned int flags);

#endif

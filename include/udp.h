#ifndef _UDP_H_
#define _UDP_H_

#include "header.h"

extern int initUDP(uint32_t host, u_short port, int *serv_sock, struct sockaddr_in *addr);

extern int bindUDP(int sockfd, struct sockaddr_in *addr);

extern ssize_t recvfromUDP(int sockfd, unsigned char *buff,int len,unsigned int flags,struct sockaddr *from,socklen_t *fromlen);

extern ssize_t sendtoUDP(int sock,const unsigned char *buff,int max_len,unsigned int flags,struct sockaddr *to,socklen_t tolen);

#endif

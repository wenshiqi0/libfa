#include "../include/udp.h"

int initUDP(uint32_t host, u_short port, int *serv_sock, struct sockaddr_in *addr){
  memset(addr,0,sizeof(struct sockaddr_in));

  (*serv_sock) = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
  if((*serv_sock) == -1){
    perror("Create server socket failed");
    exit(1);
  }

  addr->sin_family = AF_INET;
  addr->sin_addr.s_addr = htonl(host);
  addr->sin_port = htons(port);

  bzero(&(addr->sin_zero), 8);

  return 1;
}

int bindUDP(int sockfd, struct sockaddr_in *addr){
  if(bind(sockfd, (struct sockaddr*)addr, sizeof(struct sockaddr)) == -1){
    perror("Bind socket and addr failed");
    exit(1);
  }

  return 1;
}

ssize_t recvfromUDP(int sockfd, unsigned char *buff,int len,unsigned int flags,struct sockaddr *from,socklen_t *fromlen){
  ssize_t recv_len = recvfrom(sockfd,buff,len,flags,from,fromlen);
  if(recv_len == -1){
    perror("Recv data failed");
    return -1;
  }

  return recv_len;
}

ssize_t sendtoUDP(int sock,const unsigned char *buff,int max_len,unsigned int flags,struct sockaddr *to,socklen_t tolen){
  ssize_t send_len = sendto(sock,buff,max_len,flags,to,tolen);
  if(send_len == -1){
    perror("Send data failed");
    return -1;
  }

  return send_len;
}

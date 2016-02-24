#include "../include/tcp.h"

int initTCP(uint32_t host, u_short port, int *sockfd, struct sockaddr_in *addr){
  (*sockfd) = socket(AF_INET, SOCK_STREAM, 0);
  if((*sockfd) == -1){
    perror("Create host socket failed");
    exit(1);
  }

  addr->sin_family = AF_INET;
  addr->sin_port = htons(port);
  addr->sin_addr.s_addr = host;

  bzero(&(addr->sin_zero), 8);

  return 1;
}

int bindTCP(int sockfd, struct sockaddr_in *addr){
  if(bind(sockfd, (struct sockaddr *)addr, sizeof(struct sockaddr)) == -1){
    perror("Bind socket and addr failed");
    exit(1);
  }

  return 1;
}

int listenTCP(int sockfd, int backlog){
  if(listen(sockfd, backlog) == -1){
    perror("Listen to host failed");
    exit(1);
  }

  return 1;
}

int acceptTCP(int sockfd, struct sockaddr *client_addr, socklen_t *size){
  int client_sockfd = accept(sockfd, client_addr, size);
  if(client_sockfd == -1){
    perror("Accept TCP socket failed");
    exit(1);
  }

  return client_sockfd;
}

int connectTCP(int sockfd, struct sockaddr *serv_addr){
  if(connect(sockfd, serv_addr, sizeof(struct sockaddr)) == -1){
    perror("Connect to server failed");
    exit(1);
  }

  return 1;
}

ssize_t sendTCP(int remote_sockfd, const unsigned char* buffer, int len, unsigned int flags){
  ssize_t send_len = send(remote_sockfd,buffer,len,flags);
  if(send_len == -1){
    perror("Send data failed");
    return -1;
  }

  return send_len;
}

ssize_t recvTCP(int remote_sockfd, unsigned char* buffer, int max_len, unsigned int flags){
  ssize_t recv_len = recv(remote_sockfd, buffer, max_len, flags);
  if(recv_len == -1){
    perror("Recv data failed");
    return -1;
  }

  return recv_len;
}

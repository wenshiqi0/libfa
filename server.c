#include "./include/udp.h"
#include "./include/tcp.h"
#include "./include/file.h"
#define MAX_BACKLOG 10

int main(){
  unsigned char buffer[UDP_MAX];
  unsigned char buff[11];
  unsigned char test[10] = "123456789";

  int timeout = 1000;
  int serv_sock, client_sock;
  struct sockaddr_in addr, client_addr;
  socklen_t addr_len, client_addr_len;

  readYuvFileToBuffer("./res/1.yuv",buffer);

  initTCP(INADDR_ANY, 8000, &serv_sock, &addr);

  setsockopt(serv_sock, SOL_SOCKET, SO_REUSEADDR, (char *)&timeout, sizeof(int));

  bindTCP(serv_sock, &addr);

  listenTCP(serv_sock, MAX_BACKLOG);

  client_sock = acceptTCP(serv_sock, (struct sockaddr *) &client_addr, &client_addr_len);

  sendTCP(client_sock, test, 10, 0);

  close(serv_sock);

  return 0;
}

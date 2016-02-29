#ifndef _URL_H_
#define _URL_H_

#include "header.h"

struct Url{
  char *protocol;
  char *host;
  char *path;
  char *params;
  int port;
};

extern int urlParse(char *url, struct Url *parsed);

extern int paramsParse(const char *params);

#endif

#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include<regex.h>

#define GET_ARRAY_LEN(array) sizeof(array) / sizeof(array[0])
#define MAX(X,Y) (X>Y?X:Y)
#define MIN(X,Y) (X<Y?X:Y)

#endif

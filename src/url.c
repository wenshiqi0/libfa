#include "../include/url.h"

int urlParse(char *url, struct Url *parsed){
  int index = 0;
  char *u = url-1;
  char *parsed_info[5] = {NULL, NULL, NULL, NULL, NULL};

  for(int i = 0; i < 5; i++){
    for(;;){
      u++;

      if( (i == 1 || i == 2) && *u == '/'){
        goto assign;
      }

      if(*u == ':' || *u == '?' || *u == '\0'){

assign:

        parsed_info[i] = (char *)malloc(index);
        strncpy(parsed_info[i], u-index, index);
        if(i == 0) u += 2;
        if(i == 1 && *u == '/') i = 2;
        index = 0;
        break;
      }else{
        index++;
      }
    }
  }

  parsed->protocol = parsed_info[0];
  parsed->host = parsed_info[1];
  parsed->path = parsed_info[3];
  parsed->params = parsed_info[4];

  if(parsed_info[2])
    parsed->port = atoi(parsed_info[2]);
  else
    parsed->port = 80;

  return 1;
}

int paramsParse(const char *params){


  return 1;
}

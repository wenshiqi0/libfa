#include "../include/file.h"

int readYuvFileToBuffer(char *path,unsigned char *buffer){
  FILE *file;
  int ret;
  file = fopen(path,"rb");

  ret = fread(buffer, 1, TCP_MAX, file);

  fclose(file);

  return ret;
}

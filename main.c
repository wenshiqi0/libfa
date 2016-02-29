#include "./include/url.h"
#include "./include/map.h"

int main(){
  struct HashMap *map = initHashMap();

  hashMapSet(map,"name","name_info");
  hashMapSet(map,"pass","wsq13567");

  printf("%s\n", hashMapGet(map,"pass"));
  printf("%s\n", hashMapGet(map,"name"));

  return 1;
}

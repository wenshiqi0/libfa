#ifndef _MAP_H_
#define _MAP_H_

#include "header.h"
#define MAX_MAP_SIZE 2000
#define MAX_KEY_SIZE 20
#define MAX_VALUE_SIZE 200

struct HashNode{
  char *key;
  char *value;
};

struct HashMap {
  unsigned int size;
  struct HashNode **array;
};

extern struct HashMap *initHashMap();

extern int freeHashMap(struct HashMap *map);

extern int hashMapSet(struct HashMap *map, const char *key, const char* value);

extern int hashMapSetHashNode(struct HashMap *map,struct HashNode* node);

extern char *hashMapGet(struct HashMap *map, const char *key);

extern struct HashNode *hashMapGetHashNode(struct HashMap *map,const char *key);

#endif

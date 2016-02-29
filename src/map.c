#include "../include/map.h"

//Hash Define
unsigned int defaultHashFunction(const char *str);

#define Hash(X) defaultHashFunction(X)%MAX_MAP_SIZE

struct HashMap *initHashMap(){
  struct HashMap *map = (struct HashMap *)malloc(sizeof(struct HashMap));

  map->size = MAX_MAP_SIZE;
  map->array = (struct HashNode **)malloc(sizeof(struct HashNode *) * MAX_MAP_SIZE);
  if(NULL == map->array){
    perror("map array malloc failed");
    exit(0);
  }
  memset(map->array, 0, MAX_MAP_SIZE*sizeof(struct HashNode *));

  return map;
}

int freeHashNode(struct HashNode *node){
  if(node == NULL){
    return 1;
  }
  free(node);
  node = NULL;
  return 1;
}

int freeHashMap(struct HashMap *map){
  for(int i=0;i<MAX_MAP_SIZE;i++){
    if(NULL != map->array[i]){
      freeHashNode(map->array[i]);
    }
  }
  free(map->array);
  map->array = NULL;
  free(map);
  map = NULL;
  return 1;
}

int hashMapSet(struct HashMap *map,const char *key,const char *value){
  struct HashNode *node = (struct HashNode *)malloc(sizeof(struct HashNode));
  if(NULL == node){
    printf("node malloc failed\n");
    return 0;
  }
  node->key = (char *)key;
  node->value = (char *)value;

  if(NULL == value){
    printf("can not set a NULL value for key:%s\n",key);
    return 0;
  }

  map->array[Hash(key)] = node;

  return 1;
}

int hashMapSetHashNode(struct HashMap *map,struct HashNode* node){
  if(NULL == node || NULL == node->value){
    printf("can not set an empty node\n");
    return 0;
  }
  if(NULL == node->key){
    printf("key can not be NULL\n");
    return 0;
  }

  map->array[Hash(node->key)] = node;

  return 1;
}

char *hashMapGet(struct HashMap *map,const char *key){
  struct HashNode *node = map->array[Hash(key)];
  if(!node){
    return NULL;
  }
  return node->value;
}

struct HashNode *hashMapGetHashNode(struct HashMap *map,const char *key){
  struct HashNode *node = map->array[Hash(key)];
  if(!node || !node->value){
    return NULL;
  }
  return node;
}

//Hash Function
unsigned int defaultHashFunction(const char *str)
{
    register unsigned int h;
    register unsigned char *p;

    for(h=0, p = (unsigned char *)str; *p ; p++)
        h = 31 * h + *p;

    return h;
}

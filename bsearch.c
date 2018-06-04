#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *));
int cmpfunc(const void * a, const void * b);


int main (int argc, char **argv) {
  int *item;
  int key = 32;
  int values[] = { 5, 20, 29, 32, 63 };

  /* using bsearch() to find value 32 in the array */
  item = (int*) bsearch (&key, values, 5, sizeof (int), cmpfunc);

  if( item != NULL ) {
     printf("Found item = %d\n", *item);
  } else {
     printf("Item = %d could not be found\n", key);
  }

  return(0);
}


void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *)){
  int left = 0, right = nitems, mid;
  const void *midElement;

  while(left <= right){
    mid = floor((right - left) / 2) + left;

    midElement = ((const char *) base) + (mid * size);

    if ((* compar)(key, midElement) < 0){
      right = mid - 1;
    }else if((* compar)(key, midElement) > 0){
      left = mid + 1;
    }else
      return (int *) midElement;
  }
  return NULL;
}


int cmpfunc(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

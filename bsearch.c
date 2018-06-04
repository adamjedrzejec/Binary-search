#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *));
int intcmp(const void * a, const void * b);
int charcmp(const void * a, const void * b);
int stringcmp(const void *s1, const void *s2);


int main (int argc, char **argv) {
  int *item;
  int key = 32;
  int values[] = { 5, 20, 29, 32, 63 };

  char *state = "Indiana";
  const char *stateNames[] = {"Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii",
  "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana", "Maine", "Maryland", "Massachusetts", "Michigan", "Minnesota", "Mississippi",
  "Missouri", "Montana", "Nebraska", "Nevada", "New Hampshire", "New Jersey", "New Mexico", "New York", "North Carolina", "North Dakota", "Ohio", "Oklahoma",
  "Oregon", "Pennsylvania", "Rhode Island", "South Carolina", "South Dakota", "Tennessee", "Texas", "Utah", "Vermont", "Virginia", "Washington", "Washington DC",
  "West Virginia", "Wisconsin", "Wyoming"};

  /* using bsearch() to find value 32 in the array */
  item = (int*) bsearch (&key, values, 5, sizeof (int), intcmp);

  char **found = (char **) bsearch(&state, stateNames, 51, sizeof(char *), stringcmp);

  if(item != NULL ) {
     printf("Found item = %d\n", *item);
  } else {
     printf("Item = %d could not be found\n", key);
  }

  if(found != NULL ) {
     printf("Found state = %s\n", *found);
  } else {
     printf("State = %s could not be found\n", state);
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


int intcmp(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int charcmp(const void * a, const void * b) {
  if (*(int*)a > *(int*)b)
   return 1;
  if (*(int*)a < *(int*)b)
    return -1;
  return 0;
}

//int stringcmp(const void *s1, const void *s2) {
//  const char *key = s1;
//  const char * const *arg = s2;
  //printf("myStrCmp: s1(%p): %s, s2(%p): %s\n", s1, key, s2, *arg);
//  return strcmp(key, *arg);
//}

int stringcmp(const void *s1, const void *s2) {
  //printf("myStrCmp: s1(%p): %s, s2(%p): %s\n", s1, (char *)s1, s2, (char *)s2);
  return strcmp(*(char **) s1, *(char **) s2);
}

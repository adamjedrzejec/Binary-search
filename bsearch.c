#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *));
int intcmp(const void * a, const void * b);
int floatcmp(const void * a, const void * b);
int charcmp(const void * a, const void * b);
int stringcmp(const void *s1, const void *s2);


int main (int argc, char **argv) {

  // looking for an integer
  int key = 312;
  int values[] = { 5, 20, 29, 32, 63 };
  int *item = (int*) bsearch (&key, values, 5, sizeof (int), intcmp);

  if(item != NULL ) {
     printf("Found item = %d\n", *item);
  } else {
     printf("Item = %d could not be found\n", key);
  }


  // looking for a float
  float floatToFind = 46.718;
  float floats[] = { 5, 20, 21.5, 29, 32, 46.718, 63 };
  float *floatingNumber = (float*) bsearch (&floatToFind, floats, 7, sizeof (float), floatcmp);

  if(floatingNumber != NULL ) {
     printf("Found float = %f\n", *floatingNumber);
  } else {
     printf("Float = %f could not be found\n", floatToFind);
  }


  // looking for a character
  char characterToFind = 'e';
  char characters[] = { 'a', 'b', 'c', 'd', 'e' };
  char *character = (char*) bsearch (&characterToFind, characters, 5, sizeof (char), charcmp);

  if(character != NULL ) {
     printf("Found character = \'%c\'\n", *character);
  } else {
     printf("character = \'%c\' could not be found\n", characterToFind);
  }


  // looking for a string
  char *state = "Vermont";
  const char *stateNames[] = {"Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii",
  "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana", "Maine", "Maryland", "Massachusetts", "Michigan", "Minnesota", "Mississippi",
  "Missouri", "Montana", "Nebraska", "Nevada", "New Hampshire", "New Jersey", "New Mexico", "New York", "North Carolina", "North Dakota", "Ohio", "Oklahoma",
  "Oregon", "Pennsylvania", "Rhode Island", "South Carolina", "South Dakota", "Tennessee", "Texas", "Utah", "Vermont", "Virginia", "Washington", "Washington DC",
  "West Virginia", "Wisconsin", "Wyoming"};
  char **found = (char **) bsearch(&state, stateNames, 51, sizeof(char *), stringcmp);

  if(found != NULL ) {
     printf("Found state = \"%s\"\n", *found);
  } else {
     printf("State = \"%s\" could not be found\n", state);
  }


  return(0);
}



// bsearch implementation
void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *)){
  int left = 0, right = nitems - 1, mid;
  const void *midElement;

  while(left <= right && left <= nitems - 1 && right >= 0){
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



// integers comparing function
int intcmp(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

// floats comparing function
int floatcmp(const void * a, const void * b) {
  if( *(float*)a - *(float*)b > 0){
    return 1;
  }else if( *(float*)a - *(float*)b < 0){
    return -1;
  }return 0;
}

// characters comparing function
int charcmp(const void * a, const void * b) {
  if (*(char *)a > *(char *)b)
   return 1;
  if (*(char *)a < *(char *)b)
    return -1;
  return 0;
}

// strings comparing function
int stringcmp(const void *s1, const void *s2) {
  return strcmp(*(char **) s1, *(char **) s2);
}

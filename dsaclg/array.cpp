#include <stdio.h>

void displayTraverse(int* arr, int size){
  int i = 0;
  while(i<size){
    printf("%d",arr[i]);
    i+=1;
  }
}
void insert(int* arr, int size, int key, int locn){
  int i = (size-1);
  size = size+1;
  while(i>locn){
    arr[i+1] = arr[i];
    i+=1;

  }
  arr[locn] = key;
}


int main(){

}

#include <stdio.h>
void createArray(int* arr, int size){
  int i = 0;
  while(i<size){
    scanf("%d", &arr[i]);
    i+=1;
  }
}
void displayTraverse(int* arr, int size){
  int i = 0;
  while(i<size){
    printf("%d ",arr[i]);
    i+=1;
  }
  printf("\n");
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
void delete(int* arr,int size, int key,int locn){
  int item = arr[(locn+1)];
  size = size -1;
  int i = locn;
  while(i<size){
    arr[i] = arr[i+1];
    i+=1;
  }
}
void merge(int* arr1, int* arr2, int* arr3, int n1, int n2){
  int i = 0,j =0, k=0;
  while(i<n1 && j <n2){
    if(arr1[i]<=arr2[j]){
      arr3[k] = arr1[i];
      i+=1;
    }else{
      arr3[k] = arr2[j];
      j+=1;
    }
    k+=1;
  }
  while(i<n1){
    arr3[k] = arr1[i];
    i++;
    k++;
  }
  while(j<n2){
    arr3[k] = arr2[j];
    j++;
    k++;
  }
  printf("The Final Sorted array is:\n");
  displayTraverse(arr3,n1+n2);
}
void linearSearch(int* arr, int size, int element){
	int  i =0;
	while(arr[i]!= element && i<size){
		i+=1;
	
	}
	if(i<size){
		printf("The number %d is at %d position", element, i+1 );
	}
	else{
		printf("The number is not present in the array");
	}
}

void binarySearch(int* arr, int size, int element){
	int beg, end, mid;
	beg = 0;
	end = (size -1);
	mid = (beg*05 + end*0.5);
	while(arr[mid]!=element && beg<=end){
		if(element < arr[mid]){
			end = mid -1 ;
			}
		else{
			beg = mid +1;
		}
		mid = ((beg*0.5) + (end*0.5));
	}
	if(arr[mid]== element){
		printf("The number %d is present in the array at the position %d", element, mid+1);
	}
	else{
		printf("The number is not present in the array");
	}
}
int main(void){
  // Call all the functions
  int size1, size2;
  printf("Enter the size of the array 1:");
  scanf("%d",&size1);
  printf("Enter the size of array 2:");
  scanf("%d", &size2);
  int arr1[size1];
  int arr2[size2];
  printf("Enter the elements of array 1:");
  createArray(arr1,size1);
  printf("Enter the elements of array 2:");
  createArray(arr2,size2);
  printf("The elements of array 1:");
  displayTraverse(arr1,size1);
  printf("The elements of array 2:");
  displayTraverse(arr2, size2);
  int arr3[size1+size2];
  merge(arr1, arr2, arr3, size1, size2);
  
  return 0;
}

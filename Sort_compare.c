/* Write the following two sorting functions

   

      1. Fastest sorting algorithm that you know

      2. Second fastest sorting algorithm that you know

 

     compare them by sorting 100000 randomly gerated integers in range 1 to 100 & also print the time taken by both of them. */
//-----------------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
int M[SIZE - 1];
int Timer=0;
int Timerb=0;
///...................................Merge Sort.....................................//


// Merge: Function to Merge L and R array into M array. 

void Merge(int *L,int left,int *R,int *M,int right) {
	int i,j,k;
			/* left = number of elements in L array
   			right = number of elements in R array. */
			
	i = 0; j = 0; k =0;
				/* i: variable for L array
				j: variable for L array
				k: variable for L array */
	while(i<left && j< right) {
		if(L[i]  < R[j]) M[k++] = L[i++];
		else M[k++] = R[j++];
	Timer++;
	}
	while(i < left){
		 M[k++] = L[i++];
		Timer++; }
	while(j < right){ M[k++] = R[j++];
		Timer++;
		}
}

// Recursive function to sort an array of integers. 
void Merge_Sort(int *M,int n) {
	int mid,i, *L, *R;
	if(n < 2) return; //If the array has less than two element, do nothing. 

	mid = n/2;  // find the mid index. 

	// create left and right subarrays
	L = (int*)malloc(mid*sizeof(int)); 
	for(i = 0;i<mid;i++){
	 L[i] = M[i];
	Timerb++;
		} // creating left subarray
	R = (int*)malloc((n- mid)*sizeof(int)); 
	for(i = mid;i<n;i++){
	 R[i-mid] = M[i];
	Timerb++;
		} // creating right subarray

	Merge_Sort(L,mid);  // sorting the left subarray
	Merge_Sort(R,n-mid);  // sorting the right subarray
	Merge(L,mid,R,M,n-mid);  // Merging L and R into M as sorted list.
        
	free(L); //deallocating space
        free(R); //deallocating space
}
//..............................testbench...................................................//
int Test_inputs() {
/* Code to test the Merge_Sort and Bubble_sort functions. */
	int i,M[SIZE - 1],numberOfElements;
    for( i = 0; i < SIZE - 1; i++)
    {
        M[i] = rand()%100+1;
    }
	
	numberOfElements = sizeof(M)/sizeof(M[0]); 

	// Calling merge sort to sort the array. 
	Merge_Sort(M,numberOfElements);
	bubbleSort(M,numberOfElements);

	//printing all elements in the array once its sorted.
	//for(i = 0;i < numberOfElements;i++) printf("%d ",M[i]);
	
    //	printSorted(); bubble sort 
}

//..........................................Bubble Sort.................................................//


void bubbleSort(int x[],int n)
{
    int i, j;
    for(i = 1; i < SIZE; i++)
    {
        for( j = 0; j < SIZE - 1; j++)
        {
            if(M[j] > M[j+1])
                swapf(j, j+1);
        }
    }
}

void swapf(int x, int y)
{
    int temp;
    temp = M[x];
    M[x] = M[y];
    M[y] = temp;
}
/* void printSorted()
{
    int i;
    for( i = 0; i < SIZE - 1; i++)
    {
        printf("%d\n", M[i]);
    }
}*/
int main() {
	Test_inputs();
	printf("Time taken for merge sort is:%d \n",Timer);
	printf("Time taken for bubble sort is:%d \n",Timerb);
	return 0;
}

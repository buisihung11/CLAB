#include <stdio.h>
#include <string.h>
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    printf("\nLeft Item: ");
    for (i = 0; i < n1; i++) {

        L[i] = arr[l + i];
        printf("%d   ",L[i]); 
    }
    printf("\nRight Item: ");
    for (j = 0; j < n2; j++) {

        R[j] = arr[m + 1+ j]; 
        printf("%d   ",R[j]); 
    }
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

int main(int argc, char const *argv[])
{
	/* code */
	int a[] = { 38 ,27,43,3,9,82,10};
	printf("Before:\n");
	for (int i = 0; i < 7; ++i)
	{
		printf("%d\t", a[i]);
	}
	printf("\n");
	mergeSort(a,0,6);
	printf("After:\n");
	for (int i = 0; i < 7; ++i)
	{
		printf("%d\t", a[i]);
	}
	return 0;
}
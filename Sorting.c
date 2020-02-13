#include<stdio.h>

void bubble(int ar[],int n);
void mergeSort(int ar[],int l,int r);
void quickSort(int ar[],int low,int high);
void display(int ar[],int n);
void swap(int* a, int* b);

int i,j,k,ar[100],l=0,r;

void main()
{
	int n,ans;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&ar[i]);
	printf("Choose Sorting Method:\n1:Bubble Sort\n2:Merge Sort\n3:Quick Sort\n");
	scanf("%d",&ans);
	r=n;
	switch(ans)
	{
		case 1: bubble(ar,n);
			break;
		case 2: mergeSort(ar,l,r);
			display(ar,r+1);
			break;
		case 3: quickSort(ar,l,r);
			display(ar,r+1);
			break;
		default:printf("Invalid Input !!");
	}
}

void bubble(int ar[],int n)
{
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(ar[j]>ar[j+1])
			{
				ar[j]=ar[j]+ar[j+1];
				ar[j+1]=ar[j]-ar[j+1];
				ar[j]=ar[j]-ar[j+1];
			}
		}
	}
	display(ar,n);
}

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
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
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
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

int partition (int arr[], int low, int high) 
{ 
    int j;
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for(j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

void display(int ar[],int n)
{
	printf("Sorted array:\n");
	for(i=1;i<n;i++)
		printf("%d ",ar[i]);
}

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
}

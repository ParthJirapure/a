// Write a program to sort the given array elements using selection sort largest element method.
//Fill in the missing code so that it produces the desired result

#include<stdio.h>
void main() {
	int a[20], i, n, j, large, index;
	printf("Enter value of n : ");
	scanf("%d", &n);
	// Write the code to read an array elements
	for(i=0;i<n;i++){
	printf("Enter element for a[%d] : ",i);
	scanf("%d",&a[i]);
	}
	printf("Before sorting the elements in the array are\n");
	// Write the code to print the given array elements before sorting
	for(i=0;i<n;i++){
	printf("Value of a[%d] = %d\n",i,a[i]);
	}
	// Write the code for selection sort largest element method
	for(i=n-1;i>0;i--){
	large = a[0];
	index = 0;
	for(j=1;j<=i;j++){
	if(a[j] > large){
		large = a[j];
	index = j;
}
}
a[index] = a[i];
a[i] = large;
}
printf("After sorting the elements in the array are\n");
// Write the code to print the given array elements after sorting
for(i=0;i<n;i++){
printf("Value of a[%d] = %d\n",i,a[i]);
}
}
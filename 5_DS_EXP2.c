//Write a program to sort the given elements using insertion sort technique.
//Fill in the missing code so that it produces the desired result.

#include<stdio.h>
void main() {
	int a[20], i, n, j, temp, pos;
	printf("Enter value of n : ");
	scanf("%d", &n);
	// write the for loop to read array elements
	for(i=0;i<n;i++){
	printf("Enter element for a[%d] : ",i);
	scanf("%d",&a[i]);
	}
	// write the for loop to display array elements before sorting
	printf("Before sorting the elements in the array are\n");
	for(i=0;i<n;i++){
	printf("Value of a[%d] = %d\n",i,a[i]);
	}
	for(pos=1;pos<n;pos++){
	temp = a[pos];
	for(j=pos;j>0;j--){
	if(a[j-1] > temp){
	a[j] = a[j-1];
	a[j-1] = temp;
	}
	}
}
// write the code to sort elements
printf("After sorting the elements in the array are\n");
// write the for loop to display array elements after sorting
for(i=0;i<n;i++){
printf("Value of a[%d] = %d\n",i,a[i]);
}
}
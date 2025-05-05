// Write a program to sort (Ascending order) the given elements using merge sort technique.

#include <stdio.h>
#include "MergeSortFunctions.c"
void main() {
	int arr[15], i, n;
	printf("Enter array size : ");
	scanf("%d", &n);
	printf("Enter %d elements : ", n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	printf("Before sorting the elements are : ");
	display(arr, n);
	splitAndMerge(arr, 0, n - 1);
	printf("After sorting the elements are : ");
	display(arr, n);
}

#include<stdio.h>
void merge(int arr[],int left,int mid,int right){
	int n1=mid-left+1;
	int n2=right-mid;
	int leftarr[n1],rightarr[n2];
	for(int i=0;i<n1;i++){
	leftarr[i]=arr[left+i];
	}
for(int i=0;i<n2;i++){
	rightarr[i]=arr[mid+1+i];
}
	int i=0,j=0,k=left;
	while(i<n1 && j<n2){
		if(leftarr[i]<=rightarr[j]){
	arr[k]=leftarr[i];
	i++;
	}else{
	arr[k]=rightarr[j];
	j++;
	}
	k++;
	}
    while(i<n1){
        arr[k]=leftarr[i];
        i++;
        k++;
        }
        while(i<n2){
        arr[k]=rightarr[j];
        i++;
        k++;
        }
        }
    void splitAndMerge(int arr[], int left, int right){
        if(left<right){
        int mid=left+(right-left)/2;
        splitAndMerge(arr,left,mid);
        splitAndMerge(arr,mid+1,right);
        merge(arr,left,mid,right);
        }
    }
    void display(int arr[],int size){
        for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
        }
        printf("\n");
    }
//
//  main.cpp
//  HeapRadixSort
//
//  Created by shijia hu on 3/19/17.
//  Copyright © 2017 shijia hu. All rights reserved.
//

#include <iostream>

using namespace std;

void maxHeapify(int *array, int index, int n){

    int left = index*2+1;
    int right = left+1;
    
    int largest = index;
    
    if(left < n && array[left] > array[index]){
        largest = left;
    }
    
    if(right < n && array[largest] < array[right]){
        largest = right;
    }
    
    if(largest!=index)
    {
        int temp=array[largest];
        array[largest]=array[index];
        array[index]=temp;
        maxHeapify(array,largest,n);
    }
}

void heapSort(int *array,int n)
{
    for(int i = n/2-1; i>=0 ; --i)
    {
        maxHeapify(array,i,n);
    }
    for(int i = n-1;i>=1;--i)
    {
        int temp=array[0];
        array[0]=array[i];
        array[i]=temp;
        
        maxHeapify(array,0,i);
        if (n<=20) {
            cout<<endl;
            printf("After executing one step, the result is:\n");
            for (int i = 0; i<n; i++) {
                for (int j = 0; j<array[i]; j++) {
                    printf("*");
                }
                printf("\n");
            }
            for (int k = 0; k < n; k++) {
                if (k == n-1) {
                    printf("%d\n",array[k]);
                    break;
                }
                printf("%d ", array[k]);
            }
        }
        
    }  
}

int getDigit(int number, int index)
{
    for (int i = index; i > 0; i--) {
        number /= 10;
    }
    return number % 10;
}

void countingSort(int *array, int n, int digit, int k=9)
{
    int *digitNum = new int[n];
    memset(digitNum, 0, n*sizeof(int));
    int *count = new int[k+1];
    memset(count, 0, (k+1)*sizeof(int));
    int *arrayResult = new int[n];
    memset(arrayResult, 0, n*sizeof(int));
    
    for (int idx = 0; idx<n; idx++)
        digitNum[idx] = getDigit(array[idx], digit);
    for (int idx = 0; idx<n; idx++)
        count[digitNum[idx]] = count[digitNum[idx]] + 1;
    for (int idx = 1; idx<k+1; idx++)
        count[idx] = count[idx] + count[idx-1];
    for (int idx=n-1; idx>=0; idx--)
    {
        arrayResult[count[digitNum[idx]]-1] = array[idx];
        count[digitNum[idx]] = count[digitNum[idx]] - 1;
    }
    
    memcpy(array, arrayResult, n*sizeof(int));
    
    delete [] digitNum;
    delete [] count;
    delete [] arrayResult;
}

void radixSort(int *array, int n, int digit){
    for (int index=0; index<=digit; index++) {
        countingSort(array, n, index);
        if (n<=20) {
            cout<<endl;
            printf("After executing one step, the result is:\n");
            for (int i = 0; i<n; i++) {
                for (int j = 0; j<array[i]; j++) {
                    printf("*");
                }
                printf("\n");
            }
            for (int k = 0; k < n; k++) {
                if (k == n-1) {
                    printf("%d\n",array[k]);
                    break;
                }
                printf("%d ", array[k]);
            }
        }
        
    }
}


int main(int argc, const char * argv[]) {
    while(1){
        printf("*************************************************\n");
        printf("************* 1   heap sort         *************\n");
        printf("************* 2   radix sort        *************\n");
        printf("*************************************************\n\n");
        
        int number;

        while (1) {
            printf("Please select a sorting algorithm(1-2):\n");
            scanf("%d", &number);
            if (number != 1 && number != 2) {
                printf("Wrong number of selection!\n");
            }else{
                break;
            }
        }
        
        int n;
        int arr[1002] = {0};
        
        while (1) {
            printf("Please enter the number of input data n(0-1000):\n");
            scanf("%d", &n);
            if (n > 0 && n <= 1000) {
                break;
            }else{
                printf("Wrong Number!\n");
            }
        }

        printf("You got an array for %d integers:\n", n);
        srand(time(0));
        
        
        if (n <= 20) {
            for (int i = 0; i<n; i++) {
                arr[i] = rand()%16;
                for (int j = 0; j<arr[i]; j++) {
                    printf("*");
                }
                printf("\n");
            }
            for (int i = 0; i<n; i++) {
                if (i == n-1) {
                    printf("%d\n",arr[i]);
                    break;
                }
                printf("%d ", arr[i]);
            }
            
        }else{
            if (number == 1) {
                for (int i = 0; i < n; i++) {
                    
                    arr[i] = rand() % 32668;
                    if (i == n-1) {
                        printf("%d\n",arr[i]);
                        break;
                    }
                    printf("%d ", arr[i]);
                }
            }else if (number == 2){
                for (int i = 0; i < n; i++) {
                    
                    arr[i] = rand() % 1000;
                    if (i == n-1) {
                        printf("%d\n",arr[i]);
                        break;
                    }
                    printf("%d ", arr[i]);
                }
            }
            
        }
        
        
        switch (number) {
            case 1:
                heapSort(arr, n);
                cout<<endl<<"The result of heap sort is:"<<endl;
                for (int k = 0; k < n; k++) {
                    if (k == n-1) {
                        printf("%d\n",arr[k]);
                        break;
                    }
                    printf("%d ", arr[k]);
                }

                break;
                
            case 2:
                if (n<=20) {
                    radixSort(arr, n, 2);
                }else{
                    radixSort(arr, n, 3);
                }
                cout<<endl<<"The result of radix sort is:"<<endl;
                for (int k = 0; k < n; k++) {
                    if (k == n-1) {
                        printf("%d\n",arr[k]);
                        break;
                    }
                    printf("%d ", arr[k]);
                }
                break;
            default:
                break;
        }
        
        printf("Input any character to continue or input N to exit:");
        char icontinue;
        scanf("\n%c",&icontinue);
        if (icontinue =='N' || icontinue =='n') {
            break;
        }
        
    }
    return 0;
}

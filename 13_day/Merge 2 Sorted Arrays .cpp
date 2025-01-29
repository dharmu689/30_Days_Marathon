#include <iostream>
using namespace std;

int* mergeArrays(int a[], int b[], int asize, int bsize) {
    int* mergedArray = new int[asize + bsize];
    int i = 0, j = 0, k = 0;

    while (i < asize && j < bsize) {
        if (a[i] < b[j]) {
            mergedArray[k++] = a[i++];
        } else {
            mergedArray[k++] = b[j++];
        }
    }

    while (i < asize) {
        mergedArray[k++] = a[i++];
    }

    while (j < bsize) {
        mergedArray[k++] = b[j++];
    }

    return mergedArray;
}

int main() {
    int a[] = {1, 2, 3, 6};
    int b[] = {4, 5, 7};
    int asize = sizeof(a) / sizeof(a[0]);
    int bsize = sizeof(b) / sizeof(b[0]);

    int* mergedArray = mergeArrays(a, b, asize, bsize);

    for (int i = 0; i < asize + bsize; i++) {
        cout << mergedArray[i] << " ";
    }
    cout << endl;

    delete[] mergedArray;
    return 0;
}


/*

int* mergeArrays(int a[], int b[], int asize, int bsize) {
  // Write your code here
    int* mergedArray = new int[asize + bsize];
    int i = 0, j = 0, k = 0;

    while (i < asize && j < bsize) 
    {
        if (a[i] < b[j]) 
        {
            mergedArray[k++] = a[i++];
        } 
        else 
        {
            mergedArray[k++] = b[j++];
        }
    }

    while (i < asize) 
    {
        mergedArray[k++] = a[i++];
    }

    while (j < bsize) 
    {
        mergedArray[k++] = b[j++];
    }

    return mergedArray;
  
}

*/
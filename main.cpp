//
// Created by Chad Beibide and Jackson Houston
//

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

//Sorting Functions
void mergeSort(int[], int, int);
void quickSort(int[]);
void bubbleSort(int[], int);
void insertionSort(int[]);
void blockSort(int[]);
void slowSort(int[]);

// Utility Functions
void printArray(int arr[], int n);
//void printStats();
void swap (int *x, int *y);

int arr10_preSorted[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    arr10_backwards[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

int main(){
    cout << "––-----------------------------------------" << endl
         << "Group Project" << endl
         << "Created by Chad Beibide and Jackson Houston" << endl
         << "––-----------------------------------------" << endl
         << endl;

    char input1, input2;

    cout << "Available Sorting Algorithms:" << endl
         << "1: Merge Sort" << endl
         << "2: Quick Sort" << endl
         << "3: Bubble Sort" << endl
         << "4: Insertion Sort" << endl
         << "5: Block Sort" << endl
         << "Slow Sort" << endl;
    do{
        cout << "Enter the number corresponding to an algorithm above:";
        cin >> input1;
    } while (input1 >= '1' && input1 <= '5');
    cout << endl;

    do{
        cout << "Enter the number corresponding to :";
        cin >> input1;
    } while (input1 >= '1' && input1 <= '5');

    switch (input1) {
        case '1':
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            break;
    }

    int arr[10];

    //Copy predefined array into an array to be manipulated
    copy(begin(arr10_backwards), end(arr10_backwards), begin(arr));

    printArray(arr, 10);
    bubbleSort(arr, 10);
    printArray(arr, 10);


    return 0;
}

void printArray(int arr[], int n){
    cout << "Array Contents: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void mergeSort(int arr[], int l, int r){
        if (l < r){
            int m = l + (r - l) / 2;
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            int n1 = m - l + 1;
            int n2 = r - m;
            int L[n1], R[n2];

            for(int i = 0; i < n1; i++)
                L[i] = arr[l + i];

            for(int j = 0; j < n2; j++)
                R[j] = arr[m + 1 + j];

            int i = 0;
            int j = 0;
            int k = l;

            while (i < n1 && j < n2){
                if (L[i] <= R[j]){
                    arr[k] = L[i];
                    i++;
                }
                else{
                    arr[k] = R[j];
                    j++;
                }
                k++;
            }

            while (i < n1){
                arr[k] = L[i];
                i++;
                k++;
            }

            while (j < n2){
                arr[k] = R[j];
                j++;
                k++;
            }
        }
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

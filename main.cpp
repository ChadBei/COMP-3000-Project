//
// Created by Chad Beibide and Jackson Houston
//

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

//Sorting Functions
void mergeSort(int[], int, int);
void quickSort(int[], int, int);
void bubbleSort(int[], int);
void insertionSort(int[]);
void blockSort(int[]);
void slowSort(int[]);

// Utility Functions
void printArray(int arr[], int n);
//void printStats();
void swap (int *x, int *y);
// TODO: void excecutionTime()

int const arr10_preSorted[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    arr10_backwards[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
    arr10_random[] = {7, 4, 10, 1, 5, 2, 9, 3, 6, 8},
    arr5_preSorted[] = {1, 2, 3, 4, 5},
    arr5_backwards[] = {5, 4, 3, 2, 1},
    arr5_random[] = {4, 2, 5, 1, 3},
    arr20_preSorted[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
    arr20_backwards[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
    arr20_random[] = {9, 13, 8, 11, 15, 4, 20, 2, 18, 1, 12, 14, 19, 7, 5, 16, 17, 3, 6, 10};

int main(){
    //Display header message
    cout << "––-----------------------------------------" << endl
         << "Group Project" << endl
         << "Created by Chad Beibide and Jackson Houston" << endl
         << "––-----------------------------------------" << endl
         << endl;

    // Variables to save input into
    char input1, input2;

    cout << "Available Sorting Algorithms:" << endl
         << "1: Merge Sort" << endl
         << "2: Quick Sort" << endl
         << "3: Bubble Sort" << endl
         << "4: Insertion Sort" << endl
         << "5: Block Sort" << endl
         << "6: Slow Sort" << endl;

    // Ensure a valid input is received
    do{
        cout << "Enter the number corresponding to an algorithm above:";
        cin >> input1;
    } while (!(input1 >= '1' && input1 <= '6'));
    cout << endl;


    cout << "Available Data Sets:" << endl
         << "1: Int Array Size: 5, Already Sorted" << endl
         << "2: Int Array Size: 5, Sorted Backwards" << endl
         << "3: Int Array Size: 5, Randomized Order" << endl
         << "4: Int Array Size: 10, Already Sorted" << endl
         << "5: Int Array Size: 10, Sorted Backwards" << endl
         << "6: Int Array Size: 10, Randomized Order" << endl
         << "7: Int Array Size: 20, Already Sorted" << endl
         << "8: Int Array Size: 20, Sorted Backwards" << endl
         << "9: Int Array Size: 20, Randomized Order" << endl;

    // Ensure a valid input is received
    do{
        cout << "Enter the number corresponding to the data set to be analyzed:";
            cin >> input2;
    } while (!(input2 >= '1' && input2 <= '9'));
    cout << endl;

    // Interpret the input for the data selection, copying the
    int arr[20], n = 0;
    switch (input2) {
        case '1':
            copy(begin(arr5_preSorted), end(arr5_preSorted), begin(arr));
            n = 5;
            break;
        case '2':
            copy(begin(arr5_backwards), end(arr5_backwards), begin(arr));
            n = 5;
            break;
        case '3':
            copy(begin(arr5_random), end(arr5_random), begin(arr));
            n = 5;
            break;
        case '4':
            copy(begin(arr10_preSorted), end(arr10_preSorted), begin(arr));
            n = 10;
            break;
        case '5':
            copy(begin(arr10_backwards), end(arr10_backwards), begin(arr));
            n = 10;
            break;
        case '6':
            copy(begin(arr10_random), end(arr10_random), begin(arr));
            n = 10;
            break;
        case '7':
            copy(begin(arr20_preSorted), end(arr20_preSorted), begin(arr));
            n = 20;
            break;
        case '8':
            copy(begin(arr20_backwards), end(arr20_backwards), begin(arr));
            n = 20;
            break;
        case '9':
            copy(begin(arr20_random), end(arr20_random), begin(arr));
            n = 20;
            break;
    }


    // TODO: Left off here, figure out how to call the different functions, keepig in mind that it will be run multiple times.
    // Interpret the input for the sorting algorithm
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

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return(i + 1);

}

void quickSort(int arr[], int low, int high){
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

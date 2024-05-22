#include<iostream>

using namespace std;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void displayArray(int pInt[], int n) {
    cout << "\nThe Array is : ";
    for(int i = 0; i < n ; i++){
        cout << pInt[i] << " ";
    }
}

int* bubbleSort(int arr[], int n) {
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++ ){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}

int* insertionSort(int arr[], int n){
    int* result = new int[n];
    result[0] = arr[0];
    int i, j;
    for( i = 1; i < n ; i++){
        for(j = i - 1; j >= 0; j--){
            if(arr[i] < result[j] ){
                result[j + 1] = result[j];
            }else{
                break;
            }
        }
        result[j + 1] = arr[i];
    }
    return result;
}

int * selectionSort(int arr[], int n){
    int max , index = 0;
    for(int i = 0; i < n ; i++){
        max = INT_MIN, index = 0;
        for(int j = 0; j < n - i ; j++){
            if(max < arr[j]){
                max = arr[j];
                index = j;
            }
        }
        int temp = arr[n - i - 1];
        arr[n - i - 1] = arr[index];
        arr[index ] = temp;
    }

    return arr;
}

void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *leftArray = new int[n1];
    int *rightArray = new int[n2];

    for(int i = 0; i < n1; i++){
        leftArray[i] = arr[left + i];
    }
    for(int j = 0; j < n1; j++){
        rightArray[j] = arr[mid + j + 1];
    }

    int i = 0, j = 0, k = left;
    while( i < n1 && j < n2){
        if(leftArray[i] <= rightArray[j]){
            arr[k] = leftArray[i];
            i++;
        }else{
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = rightArray[j];
        j++;
        k++;
    }

    delete[] leftArray;
    delete[] rightArray;
}


int *mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = left + (right - left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
    return arr;
}

int parition(int arr[], int low, int high){
    int pivot = arr[high];
    int index = low -1;

    for(int j = low ; j <= high -1; j++ ){
        if(arr[j] <= pivot){
            index++;
            swap(&arr[index], &arr[j]);
        }
    }
    swap(&arr[index + 1], &arr[high]);
    return index + 1 ;
}

int *quickSort(int arr[], int low, int high){
    if(low < high){
        int par = parition(arr, low, high);

        quickSort(arr, low, par - 1);
        quickSort(arr, par + 1, high);
    }
    return arr;
}

int main(){
    int arr[] = {5,9,2,2,2,68,1,4,64,6,11};
    int n = sizeof(arr)/ sizeof(arr[0]);

    cout << "Array Before: ";
    for(int& n : arr){
        cout << n << " ";
    }
    cout << "\n";
    int choice;
    // Select sorting algorithm.
    cout << "Select sorting algorithm:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Insertion Sort\n";
    cout << "3. Selection Sort\n";
    cout << "4. Merge Sort\n";
    cout << "5. Quick Sort\n";
    cout << "Enter your choice: ";
    cin >> choice;
    int *sortedArray;
    switch (choice) {
        case 1:
            sortedArray = bubbleSort(arr, n);
            break;
        case 2:
            sortedArray = insertionSort(arr, n);
            break;
        case 3:
            sortedArray = selectionSort(arr, n);
            break;
        case 4:
            sortedArray = mergeSort(arr, 0, n - 1);
            break;
        case 5:
            sortedArray = quickSort(arr, 0, n - 1);
            break;
        default:
            cout << "Invalid choice!" << endl;
            return 1;
    }

    // Display sorted array
    cout << "Sorted array: ";
    displayArray(arr, n);

    return 0;
}



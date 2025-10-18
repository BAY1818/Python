#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//For generating array 
void genArr(int arr[], int arrSize){
    for (int i = 0; i <= arrSize; i++){
        arr[i] = i + 1;
    }
    /*for (int n = 0; n <= arrSize; n++){
        cout << arr[n] << " ";
        if((n + 1) % 10 == 0) cout << endl;
    }*/
}

//Linear search algorithm
int linearSearch(int* arr, int arrSize, int target){
    for(int i = 0; i < arrSize; i++ ){
        if(arr[i] == target){
            cout << "Target is found at index: " << i << endl;
            return i;  
        }
    }
    return -1;
    
}

//Binary search algorithm
int binarySearch(int* arr, int arrSize, int target){
    int left = 0;
    int right = arrSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}


int main(){
    srand(time(0));
    int arrSize;
    cout << "Enter the array size: " ;
    cin >> arrSize;
    int* arr = new int[arrSize];
    
    genArr(arr,arrSize);
    cout << "Created array of size " << arrSize << " successfully." << endl;
           
    int target;
    cout << "Enter your target: ";
    cin >> target;
    
    clock_t startTime = clock();
    linearSearch(arr, arrSize, target);
    clock_t endTime = clock();
    double elapsed = double(endTime - startTime) / CLOCKS_PER_SEC;
    cout << "Linear search time: " <<  elapsed << " sec" << endl;

    clock_t start = clock();
    binarySearch(arr, arrSize, target);
    clock_t end = clock();
    double elapse = double(end - start) / CLOCKS_PER_SEC;
    cout << "Binary search time: " <<  elapse << " sec" << endl;

    delete [] arr;
    return 0;
}
    
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

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



int main(){
    srand(time(0));
    int arrSize;
    cout << "Enter the array size: " ;
    cin >> arrSize;
    int* arr = new int[arrSize];
    
    genArr(arr,arrSize);
    cout << "\nCreated array of size " << arrSize << " successfully." << endl;
           
    int target = 500000;
    
    clock_t startTime = clock();
    linearSearch(arr, arrSize, target);
    clock_t endTime = clock();
    double elapsed = double(endTime - startTime);
    cout << "Time of searching: " <<  elapsed << "sec"; 


    delete [] arr;
    return 0;
}
    
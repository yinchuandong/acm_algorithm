#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>

using namespace std;


class MedianFinder {
public:

    void swap(int arr[], int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    void adjustMinHeap(int arr[], int size, int i){
        int left, right, max;
        max = i;
        while(2*i < size){
            left = 2 * i + 1;
            right = 2 * i + 2;
            if(left < size && arr[max] < arr[left]){
                //node i has left leaf and node < left leaf
                max = left;
            }
            if(right < size && arr[max] < arr[right]){
                max = right;
            }
            if(max != i){
                swap(arr, i, max);
                i = max;
            }else{
                break;
            }
        }
    }
    void adjustMaxHeap(int arr[], int size, int i){
        int left, right, max;
        max = i;
        while(2*i < size){
            left = 2 * i + 1;
            right = 2 * i + 2;
            if(left < size && arr[max] > arr[left]){
                //node i has left leaf and node < left leaf
                max = left;
            }
            if(right < size && arr[max] > arr[right]){
                max = right;
            }
            if(max != i){
                swap(arr, i, max);
                i = max;
            }else{
                break;
            }
        }
    }

    void sortMinHeap(int arr[], int size){
        for(int i = size - 1; i > 0; i--){
            swap(arr, 0, i);
            adjustMinHeap(arr, i, 0);
        }
    }
    void sortMaxHeap(int arr[], int size){
        for(int i = size - 1; i > 0; i--){
            swap(arr, 0, i);
            adjustMaxHeap(arr, i, 0);
        }
    }

    void buildMinHeap(){
        int size = 10;
        int arr[] = {45,36,18,53,72,30,48,93,15,35};
        //build init heap
        
        // printMat(arr, size);
        for (int i = size / 2; i >= 0; i--){
            adjustMinHeap(arr, size, i);
        }
        // printMat(arr, size);
        sortMinHeap(arr, size);
        printMat(arr, size);
    }
    
    void buildMaxHeap(){
        int size = 10;
        int arr[] = {45,36,18,53,72,30,48,93,15,35};
        //build init heap
        
        // printMat(arr, size);
        for (int i = size / 2; i >= 0; i--){
            adjustMaxHeap(arr, size, i);
        }
        // printMat(arr, size);
        sortMaxHeap(arr, size);
        printMat(arr, size);
    }


    void printMat(int arr[], int size){
        for(int i = 0; i < size; i++){
            cout<<arr[i]<< ' ';
        }
        cout<<endl;
    }

    // Adds a number into the data structure.
    void addNum(int num) {
        
    }

    // Returns the median of current data stream
    double findMedian() {
        
        return 0.0;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

int main(int argNum, char* args[]){
    MedianFinder finder;
    finder.buildMinHeap();
    cout << "----------" << endl;
    finder.buildMaxHeap();
    cout<< "main funciton end"<<endl;
    return 0;
}
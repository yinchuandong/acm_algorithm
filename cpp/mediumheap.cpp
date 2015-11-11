#include <iostream>
#include <vector>

using namespace std;



class MedianFinder {
public:

    template <class T>
    void swap(T &a, T &b){
        T temp(a);
        a = b;
        b = temp;
    }

    template <class T>
    void adjustMinHeap(vector<T> &arr, int size, int i){
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
                swap(arr[i], arr[max]);
                i = max;
            }else{
                break;
            }
        }
    }

    template <class T>
    void adjustMaxHeap(vector<T> &arr, int size, int i){
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
                swap(arr[i], arr[max]);
                i = max;
            }else{
                break;
            }
        }
    }

    template <class T>
    void sortMinHeap(vector<T> &arr, int size){
        for(int i = size - 1; i > 0; i--){
            swap(arr[i], arr[0]);
            adjustMinHeap(arr, i, 0);
        }
    }

    template <class T>
    void sortMaxHeap(vector<T> &arr, int size){
        for(int i = size - 1; i > 0; i--){
            swap(arr[i], arr[0]);
            adjustMaxHeap(arr, i, 0);
        }
    }

    template <class T>
    void test(vector<T> &arr){
        swap(arr[0], arr[1]);
    }

    void buildMinHeap(){        
        cout << "------buildMinHeap function---------------"<<endl;
        vector<int> &arr = *assignVector();
        int size = arr.size();

        adjustMinHeap(arr, size, size/2);
        // printMat(arr, size);
        for (int i = size / 2; i >= 0; i--){
            adjustMinHeap(arr, size, i);
        }
        // printMat(arr, size);
        sortMinHeap(arr, size);
        printMat(arr, size);
    }
    
    void buildMaxHeap(){
        cout << "------buildMaxHeap function---------------"<<endl;
        vector<int> &arr = *assignVector();
        int size = arr.size();

        adjustMinHeap(arr, size, size/2);
        // printMat(arr, size);
        for (int i = size / 2; i >= 0; i--){
            adjustMaxHeap(arr, size, i);
        }
        // printMat(arr, size);
        sortMaxHeap(arr, size);
        printMat(arr, size);
    }

    vector<int>* assignVector(){
        int size = 10;
        int originArr[] = {45,36,18,53,72,30,48,93,15,35};
        vector<int> *arr = new vector<int>();
        for(int i = 0; i < size; i++){
            arr->push_back(originArr[i]);
        }

        return arr;
    }

    template <class T>
    void printMat(vector<T> arr, int size){
        // swap(arr[0], arr[1]);
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
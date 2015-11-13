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
    void adjustHeap(vector<T> &arr, int size, int i, bool isMaxHeap){
        int left, right, max;
        max = i;
        while(2*i < size){
            left = 2 * i + 1;
            right = 2 * i + 2;
            if(isMaxHeap){
                //max heap adjust
                if(left < size && arr[max] > arr[left]){
                    //node i has left leaf and node < left leaf
                    max = left;
                }
                if(right < size && arr[max] > arr[right]){
                    max = right;
                }
            }else{
                //min heap adjust
                if(left < size && arr[max] < arr[left]){
                    //node i has left leaf and node < left leaf
                    max = left;
                }
                if(right < size && arr[max] < arr[right]){
                    max = right;
                }
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
    void sortHeap(vector<T> &arr, int size, bool isMaxHeap){
        for(int i = size - 1; i > 0; i--){
            swap(arr[i], arr[0]);
            adjustHeap(arr, i, 0, isMaxHeap);
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

        adjustHeap(arr, size, size/2, false);
        for (int i = size / 2; i >= 0; i--){
            adjustHeap(arr, size, i, false);
        }
        sortHeap(arr, size, false);
        printMat(arr, size);
        insertHeap(arr, 80, false);
        deleteHeap(arr, 0, false);
        printMat(arr, arr.size());
    }
    
    void buildMaxHeap(){
        cout << "------buildMaxHeap function---------------"<<endl;
         vector<int> &arr = *assignVector();
        int size = arr.size();
        adjustHeap(arr, size, size/2, true);
        for (int i = size / 2; i >= 0; i--){
            adjustHeap(arr, size, i, true);
        }
        sortHeap(arr, size, true);
        printMat(arr, arr.size());
        insertHeap(arr, 80, true);
        printMat(arr, arr.size());
    }
    
    template <class T>
    void deleteHeap(vector<T> &arr, int index, bool isMaxHeap){
        int childId = 0;
        int n = arr.size() - 1;
        //replace the index node with last node
        arr[index] = arr[n];
        T temp = arr[index];
       
        
        while(2 * index < n){
            //left child
            childId = 2 * index + 1;
            //if has right child, record the max/min of left and right
//            if(childId + 1 < n && childId + 1 != n){
            if(childId + 1 <= n ){
                if (isMaxHeap && arr[childId] < arr[childId + 1]) {
                    childId += 1;
                }
                if (!isMaxHeap && arr[childId] > arr[childId + 1]) {
                    childId += 1;
                }
            }
            
            if (isMaxHeap) {
                if (arr[childId] > temp) {
                    swap(arr[childId], arr[index]);
                }else{
                    break;
                }
            }else{
                if (arr[childId] < temp) {
                    swap(arr[childId], arr[index]);
                }else{
                    break;
                }
            }
            
            index = childId;
        }
        arr.pop_back();
    }

    template <class T>
    void insertHeap(vector<T> &arr, T ele, bool isMaxHeap){
        arr.push_back(ele);
        int index = arr.size() - 1;
        int parent;
        while(index > 0){
            parent = (index - 1) / 2;
            if(isMaxHeap){
                if(arr[parent] < arr[index]){
                    swap(arr[index], arr[parent]);
                }else{
                    break;
                }
            }else{
                if(arr[parent] > arr[index]){
                    swap(arr[index], arr[parent]);
                }else{
                    break;
                }
            }
            index = parent;
        }

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
    
    vector<int>* assignVector(int originArr[]){
        int size = 10;
        vector<int> *arr = new vector<int>();
        for(int i = 0; i < size; i++){
            arr->push_back(originArr[i]);
        }
        
        return arr;
    }

    template <class T>
    void printMat(vector<T> &arr, int size){
        // swap(arr[0], arr[1]);
        for(int i = 0; i < size; i++){
            cout<<arr[i]<< ' ';
        }
        cout<<endl;
    }
    
public:
    vector<int> *maxHeap;
    vector<int> *minHeap;
    
    MedianFinder(){
        maxHeap = new vector<int>();
        minHeap = new vector<int>();
        
    }
    ~MedianFinder(){
        delete maxHeap;
        delete minHeap;
    }

    // Adds a number into the data structure.
    void addNum(int num) {
        insertHeap(*minHeap, num, false);
        int tempL = minHeap->at(0);
        deleteHeap(*minHeap, 0, false);
        insertHeap(*maxHeap, tempL, true);
        if (maxHeap->size() > minHeap->size()) {
            int tempR = maxHeap->at(0);
            deleteHeap(*maxHeap, 0, true);
            insertHeap(*minHeap, tempR, false);
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(minHeap->size() == maxHeap->size()){
            int max = (*maxHeap)[0];
            int min = (*minHeap)[0];
            return (max + min) / 2.0;
        }
        if(minHeap->size() > maxHeap->size()){
            return (double)minHeap->at(0);
        }else{
            return (double)maxHeap->at(0);
        }
    }
    
    void test1(){
        int size = 4;
        int originArr[] = {4, 6, 5, 7};
        vector<int> &arr = *(new vector<int>);
        for(int i = 0; i < size; i++){
            insertHeap(arr, originArr[i], false);
        }
        printMat(arr, arr.size());
        deleteHeap(arr, 0, false);
        printMat(arr, arr.size());
 
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

int main(int argNum, char* args[]){
    MedianFinder finder;

//     finder.buildMinHeap();
//    // cout << "----------" << endl;
//    finder.buildMaxHeap();
    
//    finder.test1();
    int size = 14;
//    int originArr[] = {1,2,3,4,5,6,7,8,9,10};
//    int originArr[] = {-1,-2,-3,-4, -5};
    int originArr[] = {78,14,50,20,13,9,25,8,13,37,29,33,55,52};
    for(int i = 0; i < size; i++){
        finder.addNum(originArr[i]);
    }
//    finder.addNum(29);
    double r = finder.findMedian();
    cout<< r<<endl;
    cout<< "main funciton end"<<endl;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
// A bunch of c++ sorts

// Swap
// O(1)
void Swap(int& a, int& b){ 
    int temp = a; 
    a = b; 
    b = temp; 
} 

// Select Smallest
// O(N)
int Select_Smallest(const vector<int> &v, int start){
    int smallest_val = v[start];
    int smallest_pos = start;
    for (int i = start + 1; i < v.size(); i++) {
        if (v[i] < smallest_val) {
            smallest_val = v[i];
            smallest_pos = i;
        }
    }
    return smallest_pos;
}

// Selection sort
// This is an O(N^2) in Best, Worst, and Normal case
void Selection_Sort(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        int smallest_pos = Select_Smallest(v, i); // Find the smallest element's position in the unsorted part
        Swap(v[i], v[smallest_pos]);              // Swap the found smallest element with the current element
    }
}

// Bubble sort
// This is an O(N^2) - Best case: O(N)
void Bubble_Sort(vector<int> &v){
    for (int i = 0; i < v.size() - 1; i++){
        for (int j = 0; j < v.size() - i - 1; j++){
            if (v[j] > v[j + 1]){
                Swap(v[j], v[j + 1]);   // Swap adjacent elements if they are in the wrong order
            }
        }
    }
}

// Merge
// O(N)
void Merge(vector<int> &v, int low, int mid, int high){
    // Create temporary vectors to hold the two halves
    vector<int> left(mid - low + 1);
    vector<int> right(high - mid);

    // Copy data to temporary left vector
    for (int i = 0; i < left.size(); i++)
        left[i] = v[low + i];
    // Copy data to temporary right vector
    for (int j = 0; j < right.size(); j++)
        right[j] = v[mid + 1 + j];

    // Indexes for left, right, and the original vector
    int l = 0;  // left
    int r = 0;  // right
    int o = low;    // original

    // Merge the two halves into the original vector
    while (l < left.size() && r < right.size()){
        if (left[l] <= right[r]){
            v[o++] = left[l++];
        } 
        else{
            v[o++] = right[r++];
        }
    }

    // Copy the remaining elements from the left half, if any
    while (l < left.size()){
        v[o++] = left[l++];
    }

    // Copy the remaining elements from the right half, if any
    while (r < right.size()){
        v[o++] = right[r++];
    }
}

// Merge Sort
// O(NlogN) in most cases, O(N) Best Case
void MergeSort(vector<int> &v, int low, int high){
    if(low < high){
        int mid = (low+high)/2;
        MergeSort(v,low,mid);
        MergeSort(v,mid+1,high);
        Merge(v,low,mid,high);
    }
}

// Partition
// O(N)
int Partition(vector<int> &v, int low, int high){
    int pivot_val = v[low];
    int last_small = low;
    int first_unseen = low + 1;
    while(first_unseen <= high){
        if(v[first_unseen] <= pivot_val){             // move to small side
          last_small++;                             // Increase Last_small
          swap(v[last_small],v[first_unseen]);    // Swaps the last smallest value with the next unseen
        }
        first_unseen++;
    }
    Swap(v[low],v[last_small]); // Swaps the element in the middle with the pivot
    return last_small;
}

// Quicksort
// O(NlogN) in most cases, O(N^2) in worst case
void QuickSort(vector<int> &v, int low, int high){
    if (low < high) {
        int pivot_pos = Partition(v, low, high); // Get the pivot position
        QuickSort(v, low, pivot_pos - 1); // Sort the left side of the pivot
        QuickSort(v, pivot_pos + 1, high); // Sort the right side of the pivot
    }
}

int main(){
    // Vector of numbers to test
    vector<int> numbers = {9,8,7,6,5,4,3,2,1,0};
    
    // Selection_Sort(numbers);
    // Bubble_Sort(numbers);
    // MergeSort(numbers, 0, numbers.size()-1);
    // QuickSort(numbers, 0, numbers.size()-1);
    
    // Display the numbers in the vector to the screen
    for(int i = 0; i < numbers.size(); i++){
        if(i < numbers.size()-1)
            cout << numbers[i] << ", ";
        else
            cout << numbers[i] << endl;
    }
}
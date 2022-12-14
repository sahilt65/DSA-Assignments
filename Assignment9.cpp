/*
Implement Heap sort to sort given set of values using max or min heap.
*/

#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if(left <= n && arr[largest] < arr[left]){
       //((left <= n)checking left exist or not)
        largest = left;
    }

    if(right  <=  n && arr[largest] < arr[right]){
      //((right <= n)checking right exist or not)  
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    int size = n;

    while(size>1){
        //step 1
        swap(arr[1], arr[size]);
        //step 2
        size--;
        //step 3
        heapify(arr, size, 1);

    }
}


int main() {
    // heap h ;
    int v;
    cout<<"Enter the size of Heap"<<endl;
    cin>>v;
    v = v+1;
    int arr[v];
    arr[0] = -1;

    int n = v-1;
    cout<<"Enter the Elements in the Heap"<<endl;
    for(int i = 1; i<v; i++){
        cin>>arr[i];
    }

    for(int i = n/2; i>0; i--){
        heapify(arr, n, i);
    }
     
    cout<<"Printing Array Before Heap Sort"<<endl;
    for(int i = 1 ; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;

    heapSort(arr, n);
    cout<<"Printing Array After Heap Sort"<<endl;
    for(int i = 1 ; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl; 
    
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

// selection sort 
// Time Complexity : O(n^2)
// Space Complexity : O(1)
void selection_sort(vector<int> arr) {

  for (int i = 0; i < arr.size()-1; i++) {
    int mini = i;
    for (int j = i + 1; j < arr.size(); j++) {
      if (arr[j] < arr[mini]) {
        mini = j;
      }
    }
    swap(arr[i],arr[mini]);
  }

  cout << "After selection sort: " << "\n";
  for (int i=0;i<arr.size();i++) {
    cout<<arr[i]<<" ";
  }
  cout << "\n";

}

// bubble sort
// Time Complexity = O(n^2)
// Space Complexity = O(1)
void bubble_sort(vector<int> arr) {
    for (int i = arr.size()-1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j],arr[j+1]);
            }
        }
    }

    cout << "After Using bubble sort: " << "\n";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void rec_bubble(vector<int> &arr,int i){
  if(i==1){
    cout << "After recursive bubble sort: " << "\n";
    for (int j = 0; j < arr.size(); j++) {
      cout << arr[j] << " ";
    }
    cout << "\n";
    return;
  } 

  bool swapped=0;
  for(int j=0;j<i-1;j++){
    if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
    swapped=1;
  }
  if(!swapped) return;
  else rec_bubble(arr,i-1);
}

//insertion sort
//Time Complexity = O(n^2)
//Space Complexity = O(1)
void insertion_sort(vector<int> arr) {
    for (int i = 0; i <= arr.size()-1; i++) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            swap(arr[j],arr[j-1]);
            j--;
        }
    }

    cout << "After Using insertion sort: " << "\n";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void rec_insertion(vector<int> arr, int i){
    if(i==arr.size()){
    cout << "After recursive insertion sort: " << "\n";
    for (int j = 0; j < arr.size(); j++) {
      cout << arr[j] << " ";
    }
    cout << "\n";
    return;
  } 
  int j=i;
  while(j>0 && arr[j]<arr[j-1]){
    swap(arr[j],arr[j-1]);
    j--;
  }
  rec_insertion(arr,i+1);
}

//merge sort
//Time Complexity = O(nlogn)
//Space Complexity = O(n)
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}
void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high)
      return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid);  // left half
    mergeSort(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);  // merging sorted halves
}

//quick sort
//Time complexity = O(nlogn)
//Space complexity = O(1) + O(n)"stack"
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}
void quicksort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        quicksort(arr, low, pIndex - 1);
        quicksort(arr, pIndex + 1, high);
    }
}

int main() {
//   int arr[] = {13,46,24,52,20,9};
//   int n = sizeof(arr) / sizeof(arr[0]);
    int n;
    cin>>n;
    vector<int> arr;
    while(n--){
        int x;
        cin>>x;
        arr.push_back(x);
    }
   cout << "Before sort: " << "\n";
   for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
    }
  cout << "\n";

  // selection_sort(arr);
  // bubble_sort(arr);
  // insertion_sort(arr);

  // rec_bubble(arr,arr.size());
  // rec_insertion(arr,1);

  // mergeSort(arr,0,arr.size()-1);
  // cout << "After Merge Sort: " << "\n";
  //     for (int i = 0; i < arr.size(); i++) {
  //       cout << arr[i] << " ";
  //      }
  //     cout << "\n";

  //  quicksort(arr,0,arr.size()-1);
  //   cout << "After Quick Sort: " << "\n";
  //     for (int i = 0; i < arr.size(); i++) {
  //       cout << arr[i] << " ";
  //      }
  //     cout << "\n";


  
  return 0;
}
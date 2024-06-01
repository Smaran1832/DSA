#include<bits/stdc++.h>
using namespace std;

//Simple for loop search
int findLargestElement(int arr[], int n) {
 
  int max = arr[0];
  for (int i = 0; i < n; i++) {
    if (max < arr[i]) {
      max = arr[i];
    }
  }
  return max;
}

//two variable hierarchy
int secondLargest(int arr[],int n)
{
	if(n<2)
	return -1;
    int large=INT_MIN,second_large=INT_MIN;
    int i;
    for (i = 0; i < n; i++) 
    {   
        //current number greater than largest
        if (arr[i] > large) 
        {
            second_large = large;
            large = arr[i];
        }

        //current number greater than second largest
        else if (arr[i] > second_large && arr[i] != large) 
        {
            second_large = arr[i];
        }
    }
    return second_large;                
}

//simple forward comparison with modulus
bool check_sorted_rotated(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums[(i+1)%(nums.size())]) //modulus concept important for full check of the array
                count++;   
        }
        if(count>1) 
            return false;

        return true;
    }

//move newer unique elements to with the help of a static index pointer for latest unique
int removeDuplicates(int arr[], int n)
{
  int i = 0;
  for (int j = 1; j < n; j++) {
    if (arr[i] != arr[j]) {
      i++;
      arr[i] = arr[j];
    }
  }
  return i + 1;
}

//new array with calculated index 
void rotate_left(vector<int>& nums, int k) {
        vector<int> nums2(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            nums2[(i+k)%nums.size()]=nums[i];
        }
        nums=nums2;
    }

//another approach using reverse
void Rotateeletoleft(int arr[], int n, int k)
{
  // Reverse first k elements
  reverse(arr, arr+k);
  // Reverse last n-k elements
  reverse(arr+k,arr+n);
  // Reverse whole array
  reverse(arr,arr+n);
}

//static index pointer with newer values being swapped with latest index value
void moveZeroes(vector<int>& nums) {
        int index=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[index++],nums[i]);
            }
        }
    }


//for sorted arrays
vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
  int i = 0, j = 0; // static pointers for individual arrays
  vector < int > Union; // Uninon vector
  while (i < n && j < m) {
    if (arr1[i] <= arr2[j]) // Case 1 and 2  (smaller and equal; equal taken care via 2nd || check )
        {
            if (Union.size() == 0 || Union.back() != arr1[i])
             Union.push_back(arr1[i]);
             i++;
         } 
    else // case 3
        {
          if (Union.size() == 0 || Union.back() != arr2[j])
            Union.push_back(arr2[j]);
          j++;
        }
  }
  while (i < n) // IF any element left in arr1
  {
    if (Union.back() != arr1[i])
      Union.push_back(arr1[i]);
    i++;
  }
  while (j < m) // If any elements left in arr2
  {
    if (Union.back() != arr2[j])
      Union.push_back(arr2[j]);
    j++;
  }
  return Union;
}

//intersection is similar 3 pointers a1(arr1),a2(arr2),a3(interection) 
//if arr1[a1]==arr2[a2] insert insertion and increment all indexes else increase the index for smaller element 


//Summation method
int missingNumber(vector<int>& nums) {
        int sum=(nums.size()*nums.size()+nums.size())/2;
        int arr_sum=accumulate(nums.begin(),nums.end(),0);
        return abs(arr_sum-sum);
    }


//XOR
int missingNumber(vector<int>&a, int N) {

    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < N - 1; i++) {
        xor2 = xor2 ^ a[i]; // XOR of array elements
        xor1 = xor1 ^ (i + 1); //XOR up to [1...N-1]
    }
    xor1 = xor1 ^ N; //XOR up to [1...N]

    return (xor1 ^ xor2); // the missing number
}    

//only number appearing once others appearing twice XOR concept
int singleNumber(vector<int>& nums) {
        int n=0;
        for(int i=0;i<nums.size();i++){
            n=n^nums[i];
        }
        return n;
    }

//all numbers thrice except one pattern recognition 
int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i+=3){
            if(nums[i]!=nums[i-1]){
                return nums[i-1];
            }
        }
        return nums.back();
    }

//positives and negatives    
//hashing prefix sum (if {sum-k} exists previously that means current from that {index + 1} till current index exist new subarray with the sum k)
int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        //calculate the prefix sum till index i:
        sum += a[i];

        // if the sum = k, update the maxLen:
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        long long rem = sum - k;

        //Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        //Finally, update the map checking the conditions since there is possibility of zeros and require the longest:
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}

//only positives and zeros
//two pointer type of sliding window (if sum>k drop the leftmost item and see the how many more can be accomodated till process repeats)
int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;
    while (right < n) {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move forward the right pointer:
        right++;
        if (right < n) sum += a[right];
    }

    return maxLen;
}

//simple hashing and querying for pair while travesing
vector<int> twoSum(int n, vector<int> &arr, int target) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return { -1, -1};
}

//two pointer approach to verify if pair exists
string istwoSum(int n, vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return "YES";
        }
        else if (sum < target) left++;
        else right--;
    }
    return "NO";
}

//count and insert
void sortColors(vector<int>& nums) {
        int zeroes=0,ones=0,twos=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zeroes++;
            else if(nums[i]==1) ones++;
            else twos++;
        }
        int index=0;
        while(zeroes--) nums[index++]=0;
        while(ones--) nums[index++]=1;
        while(twos--) nums[index++]=2;
    }
   
//Ducth-Flag Algo three elements (array below low and after high is assumed to be sorted)
void sortArray(vector<int>& arr, int n) {

    int low = 0, mid = 0, high = n - 1; // 3 pointers

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

//Moore's voting Algo (simply put majority element will have extra element and will replace the ele by the end(dominance))
int majorityElement(vector<int>& nums) {
        int count=0;
        int ele;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                ele=nums[i];
                count++;
            }else if(nums[i]==ele){
                count++;
            }else{
                count--;
            }
        }
        return ele;
    }

//pick the previous subarray iff positive cumulative sum (max!=k specific sum)
int maxSubArray(vector<int>& nums) {
        int start=0,end=0,max=INT_MIN,sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum<0){
                sum=nums[i];
                start=i;
                end=i;
            }else if(sum>=0){
                sum+=nums[i];
                end=i;
            }

            if(sum>max) max=sum;

        }
        //return end-start+1; if length of max subarray
        return max;
    }

//dp stocks buy and sell 1 ( update the min and max while traversing)
int maxProfit(vector<int>& prices) {
        int mini=prices[0],profit=0;
        for(int i=1;i<prices.size();i++){
            profit=max(profit,prices[i]-mini);
            mini=min(mini,prices[i]);
        }
        return profit;
    }

// n/2 positive and negative (simple alloting position in new array)
vector<int> rearrangeArray(vector<int>& nums) {
        int positive_in=0,negative_in=1;
        vector<int> arr(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                arr[positive_in]=nums[i];
                positive_in+=2;
            }else{
                arr[negative_in]=nums[i];
                negative_in+=2;
            }
                
        }
             return arr;
    }    

//unequal positives and negatives
vector<int> RearrangebySign(vector<int>A, int n){
    
  // Define 2 vectors, one for storing positive 
  // and other for negative elements of the array.
  vector<int> pos;
  vector<int> neg;
  
  // Segregate the array into positives and negatives.
  for(int i=0;i<n;i++){
      
      if(A[i]>0) pos.push_back(A[i]);
      else neg.push_back(A[i]);
  }
  
  // If positives are lesser than the negatives.
  if(pos.size() < neg.size()){
      
    // First, fill array alternatively till the point 
    // where positives and negatives ar equal in number.
    for(int i=0;i<pos.size();i++){
      
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
    }
    
    // Fill the remaining negatives at the end of the array.
    int index = pos.size()*2;
    for(int i = pos.size();i<neg.size();i++){
        
        A[index] = neg[i];
        index++;
    }
  }
  
  // If negatives are lesser than the positives.
  else{
      
      // First, fill array alternatively till the point 
      // where positives and negatives ar equal in number.
      for(int i=0;i<neg.size();i++){
      
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
  }
    
    // Fill the remaining positives at the end of the array.
    int index = neg.size()*2;
    for(int i = neg.size();i<pos.size();i++){
        
        A[index] = pos[i];
        index++;
    }
  }
  return A;
    
}

//elements sorted till a point dip
void nextPermutation(vector<int>& nums) {
        int n=nums.size(),dip=-1;
        //find the the dip from last element to find the possibility of next permutation
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                dip=i;
                break;
            }
        }
        //no possible next permutation
        if(dip==-1){
            reverse(nums.begin()+dip+1,nums.end());
            return;
        }
        //generate the next permutation by switching last greater character
        for(int i=n-1;i>dip;i--){
            if(nums[dip]<nums[i]){
                swap(nums[dip],nums[i]);
                break;
            }
        }
        //right now the combination is after dip is the last permutation(decreasing order) need to change it to smallest for it to be exact succession of the overall string
        reverse(nums.begin()+dip+1,nums.end());
    }

//simple comparison and pushing
vector<int> printLeaders(int arr[], int n) {

  vector<int> ans;
  
 // Last element of an array is always a leader,
 // push into ans array.
 int max = arr[n - 1];
 ans.push_back(arr[n-1]);

  // Start checking from the end whether a number is greater
  // than max no. from right, hence leader.
  for (int i = n - 2; i >= 0; i--)
    if (arr[i] > max) {
      ans.push_back(arr[i]);
      max = arr[i];
    }

  
  return ans;
}

//longest consecutive sequence that can be made
int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int count=0,maxi=0;
        for(auto it:st){
            if(st.find(it-1)!=st.end()){
                continue;
            }else{
                while(st.find(it++)!=st.end()){
                    count++;
                }
                maxi=max(maxi,count);
                count=0;
            }
        }
        return maxi;
    }

void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int col0=1; //make a different variable for column 0 specifically; using matrix[0][0] for the row0

        //Finding and marking the zeores in first row and column
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    if(j!=0){
                        matrix[0][j]=0;
                    }else{
                        col0=0;
                    }
                }
            }
        }

        //For the row setting corresponding zeroes of the sub matrix
        for(int i=1;i<n;i++){
            if(matrix[i][0]==0){
                for(int j=1;j<m;j++){
                    matrix[i][j]=0;
                }
            }
        }

        //For the column setting corresponding zeroes of the sub matrix
        for(int i=1;i<m;i++){
            if(matrix[0][i]==0){
                for(int j=1;j<n;j++){
                    matrix[j][i]=0;
                }
            }
        }

        
        //if 0th row is to be set to 0 
        if (matrix[0][0] == 0) {
            for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
            }
        }
        //if 0th col is to be set to 0 
        if (col0 == 0) {
            for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
            }
        }
    }   

//rotate by 90
void rotate(vector<vector<int>>& matrix) {
        //transpose
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<matrix.size();i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }

//simple implementation using stl
void merge(long long arr1[], long long arr2[], int n, int m) {

    //Declare 2 pointers:
    int left = n - 1;
    int right = 0;

    //Swap the elements until arr1[left] is
    // smaller than arr2[right]:
    while (left >= 0 && right < m) {
        if (arr1[left] > arr2[right]) {
            swap(arr1[left], arr2[right]);
            left--, right++;
        }
        else {
            break;
        }
    }

    // Sort arr1[] and arr2[] individually:
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

int main(){
    return 0;
}
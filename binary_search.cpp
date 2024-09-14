#include<bits/stdc++.h>
using namespace std;

int Binary_search(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1,mid;
        while(start<=end){
            mid=start+(end-start)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]<target){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return -1;
    }

int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int upperBound(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}


//element position in the list if it exists(real position) or not(appropriate) 
int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(),nums.end(),target) - nums.begin();
    }

int findFloor(int arr[], int n, int x) {
	int low = 0, high = n - 1;
	int ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		// maybe an answer
		if (arr[mid] <= x) {
			ans = arr[mid];
			//look for smaller index on the left
			low = mid + 1;
		}
		else {
			high = mid - 1; // look on the right
		}
	}
	return ans;
}

int findCeil(int arr[], int n, int x) {
	int low = 0, high = n - 1;
	int ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		// maybe an answer
		if (arr[mid] >= x) {
			ans = arr[mid];
			//look for smaller index on the left
			high = mid - 1;
		}
		else {
			low = mid + 1; // look on the right
		}
	}
	return ans;
}

//first and last occurances // number of occurances = last-first
vector<int> searchRange(vector<int>& nums, int target) {
        int first,last;
        first = (lower_bound(nums.begin(),nums.end(),target)-nums.begin());
        if(first==nums.size() || nums[first]!=target){
            return {-1,-1};
        }
        last = (upper_bound(nums.begin(),nums.end(),target)-nums.begin());
        return {first,last-1};
    }

//binary search single rotated array distinct elements
int search(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1,mid;
        while(start<=end){
                mid=start+(end-start)/2;
                if(nums[mid]==target){
                    return mid; 
                //left sorted       
                }else if(nums[mid]>=nums[start]){
                    if(target<=nums[mid] && target>=nums[start]){
                        end=mid-1;
                    }else{
                        start=mid+1;
                    }
                //right sorted    
                }else{
                    if(target>=nums[mid] && target<=nums[end]){
                        start=mid+1;
                    }else{
                        end=mid-1;
                    }
                }          
        }
      return -1;  
    }

//duplicates present in rottated array search; 
bool rotated_search(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1,mid;
        while(start<=end){
                mid=start+(end-start)/2;
                if(nums[mid]==target){
                    return true;
                }else if(nums[mid]==nums[start] && nums[mid]==nums[end]){
                    start++;
                    end--;
                    continue;     
                //left sorted       
                }else if(nums[mid]>=nums[start]){
                    if(target<=nums[mid] && target>=nums[start]){
                        end=mid-1;
                    }else{
                        start=mid+1;
                    }
                //right sorted    
                }else{
                    if(target>=nums[mid] && target<=nums[end]){
                        start=mid+1;
                    }else{
                        end=mid-1;
                    }
                }          
        }
      return false;
    }

//minimum in rotated array
int findMin(vector<int>& nums) {
        int start=0,end=nums.size()-1,mid,mini=nums[0];
        while(start<=end){
            mid=start+(end-start)/2;
            if(nums[start]<=nums[mid]){
                mini=min(nums[start],mini);
                start=mid+1;
            }else{
                 mini=min(nums[mid],mini);
                 end=mid-1;
            }
        }
        return mini;
    }

//number of rotations in the array meaning how many elements have been rotated
int findKRotation(vector<int> &arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        //search space is already sorted
        //then arr[low] will always be
        //the minimum in that search space:
        if (arr[low] <= arr[high]) {
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }
            break;
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            // keep the minimum:
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }

            // Eliminate left half:
            low = mid + 1;
        }
        else { //if right part is sorted:

            // keep the minimum:
            if (arr[mid] < ans) {
                index = mid;
                ans = arr[mid];
            }

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return index;
}

//single occurance ; observation based solution even-odd the odd-even pivot
int singleNonDuplicate(vector<int>& nums) {
        int start=0,end=nums.size()-1,mid;
        if(end==0) return nums[0];
        if(nums[start]!=nums[start+1]) return nums[start];
        if(nums[end]!=nums[end-1]) return nums[end];
        start++;
        end--;
        while(start<=end){
            mid=start+(end-start)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid+1]!=nums[mid]){
                return nums[mid];
            }else if(mid%2==0){
                if(nums[mid]==nums[mid+1]) start=mid+1;
                else end=mid-1;
            }else{
                if(nums[mid]!=nums[mid+1]) start=mid+1;
                else end=mid-1;
            }
        }
        return -1;
    }


// find peaks similar tweaking to single occurance; special case of low handled by simple else block rather than case sepecif else
int findPeakElement(vector<int>& nums) {
        int start=0,end=nums.size()-1,mid;
        if(end==0) return 0;
        if(nums[start]>nums[start+1]) return 0;
        if(nums[end]>nums[end-1]) return end;
        start++;
        end--;
        while(start<=end){
            mid=start+(end-start)/2;
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
                return mid;
            }else if(nums[mid]>nums[mid+1]){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return -1;
    }


int floorSqrt(int n) {
    int low = 1, high = n;
    //Binary search on the answers:
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long val = mid * mid;
        if (val <= (long long)(n)) {
            //eliminate the left half:
            low = mid + 1;
        }
        else {
            //eliminate the right half:
            high = mid - 1;
        }
    }
    return high;
}

//return 1, if == m:
//return 0, if < m:
//return 2, if > m:
int func(int mid, int n, int m) {
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * mid;
        if (ans > m) return 2;
    }
    if (ans == m) return 1;
    return 0;
}

int NthRoot(int n, int m) {
    //Use Binary search on the answer space:
    int low = 1, high = m;
    while (low <= high) {
        int mid = (low + high) / 2;
        int midN = func(mid, n, m);
        if (midN == 1) {
            return mid;
        }
        else if (midN == 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}


//Koko bananas
 int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();
    //find the maximum:
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

int calculateTotalHours(vector<int> &v, int hourly) {
    int totalH = 0;
    int n = v.size();
    //find total hours:
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}

    long long minEatingSpeed(vector<int>& v, long long h) {
        int low = 1, high = findMax(v);

    //apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        int totalH = calculateTotalHours(v, mid);
        if (totalH <= h) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
    }


//Minimum bloomday flowers
 long long enoughDays(vector<int>& bloomDay, int d, int k){
        long long cnt=0,boq=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=d){
                cnt++;
            }else{
                boq+=cnt/k; //takes care of the adajacency contrainst
                cnt=0;
            }
        }
        boq+=cnt/k; //very important //although could be checked above in if clause
        return boq;
    } 

    long long minDays(vector<int>& bloomDay, int m, int k) {
          
          if((long long)m*k>bloomDay.size()) return -1;

          int start=*min_element(bloomDay.begin(),bloomDay.end());
          int end=*max_element(bloomDay.begin(),bloomDay.end());
          
          int mid=0,ans=0;
          while(start<=end){
              mid=start+(end-start)/2;
              if(enoughDays(bloomDay,mid,k)>=m){
                  ans=mid;
                  end=mid-1;
              }else{
                  start=mid+1;
              }
          }
          return ans;
    }


//Minimum ships days
int possibleDay(vector<int>& weights,int w){
        int cnt=1,totalw=0;
        for(int i=0;i<weights.size();i++){
            if(totalw+weights[i]>w){ //increase if the weight goes above the daily limit
                cnt++;
                totalw=weights[i]; 
            }else{
                totalw+=weights[i];
            }
        }
        return cnt;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        
        int end=0,start=INT_MIN;
        for(int i=0;i<weights.size();i++){
            end+=weights[i];  //end will be all the weights alltogether
            start=max(start,weights[i]); //minimum limit we need is the max weight of the item 
        }

        int mid;
        while(start<=end){
            mid=start+(end-start)/2;
            if(possibleDay(weights,mid)<=days){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }   
        return start; 
    }

//smallest divisor
    int min_threshold(vector<int>& nums,int divisor){
        int Sum=0;
        for(double i:nums){
            Sum+=ceil(i/divisor);
        }
        return Sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int start=1,mid;
        int end=*max_element(nums.begin(),nums.end());
        while(start<=end){
            mid=start+(end-start)/2;
            if(min_threshold(nums,mid)<=threshold){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return start;
    }

//kth missing number in increasing missing
int findKthPositive(vector<int>& arr, int k) {
        int start=0;
        int end=arr.size()-1;
        int mid;
        while(start<=end){
            mid=start+(end-start)/2;
            if(arr[mid]-mid>k){ //number of mising numbers greater than k
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return (k+(end))+1; //(arr[end]+(k-(arr[end]-end))+1)
    }


//aggressive cows
bool canWePlace(vector<int> &stalls, int dist, int cows) {
    int n = stalls.size(); //size of array
    int cntCows = 1; //no. of cows placed
    int last = stalls[0]; //position of last placed cow.
    for (int i = 1; i < n; i++) {
        if (stalls[i] - last >= dist) {
            cntCows++; //place next cow.
            last = stalls[i]; //update the last location.
        }
        if (cntCows >= cows) return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k) {
    int n = stalls.size(); //size of array
    //sort the stalls[]:
    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls[n - 1] - stalls[0];
    //apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, k) == true) {
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return high;
}

//book allocation like A-cows and shipping problem
int countStudents(vector<int> &arr, int pages) {
    int n = arr.size(); //size of array.
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++) {
        if (pagesStudent + arr[i] <= pages) {
            //add pages to current student
            pagesStudent += arr[i];
        }
        else {
            //add pages to next student
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int>& arr, int n, int m) {
    //book allocation impossible:
    if (m > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        if (students > m) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}


//painter's partition //array splits //similar to previous problems
int possibleSplit(vector<int>& nums, int sum){
        int splits=1,seq_sum=0;
        for(int i:nums){
            if(seq_sum+i>sum){
                seq_sum=i;
                splits++;
            }else{
                seq_sum+=i;
            }
        }
        return splits;
    }

    int splitArray(vector<int>& nums, int k) {
        int start=*max_element(nums.begin(),nums.end()),mid;
        int end=accumulate(nums.begin(),nums.end(),0);

        while(start<=end){
            mid=start+(end-start)/2;
            if(possibleSplit(nums,mid)<=k){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return start;

    }

//priority queue approach
long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size(); //size of array.
    vector<int> howMany(n - 1, 0); //since we create only current index to track space. it would help keep track of the dynamic placement of the stations
    priority_queue<pair<long double, int>> pq;

    //insert the first n-1 elements into pq
    //with respective distance values:
    for (int i = 0; i < n - 1; i++) {
        pq.push({arr[i + 1] - arr[i], i});
    }

    //Pick and place k gas stations:
    for (int gasStations = 1; gasStations <= k; gasStations++) {
        //Find the maximum section
        //and insert the gas station:
        auto tp = pq.top();
        pq.pop();
        int secInd = tp.second;

        //insert the current gas station:
        howMany[secInd]++;

        long double inidiff = arr[secInd + 1] - arr[secInd];
        long double newSecLen = inidiff / (long double)(howMany[secInd] + 1); //will sort of keep a dynamic track of space
        pq.push({newSecLen, secInd});
    }

    return pq.top().first;
}    


//binary search approach
int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
    int n = arr.size(); // size of the array
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
        if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size(); // size of the array
    long double low = 0;
    long double high = 0;

    //Find the maximum distance:
    for (int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    //Apply Binary search:
    long double diff = 1e-6 ;
    while (high - low > diff) {
        long double mid = (low + high) / (2.0);
        int cnt = numberOfGasStationsRequired(mid, arr);
        if (cnt > k) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    return high;
}

//median of 2 sorted array; generating a symmetry (two equal sections l and r )
 double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1=nums1.size();
        int size2=nums2.size();

        if(size1>size2) return findMedianSortedArrays(nums2,nums1);

        int start=0,end=size1,mid1;
        int lefthand_side=(size1+size2+1)/2;
        while(start<=end){
            int l1=INT_MIN,l2=INT_MIN;
            int r1=INT_MAX,r2=INT_MAX;
            mid1=start+(end-start)/2;
            int mid2=lefthand_side-mid1;
            if(mid1<size1) r1=nums1[mid1];
            if(mid2<size2) r2=nums2[mid2];
            if(mid1-1>=0) l1=nums1[mid1-1];
            if(mid2-1>=0) l2=nums2[mid2-1];

            if(l1<=r2 && l2<=r1){
                if((size1+size2)%2==1) return max(l1,l2);
                return (double)(max(l1,l2)+min(r1,r2))/2.0;
            }else if(l1>r2){
                end=mid1-1;
            }else{
                start=mid1+1;
            }
        }
        return 0.0;
    }

//similar to median
int kthelement(int arr1[], int arr2[], int m, int n, int k) {
    if(m > n) {
        return kthelement(arr2, arr1, n, m, k); 
    }
        
    int low = max(0,k-m), high = min(k,n); //important change
        
    while(low <= high) {
        int cut1 = (low + high) >> 1; 
        int cut2 = k - cut1; 
        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1]; 
        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
        int r1 = cut1 == n ? INT_MAX : arr1[cut1]; 
        int r2 = cut2 == m ? INT_MAX : arr2[cut2]; 
            
        if(l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }
        else if (l1 > r2) {
            high = cut1 - 1;
        }
        else {
            low = cut1 + 1; 
        }
    }
    return 1; 
}    

int main(){
    return 0;
}    
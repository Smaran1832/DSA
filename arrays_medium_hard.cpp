#include<bits/stdc++.h>
using namespace std;

//spiral traversal
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left=0,right=matrix[0].size()-1;
        int top=0,bottom=matrix.size()-1;
        vector<int> arr;
        

        while(top<=bottom && left<=right){
            
            for(int i=left;i<=right;i++){
                arr.push_back(matrix[top][i]);
            }
            top++;

            
            for(int i=top;i<=bottom;i++){
                arr.push_back(matrix[i][right]);
            }
            right--;

            //important conditions to check again
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                arr.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                arr.push_back(matrix[i][left]);
                }
                left++;

            }
            
        }
        
        return arr;
    }

//Mathematical Calaculations
class PascalTriangleSolution {
public:

    //reduced combinations computations
    long long combination(int n,int r){
        long long res=1;
        for(int i=0;i<=r;i++){
            res*=(n-i);
            res/=(i+1);
        }
        return res;
    }

    vector<int> generateRow(int row){
        vector<int> ansRow;
        long long res=1;
        ansRow.push_back(res);
        for(int i=1;i<row;i++){
            res*=(row-i);
            res/=(i);
            ansRow.push_back(res);
        } 
        return ansRow;
    }
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> matrix;
        for(int i=1;i<=numRows;i++){
            matrix.push_back(generateRow(i));
        }
        return matrix;
    }
};

//3 SUM; triplets that add up to 0
vector<vector<int>> triplet(int n, vector<int> &arr) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        //remove duplicates:
        if (i != 0 && arr[i] == arr[i - 1]) continue;

        //moving 2 pointers:
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0) {
                j++;
            }
            else if (sum > 0) {
                k--;
            }
            else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                //skip the duplicates:
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }
    return ans;
}

//my code used while loops 
//4 Sum 
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    vector<vector<int>> ans;

    // sort the given array:
    sort(nums.begin(), nums.end());

    //calculating the quadruplets:
    for (int i = 0; i < n; i++) {
        // avoid the duplicates while moving i:
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            // avoid the duplicates while moving j:
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            // 2 pointers:
            int k = j + 1;
            int l = n - 1;
            while (k < l) {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target) {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++; l--;

                    //skip the duplicates:
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    while (k < l && nums[l] == nums[l + 1]) l--;
                }
                else if (sum < target) k++;
                else l--;
            }
        }
    }

    return ans;
}


int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int xr = 0;
    map<int, int> mpp; //declaring the map.
    mpp[xr]++; //setting the value of 0.
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        // prefix XOR till index i:
        xr = xr ^ a[i];

        //By formula: x = xr^k:
        int x = xr ^ k;
        //find the needed xor (reverse engineer)

        // add the occurrence of xr^k to our number of subbarrays since that is the new number of possible answers
        // to the count:
        cnt += mpp[x];
        //if exist will be added to the count 


        // Insert the prefix xor till index i
        // into the map:
        mpp[xr]++;
    }
    return cnt;
}

//merger intervals
vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        
        sort(intervals.begin(),intervals.end());

        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=ans.back()[1]){
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }else{
                ans.push_back(intervals[i]);
            }
            //since sorted it will either be added to existing or as a new interval
        }
        return ans;
    }

//missing and repeating numbers numerical approach
vector<int> findMissingRepeatingNumbers(vector<int> a) {
    long long n = a.size(); // size of the array

    // Find Sn and S2n:
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    // Calculate S and S2:
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }

    //S-Sn = X-Y:
    long long val1 = S - SN;

    // S2-S2n = X^2-Y^2  = (X-Y)(X+Y):
    long long val2 = S2 - S2N;

    //Find X+Y = (X^2-Y^2)/(X-Y):
    val2 = val2 / val1;

    //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
    // Here, X-Y = val1 and X+Y = val2:
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}

//XOR bitwise manipulation
vector<int> findMissingRepeatingNumbers(vector<int> a) {
    int n = a.size(); // size of the array

    int xr = 0;

    //Step 1: Find XOR of all elements:
    for (int i = 0; i < n; i++) {
        xr = xr ^ a[i];
        xr = xr ^ (i + 1);
    }

    //Step 2: Find the differentiating bit number:
    int number = (xr & ~(xr - 1));

    //Step 3: Group the numbers:
    int zero = 0;
    int one = 0;
    for (int i = 0; i < n; i++) {
        //part of 1 group:
        if ((a[i] & number) != 0) {
            one = one ^ a[i];
        }
        //part of 0 group:
        else {
            zero = zero ^ a[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        //part of 1 group:
        if ((i & number) != 0) {
            one = one ^ i;
        }
        //part of 0 group:
        else {
            zero = zero ^ i;
        }
    }

    // Last step: Identify the numbers: repeating , missing
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == zero) cnt++;
    }

    if (cnt == 2) return {zero, one};
    return {one, zero};
}

//count inversions (left eles > how many right eles)
int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //Modification 1: cnt variable to count the pairs:
    int cnt = 0;

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); //Modification 2
            //all remaining eles in left are greater than current right ele
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

    return cnt; // Modification 3
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}

int numberOfInversions(vector<int>&a, int n) {

    // Count the number of pairs:
    return mergeSort(a, 0, n - 1);
}


//count arr[i]>2*arr[i+1,.......] relationship
int merge(vector<int>& nums,int start,int mid,int end){
        int index1=start,index2=mid+1;
        int cnt=0;
        while(index1<=mid && index2<=end){
            if(nums[index1]>(2LL*nums[index2])){
                cnt+=mid-index1+1; //similar to previous problem
                index2++;
            }else{
                index1++;
            }
        }
        sort(nums.begin()+start,nums.begin()+end+1);
        return cnt;
    }

    int mergeSort(vector<int>& nums,int start,int end){
        if (start>=end) return 0;
        int mid = start+(end-start)/2;
        int cnt=0;
        cnt+=mergeSort(nums,start,mid);
        cnt+=mergeSort(nums,mid+1,end);
        return cnt+merge(nums,start,mid,end);
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }

//observation based solution even or odd negatives with "0" special cases; intuitively 
 long maxProduct(vector<int>& nums) {
        long preffix=nums[0];
        long suffix=nums.back();
        long maxProduct=max(preffix,suffix);
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(preffix==0) preffix=1;
            if(suffix==0) suffix=1; 
            preffix*=nums[i];
            suffix*=nums[n-i-1];
            maxProduct=max(maxProduct,max(preffix,suffix));
        }
        return maxProduct;
    }


// Helper function to rotate the matrix by 90 degrees
vector<vector<int>> rotate90(vector<vector<int>>& image) {
    int n = image.size();
    vector<vector<int>> rotated(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            rotated[j][n - i - 1] = image[i][j];
        }
    }
    return rotated;
}

// Helper function to rotate the matrix by 180 degrees
vector<vector<int>> rotate180(vector<vector<int>>& image) {
    int n = image.size();
    vector<vector<int>> rotated(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            rotated[n - i - 1][n - j - 1] = image[i][j];
        }
    }
    return rotated;
}

// Helper function to rotate the matrix by 270 degrees
vector<vector<int>> rotate270(vector<vector<int>>& image) {
    int n = image.size();
    vector<vector<int>> rotated(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            rotated[n - j - 1][i] = image[i][j];
        }
    }
    return rotated;
}

// Function to flip the matrix vertically
vector<vector<int>> verticalFlip(vector<vector<int>>& image) {
    int n = image.size();
    for (int i = 0; i < n / 2; ++i) {
        swap(image[i], image[n - i - 1]);
    }
    return image;
}

// Function to flip the matrix horizontally
vector<vector<int>> horizontalFlip(vector<vector<int>>& image) {
    int n = image.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            swap(image[i][j], image[i][n - j - 1]);
        }
    }
    return image;
}


int main(){
    return 0;
}
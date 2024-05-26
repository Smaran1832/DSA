#include<bits/stdc++.h>
using namespace std;

//simply print 
void rec1(int n){
    if(n<0) return;
    cout<<n<<" ";
    rec1(n-1);
}

//backtracing and then print
void rec2(int n){
    if(n<0) return;
    rec2(n-1);
    cout<<abs(n)<<" ";
}

//sum positive
int rec_sum(int n){
    if(n<2) return 1;
    return n+rec_sum(n-1);
}

//factorial
int factorial_rec(int n){
    if(n<2) return 1;
    return n*factorial_rec(n-1);
}

//vector isn't passed with ref like arrays
void rec_rev(vector<int> &arr,int i){
    if(i>(arr.size()/2)) return;
    swap(arr[i],arr[arr.size()-i-1]);
    rec_rev(arr,++i);
}

bool check_palin(vector<int> arr,int i){
    if(i>(arr.size()/2)) return true;
    if(arr[i]!=arr[arr.size()-i-1]) return false;
    return check_palin(arr,++i);
}

int fib_rec(int n){
    if (n<=1)   
        return n;
    return fib_rec(n-1) + fib_rec(n-2);
}

//powerset generation recursive pick/no-pick
vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;

        function<void(int)> explore = [&](int index) {
            if (index == nums.size()) {
                result.push_back(curr);
                return;
            }

            // Include the current element
            curr.push_back(nums[index]);
            explore(index + 1);
            curr.pop_back(); // Backtrack

            // Exclude the current element
            explore(index + 1);
        };

        explore(0);
        return result;
    }

//combination sum 
void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
      if (ind == arr.size()) {
        if (target == 0) {
          ans.push_back(ds);
        }
        return;
      }
      // pick up the element 
      if (arr[ind] <= target) {
        ds.push_back(arr[ind]);
        findCombination(ind, target - arr[ind], arr, ans, ds);
        ds.pop_back();
      }

      findCombination(ind + 1, target, arr, ans, ds);

    }

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> ans;
      vector<int>ds;
      findCombination(0, target, candidates, ans, ds);
      return ans;
    }


void subsetSumsHelper(int ind, vector < int > & arr, int n, vector < int > & ans, int sum) {
      if (ind == n) {
        ans.push_back(sum);
        return;
      }
      //element is picked
      subsetSumsHelper(ind + 1, arr, n, ans, sum + arr[ind]);
      //element is not picked
      subsetSumsHelper(ind + 1, arr, n, ans, sum);
    }
 vector < int > subsetSums(vector < int > arr, int n) {
    vector < int > ans;
    subsetSumsHelper(0, arr, n, ans, 0);
    sort(ans.begin(), ans.end());
    return ans;
  }

//Generate all permutations
 void genPermutation(int i, vector<int>& nums, vector<int>& current_ans, vector<vector<int>>& ans, unordered_map<int,bool> nums_utilized){
        if(i==nums.size()){
            ans.push_back(current_ans);
            return;
        }
        for(int j=0;j<nums.size();j++){
            if(!nums_utilized[j]){
                nums_utilized[j]=true;
                current_ans.push_back(nums[j]);
                genPermutation(i+1,nums,current_ans,ans,nums_utilized);
                current_ans.pop_back();
                nums_utilized[j]=false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> current_ans;
        vector<vector<int>> ans;
        unordered_map<int,bool> nums_utilized;
        genPermutation(0,nums,current_ans,ans,nums_utilized);
        return ans;
    }

//better solution no new space
 void genPermutation(int i, vector<int>& nums, vector<vector<int>>& ans){
        if(i==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            genPermutation(i+1,nums,ans);
            swap(nums[i],nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        genPermutation(0,nums,ans);
        return ans;
    }

int main(){
    int n;
    cin>>n;
    // rec2(n);
    // cout<<rec_sum(n);
    // cout<<factorial_rec(n);
    // vector<int> arr;
    // while(n--){
    //     int x;
    //     cin>>x;
    //     arr.push_back(x);
    // }

    // rec_rev(arr,0);
    // for(int i=0;i<arr.size();i++) cout<<arr[i]<<" ";

    // cout<<"Is Palindrome:"<<check_palin(arr,0);

    cout<<fib_rec(n);

    //gives error with the setup
    // for(auto it: arr){
    //     cout<<it<<" ";
    // }
        


    return 0;
}
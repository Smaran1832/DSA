#include<bits/stdc++.h>
using namespace std;

//max consecutive ones window 
int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0;
        int zeroes=0,res=0;

        while(r<nums.size()){
            if(nums[r]==0) zeroes++;
            while(zeroes>k){
                if(nums[l]==0){
                    zeroes--;
                }
                l++;
            }
            res=max(res,r-l+1);
            r++;
        }

        return res;
    }

//maximum window with only 2 types of items allowed to hold 
 int totalFruits(vector<int> &arr) {
        int l=0,r=0,res=0;
        unordered_map<int,int> mpp;
        while(r<arr.size()){
            mpp[arr[r]]++;
            if(mpp.size()>2){
                while(mpp.size()!=2){
                    if(mpp[arr[l]]==1){
                        mpp.erase(arr[l]);
                    }else{
                        mpp[arr[l]]--;
                    }
                    l++;
             }
            }
            res=max(res,r-l+1);
            r++;
        }
        
        return res;
        
    }    


int characterReplacement(string s, int k) {
        unordered_map<int,int> mpp;
        int l=0,r=0,res=0,max_char=0;

        // the window will always include the largest set of same characters in it,
        // we dont explicitly make note of the highest character since when it is 
        // at the highest quantity we will have already taken it into consideration
        // if not other character will take its position
        while(r<s.size()){
            mpp[s[r]-'A']++;
            max_char=max(max_char,mpp[s[r]-'A']);
            if((r-l+1)-max_char>k){
                mpp[s[l]-'A']--;
                l++;
            }
            res=max(res,r-l+1);
            r++;
        }

        return res;
    }

//Binary subarrays with sum k, optimized to constant space 
    int numSubarraysWithLessThanSum(vector<int>& nums, int goal){
        if(goal<0) return 0; //necessary edge case
        int l=0,r=0,res=0,cumsum=0;
        while(r<nums.size()){
            cumsum+=nums[r];
            while(cumsum>goal){
                    cumsum-=nums[l];
                    l++;
                }
            res+=(r-l+1);
            r++;
        }
        return res;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return numSubarraysWithLessThanSum(nums,goal)-numSubarraysWithLessThanSum(nums,goal-1);
    }

//nice subarrays (subbarrays with k odd integers)
//we will change the question into binary representation of the number being odd and solve for sum k
    int numSubarraysWithLessThanSum(vector<int>& nums, int goal){
        if(goal<0) return 0; //necessary edge case
        int l=0,r=0,res=0,cumsum=0;
        while(r<nums.size()){
            cumsum+=nums[r]%2;
            while(cumsum>goal){
                    cumsum-=nums[l]%2;
                    l++;
                }
            res+=(r-l+1);
            r++;
        }
        return res;
    }


    int numberOfSubarrays(vector<int>& nums, int k) {
        return numSubarraysWithLessThanSum(nums,k)-numSubarraysWithLessThanSum(nums,k-1);
    }


//number of all substrings that contain all 3 latters; Once all keys are encountered we can 
// start adding letters before it to generate larger valid arrays 
 int numberOfSubstrings(string s) {
        vector<int> mpp(3,-1);
        int counter=0;
        for(int i=0;i<s.size();i++){
            //update the latest index
            mpp[s[i]-'a']=i;
            if(mpp[0]!=-1 && mpp[1]!=-1 && mpp[2]!=-1){
                counter+=min({mpp[0],mpp[1],mpp[2]})+1;
            }
        }
        return counter;
    }   

//max points alternate end pickings; check all the possible answers
int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        if(n<k){
            return accumulate(cardPoints.begin(),cardPoints.end(),0);
        }

        int points=0,lsum=0,rsum=0;
        lsum=accumulate(cardPoints.begin(),cardPoints.begin()+k,0);
        points=lsum;
        for(int i=1;i<=k;i++){
            lsum-=cardPoints[k-i];
            rsum+=cardPoints[n-i];
            points=max(points,lsum+rsum);
        }

        return points;
    }    


//subarrays with exactly k elements 2N run neccessary due to the of checking elements 
//previous to l for the future cases or else same case as N^2
    int subbarrayLessThanK(vector<int>& nums, int k){
         unordered_map<int,int> mpp;
        int l=0,r=0,subbs=0;
        while(r<nums.size()){
            mpp[nums[r]]++;
            
            while(mpp.size()>k){
                if(mpp[nums[l]]==1){
                    mpp.erase(nums[l]);
                }else{
                    mpp[nums[l]]--;
                }
                
                l++;
            }

            subbs+=(r-l+1);
            r++;
        }

        return subbs;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return subbarrayLessThanK(nums,k)-subbarrayLessThanK(nums,k-1);
    }    

//longest subbarray with k unique elements; map to track k unique elements + sliding window logic
int longestKSubstr(string s, int k) {
         unordered_map<char,int> mpp;
         int l=0,r=0,max_len=-1;
         
         while(r<s.size()){
             mpp[s[r]]++;
                 while(mpp.size()>k){
                     if(mpp[s[l]]==1) mpp.erase(s[l]);
                     else mpp[s[l]]--;
                     l++;
                 }
             if(mpp.size()==k){
                 max_len=max(max_len,r-l+1);
             }
             r++;
         }
        
        return max_len; 
    }


//map to track characters of the necessary string with counter logic (only previously inserted elements may reach 0 within the map)
string minWindow(string s, string t) {
    unordered_map<char, int> mpp;

    // Edge case where t is longer than s
    if (t.size() > s.size()) {
        return "";
    }

    // Frequency map for characters in t
    for (char c : t) {
        mpp[c]++;
    }

    int required = mpp.size(); // Number of unique characters in t that need to be present in the window
    int l = 0, r = 0, formed = 0; // 'formed' is the number of unique characters in the current window that match the required frequency
    int min_len = INT_MAX, min_start = 0; // Track the minimum length and start index of the window

    while (r < s.size()) {
        char c = s[r];
        if (mpp.count(c)) {
            mpp[c]--;
            if (mpp[c] == 0) {
                formed++;
            }
        }

        // Try and contract the window till the point it ceases to be 'desirable'
        while (l <= r && formed == required) {
            c = s[l];
            // Save the smallest window until now
            if (r - l + 1 < min_len) {
                min_len = r - l + 1;
                min_start = l;
            }

            // The character at the position pointed by `l` is going to be removed
            if (mpp.count(c)) {
                if (mpp[c] == 0) {
                    formed--;
                }
                mpp[c]++;
            }
            l++;
        }

        r++;
    }

    return min_len == INT_MAX ? "" : s.substr(min_start, min_len);
}



//minimum sliding window subsequence
//we use 3 pointers 2 on the larger string 1 on the smaller; if the 3 pointer manages to go over the size of 
//the second string that means we have encountered all the characters we wanted in the correct sequence. we 
//will traverse back form the current point at string 1 to find the minimum possible string with the k third pointer
//repeat the process untill string 1 is completely finished.
   string minWindow(string& str1, string& str2) {
    int i=0,j=0,k=0,res=INT_MAX;
    int s1=str1.size(),s2=str2.size();
    string ans="";
    
    while(j<s1 && k<s2){
        if(str1[j]==str2[k]){
            k++;
        }
        
        if(k==s2){
            i=j;
            k=s2-1;
            while(i>=0 && k>=0){
                if(str1[i]==str2[k]){
                    k--;
                }
                i--;
            }
            i++;
            if(res>j-i+1){
                res=j-i+1;
                ans=str1.substr(i,res);
            }
            k=0;
            j=i+1;
        }
        
        j++;
    }
    
    return ans;
    }    
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
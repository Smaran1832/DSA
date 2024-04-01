#include<bits/stdc++.h>
using namespace std;

string frequencySort(string s) {
        unordered_map<char,int> mpp;
        for(char c:s){
            mpp[c]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto x:mpp){
            pq.push({x.second,x.first});
        }
        string ans="";
        while(!pq.empty()){
            int cnt=pq.top().first;
            char x=pq.top().second;
            while(cnt>0){
                ans+=x;
                cnt--;
            }
            pq.pop();
        }
        return ans;
    }

int romanToInt(string s) {
        unordered_map<char, int> m{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
     
        int ans = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(m[s[i]] < m[s[i+1]]){
                ans -= m[s[i]];
            }
            else{
                ans += m[s[i]];
            }
        }
        return ans;
    }

int myAtoi(string s) {
        int i = 0, sign = 1;
    long result = 0;  // Use long to handle overflow cases
    
    // 1. Skip whitespace
    while (i < s.length() && s[i] == ' ') {
        i++;
    }
    
    // 2. Check the sign
    if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
    
    // 3. Build the number
    while (i < s.length() && isdigit(s[i])) {
        result = result * 10 + (s[i] - '0');
        i++;
        
        // 5. Handle overflow
        if (result * sign >= INT_MAX) return INT_MAX;
        if (result * sign <= INT_MIN) return INT_MIN;
    }
    
    // 4. Apply the sign
    result *= sign;
    
    return static_cast<int>(result);
    }    

string longestPalindrome(string s) {
        int end=s.size()-1;
        string res(1,s[0]);

        for(int i=1;i<=end;i++){
            //odd cases of palindrome >= 3
            int left=i-1;
            int right=i+1;

            while(left>=0 && right<=end && s[left]==s[right]){
                if(res.size()<=right+1-left){
                    res=s.substr(left,right+1-left);
                }
                left--;
                right++;
            }

            //even cases of palindrome >=2
            left=i-1;
            right=i;
            while(left>=0 && right<=end && s[left]==s[right] ){
                if(res.size()<=right+1-left){
                    res=s.substr(left,right+1-left);
                }
                left--;
                right++;
            }

        }

        return res;
    }

    int beautySum(string s) {
        long sum=0;
        for(int i=0;i<s.size();i++){
            int freq[26]={};
            for(int j=i;j<s.size();j++){
                freq[s[j]-'a']++;
                 int maxi=get_max_element(freq);
                 int mini=get_min_element(freq);
                 sum+=(maxi-mini);
            }
           
        }
        return sum;
    }

    int get_max_element(int freq[]){
        int num=INT_MIN;
        for(int i=0;i<26;i++){
            num=max(num,freq[i]);
        }
        return num;
    }

    int get_min_element(int freq[]){
        int num=INT_MAX;
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                num=min(num,freq[i]);
            }
        }
        return num==INT_MAX? 0:num;
    }



string reverseWords(string s) {
        int n = s.size();
        // Reverse the entire string
        reverse(s.begin(),s.end());

        // Reverse each word in the string and remove extra spaces
        int i = 0, j = 0;
        while (j < n) {
            while (j < n && s[j] == ' ') j++; // Skip leading spaces
            if (j < n && i > 0) s[i++] = ' '; // Add space if not first word
            int start = i;
            while (j < n && s[j] != ' ') s[i++] = s[j++]; // Copy word
            reverse(s.begin()+start,s.begin()+i); // Reverse word
        }
        s.resize(i); // Resize string to remove trailing spaces
        return s;
    }    

int main(){
    string x;
    cin>>x;
    reverseWords(x);
    return 0;
}        
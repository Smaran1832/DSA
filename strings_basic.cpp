#include<bits/stdc++.h>
using namespace std;


int maxDepth(string s) {
        int cnt=0,maxi=0;
        for(char c:s){
            if(c=='(') cnt++;
            else if(c==')') cnt--;
            maxi=max(maxi,cnt);
        }
        return maxi;
    }

string removeOuterParentheses(string s) {
        string res;
        int opened = 0;
        for (char c : s) {
            if (c == '(' && opened++ > 0) res += c;
            if (c == ')' && opened-- > 1) res += c;
        }
        return res;
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

string largestOddNumber(string num) {
       for(int i=num.length()-1;i>=0;i--){
           if((num[i]-'0')%2!=0){
               num.resize(i+1);
               return num;
           }   
       } 
       return "";
    }

string longestCommonPrefix(vector<string>& strs) {
       if (strs.empty()) {
            return "";
        }

        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            while (j < prefix.length() && j < strs[i].length() && prefix[j] == strs[i][j]) {
                j++;
            }

            prefix = prefix.substr(0, j);

            if (prefix.empty()) {
                break; // No need to continue if the prefix is already empty
            }
        }

        return prefix;
    }

bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mpp1;
        unordered_map<char,char> mpp2;
        for(int i=0;i<s.size();i++){
            if(mpp1.find(s[i])==mpp1.end() && mpp2.find(t[i])==mpp2.end()){
                mpp1[s[i]]=t[i];
                mpp2[t[i]]=s[i];
            }else{
                if(mpp1[s[i]]!=t[i] || mpp2[t[i]]!=s[i]) return false;
            }
        }
        return true;
    }

 bool rotateString(string s, string goal) {
      if (s.length() != goal.length()) {
        return false;
    }
    return (s + s).find(goal) != string::npos;
}

bool isAnagram(string s, string t) {
if (s.length() != t.length()) {
        return false;
    }

    int counts[26] = {0}; // Assuming the strings contain only lowercase alphabets

    for (int i = 0; i < s.length(); ++i) {
        counts[s[i] - 'a']++; // Increment count for this character in s
        counts[t[i] - 'a']--; // Decrement count for this character in t
    }

    for (int count : counts) {
        if (count != 0) {
            return false; // If counts don't match, they are not anagrams
        }
    }

    return true;
    }

int main(){
    string x;
    cin>>x;
    removeOuterParentheses(x);
    return 0;
}    


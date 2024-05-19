#include<bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
        long num=0;
        int i=0;
        bool neg=0;

        while(s[i]==' ') i++;
        
        if(i<s.length() && s[i]=='-'){
            neg=1;
            i++;
        }else if(i<s.length() && s[i]=='+'){
            i++;
        }


        while(i<s.length()){
            if(s[i]>='0' && s[i]<='9'){
                num=(num*10)+(s[i]-'0');
                if(neg && -num<=INT_MIN) return INT_MIN;
                else if(!neg && num>=INT_MAX) return INT_MAX;
            }else{
                break;
            }
            i++;
        }
        num=(neg)?-num:num;
        return num;
    }


//binary Exponentiations
double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;
        if (nn < 0) nn = -1 * nn;
        while (nn) {
            if (nn % 2) {
                 ans = ans * x;
                 nn = nn - 1;
            } else {
                 x = x * x;
                 nn = nn / 2;
             }
        }
        if (n < 0) ans = (double)(1.0) / (double)(ans);
        return ans;
   }

//count good numbers
const int MOD = 1000000007;

    // Function to perform modular exponentiation   
    long long modExpo(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod; //reduces the number of exponential calculation by eliminating repeating calculations
        exp /= 2;
    }
    return result;
}
    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;  // Number of positions at even indices
        long long oddCount = n / 2;         // Number of positions at odd indices
        long long evenChoices = modExpo(5, evenCount, MOD); // 5 choices for even indices
        long long oddChoices = modExpo(4, oddCount, MOD);   // 4 choices for odd indices
        return (evenChoices * oddChoices) % MOD;            // Return the product modulo 10^9+7
    }


 //generate valid paranthesis recursion problem
 void string_gen(vector<string> &ans,string &current,int open,int close,int max){
        if(current.length()==max*2){
            ans.push_back(current);
            return;
        }

        if(open<max){
            current.push_back('(');
            string_gen(ans,current,open+1,close,max);
            current.pop_back();
        }

        if (close < open) {
            current.push_back(')');
            string_gen(ans, current, open, close + 1, max);
            current.pop_back();
        }
    }

    //call the recursive function to generate the valid paranthesis
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp="";
        string_gen(ans,temp,0,0,n);
        return ans;
        
    }

    

int main(){
    int n;
    cin>>n;
        return 0;
}
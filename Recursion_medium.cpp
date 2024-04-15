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


int main(){
    int n;
    cin>>n;
        return 0;
}
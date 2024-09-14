#include <bits/stdc++.h>
using namespace std;

pair<int, int> get_swap(int a, int b){
        a=a^b;
        b=a^b;
        a=a^b;
        return {a,b};
    }

string oddEven(int N){ //faster odd even
        if(N&1) return "odd";
        else return "even";
    }    

void bitManipulation(int num, int i) {
        i--;//0 based indexing(varies)  get ith, set ith, clear ith 
        cout<<((num & 1<<i)!=0)<<" "<<(num | 1<<i)<<" "<<(num & (~(1<<i)));
    }

//toggle ith bit XOR    

bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        else return (n&n-1)==0;
    }

int setRighmostUnsetBit(int N)
    {
        if (N == 0) return 1;  // Special case for 0, as it has no set bits.
        return N | (N + 1 - (N & (N + 1)));
    }    

int UnsetRighmostSetBit(int N)
    {
        if (N == 0) return 1;  // Special case for 0, as it has no set bits.
        return (N & (N - 1)));
    }  

int countSetBits(int n){
        int counter=0;
        while(n!=0){
            n=(n&(n-1));
            counter++;
        }
        
        return counter;
    }  

 int minBitFlips(int start, int goal) {
        int x=start^goal;
        int counter=0;
        while(x!=0){
            if(x & 1 == 1){
                counter++;
            }
            x=x>>1;
        }
        return counter;
    }      

vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        int subsets=pow(2,n);
        for(int i=0;i<subsets;i++){
            vector<int> current_ans;
            for(int j=0;j<n;j++){
                if((i&(1<<j))!=0){
                    current_ans.push_back(nums[j]);
                }
            }
            ans.push_back(current_ans);
        }
        return ans;
    }  

//Xor Range
    int XOR_n(int n){
        if(n%4==1) return 1;
        else if(n%4==2) return n+1;
        else if(n%4==3) return 0;
        else return n;
        
    }
    
    int findXOR(int l, int r) {
        return XOR_n(l-1)^XOR_n(r);
    }

//2 numbers once rest twice; find differentiating bit then simple XOR
 vector<int> singleNumber(vector<int>& nums) {
    long XOR=0; //for the overflow condition in 2^-31
    for(int i=0;i<nums.size();i++){
        XOR^=nums[i];
    }
    long rightmost=(XOR&~(XOR-1))&XOR;
    int gp1=0;
    int gp2=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]&rightmost){
            gp1=gp1^nums[i];
        }else{
            gp2=gp2^nums[i];
        }
    }
    return {gp1,gp2};
    }    

//divide with no / operator
  int divide(int dividend, int divisor) {
    // Handle overflow condition mentioned in the problem
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

    // Determine the sign of the result
    int sign = (dividend >= 0) == (divisor >= 0) ? 1 : -1;

    // Work with absolute values to avoid overflow
    long long ldividend = abs((long long)dividend);
    long long ldivisor = abs((long long)divisor);
    long long result = 0;

    // Subtract powers of two of the divisor from dividend
    while (ldividend >= ldivisor) {
        long long temp = ldivisor, multiple = 1;
        while (ldividend >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        ldividend -= temp;
        result += multiple;
    }

    // Apply the sign to the result
    return sign * result;
    }   
//all numbers thrice except one (a little unituitive)
 int singleNumber(vector<int>& nums) {
        int ones=0;
        int twos=0;
        for(int i=0;i<nums.size();i++){
            //First occurance goes adds in ones
            //Second occurance deletes form ones and adds in twos
            //Third occurance deletes from twos(irrelevalnt)
            ones=(ones^nums[i])&~twos;
            twos=(twos^nums[i])&~ones;
        }
        return ones;
 }
int main(){
    return 0;
}    
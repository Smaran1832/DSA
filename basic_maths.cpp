#include<bits/stdc++.h>
using namespace std;

 void print_divisors(int n) {
        vector<int> ans;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                ans.push_back(i);
                if(i!=n/i) ans.push_back(n/i);
            }
        }
        if(!ans.empty())
            sort(ans.begin(),ans.end());
        else
            ans.push_back(1);
        for(int x:ans){
            cout<<x<<" ";
        }
    }

vector<long long> lcmAndGcd(long long A , long long B) {
        int tempA=A;
        int tempB=B;
        
        long long GCD;
        long long LCM;
        
        //euclidean formula for GCD
        while(tempA>0 && tempB>0){
            if(tempA>tempB)
                tempA=tempA%tempB;
            else
                tempB=tempB%tempA;
        }
        
        if(tempA==0) GCD=tempB;
        else GCD=tempA;
        
        LCM=(A/GCD)*B; //prevent overflow
        
        return {LCM,GCD};
        
    }

//divisor sum TLE
long long divisor_sum(int N){
        long long sum=0;
        for(int i=1;i*i<=N;i++){
            if(N%i==0){
                if(i!=N/i) sum+=i+(N/i);
                else sum+=i;
            } 
            
        }
        
        return sum;
    }
    
    long long sumOfDivisors(int N){
        long long sum=0;
        for(int i=2;i<=N;i++){
            sum+=divisor_sum(i);
        }
        return sum+1;
    }  

//mathematic breakdown of the function
long long sumOfDivisors(int N){
    long long totalSum = 0;
    for (int i = 1; i <= N; ++i) {
        totalSum += i*(N/i);
    }
    return totalSum;
    }      

//if only need to count digits Log10(n)+1 can also be done
int evenlyDivides(int N){
        int n=N;
        int count=0;
        while(n>0){
            int temp=n%10; //digit can be 0 so needs appropriate check
            if(temp!=0 && N%(n%10)==0) 
                count++;
            n/=10;
        }
        return count;
    }

int reverse(int x) {
        int reversed = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            
            // Check for overflow before updating the reversed number
            if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && pop > 7)) return 0;
            if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && pop < -8)) return 0; //c++ and java allow for negative modulo python will change things
            
            reversed = reversed * 10 + pop;
        }
        return reversed;
    }    

//prime factors till n
vector<int>AllPrimeFactors(int N) {
        vector<int> ans;
        if(N<2) return ans;
        for(int i=2;i<=N;i++){
            // cout<<N<<" "<<i<<endl;
            if(N%i==0){
                ans.push_back(i);
                while(N%i==0){
                    N/=i;
                }
            }
        }
        if(ans.empty()){
            ans.push_back(N);
        }
        return ans;
	}

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


//sieve of erathosthenes //note bool summation takes time better to just have int 
//count between range can be solved via cumulative sum
int countPrimes(int n) {
        if(n==0 || n==1) return 0;
        // vector<bool> primes(n+1,true); upto n
        vector<int> primes(n,1); // strictly less than n
        int counter=0;
        primes[0]=0;
        primes[1]=0;
        for(int i=2;i*i<n;i++){ //i*i since that is the starting condition of the inner loop the further non primes should have already been marked by then
            if(primes[i]){
                for(int j=i*i;j<n;j+=i){ //i*i since earlier factor wuold have already been taken care of
                    primes[j]=0;
                }
            }
        }

        return accumulate(primes.begin(),primes.end(),0);

    }

//query based probable scalable solution solution
class Solution {
    vector<int> primes;
  public:
    
    Solution(): primes(200001) {
        for (int i = 2; i < 200001; i++) {
            primes[i] = i;
        }
    }
    
    void sieve() {
        for(int i=2;i*i<200001;i++){
            if(primes[i]==i){
                for(int j=i*i;j<200001;j+i){
                    primes[j]=i;
                }
            }
        }
    }

    vector<int> findPrimeFactors(int N) {
    
        primes[0]=primes[1]=0;
        
        vector<int> ans;
        while(N!=1){
            int factor=primes[N];
            N/=factor;
            ans.push_back(factor);
        }
        
        return ans;

        //simpler solution for single query not scalable (altough this can be repeated itself)
        // vector<int> ans;
        // if(N<2) return ans;
        // for(int i=2;i<=N;i++){
        //     // cout<<N<<" "<<i<<endl;
        //     if(N%i==0){
        //         while(N%i==0){
        //             N/=i;
        //             ans.push_back(i);
        //         }
        //     }
        // }
        // if(ans.empty()){
        //     ans.push_back(N);
        // }
        // return ans;
    }
};        

int main(){
    int x;
    cin>>x;
    cout<<"Hello"<<x;
    return 0;
}
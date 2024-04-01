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

//vector isn't passed with ref
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
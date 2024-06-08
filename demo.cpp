#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    while(n--){
        int x;
        cin>>x;
        arr.push_back(x);
    }
   cout << "Before sort: " << "\n";
   for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
    }
   cout << "\n";
}

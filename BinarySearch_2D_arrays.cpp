#include <bits/stdc++.h>
using namespace std;


//dont remove helper function for the below function
int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int cnt_max = 0;
    int index = -1;

    //traverse the rows:
    for (int i = 0; i < n; i++) {
        // get the number of 1's:
        int cnt_ones = m - lowerBound(matrix[i], m, 1);
        if (cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}

//2D matrix binary search  (2d-mapping 1 to n*n) Unlike assumption each number has unique number attached
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start=0,r=matrix.size(),c=matrix[0].size();
        int end=(r*c)-1,mid;
        while(start<=end){
            mid=start+(end-start)/2;
            int row=mid/c;
            int col=mid%c;
            if(matrix[row][col]==target){
                return true;
            }else if(matrix[row][col]<target){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return false;
    }


//find peak 2D array
int max_row(vector<vector<int>>& mat,int col){
        int row=0;
        for(int i=1;i<mat.size();i++){
            if(mat[i][col]>mat[row][col]){
                row=i;
            }
        }
        return row;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int cols=mat[0].size()-1,row;
        int start=0,end=cols,mid;
        while(start<=end){
            mid=start+(end-start)/2;
            row=max_row(mat,mid);
            int left= (mid-1>=0) ? mat[row][mid-1] : -1;
            int right= (mid+1)<=cols ? mat[row][mid+1]:-1;
            if(mat[row][mid]>left && mat[row][mid]>right){
                    return {row,mid};
            }else if(mat[row][mid]<left){
                    end=mid-1;
            }else{
                    start=mid+1;
            }
            
        }
        return {0,0};
    }


//median 2D matrix
int countSmallerThanMid(vector<int> &row, int mid)
{
  int l = 0, h = row.size() - 1;
  while (l <= h)
  {
    int md = (l + h) >> 1;
    if (row[md] <= mid)
    {
      l = md + 1;
    }
    else
    {
      h = md - 1;
    }
  }
  return l;
}
int findMedian(vector<vector<int>> &A)
{
  int low = 1;
  int high = 1e9;
  int n = A.size();
  int m = A[0].size();
  while (low <= high)
  {
    int mid = (low + high) >> 1;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      cnt += countSmallerThanMid(A[i], mid);
    }
    if (cnt <= (n * m) / 2)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return low;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;
    cout << "The row with maximum no. of 1's is: " <<
         rowWithMax1s(matrix, n, m) << '\n';
}
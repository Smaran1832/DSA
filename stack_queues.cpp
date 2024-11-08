

//------------------------------------------------//stack with the help of arrays
class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};


void MyStack :: push(int x)
{
    arr[++top]=x;
}

//Function to remove an item from top of the stack.
int MyStack :: pop()
{
    if(top!=-1)   
    return arr[top--];
    else return -1;
}

//----------------------------------------------//queue with the help of arrays
class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};


//Function to push an element x in a queue.
void MyQueue :: push(int x)
{
    arr[rear++]=x;

}

//Function to pop an element from queue and return that element.
int MyQueue :: pop()
{
     if(front!=rear) return arr[front++];
     else return -1;
}


//-----------------------------------------------stack using queues
// Using 2 queues
class MyStack {
public:
    queue<int> que1;
    queue<int> que2;

    MyStack() {}
    
    void push(int x) {
        que2.push(x);

        while(!que1.empty()){
            que2.push(que1.front());
            que1.pop();
        }

        swap(que1, que2);
    }
    
    int pop() {
        int result = que1.front();
        que1.pop();

        return result;
    }
    
    int top() {
        return que1.front();
    }
    
    bool empty() {
        return que1.empty();
    }
};

// Follow-up : Using 1 queue
class MyStack {
public:
    queue<int> que;

    MyStack() {
        
    }
    
    void push(int x) {
        que.push(x);
        int n = que.size(); 

        for(int i=0; i<n-1; i++){
            que.push(que.front());
            que.pop();
        }
    }
    
    int pop() {
        int result = que.front();
        que.pop();

        return result;
    }
    
    int top() {
        return que.front();
    }
    
    bool empty() {
        return que.empty();
    }

};

//next greater element to right no modulus
 vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int,int> mpp;
       stack<int> st;
       for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }
            if(st.empty()) mpp[nums2[i]]=-1;
            else mpp[nums2[i]]=st.top();
            st.push(nums2[i]);
        }

        vector<int> ans;
        for(int x:nums1){
            ans.push_back(mpp[x]);
        }
       
       return ans;
    }

//next greater element modulo
vector<int> nextGreaterElements(vector<int>& nums) {
      int n = nums.size();
      vector < int > nge(n, -1);
      stack < int > st;
      for (int i = 2 * n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i % n]) {
          st.pop();
        }

        if (i < n) {
          if (!st.empty()) nge[i] = st.top();
        }
        st.push(nums[i % n]);
      }
      return nge;
    }    

// Function to convert an infix expression to a postfix expression.
     int precedence(char op) {
        if(op == '^') return 3;
        else if(op == '*' || op == '/') return 2;
        else if(op == '+' || op == '-') return 1;
        return -1;  // For '('
    }

    string infixToPostfix(string s) {
        string ans;
        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];

            // If the character is an operand, add it to output.
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
                ans += c;
            }
            // If the character is '(', push it to stack.
            else if(c == '(') {
                st.push(c);
            }
            // If the character is ')', pop and output from the stack
            // until an '(' is encountered.
            else if(c == ')') {
                while(!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop();  // pop '('
            }
            else {  // operator encountered
                while(!st.empty() && precedence(c) <= precedence(st.top())) {
                    ans += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        // Pop all the operators from the stack
        while(!st.empty()) {
            if(st.top() != '(') {
                ans += st.top();
            }
            st.pop();
        }

        return ans;
    }

//water trapped between walls
    int trap(vector<int>& height) {
        int leftmax=0;
        int rightmax=0;
        int water=0;
        int left=0;
        int right=height.size()-1;
        while(left<=right){
            if(leftmax<=rightmax){
                if(height[left]<=leftmax){
                    water+=leftmax-height[left++];
                }else{
                    leftmax=height[left++];
                }
            }else{
                if(height[right]<=rightmax){
                    water+=rightmax-height[right--];
                }else{
                    rightmax=height[right--];
                }
            }
            
        }
        return water;
    }    

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> st;
    for (int i = 0; i < asteroids.size(); ++i) {
        bool destroyed = false;
        while (!st.empty() && st.back() > 0 && asteroids[i] < 0) {
            if (abs(st.back()) == abs(asteroids[i])) {
                st.pop_back();
                destroyed = true;
                break;
            } else if (abs(st.back()) > abs(asteroids[i])) {
                destroyed = true;
                break;
            } else {
                st.pop_back();
            }
        }
        if (!destroyed) {
            st.push_back(asteroids[i]);
        }
    }
    return st;
}

//sum of minimum element in all subarrays;
//(prevoius smaller and next smaller index) we count how many times the current index will contribute 
//similar problem is sum of range diff in subarrays; we will do "sum of max"-"sum of min"
    int sumSubarrayMins(vector<int>& arr) { 
        int n = arr.size();
    const int MOD = 1e9 + 7;

    std::vector<int> left(n), right(n);
    std::stack<int> s;

    // Find number of previous less element for each element
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && arr[s.top()] > arr[i]) s.pop();
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    // Clear the stack for the next use
    while (!s.empty()) s.pop();

    // Find nyumber of next less element for each element
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
        right[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    // Calculate the result using the indices from left and right
    long long result = 0;
    for (int i = 0; i < n; ++i) {
        long long l = i - left[i];
        long long r = right[i] - i;
        result = (result + arr[i] * l * r) % MOD;
    }

    return result;
    }


//remove k digits to result in smallest
// stack should be in monotonic decreasing order else pop 
    string removeKdigits(string num, int k) {
    string result;  // Use a string to build the result
    for (char digit : num) {
        while (!result.empty() && result.back() > digit && k > 0) {
            result.pop_back();  // Remove the last character
            k--;
        }
        if (!result.empty() || digit != '0') {  // Avoid leading zeros
            result.push_back(digit);
        }
    }

    // Remove the remaining digits from the end if k > 0
    while (k > 0 && !result.empty()) {
        result.pop_back();
        k--;
    }

    return result.empty() ? "0" : result;  // Check for empty result to return "0"
    }

//Largest histogram plus maximal rectangle (parent problem) 
int maximum_area(vector<int> histo){
      stack < int > st;
      int maxA = 0;
      int n = histo.size();
      //stack made will monotonically increasing allowing us to find the right and left smaller by logic/observation 
      //since the stack holds monotonic increasing index values the second stack holds left smaller while the size of array 
      //will serve as a right smaller index (since monotonic increasing means if greater it would have entered the stack,
      // if smaller we woudn't have the current element with us; it would have already been removed to maintain monotonicity)
      for(int i=0; i<=n; i++) {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
          int height = histo[st.top()]; //current min height
          st.pop(); //current element 
          int width;
          if (st.empty())
            width = i;
          else
            width = i - st.top() - 1;
          maxA = max(maxA, width * height);
        }
        st.push(i); //push current element
      }
      return maxA;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();\
        int maxArea=0;
        vector<int> current_recs(c,0);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]=='0'){
                    current_recs[j]=0;
                }else{
                    current_recs[j]++;
                }
            }
            maxArea=max(maxArea,maximum_area(current_recs));
        }

        return maxArea;
    }

 vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(!dq.empty() && dq.front()<=i-k) dq.pop_front(); //renove the earlier index values
            
            while(!dq.empty() && nums[dq.back()]<nums[i]) dq.pop_back(); //maintaining a monotonic decreasing stack since latest greatest element will serve as max for current and most probably future arrays

            dq.push_back(i); //insert index at decreasing rank 
            
            if(i>=k-1) ans.push_back(nums[dq.front()]);


        }
        return ans;
        
    }


//span of days the stock price was lower or equal consequetively
class StockSpanner {
private:

    stack<pair<int,int>> st;

public:
    StockSpanner() {
    }
    
    int next(int price) {
        int counter=1;
        while(!st.empty() && price>=st.top().first){
            counter+=st.top().second;
            st.pop();
        }
        st.push({price,counter});
        return counter;
    }
};

//Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n) 
    {
        stack<int> st;
        //push all members into the stack
        for(int i=0;i<n;i++){
            st.push(i);
        }
        
        while(st.size()!=1){
            
            //retrieve the members
            int mem1=st.top();
            st.pop();
            int mem2=st.top();
            st.pop();
            
            //check who knows the others (celeb does not know anyone)
            if(M[mem1][mem2]==1){
                st.push(mem2); //cannot be celeb
            }else{
                st.push(mem1); //can be celeb
            }
            
        }
        
        int candidate=st.top();
        bool celeb=1;
        
        for(int i=0;i<n;i++){
            if(candidate!=i && (M[candidate][i]==1 || M[i][candidate]!=1)){
                celeb=0;
                break;
            } 
        }
        
        return (celeb)?candidate:-1;
        
        
    }

    int main(){
        return 0;
    }


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

//minimum element in subarrays
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

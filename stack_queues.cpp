

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

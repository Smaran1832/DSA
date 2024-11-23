#include<bits/stdc++.h>
using namespace std;

// Structure definition for
// a node in a binary tree
struct Node {
    // Defining the value of
    // the node (integer data)
    int data;        
     // Reference pointer to
     // the left child node
    Node* left;      
    // Reference pointer to
    // the right child node
    Node* right;      

    // Method to initialize
    // the node with a value
    Node(int val) {
        // Set the value of the
        // node to the passed integer
        data = val;   
        // Initialize left and 
        //r ight pointers as NULL
        left = right = NULL;  
    }
};


// Function to perform preorder traversal
// of the tree and store values in 'arr'
void preorder(Node* root, vector<int> &arr){
    // If the current node is NULL
    // (base case for recursion), return
    if(root == nullptr){
        return;
    }
    // Push the current node's
    // value into the vector
    arr.push_back(root->data);
    // Recursively traverse
    // the left subtree
    preorder(root->left, arr);
    // Recursively traverse 
    // the right subtree
    preorder(root->right, arr);
}

// Function to initiate preorder traversal
// and return the resulting vector
vector<int> preOrder(Node* root){
    // Create an empty vector to
    // store preorder traversal values
    vector<int> arr;
    // Call the preorder traversal function
    preorder(root, arr);
    // Return the resulting vector
    // containing preorder traversal values
    return arr;
}


// Function to perform inorder traversal
// of the tree and store values in 'arr'
void inorder(Node* root, vector<int> &arr){
    // If the current node is NULL
    // (base case for recursion), return
    if(root == nullptr){
        return;
    }
    // Recursively traverse the left subtree
    inorder(root->left, arr);
    // Push the current node's
    // value into the vector
    arr.push_back(root->data);
    // Recursively traverse 
    // the right subtree
    inorder(root->right, arr);
}

// Function to initiate inorder traversal
// and return the resulting vector
vector<int> inOrder(Node* root){
    // Create an empty vector to
    // store inorder traversal values
    vector<int> arr;
    // Call the inorder traversal function
    inorder(root, arr);
    // Return the resulting vector
    // containing inorder traversal values
    return arr;
}

// Function to perform postorder
// traversal recursively
void postorder(Node* root, vector<int>& arr){
    // Base case: if root is null, return
    if(root==NULL){
        return;
    }
    // Traverse left subtree
    postorder(root->left, arr);
    // Traverse right subtree
    postorder(root->right, arr);
    // Visit the node
    // (append node's data to the array)
    arr.push_back(root->data);
}

// Function to get the postorder
// traversal of a binary tree
vector<int> postOrder(Node* root){
    // Create a vector to
    // store the traversal result
    vector<int> arr;
    // Perform postorder traversal
    // starting from the root
    postorder(root, arr);
    // Return the postorder
    // traversal result
    return arr;
}

vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        
        if(root==nullptr) return ans;
        queue<Node*> que;
        que.push(root);
        
        while(!que.empty()){
            int n=que.size();
            vector<int> curr_level;
            for(int i=0;i<n;i++){
                Node* temp=que.front();
                que.pop();
                curr_level.push_back(temp->data);
                if(temp->left!=nullptr) que.push(temp->left);
                if(temp->right!=nullptr)que.push(temp->right);
            }
            ans.push_back(curr_level);
        }

        return ans;
    }


// Function to get the Preorder,
// Inorder and Postorder traversal
// Of Binary Tree in One traversal
vector<vector<int>> preInPostTraversal(Node* root) {
    // Vectors to store traversals
    vector<int> pre, in, post;

    // If the tree is empty,
    // return empty traversals
    if (root == NULL) {
        return {};
    }

    // Stack to maintain nodes
    // and their traversal state
    stack<pair<Node*, int>> st;

    // Start with the root node
    // and state 1 (preorder)
    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        // this is part of pre
        if (it.second == 1) {
            // Store the node's data
            // in the preorder traversal
            pre.push_back(it.first->data);
            // Move to state 2
            // (inorder) for this node
            it.second = 2;
            // Push the updated state
            // back onto the stack
            st.push(it); 

            // Push left child onto
            // the stack for processing
            if (it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        }

        // this is a part of in
        else if (it.second == 2) {
            // Store the node's data
            // in the inorder traversal
            in.push_back(it.first->data);
            // Move to state 3
            // (postorder) for this node
            it.second = 3;
            // Push the updated state
            // back onto the stack
            st.push(it); 

            // Push right child onto
            // the stack for processing
            if (it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        }

        // this is part of post
        else {
            // Store the node's data
            // in the postorder traversal
            post.push_back(it.first->data);
        }
    }

    // Returning the traversals
    vector<vector<int>> result;
    result.push_back(pre);
    result.push_back(in);
    result.push_back(post);
    return result;
}    

//Height of the tree
void height_dfs(Node* root,int &max_D,int curr_height){
        if(root!=nullptr){
            max_D=max(max_D,curr_height);
        }else return;
        if(root->left!=nullptr) height_dfs(root->left,max_D,curr_height+1);
        if(root->right!=nullptr) height_dfs(root->right,max_D,curr_height+1);
    }

    int maxDepth(Node* root) {
        int max_D=0;
        height_dfs(root,max_D,1);
        return max_D;
    }

//balanced or not
int balanced_dfs(Node* temp){
        if(temp==nullptr)
            return 0;
        else{
            int left=balanced_dfs(temp->left);
            if (left==-1) return -1;
            int right=balanced_dfs(temp->right);
            if (right==-1) return -1;

            return (abs(right-left)>1)? -1 : 1+max(left,right);
        }
    }

    bool isBalanced(Node* root) {
        if(balanced_dfs(root)==-1)
            return false;
        else return true;
    }


//diameter (longest semicircle)
int diameter_dfs(Node* root,int &diameter){
        if (root==nullptr){
            return 0;
        }
        else{
            int right=diameter_dfs(root->right,diameter);
            int left=diameter_dfs(root->left,diameter);
            diameter=max(diameter,left+right);
            return 1+max(left,right);
        }


    }

    int diameterOfBinaryTree(Node* root) {
        int diameter=0,height=0;
        height=diameter_dfs(root,diameter);
        return diameter;
    }    


//Max Sum any path
int subPathSum_dfs(Node* temp,int &sum){
        if(temp==nullptr){
            return 0;
        }
        else{
            int left=subPathSum_dfs(temp->left,sum);
            int right=subPathSum_dfs(temp->right,sum);

            if(left<0){
                left=0;
            }
            if(right<0){
                right=0;
            }

            sum=max(sum,temp->data + left + right);

            return temp->data + max(left,right);
        } 
    }

    int maxPathSum(Node* root) {
        int sum=INT_MIN; //not 0 since we can't pick 0 if not present
        
        subPathSum_dfs(root,sum);

        return sum; 
    }

//same tree
bool isSameTree(Node* p, Node* q) {
        if(p==q && p==nullptr){
            return true;
        }else{
            if(p!=nullptr && q!=nullptr && p->data==q->data){
                return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
            }else{
                return false;
            }
        }
    }


//zigzag
vector<vector<int>> zigzagLevelOrder(Node* root) {
        vector<vector<int>> ans;
        if (root==nullptr) return ans;
        
        queue<Node*> que;
        que.push(root);

        bool reversed_flag=0;
        
        while(!que.empty()){
            int current_level_size=que.size();
            vector<int> current_level;
            for(int i=0;i<current_level_size;i++){
                Node* temp=que.front();
                que.pop();
                current_level.push_back(temp->data);
                if(temp->left!=nullptr)que.push(temp->left);
                if(temp->right!=nullptr)que.push(temp->right);
            }
            if(reversed_flag){
                reverse(current_level.begin(),current_level.end());
                ans.push_back(current_level);
            }else{
                ans.push_back(current_level);
            }

            reversed_flag=!reversed_flag;
        }

        return ans;
    }    


//boundary anti clockwise a little tricky need to careful of the cases
void dfs_left(Node* root, vector<int> &ans){
        
        if(root!=nullptr) root=root->left;
        
        while(root!=nullptr){
            if(root->left!=nullptr || root->right!=nullptr) ans.push_back(root->data);
            
            if(root->left!=nullptr) root=root->left;
            else root=root->right;
        }
        
        return;
    }
    
    void dfs_leafs(Node* root, vector<int> &ans){
        
        if(root==nullptr) return;
        
        if(root->left==nullptr && root->right==nullptr){
              ans.push_back(root->data);
              return;
        } 
        
        dfs_leafs(root->left, ans);    
        dfs_leafs(root->right, ans);
        
        
        return;
    }
    
    void dfs_right(Node* root, vector<int> &ans){
        
        if(root!=nullptr) root=root->right;
        
        
        while(root!=nullptr){
            if(root->left!=nullptr || root->right!=nullptr) ans.push_back(root->data);
            if(root->right!=nullptr) root=root->right;
            else root=root->left;
        }
        
        return;
    }
  
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        
        ans.push_back(root->data);
        if(root->left==nullptr && root->right==nullptr) return ans;
        
        
        //left 
        dfs_left(root,ans);
        
        //leaves
        dfs_leafs(root,ans);
        
        //right
        vector<int> rev_right;
        dfs_right(root,rev_right);
        
        for(int i=rev_right.size()-1;i>=0;i--){
            ans.push_back(rev_right[i]);
        }
        
        return ans;
    }

//vertical order (column wise if root is 0,0 and serves as origin)
void vertical_order_dfs(Node* root, int col,int row, priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> &pq){
        if(root==nullptr) return;
        pq.push({col,row,root->data});
        vertical_order_dfs(root->left,col-1,row+1,pq);
        vertical_order_dfs(root->right,col+1,row+1,pq);

        return;
    }

    vector<vector<int>> verticalTraversal(Node* root) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vertical_order_dfs(root,0,0,pq);

        vector<vector<int>> ans;
        while(!pq.empty()){
            auto x=pq.top();
            int current_col=x[0];
            vector<int> current_col_ele;
            current_col_ele.push_back(x[2]);
            pq.pop();
            
            while(!pq.empty() && pq.top().front()==current_col){
                current_col_ele.push_back(pq.top().back());
                pq.pop();
                }
            ans.push_back(current_col_ele);
        }

        return ans;
    }


//same concept as above but we are only concerned with the first col element encountered
vector<int> topView(Node *root){
        vector<int> ans;
        map<int,int> view;
        queue<pair<Node*,int>> que;
        
        que.push({root,0});
        
        while(!que.empty()){
            auto x=que.front();
            if(view.find(x.second)==view.end()){
                view[x.second]=x.first->data;
            }
            que.pop();
            if(x.first->left!=nullptr) que.push({x.first->left,x.second-1});
            if(x.first->right!=nullptr) que.push({x.first->right,x.second+1});
        }
        
        for(auto x:view){
            ans.push_back(x.second);    
        }
        
        return ans;
    }

//same concept just we update everytime we find an element
vector <int> bottomView(Node *root) {
        vector<int> ans;
        map<int,int> view;
        queue<pair<Node*,int>> que;
        
        que.push({root,0});
        
        while(!que.empty()){
            auto x=que.front();
            view[x.second]=x.first->data;
            que.pop();
            if(x.first->left!=nullptr) que.push({x.first->left,x.second-1});
            if(x.first->right!=nullptr) que.push({x.first->right,x.second+1});
        }
        
        for(auto x:view){
            ans.push_back(x.second);    
        }
        
        return ans;
    }    

//same thing ordered map helps out here
vector<int> rightSideView(Node* root) {
        vector<int> ans;
        if(root==nullptr) return ans;

        map<int,int> view;
        queue<pair<Node*,int>> que;
        
        que.push({root,0});
        
        while(!que.empty()){
            auto x=que.front();
            view[x.second]=x.first->data;
            que.pop();
            if(x.first->left!=nullptr) que.push({x.first->left,x.second+1});
            if(x.first->right!=nullptr) que.push({x.first->right,x.second+1});
        }
        
        for(auto x:view){
            ans.push_back(x.second);    
        }
        
        return ans;
    }

//recursive checks (mirror traversal)
bool isSymmetricUtil(Node* left_sub,Node* right_sub){
        if(left_sub==nullptr || right_sub==nullptr)
            return left_sub==right_sub;
    
        return (left_sub->data==right_sub->data) && isSymmetricUtil(left_sub->left,right_sub->right) && isSymmetricUtil(left_sub->right,right_sub->left);
            
    }

    bool isSymmetric(Node* root) {
        if (root==nullptr) return true;

        return isSymmetricUtil(root->left,root->right);
    }    

//all paths to leaves
void dfs_paths_to_leaves(Node* root,vector<int> &curr_path,vector<vector<int>> &ans){
        
        if(root==nullptr) return;
        
        curr_path.push_back(root->data);
        
        if(root->left==nullptr && root->right==nullptr){
            ans.push_back(curr_path);
        }
        
        dfs_paths_to_leaves(root->left, curr_path, ans);
        dfs_paths_to_leaves(root->right, curr_path, ans);
        
        curr_path.pop_back();
        
        return;
        
    }
    
    vector<vector<int>> Paths(Node* root) {
        vector<int> curr;
        vector<vector<int>> ans;
        
        dfs_paths_to_leaves(root, curr, ans);
        
        return ans;
    }

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
        if(root == nullptr) return nullptr;
        if(root==p) return p;
        if(root==q) return q;
        Node* left=lowestCommonAncestor(root->left,p,q);
        Node* right=lowestCommonAncestor(root->right,p,q);
        if((left==p && right==q) || (left==q && right==p)){
            return root;
        }else if(left==nullptr) return right;
        else return left;
    }

int main() {
    // Creating a new node for the root of the 
    // binary tree using dynamic allocation
    Node* root = new Node(1);
    // Creating left and right child
    // nodes for the root node
    root->left = new Node(2);
    root->right = new Node(3);
    // Creating a right child node for
    // the left child node of the root
    root->left->right = new Node(5);
}
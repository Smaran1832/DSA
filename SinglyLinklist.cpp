#include<bits/stdc++.h>
using namespace std;

//insert, insert kth, delete, delete kth; edge cases 

class Node{
    public: // access modifier
    int data; // the data dataue
    Node* next; // the pointer to the next dataue
    public:
    // constructor
    Node (int data1, Node* next1){
        data=data1;  // Initialize data with the provided dataue
        next=next1;  // Initialize next with the provided
    }
    Node (int data1){
        data=data1;  // Initialize data with the provided dataue
        next=nullptr;  // Initialize next as null since it's the end of the list

    }

    // Function to print the linked list starting from the given head
    void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
        }
    }   
    // Function to delete the tail node of a linked list and return the new head
    Node* deleteTail(Node* head) {
    // If the list is empty or has only one node, return NULL
    if (head == NULL || head->next == NULL)
        return NULL;
    // Initialize a temporary pointer to traverse the list
    Node* temp = head;
    // Traverse to the second last node in the list
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    // Delete the last node
    delete temp->next;
    // Set the next of the second last node to nullptr, effectively removing the last node
    temp->next = nullptr;
    // Return the head of the modified list
    return head;
    }
};


Node* reverseList(Node* head) {

        Node* prev = NULL;
        Node* curr = head;

        while(curr != NULL){
            Node* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            
        }
        return prev;
    }

//palindrome time:O(n) space:O(1) simpler approach new list and then palindrome check
Node* reverse(Node* head){
        
        if(head==nullptr || head->next==nullptr){
            return head;
        }

        Node* prev=nullptr;
        Node* current=head;
        while(current!=nullptr){
            Node* next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        return prev;
    }

    bool isPalindrome(Node* head) {
        if(head==nullptr || head->next==nullptr) return true; 
       
        Node* slow=head;
        Node* fast=head->next;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }

        Node* half = reverse(slow->next);
        fast=head;
        while(half!=nullptr){
            if(fast->data!=half->data){
                reverse(slow->next);
                return false;
            }
            half=half->next;
            fast=fast->next;
        }
        reverse(slow->next);
        return true;
        
    }

    

int main(){
    vector<int> arr={2,5,8,7};
    Node* y = new Node(arr[0]);
    cout<<y<<'\n'; // returns the memory dataue
    cout<<y->data<<'\n'; // returns the data stored at that memory point
}

// Types of list Singly linked. Doubly Linked. Circular
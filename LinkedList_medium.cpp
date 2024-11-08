#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
     int val;
     int data;
     ListNode* bottom;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

//iterative
ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            
        }
        return prev;
    }

//recursive; will only go to second last else return null
ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* prev = NULL;
        ListNode* h2 = reverseList(head->next);
        head->next->next = head;
        head->next=prev;
        return h2;
    }

ListNode* middleNode(ListNode* head) {
        ListNode* turtle=head;
        ListNode* hare=head->next;
        if(hare==nullptr){
            return turtle;
        }
        turtle=turtle->next;
        hare=hare->next;
        while(hare!=nullptr){    
            if(hare->next!=nullptr){
                turtle=turtle->next;
                hare=hare->next;
            } else {
                return turtle;
            }
            if(hare->next==nullptr){
                return turtle;
            }
            hare=hare->next;           
        }
        return turtle;
    }

ListNode* deleteMiddle(ListNode* head) {
        
        if(head==nullptr || head->next==nullptr){
            if(head!=nullptr) delete(head);
            return nullptr;
        }

        ListNode* turtle=head;
        ListNode* hare=head->next;
        
        while(hare!=nullptr){
            hare=hare->next;
            //&& operator helps since it checks for the first  condition before 
            if(hare!=nullptr && hare->next!=nullptr){
                hare=hare->next;
                turtle=turtle->next;
            } 
        }

        ListNode* temp=turtle;
        turtle=turtle->next;
        temp->next=turtle->next;
        delete(turtle);

        return head;
    }    


//similar problem add 1 to number; reverse, add, reverse;
//dummy node helps simplyfy the implementation in terms of implemetnation
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int digit1 = (l1 != nullptr) ? l1->val : 0;
            int digit2 = (l2 != nullptr) ? l2->val : 0;

            int sum = digit1 + digit2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);
            tail->next = newNode;
            tail = tail->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }

        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }

//odd index first half, even index second half
ListNode* oddEvenList(ListNode* head) {
        
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        
        ListNode* odds=head;
        ListNode* evens=head->next;
        ListNode* div=evens;

        while(evens!=nullptr && evens->next!=nullptr){
            odds->next=odds->next->next;
            odds=odds->next;
            evens->next=evens->next->next;
            evens=evens->next;
        }

        odds->next=div;

        return head;


    }


ListNode* sortList0_1_2(ListNode* head) {
        
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        
        ListNode* zeroesHead=new ListNode(-1);
        ListNode* onesHead=new ListNode(-1);
        ListNode* twosHead=new ListNode(-1);

        ListNode* zero=zeroesHead;
        ListNode* one=onesHead;
        ListNode* two=twosHead;
        ListNode* temp=head;

        while(temp){
            if(temp->val==0){
                zero->next=temp;
                zero=zero->next;
            }else if(temp->val==1){
                one->next=temp;
                one=one->next;
            }else if(temp->val==2){
                two->next=temp;
                two=two->next;
            }
            temp=temp->next;
        }

        zero->next=(onesHead->next)?onesHead->next:(twosHead->next);
        one->next=twosHead->next;
        two->next=nullptr;

        ListNode* newHead = zeroesHead->next;

        delete zeroesHead;
        delete onesHead;
        delete twosHead;

        return newHead;


    }

ListNode* DeleteNthNodefromEnd(ListNode* head, int N) {
    // Create two pointers, fastp and slowp
    ListNode* fastp = head;
    ListNode* slowp = head;

    // Move the fastp pointer N nodes ahead
    for (int i = 0; i < N; i++)
        fastp = fastp->next;

    // If fastp becomes NULL,
    // the Nth node from the end is the head
    if (fastp == NULL)
        return head->next;

    // Move both pointers until fastp reaches the end
    while (fastp->next != NULL) {
        fastp = fastp->next;
        slowp = slowp->next;
    }

    // Delete the Nth node from the end
    ListNode* delNode = slowp->next;
    slowp->next = slowp->next->next;
    delete delNode;
    return head;
}    

//return the starting node of the loop slow and fast need to start from head for this logic to work; 
// once slow and fast enter the loop slow will move node while fast moves 2, consequentially minimizing the distance btw them eventually meeting again
ListNode *detectCycle(ListNode *head) {
        if(head==nullptr || head->next==nullptr) return nullptr;

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }

        if(fast==nullptr || fast->next==nullptr) return nullptr;
        
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return fast;
        
    }

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* cur1=headA;
        ListNode* cur2=headB;
        while(cur1!=cur2){
            cur1=(cur1==nullptr)?headB:cur1->next;
            cur2=(cur2==nullptr)?headA:cur2->next;
        }
        return cur1;
    }    

//make circular then update tail next
ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp=head;
        int size=1;
        
        if(head==nullptr || head->next==nullptr) return head;

        while(temp->next!=nullptr){
            temp=temp->next;
            size++;
        }

        if(k%size==0) return head;

        temp->next=head;
        temp=head;
       
        int cur=0,rotate=(k%size);
        while(cur!=(size-rotate-1)){
            temp=temp->next;
            cur++;
        }

        head=temp->next;
        temp->next=nullptr;

        return head;

    }    

//two pointer fast is n ahead when reaches null delete at slow
 ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* Fast=head;
       ListNode* Slow=head;
       int cnt=0;
       while(cnt<n){
        Fast=Fast->next;
        cnt++;
       }

       if(Slow==Fast || Fast==nullptr){
        head=Slow->next;
        delete(Slow);
        return head;
       }

       while(Fast->next!=nullptr){
        Slow=Slow->next;
        Fast=Fast->next;
       } 

       if(Slow->next!=nullptr){
        ListNode* temp=Slow->next;
        Slow->next=Slow->next->next;
        delete(temp);
        }

       return head;

    }

//merge two sorted list FLATTEN
ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
    
    ListNode *temp = new ListNode(0);
    ListNode *res = temp; 
    
    while(a != NULL && b != NULL) {
        if(a->data < b->data) {
            temp->bottom = a; 
            temp = temp->bottom; 
            a = a->bottom; 
        }
        else {
            temp->bottom = b;
            temp = temp->bottom; 
            b = b->bottom; 
        }
    }
    
    if(a) temp->bottom = a; 
    else temp->bottom = b; 
    
    return res -> bottom; 
    
}

ListNode *flatten(ListNode *root)
{
   
        if (root == NULL || root->next == NULL) 
            return root; 
  
        // recur for list on right 
        root->next = flatten(root->next); 
  
        // now merge 
        root = mergeTwoLists(root, root->next); 
  
        // return the root 
        // it will be in turn merged with its left 
        return root; 
}


//hard reverse k-groups linked list
 ListNode* findKtnNode(ListNode* head, int k){
        int cnt=0;
        ListNode* temp=head;
        while(cnt<k-1 && temp!=nullptr){
            cnt++;
            temp=temp->next;
        }
        if(cnt==k-1){
           return temp;
        }

        return nullptr;
        
    }

    ListNode* reverseList(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* cur=head;
        ListNode* front=nullptr;

        while(cur!=nullptr){
                    front=cur->next;
                    cur->next=prev;
                    prev=cur;
                    cur=front;
                }

        return prev;        
    }


    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr) return head;
        
        ListNode* kthNode=nullptr;
        ListNode* cur=head;
        ListNode* kthNext=nullptr;
        ListNode* prev=nullptr;

        ListNode* dummy = new ListNode(-1);
        prev=dummy;


        while(cur!=nullptr){
            kthNode = findKtnNode(cur,k);
            if(kthNode==nullptr){
                prev->next=cur;
                break;
            }else{
                prev->next=kthNode;
                kthNext = kthNode->next;
                kthNode->next=nullptr;
                ListNode* temp=reverseList(cur);
                prev=cur;
                cur=kthNext;
                if(head==prev) head=kthNode;  
            } 
        }
        return head;
    }


int main(){
    string x;
    cin>>x;
    return 0;
}        
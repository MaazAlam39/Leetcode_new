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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0){return head;}
        int len=1;
        ListNode* tail=head;
        while(tail->next !=NULL){
            tail=tail->next;
            len++;
        }
        tail->next=head;
        k = k%len; //when k is more than length of list
        int end = len-k; //to get end of the list
        while(end--) tail = tail->next;
        
        head = tail->next;
        tail->next = NULL;
        
        return head;

        //if (k>len){
        //     k=k%len;
        //     if(k==0)return head;
        // }
        // if(k<=len){
        //     k=len-k;
        //     if(k==0)return head;
        // }

        // int cnt=1;
        // ListNode* curr=head;
        // while(cnt<k && cnt !=NULL){
        //     curr=curr->next;
        //     cnt++;
        // }
    }
};
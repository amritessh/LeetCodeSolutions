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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //size of list
        int k = lists.size();
        
        //handling edge case
        if(k==0) return NULL;
        
        vector<int> nodes;
        ListNode head(0);
        ListNode* point = &head;
        for(ListNode* l: lists){
            while(l){
                nodes.push_back(l->val);
                l=l->next;
            }
        }
        
        sort(nodes.begin(),nodes.end());
        for(int x : nodes){
            point->next = new ListNode(x);
            point = point->next;
        }
        return head.next;
        
    }
};
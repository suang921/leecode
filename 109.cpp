#include<iostream>
#include<string>

using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return fromTree(head,NULL);
    }
    TreeNode* fromTree(ListNode* head, ListNode* tail){
        if(head==tail)return nullptr;
        ListNode* midNode = getMedian(head,tail);
        TreeNode* root = new TreeNode(midNode->val);
        root->left = fromTree(head,midNode);
        root->right = fromTree(midNode->next,tail);
        return root;
    }
    ListNode* getMedian(ListNode* head,ListNode* tail){
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next!=tail&&fast->next->next!=tail){
            fast=fast->next->next;
            slow=slow->next;

        }
        return slow;
    }
};
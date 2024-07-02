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
    class compare{
        public:
            bool operator()(ListNode* a, ListNode* b){
                return a->val > b->val;
            }
    };  
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        if(k==0) return NULL;

        for(int i = 0; i < k; i++){
            if(lists[i] != NULL){
                minHeap.push(lists[i]);
            }
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(!minHeap.empty()){
            ListNode* temp = minHeap.top();
            minHeap.pop();

            if(temp->next != NULL){
                minHeap.push(temp->next);
            }

            if(head==NULL){
                head = temp;
                tail = temp;
            }else{
                tail -> next = temp;
                tail = temp;
            }
        }
        return head;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, decltype(cmp) *> headHeap(cmp);
        for (auto head : lists) {
            if (head) {
                headHeap.push({head->val, head});
            }
        }
        ListNode *root = nullptr, *last = nullptr;
        while (!headHeap.empty()) {
            auto head = headHeap.top().second;
            headHeap.pop();
            if (root) {
                last->next = head;
                last = head;
            } else {
                last = root = head;
            }
            if (head->next) {
                headHeap.push({head->next->val, head->next});
            }
            head->next = nullptr;
        }
        return root;
    }
private:
    static bool cmp(const pair<int, ListNode *> &a, const pair<int, ListNode *> &b) {
        return a.first > b.first;
    }
};
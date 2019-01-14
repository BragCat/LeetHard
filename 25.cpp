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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) {
            return head;
        }
        auto ptr = head;
        ListNode *lastGTail = nullptr;
        while (ptr) {
            auto st = ptr, ed = ptr->next;
            int cnt = 1;
            while (ed && cnt < k) {
                ed = ed->next;
                ++cnt;
            }
            if (cnt < k) {
                break;
            }
            auto gPair = reverseEachGroup(st, ed);
            if (!lastGTail) {
                head = gPair.first;
            } else {
                lastGTail->next = gPair.first;
            }
            gPair.second->next = ed;
            ptr = ed;
            lastGTail = gPair.second;
        }
        return head;
    }
private:
    pair<ListNode *, ListNode *> reverseEachGroup(ListNode *st, ListNode *ed) {
        auto gLast = st, now = st;
        ListNode *prev = nullptr;
        while (now != ed) {
            auto next = now->next;
            now->next = prev;
            prev = now;
            now = next;
        }
        return make_pair(prev, gLast);
    }
};
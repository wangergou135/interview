/**
 * @file MergeKSortedLists.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "common.h"
class Solution {
public:
    // a little bit slow
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        ListNode *dummy = lists[0];
        for (int i = 1; i < lists.size(); i++) {
            dummy = mergeTwoLists(dummy, lists[i]);
        }
        return dummy;
    }
    // their solution   https://www.cnblogs.com/grandyang/p/4606710.html
    ListNode* mergeKLists_1(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        int n = lists.size();
        while (n > 1) {
            int k = (n + 1) / 2;
            for (int i = 0; i < n / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            }
            n = k;
        }
        return lists[0];
    }
private:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy  = new ListNode(-1);
        ListNode *cur = dummy;
        while (list1 && list2) {
            if (list1->val >= list2->val) {
                cur->next = list2;
                list2 = list2->next;
            } else {
                cur->next = list1;
                list1 = list1->next;
            }
            cur = cur->next;

        }
        if (list1) {
            cur->next = list1;
        }
        if (list2) {
            cur->next = list2;
        }       
        return dummy->next;
    }
};

int main() 
{
    print_listnode(ls1);
    print_listnode(ls2);
    print_listnode(ls3);

    vector<ListNode*> lists = {ls1, ls2, ls3};
    print_listnode(Solution().mergeKLists(lists));
}
/**
 * @file AddTwoNumbers.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-04
 * 
 * @copyright Copyright (c) 2022
 * 
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order, and each of their nodes contains a single digit.
 * Add the two numbers and return the sum as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
    The number of nodes in each linked list is in the range [1, 100].
    0 <= Node.val <= 9
    It is guaranteed that the list represents a number that does not have leading zeros.
 */

#include "common.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carryFlag = 0;
        int curSum = 0;

        ListNode *l3, *result;
        l3 = new ListNode(0);
        result = l3;

        while (l1 || l2 || carryFlag) {
            curSum = 0;
            if (l1) { 
                curSum += l1->val;
                l1 = l1->next;
            }
            if (l2) { 
                curSum += l2->val;
                l2 = l2->next;
            }

            curSum += carryFlag;

            l3->val = curSum % 10;
            carryFlag = curSum / 10;

            if (l1 || l2 || carryFlag) {
                l3->next = new ListNode(0);
                l3 = l3->next;
            }

        }

        return result;
    }

};



int main() 
{



    return 1;
}
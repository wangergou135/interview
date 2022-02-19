#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <climits>
#include <cmath>
#include <list>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

template <typename Container1D>
void print_1d_container(Container1D container)
{
    for_each(container.cbegin(), container.cend(), [](auto item){
        cout << item << ", ";
    });
    cout << endl;
}

template <typename Container2D>
void print_2d_container(Container2D container)
{

    for_each(container.cbegin(), container.cend(), [](auto item){
        print_1d_container(item);
    });
}

void print_listnode(ListNode* l) 
{
    while(l) {
        cout << l->val << ", ";
        l = l->next;
    }
    cout << endl;
}
template <typename MapType>
void print_map(MapType&& m) 
{
    for(auto item : m) {
        cout << item.first << ", " << item.second << endl;
    }
    cout << endl;
}
// sorted lists
ListNode ln11 {10};
ListNode ln12 {8, &ln11};
ListNode ln13 {5, &ln12};
ListNode ln14 {1, &ln13};
ListNode* ls1 = &ln14;

ListNode ln21 {13};
ListNode ln22 {7, &ln21};
ListNode ln23 {5, &ln22};
ListNode ln24 {3, &ln23};
ListNode ln25 {-1, &ln24};
ListNode* ls2 = &ln25;

ListNode ln31 {9};
ListNode ln32 {7, &ln31};
ListNode ln33 {4, &ln32};
ListNode* ls3 = &ln33;
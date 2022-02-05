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


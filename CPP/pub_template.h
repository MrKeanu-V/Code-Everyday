/*
@Author: MrKeanu
@Date: 2022-05-17 15:16:22
@Description: 本文件为模板文件，用于存放一些常用的模板函数和模板类
*/
#pragma once

#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
//#include <ranges>
#include <functional>
#include <climits>
#include <cmath>
#include <intrin.h> // 包含 _BitScanForward
using namespace std;

namespace pub {
    // 单链表
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int val) :val(val), next(nullptr) {}
        ListNode(int val, ListNode* next) : val(val), next(next) {}
    };
    // 构建链表
    ListNode* createList(vector<int>& nums);
    // 删除链表
    ListNode* deleteNode(ListNode* head, int val);
    // 链表打印
    void printList(ListNode* head);

    // 二叉树
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() :val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* l, TreeNode* r) :val(x), left(l), right(r) {}
    };
    // 层序构建二叉树
    TreeNode* createTree(vector<int>& nums);
    // 层序打印二叉树
    void printTree(TreeNode* root);
    // 前序遍历二叉树
    void preOrderTree(TreeNode* root);
    // 中序遍历二叉树
    void inOrderTree(TreeNode* root);
    // 后序遍历二叉树
    void postOrderTree(TreeNode* root);
    // 层序遍历二叉树
    vector<vector<int>> levelOrderTree(TreeNode* root);

    // 数组打印
    template<typename T>
    void printVector1D(const vector<T>& vec) {
        cout << "[";
        for (size_t i = 0; i < vec.size(); ++i) {
            cout << vec[i];
            if (i != vec.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    template<typename T>
    void printVector2D(const vector<vector<T>>& vec2D) {
        cout << "[";
        for (size_t i = 0; i < vec2D.size(); ++i) {
            printVector1D(vec2D[i]);
        }
        cout << "]" << endl;
    }

    // Bool转换
    string Bool2Str(bool b);

    // 汉明重量
    int count_one(int n);
    // 最长公共前缀
    string longestCommonPrefix(const string& s1, const string& s2);

    // 位运算相关
    unsigned int __builtin_ctz(unsigned int val); // 返回n中最低位的1的位置
}


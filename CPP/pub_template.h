/*
@Author: MrKeanu
@Date: 2022-05-17 15:16:22
@Description: ���ļ�Ϊģ���ļ������ڴ��һЩ���õ�ģ�庯����ģ����
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
#include <intrin.h> // ���� _BitScanForward
using namespace std;

namespace pub {
    // ������
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int val) :val(val), next(nullptr) {}
        ListNode(int val, ListNode* next) : val(val), next(next) {}
    };
    // ��������
    ListNode* createList(vector<int>& nums);
    // ɾ������
    ListNode* deleteNode(ListNode* head, int val);
    // �����ӡ
    void printList(ListNode* head);

    // ������
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() :val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* l, TreeNode* r) :val(x), left(l), right(r) {}
    };
    // ���򹹽�������
    TreeNode* createTree(vector<int>& nums);
    // �����ӡ������
    void printTree(TreeNode* root);
    // ǰ�����������
    void preOrderTree(TreeNode* root);
    // �������������
    void inOrderTree(TreeNode* root);
    // �������������
    void postOrderTree(TreeNode* root);
    // �������������
    vector<vector<int>> levelOrderTree(TreeNode* root);

    // �����ӡ
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

    // Boolת��
    string Bool2Str(bool b);

    // ��������
    int count_one(int n);
    // �����ǰ׺
    string longestCommonPrefix(const string& s1, const string& s2);

    // λ�������
    unsigned int __builtin_ctz(unsigned int val); // ����n�����λ��1��λ��
}


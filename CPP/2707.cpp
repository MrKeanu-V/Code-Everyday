/*
2707. Extra Characters of a String [Medium]
*/
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <functional>
#include <numeric>
#include <ranges>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <cmath>
using namespace std;

// 字典树
class Trie {
private:
    vector<Trie*> children;
    bool isEnd;

public:
    Trie() : children(26, nullptr), isEnd(false) {}

    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if(node->children[ch] == nullptr) node->children[ch] = new Trie();
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool track(Trie*& node, char ch) {  // 指针引用，修改指针本身
        if (node == nullptr || node->children[ch - 'a'] == nullptr) {
            node = nullptr;
            return false;
        }
        node=node->children[ch - 'a'];
        return node->isEnd;
    }
};

class Solution {
public:
    // 解法一 动态规划 转化完全背包
    int minExtraChar1(string s, vector<string>& words) {
        int n = s.size();
        vector<int> dp(n + 1, INT_MAX);
        unordered_map<string, int> word2cnt;
        // Init
        for (auto& word : words) word2cnt[word]++;
        dp[0] = 0;
        // DP
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + 1;
            for (int j = i-1; j >= 0; j--) 
                if (word2cnt.count(s.substr(j, i - j))) dp[i] = min(dp[i], dp[j]);
        }
        return dp[n];
    }
    // 解法二 字典树 优化查找
    int minExtraChar(string s, vector<string>& words) {
        int n = s.size();
        vector<int> dp(n + 1, INT_MAX);
        Trie trie;
        for (auto word : words) {
            reverse(word.begin(), word.end());
            trie.insert(word);
        }
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + 1;
            Trie* node = &trie;
            for (int j = i - 1; j >= 0; j--)
                if (trie.track(node, s[j])) dp[i] = min(dp[i], dp[j]);
        }
        return dp[n];
    }
};

int main() {
    Solution sln;
    string s = "leetscode";
    vector<string> words = {"leetcode", "leet", "code"};
    cout << sln.minExtraChars(s, words) << endl;
    return 0;
}
/*
LeetCode 49. 字母异位词分组
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<ranges>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> st;
        if (strs.empty()) return res;
        int index = 0;
        for (auto& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            if (st.find(key) == st.end()) {
                st[key] = index;
                index++;
                vector<string> tmp;
                tmp.push_back(str);
                res.push_back(tmp);
            }
            else res[st[key]].push_back(str);
        }
        return res;
    }

    // 哈希表
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }

    }
};

int main() {
    Solution s;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = s.groupAnagrams(strs);
    for (auto& vec : res) {
        for (auto& str : vec) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}


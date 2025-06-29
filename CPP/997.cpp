/*
997. Find the Town Judge [Esay - 3]
*/
#include "pub_template.h"

class Solution {
public:
    // 解法一 暴力法 Time:O(m+n) Space:O(n) 
    int findJudge_1(int n, vector<vector<int>>& trust) {
        vector<vector<int>> trust_count(n + 1, vector<int>(2, 0));//分别表示出度 入度
        for (auto& t : trust) {
            trust_count[t[0]][0]++;
            trust_count[t[1]][1]++;
        }
        for (int i = 1; i <= n; i++) {
            if (!trust_count[i][0] && trust_count[i][1] == n - 1) return i;
        }
        return -1;
    }
    // 解法一 优化 Time:O(m+n) Space:O(n)
    int findJudge(int n, vector<vector<int>>& trust) {
        //分别表示出度 入度
        vector<int> out_cnt(n + 1,0);
        vector<int> in_cnt(n + 1, 0);
        for (auto& t : trust) {
            in_cnt[t[1]]++;
            out_cnt[t[0]]++;
        }
        for (int i = 1; i <= n; i++) {
            if (!out_cnt[i] && in_cnt[i] == n - 1) return i;
        }
        return -1;
    }
    void test() {
        vector<vector<int>> trust1 = {{1,2}};
        vector<vector<int>> trust2 = { {1,3},{2,3} };
        vector<vector<int>> trust3 = {{1,3},{2,3},{3,1}};
        cout << findJudge(2, trust1) << endl;
        cout << findJudge(3, trust2) << endl;
        cout << findJudge(3, trust3) << endl;
    }
};

//int main() {
//    Solution().test();
//    return 0;
//}
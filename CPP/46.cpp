/*
46. Permutations [Medium - 4]
*/
#include "pub_template.h"
using namespace pub;

// ����·�����⣺DFS�����ݷ� ��������DFS�Ǳ�������·�������ݷ��Ǳ������н⣬��������ͬ���Ƚ����
class Solution {
public:
    // �ⷨһ ���ݷ� Time:O(N*N!) Space:O(N)
    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len) {
        if (first == len) return res.push_back(output);

        for (int i = first; i < output.size(); ++i) {   // ��������⣬��first��ʼ��
            swap(output[i], output[first]);
            backtrack(res, output, first + 1, len);
            swap(output[i], output[first]);
        }
    }
    vector<vector<int>> permute_1(vector<int>& nums) {
        if (nums.empty()) return {};
        vector<vector<int>> res;
        backtrack(res, nums, 0, nums.size());
        return res;
    }

    // �ⷨ�� DFS Time:O(N*N!) Space:O(N)
    vector<vector<int>> permute_2(vector<int>& nums) {
        if (nums.empty()) return {};
        vector<vector<int>> res;
        int len = nums.size();
        vector<int> path(len), visited(len, false);

        auto dfs = [&](auto&& dfs, int depth) -> void {
            if (depth == len) return res.push_back(path);
            for (int i = 0; i < len; i++) {
                if (!visited[i]) {
                    path[depth] = nums[i];
                    cout << "depth: " << depth << " i: " << i << endl;
                    cout<<"visited: "<<visited[i]<<endl;
                    cout << "path: ";
                    for (auto& p : path) cout << p << " ";
                    cout << endl;
                    visited[i] = true;
                    dfs(dfs, depth + 1);
                    visited[i] = false; // ����״̬
                }
            }
        };

        dfs(dfs, 0);

        return res;
    }

    void test() {
        vector<int> nums = {1, 2, 3};
        vector<vector<int>> res = permute_2(nums);
    }
};

//int main() {
//    Solution().test();
//    return 0;
//}
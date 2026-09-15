/*
239. Sliding Window Maximum [Hard - 6]
*/
#include "fnt/fnt_solution.h"
#include "fnt/fnt_utils.h"
using namespace fnt;

class Solution239 : public BaseSolution {
public:
    FNT_SOLUTION_KEY("239")
    // 解法一 容器+暴力 Time:O(n*k) Space:O(k)
    vector<int> maxSlidingWindow_1(vector<int>& nums, int k) {
        int n = nums.size(), i = 0;
        vector<int> res, v(1);
        while (i < k - 1) v.push_back(nums[i++]);
        while (i < n) {
            v.push_back(nums[i++]);
            v.erase(v.begin());
            res.push_back(*max_element(v.begin(), v.end()));
        }
        return res;
    }
    // 解法二 滑动指针+最大堆 Time:O(nlogk) Space:O(k)
    vector<int> maxSlidingWindow_2(vector<int>& nums, int k) {
        vector<int> res;
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) { return a.first < b.first; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);   // pair<nums[i], i>
        q.emplace(INT_MAX, -1);
        for (int i = 0; i < k - 1; i++) q.emplace(nums[i], i);
        for (int i = k - 1; i < nums.size(); i++) {
            q.emplace(nums[i], i);
            while (q.top().second <= i - k) q.pop();
            res.push_back(q.top().first);
        }
        return res;
    }
    // 解法三 滑动指针+双端队列 Time:O(n) Space:O(k)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(), i = 0;
        deque<int> q;
        while (i < k) {
            while (!q.empty() && nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i++);
        }
        vector<int> res = { nums[q.front()] };
        while (i < n) {
            while (!q.empty() && nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i);
            while (q.front() <= i - k) q.pop_front();
            res.push_back(nums[q.front()]);
            i++;
        }
        return res;
    }

    void test() override {
        // 注意：三种解法都会修改入参，每个用例使用独立副本
        vector<int> nums1 = { 1, 3, -1, -3, 5, 3, 6, 7 };
        printVector1D(maxSlidingWindow(nums1, 3));    // [3, 3, 5, 5, 6, 7]

        vector<int> nums2 = { 1 };
        printVector1D(maxSlidingWindow(nums2, 1));    // [1]

        vector<int> nums3 = { 1, 3, -1, -3, 5, 3, 6, 7 };
        printVector1D(maxSlidingWindow_1(nums3, 3));  // 解法一 对照
    }
};

FNT_REGISTER(Solution239);

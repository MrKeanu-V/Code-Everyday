/*
2080. Range Frequency Queries [Medium - 1702]
*/
#include  <iostream>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <functional>
#include <ranges>
#include <cmath>
#include <climits>
using namespace std;

// 解法一 哈希表 + 二分查找
class RangeFreqQuery {
private:
    unordered_map<int, vector<int>> ocr;
public:
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) ocr[arr[i]].push_back(i);
    }

    int query(int left, int right, int value) {
        const vector<int>& pos = ocr[value];
        auto l = lower_bound(pos.begin(), pos.end(), left);
        auto r = upper_bound(pos.begin(), pos.end(), right);
        return r - l;
    }
};

int main() {
    vector<int> arr = {12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56};
    RangeFreqQuery obj(arr);
    cout << obj.query(1, 2, 4) << endl;
    cout << obj.query(0, 11, 33) << endl;
    return 0;
}
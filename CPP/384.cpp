/*
384. Shuffle an Array [Medium - 5]
*/
#include "pub_template.h"
using namespace pub;

class Solution {
private:
    vector<int> original;
    vector<int> shuffled;

public:
    Solution(vector<int>& nums) {
        this->shuffled = nums;
        this->original.resize(nums.size());
        copy(nums.begin(), nums.end(), original.begin());
    }
    vector<int> reset() {
        copy(original.begin(), original.end(), shuffled.begin());
        return shuffled;
    }
    // Fisher-Yates shuffle algorithm
    vector<int> shuffle() {
        for (int i = 0; i < shuffled.size(); ++i) {
            int j = i + rand() % (shuffled.size() - i); // next waiting index
            swap(shuffled[i], shuffled[j]);
        }
        return shuffled;
    }
    vector<int> shuffle_1() {
        vector<int> result = original;
        for (int i = 0; i < result.size(); ++i) {
            swap(result[i], result[rand() % result.size()]);
        }
        return result;
    }
    void test() {
        vector<int> result = shuffle();
        print1DVector(result);
        result = reset();
        print1DVector(result);
    }
};

//int main() {
//    vector<int> nums = { 1, 2, 3 };
//    Solution(nums).test();
//    return 0;
//}

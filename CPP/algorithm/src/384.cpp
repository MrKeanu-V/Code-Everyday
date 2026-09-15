/*
384. Shuffle an Array [Medium - 5]
*/
#include "fnt/fnt_solution.h"
#include "fnt/fnt_utils.h"
using namespace fnt;

class Solution384 : public BaseSolution {
private:
    vector<int> original;
    vector<int> shuffled;

public:
    FNT_SOLUTION_KEY("384")

    Solution384() = default;

    Solution384(vector<int>& nums) {
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
    void test() override {
        vector<int> result = shuffle();
        printVector1D(result);
        result = reset();
        printVector1D(result);
    }
};
FNT_REGISTER(Solution384);
//int main() {
//    vector<int> nums = { 1, 2, 3 };
//    Solution(nums).test();
//    return 0;
//}

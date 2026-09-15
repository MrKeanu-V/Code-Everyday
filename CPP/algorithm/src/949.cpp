/*
949. Largest Time for Given Digits. [Medium - 3 - Backtrack]
*/
#include "fnt/fnt_solution.h"
#include "fnt/fnt_utils.h"

class Solution949 : public fnt::BaseSolution {
public:
    FNT_SOLUTION_KEY("949")

    string largestTimeFromDigits(vector<int>& arr) {
        string ans = "";
        vector<int> used(arr.size(), 0);
        //vector<
        return ans;
    }
    void test() override {
        vector<int> A = {1, 2, 3, 4};
        cout << largestTimeFromDigits(A) << endl;   // 23:41
        vector<int> B = { 0,4,0,0 };
        cout << largestTimeFromDigits(B) << endl;   // 04:00
    }
};

FNT_REGISTER(Solution949);
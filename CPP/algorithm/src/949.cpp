/*
949. Largest Time for Given Digits. [Medium - 3 - Backtrack]
*/
#include "fnt_solution.h"
#include "fnt_template.h"

class Solution949 {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        string ans = "";
        vector<int> used(arr.size(), 0);
        //vector<
        //return ans;
    }
    void test() {
        vector<int> A = {1, 2, 3, 4};
        cout << largestTimeFromDigits(A) << endl;   // 23:41
        vector<int> B = { 0,4,0,0 };
        cout << largestTimeFromDigits(B) << endl;   // 04:00
    }
};

FNT_REGISTER_SOLUTION(Solution949, 949)
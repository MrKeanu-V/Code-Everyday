/*
278. First Bad Version [Esay - 3]
*/
#include "fnt/fnt_solution.h"
#include "fnt/fnt_utils.h"
using namespace fnt;

class Solution278 : public BaseSolution {
private:
	int bad = -1;
public:
	FNT_SOLUTION_KEY("278")
	int firstBadVersion(int n) {
		int l = 1, r = n;	//[1, n]
		while (l < r) { 
			int mid = l + (r - l) / 2;
			if (isBadVersion(mid)) r = mid;
			else l = mid + 1;
		}
		return l;
	}

	void setBad(int n) {
		this->bad = n;
	}

	bool isBadVersion(int n) {
		return n >= bad;
	}

	void test() override {
		setBad(4);
		cout<< firstBadVersion(5) <<endl;
		setBad(1);
		cout<< firstBadVersion(1) <<endl;
	}
};

FNT_REGISTER(Solution278);
//int main() {
//	Solution().test();
//	return 0;
//}
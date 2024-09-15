/*
С����C++����2
ħ���Ķ���
С�����ܲ���һ�������ħ���Ķ��ң������ķ����ģ����߳�Ϊx��y��z������ά�ռ�����Ǽٶ���ռ��(0,0,0) ��(x,y,z)�Ŀռ䡣��ħ���ռ�û���������Ķ������Է����κ�λ�á�
���ڣ���ҹ�����һ�����Ϊk���߳�����Ϊ������������ħ������ħ�������Է���ħ���Ķ��ҵ�����λ�ã������뱣֤ħ�������ĸ��Ƕ���ħ���Ķ��ҵĿռ��ڡ�
�������ħ���������п��ܵı߳�ѡȡ����£���ת����Ҳ��Ϊһ�ְڷŷ�ʽ�����ҵ�ȫ�����ַ�����ڷŷ�ʽ����������һ�֡�
����������
��һ��ΪT����ʾ��T�����ݡ�
ÿ�����ݰ���һ�У����ĸ�����x,y,z,k���ֱ��ʾħ���Ķ��ҵĳߴ磬�����ӵ������
*/
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
	int countWays(int x, int y, int z, int a, int b, int c) {
		int count = 0;
		if (a <= x && b <= y && c <= z) count++;
		if (b <= x && c <= y && a <= z) count++;
		if (c <= x && a <= y && b <= z) count++;
		return count;
	}
	// ��ħ�����߳��������Ϊkey���԰ڷŷ�ʽ����Ϊvalue
	int magicTable(int x, int y, int z, int k) {
		int maxCount = 0;
		for (int a = 1; a * a * a <= k; a++)	// ��һ������߳�
		{
			if (k % a != 0) continue;
			for (int b = 1; a * b * b <= k; b++)	// �ڶ�������߳�{
			{
				if (k % (a * b) == 0) {
					int c = k / (a * b);
					int count = countWays(x, y, z, a, b, c);
					maxCount = max(maxCount, count);
				}
			}
		}
   		return maxCount;
	}
};

int main() {
	int T;
	cin >> T;
	Solution s;
	while (T--) {
		int x, y, z, k;
		cin>> x >> y >> z >> k;
		cout<< s.magicTable(x, y, z, k) << endl;
	}
	return 0;
}
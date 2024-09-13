/*
小红定义一个字符串是“好串”，当且仅当该字符串的每个字符都相等。
小红拿到了一个字符串，她想知道最多可以找到多少个不重叠的、长度为k的相同的连续子串,满足这些子
串都是好串?
*/ 
/*
样例 
7 2
aabaacc
2
如果取"cc"则只能取一个。但取"aa"则可以取2个。因此答案是2。
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int maxGoodSubstrings(const std::string& s, int k) {
    int n = s.length();
    int maxCount = 0;

    for (int i = 0; i <= n - k; ++i) {
        int count = 1; // 至少有一个好串
        bool allSame = true;

        // 检查从当前位置开始的子串是否是好串
        for (int j = i + 1; j < i + k; ++j) {
            if (s[j] != s[i]) {
                allSame = false;
                break;
            }
        }

        // 如果是好串，尝试扩展窗口以找到更多的好串
        if (allSame) {
            for (int j = i + k; j <= n - k; j += k) {
                int sameCount = 1;
                for (int m = j + 1; m < j + k; ++m) {
                    if (s[m] != s[j]) {
                        sameCount = 0;
                        break;
                    }
                }
                if (sameCount == 1) {
                    count++;
                } else {
                    break;
                }
            }
            maxCount = std::max(maxCount, count);
        }
    }

    return maxCount;
}

int main() {
    int n, k;
    std::string s;
    std::cin >>n>> k;
    std::cin >> s;
    std::cout << maxGoodSubstrings(s, k) << std::endl;
    return 0;
}

//#include <string>
//#include <vector>
//#include <algorithm>
//#include <stack>
//#include<unordered_map>
//#include<unordered_set>
//#include<iostream>
//using namespace std;
//
//unordered_map<std::string, int> flag; 
//
//int main(){
//	int n, k;
//	cin>>n>>k;
//
//	string chars;
//	cin>>chars;
//	cout<<endl<<" Inputs chars: "<<chars<<endl;
//	
//	int maxRes=0;
//	for(int i=0;i<=n-k;i++){
//		char search[k];
//		chars.copy(i, i+k, search);	//C11
//		cout<<"copy searching chars: "<<search<<endl;
//			
//		int res=0;	
//		for(int s=0;s<=n-k;s++){
//			char indeed[k];
//			chars.copy(s, s+k, indeed);
//			cout<<"copy searching chars: "<<indeed<<endl;
////			if(flag.end()!=flag.find(indeed)){
////				continue;
////			}
//			if(chars.compare(s,k,search)==0){
//				res++;
//			}
//			cout<<"search: "<<search<<" indeed: "<<indeed <<" compare: "<<chars.compare(s,k,search)<<endl;
//		}
//		cout<<"results"<<res<<endl;
//		maxRes = max(maxRes,res);
////		flag.insert({search, res});
//	}
//	
//	cout<<"result: "<<maxRes<<endl;
//}



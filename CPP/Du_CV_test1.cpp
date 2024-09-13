/*
С�춨��һ���ַ����ǡ��ô��������ҽ������ַ�����ÿ���ַ�����ȡ�
С���õ���һ���ַ���������֪���������ҵ����ٸ����ص��ġ�����Ϊk����ͬ�������Ӵ�,������Щ��
�����Ǻô�?
*/ 
/*
���� 
7 2
aabaacc
2
���ȡ"cc"��ֻ��ȡһ������ȡ"aa"�����ȡ2������˴���2��
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int maxGoodSubstrings(const std::string& s, int k) {
    int n = s.length();
    int maxCount = 0;

    for (int i = 0; i <= n - k; ++i) {
        int count = 1; // ������һ���ô�
        bool allSame = true;

        // ���ӵ�ǰλ�ÿ�ʼ���Ӵ��Ƿ��Ǻô�
        for (int j = i + 1; j < i + k; ++j) {
            if (s[j] != s[i]) {
                allSame = false;
                break;
            }
        }

        // ����Ǻô���������չ�������ҵ�����ĺô�
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



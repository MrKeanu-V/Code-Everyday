/*
208. Implement Trie (Prefix Tree) [Medium - 5]
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ranges>
#include <numeric>
#include <cmath>
#include <climits>
#include <utility>
#include <functional>
using namespace std;

struct TrieNode {
	TrieNode* children[26];
	bool isEnd = false;
};

class Trie {
private:
	TrieNode* root = new TrieNode();

	int find(string word) {
		TrieNode* cur = root;
		for (char c : word) {
			c -= 'a';
			if (cur->children[c] == nullptr) return 0;
			cur = cur->children[c];
		}
		return cur->isEnd ? 2 : 1;
	}

public:
	Trie() {

	}

	void insert(string word) {
		TrieNode* cur = root;
		for (char c : word) {
			c -= 'a';
			if (cur->children[c] == nullptr) {
				cur->children[c] = new TrieNode();
			}
			cur = cur->children[c];
		}
		cur->isEnd = true;
	}

	bool search(string word) {
		TrieNode* cur = root;
		for (char c : word) {
			c -= 'a';
			if (cur->children[c] == nullptr) return false;
			cur = cur->children[c];
		}
		return cur->isEnd;
	}

	bool startsWith(string prefix) {
		TrieNode* cur = root;
		for (char c : prefix) {
			c -= 'a';
			if (cur->children[c] == nullptr) return false;
			cur = cur->children[c];
		}
		return true;
	}
};

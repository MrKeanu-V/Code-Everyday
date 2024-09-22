/*
146. LRU Cache Medium LRU���� �е�
*/
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <unordered_map>
#include <algorithm>
#include <numeric>
using namespace std;

// �ⷨһ������ ���Ա�
class LRUCache1 {
public:
    unordered_map<int, int> cache;  // key, value
    int _capacity_;
    list<int> lru;  // key
    LRUCache1(int capacity) {
        _capacity_ = capacity;
    }

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        lru.erase(find(lru.begin(), lru.end(), key));
        lru.push_back(key);
        return it->second;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cache[key] = value;
            lru.erase(find(lru.begin(), lru.end(), key));
            lru.push_back(key);
        }
        else {
            cache[key] = value;
            lru.push_back(key);
            if (cache.size() > _capacity_) {
                cache.erase(lru.front());
                lru.pop_front();
            }
        }
    }
};

// �ⷨ����˫������(����) + ��ϣ��
class Node {
public:
    int key, value; //dummy��key��valueʵ���Ͽ������ڱ����㳤�Ⱥ��������
    Node* prev, * next;

    Node(int k = 0, int v = 0) :key(k), value(v), prev(nullptr), next(nullptr) {}
};
class LRUCache {
private:
    int _capacity_;
    Node* dummy;    //dummy�ڱ�����Լһ��tail
    unordered_map<int, Node*> cache;  // ��key��Node�佨��ӳ���ϵ

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void push_front(Node* node) {
        node->prev = dummy;
        node->next = dummy->next;
        dummy->next->prev = node;
        dummy->next = node;
    }

    Node* find(int key) {
        // auto it = cache.find(key);
        if(cache.find(key)==cache.end())
            return nullptr;
        Node* node = cache[key];
        remove(node);
        push_front(node);
        return node;
    }
public:
    LRUCache(int capacity) : _capacity_(capacity), dummy(new Node()) {
        dummy->prev = dummy->next = dummy;  // ��������
    }

    int get(int key) {
        Node* node = find(key);
        return node ? node->value : -1;
    }

    void put(int key, int value) {
        auto node = find(key);
        if (node)
            node->value = value;
        else {
            cache[key] = node = new Node(key, value);
            push_front(node);
            if (cache.size() > _capacity_) {
                Node* last = dummy->prev;
                cache.erase(last->key);
                remove(last);
                delete(last);//�ͷ�node C++ʹ��delete�ͷ��ڴ� Cʹ��free�ͷ��ڴ�
            }
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;       // returns 1
    cache.put(3, 3);    // evicts key 2
    cout << cache.get(2) << endl;       // returns -1 (not found)
    return 0;
}
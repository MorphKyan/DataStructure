//
// Created by morph on 2021/5/6.
//
#include <unordered_map>

using namespace std;

class Node {
public:
    int key;
    int val;
    Node *next, *prev;

    Node(int key, int val) : key(key), val(val) {}
};

class DoubleList {
private:
    Node *head, *tail;
    int size;

public:
    DoubleList() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addLast(Node *x) {
        tail->prev->next = x;
        x->prev = tail->prev;
        x->next = tail;
        tail->prev = x;
        size++;
    }

    void remove(Node *x) {
        x->prev->next = x->next;
        x->next->prev = x->prev;
        size--;
    }

    // 删除第一个，并返回
    Node *removeFirst() {
        if (head->next == tail)
            return nullptr;
        Node *first = head->next;
        remove(first);
        return first;
    }

    int getSize() {
        return size;
    }
};

class LRU {
private:
    unordered_map<int, Node *> map;
    Node *head, *tail;
    int size;
    int capability;

public:
    LRU(int cap) : capability(cap) {
        size = 0;
    }

    int get(int key) {
        if (!map.count(key))
            return -1;
        Node *node = map[key];
        moveToHead(key);
        return node->val;
    }

    void put(int key, int val) {
        if (!map.count(key)) {
            if (size >= capability) {
                Node *x = removeTail();
                map.erase(x->key);
                delete x;
                size--;
            }
            Node *node = new Node(key, val);
            map[key] = node;
            addToHead(node);
            size++;
        } else {
            map[key]->val = val;
            moveToHead(key);
        }
    }

    void moveToHead(int key) {
        Node *x=map[key];
        detach(x);
        addToHead(x);
    }

    // 临时断开，后面还会有操作所以不会内存泄露
    void detach(Node *x) {
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }

    void addToHead(Node *x) {
        x->prev = head;
        x->next = head->next;
        head->next->prev = x;
        head->next = x;
    }

    Node *removeTail() {
        Node *x = tail->prev;
        detach(x);
        return x;
    }
};
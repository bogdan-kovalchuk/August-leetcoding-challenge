#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        top = nullptr;
    }

    void add(int key) {
        if (!contains(key)) {
            top = new Node(key, top);
        }
    }

    void remove(int key) {
        if (top != nullptr && top->data == key) {
            top = top->next;
            return;
        }

        auto node = top;
        while (node != nullptr) {
            if (node->next != nullptr && node->next->data == key) {
                node->next = node->next->next;
                return;
            }
            node = node->next;
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        auto node = top;
        while (node != nullptr) {
            if (node->data == key) return true;
            node = node->next;
        }
        return false;
    }

private:
    struct Node {
        Node(int val, Node *n) : data(val), next(n) {}

        int data;
        Node *next;
    };

    Node *top;
};

int main() {
    auto hashSet = new MyHashSet();

    vector<string> functions = {"add", "contains", "add", "contains", "remove", "add", "contains", "add", "add", "add",
                                "add", "add", "add", "contains", "add", "add", "add", "contains", "remove", "contains",
                                "contains", "add", "remove", "add", "remove", "add", "remove", "add", "contains", "add",
                                "add", "contains", "add", "add", "add", "add", "remove", "contains", "add", "contains",
                                "add", "add", "add", "remove", "remove", "add", "contains", "add", "add", "contains",
                                "remove", "add", "contains", "add", "remove", "remove", "add", "contains", "add",
                                "contains", "contains", "add", "add", "remove", "remove", "add", "remove", "add", "add",
                                "add", "add", "add", "add", "remove", "remove", "add", "remove", "add", "add", "add",
                                "add", "contains", "add", "remove", "remove", "remove", "remove", "add", "add", "add",
                                "add", "contains", "add", "add", "add", "add", "add", "add", "add", "add"};

    vector<int> values = {58, 0, 14, 58, 91, 6, 58, 66, 51, 16, 40, 52, 48, 40, 42, 85, 36, 16, 0, 43, 6, 3, 25, 99, 66,
                          60, 58, 97, 3, 35, 65, 40, 41, 10, 37, 65, 37, 40, 28, 60, 30, 63, 76, 90, 3, 43, 81, 61, 39,
                          75, 10, 55, 92, 71, 2, 20, 7, 55, 88, 39, 97, 44, 1, 51, 89, 37, 19, 3, 13, 11, 68, 18, 17,
                          41, 87, 48, 43, 68, 80, 35, 2, 17, 71, 90, 83, 42, 88, 16, 37, 33, 66, 59, 6, 79, 77, 14, 69,
                          36, 21, 40};

    vector<string> expected = {"null", "false", "null", "true", "null", "null", "true", "null", "null", "null",
                               "null", "null", "null", "true", "null", "null", "null", "true", "null", "false", "true",
                               "null", "null", "null", "null", "null", "null", "null", "true", "null", "null", "true",
                               "null", "null", "null", "null", "null", "true", "null", "true", "null", "null", "null",
                               "null", "null", "null", "false", "null", "null", "false", "null", "null", "false",
                               "null", "null", "null", "null", "true", "null", "true", "true", "null", "null", "null",
                               "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null",
                               "null", "null", "null", "null", "null", "null", "true", "null", "null", "null", "null",
                               "null", "null", "null", "null", "null", "false", "null", "null", "null", "null", "null",
                               "null", "null", "null"};


    for (int i = 0; i < functions.size(); ++i) {
        if (functions[i] == "add") {
            hashSet->add(values[i]);
        }
        if (functions[i] == "remove") {
            hashSet->remove(values[i]);
        }
        if (functions[i] == "contains") {
            auto res = hashSet->contains(values[i]);
            auto output = "false";
            if (res == 1) {
                output = "true";
            }
            if (output != expected[i]) {
                std::cout << "i = " << i << std::endl;
            }
        }
    }
}
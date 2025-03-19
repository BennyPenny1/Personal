#include <iostream>

template <typename T> class slist {
    public:
     slist(T value) {
        Node* new_node = new Node
        new_node->data = value;
        new_node->next = root;
        root = new_node;
    }

    void prepend() {

    }
    private:
    struct Node {
        node* next;
        T data;
    };

    static node* root;
};

int main() {
    slist::Node* slist::root = nullptr;
}

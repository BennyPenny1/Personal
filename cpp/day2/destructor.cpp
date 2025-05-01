#include <iostream>

// this was not finished

template <typename T> class slist {
    public:
     slist(T value) {
        Node* new_node = new Node;
        new_node->data = value;
        new_node->next = root->next;
        root = new_node;
    }
    void remove(T value, int instances) {
        if (instances <= 0) {
            std::cerr << "must provide more than one instance\n";
            return;
        }
        if (root == nullptr) {
            std::cerr << "there is no slist to iterate over\n";
            return;
        }
            Node* trav = root->next;
            Node* prev = root;
            while(trav != nullptr && instances <= 0) {
                if (trav->data == value) {
                    prev->next = trav->next;
                    instances--;
                    delete trav;
                    trav = prev->next;
                }
                else {
                    prev = trav;
                    trav = trav->next;
                }
            }
        }
    ~slist() {
        Node* trav = root->next;
        Node* next = trav->next;
        while(trav != nullptr) {
            delete trav;
            if (trav != nullptr) {
                trav = next;
                next = trav->next;
            }
        }
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

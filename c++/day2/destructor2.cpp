#include <iostream>

class slist {
    public:
    slist() {
        root = nullptr;
    }
    ~slist() {
        if (root == nullptr) {
            delete root;
            return;
        }
        else {
            Node* trav = root;
            Node* next = root->next;
            while (trav != nullptr) {
                next = trav->next;
                delete trav;
                trav = next;
            }
        }
        return;
    }

    void insert(int value) {
        Node* new_node = new Node();
        if (root == nullptr) {
            root = new_node;
            new_node->data = value;
            new_node->next = nullptr;
        }
        else{
            new_node->next = root;
            new_node->data = value;
            root = new_node;
        }
    }

    int get_by_value(int value) {
        if (root == nullptr) {
            std::cerr << "there is no slist to iterate through\n";
            return 1;
        }
        Node* trav = root->next;
        Node* prev = root;
        while (trav != nullptr) {
            std::cout << trav->data << "\n";
            if (trav->data == value) {
                return trav->data;
            }
            else {
                prev = trav;
                trav = trav->next;
            }
        }
        std::cerr << "value was not found";
        return 2;
    }

    int get_by_index(int index) {
        if (index < 0) {
            std::cerr << "index must be more than zero\n";
            return 1;
        }
        if (root == nullptr) {
            std::cerr << "there is no slist to iterate through\n";
            return 2;
        }
        Node* trav = root;
        while (trav != nullptr) {
            if (index == 0) {
                return trav->data;
            }
            else {
                trav = trav->next;
                index--;
            }
        }
        std::cerr << "index out of bounds\n";
        return 3;
    }

    int delete_by_value(const int value) {
        if (root == nullptr) {
            std::cerr << "there is no slist to iterate through\n";
            return 1;
        }
        Node* cur = root->next;
        Node* prev = root;
        bool has_2 = false;
        if (cur != nullptr) {
            Node* next = cur->next;
            has_2 = true;
        }
        bool is_found = false;
        if (has_2) {
            while (next != nullptr) {
                if (cur->data == value) {
                    prev->next = next;
                    delete cur;
                    cur = next;
                    next = next->next;
                    is_found = true;
                }
                else {
                    prev = cur;
                    cur = next;
                    next->next;
                }
            }
        }
        if (prev->data == value) {
            delete prev;
            root = cur;
        }
        if (cur->data == value) {
            delete cur;
            root = nullptr;
        }
        }
        if (is_found) {
            return value;
        }
        else {
            std::cerr << "value was not found";
            return 2;
        }
    }
    int delete_by_index(int index) {
        if (index < 0) {
            std::cerr << "index must be more than zero\n";
            return 1;
        }
        if (root == nullptr) {
            std::cerr << "there is no slist to iterate through\n";
            return 2;
        }
        Node* trav = root->next;
        Node* prev = root;
        while (trav != nullptr) {
            if (index == 0) {
                prev->next = trav->next;
                int x = trav->data;
                delete trav;
                return x;
            }
            else {
                prev = trav;
                trav = trav->next;
                index--;
            }
        }
        std::cerr << "index is out of bounds\n";
        return 3;
    }
    private:
    struct Node {
        Node* next;
        int data;
    };
    Node* root;
};

int main () {
    slist list;
    list.insert(5);
    list.insert(6);
    std::cout<< list.get_by_index(0) << "\n";

}

#include <iostream>

class slist {
    public:
    slist() {
        root = nullptr;
    }
    ~slist() {
        if (root == nullptr) {
            return;
        }
        else {
            Node* trav = root;
            while (trav != nullptr) {
                Node* temp = trav->next;
                delete trav;
                trav = temp;
            }
            root = nullptr;
        }
        return;
    }

    void insert(int value) {
        Node* new_node = new Node();
        new_node->data = value;
        new_node->next = nullptr;


        if (root == nullptr) {
            root = new_node;
        }
        else {
            Node* trav = root;
            while (trav->next != nullptr) {
                trav = trav->next;
            }
            trav->next = new_node;
        }
    }

    int get_by_value(int value) {
        if (root == nullptr) {
            std::cerr << "there is no slist to iterate through\n";
            return 1;
        }

        Node* prev = root;
        if (prev->data == value) {
            root = prev->next;
        }

        Node* trav = root->next;
        while (trav != nullptr) {
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
        bool is_found = false;

        while (root->data == value) { // get root not to be the value
            Node* temp = root;
            delete root;
            root = temp->next;
            is_found = true;
            if (root == nullptr) {
                return value;
            }
        }
        Node* prev = root;
        Node* cur = root->next;
        if (cur == nullptr) {
            if (prev->data == value) {
                delete prev;
                root = nullptr;
                return value;
            }
            else {
                if (is_found) {
                    return value;
                }
                else{
                    std::cerr << "value not found\n";
                    return 2;
                }
            }
        }
        Node* next = cur->next;

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
                next = next->next;
            }

        }
        if (cur->data == value) {
            delete cur;
            prev->next = nullptr;
            is_found = true;
        }

        if (is_found) {
            return value;
        }
        else {
            std::cerr << "value was not found\n";
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

        Node* prev = root;
        if (index == 0) {
            root = prev->next;
            int value = prev->data;
            delete prev;
            return value;
        }
        Node* trav = root;
        while (trav != nullptr) {
            if (index == 0) {
                prev->next = trav->next;
                int value = trav->data;
                delete trav;
                return value;
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
    list.insert(7);
    list.insert(6);
    list.insert(8);
    list.insert(9);
    std::cout << list.get_by_index(0) << "\n";
    std::cout << "A\n";;
    std::cout << list.get_by_index(1) << "\n";
    std::cout << "B\n";
    std:: cout << list.delete_by_index(2) << "\n";
    std::cout << "C\n";
    std::cout << list.get_by_index(2) << "\n";
    list.~slist();
}

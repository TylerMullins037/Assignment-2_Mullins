#include "SingleLinkedList.h"
#include <string>
using namespace std;

template <typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

template <typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List() {
    clear();
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
    // Pre-condition: None.
    // Post-condition: A new node with the provided 'item' is added to the front of the list.
    Node* new_node = new Node(item);
    if (empty()) {
        head = tail = new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }
    num_items++;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
    // Pre-condition: None.
    // Post-condition: A new node with the provided 'item' is added to the end of the list.
    Node* new_node = new Node(item);
    if (empty()) {
        head = tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
    num_items++;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front() {
    // Pre-condition: None.
    // Post-condition: The first node of the list is removed if the list is not empty.
    if (!empty()) {
        Node* temp = head;
        head = head->next;
        delete temp;
        num_items--;
    }
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back() {
    // Pre-condition: None.
    // Post-condition: The last node of the list is removed if the list is not empty.
    if (!empty()) {
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
        num_items--;
    }
}

template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::front() const {
    // Pre-condition: None.
    // Post-condition: The data of the first node is returned if the list is not empty; 
    //                 otherwise, a runtime error is thrown.
    if (!empty()) {
        return head->data;
    }
    throw runtime_error("List is empty");
}

template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::back() const {
    // Pre-condition: None.
    // Post-condition: The data of the last node is returned if the list is not empty; 
    //                 otherwise, a runtime error is thrown.
    if (!empty()) {
        return tail->data;
    }
    throw runtime_error("List is empty");
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {
    // Pre-condition: None.
    // Post-condition: Returns true if the list is empty; otherwise, returns false.
    return num_items == 0;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
    // Pre-condition: 'index' is a valid index within the list (0 <= index <= num_items), 'item' is of type Item_Type.
    // Post-condition: A new node with the provided 'item' is inserted at the specified 'index' in the list.
    if (index > num_items) {
        index = num_items;
    }
    if (index == 0) {
        push_front(item);
    } else if (index == num_items) {
        push_back(item);
    } else {
        Node* new_node = new Node(item);
        Node* current = head;
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
        num_items++;
    }
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
    // Pre-condition: 'index' is a valid index within the list (0 <= index < num_items).
    // Post-condition: The node at the specified 'index' is removed from the list if it exists; 
    //                 otherwise, returns false.
    if (index >= num_items) {
        return false;
    }
    if (index == 0) {
        pop_front();
    } else {
        Node* current = head;
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        if (index == num_items - 1) {
            tail = current;
        }
        num_items--;
    }
    return true;
}

template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) const {
    // Pre-condition: None.
    // Post-condition: Returns the index of the first occurrence of 'item' in the list if found; 
    //                 otherwise, returns num_items.
    Node* current = head;
    size_t index = 0;
    while (current != nullptr) {
        if (current->data == item) {
            return index;
        }
        current = current->next;
        index++;
    }
    return num_items;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::clear() {
    // Pre-condition: None.
    // Post-condition: Removes all nodes from the list, making it empty.
    while (!empty()) {
        pop_front();
    }
}

template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::size() const {
    // Pre-condition: None.
    // Post-condition: returns the number of items in the list ( nodes)
    return num_items;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::traverseAndPrint() const {
    // Pre-condition: None.
    // Post-condition: prints the list (all nodes)
    if (!empty()) {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}

template class Single_Linked_List<int>;
template class Single_Linked_List<std::string>;
template class Single_Linked_List<double>;
template class Single_Linked_List<char>;

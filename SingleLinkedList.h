#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

// Templated class for a singly linked list
template <typename Item_Type>
class Single_Linked_List {
private:
    // Node structure to store data and link to the next node
    struct Node {
        Item_Type data;
        Node* next;
        Node(const Item_Type& item) : data(item), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t num_items;

public:
    // Constructor: Initializes an empty singly linked list
    Single_Linked_List();

    // Destructor: Deallocates memory used by the list
    ~Single_Linked_List();

    
    void push_front(const Item_Type& item); // Adds an item to the front of the list
    void push_back(const Item_Type& item); // Adds an item to the back of the list
    void pop_front();     // Removes the item at the front of the list
    void pop_back(); // Removes the item at the back of the list
    Item_Type front() const;     // Gets the item at the front of the list
    Item_Type back() const;     // Gets the item at the back of the list
    bool empty() const;    // Checks if the list is empty
    void insert(size_t index, const Item_Type& item);     // Inserts an item at a specified index in the list
    bool remove(size_t index);     // Removes an item at a specified index in the list
    size_t find(const Item_Type& item) const;     // Find the index of the first occurrence of an item in the list
                                                  // Returns num_items if the item is not found
    void clear();     // Clear the entire list, deallocating memory and making it empty
    size_t size() const;     // Get the number of items (nodes) in the list
    void traverseAndPrint() const;     // Traverse and print the items in the list to the console
};

#include "SingleLinkedList.cpp"

#endif // SINGLELINKEDLIST_H

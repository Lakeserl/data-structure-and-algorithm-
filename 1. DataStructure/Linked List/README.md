# [Linked List Data Structure](https://www.geeksforgeeks.org/data-structures/linked-list/)

- Linked List Data Structure is using for collection of elements.

<b>Example:</b>

```C++
#include <iostream>

// Define the structure for a Node
class Node {
public:
    int data; // Data stored in the node
    Node* next; // Pointer to the next node

    // Constructor to initialize a node with given data and null next pointer
    Node(int value) : data(value), next(nullptr) {}
};
/*
- This class defines a node in the linked list. Each node has two members:
    data: Holds the value stored in the node.
    next: Points to the next node in the list.
- The constructor initializes a node with the provided data value and sets the next pointer to nullptr, indicating that it's not pointing to any other node initially.
*/
// Define the Linked List class
class LinkedList {
private:
    Node* head; // Pointer to the first node (head) of the list

public:
    // Constructor to initialize an empty linked list with null head pointer
    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the beginning of the list
    void insert(int value) {
        Node* newNode = new Node(value); // Create a new node with given value
        newNode->next = head; // Make the new node point to the current head
        head = newNode; // Update the head to point to the new node
    }

    // Function to display the elements of the linked list
    void display() {
        Node* current = head; // Start from the head node
        while (current != nullptr) { // Traverse until reaching the end of the list
            std::cout << current->data << " -> "; // Print the data of the current node
            current = current->next; // Move to the next node
        }
        std::cout << "nullptr" << std::endl; // Print nullptr to indicate the end of the list
    }

    // Iterative linear search function
    bool search(int key) {
        Node* current = head; // Start from the head node
        while (current != nullptr) { // Traverse until reaching the end of the list
            if (current->data == key) { // If current node's data matches the key
                return true; // Key found, return true
            }
            current = current->next; // Move to the next node
        }
        return false; // Key not found, return false
    }
};

int main() {
    // Create a linked list object
    LinkedList myList;

    // Insert some elements into the list
    myList.insert(10);
    myList.insert(20);
    myList.insert(30);

    // Display the elements of the list
    myList.display();

    // Search for elements in the list
    int key = 20;
    if (myList.search(key)) {
        std::cout << "Element " << key << " found in the list." << std::endl;
    } else {
        std::cout << "Element " << key << " not found in the list." << std::endl;
    }

    key = 40;
    if (myList.search(key)) {
        std::cout << "Element " << key << " found in the list." << std::endl;
    } else {
        std::cout << "Element " << key << " not found in the list." << std::endl;
    }

    return 0;
}
```

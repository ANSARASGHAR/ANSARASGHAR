#include <iostream>
#include<cstdlib>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void insertAtNthPosition(int value, int position) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; ++i) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid position" << endl;
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void traverse() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void updateAtNthPosition(int value, int position) {
        Node* temp = head;
        for (int i = 1; i < position && temp != nullptr; ++i) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid position" << endl;
        } else {
            temp->data = value;
        }
    }

    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void deleteFromNthPosition(int position) {
        if (position == 1) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;
        for (int i = 1; i < position && temp != nullptr; ++i) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid position" << endl;
        } else {
            prev->next = temp->next;
            delete temp;
        }
    }
    
};

void displayMenu(LinkedList &linkedList);

int main() {
    LinkedList linkedList;

    while (true) {
    	displayMenu(linkedList);

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Enter value to insert at the beginning: ";
                cin >> value;
                linkedList.insertAtBeginning(value);
                cout << "\nList: ";
                linkedList.traverse();
                cout<<endl;
                break;
            }
            case 2: {
                int value;
                cout << "Enter value to insert at the end: ";
                cin >> value;
                linkedList.insertAtEnd(value);
                cout << "\nList: ";
                linkedList.traverse();
                cout<<endl;
                break;
            }
            case 3: {
                int value, position;
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position to insert at: ";
                cin >> position;
                linkedList.insertAtNthPosition(value, position);
                cout << "\nList: ";
                linkedList.traverse();
                cout<<endl;
                break;
            }
            case 4: {
                cout << "\nList: ";
                linkedList.traverse();
                cout<<endl;
                break;
            }
            case 5: {
                int value;
                cout << "Enter value to search: ";
                cin >> value;
                if (linkedList.search(value)) {
                    cout << value << " found in the list." << endl;
                } else {
                    cout << value << " not found in the list." << endl;
                }
                break;
            }
            case 6: {
                int value, position;
                cout << "Enter value to update: ";
                cin >> value;
                cout << "Enter position to update at: ";
                cin >> position;
                linkedList.updateAtNthPosition(value, position);
                cout << "\nList: ";
                linkedList.traverse();
                cout<<endl;
                break;
            }
            case 7: {
                linkedList.deleteFromBeginning();
                cout << "\nList: ";
                linkedList.traverse();
                cout<<endl;
                break;
            }
            case 8: {
                int position;
                cout << "Enter position to delete from: ";
                cin >> position;
                linkedList.deleteFromNthPosition(position);
                cout << "\nList: ";
                linkedList.traverse();
                cout<<endl;
                break;
            }
            case 0: {
                cout << "Exiting program." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }

    return 0;
}

void displayMenu(LinkedList &linkedList) {
    system("cls"); 

    cout << "Current List: ";
    linkedList.traverse();

    cout << "1. Insert at the beginning" << endl;
    cout << "2. Insert at the end" << endl;
    cout << "3. Insert at nth position" << endl;
    cout << "4. Traverse" << endl;
    cout << "5. Search" << endl;
    cout << "6. Update at nth position" << endl;
    cout << "7. Delete from the beginning" << endl;
    cout << "8. Delete from nth position" << endl;
    cout << "0. Exit" << endl;
    }
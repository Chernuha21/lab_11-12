#include <iostream>
using namespace std;

// Вузол списку
struct Node {
    int data;
    Node* next;
};

// Додати елемент у кінець списку
void append(Node*& head, int value) {
    Node* newNode = new Node{ value, nullptr };
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Вивести список
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Видалити елементи, кратні трьом
void removeMultiplesOfThree(Node*& head) {
    while (head && head->data % 3 == 0) { // Видалення з початку
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    Node* current = head;
    while (current && current->next) {
        if (current->next->data % 3 == 0) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else {
            current = current->next;
        }
    }
}

// Додати число 88 після кожної пари рівних чисел
void addAfterEqualPairs(Node*& head) {
    Node* current = head;
    while (current && current->next) {
        if (current->data == current->next->data) {
            Node* newNode = new Node{ 88, current->next };
            current->next = newNode;
            current = newNode->next; // Пропустити новий вузол
        }
        else {
            current = current->next;
        }
    }
}

// Звільнити пам'ять списку
void freeList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Головна функція
int main() {
    Node* head = nullptr;

    // Заповнення списку
    append(head, 9);
    append(head, 3);
    append(head, 7);
    append(head, 7);
    append(head, 15);
    append(head, 5);
    append(head, 5);

    cout << "List: ";
    printList(head);

    // Видалення кратних трьом
    removeMultiplesOfThree(head);
    cout << "List if we delete sone lements that can be /3 : ";
    printList(head);

    // Додавання числа 88 після кожної пари рівних чисел
    addAfterEqualPairs(head);
    cout << "List after add num 88: ";
    printList(head);

    // Звільнити пам'ять
    freeList(head);

    return 0;
}

#include <iostream>
using namespace std;

// ����� ������
struct Node {
    int data;
    Node* next;
};

// ������ ������� � ����� ������
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

// ������� ������
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// �������� ��������, ����� �����
void removeMultiplesOfThree(Node*& head) {
    while (head && head->data % 3 == 0) { // ��������� � �������
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

// ������ ����� 88 ���� ����� ���� ����� �����
void addAfterEqualPairs(Node*& head) {
    Node* current = head;
    while (current && current->next) {
        if (current->data == current->next->data) {
            Node* newNode = new Node{ 88, current->next };
            current->next = newNode;
            current = newNode->next; // ���������� ����� �����
        }
        else {
            current = current->next;
        }
    }
}

// �������� ���'��� ������
void freeList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// ������� �������
int main() {
    Node* head = nullptr;

    // ���������� ������
    append(head, 9);
    append(head, 3);
    append(head, 7);
    append(head, 7);
    append(head, 15);
    append(head, 5);
    append(head, 5);

    cout << "List: ";
    printList(head);

    // ��������� ������� �����
    removeMultiplesOfThree(head);
    cout << "List if we delete sone lements that can be /3 : ";
    printList(head);

    // ��������� ����� 88 ���� ����� ���� ����� �����
    addAfterEqualPairs(head);
    cout << "List after add num 88: ";
    printList(head);

    // �������� ���'���
    freeList(head);

    return 0;
}

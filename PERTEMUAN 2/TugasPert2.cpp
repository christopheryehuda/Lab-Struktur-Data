#include <iostream>
using namespace std;

// Node untuk linked list
struct Node {
    int data;
    Node *next;
};

Node *top = NULL; // stack kosong

// Push = tambah di depan
void push(int value) {
    Node *newNode = new Node{value, top};
    top = newNode;
    cout << value << " masuk ke stack\n";
}

// Pop = hapus dari depan
void pop() {
    if (top == NULL) {
        cout << "Stack kosong!\n";
        return;
    }
    Node *temp = top;
    cout << top->data << " di-pop dari stack\n";
    top = top->next;
    delete temp;
}

// Cetak isi stack
void printStack() {
    Node *curr = top;
    cout << "Isi stack: ";
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    // Push 3 angka
    push(10);
    push(20);
    push(30);

    printStack(); // Stack: 30 20 10

    // Pop 1 angka
    pop();

    printStack(); // Stack: 20 10

    return 0;
}

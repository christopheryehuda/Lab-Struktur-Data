#include <iostream>
using namespace std;

#define MAX 5
int stack[MAX];
int top = -1;

void push(int value) {
    if (top >= MAX - 1) {
        cout << "Stack penuh!" << endl;
    } else {
        top++;
        stack[top] = value;
        cout << value << " masuk ke stack." << endl;
    }
}

void pop() {
    if (top < 0) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << stack[top] << " keluar dari stack." << endl;
        top--;
    }
}

void printStack() {
    cout << "Isi stack:";
    if (top < 0) {
        cout << " (kosong)";
    } else {
        for (int i = top; i >= 0; i--) {
            cout << " " << stack[i];
        }
    }
    cout << endl;
}

int main() {
    // PUSH semua elemen
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    // POP satu per satu sesuai gambar
    printStack();
    pop();
    printStack();
    pop();
    printStack();
    pop();
    printStack();
    pop();
    printStack();
    pop();

    if (top < 0)
        cout << "Stack kosong!" << endl;

    return 0;
}
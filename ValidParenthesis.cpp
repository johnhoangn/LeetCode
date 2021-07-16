#include<stdlib.h>
#include<string>
#include<iostream>

class node {
    public:
        node* next = NULL;
        char val;

        node(char data) {
            val = data;
        }
};

class simpleStack {
    node* top = NULL;
    
    public:
        void push(char data) {
            node* newNode = new node(data);
            
            if (top != NULL) {
                newNode->next = top;
            }
            
            top = newNode;
        }
    
    // minimum string length is 1, no underflow concerns
    public:
        void pop() {
            top = top->next;
        }
    
    public:
        char peek() {
            if (top == NULL) {
                return 0;
            } else {
                return top->val;
            }
        }

    public:
        void print() {
            node* curr = top;

            while (curr != NULL) {
                std::cout << curr->val;
                curr = curr->next;
            }
        }
};

bool isValid(std::string s) {
    simpleStack stack;
    char top = s.at(0);
    stack.push(top);

    for (int i = 1; i < s.length(); i++) {
        char curr = s.at(i);

        switch (curr) {
            case ')':
                if (top == '(') {
                    stack.pop();
                    top = stack.peek();
                } else {
                    return false;
                }
                break;
            case '}':
                if (top == '{') {
                    stack.pop();
                    top = stack.peek();
                } else {
                    return false;
                }
                break;
            case ']':
                if (top == '[') {
                    stack.pop();
                    top = stack.peek();
                } else {
                    return false;
                }
                break;
            default:
                stack.push(curr);
                top = curr;
        }
    }

    return stack.peek() == 0;
}

int main() {
    std::cout << isValid("()()") << "\n";
    std::cout << "HELLO, WORLD!";
    return 0;
}
#include <iostream>
using namespace std;

class Node {
private:

public:
	int value;
	Node* next;
	Node* prev;
	Node() {};
	Node(int value) {
		this->value = value;
		this->next = NULL;
		this->prev = NULL;
	}

	~Node() {}
};

class LinkedList {
private:
	Node* front;
	Node* back;
	int size;
public:

	LinkedList() {
		this->front = NULL;
		this->back = NULL;
		this->size = 0;
	}

	void printNodes() {
		while (front->next != NULL) {
			cout << front->value << " -> ";
			front = front->next;
		}
		if (front->next == NULL) {
			cout << front->value;
		}
		return;
	}

	void pushFront(int value) {
		Node* newNode = new Node(value);
		if (this->front == NULL && this->back == NULL) {
			this->front = newNode;
			this->back = newNode;
			size++;
			return;
		}
		newNode->next = front;
		front = newNode;
		newNode->value = value;
		newNode->next->prev = newNode;
		size++;
		return;
	}
	~LinkedList() {}
};
int main() {






	return 0;
}
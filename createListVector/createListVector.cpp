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

	void pushBack(int value) {
		Node* newNode = new Node(value);
		if (this->front == NULL && this->back == NULL) {
			this->front = newNode;
			this->back = newNode;
			size++;
			return;
		}
		newNode->prev = this->back;
		this->back->next = newNode;
		this->back = newNode;
		newNode->value = value;
		size++;
		return;
	}

	int popFront() {
		if (this->front == NULL && this->back == NULL) {
			return -1;
		}
		Node* tempNode = this->front;
		if (size <= 1) {
			int result = tempNode->value;
			this->back = NULL;
			this->front = NULL;
			delete tempNode;
			return result;
		}
		this->front = this->front->next;
		this->front->prev = NULL;
		int result = tempNode->value;
		delete tempNode;
		size--;
		return result;
	}

	int popBack() {
		if (this->front == NULL && this->back == NULL) {
			return -1;
		}
		Node* tempNode = this->back;
		if (size <= 1) {
			int result = tempNode->value;
			this->back = NULL;
			this->front = NULL;
			delete tempNode;
			return result;
		}
		this->back = this->back->prev;
		int result = tempNode->value;
		this->back->next = NULL;
		delete tempNode;
		size--;
		return result;
	}

	~LinkedList() {}
};


class VectorV {
private:
	int size;
	int capacity;
	int* data;
public:
	VectorV() {
		this->size = 0;
		this->capacity = 0;
		this->data = NULL;
	}

	int resize(int overSize) {
		int result = this->size + overSize;
		return result;
	}

	void insertNode(int value) {
		for (int i = 0; i < size; i++) {
			data[i] = value;
		}
	}




	~VectorV() {}
};




int main() {






	return 0;
}
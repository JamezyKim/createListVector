#include <iostream>
#include <chrono>
#include <string>
using namespace std;
using namespace std::chrono;

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
		this->capacity = 3;
		this->data = new int[this->capacity];
	}

	void printVector() {
		int count = 0;
		while (count+1 < this->size) {
			cout << data[count] << " -> ";
			count++;
		}
		cout << data[count];

	}

	void resize(int overSize) {
		int newCapacity = this->size + overSize;
		int* newData = new int[newCapacity];
		for (int i = 0; i < this->size; i++) {
			newData[i] = this->data[i];
		}
		delete this->data;
		this->data = newData;
		this->capacity = newCapacity;
	}

	void pushFront(int value) {
		this->size++;
		if (this->size >= this->capacity) {
			resize(this->size - this->capacity);
		}
		for (int i = this->size - 1; i > 0; i--) {
			data[i] = data[i - 1];
		}
		this->data[0] = value;
	}

	void pushBack(int value) {
		if (this->size >= this->capacity) {
			resize(this->size - this->capacity);
		}
		this->data[this->size] = value;
		this->size++;
	}

	int popFront() {
		if (this->size == 0) {
			return -1;
		}
		int result = this->data[0];
		for (int i = 0; i <= this->size; i++) {
			this->data[i] = this->data[i + 1];
		}
		this->size--;
		return result;
	}

	int popBack() {
		if (this->size == 0) {
			return -1;
		}
		int result = data[this->size - 1];
		this->size--;
		return result;
	}


	~VectorV() {}
};

void printVDurationMicroseconds() {
	VectorV v;
	auto startV = high_resolution_clock::now();
	int count = 0;
	for (int i = 0; i < 10000; i++) {
		v.pushFront(i);
		count = i;
	}
	auto stopV = high_resolution_clock::now();
	auto durationV = duration_cast<microseconds>(stopV - startV);
	cout << "The function has called " << count << " times." << endl <<
		"The duration of the vector is: " << durationV.count() << " microseconds" << endl;

}

void printVDurationSeconds() {
	VectorV v;
	auto startV = high_resolution_clock::now();
	int count = 0;
	for (int i = 0; i < 10000; i++) {
		v.pushFront(i);
		count = i;
	}
	auto stopV = high_resolution_clock::now();
	auto durationV = duration_cast<seconds>(stopV - startV);
	cout << "The function has called " << count << " times." << endl
		<< "The duration of the vector is: " << durationV.count() << " seconds" << endl;

}

void printLDurationMicroseconds() {
	LinkedList l;
	auto startL = high_resolution_clock::now();
	int count = 0;
	for (int i = 0; i < 10000; i++) {
		l.pushFront(i);
		count = i;
	}
	auto stopL = high_resolution_clock::now();
	auto durationL = duration_cast<microseconds>(stopL - startL);
	cout << "The function has called " << count << " times." << endl
		<< "The duration of the list is: " << durationL.count() << " microseconds" << endl;

}

void printLDurationSeconds() {
	LinkedList l;
	int count = 0;
	auto startL = high_resolution_clock::now();
	for (int i = 0; i < 10000; i++) {
		l.pushFront(i);
		count = i;
	}
	auto stopL = high_resolution_clock::now();
	auto durationL = duration_cast<seconds>(stopL - startL);
	cout << "The function has called " << count << " times." << endl 
		<< "The duration of the list is: " << durationL.count() << " seconds" << endl;

}

int main() {
	string result;
	cout << "Welcome. To exit, press x." << endl;
	do {
		cout << endl << "Please choose either Vector or List: ";
		getline(cin, result);
		if (result == "Vector" || result == "vector") {
			printVDurationSeconds();
			printVDurationMicroseconds();
		}
		else if (result == "List" || result == "list") {
			printLDurationSeconds();
			printLDurationMicroseconds();
		}
		else if(result != "x") {
			cout << "Sorry, " << result << " has not been successfully searched." << endl;
		}
	} while (result != "x");
	cout << "Thank you" << endl;

	return 0;
}
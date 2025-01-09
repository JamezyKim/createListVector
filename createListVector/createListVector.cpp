#include <iostream>
using namespace std;

int main() {

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

		~LinkedList() {}
	};

	return 0;
}
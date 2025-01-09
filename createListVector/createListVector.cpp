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

	return 0;
}
#include <list>

template<class T>
class Node {
public:
	Node() {}
	T data;
	Node *next;
	Node *prev;
};

template<class T>
class Queue {
public:
	Queue() {
		Start = NULL;
		Last = NULL;
		Size = 0;
	}
	//Queue(const Queue &pointer) {}
	~Queue() {}

	void Add(T &setData) {
		Node<T> *n = new Node<T>();
		n->data = setData;
		n->next = NULL;
		n->prev = Last;
		if (Last != NULL) {
			Last->next = n;
		}
		Last = n;
		if (Start == NULL) {
			Start = Last;
		}
		//Start->next = n;
		Size++;
	}
	void Pop() {
		Node<T> *r = Start;
		if (r->next != NULL) {
			Start = r->next;
			Start->prev = NULL;
		}
		else {
			Start = NULL;
			Last = NULL;
		}
		delete r;
		Size--;
	}
	Node<T>* getFront() {
		return Start;
	}

	Node<T> *Start;
	Node<T> *Last;
	unsigned int Size;
};
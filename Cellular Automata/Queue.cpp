#include <list>

template<class T>
class Node {
public:
	Node() {}
	T data;//Data the node holds
	Node *next;//Node behind this
	Node *forward;//Node in front of this
};

template<class T>
class Queue {
public:
	//Constructor
	Queue() {
		Front = NULL;
		Back = NULL;
		Size = 0;
	}
	//Deconstructor
	~Queue() {}

	//ADD::::Add a new node to Back of queue
	void Add(T &setData) {
		//make new node, n = new node holder
		Node<T> *n = new Node<T>();
		//set node data
		n->data = setData;
		//back of line has nothing behind it
		n->next = NULL;
		//previous back of line is set in front of new node
		n->forward = Back;
		//if back of line is empty, back of line is behind itself(?)
		if (Back != NULL) {
			Back->next = n;
		}
		//new node is the new back of line
		Back = n;
		//if front of line is empty, back of line is also front
		if (Front == NULL) {
			Front = Back;
		}
		//Size of queue is incremented
		Size++;
	}

	//POP::::Remove the node off the Front of queue
	void Pop() {
		//r = holder for node being removed
		Node<T> *r = Front;
		//if not the last node in queue...
		if (r->next != NULL) {
			//...new front of line equals node behind original front
			Front = r->next;
			//new Front of line no longer has anything in front of it
			Front->forward = NULL;
		}
		//...else, if the last node node in queue...
		else {
			//...queue is cleaned
			Front = NULL;
			Back = NULL;
		}
		//holder is deleted
		delete r;
		//Size of queue is decrimented
		Size--;
	}

	//get the data of the front of the line to use/reference
	T getFront() {
		return Front->data;
	}

	//returns the size
	int getSize() {
		return Size;
	}

	//Queue objects:
private:
	Node<T> *Front;//Node first in line
	Node<T> *Back;//Node last in line
	unsigned int Size;//number of nodes total in line
};
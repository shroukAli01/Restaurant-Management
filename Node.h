#pragma once

template <typename T>
class Node
{
private:
	T value;
	Node<T>* next;
	Node<T>* prev;

public:
	Node(T val) {
		value = val;
		next = nullptr;
		prev = nullptr;
	}

	T getValue() const {
		return value;
	}

	Node<T>* getNext() const {
		return next;
	}

	Node<T>* getPrev() const {
		return prev;
	}

	void setNext(Node<T>* n) {
		next = n;
	}

	void setPrev(Node<T>* p) {
		prev = p;
	}

	void setValue(T val) {
		value = val;
	}
};


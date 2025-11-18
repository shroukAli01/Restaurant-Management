#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

template <typename T>
class Queue
{
private:
	Node<T>* front;
	Node<T>* rear;
	int size;

public:
	Queue() {
		front = nullptr;
		rear = nullptr;
		size = 0;
	}

	~Queue() {
		while (!isEmpty()) {
			Dequeue();
		}
	}

	int getSize() {
		return size;
	}

	bool isEmpty() {
		return size == 0;
	}
	
	void Enqueue(T& value) {
		Node<T>* newNode = new Node<T>(value);
		if (isEmpty()) {
			front = newNode;
			rear = newNode;
		}
		else {
			rear->setNext(newNode);
			newNode->setPrev(rear);
			rear = newNode;
		}
		size++;
	}
	
	void Dequeue() {
		if (isEmpty()) {
			return;
		}
		Node<T>* temp = front;
		front = front->getNext();
		if (front != nullptr) {
			front->setPrev(nullptr);
		}
		else {
			rear = nullptr;
		}
		delete temp;
		size--;
	}
	
	T peek() {
		if (isEmpty()) {
			return;
		}
		return front->getValue();
	}
	
	void Print() {
		Node<T>* current = front;
		while (current != nullptr) {
			cout << current->getValue() << endl;
			current = current->getNext();
		}
	}
};


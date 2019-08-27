#include "QueueTwoStacks.h"

template<class T>
void QueueTwoStacks<T>::flip() {
	if (flipped) {
		flip(regular, backup);
	} else {
		flip(backup, regular);
	}

	flipped = !flipped;
}

template<class T>
void QueueTwoStacks<T>::flip(std::stack<T> one, std::stack<T> two) {
	while (!one.empty()) {
		two.push(one.pop());
	}
}

template<class T>
void QueueTwoStacks<T>::enqueue(T item) {
	if (item == nullptr) {
		throw "Value cannot be null";
	}

	if (flipped) {
		flip();
	}
	regular.push(item);
	sz++;
}

template<class T>
T QueueTwoStacks<T>::dequeue() {
	if (sz == 0) {
		throw "No elements to dequeue";
	}

	if (!flipped) {
		flip();
	}
	sz--;
	return backup.pop();
}
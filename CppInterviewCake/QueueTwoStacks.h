#pragma once
#include <stack>

template<class T>
class QueueTwoStacks {
	std::stack<T> regular, backup;
	int sz;
	bool flipped;
	void flip();
	void flip(std::stack<T> one, std::stack<T> two);

public:
	QueueTwoStacks(): sz(0), flipped(false) {}
	public void enqueue(T item);
	public T dequeue();
	public int size() { return sz };
};
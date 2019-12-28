#include<iostream>

#include "MyStack.h"

using namespace std;

void MyStack::push(int el) {
	list.addToHead(el);
}
void MyStack::pop() {
	list.deleteFromHead();
}
int MyStack::top() {
	int i=list.deleteFromHead();
	list.addToHead(i);
	return i;
}
bool MyStack::isEmpty() {
	if(list.isEmpty())
		return true;
	else
		return false;
}

void MyStack::print() {
	int i;
	list.printAll();
}



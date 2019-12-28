//************************  intSLList.cpp  **************************

#include <iostream>
#include "intSLList.h"
using namespace std;

IntSLList::~IntSLList() {
    for (IntSLLNode *p; !isEmpty(); ) {
        p = head->next;
        delete head;
        head = p;
    }
}

void IntSLList::addToHead(int el) {
    head = new IntSLLNode(el,head);
    if (tail == 0)
       tail = head;
}

void IntSLList::addToTail(int el) {
    if (tail != 0) {      // if list not empty;
         tail->next = new IntSLLNode(el);
         tail = tail->next;
    }
    else head = tail = new IntSLLNode(el);
}

int IntSLList::deleteFromHead() {
    int el = head->info;
    IntSLLNode *tmp = head;
    if (head == tail)     // if only one node on the list;
         head = tail = 0;
    else head = head->next;
    delete tmp;
    return el;
}

int IntSLList::deleteFromTail() {
    int el = tail->info;
    if (head == tail) {   // if only one node on the list;
         delete head;
         head = tail = 0;
    }
    else {                // if more than one node in the list,
         IntSLLNode *tmp; // find the predecessor of tail;
         for (tmp = head; tmp->next != tail; tmp = tmp->next);
         delete tail;
         tail = tmp;      // the predecessor of tail becomes tail;
         tail->next = 0;
    }
    return el;
}

void IntSLList::deleteNode(int el) {
    if (head != 0)                     // if non-empty list;
         if (head == tail && el == head->info) { // if only one
              delete head;                       // node on the list;
              head = tail = 0;
         }
         else if (el == head->info) {  // if more than one node on the list
              IntSLLNode *tmp = head;
              head = head->next;
              delete tmp;              // and old head is deleted;
         }
         else {                        // if more than one node in the list
              IntSLLNode *pred, *tmp;
              for (pred = head, tmp = head->next; // and a non-head node
                   tmp != 0 && !(tmp->info == el);// is deleted;
                   pred = pred->next, tmp = tmp->next);
              if (tmp != 0) {
                   pred->next = tmp->next;
                   if (tmp == tail)
                      tail = pred;
                   delete tmp;
              }
         }
}


void IntSLList::addToThird(int el) {

	head = new IntSLLNode(el,head);
	IntSLLNode *NewNode;
	IntSLLNode *tmp;
	
	int count =0;
	for(tmp=head;(tmp->next!=0)&&(tmp!=0);tmp=tmp->next)
		count++;
	cout<<"size:"<<count<<"  ";
	if(count<2) {
			if(count==0)
				tail=head;
	}
	else if(count=2) {
		head = head->next;
		tail->next = new IntSLLNode(el);
         	tail = tail->next;
	}
	else {
		head = head->next;
		NewNode = new IntSLLNode(el);
		NewNode=head->next->next;
	}
}

void IntSLList::deleteThird() {
	IntSLLNode *tmp;

	int count =0;
	for(tmp=head;(tmp->next!=0)&&(tmp!=0);tmp=tmp->next)
		count++;
	cout<<"size:"<<count<<"  ";
	if(count<3) {
		int el = tail->info;
		if (head == tail) {  
			 delete head;
			 head = tail = 0;
		}
		else {
			 IntSLLNode *tmp;
			 for (tmp = head; tmp->next != tail; tmp = tmp->next);
			 delete tail;
			 tail = tmp;
			 tail->next = 0;
		    }
	}
	else {
		IntSLLNode *prev;
		IntSLLNode *third;
		prev=head->next;
		third=head->next->next; 
		prev->next=third->next;
		delete third;
	}
}



bool IntSLList::isInList(int el) const {
    IntSLLNode *tmp;
    for (tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next);
    return tmp != 0;
}

void IntSLList::printAll() const {
	for (IntSLLNode *tmp = head; tmp != 0; tmp = tmp->next) {
		std::cout << tmp->info << " ";
	}
	std::cout << std::endl;
}

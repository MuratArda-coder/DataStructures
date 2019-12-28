#include <iostream>
#include <stdlib.h>
using namespace std;
#include "intSLList.h"

//Part 1
//*********************************************
float findAverage(IntSLList & list)
{
	float average=0.0;
	for(int i=0;i<20;i++) {
		average=average+list.deleteFromHead();
	}
	return average/20.0;

}

void findMinAndMax(IntSLList & list, int & min,int & max)
{
	min=999999;
	max=0;
	for(int i=0;i<20;i++) {
		int number=list.deleteFromHead();
		if(number<min)
			min=number;
		if(number>=max)
			max=number;
	}	

}

//*********************************************

//Part 2
//*********************************************
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
//*********************************************

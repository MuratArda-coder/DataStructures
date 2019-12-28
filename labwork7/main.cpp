#include <iostream>
#include "QUEUE.h"
#include <stack>
using namespace std;

/* this function reverse a given queue by using stack or stacks, 
do not use any other data structure other than the given queue and stacks */

void reverseQueue(QUEUE  & que)
{
	int i;
	stack<int> st; //this is an example declaration of a stack of STL library
	while(!(que.isEmpty())) {
		i=que.dequeue();
		st.push(i);
	}
	while(!(st.empty())) {
		i=st.top();
		st.pop();
		que.enqueue(i);
	}
}

int main()
{
	QUEUE myQue;

	for(int i=0;i<10;i++)
		myQue.enqueue(i);
	myQue.print();
	reverseQueue(myQue);
	myQue.print();
}

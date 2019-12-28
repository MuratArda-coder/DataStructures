#include "genDLList.h" 

class QUEUE
{
	private:
	DoublyLinkedList<int> list;

	public:
	/* do not this function, you can use it to print queue */
	void print()
	{
		cout<<list<<endl;
	}

	/* implement these functions outside the class*/
	void enqueue(int data); //add data to tail
	int dequeue(); //remove head and return the data
	bool isEmpty(); //return whether queue is empty or not

};


void QUEUE::enqueue(int data) {

	list.addToDLLHead(data);

}

int QUEUE::dequeue() {

	list.deleteFromDLLTail();

}

bool QUEUE::isEmpty() {

	list.isEmpty();

}








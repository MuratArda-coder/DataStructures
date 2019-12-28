#include<iostream>

#include "MyStack.h"
using namespace std;


void reverse(MyStack & st)
{
	MyStack *st2 = new MyStack;
	int i;
	while(!(st.isEmpty())) {
		i = st.top();
		st2->push(i);
		st.pop();
	}
	st=*st2;
}

bool isAwasome(MyStack & st)
{
	MyStack st1,st2;


	
	int i=st.top();
	while(!(st.isEmpty())) {
		st.pop();
		while(!(st.isEmpty())) {
			i = st.top();
			st1.push(i);
			st.pop();
		}
		int k=st1.top();
		if(i!=k)
			return false;
		st1.pop();
	}
	if((st.isEmpty()))
		return true;
}

bool isReverse(MyStack & st1, MyStack & st2)
{
	MyStack st3,st4;
	while(!(st1.isEmpty())) {
		int i = st1.top();
		st3.push(i);
		st1.pop();
	}
	while(!(st3.isEmpty())) {
		int i=st3.top();
		int k=st2.top();
		if(i!=k)
			return false;
		st3.pop();
		st2.pop();
	}
	if((st3.isEmpty()))
		return true;
}

int main()
{
		/* TESTING 2. QUESION */
		cout<<"testing 2. question:"<<endl;
		MyStack st;
		for( int i = 1; i <= 10 ; i++)
		{
			st.push(i);
		}
		cout<<"before reverse:"<<endl;
		st.print();
      	reverse(st); // second question
		cout<<"after reverse:"<<endl;
		st.print();
	
		/* TESTING 3. QUESION */
		cout<<"\ntesting 3. question:\n"<<endl;
		MyStack st2; //create a new stack and fill it to make it awasome
		for( int i = 1; i <= 3 ; i++)
		{
			st2.push(i);
		} 
		for( int i = 3; i >= 1 ; i--)
		{
			st2.push(i);
		} 
		st2.print();
		if(isAwasome(st2)) //third question, awasome	 	 
			cout<<"yes it is awasome\n";
		else
			cout<<"no it is not awasome\n";


		/* TESTING 4. QUESION */
		cout<<"\ntesting 4. question:\n"<<endl;
		MyStack st3,st4;
		st3.push(1);
		st3.push(2);
		st4.push(2);
		st4.push(3);
		
		if(isReverse(st3,st4))
			cout<<"yes they are reverse\n";
		else
			cout<<"no they are not reverse\n";	
		

}

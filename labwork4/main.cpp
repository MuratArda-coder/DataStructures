#include <iostream>
#include <stdlib.h>
using namespace std;
#include "intSLList.h"

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




int main()
{

	IntSLList numbers, numbers2;
	int min,max;

	//for question 1
	for(int i=1;i<=20;i++)
		numbers.addToTail(i);
	cout<<"average: "<<findAverage(numbers)<<endl;
	numbers.printAll();

	//for question 2
	for(int i=1;i<=20;i++)
		numbers2.addToTail(i);
	
	findMinAndMax(numbers2,min,max);
	cout<<"min: "<<min<<" max: "<<max<<endl;
	numbers2.printAll();
	
}

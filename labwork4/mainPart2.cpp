#include <iostream>
#include <stdlib.h>
using namespace std;
#include "intSLList.h"





int main()
{

	IntSLList numbers;

	
	numbers.addToThird(2);	
	numbers.printAll();

	numbers.addToThird(1);
	numbers.printAll();

	numbers.addToThird(8);
	numbers.printAll();

	numbers.addToThird(7);
	numbers.printAll();

	numbers.addToThird(6);
	numbers.printAll();

	numbers.deleteThird();
	numbers.printAll();
	numbers.deleteThird();
	numbers.printAll();
	numbers.deleteThird();
	numbers.printAll();
	numbers.deleteThird();
	numbers.printAll();
	numbers.deleteThird();
	numbers.printAll();

	
}

#include <iostream>
#include <stdlib.h>
using namespace std;
#include "intSLList.h"





int main()
{

        IntSLList numbers;

        numbers.insertToMiddle(8);
        numbers.insertToMiddle(2);
        numbers.insertToMiddle(5);
        numbers.insertToMiddle(3);
        numbers.insertToMiddle(4);
        numbers.printAll();
}

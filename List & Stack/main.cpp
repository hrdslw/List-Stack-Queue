#include <iostream>
#include <string.h>
#include "TLStack.h"
#include "TLCalc.h"
using namespace std;

int main() {


	TLCalc s("(2 + 2) ^ 3 + (3 * 4) ^ 2");
	//s.ToPostfix();
	//cout << s.get_postfix();
	//cout << s.CalcPostfix();
	cout << s.Calc();

}

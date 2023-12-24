#include "TLCalc.h"
#include <stdlib.h>


double TLCalc::CalcPostfix() {
	D.Clear();
	double x2, x1, y;
	for (int i = 0; i < postfix.length(); i++) {
		if (postfix[i] >= '0' && postfix[i] <= '9')
		{
			D.Push(postfix[i] - '0');
		}
		if ((postfix[i] == '+') || (postfix[i] == '-') || (postfix[i] == '*') || (postfix[i] == ':') || (postfix[i] == '^')) {
			
			double x1 = 0; double x2 = 0; double  y = 0;
			if (!D.IsEmpty())
			{
				x2 = D.Pop();
			}
			if (!D.IsEmpty())
			{
				x1 = D.Pop();
			}			if (postfix[i] == '+')
				y = x1 + x2;
			else if (postfix[i] == '-')
				y = x1 - x2;
			else if (postfix[i] == '*')
				y = x1 * x2;
			else if (postfix[i] == ':')
				y = x1 / x2;
			else if (postfix[i] == '^')
			{
				int x3 = x2;
				y = pow(x1, x3);
			}
			D.Push(y);
		}
	}
	double res;
	if (!D.IsEmpty())
		res = D.Pop();
	else
		throw "Empty stack.";

	if (!D.IsEmpty())
		throw "Problems with brackets.";
	return res;
}

void TLCalc::ToPostfix() {
	C.Clear();
	string str = "(" + infix + ")";
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(')
			C.Push('(');
		else if ((str[i] >= '0') && (str[i] <= '9'))
			postfix += str[i];
		if (str[i] == ')') {
			char el = C.Pop();
			while (el != '(') {
				postfix += el;
				el = C.Pop();
			}
			if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/') || (str[i] == '^')) {
				char el = C.Pop();
				while (Prior(el) >= Prior(str[i])) {
					postfix += el;
					el = C.Pop();
				}
			}
		}
	}
}

double TLCalc::Calc() {
	C.Clear(); D.Clear();
	string str = '(' + infix + ')';
	char* tmp;
	double res;

	for (int i = 0; i < str.size(); i++)
	{

		if (str[i] == '(') C.Push(str[i]);
		if (str[i] >= '0' && str[i] <= '9' || str[i] == '.' || str[i] == ',')
		{
			double x = strtod(&str[i], &tmp);
			int j = tmp - &str[i];
			i += j - 1;
			D.Push(x);
		}
		if (str[i] == '(' && str[i + 1] == '-')
		{
			int j = i + 1;
			str.insert(j, 1, '0');
		}
		if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*' || str[i] == '^')
		{
			char tmp = C.Pop();
			while (Prior(str[i]) <= Prior(tmp))
			{
				char op = tmp;
				tmp = C.Pop();
				if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
				{
					double op1 = D.Pop();
					double op2 = D.Pop();
					switch (op)
					{
					case '+':
						res = op1 + op2;
						break;
					case  '-':
						res = op2 - op1;
						break;
					case '*':
						res = op1 * op2;
						break;
					case '/':
						res = op2 / op1;
						break;
					case '^':
						res = pow(op2, op1);
						break;
					default:
						if (C.IsEmpty()) throw - 1;
					}
					D.Push(res);
				}
			}
			C.Push(tmp);
			C.Push(str[i]);
		}
		if (str[i] == ')')
		{
			char op = C.Pop();
			while (op != '(')
			{
				if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
				{
					double op1 = D.Pop();
					double op2 = D.Pop();
					switch (op)
					{
					case '+':
						res = op1 + op2;
						break;
					case  '-':
						res = op2 - op1;
						break;
					case '*':
						res = op1 * op2;
						break;
					case '/':
						res = op2 / op1;
						break;
					case '^':
						res = pow(op2, op1);
						break;
					default:
						if (C.IsEmpty()) throw - 1;
					}
					D.Push(res);
				}
				op = C.Pop();
			}
		}
	}
	//if (!(st_d.IsEmpty()))throw - 1;
	return D.Pop();
}//((2+5)*9)/((-1)*9)



#pragma once

template <class T>
struct TNode {
	T val;
	TNode* pNext;
};

template <class T>
class TLStack
{
	TNode<T>* pFirst;
public:
	TLStack() {
		this->pFirst = 0;
	}

	
	void Push(const T el) {
		TNode<T>* tmp = new TNode<T>;
		tmp->val = el;
		tmp->pNext = pFirst;
		pFirst = tmp;
	}

	
	T Pop() {                                     //пуш ругается сука пидор
		TNode<T>* p = pFirst;
		pFirst = pFirst->pNext;
		T res = p->val;
		delete p;
		return res;
	}

	void Clear() {
		pFirst = 0;
	}
	bool IsEmpty() {
		if (pFirst == nullptr)
			return true;
		else
			return false;
	}

	T Head()
	{
		if (IsEmpty())
		{
			throw ("Stack is empty");
		}
		return pFirst->val;
	}

	int Count() {
		int count = 0;
		TNode<T>* p;
		p = pFirst;
		while (p != nullptr) {
			count++;
			p = p->pNext;
		}
		return count;
	}

	~TLStack() {
		while (!this->IsEmpty())
			Pop();
	}
};



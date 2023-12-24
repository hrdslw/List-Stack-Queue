#pragma once
using namespace std;


template <class T>
struct TNode {
	T val;
	TNode* pNext;
};

template <class T>
class TLQueue
{
	TNode<T>* pFirst, * pLast;                //if pFirst == nullptr -> Queue is empty
	
public:

	TLQueue(const TLQueue<T>& q) {            // costuctor - copy
		TNode<T>* tmp = q.pFirst;
		TNode<T> *i;
		while (tmp != nullptr) {
			i = new TNode<T>;
			i->val = tmp->val;
			if (pFirst == nullptr){
				pFirst = i;
				pLast = i;
			}
			else {
				pLast->pNext = i;
				pLast = i;
			}
			tmp = tmp->pNext;
		}
	}

	bool IsFull() {
		TNode<T>* p = new TNode<T>;
		bool res = p == nullptr;
		delete p;
		return res;
	}

	bool IsEmpty() {
		if (pFirst == nullptr)
			return true;
		else
			return false;
	}
	
	void Push(const T& el) {
		TNode<T>* tmp = new TNode<T>;
		tmp->val = el;
		tmp->pNext = nullptr;
		if (!this->IsEmpty()) 
			pFirst = pLast = tmp;
		else
		{
			pLast->pNext = tmp;
			pLast = tmp;
		}
	}

	T Pop() {
		if (pFirst == pLast) {
			delete pFirst;
			pFirst = pLast = nullptr;
		}
		else {
			TNode<T>* tmp = pFirst;
			pFirst = pFirst->pNext;
			T res = tmp->val;
			delete tmp;
			return res;
		}
	}
};
#pragma once
#include "SortedSet.h"
#include<stack>
//DO NOT CHANGE THIS PART
class SortedSetIterator
{
	friend class SortedSet;
private:
	const SortedSet& multime;
	SortedSetIterator(const SortedSet& m);

	std::stack<PNod> inorder_stack; // stack for keeping the elements for the iterator

	PNod current; // keeping the current node
public:
	void first();
	void next();
	TElem getCurrent();
	bool valid() const;
};


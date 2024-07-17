#pragma once
//DO NOT INCLUDE SETITERATOR

//DO NOT CHANGE THIS PART
typedef int TElem;
typedef TElem TComp;
typedef bool(*Relation)(TComp, TComp);
#define NULL_TELEM -11111
class SortedSetIterator;

class Node;
// We define the type PNode as being the address of a Node
typedef Node* PNod;

//---------------------------//
class Node
{
	friend class SortedSet;
public:
	
	//constructor
	Node(TComp e, PNod left, PNod right);
	//PNod initNode(TComp e);
	TComp element();
	PNod left();
	PNod right();
private:
	TComp e;
	PNod leftNode;
	PNod rightNode;
};

class SortedSet {
	friend class SortedSetIterator;
private:
	PNod root;
	Relation rel;
	int n; //size;
public:
	//constructor
	SortedSet(Relation r);

	//adds an element to the sorted set
	//if the element was added, the operation returns true, otherwise (if the element was already in the set) 
	//it returns false
	bool add(TComp e);

	
	//removes an element from the sorted set
	//if the element was removed, it returns true, otherwise false
	PNod minimum(PNod node) const;
	PNod remove_rec(PNod node, TComp elem) const;
	bool remove(TComp e);

	//checks if an element is in the sorted set
	bool search(TComp elem) const;


	//returns the number of elements from the sorted set
	int size() const;

	//checks if the sorted set is empty
	bool isEmpty() const;

	//returns an iterator for the sorted set
	SortedSetIterator iterator() const;

	// destructor
	~SortedSet();


};

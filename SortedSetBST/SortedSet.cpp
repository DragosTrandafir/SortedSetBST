#include "SortedSet.h"
#include "SortedSetIterator.h"
#include <exception>
#include <iostream>

using namespace std; 

SortedSet::SortedSet(Relation r) {
	// BC:Tita(1) WC:Tita(1) Overall:O(1)
	this->rel = r;
	this->root = nullptr;
	n = 0;
}


PNod SortedSet::minimum(PNod node) const
{
	// max height: n-1 => O(h)~O(n)
    // BC:Tita(1) WC:Tita(h) Overall:O(h)
	PNod currentNode = node;
	if (currentNode == nullptr)
		return currentNode;
	else
	{
		while (currentNode->leftNode != nullptr)
			currentNode = currentNode->leftNode;
		return currentNode;
	}
}

PNod SortedSet::remove_rec(PNod node, TComp elem) const
{
	// max height: n-1 => O(h)~O(n)
	// BC:Tita(1) WC:Tita(h) Overall:O(h)
	if (node == nullptr)
		return node;
	else {
		if (rel(elem, node->e) && elem != node->e) {
			node->leftNode = remove_rec(node->leftNode, elem);
			return node;
		}
		else if (!rel(elem, node->e) && elem!=node->e) {
			node->rightNode = remove_rec(node->rightNode, elem);
			return node;
		}
		else {
			if (node->leftNode != nullptr && node->rightNode != nullptr) {
				PNod temp = minimum(node->rightNode);
				node->e = temp->e;
				node->rightNode = remove_rec(node->rightNode, node->e);
				return node;
			}
			else if (node->leftNode == nullptr)
				return node->rightNode;
			else
				return node->leftNode;
		}
	}
}

bool SortedSet::remove(TComp elem) {
	// max height: n-1 => O(h)~O(n)
    // BC:Tita(1) WC:Tita(h) Overall:O(h)
	if (search(elem)) {
		this->root = remove_rec(root, elem);
		n--;
		return true;
	}
	return false;
}


bool SortedSet::add(TComp elem) {
	// max height: n-1 => O(h)~O(n)
	// BC:Tita(1) WC:Tita(h) Overall:O(h)

	if (search(elem)) {
		return false;
	}

	PNod prev = nullptr;
	PNod currentNode = root;
	PNod newNode = new Node(elem, nullptr, nullptr);

	while (currentNode != nullptr) {
		prev = currentNode;
		if (!rel(currentNode->e, elem))
			currentNode = currentNode->leftNode;
		else
			currentNode = currentNode->rightNode;
	}

	if (root == nullptr) {
		root = newNode;
	}
	else if (rel(elem, prev->e)) {
		prev->leftNode = newNode;
	}
	else {
		prev->rightNode = newNode;
	}

	n++; 
	return true;
}

bool SortedSet::search(TComp elem) const {
	// max height: n-1 => O(h)~O(n)
	// BC:Tita(1) WC:Tita(h) Overall:O(h)
	PNod currentNode = root;
	bool found = false;
	while (currentNode != nullptr && !found) {
		if (currentNode->e == elem)
			found = true;
		else if (rel(currentNode->e, elem))
			currentNode = currentNode->rightNode;
		else
			currentNode = currentNode->leftNode;
	}
	return found;
}


int SortedSet::size() const {
	// BC:Tita(1) WC:Tita(1) Overall:O(1)
	return n;
}



bool SortedSet::isEmpty() const {
	// BC:Tita(1) WC:Tita(1) Overall:O(1)
	return this->root == nullptr;
}

SortedSetIterator SortedSet::iterator() const {
	// BC:Tita(1) WC:Tita(1) Overall:O(1)
	return SortedSetIterator(*this);
}


SortedSet::~SortedSet() {
}

Node::Node(TComp e, PNod left, PNod right)
{
	// BC:Tita(1) WC:Tita(1) Overall:O(1)
	this->e = e;
	this->leftNode = left;
	this->rightNode = right;
}


TComp Node::element()
{
	// BC:Tita(1) WC:Tita(1) Overall:O(1)
	return this->e;
}

PNod Node::left()
{
	// BC:Tita(1) WC : Tita(1) Overall : O(1)
	return leftNode;
}

PNod Node::right()
{
	// BC:Tita(1) WC:Tita(1) Overall:O(1)
	return rightNode;
}

#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m)
{
	// BC:Tita(1) WC:Tita(n) Overall:O(n)
	PNod node = multime.root;
	while (node != nullptr)
	{
		inorder_stack.push(node);
		node = node->left();
	}
	if (!inorder_stack.empty())
		current = inorder_stack.top();
	else
		current = nullptr;
}


void SortedSetIterator::first() {

	// BC:Tita(1) WC:Tita(n) Overall:O(n)

	// Clear the stack
	while (!inorder_stack.empty()) {
		inorder_stack.pop();
	}

	// Reinitialize the stack with the leftmost path from the root
	PNod node = multime.root;
	while (node != nullptr) {
		inorder_stack.push(node);
		node = node->left();
	}

	// Set the current pointer
	if (!inorder_stack.empty())
		current = inorder_stack.top();
	else
		current = nullptr;
}


void SortedSetIterator::next() {
	// BC:Tita(1) WC:Tita(n) Overall:O(n)
	if (!valid()) {
		throw exception();
	}
	PNod node = inorder_stack.top();
	inorder_stack.pop();
	if (node->right() != nullptr) {
		node = node->right();
		while (node != nullptr)
		{
			inorder_stack.push(node);
			node = node->left();
		}
	}
	if (!inorder_stack.empty())
		current = inorder_stack.top();
	else
		current = nullptr;
}


TElem SortedSetIterator::getCurrent()
{
	// BC:Tita(1) WC:Tita(1) Overall:O(1)
	if (!valid()) 
		throw exception();
	return current->element();
}

bool SortedSetIterator::valid() const {
	// BC:Tita(1) WC:Tita(1) Overall:O(1)
	return (current != nullptr);
}


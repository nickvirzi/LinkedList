// LinkedList.cpp : Defines the exported functions for the DLL application.
//

#include "header.h"
#include "LinkedList.h"
#include <iostream>

Node::Node() : m_value(-1), m_next(nullptr)
{

}
Node::Node(int val) : m_value(val), m_next(nullptr)
{

}
Node::Node(int val, Node * nextNode) : m_value(val), m_next(nextNode)
{

}
void Node::setItem(const int& val)
{
	m_value = val;
}
void Node::setNext(Node* nextNodePtr)
{
	m_next = nextNodePtr;
}
int Node::getItem() const
{
	return m_value;
}
Node * Node::getNext() const
{
	return m_next;
}
Node::~Node()
{
	std::cout << "Deleting node with value " << m_value << std::endl;
	delete m_next;
}

PointerBasedLinkedList::PointerBasedLinkedList()
{
	m_head = new Node(NULL, nullptr);
	m_count = 0;
}
/** Returns true  if list is empty, otherwise true */
bool PointerBasedLinkedList::isEmpty() const
{
	return m_count == 0;
}
/** Adds a value to the LinkedList.  Return true if able to, otherwise false */
bool PointerBasedLinkedList::add(int val)
{
	Node * newNode = new Node;
	newNode->setItem(val);
	newNode->setNext(m_head);
	m_head = newNode;
	m_count++;
	return true;
}

Node * PointerBasedLinkedList::getPointerTo(const int val) const
{
	Node * curNode = m_head;
	int count = 0;
	while ((curNode != nullptr) && (count < m_count))
	{
		int temp = curNode->getItem();
		if (val == temp)
		{
			count++;
			return curNode;
		}
		else
		{
			curNode = curNode->getNext();
			count++;
			if (count == m_count) {
				return nullptr;
			}
		}
	}
}

/** Remove a value to the LinkedList.  Return true if able to, otherwise false.
Will only remove one entry if there are multiple entries with the same value */
bool PointerBasedLinkedList::remove(int val)
{
	Node * prev = m_head;
	Node * temp = m_head->getNext();

	while (temp != NULL)
	{
		if (temp->getItem() == val) 
		{
			break;
		}
		else
		{
			prev = temp;
			temp = temp->getNext();
		}
	}
	if (temp == NULL)
	{
		return false;
	}
	else
	{
		prev->setNext(temp->getNext());
		return true;
	}
}

/** Remove  all elements from LinkedList */
void PointerBasedLinkedList::clear()
{
	Node * nodeDelete = new Node;
	while (m_head != nullptr) {
		m_head = m_head->getNext();
		nodeDelete->setNext(nullptr);
		delete nodeDelete;
		nodeDelete = m_head;
	}
	m_count = 0;
}
PointerBasedLinkedList::~PointerBasedLinkedList()
{
	delete m_head;
}

std::string PointerBasedLinkedList::toString() const
{
	std::string output = "";
	Node * curNode = m_head;
	Node * indexNode = m_head;
	int count = 0;
	int count2 = 0;
	while (indexNode != nullptr)
	{
		indexNode = indexNode->getNext();
		count2++;
	}
	count2--;
	while ((curNode != nullptr) && (count < count2))
	{
		if (count == count2 - 1)
		{
			output = std::to_string((curNode->getItem())) + output;
			curNode = curNode->getNext();
			count++;
		}
		else
		{
			output = std::to_string((curNode->getItem())) + output;
			output = " " + output;
			curNode = curNode->getNext();
			count++;
		}
	}
	return output;
}

ArrayBasedLinkedList::ArrayBasedLinkedList()
{
	m_count = 0;
	m_values[10];
}

bool ArrayBasedLinkedList::isEmpty() const
{
	if (m_count == 0) {
		return true;
	}
	else
	{
		return false;
	}
}
bool ArrayBasedLinkedList::add(int val)
{
	if (m_count + 1 <= std::size(m_values)) {
		m_values[m_count] = val;
		m_count++;
		return true;
	}
	return false;
}
bool ArrayBasedLinkedList::remove(int val)
{
	for (int i = 0; i < m_count; i++) {
		if (m_values[i] == val) {
			m_values[i] = INT_MIN;
			return true;
		}
	}
	return false;
}
void ArrayBasedLinkedList::clear()
{
	for (int i = 0; i < std::size(m_values); i++)
	{
		m_values[i] = INT_MIN;
		m_count = 0;
	}
}
ArrayBasedLinkedList::~ArrayBasedLinkedList()
{

}

std::string ArrayBasedLinkedList::toString() const
{
	std::string output = "";
	for (int i = 0; i < m_count; i++) {
		if (i < std::size(m_values) - 1) {
			if (m_values[i] > -1000) {
				output += std::to_string(m_values[i]);
				output += " ";
			}
		}
		else if (i == std::size(m_values) - 1)
		{
			if (m_values[i] > -1000) {
				output += std::to_string(m_values[i]);
			}
		}
	}
	return output;
}
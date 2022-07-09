#include <iostream>

#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList()
	: _head(nullptr)
	, _tail(nullptr)
{

}

DoublyLinkedList::~DoublyLinkedList()
{
	clear();
}

void DoublyLinkedList::clear()
{
	Node* tmp = nullptr;

	while (_head != nullptr)
	{
		tmp = _head->next;
		delete _head;
		_head = tmp;
	}

	_tail = nullptr;
}

void DoublyLinkedList::insertFront(int value)
{
	//utworzenie nowego wêz³a, ustawiamy prev na nullptr, poniewa¿ pierwszy element listy nie ma poprzednika
	Node* newNode = new Node();
	newNode->data = value;
	newNode->prev = nullptr;

	//kopiujemy wskaznik na pierwszy element (ten ktory wskazuje _head), robimy to najpierw zeby nie stracic uchywtu do listy
	newNode->next = _head;

	//ustawiamy wskaznik poczatku listy na nasz nowo utworzony weze³
	_head = newNode;
}

void DoublyLinkedList::print() const
{
	Node* tmp = _head;

	while (tmp != nullptr) //przechodzenie listy - odwiedzanie wszytkich wez³ów (ang. traverse)
	{
		std::cout << tmp->data << "<->";
		tmp = tmp->next;
	}

	std::cout << "nullptr";
}

unsigned int DoublyLinkedList::size() const //dla przykladu policzymy elementy od konca
{
	Node* tmp = _tail;
	unsigned int size = 0;

	while (tmp != nullptr) //przechodzenie listy - odwiedzanie wszytkich wez³ów (ang. traverse)
	{
		++size;
		tmp = tmp->prev;
	}

	return size;
}

void DoublyLinkedList::insertAfter(int value, const unsigned int position)
{
	Node* tmp = _head;
	unsigned int index = 0;

	while (tmp != nullptr && index != position) //przechodzenie listy - odwiedzanie wszytkich wez³ów (ang. traverse)
	{
		++index;
		tmp = tmp->prev;
	}


}
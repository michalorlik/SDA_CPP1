#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList()
	: _head(nullptr)
	, _tail(nullptr)
{

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

}
#pragma once
class DoublyLinkedList
{
public:
	DoublyLinkedList();
	virtual ~DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList& other)=delete; // zabronienie kompulatorowi generowanie domyslnego copy c-tora 

	unsigned int size() const; //policz ilosc elementow w liscie
	bool empty() const;
	void print() const;

	void insertFront(int value); //wstaw wartosc na poczatek
	void insertBack(int value); //wstaw wartosc na koniec
	void insertAfter(int value, const unsigned int position); //wstaw wartosc w dowolnym miejscu

	void removeValue(int value);
	void remove(const unsigned int position);
	void clear();

	int& operator[](const unsigned int index) const;

	//praca domowa:
	//merge
	//splice

private:
	struct Node
	{
		int data;
		Node* next;
		Node* prev;
	};

	Node* _head;
	Node* _tail;

	//DoublyLinkedList(const DoublyLinkedList& other); //zabronienei copy c-tora w starym c++ (przed 11)
	DoublyLinkedList& operator=(DoublyLinkedList& other);
};


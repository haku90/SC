/********************************************//**
 * \file   event_scheduling.cpp
 * \brief  Implementacja listy zdarzen.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-05-08
 ***********************************************/
#include "e4_rk_ha.h"
/////////////////////////////////////////////////
template <class object> void link<object>::follow(link* item)
{
	this->prev = item;			// Item staje siê obiektem poprzedzaj¹cym.
	this->next = item->next;	// Nastêpny dla tego, za ktory wstawiamy obecny uzna za nastêpny.
	item->next = this->next->prev = this;
}
//----------------------------------------------
template <class object> void link<object>::remove()
{
	prev->next=this->next;
	next->prev=this->prev;
	delete this;
}
//===============================================
event_list::event_list()
{
	head = new link<event>(new nil());
}
//----------------------------------------------
event* event_list::first()
{
	return head->next->data;
}
//----------------------------------------------
event* event_list::remove_first()
{
	event* current = first();      // Wskaznik na pierwsze zdarzenie w liscie.
	head->next->remove();		   // Usuniecie wskazanego obiektu kalsy link.
	return current;
}
//----------------------------------------------
void event_list::schedule(event * to_occur)
{
	link<event>* n = NULL;

	// Przeszukiwanie od konca.
	for(n = head->prev; n->data->event_time > to_occur->event_time; n = n->prev);
	
	(new link<event>(to_occur))->follow(n);
}
//----------------------------------------------
bool event_list::empty()
{
	return head->next == head;
}
//----------------------------------------------
void event_list::make_empty()
{
	while(!empty()) delete this->remove_first();
}
/////////////////////////////////////////////////
//***********************************************

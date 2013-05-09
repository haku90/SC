/********************************************//**
 * \file   event_scheduling.h
 * \brief  Implementacja listy zdarzen.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-05-08
 ***********************************************/
#ifndef EVENT_SCHEDULING_H
#define EVENT_SCHEDULING_H
/////////////////////////////////////////////////
class process;
//----------------------------------------------
/*! \brief Zdarzenie.
 *
 *	Klasa event reprezentuje zdarzenie czasowe.
 *
 */
struct event
{
	//! Konstruktor.
	event(process  * ptr): event_time(-1.0), proc(ptr){}

	double event_time; //!< Zmienna przechowuj¹ca czas wyst¹pienia zdarzenia.

	process * proc;	   //!< Wskaznik na process.
};
//----------------------------------------------
// Deklaracja szablonu klasy link odpowiedzialnego za przechowywanie elementów w liœcie i powi¹zanie jej elementów
template <class object> class link;
//----------------------------------------------
/*! \brief Lista zdarzen.
 *
 *	Implementacja listy zdarzen.
 *
 */
class event_list
{
public:
	//! Konstruktor.
	event_list();

	event* first();			//! Zwraca wskaznik do pierszego zdarzenia na liscie.

	event* remove_first();	//! Usuwa pierwsze zdarzenie z listy i zwraca wskaznik do niego.

	void schedule(event*);	//! Metoda odpowiedzialna za wstawienie nowego zdarzenia do listy.

	bool empty();			//! Informuje czy lista jest pusta.

	void make_empty();		//! Po tej operacji lista jest pusta.

private:
	
	link<event>* head;		//! Wskaznik na pierwszy element listy.
};
//----------------------------------------------
template <class object> class link
{
	friend class event_list;

public:
	link(object* ptr): data(ptr) {next=prev=this;}

	void follow(link* item);	//! Wstawienie obiektu link na liste za podany obiekt.
	void remove();				//! Usuniêcie obiektu link z listy. Funkcja usuwa obiet, na rzecz ktorego jest wywolana.

private:

	link<object>* next;	//! Wskaznik na nastêpny obiekt link w liscie.
	link<object>* prev;	//! Wskaznik na poprzedni obiekt link w liscie.
	object* data;		//! Wskaznik do przechowywanego obiektu.
};
//----------------------------------------------
/*! \brief Pusty obiekt listy.
 *
 *	Implementacja stalego obiektu na liscie zdarzen.
 *
 */
struct nil: public event
{
	nil(process * ptr = NULL): event(ptr){}
};
/////////////////////////////////////////////////
//***********************************************
#endif /*EVENT_SCHEDULING_H*/
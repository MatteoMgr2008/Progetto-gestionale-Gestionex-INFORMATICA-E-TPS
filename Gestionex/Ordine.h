#pragma once

#include <string>
#include <list>
#include "ArticoliDellOrdine.h"
using namespace std;

class Ordine
{
	private:
		string ID_track;
		int statoOrdine;
		list<ArticoliDellOrdine> listaArticoli;

	public:
		Ordine(string id, int stato,list<ArticoliDellOrdine> &listaArticoli);
		~Ordine();
		string getID_track();
		string getStatoOrdineString();
		int getStatoOrdine();
		void setStatoOrdine(int stato);
		void setID_track(string id);
		list<ArticoliDellOrdine> getListaArticoli();
		
};

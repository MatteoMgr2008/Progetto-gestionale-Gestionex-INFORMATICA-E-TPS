#pragma once
#include <string>
#include <list>
#include "ArticoliDellOrdine.h"
#include "ArticoliDelloStock.h"

using namespace std;

class Stock
{
private:
	string nomeStock;
	int numeroSlotMagazzino;
	float spazioTotale;
	float spazioOccupato;
	list<ArticoliDelloStock> listaArticoliDelloStock;

public:
	Stock();
	Stock(string nomeStock, int numeroSlotMagazzino, float spazioTotale, float spazioOccupato);
	~Stock();
	void setSpazioOccupato(float spazioOccupato);
	void setArticoliDelloStock(list<ArticoliDellOrdine> listaArticoli);
	float getSpazioOccupato();
	float getSpazioTotale();
	list<ArticoliDelloStock>& getArticoliDelloStock();
	void liberaStock();
	string getInfoStock();

};
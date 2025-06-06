#include "Stock.h"

// Costruttore di default
Stock::Stock()
{
	this->nomeStock = "";
	this->numeroSlotMagazzino = 0;
	this->spazioTotale = 0;
	this->spazioOccupato = 0;
}

// Costruttore con parametri
Stock::Stock(string nomeStock, int numeroSlotMagazzino, float spazioTotale, float spazioOccupato)
{
	this->nomeStock = nomeStock;
	this->numeroSlotMagazzino = numeroSlotMagazzino;
	this->spazioTotale = spazioTotale;
	this->spazioOccupato = spazioOccupato;
}

// Distruttore
Stock::~Stock()
{
	// Il distruttore non fa nulla di fatto, ma è presente per completezza
}

void Stock::setSpazioOccupato(float spazioOccupato)
{
	this->spazioOccupato = spazioOccupato;
}

// Imposta la lista finale degli articoli dello stock
void Stock::setArticoliDelloStock(list<ArticoliDellOrdine> listaArticoli)
{
	for (auto& articolo : listaArticoli) {
		// Aggiungi ogni articolo alla lista degli articoli dello stock
		this->listaArticoliDelloStock.push_back(ArticoliDelloStock(articolo.getArticolo(), articolo.getQuantita()));
		this->spazioOccupato += articolo.getArticolo().getSpazioOccupato() * articolo.getQuantita();
	}
}

void Stock::liberaStock()
{
	// Libera (ripulisce) lo stock
	this->spazioOccupato = 0;
	this->spazioTotale = 0;
	this->numeroSlotMagazzino = 0;
	this->nomeStock = "";
}

string Stock::getInfoStock()
{
	return this->nomeStock;
}

float Stock::getSpazioOccupato()
{
	return this->spazioOccupato;
}

float Stock::getSpazioTotale()
{
	return this->spazioTotale;
}

// Restituisce gli articoli dello stock selezionato di un magazzino esistente
list<ArticoliDelloStock>& Stock::getArticoliDelloStock()
{
	return this->listaArticoliDelloStock;
}
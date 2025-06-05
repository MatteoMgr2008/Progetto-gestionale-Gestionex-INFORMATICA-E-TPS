#include "Magazzino.h"

// Costruttore con parametri
Magazzino::Magazzino(int id, string nome, string indirizzo, string citta, string provincia, string cap, string telefono, string email, float spazioOccupato, float spazioTotale)
{
	this->id = id;
	this->nome = nome;
	this->indirizzo = indirizzo;
	this->citta = citta;
	this->provincia = provincia;
	this->cap = cap;
	this->telefono = telefono;
	this->email = email;
	this->spazioOccupato = spazioOccupato;
	this->spazioTotale = spazioTotale;
}

Magazzino::Magazzino(int id, string nome)
{
	this->id = id;
	this->nome = nome;
	this->indirizzo = "";
	this->citta = "";
	this->provincia = "";
	this->cap = "";
	this->telefono = "";
	this->email = "";
	this->spazioOccupato = 0.0f;
	this->spazioTotale = 100.0f;
}

// Distruttore
Magazzino::~Magazzino()
{
	// Il distruttore non fa nulla di fatto, ma è presente per completezza
}

// Metodi getter della classe
string Magazzino::getNome() const
{
	return this->nome;
}

void Magazzino::aggiungiStock(Stock stock)
{
	if (this->spazioOccupato + stock.getSpazioTotale() <= this->spazioTotale) {
		this->stockList.push_back(stock);
		this->spazioOccupato += stock.getSpazioTotale();
	}
}

float Magazzino::getSpazioOccupato()
{
	return this->spazioOccupato;
}

float Magazzino::getSpazioTotale()
{
	return this->spazioTotale;
}

int Magazzino::getNumeroStockMagazzino()
{
	return this->stockList.size();
}

vector<Stock>& Magazzino::getStockList()
{
	return this->stockList;
}

void Magazzino::rimuoviStock(Stock stock)
{
	for (auto it = stockList.begin(); it != stockList.end(); ++it) {
		if (it->getInfoStock() == stock.getInfoStock()) {
			this->spazioOccupato -= it->getSpazioTotale();
			stockList.erase(it);
			break;
		}
	}
}
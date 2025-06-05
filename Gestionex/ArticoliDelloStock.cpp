#include "ArticoliDelloStock.h"

// Costruttore della classe ArticoliDelloStock
ArticoliDelloStock::ArticoliDelloStock(Articolo articolo, int quantita)
{
	this->articolo = articolo;
	this->quantita = quantita;
}

// Distruttore della classe ArticoliDelloStock
ArticoliDelloStock::~ArticoliDelloStock()
{
	// Il distruttore non fa nulla di fatto, ma è presente per completezza
}

// Metodi getter della classe
Articolo ArticoliDelloStock::getArticolo()
{
	return this->articolo;
}

int ArticoliDelloStock::getQuantita()
{
	return this->quantita;
}

// Metodi setter della classe
void ArticoliDelloStock::setArticolo(Articolo articolo)
{
	this->articolo = articolo;
}

void ArticoliDelloStock::setQuantita(int quantita)
{
	this->quantita = quantita;
}


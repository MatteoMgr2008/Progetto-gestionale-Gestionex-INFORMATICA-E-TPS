#include "ArticoliDellOrdine.h"
#include "Articolo.h"

ArticoliDellOrdine::ArticoliDellOrdine(Articolo articolo, int quantita)
{
	this->articolo = articolo;
	this->quantita = quantita;
}

// Distruttore
ArticoliDellOrdine::~ArticoliDellOrdine()
{
	// Il distruttore non fa nulla di fatto, ma è presente per completezza
}

// Metodi getter della classe
Articolo ArticoliDellOrdine::getArticolo()
{
	return this->articolo;
}

int ArticoliDellOrdine::getQuantita()
{
	return this->quantita;
}

// Metodi setter della classe
void ArticoliDellOrdine::setArticolo(Articolo articolo)
{
	this->articolo = articolo;
}

void ArticoliDellOrdine::setQuantita(int quantita)
{
	this->quantita = quantita;
}
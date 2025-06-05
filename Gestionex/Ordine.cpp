#include "Ordine.h"

// Costruttore con parametri
Ordine::Ordine(string id, int stato, list<ArticoliDellOrdine> &listaArticoli)
{
	this->ID_track = id;
	this->statoOrdine = stato;
	this->listaArticoli = listaArticoli;
}

// Distruttore
Ordine::~Ordine()
{
	// Il distruttore non fa nulla di fatto, ma è presente per completezza
}

string Ordine::getID_track()
{
	return this->ID_track;
}

int Ordine::getStatoOrdine()
{
	return this->statoOrdine;
}

string Ordine::getStatoOrdineString()
{
	switch (this->statoOrdine)
	{
	case 0:
		return "In attesa";
	case 1:
		return "Arrivato";
	case 2:
		return "Annullato";
	case 3:
		return "In attesa di controllo";
	case 4:
		return "Articoli in stoccaggio";
	case 5:
		return "Completato";
	default:
		return "Stato sconosciuto";
	}
}

void Ordine::setStatoOrdine(int stato)
{
	this->statoOrdine = stato;

	if (stato >= 0 && stato <= 5)
	{
		this->statoOrdine = stato; // Limita lo stato dell'ordine ad avere un valore incluso tra 0 e 5
	}
}

void Ordine::setID_track(string id)
{
	this->ID_track = id;
}

list<ArticoliDellOrdine> Ordine::getListaArticoli()
{
	return this->listaArticoli;
}
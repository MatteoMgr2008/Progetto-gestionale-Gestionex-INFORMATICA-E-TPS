#include "Articolo.h"

//Costruttore di default
Articolo::Articolo()
{
	this->nome = "";
	this->ID_articolo = "";
	this->ID_ordine = "";
	this->spazioOccupato = 0.0f;
	this->peso = 0.0f;
	this->prezzo = 0.0f;
}

//Costruttore con parametri
Articolo::Articolo(string nome, string ID_articolo, string ID_ordine, float spazioOccupato, float peso, float prezzo)
{
	this->nome = nome;
	this->ID_articolo = ID_articolo;
	this->ID_ordine = ID_ordine;
	this->spazioOccupato = spazioOccupato;
	this->peso = peso;
	this->prezzo = prezzo;
}

Articolo::~Articolo()
{
	// Il distruttore non fa nulla di fatto, ma è presente per completezza
}

// Metodi getter della classe
string Articolo::getInfoArticoli()
{
	return "Nome articolo: "+this->nome + " " + "| ID articolo: "+this->ID_articolo + " " + "| ID Tracking: "+this->ID_ordine;
}

string Articolo::getNomeArticolo()
{
	return this->nome;
}

string Articolo::getIDArticolo()
{
	return this->ID_articolo;
}

string Articolo::getIDOrdine()
{
	return this->ID_ordine;
}

float Articolo::getSpazioOccupato()
{
	return this->spazioOccupato;
}

float Articolo::getPeso()
{
	return this->peso;
}

float Articolo::getPrezzo()
{
	return this->prezzo;

}

// Metodi setter della classe
void Articolo::setInfoArticolo(string nome, string ID_articolo)
{
	this->nome = nome;
	this->ID_articolo = ID_articolo;
	this->ID_ordine = ID_ordine;
}

void Articolo::setSpazioOccupato(float spazioOccupato)
{
	this->spazioOccupato = spazioOccupato;
}

void Articolo::setPeso(float peso)
{
	this->peso = peso;
}

void Articolo::setPrezzo(float prezzo)
{
	this->prezzo = prezzo;
}
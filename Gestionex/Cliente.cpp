#include "Cliente.h"
using namespace std;
//construttore

//costruttore di default
Cliente::Cliente()
{
	this->nome = "";
	this->cognome = "";
	this->indirizzo = "";
	this->citta = "";
	this->provincia = "";
	this->CAP = "";
	this->telefono = "";
	this->email = "";
	this->partitaIVA = "";
}

Cliente::Cliente(string nome, string cognome, string indirizzo, string citta, string provincia,
	string CAP, string telefono, string email, string partitaIVA)
{
	this->nome = nome;
	this->cognome = cognome;
	this->indirizzo = indirizzo;
	this->citta = citta;
	this->provincia = provincia;
	this->CAP = CAP;
	this->telefono = telefono;
	this->email = email;
	this->partitaIVA = partitaIVA;
}

//destruttore
Cliente::~Cliente()
{
	// Destructor
}

string Cliente::getNome()
{
	return this->nome;
}

string Cliente::getCognome()
{
	return this->cognome;
}

string Cliente::getIndirizzo()
{
	return this->indirizzo;
}

string Cliente::getCitta()
{
	return this->citta;
}

string Cliente::getProvincia()
{
	return this->provincia;
}

string Cliente::getCAP()
{
	return this->CAP;
}

string Cliente::getTelefono()
{
	return this->telefono;
}

string Cliente::getEmail()
{
	return this->email;
}

string Cliente::getPartitaIVA()
{
	return this->partitaIVA;
}

void Cliente::setNome(string nome)
{
	this->nome = nome;
}

void Cliente::setCognome(string cognome)
{
	this->cognome = cognome;
}

void Cliente::setIndirizzo(string indirizzo)
{
	this->indirizzo = indirizzo;
}

void Cliente::setCitta(string citta)
{
	this->citta = citta;
}

void Cliente::setProvincia(string provincia)
{
	this->provincia = provincia;
}

void Cliente::setCAP(string CAP)
{
	this->CAP = CAP;
}

void Cliente::setTelefono(string telefono)
{
	this->telefono = telefono;
}

void Cliente::setEmail(string email)
{
	this->email = email;
}

void Cliente::setPartitaIVA(string partitaIVA)
{
	this->partitaIVA = partitaIVA;
}


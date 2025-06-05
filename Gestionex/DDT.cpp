#include "DDT.h"
#include "Cliente.h"

DDT::DDT(int numero, string data, string ora) : numero(numero), data(data), ora(ora)
{
	// Constructor
	this->mittente = Cliente();
	this->destinatario = Cliente();
	this->causaleTrasporo = "";
}

DDT::~DDT()
{
	// Destructor
}
int DDT::getNumero()
{
	return this->numero;
}
string DDT::getData()
{
	return this->data;
}
string DDT::getOra()
{
	return this->ora;
}
void DDT::setNumero(int numero)
{
	this->numero = numero;
}
void DDT::setData(string data)
{
	this->data = data;
}
void DDT::setOra(string ora)
{
	this->ora = ora;
}


#include "OrdineEntrata.h"

// crea costruttore per classe derivata in modo classico e chiaro
OrdineEntrata::OrdineEntrata(string id, int stato, list<ArticoliDellOrdine>& listaArticoli, string dataRicezione, bool checkDanno, bool checkDocumento)
	: Ordine(id, stato, listaArticoli), dataRicezione(dataRicezione), checkDanno(checkDanno), checkDocumento(checkDocumento)
{
}


OrdineEntrata::~OrdineEntrata()
{
}

string OrdineEntrata::getDataRicezione()
{
	return this->dataRicezione;
}

bool& OrdineEntrata::getCheckDanno()
{
	return this->checkDanno;
}

bool& OrdineEntrata::getCheckDocumento()
{
	return this->checkDocumento;
}

void OrdineEntrata::setDataRicezione(string dataRicezione)
{
	this->dataRicezione = dataRicezione;
}

void OrdineEntrata::setCheckDanno(bool checkDanno)
{
	this->checkDanno = checkDanno;
}

void OrdineEntrata::setCheckDocumento(bool checkDocumento)
{
	this->checkDocumento = checkDocumento;
}

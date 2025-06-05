#include "OrdineUscita.h"

OrdineUscita::OrdineUscita(string id, int stato, list<ArticoliDellOrdine>& listaArticoli, string dataSpedizione, bool checkDanno, bool checkDocumento)
	: Ordine(id, stato, listaArticoli), dataSpedizione(dataSpedizione), checkDanno(checkDanno), checkDocumento(checkDocumento)
{
}

OrdineUscita::~OrdineUscita()
{
}

string OrdineUscita::getDataSpedizione()
{
	return this->dataSpedizione;
}

bool& OrdineUscita::getCheckDanno()
{
	return this->checkDanno;
}

bool& OrdineUscita::getCheckDocumento()
{
	return this->checkDocumento;
}

void OrdineUscita::setDataSpedizione(string dataSpedizione)
{
	this->dataSpedizione = dataSpedizione;
}

void OrdineUscita::setCheckDanno(bool checkDanno)
{
	this->checkDanno = checkDanno;
}

void OrdineUscita::setCheckDocumento(bool checkDocumento)
{
	this->checkDocumento = checkDocumento;
}



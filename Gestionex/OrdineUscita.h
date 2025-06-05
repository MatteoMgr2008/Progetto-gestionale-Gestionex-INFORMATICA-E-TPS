#pragma once

#include "Ordine.h"

using namespace std;
class OrdineUscita : public Ordine
{
private:
	string dataSpedizione;
	bool checkDanno;
    bool checkDocumento; 
public:
	OrdineUscita(string id, int stato, list<ArticoliDellOrdine>& listaArticoli, string dataSpedizione, bool checkDanno, bool checkDocumento);
	~OrdineUscita();
	string getDataSpedizione();
	bool& getCheckDanno();
	bool& getCheckDocumento();
	void setDataSpedizione(string dataSpedizione);
	void setCheckDanno(bool checkDanno);
	void setCheckDocumento(bool checkDocumento);

};


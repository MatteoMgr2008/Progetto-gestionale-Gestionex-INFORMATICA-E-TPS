#pragma once
#include "Ordine.h"

using namespace std;

class OrdineEntrata : public Ordine
{
private:
	string dataRicezione;
	bool checkDanno;
	bool checkDocumento;

public:
	OrdineEntrata(string id, int stato, list<ArticoliDellOrdine>& listaArticoli, string dataRicezione, bool checkDanno, bool checkDocumento);
	~OrdineEntrata();
	string getDataRicezione();
	bool& getCheckDanno();
	bool& getCheckDocumento();
	void setDataRicezione(string dataRicezione);
	void setCheckDanno(bool checkDanno);
	void setCheckDocumento(bool checkDocumento);
};

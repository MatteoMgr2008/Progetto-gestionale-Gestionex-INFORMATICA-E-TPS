#pragma once
#include "Articolo.h"

class ArticoliDelloStock
{
private:
	int quantita;
	Articolo articolo;
public:
	ArticoliDelloStock(Articolo articolo, int quantita);
	~ArticoliDelloStock();
	Articolo getArticolo();
	void setArticolo(Articolo articolo);
	void setQuantita(int quantita);
	int getQuantita();

};


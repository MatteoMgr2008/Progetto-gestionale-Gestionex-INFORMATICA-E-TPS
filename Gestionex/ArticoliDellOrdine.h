#pragma once  
#include "../Gestionex/Articolo.h"
#include <list>

using namespace std;
class ArticoliDellOrdine  
{  
private:  
   int quantita;  
   Articolo articolo;
public:  
	ArticoliDellOrdine(Articolo articolo, int quantita);
	~ArticoliDellOrdine();
	Articolo getArticolo();
	void setArticolo(Articolo articolo);
	void setQuantita(int quantita);
	int getQuantita();
};
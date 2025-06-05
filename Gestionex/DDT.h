#pragma once
#include <string>
#include "Cliente.h"

using namespace std;

class DDT
{
private:
	int numero;
	string data;
	string ora;
	Cliente mittente;
	Cliente destinatario;
	string causaleTrasporo;
public:
	DDT(int numero, string data, string ora);
	~DDT();
	int getNumero();
	string getData();
	string getOra();
	void setNumero(int numero);
	void setData(string data);
	void setOra(string ora);
};
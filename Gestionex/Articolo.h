#pragma once
#include <string>

using namespace std;

class Articolo
{
private:
	string nome;
	string ID_articolo;
	string ID_ordine;
	float spazioOccupato;
	float peso;
	float prezzo;
public:
	Articolo(); // Costruttore di default
	Articolo(string nome, string ID_articolo, string ID_ordine, float spazioOccupato, float peso, float prezzo); // Costruttore con parametri
	~Articolo();
	string getInfoArticoli();
	string getNomeArticolo();
	string getIDArticolo();
	string getIDOrdine();
	float getSpazioOccupato();
	float getPeso();
	float getPrezzo();
	void setInfoArticolo(string nome, string ID_articolo);
	void setSpazioOccupato(float spazioOccupato);
	void setPeso(float peso);
	void setPrezzo(float prezzo);
};
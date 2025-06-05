#pragma once
#include "Stock.h"
#include <string>
#include <list>
#include <vector>

using namespace std;

class Magazzino
{
private:
	int id;
	string nome;
	string indirizzo;
	string citta;
	string provincia;
	string cap;
	string telefono;
	string email;
	float spazioOccupato;
	float spazioTotale;
	vector<Stock> stockList;
public:
	// Constructor
	Magazzino(int id, string nome, string indirizzo, string citta, string provincia, string cap, string telefono, string email, float spazioLibero, float spazioTotale);
	Magazzino(int id, string nome);
	~Magazzino();
	// Getters
    string getNome() const;
	void aggiungiStock(Stock stock);
	float getSpazioOccupato();
	float getSpazioTotale();
	int getNumeroStockMagazzino();
	vector<Stock>& getStockList();
	void rimuoviStock(Stock stock);
};
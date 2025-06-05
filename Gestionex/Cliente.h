#pragma once
#include <string>

class Cliente
{
private:
	std::string nome;
	std::string cognome;
	std::string indirizzo;
	std::string citta;
	std::string provincia;
	std::string CAP;
	std::string telefono;
	std::string email;
	std::string partitaIVA;

public:
	Cliente();
	Cliente(std::string nome, std::string cognome, std::string indirizzo, std::string citta, std::string provincia,
		std::string CAP, std::string telefono, std::string email, std::string partitaIVA);
	~Cliente();
	std::string getNome();
	std::string getCognome();
	std::string getIndirizzo();
	std::string getCitta();
	std::string getProvincia();
	std::string getCAP();
	std::string getTelefono();
	std::string getEmail();
	std::string getPartitaIVA();
	void setNome(std::string nome);
	void setCognome(std::string cognome);
	void setIndirizzo(std::string indirizzo);
	void setCitta(std::string citta);
	void setProvincia(std::string provincia);
	void setCAP(std::string CAP);
	void setTelefono(std::string telefono);
	void setEmail(std::string email);
	void setPartitaIVA(std::string partitaIVA);
};


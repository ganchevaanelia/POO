#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

//clase abstracte sunt folosite pt a pastra un anumit pattern
class ScriereCitire //clasa abstracta
{ 
public:
	//fct virtual pure
	virtual void scriereInFisierBinar(fstream& fisier) = 0;
	virtual void citesteDinFisierBinar(fstream& fisier) = 0;
};

class Eveniment : public ScriereCitire
{
	char* locatie;
	int nrInvitati;
	float durata;
	int oraIncepere;

 public:
	 Eveniment() 
	 {
		 this->locatie = NULL;
		 this->nrInvitati = 0;
		 this->durata = 0;
		 this->oraIncepere = 0;
	}

	 Eveniment(const char* locatie, int nrInvitati, float durata, int oraIncepere) 
	 {
		 this->locatie = new char[strlen(locatie)+1]; //tb si verificat daca e mai mare
		 strcpy(this->locatie, locatie);
		 this->nrInvitati = nrInvitati;
		 this->durata = durata;
		 this->oraIncepere = oraIncepere;
	 }

	 Eveniment(const Eveniment &e)
	 {
		 this->locatie = new char[strlen(e.locatie) + 1]; //tb si verificat daca e mai mare
		 strcpy(this->locatie, e.locatie);
		 this->nrInvitati = e.nrInvitati;
		 this->durata = e.durata;
		 this->oraIncepere = e.oraIncepere;
	 }

	 Eveniment& operator= (Eveniment &e)
	 {
		 if(this->locatie!=NULL) 
		 {
			 delete[]this->locatie;
		 }
		 this->locatie = new char[strlen(e.locatie) + 1]; 
		 strcpy(this->locatie, e.locatie);
		 this->nrInvitati = e.nrInvitati;
		 this->durata = e.durata;
		 this->oraIncepere = e.oraIncepere;
		 return *this;
	 }

	 char* getLocatie() 
	 {
		 return locatie;
	 }

	 int getNrInvitati()
	 {
		 return nrInvitati;
	 }

	 float getDurata()
	 {
		 return durata;
	 }

	 int getOraIncepere()
	 {
		 return oraIncepere;
	 }

	 virtual void scriereInFisierBinar(fstream& fisier)
	 {
		 //serializare: se ia fiecare camp si se trece in fisier...deserializare cand ii citim
		 int lungime = strlen(this->locatie);
		 fisier.write((char*)&lungime, sizeof(int));
		 for (int i = 0; i < lungime; i++)
			 fisier.write((char*)&this->locatie[i], sizeof(char));
		 fisier.write((char*)&this->nrInvitati, sizeof(int));
		 fisier.write((char*)&this->oraIncepere, sizeof(int));
		 fisier.write((char*)&this->durata, sizeof(float));
	 }

	 virtual void citesteDinFisierBinar(fstream& fisier) 
	 {
		 //deserializare
		 int lungime = 0;
		 fisier.read((char*)&lungime, sizeof(int));
		 if (this->locatie != NULL) 
		 { 
			 delete[]this->locatie; 
		 }
		 this->locatie = new char[lungime + 1];
		 for (int i = 0; i < lungime; i++)
		 {
			 fisier.read((char*)&this->locatie[i], sizeof(char));
		 }
		 this->locatie[lungime] = '\0'; //slagame na poslednoto mqsto sfarsit de caracter
		 fisier.read((char*)&this->nrInvitati, sizeof(int));
		 fisier.read((char*)&this->oraIncepere, sizeof(int));
		 fisier.read((char*)&this->durata, sizeof(float));
	 }

	 ~Eveniment()
	 {
		 if (this->locatie != NULL)
			 delete[]this->locatie;
	  }
};

ostream& operator<<(ostream& consola, Eveniment& e)
{
	consola << "locatie eveniment: " << e.getLocatie() << endl;
	consola << "numar invitati: " << e.getNrInvitati() << endl;
	consola << "durata: " << e.getDurata() << endl;
	consola << "ora incepere: " << e.getOraIncepere() << endl;
	return consola;
}

void main()
{
	Eveniment ev("Bucuresti", 200, 2, 14);

	fstream fisBinOut("fisier.dat", ios::out | ios::binary);
	ev.scriereInFisierBinar(fisBinOut);
	fisBinOut.close();

	Eveniment e2;
	fstream fisIn("fisier.dat", ios::in | ios::binary);
	e2.citesteDinFisierBinar(fisIn);
	cout << e2;
	fisIn.close();
}

//dangling pointer - 2 pointeri care pointeza catre o singura zona de memorie
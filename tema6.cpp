#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class pantofi {
private:
	string marca;
	int marime;
	string culoare;
	float pret;

public:
	pantofi()
	{
		string marca = "";
		int marime = 0;
		string culoare = "";
		float pret = 0;
	}
	pantofi(string marca, int marime, string culoare, float pret)
	{
		this->marca = marca;
		this->marime = marime;
		this->culoare = culoare;
		this->pret = pret;
	}
	pantofi(string marca, int marime, string culoare, float pret)
	{
		setMarca(marca);
		setMarime(marime);
		setCuloare(culoare);
		setPret2(pret);
	}

	string getMarca()
	{
		return marca;
	}
	void setMarca(string marca)
	{
		if (marca.length() > 2)
		{
			this->marca = marca;
		}
		else { throw 202; }
	}

	int getMarime()
	{
		return marime;
	}
	void setMarime(int marime)
	{
		if (marime > 10 && marime < 50) this->marime = marime;
	}

	string getCuloare()
	{
		return culoare;
	}
	void setCuloare(string culoare)
	{
		if (culoare.length() > 2)
		{
			this->culoare = culoare;
		}
		else { throw 202; }
	}
	float getPret2()
	{
		return pret;
	}
	void setPret2(float pr)
	{
		pret = pr;
	}
	
};

class cizme : public pantofi
{
private: 
	int inaltime;
	string material;
public:
	cizme() : pantofi()
	{
		this->inaltime = 0;
		this->material = "";
	}

	cizme(int inaltime, string material) : pantofi("marca", 0, "culoare", 0)
	{
		this->inaltime = inaltime;
		this->material =material;
	}
	cizme(string marca, int marime, string culoare, float pret, int inaltime, string material) :pantofi(marca, marime, culoare, pret)
	{
		this->inaltime = inaltime;
		this->material = material;
	 }
};

class de_vara : public pantofi
{
private:
	bool deschise;
public:
	de_vara() :pantofi()
	{
		this->deschise = 1;
	}
		de_vara(bool deschise) : pantofi("marca", 0, "culoare", 0)
	{
			this->deschise = deschise;
	}
	de_vara(string marca, int marime, string culoare, float pret, bool deschise) :pantofi(marca, marime, culoare, pret)
	{
		this->deschise = deschise;
	}
};

class orase {
private:
	string oras;
	string tara;
	double aria;
	double populatia;

public:
	orase()
	{
		string oras = "";
		string tara = "";
		double aria = 0;
		double populatia = 0;
	}
	orase(string oras, string tara, double aria, double populatia)
	{
		this->oras = oras;
		this->tara = tara;
		this->aria = aria;
		this->populatia = populatia;
	}
	orase(string oras, string tara, double aria, double populatia)
	{
		setOras(oras);
		setTara(tara);
		setAria(aria);
		setPopulatia(populatia);
	}
	string getOras()
	{
		return oras;
	}
	void setOras(string oras)
	{
		if (oras.length() > 2)
		{
			this->oras = oras;
		}
		else { throw 202; }
	}

	string getTara()
	{
		return tara;
	}
	void setTara(string tara)
	{
		if (tara.length() > 3)
		{
			this->tara = tara;
		}
		else { throw 202; }
	}

	double getAria()
	{
		return aria;
	}
	void setAria(double aria)
	{
		if (aria > 0)
			this->aria = aria;
	}
	double getPopulatia()
	{
		return populatia;
	}
	void setPopulatia(double populatia)
	{
		if (populatia > 0) this->populatia = populatia;
	}

};

class vizitate : public orase
{
private:
	string data_vizita;
	int nota_vizita;
public:
	vizitate() :orase()
	{
		this->data_vizita = "";
		this->nota_vizita = 0;
	}
	vizitate(string data_vizita, int nota_vizita) : orase("Londra", "Marea Britanie", 345678.74, 645764743)
	{
		this->data_vizita = data_vizita;
		this->nota_vizita = nota_vizita;
	}
	vizitate(string oras, string tara, double aria, double populatia, string data_vizita, int nota_vizita) : orase(oras, tara, aria, populatia)
	{
		this->data_vizita = data_vizita;
		this->nota_vizita = nota_vizita;
	}
};

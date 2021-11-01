#include<iostream>
#include<string>
using namespace std;

class CartelaTransport {
	const string serieCartela;
	string numePosesor;
	int nrZileUtilizare;
	float sumaPortofel;
	int nrCalatorii;
	float* valoriCalatorii;
	static float valoareMinCalatorie;

public:
	//cerinta 1
	CartelaTransport() :serieCartela("A") {
		numePosesor = "Anonim";
		nrZileUtilizare = 0;
		sumaPortofel = 5;
		nrCalatorii = 0;
		valoriCalatorii = nullptr;
	}

	//cerinta 2
	CartelaTransport(string serieCartela, string numePosesor, int nrZileUtilizare, float sumaPortofel) :serieCartela(serieCartela) {
		this->numePosesor = numePosesor;
		if (nrZileUtilizare>=0)
		this -> nrZileUtilizare = nrZileUtilizare;
		if(sumaPortofel >=0)
		this->sumaPortofel = sumaPortofel;
		nrCalatorii = 0;
		valoriCalatorii = nullptr;
	}

	//cerinta 3
	~CartelaTransport() {
		if (valoriCalatorii != nullptr) delete[]valoriCalatorii;
	}

	//cerinta 4 get si set pt numePosesor si valoriCalatorii
	string getNumePosesor() {
		return numePosesor;
}

	void setNumePosesor(string nume) {
		if (nume.length() > 1) numePosesor = nume;
	}

	float* getValoriCalatorii() {
		return valoriCalatorii;
	}

	void setValoriCalatorii(int nr, float* valori) {
		if (valori != nullptr && nr >= 1)
		{
			if (valoriCalatorii != nullptr) delete[]valoriCalatorii;
			valoriCalatorii = new float[nr];
			for (int i = 0; i < nr; i++)
			{
				if (valori[i] >= valoareMinCalatorie)
					valoriCalatorii[i] = valori[i];
				else valoriCalatorii[i] = valoareMinCalatorie;
			}
			nrCalatorii = nr;
		}
		
	}

	//cerinta 5 copy const
	CartelaTransport(CartelaTransport& c) :serieCartela(c.serieCartela) {
		numePosesor =c.numePosesor;
		nrZileUtilizare = c.nrZileUtilizare;
		sumaPortofel = c.sumaPortofel;
		nrCalatorii = c.nrCalatorii;
		valoriCalatorii = new float[nrCalatorii];
		for (int i = 0; i < nrCalatorii; i++) {
			if (c.valoriCalatorii[i] >= valoareMinCalatorie) valoriCalatorii[i] = c.valoriCalatorii[i];
			else valoriCalatorii[i] = valoareMinCalatorie;
		}
	}

	//cerinta 6 op=
	CartelaTransport operator=(CartelaTransport c) {
		numePosesor = c.numePosesor;
		nrZileUtilizare = c.nrZileUtilizare;
		sumaPortofel = c.sumaPortofel;
		nrCalatorii = c.nrCalatorii;
		if (valoriCalatorii != nullptr) delete[]valoriCalatorii;
		valoriCalatorii = new float[nrCalatorii];
		for (int i = 0; i < nrCalatorii; i++) {
			if (c.valoriCalatorii[i] >= valoareMinCalatorie) valoriCalatorii[i] = c.valoriCalatorii[i];
			else valoriCalatorii[i] = valoareMinCalatorie;
		} return *this;
	}

	//cerinta 7
	friend istream& operator>>(istream& in, CartelaTransport& c);
	friend ostream& operator<<(ostream& out,CartelaTransport c);
	//cerinta 8

	//cerinta 9

	//cerinta 10
	float medieSumaPeZi();
};
//cerinta 7
istream& operator>>(istream& in, CartelaTransport& c) {
	cout << "nume ";
	in >> c.numePosesor;
	cout << "nr zile utiliz ";
	in >> c.nrZileUtilizare;
	cout << "suma portofel ";
	in >> c.sumaPortofel;
	cout << "nr calatorii ";
	in >> c.nrCalatorii; 
	if (c.valoriCalatorii != nullptr) delete[]c.valoriCalatorii;
	c.valoriCalatorii = new float[c.nrCalatorii];
	for (int i = 0; i < c.nrCalatorii; i++)
		in >> c.valoriCalatorii[i];
	return in;
}

ostream& operator<<(ostream& out, CartelaTransport c) {
	out << c.numePosesor << " " << c.serieCartela << " " << c.nrZileUtilizare << " "
		<< c.sumaPortofel << " " << c.nrCalatorii<<endl;
	for (int i = 0; i < c.nrCalatorii; i++)
		out << c.valoriCalatorii[i] << " ";
	out << CartelaTransport::valoareMinCalatorie << endl;
	return out;
}


float CartelaTransport::valoareMinCalatorie = 10;

void main() {
	//cerinta 1
	CartelaTransport c1;
	//cerinta 2
	CartelaTransport c2("B", "Popescu", 1, 30);
	//cerinta 3
	cout << "destructorul nu se poate testa" << endl;
	//cerinta 4
	cout<< c2.getNumePosesor()<<endl;
	cout << c2.getValoriCalatorii()<<endl;
	c2.setNumePosesor("Popa");
	c2.setValoriCalatorii(2, new float[2]{ 22,24});
	cout << c2.getNumePosesor() << endl;
	cout << c2.getValoriCalatorii() << endl;
	//cerinta 5
	cout << "testare constructor de copiere" << endl;
	CartelaTransport c3 = c1;
	//cerinta 6
	CartelaTransport c4("C", "Galatanu", 3, 45);
	cout << "testare op =" << endl;
	c1 = c4;
	//cerinta 7
	cin >> c4;
	cout << c1;
	cout << c2;
	cout << c3;
	cout << c4;
	//cerinta 8

	//cerinta 9

	//cerinta 10

}
#include<iostream>
using namespace std;

class Animale {
	string nume;
	int ani;
	int nrCopii;
	int* varstaCopii;

public:
	Animale() {
		nume = "anonim";
		ani = 0;
		nrCopii = 0;
		varstaCopii = nullptr;
	}

	Animale(string nume, int ani, int nrCopii, int* varstaCopii) {
		this->nume = nume;
		if (ani > 0 && ani < 100) this->ani = ani;
		if (nrCopii > 0 && varstaCopii != nullptr) {
			this->nrCopii = nrCopii;
			this->varstaCopii = new int[nrCopii];
			for (int i = 0; i < nrCopii; i++)
				this->varstaCopii[i] = varstaCopii[i];
		}
		else {
			this->nrCopii = 0;
			this->varstaCopii = nullptr;
		}
	}

	int getAni() {
		return ani;
	}

	void setAni(int ani) {
		if(ani>0 && ani<100)
		this->ani = ani;
	}

	~Animale() { if (varstaCopii != nullptr) delete[]varstaCopii; }

	Animale(Animale& a) {
		nume = a.nume;
		ani = a.ani;
		nrCopii = a.nrCopii;
		varstaCopii = new int[nrCopii];
		for (int i = 0; i < nrCopii; i++)
			varstaCopii[i] = a.varstaCopii[i];
	}

	Animale operator=(Animale a) {
		nume = a.nume;
		ani = a.ani;
		nrCopii = a.nrCopii;
		if (varstaCopii != nullptr) delete[]varstaCopii;
		varstaCopii = new int[nrCopii];
		for (int i = 0; i < nrCopii; i++)
			varstaCopii[i] = a.varstaCopii[i];
		return *this;
	}

	friend istream& operator>>(istream& in, Animale& a);
	friend ostream& operator<<(ostream& out, Animale a);
};

 istream& operator>>(istream& in, Animale& a) {
	cout << "nume "; in >> a.nume;
	cout << "ani "; in >> a.ani;
	cout << "nr copii "; in >> a.nrCopii;
	if (a.varstaCopii != nullptr) delete[]a.varstaCopii;
	a.varstaCopii = new int[a.nrCopii];
	for (int i = 0; i < a.nrCopii; i++)
		in >> a.varstaCopii[i];
	return in;
}

 ostream& operator<<(ostream& out, Animale a) {
	 out << a.nume << a.ani << a.nrCopii;
	 for (int i = 0; i < a.nrCopii; i++)
		 out << a.varstaCopii[i];
	 return out;
 }

void main() {
	Animale a1; //testare const implicit
	Animale a2("Ana", 2, 0, nullptr); //testare constr cu param
	Animale a3 = a2; //testare copy const
	cin >> a3; //testare intrare
	cout << a1;
}
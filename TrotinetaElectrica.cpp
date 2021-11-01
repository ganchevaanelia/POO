#include<iostream>
using namespace std;

class TrotinetaElectrica {
	string model;
	int nivelBaterie;
	const float consumPerKm;
	int* kmPerSesiuneInchiriere;
	int nrSesiuniInchiriere;
	static int NIVEL_MAXIM_BATERIE;

public:
	TrotinetaElectrica() : consumPerKm(10) {
		model = "ABC567";
		nivelBaterie = 80;
		kmPerSesiuneInchiriere = nullptr;
		nrSesiuniInchiriere = 0;
	}

	string getModel() {
		return model;
	}

	int getNrSesiuniIncheriere() {
		return nrSesiuniInchiriere;
	}

	int getNivelBaterie() {
		return nivelBaterie;
	}

	TrotinetaElectrica(int nivelBaterie, float consumPerKm,
		int nrSesiuniInchiriere, int* kmPerSesiune) : consumPerKm(consumPerKm){
		model = "ABC567";
		if (nivelBaterie >= 0 && nivelBaterie <= NIVEL_MAXIM_BATERIE)
		{
			this->nivelBaterie = nivelBaterie;
		}
		if (nrSesiuniInchiriere > 0)
		{
			this->nrSesiuniInchiriere = nrSesiuniInchiriere;
			if (kmPerSesiuneInchiriere 1 + nullptr) {
			}
			else {
				this->kmPerSesiuneInchiriere = nullptr;
				this->nrSesiuniInchiriere = 0;
			}
		}
		else {
			this->nrSesiuniInchiriere = 0;
			this->kmPerSesiuneInchiriere = nullptr;
		}
	}

	~TrotinetaElectrica() {
		if (kmPerSesiuneInchiriere !=nullptr)
		delete[] kmPerSesiuneInchiriere;
	}
};

int TrotinetaElectrica::NIVEL_MAXIM_BATERIE = 100;

void main() {
	TrotinetaElectrica t1;
	cout<< "testare getModel: " << t1.getModel()<<endl;
	cout << "testare getNrSesiuniInchiriere: " << t1.getNrSesiuniIncheriere()<<endl;
	cout << "testare getNivelBaterie: " << t1.getNivelBaterie()<<endl;
}

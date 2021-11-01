#include<iostream>
using namespace std;

//sem 8-10

class Interfata {
	virtual void identificareIndivid() = 0; //metoda virtual pura
};

class Persoana :public Interfata{
protected:
	const string CNP;
	int varsta;
	string nume;

public:
	Persoana() : CNP("12334554332") {
		varsta = 22;
		nume = "Alexandru";
	}

	Persoana(string CNP, int varsta, string nume) :CNP(CNP) {
		if (varsta > 0)
			this->varsta = varsta;
		else
			this->varsta = 22;

		if (nume != "")
			this->nume = nume;
		else
			this->nume = "Alexandru";
	}

	~Persoana() {}

	Persoana(const Persoana& p) : CNP(p.CNP) {
		varsta = p.varsta;
		nume = p.nume;
	}

	void operator=(Persoana p) { //cu & nu mai apeleaza constructorul de copiere
		varsta = p.varsta;
		nume = p.nume;
	}

	string getNume() {
		return nume;
	}

	void setNume(string nume) {
		if (nume != "")
			this->nume = nume;
	}

	//metoda virtual pura
	virtual void afisareDetalii() = 0;

	/*	virtual void afisareDetalii() {
		cout << "Persoana " << nume << " este identificata prin CNP-ul " << CNP <<
			" si are varsta de " << varsta << " ani." << endl;
	}*/

	void identificareIndivid() {
		cout << CNP<<endl;
	}
};


enum class CategorieStudent {
	LICENTIAT, MASTERAND, DOCTORAND
};

ostream& operator<<(ostream& out, CategorieStudent cs) {
	out << "licentiat";
	return out;
}

class Student : public Persoana {
protected:
	const string nrMatricol;
	int anStudii;
	CategorieStudent categorieStudent;

public:
	Student() :Persoana(), nrMatricol("123456789") {
		anStudii = 1;
		categorieStudent = CategorieStudent::LICENTIAT;
	}

	Student(string CNP, int varsta, string nume, string nrMatricol,
		int anStudii, CategorieStudent categorieStudent) :
		Persoana(CNP, varsta, nume), nrMatricol(nrMatricol) {

		if (anStudii > 0 && anStudii <= 5)
			this->anStudii = anStudii;
		else
			this->anStudii = 1;

		this->categorieStudent = categorieStudent;
	}

	~Student() {}

	Student(const Student& s) :Persoana(s), nrMatricol(s.nrMatricol) {
		anStudii = s.anStudii;
		categorieStudent = s.categorieStudent;
	}

	void operator=(Student s) {
		//this->Persoana::operator=(s);
		varsta = s.varsta;
		nume = s.nume;
		anStudii = s.anStudii;
		categorieStudent = s.categorieStudent;
	}

	int getAnStudii() {
		return anStudii;
	}

	void setAnStudii(int anStudii) {
		if (anStudii > 0 && anStudii <= 5)
			this->anStudii = anStudii;
	}

	//antet identit pt overriding (supradefinire)
	virtual void afisareDetalii() {
		this->Persoana::afisareDetalii();
		cout << "studentul este inmatriculat cu codul " << nrMatricol << " in anul "
			<< anStudii << ". este " << categorieStudent << endl;
	}

	void identificareIndivid() {
		cout << nrMatricol << endl;
	}
};

class Profesor : public Persoana {
protected:
	float salariu;
	int vechime;

public:
	Profesor() :Persoana() {
		salariu = 4000;
		vechime = 10;
	}

	Profesor(string CNP, string nume, int varsta, float salariu, int vechime)
		: Persoana(CNP, varsta, nume) {
		if (salariu > 0 && salariu < 10000)
			this->salariu = salariu;
		else
			this->salariu = 4000;

		if (vechime > 0 && vechime < 50)
			this->vechime = vechime;
		else
			this->vechime = 10;
	}

	Profesor(const Profesor& p) :Persoana(p) {
		vechime = p.vechime;
		salariu = p.salariu;
	}

	void operator=(Profesor& p) {
		//this->Persoana::operator=(p);
		varsta = p.varsta;
		nume = p.nume;
		vechime = p.vechime;
		salariu = p.salariu;
	}

	~Profesor() {}

	float getSalariu() {
		return salariu;
	}

	void setSalariu(float salariu) {
		if (salariu > 0 && salariu < 10000)
			this->salariu = salariu;
	}

	void afisareDetalii() {
		this->Persoana::afisareDetalii();
		cout << "Profesorul are salariul de " << salariu << " RON si o vechime de " << vechime << endl;
	}
};

void main() {
	//Persoana p("1222738696969",32,"Viorel");
	Student s("7654333456765",23,"Georgiana","2343567",22,CategorieStudent::LICENTIAT);
	Profesor pr("4566787654", "Aurel", 30, 4500, 4);

	//p.afisareDetalii();
	s.afisareDetalii();

	Persoana* p3 = new Student("123456777543", 25, "Gigel", "3456765432", 3, CategorieStudent::LICENTIAT);
	Persoana* p4; //sa lucrez cu un student deja existent
	p4 = &s;

	p3->afisareDetalii(); //folosim sageata pt ca e un pointer
	p4->afisareDetalii();

	//cu virtual facem late-binding

	//polimorfism
	Persoana* pp;
	pp->afisareDetalii();
	pp = &s;
	pp->afisareDetalii();
	pp = &pr;
	pp->afisareDetalii();

	//da vzema celiq kod ot drive - opletoh se
	
}
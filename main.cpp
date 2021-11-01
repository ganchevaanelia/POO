#include<iostream>
#include<fstream>

#include"Persoana.h"

using namespace std;

void main() {
	int x = 8;
	int y = 9;
	int z = 10;

	// --------PRIMITIVE---------
	cout << " --------PRIMITIVE---------" << endl;
	ofstream  outfile("out.dat", ios::binary);
	//sau fct open
	if (outfile.is_open()) {
		outfile.write((char*)&x, sizeof(int));
		outfile.write((char*)&y, sizeof(int));
		outfile.write((char*)&z, sizeof(int));

		outfile.close();
	}
	else
		cerr << "Fisierul out.dat nu s-a putut deschide pt scriere" << endl;

	outfile.open("out.txt");
	if (outfile.is_open()) {
		outfile << x << endl;
		outfile << y << endl;
		outfile << z << endl;

		outfile.close();
	}
	else
		cerr << "Fisierul out.txt nu s-a putut deschide pt scriere" << endl;


	ifstream infile("out.dat", ios::binary);
	if (infile.is_open()) {
		infile.seekg(0, ios::end); //sekkpp
		cout << "nr elem in fisierul out.dat: " << infile.tellg() / sizeof(int) << endl;
			//tellg - cati bytes sunt pana in pozitia unde ma aflu; tellp pt scriere

		infile.seekg(ios::beg);
		int aux;
		infile.read((char*)&aux, sizeof(int)); //am citi pe aux primul element
		cout << "elem din fisierul out.dat: ";
		while (!infile.eof()) {
			cout << aux << " ";
			infile.read((char*)&aux, sizeof(int));
		}
		cout << endl;
		infile.close();
	}
	else 
		cerr << "Fisierul out.dat nu s-a putut deschide pt citire" << endl;


	infile.open("out.txt");
	if (infile.is_open()) {
		int aux;
		cout << "elem din fisierul out.txt: ";
		while (infile >> aux) { //infile citeste aux
			cout << aux << " ";
		}
		cout << endl;

		infile.close();
	}
	else
		cerr << "Fisierul out.txt nu s-a putut deschide pt citire" << endl;


	// --------OBIECTE- PERSOANA---------
	cout << " --------PERSOANA---------" << endl;

	Persoana p1("Alexis Zaharia",25);
	Persoana p2("George", 23);
	Persoana p3("Adina", 20);

	outfile.open("outPersoana.dat", ios::binary);
	//sau fct open
	if (outfile.is_open()) {
		outfile.write((char*)&p1, sizeof(Persoana));
		outfile.write((char*)&p2, sizeof(Persoana));
		outfile.write((char*)&p3, sizeof(Persoana));

		outfile.close();
	}
	else
		cerr << "Fisierul outPersoana.dat nu s-a putut deschide pt scriere" << endl;

	outfile.open("outPersoana.txt");
	if (outfile.is_open()) {
		outfile << p1;  //ne folosim de supraincarcarea operator
		outfile << p2;
		outfile << p3;

		outfile.close();
	}
	else
		cerr << "Fisierul outPersoana.txt nu s-a putut deschide pt scriere" << endl;


	infile.open("outPersoana.dat", ios::binary);
	if (infile.is_open()) {
		infile.seekg(0, ios::end); //sekkpp
		cout << "nr elem in fisierul outPersoana.dat: " << infile.tellg() / sizeof(Persoana) << endl;
		//tellg - cati bytes sunt pana in pozitia unde ma aflu; tellp pt scriere

		infile.seekg(ios::beg);
		Persoana aux;
		infile.read((char*)&aux, sizeof(Persoana)); //am citi pe aux primul element
		cout << "elem din fisierul outPersoana.dat: ";
		while (!infile.eof()) {
			cout << aux;
			infile.read((char*)&aux, sizeof(Persoana));
		}
		cout << endl;

		// eroare la simbolul de terminatie
		infile.close();
	}
	else
		cerr << "Fisierul outPersoana.dat nu s-a putut deschide pt citire" << endl;


	infile.open("outPersoana.txt");
	if (infile.is_open()) {
		Persoana aux;
		cout << "elem din fisierul outPersoana.txt: ";
		while (infile >> aux) { //infile citeste aux
			cout << aux;
		}
		cout << endl;

		infile.close();
	}
	else
		cerr << "Fisierul outPersoana.txt nu s-a putut deschide pt citire" << endl;

}
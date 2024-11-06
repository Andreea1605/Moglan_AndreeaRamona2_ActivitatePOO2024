#include<iostream>
using namespace std;
class Cofetarie {
public:
	string nume;
	int nrAngajati;
	const int anDeschidere;
	static int TVA;
	float* salarii;
	bool seAflaInCentrulUnuiOras;
	
	Cofetarie() :anDeschidere(2016) {
		this->nume = "Antony";
		this->nrAngajati = 10;
		this->salarii = NULL;
		this->seAflaInCentrulUnuiOras = false;
	}

	Cofetarie(string nume, int nrAngajati, bool seAflaInCentru, int an) : anDeschidere(an) {
		this->nume = nume;
		this->nrAngajati = nrAngajati;
		this->seAflaInCentrulUnuiOras = seAflaInCentru;
		this->salarii = new float[this->nrAngajati];
		for (int i = 0; i < this->nrAngajati; i++) {
			this->salarii[i] = 2000.0f + i * 500.0f;
		}

	}

	Cofetarie(string nume, int nrAngajati, int an) : anDeschidere(an) {
		this->nume = nume;
		this->nrAngajati = nrAngajati;
		this->salarii = new float[this->nrAngajati];
		this->seAflaInCentrulUnuiOras = true;
		for (int i = 0; i < this->nrAngajati; i++) {
			this->salarii[i] = 2500.0f + i * 1000.0f;
		}

	}

	void afisare() {
		cout << "Nume:" << this->nume<<endl;
		cout << "Nr. angajati:" << this->nrAngajati<<endl;
		cout << "An deschidere:" << this->anDeschidere << endl;
		cout << "TVA:" << Cofetarie::TVA << endl;
		cout << "Se afla in centrul unui oras:" << (this->seAflaInCentrulUnuiOras ? "DA" : "NU")<<endl;
	}

	static void modificaTVA(int TVA) {
		if (TVA >= 0) {
			Cofetarie::TVA = TVA;
		}
	}
	
};
class Patiserie {
public:
	string oras;
	int nrAngajati;
	float* salarii;
	const int anDeschidere;
	static int nrPatiserii;
	float suprafata;

	Patiserie() :anDeschidere(2007) {
		this->oras = "Bucuresti";
		this->nrAngajati = 10;
		this->suprafata = 30;
		this->salarii = NULL;
		Patiserie::nrPatiserii++;
	}

	Patiserie(string oras, int nrAngajati, float suprafata, int an) :anDeschidere(an) {
		this->oras = oras;
		this->nrAngajati = nrAngajati;
		this->suprafata = suprafata;
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = 3000.0f + i;
		}
		Patiserie::nrPatiserii++;
	}

	Patiserie(string oras, int nrAngajati, int an) :anDeschidere(an) {
		this->oras = oras;
		this->nrAngajati = nrAngajati;
		this->suprafata = 25;
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = 1500.0f + i * 50.0f;
		}
		Patiserie::nrPatiserii++;
	}

	void afisare() {
		cout << "Oras:" << this->oras << endl;
		cout << "Nr.angajati:" << this->nrAngajati << endl;
		cout << "An deschidere:" << this->anDeschidere << endl;
		cout << "Suprafata:" << this->suprafata << endl;
		cout << "Nr.patiserii:" << Patiserie::nrPatiserii;
	}

	static int calculeazaNrTotalAngajatiVector(int nrPatiserii, Patiserie* vector) {
		int suma = 0;
		for (int i = 0; i < nrPatiserii; i++) {
			suma += vector[i].nrAngajati;
		}
		return suma;
	}
};


class MagazinAlimentar {
public:
	string nume;
	int nrTipProduse;
	int* StocProduse;
	const int anDeschidere;
	static int TVA;
	int nrAngajati;

	MagazinAlimentar() :anDeschidere(1995) {
		this->nume = "Mega Image";
		this->nrTipProduse = 100;
		this->StocProduse = NULL;
		this->nrAngajati = 8;
	}

	MagazinAlimentar(string nume, int nrProduse, int nrAngajati,int an):anDeschidere(an) {
		this->nume = nume;
		this->nrTipProduse = nrProduse;
		this->StocProduse = new int[nrTipProduse];
		for (int i = 0; i < nrProduse; i++) {
			this->StocProduse[i] = i+1+i*10;
		}
		this->nrAngajati = nrAngajati;
	}

	MagazinAlimentar(string nume, int nrProduse, int an) :anDeschidere(an) {
		this->nume = nume;
		this->nrTipProduse = nrProduse;
		this->StocProduse = new int[nrTipProduse];
		for (int i = 0; i < nrProduse; i++) {
			this->StocProduse[i] = i + 20;
		}
		this->nrAngajati = 6;
	}

	void afisare() {
		cout << "Nume:" << this->nume << endl;
		cout << "Nr.tip produse:" << this->nrTipProduse<< endl;
		cout << "An deschidere:" << this->anDeschidere << endl;
		cout << "TVA:" << MagazinAlimentar::TVA << endl;
		cout << "Nr.angajati:" << this->nrAngajati<<endl;
	}

	static void modificaTVA(int TVA) {
		if (TVA >= 0) {
			MagazinAlimentar::TVA = TVA;
		}
	}
};
int Cofetarie::TVA = 15;
int Patiserie::nrPatiserii = 0;
int MagazinAlimentar::TVA = 19;
int main() {
	Cofetarie cofetarie1;
	cofetarie1.afisare();
	cout << endl;
	Cofetarie cofetarie2("Delice", 12, true, 2020);
	cofetarie2.afisare();
	cout << endl;
	Cofetarie cofetarie3("Alice", 8, 2019);
	cofetarie3.afisare();
	cout << endl;

	Patiserie p1;
	p1.afisare();
	cout << endl;
	cout << endl;
	Patiserie p2("Constanta", 11, 25, 2011);
	p2.afisare();
	cout << endl;
	cout << endl;
	Patiserie p3("Brasov", 9, 2021);
	p3.afisare();
	cout << endl;
	cout << endl;

	MagazinAlimentar m1;
	m1.afisare();
	cout << endl;
	MagazinAlimentar m2("Profi", 50, 5, 2006);
	m2.afisare();
	cout << endl;
	MagazinAlimentar m3("Carrefour", 110, 2018);
	m3.afisare();
	cout << endl;

	Cofetarie::modificaTVA(16);
	Cofetarie c4;
	c4.afisare();
	cout << endl;

	Patiserie* vector = new Patiserie[3];
	Patiserie::calculeazaNrTotalAngajatiVector(3, vector);

	MagazinAlimentar::modificaTVA(21);
	MagazinAlimentar m4;
	m4.afisare();
}
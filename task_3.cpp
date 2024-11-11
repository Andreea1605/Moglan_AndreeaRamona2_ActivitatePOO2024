#include<iostream>
using namespace std;
class Cofetarie {
private:
	string nume;
	int nrAngajati;
	const int anDeschidere;
	static int TVA;
	float* salarii;
	bool seAflaInCentrulUnuiOras;
public:
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

	//Constructor de copiere
	Cofetarie(const Cofetarie &c):anDeschidere(c.anDeschidere) {
		this->nume = c.nume;
		this->nrAngajati = c.nrAngajati;
		this->salarii = new float[c.nrAngajati];
		for (int i = 0; i < c.nrAngajati; i++) {
			this->salarii[i] = c.salarii[i];
		}
		this->seAflaInCentrulUnuiOras = c.seAflaInCentrulUnuiOras;
	}

	~Cofetarie() {
		if (this->salarii) {
			delete[]this->salarii;
		}
	}

	void afisare() {
		cout << "Nume:" << this->nume << endl;
		cout << "Nr. angajati:" << this->nrAngajati << endl;
		if (this->salarii != NULL) {
			cout << "Salarii: ";
			for (int i = 0; i < this->nrAngajati; i++) {
				cout << this->salarii[i] << ", ";
			}
			cout << endl;
		}
		cout << "An deschidere:" << this->anDeschidere << endl;
		cout << "TVA:" << Cofetarie::TVA << endl;
		cout << "Se afla in centrul unui oras:" << (this->seAflaInCentrulUnuiOras ? "DA" : "NU") << endl;
	}

	static void modificaTVA(int TVA) {
		if (TVA >= 0) {
			Cofetarie::TVA = TVA;
		}
	}

	string getNume() {
		return this->nume;
	}
	void setNume(string nume_nou) {
		if (nume_nou.length() > 1) {
			this->nume = nume_nou;
		}
	}
	int getNrAngajati() {
		return this->nrAngajati;
	}
	void setNrAngajati(int nrAngajati, float* salarii) {
		if (nrAngajati > 0) {
			this->nrAngajati = nrAngajati;
			if (this->salarii != NULL) {
				delete[]this->salarii;
			}
			this->salarii = new float[nrAngajati];
			for (int i = 0; i < this->nrAngajati; i++) {
				this->salarii[i] = salarii[i];
			}
		}
	}
	int getAnDeschidere() {
		return this->anDeschidere;
	}
	static int getTVA() {
		return Cofetarie::TVA;
	}

	float* getSalarii() {
		return this->salarii;
	}
	float getSalariu(int index) {
		if (this->salarii!=NULL) {
			if (index >=  0 && index < this->nrAngajati) {
				return this->salarii[index];
			}
		}
		else { 
			cout << "Salariile nu au fost inregistrate";
		}
	}
	bool getSeAflaInCentru() {
		return this->seAflaInCentrulUnuiOras;
	}
	void setSeAflaInCentru(bool seAflaInCentru) {
		this->seAflaInCentrulUnuiOras = seAflaInCentru;
	}
	friend int calculeazaNrTotalAngajati(int nrCofetarii, Cofetarie* Cofetarii);
};
int calculeazaNrTotalAngajati(int nrCofetarii, Cofetarie* Cofetarii) {
	if (nrCofetarii > 0) {
		int suma = 0;
		for (int i = 0; i < nrCofetarii; i++) {
			suma = suma + Cofetarii[i].nrAngajati;
		}
		return suma;
	}
	else {
		cout << "Nu exista cofetarii";
	}
}
class Patiserie {
private:
	string oras;
	int nrAngajati;
	float* salarii;
	const int anDeschidere;
	static int nrPatiserii;
	float suprafata;
public:
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

	Patiserie(const Patiserie& p) : anDeschidere(p.anDeschidere){
		this->oras = p.oras;
		this->nrAngajati = p.nrAngajati;
		if (p.nrAngajati > 0) {
			this->salarii = new float[p.nrAngajati];
			for (int i = 0; i < p.nrAngajati; i++) {
				this->salarii[i] = p.salarii[i];
			}
		}
		else {
			this->salarii = nullptr;
		}
		this->suprafata = p.suprafata;
		Patiserie::nrPatiserii++;
	}

	~Patiserie() {
		if (this->salarii) {
			delete[]this->salarii;
		}
	}

	void afisare() {
		cout << "Oras:" << this->oras << endl;
		cout << "Nr.angajati:" << this->nrAngajati << endl;
		if (this->salarii != NULL) {
			cout << "Salarii:";
			for (int i = 0; i < this->nrAngajati; i++) {
				cout << this->salarii[i] << ", ";
			}
			cout << endl;
		}
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
	string getOras() {
		return this->oras;
	}
	void setOras(string oras_nou) {
		if (oras_nou.length() > 2) {
			this->oras = oras_nou;
		}
	}
	int getNrAngajati() {
		return this->nrAngajati;
	}
	void setNrAngajati(int nrAngajati, float *salarii) {
		if (this->nrAngajati > 0) {
			this->nrAngajati = nrAngajati;
			if (this->nrAngajati != NULL) {
				delete[]this->salarii;
			}
			this->salarii = new float[nrAngajati];
			for (int i = 0; i < nrAngajati; i++) {
				this->salarii[i] = salarii[i];
			}
		}
	}
	int getAnDeschidere() {
		return this->anDeschidere;
	}
	float getSuprafata() {
		return this->suprafata;
	}
	void setSuprafata(float nouaSuprafata) {
		if (nouaSuprafata > 5) {
			this->suprafata = nouaSuprafata;
		}
	}
	static int getNrPatiserii() {
		return Patiserie::nrPatiserii;
	}
	float* getSalarii() {
		return this->salarii;
	}
	float getSalariu(int index) {
		if (this->salarii != NULL) {
			if (index >= 0 && index < this->nrAngajati) {
				return this->salarii[index];
			}
		}
		else {
			cout << "Salariile nu au fost inregistrate";
		}
	}
	friend void afiseazaPatiseriileCareSeAflaInBucuresti(Patiserie* patiserii,int nrPatiserii);
};
void afiseazaPatiseriileCareSeAflaInBucuresti(Patiserie *patiserii,int nrPatiserii){
	for (int i = 0; i < nrPatiserii; i++) {
		if (patiserii[i].oras == "Bucuresti") {
			cout << "Oras:" << patiserii[i].oras << endl;
			cout << "Nr.angajati:" << patiserii[i].nrAngajati << endl;
			if (patiserii[i].salarii != NULL) {
				cout << "Salarii:";
				for (int i = 0; i < patiserii[i].nrAngajati; i++) {
					cout <<patiserii[i].salarii[i]<< ", ";
				}
				cout << endl;
			}
			cout << "An deschidere:" <<patiserii[i].anDeschidere << endl;
			cout << "Suprafata:" << patiserii[i].suprafata << endl;
		}
		cout << endl;
	}
}

class MagazinAlimentar {
private:
	string nume;
	int nrTipProduse;
	int* StocProduse;
	const int anDeschidere;
	static int TVA;
	int nrAngajati;
public:
	MagazinAlimentar() :anDeschidere(1995) {
		this->nume = "Mega Image";
		this->nrTipProduse = 100;
		this->StocProduse = NULL;
		this->nrAngajati = 8;
	}

	MagazinAlimentar(string nume, int nrProduse, int nrAngajati, int an) :anDeschidere(an) {
		this->nume = nume;
		this->nrTipProduse = nrProduse;
		this->StocProduse = new int[nrTipProduse];
		for (int i = 0; i < nrProduse; i++) {
			this->StocProduse[i] = i + 1 + i * 10;
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

	MagazinAlimentar(const MagazinAlimentar& m):anDeschidere(m.anDeschidere) {
		this->nume = m.nume;
		this->nrTipProduse = m.nrTipProduse;
		this->StocProduse = new int[m.nrTipProduse];
		for (int i = 0; i < m.nrTipProduse; i++) {
			this->StocProduse[i] = m.StocProduse[i];
		}
		this->nrAngajati = m.nrAngajati;
	}

	~MagazinAlimentar() {
		if (this->StocProduse) {
			delete[]this->StocProduse;
		}
	}


	void afisare() {
		cout << "Nume:" << this->nume << endl;
		cout << "Nr.tip produse:" << this->nrTipProduse << endl;
		if (this->StocProduse!= NULL) {
			cout << "Stoc produse: ";
			for (int i = 0; i < this->nrTipProduse; i++) {
				cout << this->StocProduse[i] << ", ";
			}
			cout << endl;
		}
		cout << "An deschidere:" << this->anDeschidere << endl;
		cout << "TVA:" << MagazinAlimentar::TVA << endl;
		cout << "Nr.angajati:" << this->nrAngajati << endl;
	}

	static void modificaTVA(int TVA) {
		if (TVA >= 0) {
			MagazinAlimentar::TVA = TVA;
		}
	}
	string getNume() {
		return this->nume;
	}
	void setNume(string numeNou) {
		if (numeNou.length() > 2) {
			this->nume = numeNou;
		}
	}
	int getNrTipProduse() {
		return this->nrTipProduse;
	}
	void setNrTipProduse(int nrTipProduse, int *StocProduse) {
		if (nrTipProduse > 0) {
			this->nrTipProduse = nrTipProduse;
			if (this->StocProduse !=NULL) {
				delete[]this->StocProduse;
			}
			this->StocProduse = new int[nrTipProduse];
			for (int i = 0; i < nrTipProduse; i++) {
				this->StocProduse[i] = StocProduse[i];
			}
		}
	}
	int* getStocProduse() {
		return this->StocProduse;
	}
	int getStocProdus(int index) {
		if (this->StocProduse != NULL) {
			if (index >= 0 && index < this->nrTipProduse) {
				return this->StocProduse[index];
			}
		}
		else {
			cout << "Stocul produselor nu este inregistrat";
		}
	}
	int getAnDeschidere() {
		return this->anDeschidere;
	}
	int getTVA() {
		return MagazinAlimentar::TVA;
	}
	int getNrAngajati() {
		return this->nrAngajati;
	}
	void setNrAngajati(int nrAngajati) {
		if (nrAngajati > 0) {
			this->nrAngajati = nrAngajati;
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
	cout<<"Numar total angajati Patiserii:"<<Patiserie::calculeazaNrTotalAngajatiVector(3, vector);
	cout << endl;
	cout << endl;

	MagazinAlimentar::modificaTVA(21);
	MagazinAlimentar m4;
	m4.afisare();
	cout << endl;

	Cofetarie c5 = cofetarie2;
	c5.afisare();
	cout << endl;

	Patiserie p4 = p2;
	p2.afisare();
	cout << endl;
	cout << endl;

	MagazinAlimentar m5(m3);
	m5.afisare();
	cout << endl;

	cout<<cofetarie3.getNume()<<endl;
	cofetarie2.setNume("Vanilla");
	cofetarie2.afisare();
	cout << endl;
	cout<<cofetarie1.getAnDeschidere()<<endl<<endl;
	cout<<c5.getTVA()<<endl;
	cout << cofetarie3.getNrAngajati() << endl;
	float* nrAngajati = new float[5];
	cofetarie3.setNrAngajati(5, nrAngajati);
	cout<<cofetarie3.getNrAngajati()<<endl;
	cout<<cofetarie2.getSalariu(0)<<endl;
	cout << cofetarie1.getSeAflaInCentru() << endl;
	cofetarie1.setSeAflaInCentru(true);
	cout << cofetarie1.getSeAflaInCentru() << endl;
	Cofetarie* Cofetarii = new Cofetarie[4];
	cout << "Numarul total de angajati:" << calculeazaNrTotalAngajati(4, Cofetarii)<<endl;

	cout << p2.getOras() << endl;
	p2.setOras("Bucuresti");
	cout << p2.getOras() << endl;
	cout << p3.getNrAngajati() << endl;
	float* angajati = new float[11];
	p3.setNrAngajati(11,angajati);
	cout << p3.getNrAngajati() << endl;
	cout<<p1.getAnDeschidere() << endl;
	cout << p1.getSuprafata() << endl;
	p1.setSuprafata(35);
	cout << p1.getSuprafata() << endl;
	cout << Patiserie::getNrPatiserii()<<endl;
	cout << p2.getSalarii()<<endl;
	cout << p2.getSalariu(2) << endl;
	cout << p1.getSalariu(1)<<endl;
	cout << endl;

	cout << m2.getNume()<<endl;
	m2.setNume("Penny");
	cout << m2.getNume()<<endl;
	cout<<m3.getNrTipProduse()<<endl;
	int* tipProduse = new int[120];
	m3.setNrTipProduse(120, tipProduse);
	cout << m3.getNrTipProduse()<<endl;
	cout<<m1.getStocProdus(1)<<endl;
	cout << m2.getStocProduse()[2]<<endl;
	cout << m2.getStocProdus(2)<<endl;
	cout << m3.getAnDeschidere() << endl;
	cout << m1.getTVA() << endl;
	cout << m2.getNrAngajati() << endl;
	m2.setNrAngajati(6);
	cout << m2.getNrAngajati() << endl;
	Patiserie* patiserii = new Patiserie[4];
	afiseazaPatiseriileCareSeAflaInBucuresti(patiserii, 4);

	delete[]vector;
	delete[]nrAngajati;
	delete[]Cofetarii;
	delete[]angajati;
	delete[]tipProduse;
	delete[]patiserii;
}
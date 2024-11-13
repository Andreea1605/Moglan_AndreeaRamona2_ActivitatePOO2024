#include<iostream>
using namespace std;
class Patiserie {
private:
	string oras;
	int nrAngajati;
	float* salarii;
	float suprafata;
	static int nrPatiserii;
	const int anDeschidere;
public:
	Patiserie() :anDeschidere(2020) {
		this->oras = "Bucuresti";
		this->nrAngajati = 9;
		this->salarii = NULL;
		this->suprafata = 20;
		nrPatiserii++;
	}
	Patiserie(string oras, int nrAngajati, float suprafata, int an) :anDeschidere(an) {
		this->oras = oras;
		this->nrAngajati = nrAngajati;
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = 1500.0f + i * 50.0f;
		}
		this->suprafata = suprafata;
		nrPatiserii++;
	}
	Patiserie(string oras, int nrAngajati, int an) :anDeschidere(an) {
		this->oras = oras;
		this->nrAngajati = nrAngajati;
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = 2000.0f + i * 10.0f;
		}
		this->suprafata = 25;
		nrPatiserii++;
	}
	void afisare() {
		cout << "Oras:" << this->oras << endl;
		cout << "Nr angajati:" << this->nrAngajati << endl;
		if (this->salarii != NULL) {
			cout << "Salarii:";
			for (int i = 0; i < this->nrAngajati; i++) {
				cout << this->salarii[i] << ", ";
			}
		}
		else {
			cout << "Salarii:NULL";
		}
		cout << endl;
		cout << "Suprafata:" << this->suprafata << endl;
		cout << "An deschidere:" << this->anDeschidere << endl;
		cout << "Nr.patiserii:" << Patiserie::nrPatiserii << endl;
	}
	//constructor de copiere
	Patiserie(const Patiserie& p) :anDeschidere(p.anDeschidere) {
		this->oras = p.oras;
		this->nrAngajati = p.nrAngajati;
		if (p.nrAngajati > 0) {
			this->salarii = new float[p.nrAngajati];
			for (int i = 0; i < p.nrAngajati; i++) {
				this->salarii[i] = p.salarii[i];
			}
		}
		else {
			this->salarii = NULL;
		}
		this->suprafata = p.suprafata;
		Patiserie::nrPatiserii++;
	}

	//operator =
	Patiserie operator=(const Patiserie& p) {
		if (this != &p) {
			this->oras = p.oras;
			this->nrAngajati = p.nrAngajati;
			if (p.nrAngajati > 0) {
				if (this->salarii != NULL) {
					delete[]this->salarii;
				}
				this->salarii = new float[p.nrAngajati];
				for (int i = 0; i < p.nrAngajati; i++) {
					this->salarii[i] = p.salarii[i];
				}
			}
			else {
				this->salarii = NULL;
			}
			this->suprafata = p.suprafata;
			Patiserie::nrPatiserii++;
		}
		return *this;
	}

	//operator +
	Patiserie operator+(Patiserie p)const {
		Patiserie temp = *this;
		temp.nrAngajati = this->nrAngajati + p.nrAngajati;
		float* aux = new float[temp.nrAngajati];
		for (int i = 0; i < this->nrAngajati; i++) {
			aux[i] = this->salarii[i];
		}
		for (int i =0; i < p.nrAngajati; i++) {
			aux[i+this->nrAngajati] = p.salarii[i];
		}
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = aux;
		return temp;
	}
	friend Patiserie operator+(float salariu, Patiserie p) {
		Patiserie temp = p;
		if (temp.salarii != NULL) {
			delete []temp.salarii;
		}
		temp.salarii = new float[temp.nrAngajati + 1];
		for (int i = 0; i < p.nrAngajati; i++) {
			temp.salarii[i] = p.salarii[i];
		}
		temp.salarii[temp.nrAngajati] = salariu;
		temp.nrAngajati++;
		return temp;
	}
	//operator<<
	friend ostream& operator<<(ostream& out,const Patiserie& p) {
		out << "Oras:" << p.oras << endl;
		out << "Nr angajati:" << p.nrAngajati << endl;
		if (p.salarii != NULL) {
			out << "Salarii:";
			for (int i = 0; i < p.nrAngajati; i++) {
				out << p.salarii[i] << ", ";
			}
		}
		else {
			cout << "Salarii:NULL";
		}
		out << endl;
		out << "Suprafata:" << p.suprafata << endl;
		out << "An deschidere:" << p.anDeschidere << endl;
		out << "Nr.patiserii:" << Patiserie::nrPatiserii << endl;
		return out;
	}
	////operator >>
	//friend istream& operator>>(istream& in,Patiserie& p) {
	//	cout << "Oras:";
	//	in >> p.oras;
	//	cout << "Nr angajati:";
	//	in >> p.nrAngajati;
	//	if (p.salarii != NULL) {
	//		delete[]p.salarii;
	//	}
	//	if (p.nrAngajati > 0) {
	//		p.salarii = new float[p.nrAngajati];
	//		for (int i = 0; i < p.nrAngajati; i++) {
	//			cout << "Salariul " << i + 1 << ":";
	//			in >> p.salarii[i];
	//		}
	//	}
	//	else {
	//		p.salarii = NULL;
	//	}
	//	cout << "Suprafata:";
	//	in >> p.suprafata;
	//	return in;
	//}
	//operator cast
	explicit operator int() {
		return this->nrAngajati;
	}
	explicit operator float() {
		return this->suprafata;
	}
	//operator ++
	Patiserie operator++() {
		this->suprafata++;
		return *this;
	}
	Patiserie operator++(int) {
		Patiserie copie = *this;
		this->suprafata++;
		return copie;
	}
	//operator index
	float& operator[](int index) {
		if (index >= 0 && index < this->nrAngajati) {
			return this->salarii[index];
		}
		else {
			throw "Indexul se afla in afara limitelor.";
		}
	}
	//operator functie
	

	//destructor
	~Patiserie() {
		if (this->salarii) {
			delete[]this->salarii;
		}
	}
	string getOras() {
		return this->oras;
	}
	void setOras(string oras) {
		if (oras.length() > 2) {
			this->oras = oras;
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
			for (int i = 0; i < nrAngajati; i++) {
				this->salarii[i] = salarii[i];
			}
		}
	}
	float getSuprafata() {
		return this->suprafata;
	}
	void setSuprafata(float suprafata) {
		if (suprafata > 5) {
			this->suprafata = suprafata;
		}
	}
	static int getNrPatiserii() {
		return Patiserie::nrPatiserii;
	}
	int getAnDeschidere() {
		return this->anDeschidere;
	}
};
int Patiserie::nrPatiserii = 0;
int main() {
	Patiserie p1;
	p1.afisare();
	cout << endl;
	Patiserie p2("Bucuresti", 9, 23, 2018);
	p2.afisare();
	cout << endl;
	Patiserie p3("Constanta", 4, 2021);
	p3.afisare();
	cout << endl;
	Patiserie p4 = p2;
	p4.afisare();
	cout << endl;
	Patiserie p5 = p3;
	p5.afisare();
	cout << endl;
	Patiserie p6("Braila", 5, 2016);

	cout << p1.getOras() << endl;
	p1.setOras("Craiova");
	cout << p1.getOras() << endl;
	cout << p2.getNrAngajati() << endl;
	float* vector = new float[7];
	p2.setNrAngajati(7,vector);
	cout << p2.getNrAngajati() << endl;
	cout<<p3.getSuprafata()<<endl;
	p3.setSuprafata(26);
	cout << p3.getSuprafata()<<endl;
	cout<<Patiserie::getNrPatiserii()<<endl;
	cout << p4.getAnDeschidere() << endl;
	cout << endl;
	Patiserie p7 = p6 + p3;
	p7.afisare();
	cout << endl;
	delete[]vector;
	Patiserie p8 = 2000 + p3;
	p8.afisare();
	cout << endl;
	cout << p3 << endl;
	Patiserie p9;
	//cin >> p9;
	cout << endl;
	cout << p9<<endl;
	int NrTotalAngajati= (int)p3;
	cout << NrTotalAngajati<<endl;
	float Suprafata = (float)p2;
	cout << Suprafata<<endl;
	cout << endl;
	Patiserie p10("Braila", 4, 21, 2022);
	p4=++p10;
	cout << p4 << endl;
	p10 = p3++;
	cout << p10<<endl;
	cout << p3;
	try {
		cout << p3[2] << endl;
		cout << p10[3] << endl;
		cout << p10[4]<<endl;
	}
	catch (int exceptie) {

	}
	catch (float exceptie) {

	}
	catch (const char* exceptie) {
		cout << exceptie;
	}
	catch (...) {

	}
}
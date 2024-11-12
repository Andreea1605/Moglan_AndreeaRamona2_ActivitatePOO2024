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
	Cofetarie(const Cofetarie& c) :anDeschidere(c.anDeschidere) {
		this->nume = c.nume;
		this->nrAngajati = c.nrAngajati;
		this->salarii = new float[c.nrAngajati];
		for (int i = 0; i < c.nrAngajati; i++) {
			this->salarii[i] = c.salarii[i];
		}
		this->seAflaInCentrulUnuiOras = c.seAflaInCentrulUnuiOras;
	}

	//OPERATORUL =
	Cofetarie operator=(const Cofetarie& c) {
		if (this != &c) {
			this->nume = c.nume;
			this->nrAngajati = c.nrAngajati;
			if (this->salarii != NULL) {
				delete[]this->salarii;
			}
			this->salarii = new float[c.nrAngajati];
			for (int i = 0; i < c.nrAngajati; i++) {
				this->salarii[i] = c.salarii[i];
			}
			this->seAflaInCentrulUnuiOras = c.seAflaInCentrulUnuiOras;
		}
		return *this;
	}

	//OPERATOR +
	Cofetarie operator+(Cofetarie c2) const {
		Cofetarie temp = *this;
		temp.nrAngajati = this->nrAngajati + c2.nrAngajati;
		float* aux = new float[temp.nrAngajati];
		for (int i = 0; i < this->nrAngajati; i++) {
			aux[i] = this->salarii[i];
		}
		for (int i = 0; i < c2.nrAngajati; i++) {
			aux[i + this->nrAngajati] = c2.salarii[i];
		}
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = aux;
		return temp;
	}

	Cofetarie operator+(float salariu)const {
		Cofetarie temp = *this;
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = new float[temp.nrAngajati + 1];
		for (int i = 0; i < this->nrAngajati; i++) {
			temp.salarii[i] = this->salarii[i];
		}
		temp.salarii[temp.nrAngajati] = salariu;
		temp.nrAngajati++;
		return temp;
	}

	friend Cofetarie operator+(float salariu, Cofetarie c) {
		Cofetarie temp = c;
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = new float[temp.nrAngajati + 1];
		for (int i = 0; i < c.nrAngajati; i++) {
			temp.salarii[i] = c.salarii[i];
		}
		temp.salarii[temp.nrAngajati] = salariu;
		temp.nrAngajati++;
		return temp;
	}

	//operatorul <<
	friend ostream& operator<<(ostream& out, Cofetarie c) {
		out << "Nume:" << c.nume << endl;
		out << "Nr angajati:" << c.nrAngajati << endl;
		out << "Salarii:";
		for (int i = 0; i < c.nrAngajati; i++) {
			out << c.salarii[i] << ", ";
		}
		out << endl;
		out << "An deschidere:" << c.anDeschidere << endl;
		out << "TVA:" << c.TVA << endl;
		out << "Se afla in centrul unui oras: " << (c.seAflaInCentrulUnuiOras ? "DA" : "NU") << endl;
		return out;
	}

	//operator >>
	friend istream& operator>>(istream& input, Cofetarie& c) {
		cout << "Nume:";
		input >> c.nume;
		cout << "Nr angajati:";
		input >> c.nrAngajati;
		if (c.salarii != NULL) {
			delete[]c.salarii;
		}
		if (c.nrAngajati > 0) {
			c.salarii = new float[c.nrAngajati];
			cout << "Salarii:";
			for (int i = 0; i < c.nrAngajati; i++) {
				input >> c.salarii[i];
			}
		}
		else {
			c.salarii = NULL;
		}
		cout << endl;
		cout << "Se afla in centru(1-DA,0-Nu): ";
		input >> c.seAflaInCentrulUnuiOras;
		return input;
	}

	//operatorul index
	float& operator[](int index) {
		if (index >= 0 && index < nrAngajati) {
			return this->salarii[index];
		}
		else {
			throw "Indexul se afla in afara limitelor";
		}
	}

	//operator de cast
	explicit operator int() {
		return this->nrAngajati;
	}

	explicit operator float() {
		float s = 0;
		for (int i = 0; i < this->nrAngajati; i++) {
			s += this->salarii[i];
		}
		return s;
	}
	
	//operator ++
	Cofetarie operator++() {
		this->nrAngajati++;
		return *this;
	}

	Cofetarie operator++(int) {
		Cofetarie aux = *this;
		this->nrAngajati++;
		return aux;
	}
	
	//operator !
	Cofetarie& operator!() {
		this->seAflaInCentrulUnuiOras = !this->seAflaInCentrulUnuiOras;
		return *this;
	}

	//operator +=
	Cofetarie& operator+=(Cofetarie c) {
		*this = *this + c;
		return *this;
	}

	//operator <
	bool operator<(Cofetarie c){
		return this->nrAngajati < c.nrAngajati;
	}

	//operator ==
	bool operator==(Cofetarie c) {
		return this->nrAngajati == c.nrAngajati;
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
		if (this->salarii != NULL) {
			if (index >= 0 && index < this->nrAngajati) {
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
int Cofetarie::TVA = 15;
int main() {
	Cofetarie cofetarie1;
	Cofetarie cofetarie2("Andreea", 6, false, 2018);
	Cofetarie cofetarie3 = cofetarie2;
	cofetarie2.afisare();
	cout << endl;
	cofetarie3.afisare();
	cout << endl;
	Cofetarie cofetarie4("Alice", 8, 2022);
	Cofetarie c5 = cofetarie2 + cofetarie4;
	c5.afisare();
	cout << endl;
	Cofetarie c6 = cofetarie2 + 2000.0f;
	c6.afisare();
	cout << endl;
	Cofetarie c7 = 3000.0f + cofetarie4;
	c7.afisare();
	cout << endl;
	Cofetarie* Cofetarii = new Cofetarie[4];
	cout << "Numarul total de angajati:" << calculeazaNrTotalAngajati(4, Cofetarii) << endl;
	cout << cofetarie2 << endl;
	//cin >> cofetarie2;
	//cout << endl<<cofetarie2<<endl;
	try {
		cout << cofetarie2[1] << endl;
		cout << cofetarie3[0] << endl;
		cout << cofetarie2[-4] << endl;
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
	cout << endl;
	int nrAngajati = (int)cofetarie3;
	cout << "Nr de angajati:"<<nrAngajati<<endl;
	float SalariiTotale = (float)cofetarie2;
	cout << "Salarii Totale:" << SalariiTotale << endl;
	cout << endl;
	cofetarie4 = ++cofetarie2;
	cout << cofetarie4<<endl;
	cout << cofetarie2<<endl;
	cofetarie3 = cofetarie2++;
	cout << cofetarie3<<endl;
	cout << cofetarie2<<endl;
	!cofetarie2;
	cout << cofetarie2<<endl;
	cofetarie2 += cofetarie4;
	cout << cofetarie2 << endl;
	if (cofetarie1< cofetarie2) {
		cout << "Cofetaria 1 are mai multi angajati.";
	}
	else {
		cout << "Cofetaria 2 are mai multi angajati.";
	}
	cout << endl;
	if (cofetarie2 == cofetarie4) {
		cout << "Nr de angajati este acelasi.";
	}
	else {
		cout << "Nr de angajati difera.";
	}
}
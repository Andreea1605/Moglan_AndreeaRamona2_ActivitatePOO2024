#include<iostream>
using namespace std;
class Masina {
private:
	int nrRoti;
	string* producatori;
	string marca;
	float pret;
	static int TVA;
	const int anFabricatie;
public:
	Masina() :anFabricatie(2024), nrRoti(4) { //atributele constante se initializeaza in lista de initializari
		this->marca = "Dacia";
		this->pret = 5000;
		this->producatori = NULL;//nullptr, NULL (alias)
	}

	Masina(int _nrRoti, string marca, float pret, int an) : anFabricatie(an) {
		this->nrRoti = _nrRoti; //parametru
		this->marca = marca;
		this->pret = pret;
		this->producatori = new string[this->nrRoti];
		for (int i = 0; i < nrRoti; i++) {
			this->producatori[i] = "Michelin";
		}
	}

	Masina(const Masina& m) :anFabricatie(m.anFabricatie) {
		this->nrRoti = m.nrRoti;
		this->marca = m.marca;
		this->pret = m.pret;
		this->producatori = new string[m.nrRoti];
		for (int i = 0; i < nrRoti; i++) {
			this->producatori[i] = m.producatori[i];
		}
	}

	~Masina() {
		if (this->producatori != NULL) {
			delete[]this->producatori;
		}
	}
	Masina operator=(const Masina &m) {
		if (&m != this) { // verificare de autoasignare
			this->nrRoti = m.nrRoti;
			this->marca = m.marca;
			this->pret = m.pret;
			if (this->producatori != NULL) { // if(this->producatori) {..}
				delete[] this->producatori;
			}
			this->producatori = new string[m.nrRoti];
			for (int i = 0; i < nrRoti; i++) {
				this->producatori[i] = m.producatori[i];
			}
		}
		return *this;
	}

	string getMarca() {
		return this->marca;
	}
	void setMarca(string marca) {
		if (marca.length() > 2) {
			this->marca = marca;
		}
	}
	float getPret() {
		return this->pret;
	}
	void setPret(float pret) {
		if (pret > 0) {
			this->pret = pret;
		}
	}

	string* getProducatori() {
		return this->producatori;
	}
	string getProducator(int index) {
		if (index >= 0 && index < this->nrRoti) {
			return this->producatori[index];
		}
		else
		{
			return "Nu a fost gasit";
		}
	}

	void setNrRoti(int nrRoti, string* producatori) {
		if (nrRoti > 0) {
			this->nrRoti = nrRoti;
			if (this->producatori != NULL) {
				delete[]this->producatori;
			}
			this->producatori = new string[nrRoti];
			for (int i = 0; i < nrRoti; i++) {
				this->producatori[i] = producatori[i];
			}
		}
	}

	Masina operator+(Masina m) { // un alt parametru este this(primul)
		Masina temp = *this;
		temp.pret = this->pret + m.pret;
		return temp;
	}

	//Magazin operator+(Magazin m2) const{
	//	Magazin temp = *this;
	//	temp.nrAngajati= this->nrAngajati + m2.nrAngajati;
	// float* aux = new float [temp.nrAngajati];
	// for ( int i=0;i< this->nrAngajati; i++) {
	// aux[i]=this->salarii[i];
	// }
	// for ( int i=0; i<m2.nrAngajati; i++){
	// aux[i+ this-> nrAngajati ]= m2.salarii[i];
	// }
	// if ( temp.salarii != NULL ) {
	//  delete[] temp.salarii;
	//	}
	//	temp.salarii= aux;
	// return temp;
	//}

	friend Masina operator+(float pret, Masina m) {

	}

	void afisare() {
		cout << "Marca:" << this->marca << endl;
		cout << "Nr.roti:" << this->nrRoti << endl;
		for (int i = 0; i < nrRoti; i++) {
			if (this->producatori != NULL) {
				cout << this->producatori[i] << ", ";
			}
		}
		cout << endl;
		cout << "Pret:" << this->pret << endl;
		cout << "TVA:" << this->TVA << endl;
		cout << "An fabricatie:" << this->anFabricatie << endl;
	}

	float calculeazaPretTotal() {
		return this->pret + this->pret * ((float)Masina::TVA / 100); //100.0f
	}

	static void modificaTVA(int noulTVA) {
		if (noulTVA > 0) {
			Masina::TVA = noulTVA;
		}
	}

	static float calculeazaPretTotalVector(int nrMasini, Masina* vector) {
		float pretTotal = 0;
		for (int i = 0; i < nrMasini; i++) {
			pretTotal += vector[i].calculeazaPretTotal();
		}
		return pretTotal;
	}
};

int Masina::TVA = 19;

int main() {
	//Masina m;
	//cout << m.getMarca() << endl;
	//m.setMarca("Audi");
	//cout << m.getMarca() << endl;
	//m.afisare();

	//Masina m2(4, "BMW", 45000, 2021);
	//m2.afisare();
	//cout << endl;

	//cout << m2.getProducatori()[1] << endl;// accesam al doilea element din vector, deplasare cu 1
	//cout << m2.getProducator(1) << endl;

	//m2.setNrRoti(6, new string[6]{ "Michelin","Continental","Bridgeston","Pirelli","Hankoover","POO" });
	//cout << m2.getProducatori()[4] << endl;
	//cout << m2.getProducator(3) << endl;

	//Masina m3(m2);
	//Masina m4 = m2;
	//cout << m4.getProducator(2) << endl;
	//cout << m3.getProducator(2);

	//Masina m5;
	//m5 = m2;
	//m2 = m2;

	Masina m1;
	Masina m2(4, "BMW", 45000, 2021);

	int a = 9;
	int b = 6;
	int c = a + b; // c=15

	Masina m3 = m1 + m2;
	Masina m4 = m1.operator+(m2);
	//Masina m5 = m1 + 2000.0f;// m1.operator+(2000.0f);
}
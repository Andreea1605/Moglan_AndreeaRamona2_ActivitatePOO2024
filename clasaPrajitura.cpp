#include <iostream>
using namespace std;
class Prajitura {
private:
	char* denumire;
	int nrCalorii;
	int nrIngrediente;
	float* gramajIngrediente;
	bool esteVegana;
	const int id;
	static int nrPrajituri;
public:
	Prajitura() :id(nrPrajituri++){
		this->denumire = new char[strlen("Amandina") + 1];
		strcpy_s(denumire, strlen("Amandina") + 1, "Amandina");
		this->nrCalorii = 84;
		this->nrIngrediente = 9;
		this->gramajIngrediente = new float[this->nrIngrediente];
		for (int i = 0; i < this->nrIngrediente; i++) {
			this->gramajIngrediente[i] = 2.0f*i + 10.0f;
		}
		this->esteVegana = false;
	}
	Prajitura(const char*denumire,int nrCalorii,int nrIngrediente,float*gramajIngrediente,bool esteVegana):id(nrPrajituri++) {
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
		this->nrCalorii = nrCalorii;
		this->nrIngrediente = nrIngrediente;
		this->gramajIngrediente = new float[nrIngrediente];
		for (int i = 0; i < nrIngrediente; i++) {
			this->gramajIngrediente[i] = gramajIngrediente[i];
		}
		this->esteVegana = esteVegana;
	}
	//constructor de copiere
	Prajitura(const Prajitura& p):id(nrPrajituri++) {
		this->denumire = new char[strlen(p.denumire) + 1];
		strcpy_s(this->denumire, strlen(p.denumire) + 1, p.denumire);
		this->nrCalorii = p.nrCalorii;
		this->nrIngrediente = p.nrIngrediente;
		this->gramajIngrediente = new float[p.nrIngrediente];
		for (int i = 0; i <p.nrIngrediente; i++) {
			this->gramajIngrediente[i] = p.gramajIngrediente[i];
		}
		this->esteVegana = p.esteVegana;
	}
	//operatorul =
	Prajitura operator=(const Prajitura& p) {
		if (this != &p) {
			if (this->denumire != NULL) {
				delete[]this->denumire;
			}
			this->denumire = new char[strlen(p.denumire) + 1];
			strcpy_s(this->denumire, strlen(p.denumire) + 1, p.denumire);
			this->nrCalorii = p.nrCalorii;
			this->nrIngrediente = p.nrIngrediente;
			if (this->gramajIngrediente != NULL) {
				delete[]this->gramajIngrediente;
			}
			this->gramajIngrediente = new float[p.nrIngrediente];
			for (int i = 0; i < p.nrIngrediente; i++) {
				this->gramajIngrediente[i] = p.gramajIngrediente[i];
			}
			this->esteVegana = p.esteVegana;
		}
		return *this;
	}
	//operatorul *=
	Prajitura operator*=(int valoare) {
		this->nrIngrediente = this->nrIngrediente * valoare;
		return *this;
	}
	~Prajitura() {
		if (denumire) {
			delete[]denumire;
		}
		if (this->gramajIngrediente) {
			delete[]gramajIngrediente;
		}
	}
	int getID() {
		return this->id;
	}
	static int getNrPrajituri() {
		return Prajitura::nrPrajituri;
	}
	float getGramajTotal() {
		float suma = 0;
		for (int i = 0; i < this->nrIngrediente; i++) {
			suma = suma + this->gramajIngrediente[i];
		}
		return suma;
	}
	void afisare() {
		cout << "Denumire:" << this->denumire<<endl;
		cout << "Nr calorii:" << this->nrCalorii<<endl;
		cout << "Nr ingrediente:" << this->nrIngrediente << endl;
		if (this->gramajIngrediente!=NULL) {
			cout << "Gramaj ingrediente:";
			for (int i = 0; i < this->nrIngrediente; i++) {
				cout << this->gramajIngrediente[i] << ", ";
			}
		}
		cout << endl;
		cout << "Este vegana?:" << (this->esteVegana ? "DA" : "NU") << endl;
		cout << "ID:" << this->id<<endl;
		cout << "Nr.prajituri:" << Prajitura::nrPrajituri<<endl;
	}
	friend ostream& operator<<(ostream& out, Prajitura p) {
		out << "Denumire:" << p.denumire << endl;
		out << "Nr calorii:" << p.nrCalorii << endl;
		out << "Nr ingrediente:" << p.nrIngrediente << endl;
		if (p.gramajIngrediente != NULL) {
			out << "Gramaj ingrediente:";
			for (int i = 0; i < p.nrIngrediente; i++) {
				out << p.gramajIngrediente[i] << ", ";
			}
		}
		out << endl;
		out << "Este vegana?:" << (p.esteVegana ? "DA" : "NU") << endl;
		out << "ID:" << p.id << endl;
		out << "Nr.prajituri:" << Prajitura::nrPrajituri << endl;
		return out;
	}
	/*friend istream& operator>>(istream& input,Prajitura& p) {
		cout << "Denumire:";
		if (p.denumire != NULL) {
			delete[]p.denumire;
		}
		p.denumire = new char[strlen(p.denumire) + 1];
		strcpy_s(p.denumire, strlen(p.denumire) + 1, p.denumire);
		input >> p.denumire;
		cout << "Nr. calorii:";
		input >> p.nrCalorii;
		cout << "Nr.ingrediente:";
		input >> p.nrIngrediente;
		if (p.gramajIngrediente != NULL) {
			delete[]p.gramajIngrediente;
		}
		p.gramajIngrediente = new float[p.nrIngrediente];
		for (int i = 0; i < p.nrIngrediente; i++) {
			cout << "Gramaj ingrediente " << i + 1 << ":";
			input >> p.gramajIngrediente[i];
		}
		cout << "Este vegana?(1-DA,0-Nu):";
		cin >> p.esteVegana;
		return input;
	}*/
	friend Prajitura operator+(float valoare, Prajitura p) {
		if (valoare > 0) {
			Prajitura temp = p;
			if (temp.gramajIngrediente != NULL) {
				delete[]temp.gramajIngrediente;
			}
			temp.gramajIngrediente = new float[temp.nrIngrediente + 1];
			for (int i = 0; i < p.nrIngrediente; i++) {
				temp.gramajIngrediente[i] = p.gramajIngrediente[i];
			}
			temp.gramajIngrediente[temp.nrIngrediente] = valoare;
			temp.nrIngrediente++;
			return temp;
		}
		else {
			throw "Exceptie input!";
		}
	}
	//operator !=
	bool operator!=(Prajitura p) {
		return strcmp(this->denumire,p.denumire);
		return this->nrCalorii != p.nrCalorii;
		this->nrIngrediente != p.nrIngrediente;
		return this->esteVegana != p.esteVegana;
	}
};
int Prajitura::nrPrajituri = 0;
void main() {
	Prajitura p1;
	p1.afisare();
	cout << endl;
	float* gramajIngrediente2 = new float[5] {35,100,250,15,30};
	Prajitura p2("Foi", 70, 5, gramajIngrediente2, false);
	p2.afisare();
	cout << endl;
	cout << p2.getGramajTotal() << endl;
	Prajitura p3 = p1;
	p3.afisare();
	cout << endl;
	p3 = p2;
	p3.afisare();
	p1 *= 2;
	p1.afisare();
	cout << endl;
	cout << p3<<endl;
	Prajitura p4;
	float* gramajIngrediente5 = new float[6] {100, 150, 200, 240, 50, 25};
	Prajitura p5("Alba-ca-Zapada", 90, 6, gramajIngrediente5, true);
	Prajitura p6;
	Prajitura p7;
	Prajitura p8;
	/*cin >> p4;
	cout << endl;
	cout << p4 << endl;*/
	try {
		p5 = 300.0f + p6;
		cout << p5<<endl;
		p1 = -1.0f + p6;
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
	delete[]gramajIngrediente2;
	delete[]gramajIngrediente5;
	if (p6 != p2) {
		cout << "Prajitura p6 este diferita de prajitura p2.";
	}
	else {
		cout << "Prajiturile sunt identice.";
	}
	cout << endl;
	if (p7 != p8) {
		cout << "Prajitura p7 este diferita de prajitura p8.";
	}
	else {
		cout << "Prajiturile sunt identice.";
	}
}
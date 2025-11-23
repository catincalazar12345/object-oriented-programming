#include<iostream>
using namespace std;

class Student {
	string name;
	int year;
	int numGrades;
	int* grades;
	static int examTax; //o constanta care face parte din clasa Student dar nu variaza 

public:
	Student() {
		cout << "Apel constructor default";
		this->name = "N/A";
		this->year = -1;
		this->numGrades = -1;
		this->grades = nullptr;
	}
	Student(const char* _name) {
		cout << "Apel constructor cu param nume";
		if (strlen(_name) > 3) {
			this->name = _name;
		}
		this->year = -1;
		this->numGrades = -1;
		this->grades = nullptr;
	}
	Student(string _name, int _year, int _numGrades, int* _grades) {
		cout << "Apel constructor cu param nume";
		if (_name.length() > 3) {
			this->name = _name;
		}
		else {
			this->name = "N/A";
		}
		if (_year >= 1) {
			this->year = _year;
		}
		else {
			this->year = -1;
		}
		if (_numGrades >= 1 && _grades!=nullptr) {
			this->numGrades = _numGrades;
			this->grades = new int[this->numGrades];
			for (int i = 0; i < _numGrades; i++) {
				this->grades[i] = _grades[i];
			}
		}
		else {
			this->numGrades = -1;
			this->grades = nullptr;
		}
	}
	void print() {
		cout << "\n----------------------------------";
		cout << "\nName:" << this->name;
		cout << "\nYear:" << this->year;
		cout << "\nNumber of grades:" << this->numGrades;
		cout << "\n";
		for (int i = 0; i < this->numGrades; i++) {
			cout << this->grades[i]<<" ";
		}
	}
	~Student() {
		//trebuie sa dezaloc tot ce e de sters
		cout << "\nApel destructor";
		if (this->grades != nullptr) {
			delete[] this->grades;
			this->grades = nullptr;
		}
	}
	
};
int Student::examTax = 100;

int main() {
	Student s;
	s.print();
	int* v;
	v = new int[6] { 10, 10, 9, 7, 8, 7 };
	Student s2("Anita", 2, 6, v);
	s2.print();
	return 0;
}
#include <iostream>
using namespace std;

class Person{
public:
	Person(){}
	virtual void show(){
	}
};

class personA:public Person{
public:
	personA(string name){
		this->name = name;
	}
	void show(){
		cout << "decorator's " << this->name << endl;
	}
private:
	string name;	
};

class Finery:public Person{
public:
	void Decorate(Person *component){
		this->component = component;
	}
	void show(){
		if(component!=NULL)
			component->show();
	}
private:
	Person *component;
};

class TShirts:public Finery{
public:
	void show(){
		cout << "Big TShirts| ";
		Finery::show();
	}
};

class BigTrouser:public Finery{
public:
	void show(){
		cout << "Big Trouser| ";
		Finery::show();
	}
};

class Tie:public Finery{
public:
	void show(){
		cout << "Tie| ";
		Finery::show();
	}
};

class Suite:public Finery{
public:
	void show(){
		cout << "Suite| ";
		Finery::show();
	}
};

int main(int argc,char*argv[]){
	personA *mm = new personA("AA");
	personA *gg = new personA("CC");
	cout << "First Decorator:" << endl;
	TShirts *ts = new TShirts();
	BigTrouser *bt = new BigTrouser();

	ts->Decorate(mm);
	bt->Decorate(ts);
	bt->show();

	cout << " and " << endl;

	Suite *st = new Suite();
	Tie *te = new Tie();

	st->Decorate(gg);
	te->Decorate(st);
	te->show();

	return 0;
}

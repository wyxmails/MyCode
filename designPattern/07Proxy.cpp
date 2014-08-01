#include <iostream>
#include <string>
using namespace std;

class Girl{
public:
	Girl(string name){
		girlname = name;
	}
	string name(){
		return this->girlname;
	}
private:
	string girlname;
};

class interface{
public:
	virtual void giveDoll(){};
	virtual void giveFlower(){};
	virtual void giveChocolate(){};
};

class persuiter{
public:
	persuiter(Girl *mm){
		this->mm = mm;
	}
	void giveDoll(){
		cout << mm->name() << " doll for you!" << endl;
	}
	void giveFlower(){
		cout << mm->name() << " flower for you!" << endl;
	}
	void giveChocolate(){
		cout << mm->name() << " chocolate for you!" << endl;
	}
private:
	Girl *mm;
};
class Proxy{
public:
	Proxy(Girl *mm){
		pp = new persuiter(mm);
	}
	void giveDoll(){
		pp->giveDoll();
	}
	void giveFlower(){
		pp->giveFlower();
	}
	void giveChocolate(){
		pp->giveChocolate();
	}
private:
	persuiter *pp;
};

int main(int argc,char*argv[]){
	Girl *mm = new Girl("jiaojiao");
	Proxy *px = new Proxy(mm);
	px->giveDoll();
	px->giveFlower();
	px->giveChocolate();
	return 0;
}

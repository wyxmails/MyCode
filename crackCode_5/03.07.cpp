/*
 An animal shelter holds only dogs and cats, 
 and operates on a strictly "first in, first out" basis. 
 People must adopt either the "oldest" (based on arrival time) 
 of all animals at the shelter, 
 or they can select whether they would prefer a dog or a cat 
 (and will receive the oldest animal of that type). 
 They cannot select which specific animal they would like. 
 Create the data structures to maintain this system and 
 implement operations such as enqueue, dequeueAny, dequeueDog and 
 dequeueCat. You may use the builtin LinkedList data structure.
 */

#include <iostream>
#include <queue>
using namespace std;

struct Animal{
	string name;
	int order;
};

class DogCatList{
public:
	DogCatList(){order=0;}
	void enqueue(string animal,int type);//0:dog 1: cat
	string dequeueAny();
	string dequeueDog();
	string dequeueCat();
private:
	int order;
	queue<Animal> dogs;
	queue<Animal> cats;
};

void DogCatList::enqueue(string animal,int type){
	Animal aa;
	aa.name = animal;
	aa.order = order;
	order++;
	if(type==0)
		dogs.push(aa);
	else
		cats.push(aa);
}
string DogCatList::dequeueAny(){
	Animal dog,cat;
	if(dogs.empty()&&cats.empty())
		return "";
	if(!dogs.empty()){
		dog = dogs.front();
		if(!cats.empty()){
			cat = cats.front();
			if(dog.order<cat.order){
				dogs.pop();
				return dog.name;
			}else{
				cats.pop();
				return cat.name;
			}
		}
		dogs.pop();
		return dog.name;
	}
	cat = cats.front();
	cats.pop();
	return cat.name;
}
string DogCatList::dequeueDog(){
	if(dogs.empty()) return "";
	Animal dog = dogs.front();
	dogs.pop();
	return dog.name;
}
string DogCatList::dequeueCat(){
	if(cats.empty()) return "";
	Animal cat = cats.front();
	cats.pop();
	return cat.name;
}

int main(int argc,char*argv[]){
	return 0;
}

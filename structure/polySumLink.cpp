#include <iostream>
#include <string>
using namespace std;

struct Poly{
	char type;
	int coef;
	int power;
	Poly* next;
};
Poly* process(string line){
	Poly*p1,*h1,*t1,*p2;
	p1=h1=t1=p2=NULL;
	string s;
	int pos = line.find_first_of(' ');
	while(pos!=string::npos){
		p1 = new Poly;
		s = line.substr(0,pos);
		line = line.substr(pos+1,line.size()-pos);
		if(s[0]=='-'){
			p1->type = s[0];
			p1->coef = 0;
			for(int i=1;i<s.size();++i){
				p1->coef = p1->coef*10 + s[i]-'0';
			}
		}else{
			p1->type = '+';
			p1->coef = 0;
			for(int i=0;i<s.size();++i){
				p1->coef = p1->coef*10 + s[i]-'0';
			}
		}
		pos = line.find_first_of(' ');
		s = line.substr(0,pos);
		line = line.substr(pos+1,line.size()-pos);
		p1->power=0;
		for(int i=0;i<s.size();++i){
			p1->power = p1->power*10 + s[i] - '0';
		}
		p1->next = NULL;
		if(t1==NULL){
			h1 = t1 = p1;
		}else{
			p2 = h1;
			p1->next = p2;
			while(p2!=NULL){
				if(p2->power<p1->power){
					if(p2==h1){
					   	h1 = p1;
					}else{
						p1->next->next = p1;
						p1->next = p2;
					}
					break;
				}
				p1->next = p2;
				p2 = p2->next;
			}
			if(p2==NULL){
				p1->next = NULL;
				t1->next = p1;
				t1 = p1;
			}
		}
		pos = line.find_first_of(' ');
	}
	return h1;
}
void cntsum(Poly*h1,Poly*h2){
	Poly *s1,*s2;
	s1=h1;
	s2=h2;
	int cnt=0;
	while(s1!=NULL||s2!=NULL){
		if(s1!=NULL&&s2!=NULL&&s1->power==s2->power){
			if(s1->type==s2->type){
				if(s1->coef+s2->coef==0){
					s1 = s1->next;
					s2 = s2->next;
					continue;
				}
				cout << "[";
				if(s1->type=='-') cout << "-";
				cout << s1->coef+s2->coef << " " << s1->power << "]";
			}else{
				if(s1->coef>s2->coef){
					cout << "[";
					if(s1->type=='-') cout << "-";
					cout << s1->coef-s2->coef << " " << s1->power << "]";
				}else if(s2->coef>s1->coef){
					cout << "[";
					if(s2->type=='-') cout << "-";
					cout << s2->coef-s1->coef << " " << s1->power << "]";
				}
			}
			s1 = s1->next;
			s2 = s2->next;
		}else if((s1!=NULL&&s2!=NULL&&s1->power>s2->power)||s1!=NULL&&s2==NULL){
			if(s1->coef>0){
				cout << "[";
				if(s1->type=='-') cout << "-";
				cout << s1->coef << " " << s1->power << "]";
			}
			s1 = s1->next;
		}else if((s1!=NULL&&s2!=NULL&&s1->power<s2->power)||s2!=NULL&&s1==NULL){
			if(s2->coef>0){
				cout << "[";
				if(s2->type=='-') cout << "-";
				cout << s2->coef << " " << s2->power << "]";
			}
			s2 = s2->next;
		}
	}
	cout << endl;
	return ;
}
int main(int argc,char*argv[]){
	Poly *h1,*h2;
	h1=h2=NULL;
	string line;
	getline(cin,line);
	h1 = process(line);
	getline(cin,line);
	h2 = process(line);
	cntsum(h1,h2);
	return 0;
}

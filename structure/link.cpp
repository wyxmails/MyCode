#include <iostream>
#include <cstdio>
using namespace std;

struct lStudent{
	char ID[20];
	char name[20];
	float score;
	lStudent *next;
};
lStudent *position(lStudent *head,lStudent *tail,lStudent *student){
	lStudent *temp1,*temp2;
	temp1=temp2=head;
	while(temp1!=NULL){
		if(temp1->score>student->score){
			if(temp1==temp2) return NULL;
			return temp2;
		}
		temp2 = temp1;
		temp1 = temp1->next;
	}
	return tail;
}
int main(int argc,char*argv[]){
	char ID[20];
	char name[20];
	float score;
	lStudent *head,*tail;
	lStudent *student;
	head=tail=student=NULL;
	while(1){
		student = new lStudent;
		scanf("%s%s%f",student->ID,student->name,&student->score);
		if(student->score<0){
			delete(student);
			break;
		}
		student->next = NULL;
		if(tail==NULL){
			head = tail = student;
			continue;
		}
		lStudent *temp = position(head,tail,student);
		if(temp==NULL){
			student->next = head;
			head = student;
		}else{
			if(temp->next!=NULL){
				cout << student->score;
				student->next = temp->next;
				temp->next = student;
			}else{
				temp->next = student;
				tail = student;
			}
		}
	}
	cout << "output========" << endl;
	student = head;
	while(student!=NULL){
		cout << student->ID << " " << student->name << " " << student->score << endl;
		student = student->next;
		delete(head);
		head = student;
	}
	return 0;
}

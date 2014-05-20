#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

struct Task{
	string name;
	string start;
	string end;
	int cost;
	string label;
	Task* next;
};

struct Resource{
	string num;
	Task* tnext;
	Resource* rnext;
};

int count(string start,string end){
	int year,month,day,hour,min,sec;
	int sy,sm,sd,sh,smin,ssec,ey,em,ed,eh,emin,esec;
	sscanf(start.c_str(),"%d-%d-%d %d:%d:%d",&sy,&sm,&sd,&sh,&smin,&ssec);
	sscanf(end.c_str(),"%d-%d-%d %d:%d:%d",&ey,&em,&ed,&eh,&emin,&esec);
	year = ey-sy;
	month = em-sm;
	day = ed-sd;
	hour = eh-sh;
	min = emin-smin;
	sec = esec-ssec;
	return (year*365+month*30+day)*24*3600+hour*3600+min*60+sec;
}

int main(int argc,char*argv[]){
	ifstream ifs("aaaa");
	string str,date,stime,sectime,desc,computer;
	int pos;
	Task* task,*thead,*ttail;
	Resource* res,*reshead,*restail;
	task=thead=ttail=NULL;
	res=reshead=restail=NULL;
	while(getline(ifs,str)){
		pos = str.find_first_of(' ');
		date = str.substr(0,pos);
		str = str.substr(pos+1,str.size()-pos);
		pos = str.find_first_of(' ');
		stime = str.substr(0,pos);
		sectime = date + " " + stime;
		str = str.substr(pos+1,str.size()-pos);
		pos = str.find_last_of(' ');
		computer = str.substr(pos+1,str.size()-pos);
		desc = str.substr(0,pos);
		cout << "desc: " << desc << " computer: " << computer << endl;
		if(desc.find("created")!=string::npos){
			res = new Resource;
			res->num = computer;
			res->tnext = NULL;
			res->rnext = NULL;
			if(restail==NULL){
				reshead=restail=res;
				continue;
			}
		}else if(desc.find("started")!=string::npos){
			task = new Task;
			task->name = desc.substr(0,desc.find_first_of(' '));
			task->start = sectime;
			task->end = "";
			task->cost = 0;
			task->label = computer;
			task->next = NULL;
			res = reshead;
			while(res!=NULL){
				if(res->num==computer)
					break;
			}
			if(res==NULL) continue;
			if(res->tnext==NULL){
				res->tnext = task;
			}else{
				Task*tmp1 = res->tnext;
				Task*tmp2 = tmp1;
				while(tmp1->start.compare(task->start)<=0){
				   	tmp2 = tmp1;
					tmp1 = tmp1->next;
				}
				task->next = tmp2->next;
				tmp2->next = task;
				tmp1=tmp2=NULL;
			}
		}else if(desc.find("finished")!=string::npos){
			string name = desc.substr(0,desc.find_first_of(' '));
			res = reshead;
			while(res!=NULL){
				if(res->num==computer)
					break;
			}
			if(res==NULL) continue;
			if(res->tnext==NULL){
				continue;
			}else{
				Task*tmp1 = res->tnext;
				while(tmp1!=NULL&&tmp1->name.compare(name)!=0){
					tmp1 = tmp1->next;
				}
				tmp1->end = sectime;
				tmp1->cost = count(tmp1->start,tmp1->end);
				tmp1 = NULL;
			}
		}		
	}
	res = reshead;
	while(res!=NULL){
		task = res->tnext;
		cout << res->num << endl;
		while(task!=NULL){
			cout << task->start << " " << task->cost << " " << task->name << endl;
			task = task->next;
		}
		res = res->rnext;
	}
	return 0;
}

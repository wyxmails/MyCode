#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

typedef struct agent{
	char code;
	int stime;
	int wtime;
	int curfloor;
	bool checkin;
	bool checkout;
	map<int,int> maproomtime;
	friend bool operator> (const agent&a,const agent&b){
		if(a.stime!=b.stime)
			return a.stime>b.stime;
		else
			return a.code>b.code;
	}
	friend bool operator< (const agent&a,const agent&b){
		if(a.stime!=b.stime)
			return a.stime<b.stime;
		else
			return a.code<b.code;
	}
}agent;

typedef struct process{
	int stime;
	int etime;
	string dscrp;
}process;

typedef struct roomdsc{
	bool occupied;
	int releasetime;
}roomdsc;

int main(int argc,char*argv[]){
	roomdsc roomstate[100];
	roomdsc elevator[11];
	for(int i=0;i<100;++i){
		roomstate[i].occupied = false;
		roomstate[i].releasetime = 0;
	}
	for(int i=0;i<11;++i){
		elevator[i].occupied = false;
		elevator[i].releasetime = 0;
	}
	vector<agent> vecAgent;
	map<int,int> tmpmap;
	priority_queue<agent,vector<agent>,greater<agent> > mypq;
	agent tmpagent;
	char tmpchar;
	string strtime;
	int room,staytime,minSTime=24*3600;
	cin>>tmpchar;
	vecAgent.clear();
	while(tmpchar!='.'){
		tmpmap.clear();
		cin>>strtime;
		tmpagent.code = tmpchar;
		tmpagent.stime = ((int)(strtime[0]-'0')*10+(int)(strtime[1]-'0'))*3600 
			+ ((int)(strtime[3]-'0')*10+(int)(strtime[4])-'0')*60
			+ (int)(strtime[6]-'0')*10+(int)(strtime[7]-'0');
		tmpagent.checkin = false;
		tmpagent.checkout = false;
		tmpagent.curfloor = 1;
		tmpagent.wtime = 0;
		if(tmpagent.stime<minSTime) minSTime=tmpagent.stime;
		cin>>room;
		while(room!=0){
			cin>>staytime;
			tmpmap[room] = staytime;
			cin>>room;
		}
		tmpagent.maproomtime = tmpmap;
		mypq.push(tmpagent);
		cin>>tmpchar;
	}
	//cout << "finish cin" << endl;
	map<char,vector<process> > mapProc;
	map<int,int>::iterator it;
	vector<process> vectmp;
	process tmpproc;
	stringstream ss;
	int mapsize,roomnum;
	int count=0;
	//process the priority_queue
	//cout << "start mypq" << endl;
	while(!mypq.empty()){
		tmpagent.maproomtime.clear();
		tmpagent = mypq.top();
		mapsize = tmpagent.maproomtime.size();
		if(mapsize){
			it = tmpagent.maproomtime.begin();
			roomnum = ((*it).first/100-1)*10+(*it).first%100-1;
		}
		if(tmpagent.checkout){
			tmpproc.stime = tmpagent.stime;
			tmpproc.etime = tmpagent.stime+30;
			tmpproc.dscrp = "Exit";
			mapProc[tmpagent.code].push_back(tmpproc);//output
			mypq.pop();
			continue;
		}
		//checkin
		if(!tmpagent.checkin){
			//cout << "checkin" << endl;
			tmpagent.checkin = true;
			tmpproc.stime = tmpagent.stime;
			tmpagent.stime += 30;
			tmpproc.etime = tmpagent.stime;
			tmpproc.dscrp = "Entry";
			//output
			vectmp.clear();
			vectmp.push_back(tmpproc);
			mapProc[tmpagent.code] = vectmp;		
			if(tmpagent.stime>minSTime) minSTime = tmpagent.stime;
			mypq.pop();
			mypq.push(tmpagent);
			continue;
		}
		if(!mapsize&&tmpagent.curfloor==1){
			//cout << "empty" << endl;
			tmpagent.checkout = true;
			mypq.pop();
			mypq.push(tmpagent);
			continue;
		}
		//stay
		if(mapsize&&(!roomstate[roomnum].occupied||
				roomstate[roomnum].releasetime<=tmpagent.stime)
				&&tmpagent.curfloor==(*it).first/100){
			//cout << "stay" << endl;
			roomstate[roomnum].occupied = true;
			//output wait in front a room
			if(tmpagent.wtime>0){
				tmpproc.stime = tmpagent.stime-tmpagent.wtime;
				tmpproc.etime = tmpagent.stime;
				ss.clear();
				if((*it).first<1000) ss<<0;
				ss<<(*it).first;
				ss>>tmpproc.dscrp;
				tmpproc.dscrp = "Waiting in front of room " + tmpproc.dscrp;
				mapProc[tmpagent.code].push_back(tmpproc);//output
				tmpagent.wtime=0;
			}
			//stay
			tmpproc.stime = tmpagent.stime;
			tmpagent.stime += (*it).second;
			tmpproc.etime = tmpagent.stime;
			roomstate[roomnum].releasetime = tmpagent.stime;
			ss.clear();
			if((*it).first<1000) ss<<0;
			ss<<(*it).first;
			ss>>tmpproc.dscrp;
			tmpproc.dscrp = "Stay in room " + tmpproc.dscrp;
			mapProc[tmpagent.code].push_back(tmpproc); //output
			//Transfer
			it++;
			if(it!=tmpagent.maproomtime.end()){
				tmpproc.stime = tmpagent.stime;
				tmpagent.stime += 10;
				tmpproc.etime = tmpagent.stime;
				if((*it).first/100==tmpagent.curfloor){  //transfer from room to room
					it--;
					ss.clear();
					if((*it).first<1000) ss<<0;
					ss<<(*it).first;
					it++;
					ss>>tmpproc.dscrp;
					tmpproc.dscrp = "Transfer from room " + tmpproc.dscrp + " to room ";
					ss.clear();
					if((*it).first<1000) ss<<0;
					ss<<(*it).first;
					string tmp;
					ss>>tmp;
					tmpproc.dscrp += tmp;
					mapProc[tmpagent.code].push_back(tmpproc);//output
				}else{		//transfer from room to elevator
					ss.clear();
					it--;
					if((*it).first<1000) ss<<0;
					ss<<(*it).first;
					ss>>tmpproc.dscrp;
					tmpproc.dscrp = "Transfer from room " + tmpproc.dscrp + " to elevator";
					mapProc[tmpagent.code].push_back(tmpproc);//output
				}
			}else{
				if(tmpagent.curfloor==1) tmpagent.checkout=true;
				else{
					tmpproc.stime = tmpagent.stime;
					tmpagent.stime += 10;
					tmpproc.etime = tmpagent.stime;
					ss.clear();
					it--;
					if((*it).first<1000) ss<<0;
					ss<<(*it).first;
					ss>>tmpproc.dscrp;
					tmpproc.dscrp = "Transfer from room " + tmpproc.dscrp + " to elevator";
					mapProc[tmpagent.code].push_back(tmpproc);//output
				}
			}
			it = tmpagent.maproomtime.begin();
			tmpagent.maproomtime.erase(it);
			if(tmpagent.stime>minSTime) minSTime = tmpagent.stime;
			mypq.pop();
			mypq.push(tmpagent);
			continue;
		}
		//elevator
		it = tmpagent.maproomtime.begin();
		if(mapsize&&tmpagent.curfloor!=(*it).first/100||
				!mapsize&&tmpagent.curfloor!=1){
			//cout << "elevator" << endl;
			//wait elevator
			if(tmpagent.stime%5){
				tmpagent.wtime += 5-tmpagent.stime%5;
				tmpagent.stime += tmpagent.wtime;
				if(minSTime<tmpagent.stime) minSTime=tmpagent.stime;
				mypq.pop();
				mypq.push(tmpagent);
				continue;
			}
			//wait in elevator line
			if(tmpagent.stime<elevator[tmpagent.curfloor].releasetime){
				tmpagent.wtime += elevator[tmpagent.curfloor].releasetime-tmpagent.stime;
				tmpagent.stime = elevator[tmpagent.curfloor].releasetime;
				if(minSTime<tmpagent.stime) minSTime=tmpagent.stime;
				mypq.pop();
				mypq.push(tmpagent);
				continue;
			}
			//output wait in elevator
			if(tmpagent.wtime>0){
				tmpproc.stime = tmpagent.stime-tmpagent.wtime;
				tmpproc.etime = tmpagent.stime;
				tmpproc.dscrp = "Waiting in elevator queue";
				mapProc[tmpagent.code].push_back(tmpproc);//output
				tmpagent.wtime=0;
			}
			//stay in elevator
			elevator[tmpagent.curfloor].releasetime = tmpagent.stime+5;
			tmpproc.stime = tmpagent.stime;
			if(mapsize)
				tmpagent.stime += 30*abs((*it).first/100-tmpagent.curfloor);
			else
				tmpagent.stime += 30*(tmpagent.curfloor-1);
			tmpproc.etime = tmpagent.stime;
			tmpproc.dscrp = "Stay in elevator";
			mapProc[tmpagent.code].push_back(tmpproc);//output
			if(!mapsize) tmpagent.checkout = true;
			else{
				tmpagent.curfloor = (*it).first/100;
				tmpproc.stime = tmpagent.stime;
				tmpagent.stime += 10;
				tmpproc.etime = tmpagent.stime;
				ss.clear();
				if((*it).first<1000) ss<<0;
				ss<<(*it).first;
				ss>>tmpproc.dscrp;
				tmpproc.dscrp = "Transfer from elevator to room " + tmpproc.dscrp;
				mapProc[tmpagent.code].push_back(tmpproc);//output
			}
			if(minSTime<tmpagent.stime) minSTime=tmpagent.stime;
			mypq.pop();
			mypq.push(tmpagent);
			continue;
		}
		//room occupied
		if(mapsize&&roomstate[roomnum].occupied){
			//cout << "occupied" << endl;
			tmpagent.wtime += roomstate[roomnum].releasetime-tmpagent.stime;
			tmpagent.stime = roomstate[roomnum].releasetime;
			if(minSTime<tmpagent.stime) minSTime=tmpagent.stime;
			mypq.pop();
			mypq.push(tmpagent);
		}	
	}
	//cout << "finish process " << endl;
	map<char,vector<process> >::iterator itout;
	vector<process>::iterator itvec;
	int hours,minutes,seconds;
	for(itout=mapProc.begin();itout!=mapProc.end();++itout){
		cout << (*itout).first << endl;
		for(itvec=(*itout).second.begin();itvec!=(*itout).second.end();++itvec){
			hours = (*itvec).stime/3600;
			minutes = (*itvec).stime%3600/60;
			seconds = (*itvec).stime%60;
			cout << setw(2) << hours << setfill('0') << ":" ;
			cout << setw(2) << minutes << setfill('0')<< ":" ;
			cout << setw(2) << seconds << setfill('0') << " ";
			hours = (*itvec).etime/3600;
			minutes = (*itvec).etime%3600/60;
			seconds = (*itvec).etime%60;
			cout << setw(2) << hours << setfill('0') << ":" ;
			cout << setw(2) << minutes << setfill('0')<< ":" ;
			cout << setw(2) << seconds << setfill('0') << " ";
			cout << (*itvec).dscrp << endl;
		}
		cout << endl;
	}
	return 0;
}

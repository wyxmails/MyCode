/*
 All three rounds were coding round

Round 1 45 mins
Reverse a Link list (code it)
Find two elements in sorted array which sums to a given number (code it)
Difference between  C++ and java
Advantage and disadvantage Garbage memory collector in Java

Round 2 45 mins
Write the following function
double  solveForX(string s) {   }
input will be linear equation in x with +1 or -1 coefficient.
output will be value of x.
s can be as follows
i/p   x + 9 – 2 -4 + x = – x + 5 – 1 + 3 – x   o/p  1.00
i/p    x + 9 -1 = 0  o/p -8.00
i/p    x + 4 = – 3 – x  o/p  -3.500
it has second part
if the i/p string can have ‘(‘ or  ‘)’
x + 9 – 2 -(4 + x) = – (x + 5 – 1 + 3) – x
x + 9 + (3 + – x – ( -x + (3 – (9 – x) +x = 9 -(5 +x )

round 3
Sort an array  using below operation
An operation called flip which runs in O(1)  <<<<< important this is given
for an array ‘a’
a.flip(index)  this operation will reverse the array from index to end of the array
for eg:
a[]= {1,4,0,6,7};
a.flip(0) = 7,6,0,4,1 // reverse from 0 to end
a.flip(2) = 1,4,7,6,0 // reverse from 2nd index to end
a.flip(4) 1,4,0,6,7 // no change in array reverse from end to end
First do it in O(n^2)
Then in O(nlogn)
 */

#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
	int val;
	ListNode*next;
	ListNode(int v):val(v),next(NULL){}
};

ListNode*reverse(ListNode*head){
	if(head==NULL||head->next==NULL) return head;
	ListNode*next,*run;
	run=head;head=NULL;
	while(run!=NULL){
		next = run->next;
		run->next = head;
		head = run;
		run = next;
	}
	return head;
}

vector<int> twoSum(const vector<int>&vec,int target){
	int n = vec.size();
	vector<int> res;
	for(int l=0,r=n-1;l<r;){
		int sum = vec[l]+vec[r];
		if(sum==target){
			res.push_back(vec[l]);
			res.push_back(vec[r]);
			return res;
		}else if(sum>target) r--;
		else l++;
	}
	return res;
}

double solveForX(const string&s){
	double coef=0,val=0;
	bool left=true;
	int n = s.size();
	int i=0;
	if(s[i]=='+'||s[i]=='-') i++;
	for(;i<n;i+=2){
		if(i>0&&s[i-1]=='='){
		   	left = false;
			if(s[i]=='-'||s[i]=='+'){
				i--; continue;
			}
		}
		if(s[i]=='x'){
			if(left){
				if(i==0||s[i-1]=='+') coef++;
				else coef--;
			}else{
				if(s[i-1]=='-') coef++;
				else coef--;
			}
		}else{
			int v=s[i]-'0';
			if(left){
				if(i==0||s[i-1]=='+') val -= v;
				else val += v;
			}else{
				if(s[i-1]=='-') val -= v;
				else val += v;
			}
		}
	}
	if(coef==0){
		cout << "No X, wrong expression" << endl;
		return -1;
	}
	return double(val/coef);
}

double solveForXp(const string&s){
	double coef=0,val=0;
	bool normal = true;
	bool par = false;
	int n = s.size();
	for(int i=0;i<n;++i){
		if(s[i]=='+'||s[i]=='-')
				continue;
		if(s[i]=='('&&i>0&&s[i-1]=='-'){
			normal = !normal;
			par = true;
			continue;
		}
		if(s[i]==')'&&par){
			normal = !normal;
			par = false;
			continue;
		}
		if(s[i]=='='){
			normal = !normal;
			continue;
		}
		if(s[i]=='x'){
			if(i==0||s[i-1]=='+'||s[i-1]=='('||s[i-1]=='=')
				coef += normal?1:-1;
			else coef += normal?-1:1;
		}else{
			int v = s[i]-'0';
			if(i==0||s[i-1]=='+'||s[i-1]=='('||s[i-1]=='=')
				val += normal?-v:v;
			else val += normal?v:-v;
		}	
	}
	if(coef==0){
		cout << "No X, wrong expression" << endl;
		return -1;	
	}
	return val/coef;
}

void flip(int i,vector<int> &vec){
	
}

void move(vector<int>&vec,int l,int r){
}

int partition(vector<int>&vec,int l,int r){
	while(l<r&&vec[l]<pivol) l++;
	while(r>l&&vec[r]>pivol) r--;
}
void mySort(vector<int>&vec){
	int n = vec.size();
	int pivol = vec[n/2];
	int l=0,r=n-1;

}

int main(int argc,char*argv[]){
	//reverse linked list
	ListNode *head = new ListNode(1);
	ListNode *tail = new ListNode(2);
	head->next = tail;
	ListNode *ln = new ListNode(3);
	tail->next = ln;
	tail = ln;
	ln = new ListNode(4);
	tail->next = ln;
	ln = reverse(head);
	cout << "reverse linked list" << endl;
	while(ln!=NULL){
		cout << ln->val << " ";
		ln = ln->next;
	}
	cout << endl;
	//twoSum
	vector<int> vec;
	vec.push_back(1);vec.push_back(3);vec.push_back(5);vec.push_back(9);
	vector<int> res = twoSum(vec,14);
	cout << "two sum" << endl;
	if(res.size()==2)
		cout << res[0] << " " << res[1] << endl;
	//i/p   x + 9 – 2 -4 + x = – x + 5 – 1 + 3 – x   o/p  1.00
	//i/p    x + 9 -1 = 0  o/p -8.00
	//i/p    x + 4 = – 3 – x  o/p  -3.500
	string s = "x+9-2-4+x=-x+5-1+3-x";
	cout << "solveForX: " << endl << solveForX(s) << endl;
	s = "x+4=-3-x";
	cout << solveForX(s) << endl;
	s = "x+9-1=0";
	cout << solveForX(s) << endl;
	//x + 9 – 2 -(4 + x) = – (x + 5 – 1 + 3) – x
	//x + 9 + (3 + – x – ( -x + (3 – (9 – x) +x = 9 -(5 +x )
	cout << "solveForXp: " << endl;
	s = "x+9-2-(4+x)=-(x+5-5+3)-x";
	cout << solveForXp(s) << endl;
	s = "x+9+3+-x-x+3-(9-x)+x=9-(5+x)";
	cout << solveForXp(s) << endl;


	return 0;
}

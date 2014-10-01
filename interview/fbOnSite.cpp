#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 alg1:
 regular expression:
 . represent any character
 * represent previous character 0 to n times, if the previous is . then repeat the . matches character 0 to n times.
 s1 is a string, t1 is a pattern contains characters and . and *
 */
bool isMatch(char*s1,char*t1){
	if(*t1=='\0') return (*s1=='\0');

	if(*(t1+1)!='*')
		return (*t1==*s1||(*t1=='.'&&*s1!='\0'))&&isMatch(s1+1,t1+1);
	char *cur = s1;
	while(*s1==*t1||(*t1=='.'&&*s1==*cur)){
		if(isMatch(s1,t1+2)) return true;
		s1++;
	}
	return isMatch(s1,t1+2);
}

/*
 alg2:
 move zeros to the end of the array
 */
void mvZeros(vector<int> &vec){
	int n = vec.size();
	if(n<=1) return;
	int l=0,r=n-1;
	while(l<r){
		while(r>l&&vec[r]==0) r--;
		while(l<r&&vec[l]!=0) l++;
		if(l<r){
			vec[l] = vec[r];
			vec[r] = 0;
		}
	}
}

/*
alg3:
hex expression
examples:
dic: 012ae,aec21
lookup 012 return 0
insert 013
lookup 012 return 012
insert aec31
lookup aec21 return aec2
lookup 012 return 012a
functions:
insert(...)
lookup(...)
 */

int L=0;
struct TreeNode {
	char c;
	vector<TreeNode*> children;
	TreeNode(char c):c(c){}
};
void insert(TreeNode *root,string s,int len=0,bool flag = false){
	if(s.size()==0) return;
	vector<TreeNode*> &child = root->children;
	len++;
	if(child.size()==0){
		TreeNode*n = new TreeNode(s[0]);
		if(!flag){
			flag = true;
			if(len>L) L = len;
		}
		child.push_back(n);
		s = s.substr(1);
		insert(n,s,len,flag);
	}else{
		int i=0;
		bool find = false;
		for(;i<child.size();++i){
			if(child[i]->c==s[0]){
				find = true;
				break;
			}
		}
		if(find){
			s = s.substr(1);
			insert(child[i],s,len,flag);	
		}else{
			TreeNode*n = new TreeNode(s[0]);
			if(!flag){
				flag = true;
				if(len>L) L = len;
			}
			child.push_back(n);
			s = s.substr(1);
			insert(n,s,len,flag);
		}
	}
}

string lookup(TreeNode*root,string s){
	int n = s.size();
	int cnt=0;
	vector<TreeNode*> child;
	string res = "";
	while(cnt<L){
		child = root->children;
		if(child.size()==1){
			root = child[0];
			res += root->c;
			cnt++;
		}else{
			if(cnt<n){
				int i=0;
				root = NULL;
				for(;i<child.size();++i){
					if(child[i]->c==s[cnt]){
						root = child[i];
						cnt++;
						break;
					}
				}
			}
			if(cnt>=n||root==NULL){
				cerr << "Not found" << endl;
				return s;
			}
			res += root->c;
			cnt++;
		}
	}
	return res;
}

/*
 alg4:
 given an array of white/blue/red balls, sort in white-blue-red order. 
*/
struct Ball{
	string color;
	Ball(string clr):color(clr){}
};
void exchange(vector<Ball>&balls,int l,int r){
	Ball b = balls[l];
	balls[l] = balls[r];
	balls[r] = b;
}
void sortBalls(vector<Ball>&balls){
	int n = balls.size();
	if(n<=1) return;
	int l=0,r=n-1,i=0;
	while(i<=r){
		if(balls[i].color=="red"){
			exchange(balls,i,r);
			r--;
		}else if(balls[i].color=="white"){
			exchange(balls,l,i);
			i++;
			l++;
		}else i++;
	}
}

int main(int argc,char*argv[]){
	/*alg1*/
	char*s1 = "ab";
	char*t1 = "a*";
	if(isMatch(s1,t1)) cout << "Match" << endl;
	else cout << "Not Match" << endl;
	s1 = "aa";
	t1 = "a*";
	if(isMatch(s1,t1)) cout << "Match" << endl;
	else cout << "Not Match" << endl;
	/*alg2*/
	vector<int> vec;
	srand(time(NULL));
	for(int i=0;i<10;++i){
		int tmp = rand()%10;
		vec.push_back(tmp);
		cout << tmp << " ";
	}
	cout << endl;
	mvZeros(vec);
	for(int i=0;i<10;++i)
		cout << vec[i] << " ";
	cout << endl;
	/*alg3*/
	TreeNode*root = new TreeNode(' ');
	cout << "L: " <<  L << endl;
	insert(root,"abc123");
	cout << lookup(root,"abc1") << endl;
	insert(root,"abd123");
	cout << "L: " <<  L << endl;
	cout << lookup(root,"abd1") << endl;
	/*alg4*/
	vector<Ball> balls;
	int blue,white,red;
	blue=white=red=0;
	for(int i=0;i<10;++i){
		int tmp = rand()%3;
		switch(tmp){
			case 0:
				white++;
				balls.push_back(Ball("white"));
				break;
			case 1:
				blue++;
				balls.push_back(Ball("blue"));
				break;
			case 2:
				red++;
				balls.push_back(Ball("red"));
				break;
		}
	}
	cout << "white: " << white << " blue: " << blue << " red: " << red << endl;
	sortBalls(balls);
	for(int i=0;i<10;++i)
		cout << balls[i].color << " ";
	cout << endl;
	return 0;
}

#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
 
 You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.
 
 Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
 
 For the last line of text, it should be left justified and no extra space is inserted between words.
 
 For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.
 
 Return the formatted lines as:
 [
    "This    is    an",
    "example  of text",
    "justification.  "
 ]
Note: Each word is guaranteed not to exceed L in length.
 */
vector<string> fullJustify(vector<string> &words, int L) {
	int n = words.size();
	if(n<=0) return words;
	vector<string> res;
	int start,end,cnt;
	end=0;
	while(end<n){
		start=end;
		cnt=0;
		while(end<n&&cnt+words[end].size()<=L){
			cnt += words[end].size()+1;
			end++;
		}
		end--;
		int interval = end-start;
		int avSpace,leftSpace;
		avSpace = leftSpace = 0;
		if(interval>0){
			avSpace = (L-cnt+interval+1)/interval;
			leftSpace = (L-cnt+interval+1)%interval;
		}
		string line("");
		for(int i=start;i<=end;++i){
			if(i!=start){
				if(end+1==n){
					line.append(1,' ');
				}else{
					line.append(avSpace,' ');
					if(leftSpace>0){
						line.append(1,' ');
						leftSpace--;
					}
				}
			}
			line += words[i];
		}
		if(line.size()<L){
			line.append(L-line.size(),' ');
		}
		res.push_back(line);
		end++;
	}
	return res;
}

int main(int argc,char*argv[]){
	//string s1("a"),s2("b"),s3("c"),s4("d"),s5("e");
	string s1("");
	vector<string> vec;
	vec.push_back(s1); //vec.push_back(s2); vec.push_back(s3);
	//vec.push_back(s4); vec.push_back(s5);
	int L=2;
	vector<string> res = fullJustify(vec,L);
	for(int i=0;i<res.size();++i) cout << res[i] << "|" << endl;
	return 0;
}

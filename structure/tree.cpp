#include <iostream>
using namespace std;

struct tNode{
	int num;
	tNode *left,*right;
};

int main(int argc,char*argv[]){
	tNode *root = new tNode;
	root->num = 10;
	root->left=NULL;
	root->right=NULL;

}

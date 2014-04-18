/*Implement strStr()
 Implement strStr().
 Returns a pointer to the first occurrence of needle in haystack, 
 or null if needle is not part of haystack.
 */
char *strStr(char *haystack, char *needle) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if(haystack[0]=='\0'&&needle[0]=='\0') return haystack;
	if(needle[0]=='\0') return haystack;
	bool nf = true;
	int i;
	int l,r;
	l=r=0;
	while(haystack[l++]!='\0');
	while(needle[r++]!='\0');
	if(r>l) return NULL;
	for(i=0;nf&&i<=l-r;i++){
		for(int j=i,k=0;nf&&j<l;++j){
			if(needle[k]==haystack[j]) k++;
			else break;
			if(needle[k]=='\0') nf = false;
		}
	}
	if(nf) return NULL;
	else return &haystack[i-1];
}

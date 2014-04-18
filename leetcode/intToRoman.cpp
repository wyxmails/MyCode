/*Integer to Roman
 Given an integer, convert it to a roman numeral.
 Input is guaranteed to be within the range from 1 to 3999.
 */
string intToRoman(int num) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function    
	string str = "";
	map<int,char> mapsig;
	mapsig.clear();
	mapsig[1] = 'I';
	mapsig[5] = 'V';
	mapsig[10] = 'X';
	mapsig[50] = 'L';
	mapsig[100] = 'C';
	mapsig[500] = 'D';
	mapsig[1000] = 'M';
	map<int,char>::iterator it,ittmp;
	it = mapsig.end();
	int tmp;
	it--;
	while(1){
		tmp = num/(*it).first;
		if(tmp>=5){
			if(tmp==9){
				ittmp = it;
				ittmp++;
				ittmp++;
				str = str + (*it).second + (*ittmp).second;
			}else{
				ittmp = it;
				ittmp++;
				str += (*ittmp).second;
				while(tmp>5){
					str += (*it).second;
					tmp--;
				}
			}
		}else{
			if(tmp==4){
				ittmp = it;
				ittmp++;
				str = str + (*it).second + (*ittmp).second;
			}else{
				while(tmp>0){
					str += (*it).second;
					tmp--;
				}
			}
		}
		num %= (*it).first;
		if(it==mapsig.begin()) break;
		it--;
		it--;
	}
	return str;
}

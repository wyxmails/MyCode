/*
 博弈论题目可以用寻找必败状态的方法解决。
 第一个必败状态是2001.11.04。由此可以推出其他任何时间的状态。对于除2001.11.04外的其他任何时间，present状态是由能移动到的下两个next状态决定的（当然有些时间只有一个next状态），比如1924.12.19的状态是由1924.12.20和1925.01.19两个状态决定。如果两个next状态中有一个必败状态，则present状态为必胜状态；如果两个next状态都为必胜状态，则present状态为必败状态。
 对于2001年11月的那4天，状态都是交替胜负的。1和3号必胜，2和4号必败。现在考虑10月份，5-31号只有一个next状态，推算可知奇数号状态为必败，偶数号状态为必胜。1-4号状态有两个next状态，推算可知也是奇数号状态为必败，偶数号状态为必胜。也就是说整个10月份奇数号状态为必败，偶数号状态为必胜。
 由此我们可以推测如果每个月都是31天的话，那么每天的状态都是相反的，而且相邻的两个月的同一天状态也是相反的。即奇数月的奇数号状态为必胜，偶数号状态为必败；偶数月偶数号状态为必胜，奇数号状态为必败。从数学上说，就是月与号和为偶数的天状态为必胜，为奇数的天状态为必败。显然这个是成立的，可以自己推算一下。
     接下来要考虑特殊情况，那几个只有30天的月份。有30号的有4，6，9，11这四个月。对于04.30，next状态有05.01和05.30，显然两个next状态是相反的，所以04.30的状态是必胜的。所以04.30的状态情况符合上面那个结论。06.30同样如此。对于09.30，next状态有10.01和10.30，同样10.01和10.30的状态是相反的，所以09.30的状态为必胜，这不符合上面的结论。但是我们可以证明这只是一种特殊情况，不影响整个结论。按照原来的结论，九月份的奇数号状态为必胜，偶数号状态为必败。现在30号的状态变化了，如果我们能证明29号的状态不会因此发生变化，那么特殊情况就只局限于30号了。09.29号的next状态有09.30和10.29，10.29的状态为必败，所以09.29的状态为必胜，还是符合原来的结论。11.30同样如此。
	 最后考虑特殊的2月份。如果是闰年的29天，效果和31天一个月是一样的（只要是奇数都一样，哪怕一个月只有一天）。对于非闰年，2月只有28天。其实28天也等同于30天的情况，推算可知02.28和04.30，06.30一样，不影响整个结论。
	    
	 总结，月与号和为偶数的天状态为必胜，为奇数的天状态为必败。特殊情况为09.30和11.30，这两天的状态也为必胜。
 */
#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc,char*argv[]){
	int t,year,mm,dd;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&year,&mm,&dd);
		if(mm==9&&dd==30||mm==11&&dd==30){
			printf("YES\n");
			continue;
		}
		if((mm+dd)%2) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}

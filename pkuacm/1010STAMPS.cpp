#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int stamps[56];
int r1;
int r2[2];
int r3[3];
int r4[4];
int cmp(const void*s1,const void*s2){
	return (*(int*)s2)-(*(int*)s1);
}
int main(int argc,char*argv[]){
	int request,tmp,count,i,j,k,m,n;
	int f1,f2,f3,f4;
	bool tie1,tie2,tie3,tie4;
	i=0,j=0;
	while(scanf("%d",&stamps[i++])>0){
		while(scanf("%d",&stamps[i])&&stamps[i]>0) i++;
		count = i;
		qsort(stamps,count,sizeof(int),cmp);
		while(scanf("%d",&request)&&request>0){
			f1=f2=f3=f4=0;
			tie1=tie2=tie3=tie4=false;
			i=0;
			while(stamps[i]>request) i++;
			//1
			if(stamps[i]==request){
			   	r1 = stamps[i];
				i++;
				f1 = 1;
				if(stamps[i]==request) tie1 = true;
			}
			tmp = request;
			//2
			for(j=i;j<count-1&&!tie2;++j){
				if(f2&&stamps[j]!=r2[1]) break;
				for(k=j+1;k<count&&!tie2;++k){
					if(stamps[j]+stamps[k]==tmp){
						if(f2){
							tie2 = true;
							continue;
						}
						f2 = 2;
						r2[0] = stamps[k];
						r2[1] = stamps[j];
					}
				}
			}
			if(!f2&&!f1){
				for(j=i;j<count&&!tie2;++j){
					if(stamps[j]*2==tmp){
						if(f2){
							tie2 = true;
							continue;
						}
						f2 = 1;
						r2[0] = r2[1] = stamps[j];
					}
				}
			}
			//3
			for(j=i;j<count-2&&!tie3;++j){
				if(f3&&stamps[j]!=r3[2]) break;
				for(k=j+1;k<count-1&&!tie3;++k){
					for(m=k+1;m<count&&!tie3;++m){
						if(stamps[j]+stamps[k]+stamps[m]==tmp){
							if(f3){
								tie3 = true;
								continue;
							}
							f3 = 3;
							r3[0] = stamps[m];
							r3[1] = stamps[k];
							r3[2] = stamps[j];
						}
					}
				}
			}
			if(!f3&&f2<2){
				for(j=i;j<count-1&&!tie3;++j){
					if(f3&&stamps[j]!=r3[2]) break;
					for(k=j+1;k<count&&!tie3;++k){
						if(stamps[j]*2+stamps[k]==tmp){
							if(f3){
								tie3 = true;
								continue;
							}
							f3 = 2;
							r3[0] = stamps[k];
							r3[1] = r3[2] = stamps[j];
						}
						if(stamps[j]+stamps[k]*2==tmp){
							if(f3){
								tie3 = true;
								continue;
							}
							f3 = 2;
							r3[0]=r3[1] = stamps[k];
							r3[2] = stamps[j];
						}
					}
				}
			}
			if(!f3&&f2<1&&!f1){
				for(j=i;j<count&&!tie3;++j){
					if(stamps[j]*3==tmp){
						if(f3){
							tie3 = true;
							continue;
						}
						f3 = 1;
						r3[0] = r3[1] = r3[2] = stamps[j];
					}
				}
			}
			//4
			for(j=i;j<count-3&&!tie4;++j){
				if(f4&&stamps[j]!=r4[3]) break;
				for(k=j+1;k<count-2&&!tie4;++k){
					for(m=k+1;m<count-1&&!tie4;++m){
						for(n=m+1;n<count&&!tie4;++n){
							if(stamps[j]+stamps[k]+stamps[m]+stamps[n]==tmp){
								if(f4){
									tie4 = true;
									continue;
								}
								f4 = 4;
								r4[0] = stamps[n];
								r4[1] = stamps[m];
								r4[2] = stamps[k];
								r4[3] = stamps[j];
							}
						}
					}
				}
			}
			//4.1
			if(!f4&&f3<3){
				for(j=i;j<count-2&&!tie4;++j){
					if(f4&&stamps[j]!=r4[3]) break;
					for(k=j+1;k<count-1&&!tie4;++k){
						for(m=k+1;m<count&&!tie4;++m){
							if(stamps[j]*2+stamps[k]+stamps[m]==tmp){
								if(f4){
									tie4 = true;
									continue;
								}
								f4 = 3;
								r4[0] = stamps[m];
								r4[1] = stamps[k];
								r4[2] = r4[3] = stamps[j];
							}
							if(stamps[j]+stamps[k]*2+stamps[m]==tmp){
								if(f4){
									tie4 = true;
									continue;
								}
								f4 = 3;
								r4[0] = stamps[m];
								r4[1] = r4[2] = stamps[k];
								r4[3] = stamps[j];
							}
							if(stamps[j]+stamps[k]+stamps[m]*2==tmp){
								if(f4){
									tie4 = true;
									continue;
								}
								f4 = 3;
								r4[0] = r4[1] = stamps[m];
								r4[2] = stamps[k];
								r4[3] = stamps[j];
							}
						}
					}
				}
			}
			//4.2
			if(!f4&&f3<2&&f2<2){
				for(j=i;j<count-1&&!tie4;++j){
					if(f4&&stamps[j]!=r4[3]) break;
					for(k=j+1;k<count&&!tie4;++k){
						if(stamps[j]*3+stamps[k]==tmp){
							if(f4){
								tie4 = true;
								continue;
							}
							f4 = 2;
							r4[0] = stamps[k];
							r4[1] = r4[2] = r4[3] = stamps[j];
						}
						if(stamps[j]*2+stamps[k]*2==tmp){
							if(f4){
								tie4 = true;
								continue;
							}
							f4 = 2;
							r4[0] = r4[1] = stamps[k];
							r4[2] = r4[3] = stamps[j];
						}
						if(stamps[j]+stamps[k]*3==tmp){
							if(f4){
								tie4 = true;
								continue;
							}
							f4 = 2;
							r4[0] = r4[1] = r4[2] = stamps[k];
							r4[3] = stamps[j];
						}
					}
				}
			}
			//4.3
			if(!f4&&f3<1&&f2<1&&!f1){
				for(j=i;j<count&&!tie4;++j){
					if(stamps[j]*4==tmp){
						if(f4){
							tie4 = true;
							continue;
						}
						f4 = 1;
						r4[0] = r4[1] = r4[2] = r4[3] = stamps[j];
					}
				}
			}
			//out
			if(f4){
				printf("%d (%d): ",request,f4);
				if(tie4)
					printf("tie\n");
				else
					printf("%d %d %d %d \n",r4[0],r4[1],r4[2],r4[3]);
			}else if(f3){
				printf("%d (%d): ",request,f3);
				if(tie3)
					printf("tie\n");
				else
					printf("%d %d %d \n",r3[0],r3[1],r3[2]);
			}else if(f2){
				printf("%d (%d): ",request,f2);
				if(tie2)
					printf("tie\n");
				else
					printf("%d %d \n",r2[0],r2[1]);
			}else if(f1){
				printf("%d (%d): ",request,f1);
				if(tie1)
					printf("tie\n");
				else
					printf("%d \n",r1);
			}else{
				printf("%d ---- none\n",request);
			}
		}
		i=0,j=0;
	}
	return 0;
}

#include <stdio.h>
#include <math.h>
int main(){
	int Lc, Hc, h, l, F, BF=0, f, q, sF=0, cm, Counter,D1,D2,i,C,Cm,Counter2=0,Cfb,fm;
	int LowClass[9999];
	int HighClass[9999];
	double Classmark[9999], fx, sfx=0,L,Lm,im;
	int freq[9999];
	int CumFreq[9999];
	double _m, S_m, sd, ssd,T, SD, var,mode,md,D,d,dm,N2,median;
	printf("Enter Low Class limit (Enter negative number to end):\n");
	scanf("%d", &Lc);
	printf("Enter High Class limit (Enter negative number to end)):\n");
	scanf("%d", &Hc);
	while(Hc && Lc >=0){
		LowClass[l++]=Lc;
		HighClass[h++]=Hc;
		scanf("%d", &Lc);
		scanf("%d", &Hc);
	}
	for (int a=0;a<h;a++){
		Classmark[a]=(LowClass[a]+ HighClass[a])/2.0;
		//printf("\t%3d - %2d  %.1lf\n", LowClass[a], HighClass[a], Classmark[a]);
	}
	printf("Enter frequence of each respective class(Enter negative number to end):\n");
	scanf("%d", &F);
	while(F>=0){
		freq[f++]=F;
		sF=sF+F;
		CumFreq[cm++]=sF;
		scanf("%d", &F);
	}
	N2=sF/2.0;
	for(int a=0;a<=h;a++){
		if(freq[a]>BF){
			BF=freq[a];
		}
	for(int a=0;a<=h;a++){
			if(freq[a]==BF){
				Counter=a;
			}
		}
	}
	for(int a=0;a<=h;a++){
		if(CumFreq[a]<N2){
			Counter2=Counter2+1;
		}
	}
	if(f!=h){
		printf("Error!\nInvalid data !!!\n Number of frequence must be equivalent to the total number of classes\n");
		goto Stop;
	}
	for (int a=0;a<h;a++){
		fx= Classmark[a] * freq[a];
		sfx=sfx+fx;}
	double m;
	m = sfx / sF;
	for (int a=0;a<h;a++){
		_m= Classmark[a] - m;
		S_m=S_m + _m;
	}
	for(int a=0;a<=h;a++){
		sd=freq[a]*(Classmark[a]*Classmark[a]);
		ssd=ssd+sd;
	}
	T=ssd/sF;
	var=T-((sfx/sF)* (sfx/sF));
	SD=sqrt(var);
	//Mode Computation begin here!!!
	D1=freq[Counter]-freq[Counter-1];
	D2=freq[Counter]-freq[Counter+1];
	i= LowClass[Counter] -HighClass[Counter-1];
	if(i==0){
		L= LowClass[Counter];
	}
	else{d=i/2.0;
		L=LowClass[Counter]-d;}
	C=(HighClass[Counter]+d)-(LowClass[Counter]-d);
	D=D1+D2;
	md=D1/D;
	mode=L+(md*C);
	// End of mode
	// Median Computation
	Cfb=CumFreq[Counter2-2];
	fm=freq[Counter2-1];
	im= LowClass[Counter2-1] -HighClass[Counter2-2];
	if(im==0){
		Lm= LowClass[Counter2-1];
	}
	else{dm=im/2.0;
		Lm=LowClass[Counter2-1]-dm;}
	Cm=(HighClass[Counter2-1]+dm)-(LowClass[Counter2-1]-dm);
	median=Lm+((N2-Cfb)/fm)*Cm;
	for (int a=0;a<h;a++){
	printf("%3d - %2d  %7.1lf  %d %d %4.1lf  %4.1lf\n", LowClass[a], HighClass[a], Classmark[a], freq[a], CumFreq[a], Classmark[a] * freq[a], Classmark[a]-m);
		}
	printf("Mean:\t%.3lf\n", m);
	printf("Median:\t%.3lf\n", median);
	printf("Mode:\t%.3lf\n", mode);
	printf("Variance:\t%.3lf\n", var);
	printf("Standard\nDeviation:\t%.3lf\n", SD);
	printf("\nOther information;\n");
	printf("\nThe median class is:\t %d - %d\n",LowClass[Counter2 -1],HighClass[Counter2 -1]);
	printf("The modal class is:\t %d - %d\n",LowClass[Counter],HighClass[Counter]);
	//printf("L= %.3lf\nC= %d\nD1= %d\nD2= %d\ni= %d\nd= %.3lf", L, C, D1, D2,i,d);
	Stop:;
}
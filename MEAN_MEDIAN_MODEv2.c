#include <stdio.h>
#include <math.h>
int main(){
	int Lc, Hc, h, l, F, f, q, sF=0, cm;
	int LowClass[9999];
	int HighClass[9999];
	double Classmark[9999], fx, sfx=0;
	int freq[9999];
	int CumFreq[9999];
	double _m, S_m, sd, sd_sq, SD, var;
	printf("Enter Low Class limit (Enter zero to end):\n");
	scanf("%d", &Lc);
	printf("Enter High Class limit (Enter zero to end)):\n");
	scanf("%d", &Hc);
	while(Hc && Lc !=0){
		LowClass[l++]=Lc;
		HighClass[h++]=Hc;
		scanf("%d", &Lc);
		scanf("%d", &Hc);
	}
	for (int a=0;a<h;a++){
		Classmark[a]=(LowClass[a]+ HighClass[a])/2.0;
		//printf("\t%3d - %2d  %.1lf\n", LowClass[a], HighClass[a], Classmark[a]);
	}
	printf("Enter frequence of each respective class(Enter zero to end):\n");
	scanf("%d", &F);
	while(F!=0){
		freq[f++]=F;
		sF=sF+F;
		CumFreq[cm++]=sF;
		scanf("%d", &F);
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
	sd = S_m / sF;
	sd_sq=sd*sd;
	SD = sqrt(sd_sq);
	var = SD * SD;
	for (int a=0;a<h;a++){
	printf("%3d - %2d  %7.1lf  %d %d %4.1lf  %4.1lf\n", LowClass[a], HighClass[a], Classmark[a], freq[a], CumFreq[a], Classmark[a] * freq[a], Classmark[a]-m);
		}
	printf("Mean: %.3lf\n", m);
	printf("Variance: %.3lf\n", var);
	printf("Standard\nDeviation: %.3lf\n", SD);
	Stop:;
}
#include "uhead.h"

void show(int *a,int n){
	FILE *fp;
	fp=fopen("a.txt","w");
   int i=0;
   for(i=0;i<100;i++){
   printf("a[%d]=%d,\n",i,a[i]);  
	fprintf(fp,"%d\n",a[i]); 
 }
	fclose(fp);
}


void urand(int *a,int n){
   int i=0;
   srand((unsigned)time(0));
   for(i=0;i<n;i++){
   a[i]=(int)1000.0*rand()/(RAND_MAXs+1.0);
}
}


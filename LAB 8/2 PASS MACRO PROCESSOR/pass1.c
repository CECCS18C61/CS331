#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
FILE *f1,*f2,*f3;
char mne[20],opnd[20],la[20];
f1=fopen("input.txt","r");
f2=fopen("ntab.txt","w+");
f3=fopen("dtab.txt","w+");
fscanf(f1,"%s%s%s",la,mne,opnd);
while(strcmp(mne,"MEND")!=0)
{
if(strcmp(mne,"MACRO")==0)
{
fprintf(f2,"%s\n",la);
fprintf(f3,"%s\t%s\n",la,opnd);
}
else
fprintf(f3,"%s\t%s\n",mne,opnd);
fscanf(f1,"%s%s%s",la,mne,opnd);
}
fprintf(f3,"%s",mne);
fclose(f1);
fclose(f2);
fclose(f3);
printf("PASS 1 is successful\n");
}

*/ INPUT FILES:- input.txt
   OUTPUT FILES:- dtab.txt, ntab.txt /*  

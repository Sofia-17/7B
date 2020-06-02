#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"fun.h"
int main(void) {
 SStudent **s; int count;
 if(Input1("in.txt",&s,&count)) printf("Error, empty file");
 Sort(s,count);
 if(Output1("out.txt",s,count)) printf("Error");
 free(s);
 return 0;
}

int Output1(const char *sf, SStudent **s, int count) {
 FILE *f; int i, fl1=0, fl2=0;
 f=fopen(sf,"w");
 if(f==NULL) return -1;
 for(i=0;i<count;i++) {
  if(i+1>count%10 && fl1==0) {fl1=1; fprintf(f,"------------\n");}
  if(i+1>(count-count%10) && fl2==0) {fl2=1; fprintf(f,"------------\n");}
  fprintf(f,"%d %s: %f\n",((s)[i])->group,((s)[i])->name,((s)[i])->rating);
 }
 fclose(f);
 return 0;
}

int Input1(const char *sf, SStudent ***s, int *count) {
 char str[512], *ss, *sss; FILE *f; int i, l, p;
 f=fopen(sf, "r");
 if(f==NULL) return -1;
 if(fgets(str,512,f)==NULL) {fclose(f); return -2;}
 if(sscanf(str,"%d",&(*count))!=1) {fclose(f); return -3;}

 *s=(SStudent**)malloc((*count)*sizeof(SStudent*)+(*count)*sizeof(SStudent));
 (*s)[0]=(SStudent*)(*s+(*count));
 for(i=1;i<*count;i++)
  (*s)[i]=(*s)[i-1]+1;

 for(i=0;i<(*count) && fgets(str,512,f)!=NULL && sscanf(str,"%d",&(((*s)[i])->group))==1;i++) {
  sscanf(str,"%d%n",&(((*s)[i])->group),&l);  ss=str+l;
  sscanf(ss,"%f%n",&(((*s)[i])->rating),&l);
  ss=ss+l; //while(isspace(*ss))ss++;
  //if((sss=strchr(str,'\n'))!=NULL)*sss='\0';
  //strcpy(((*s)[i])->name,ss);
  sscanf(ss,"%s",&(((*s)[i])->name));
 }
 fclose(f);
 return 0;
}

void Sort( SStudent **s, int count) {
 SStudent* t; int i,j;
 for(i=0;i<count;i++)
  for(j=1;j<count;j++)
   if( (s[j-1]->rating) < (s[j]->rating) ) {
     t=s[j-1];
     s[j-1]=s[j];
     s[j]=t;
    }
}

#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct _st{
 char name[80];
 struct _st *next;
};

struct _st *S;

void push(char* name){
 struct _st *Q=(struct _st *)malloc(sizeof(struct _st));
 Q->next=S;
 S=Q;
 strcpy(S->name,name);
}

void list(){
  struct _st *Q;
  Q=S;  
  while(!(strncmp(S->name,"bottom",6)==0)){
  S=S->next;	 
  printf("%s", S->name);
 }
 S=Q;
}

int main(){
 char lname[80];
 S=(struct _st *)malloc(sizeof(struct _st));
 strcpy(S->name, "bottom");
 
 do{ 
  printf("Enter last name: ");	 
  fgets(lname,80,stdin);
  push(lname);
 } while(strncmp(lname,"end",3));

 list();
 return 0;
}

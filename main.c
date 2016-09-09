#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 15
#define ELEMENTS 5

typedef enum RESTYPE {
    plase,
    score
}RESTYPE;

typedef union Results{
    char plase;
    int score;
}Results;

typedef struct Club{
    char name [SIZE];
    char sity [SIZE];
    RESTYPE info;
    Results res;
}Club;
int* addMemory(Club *prt,int size);
void addStruct(Club *prt,char futbolclub[][SIZE],char sityclub[][SIZE], int placeclub[],int resultclub[], int size);

int main(){
    char futbolclub[ELEMENTS][SIZE]={"Dynamo","Shachtar","Dnipro","Vorskla","Zorya"};
    char sityclub[ELEMENTS][SIZE]= {"Kyiv","Donetsk","Dnipro","Poltava","Lugansk"};
    int  placeclub[]={1,2,4,3,5};
    int  resultclub[]={21,20,13,14,10};
    int N;
    /*printf("Input the number of clubs: ");
    scanf("%d",&N);
    */ N=5;
    Club *prt;
    prt=(Club*)addMemory(prt,N);
    addStruct(prt,futbolclub,sityclub,placeclub, resultclub, N);
    return 0;
}
int * addMemory(Club *prt,int size){
    prt=(Club*)malloc(size*sizeof(Club));
    return (int *)prt;
}
void addStruct(Club *prt,char futbolclub[][SIZE],char sityclub[][SIZE], int * placeclub,int * resultclub, int size){
    int i;
    //printf("Input the type of result: plase - enter 0, or score - enter 1 ");
    //scanf("%d",&type);
    RESTYPE type=score;// or plase
    prt->info=type;
    for (i=0;i<size;i++){
        strcpy(prt->name,futbolclub[i]);
        strcpy(prt->sity,sityclub[i]);
        switch(type) {
        case plase: prt->res.plase=placeclub[i];
            break;
        case score:prt->res.score=resultclub[i];
            break;
        }
        prt++;
    }
    prt-=size+1;
    /* printf("Input the name of team:");
    scanf("%s",name);*/

    char name[ELEMENTS][SIZE]={"Dynamo","Shachtar","Dnipro","Vorskla","Zorya"};
    for(i=0;i<size;i++){
        prt++;
        if (!strcmp(prt->name,name[i])){
            switch(type) {
            case plase: printf("%d %s %s\n",prt->res.plase,prt->name,prt->sity);
                break;
            case score: printf("%d %s %s\n",prt->res.score,prt->name,prt->sity);
                break;
            }
        }
    }
}

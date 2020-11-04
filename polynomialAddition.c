#include <stdio.h>
#include <stdlib.h>
#define max_trem 100
typedef struct {
    float coef;
    int exp;
}trem;
int avail;
trem polynomial[max_trem];
void attach(float co,int ex){
    if(avail>=max_trem){
        printf("limit Exist");
        exit(0);
    }
    else{
        polynomial[avail].coef=co;
        polynomial[avail++].exp=ex;
    }
}
void polyprint(int start,int end){
    int i;
    for(i=start;i<=end;i++)
        printf("%.1f X^%d + ",polynomial[i].coef,polynomial[i].exp);
    if(polynomial[i].exp!=0)
        printf("%.1f X^%d\n",polynomial[i].coef,polynomial[i].exp);
    else
        printf("%.1f \n",polynomial[i].coef);
}
int compire(int a,int b){
    if(a>b)
        return 1;
    if(a<b)
        return -1;
    if(a==b)
        return 0;
}
void padd(int startA,int endA,int startB,int endB,int *startD,int *endD){
    *startD=avail;
    while(startA<=endA&&startB<=endB){
        switch(compire(polynomial[startA].exp,polynomial[startB].exp)){
            case 1:attach(polynomial[startA].coef,polynomial[startA].exp);
                    startA++;
                    break;
            case 0:attach(polynomial[startA].coef+polynomial[startB].coef,polynomial[startA].exp);
                    startA++;
                    startB++;
                    break;
            case -1:attach(polynomial[startB].coef,polynomial[startB].exp);
                    startB++;
                    break;
        }
    }
    for( ;startA<=endA;startA++)
        attach(polynomial[startA].coef,polynomial[startA].exp);
    for( ;startB<=endB;startB++)
        attach(polynomial[startB].coef,polynomial[startB].exp);
    *endD=avail-1;
}
void pSort(int start,int end){
    int i,j;
    trem t;
    for(i=start;i<end;i++)
        for(j=i+1;j<=end;j++)
            if(polynomial[i].exp<polynomial[j].exp){
                t=polynomial[i];
                polynomial[i]=polynomial[j];
                polynomial[j]=t;
            }
}
void pScan(int *start,int *end){
    int n;
    printf("enter number of trems of polynomial\t");
    scanf("%d",&n);
    float co;
    int ex;
    *start=avail;
    for(int i=0;i<n;i++){
        printf("Enter co-eficent\t");
        scanf("%f",&co);
        printf("Enter Exponent\t");
        scanf("%d",&ex);
        attach(co,ex);
    }
    *end =avail-1;
    pSort(*start,*end);
}
void main(){
    int startA,endA,startB,endB,startC,endC;
    printf("Enter Detilus of First polinimial\n");
    pScan(&startA,&endA);
    printf("Enter Detilus of 2nd polinimial\n");
    pScan(&startB,&endB);
    printf("polinomial  1 is ");
    polyprint(startA,endA);
    printf("polinomial  2 is ");
    polyprint(startB,endB);
    padd(startA,endA,startB,endB,&startC,&endC);
    printf("Result \n");
    polyprint(startC,endC);
}
#include<stdio.h>
  
int Calc(int nResult[],int len,int nNumb)
{
    int i,rem=0;
    for(i=0;i<len;i++){
        rem+=nResult[i]*nNumb;
        nResult[i]=rem%10;
        rem=rem/10;
    }
    while(rem>0){
        nResult[len]=rem%10;
        len++;
        rem=rem/10;
    }
    return len;
}
 
void main()
{
    int nResult[512]={0};   //保存结果
    int i=0, len=1 ;
     
    nResult[0]=1;
    for(i=2;i<=100;i++){    //100的阶乘
        len=Calc(nResult,len,i);
    }
 
    for(i=len-1;i>=0;i--){
        printf("%d",nResult[i]);
    }
 
    printf("\n");
    getchar();
 
    return;
}
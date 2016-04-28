#include <stdio.h>
#include <stdlib.h>
#define infinity 9999
#define size 6
int matrix[size][size]={
    {infinity,50,45,10,infinity,infinity},
    {infinity,infinity,10,15,infinity,infinity},
    {infinity,infinity,infinity,infinity,30,infinity},
    {20,infinity,infinity,infinity,15,infinity},
    {infinity,20,35,infinity,infinity,infinity},
    {infinity,infinity,infinity,infinity,3,infinity}
};
int table[size][size]={
    {infinity,infinity,infinity,infinity,infinity,infinity},
    {infinity,infinity,infinity,infinity,infinity,infinity},
    {infinity,infinity,infinity,infinity,infinity,infinity},
    {infinity,infinity,infinity,infinity,infinity,infinity},
    {infinity,infinity,infinity,infinity,infinity,infinity},
    {infinity,infinity,infinity,infinity,infinity,infinity}
};
int ans[size]={0,0,0,0,0,0};
void search_start(int start_node){
    int pos,step;
    for (step=1;step<size;step++){
        int newnode=start_node;
        for (pos=0;pos<size;pos++){
            if (table[step-1][start_node]>=table[step-1][pos]){//���p�O�w�g�H�̵u���|���쪺
                table[step][pos]=table[step-1][pos];
                if (table[step-1][start_node]==table[step-1][pos]){
                    if (start_node!=pos && !ans[pos]){
                        newnode=pos;
                    }
                }
            }
            else{
                if (matrix[start_node][pos]<infinity || table[step-1][pos]<infinity){//���p�����L���j
                    table[step][pos]=table[step-1][start_node]+matrix[start_node][pos]>table[step-1][pos]?table[step-1][pos]:table[step-1][start_node]+matrix[start_node][pos];
                }
                if (start_node==newnode){
                    newnode=pos;//���H�K���]�@��
                }
                else if (table[step][pos]>=table[step-1][start_node]){
                    if (table[step][pos]<table[step][newnode]){
                        if (start_node!=newnode)newnode=pos;
                    }
                }
            }
            printf("%4d ",table[step][pos]);
        }
        printf("\n");
        start_node=newnode;
        ans[start_node]=1;
        if (table[step][start_node]!=infinity){
            printf(" %d ",start_node);
        }
    }
}

int main(){
    int start_node=1;//�_�I
    table[0][start_node]=0;//�_�I
    ans[start_node]=1;
    printf(" %d ",start_node);
    search_start(start_node);
    system("PAUSE");
    return 0;
}

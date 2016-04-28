#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;

int time1=1,time2=1;
node* create (){
    node* new_ptr =(node*)malloc(sizeof(node));
    new_ptr->data=NULL;
    new_ptr->link=NULL;
    return new_ptr;
}
void add(node** root,int n,int *first){
    node* new_ptr =(node*)malloc(sizeof(node));
    if(*first!=0&&(*root)->data==NULL){
        (*root)->data=n;
        *first=0;
    }
    else if(new_ptr != NULL){
        new_ptr -> link = *root;
        new_ptr -> data = n;
        (*root)=new_ptr;
    }
}
void enter(node** root,node** result){
    char inputchar;
    while(scanf("%c",&inputchar)){
        if (inputchar>'9' || inputchar<'0')break;
        add(root,inputchar-'0',&time1);
        add(result,0,&time2);
    }
    time1=1;
}
void calculate(node* number1,node* number2,node* result){
    for(;number1 !=NULL;number1=number1->link,result=result->link){
        node* temp_result=result,*temp_number2=number2;
        for(;temp_number2!=NULL;temp_number2=temp_number2->link,temp_result=temp_result->link){
            temp_result->data+=number1->data*temp_number2->data;
        }
    }
}
void check(node* result){
    int temp=0;
    for(;result!=NULL;result=result->link){
        result->data+=temp;
        temp=(result->data)/10;
        result->data%=10;}
}
void reverse(node** linklist)
{
    node *parentNode = *linklist;
    node *curNode = parentNode->link;
    node *childNode = curNode->link;
    parentNode->link = NULL;
    while(childNode)
    {
        curNode->link = parentNode;
        parentNode = curNode;
        curNode = childNode;
        childNode = childNode->link;
    }
    curNode->link = parentNode;
    *linklist = curNode;
}
void print_list(node *root){
    int zero = 1;
    printf("Result:");

    for(;root != NULL;root = root -> link){
        if(time1==1&&root->data!=0){
            printf("%d" ,root -> data);
            time1=0;
            zero = 0;}
        else if(time1==0){
            printf("%d" ,root -> data);}
    }
    if (zero)printf("0");
    puts("");
}

main(){
    node* number1,*number2;
    node *result=create();
    number1=create();
    number2=create();
    printf("please enter a Multiplier:");
    enter(&number1,&result);
    printf("please enter another Multiplicand:");
    enter(&number2,&result);

    calculate(number1,number2,result);
    check(result);
    reverse(&result);
    print_list(result);

    system("pause");
    return 0;
}

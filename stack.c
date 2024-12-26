#include<stdio.h>
#include<stdlib.h>
#define size 5

int top=-1;
int stack[size];
int item;

void push(){
    if(top==size-1){
        printf("Stack Overload\n");
    }
    else{
        top+=1;
        stack[top]=item;
    }
}

int pop(){
    if(top==-1){
        printf("Stack Underflow\n");
    }
    else{
        return stack[top--];
    }
}

void display(){
    if(top==-1){
        printf("Stack is empty!");
    }
    else{
        printf("Content of the stacks:");
        for(int i=0;i<=top;i++){
            printf("%d ",stack[i]);
        }printf("\n");
    }
}

void main(){
    int choice;
    while(1){
        printf("Enter your options:\n");
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter the element to be pushed in:");scanf("%d",&item);push();break;
            case 2:if(top==-1){
                printf("stack is empty!\n");
            }else{
                printf("%d popped from stack\n", stack[top]);
            }
            pop();
            break;
            case 3:display();
            break;
            case 4:exit(0);
        }
    }
}

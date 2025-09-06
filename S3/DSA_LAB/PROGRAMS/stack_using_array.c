#include<stdio.h>
#define N 5
int stack[N];
int top=-1;

void push(){
    if(top==N-1){
        printf("\nSTACK OVERFLOW");
    }
    else{
        int item;
        printf("\nEnter item to be pushed:");
        scanf("%d",&item);
        top++;
        stack[top]=item;
        printf("\nPushed %d to the stack",stack[top]);
    }
}

void pop(){
    if(top==-1){
        printf("\nSTACK UNDERFLOW");
    }
    else{
        printf("\nPopped %d from the stack",stack[top]);
        top--;
    }
}

void display()
{
    if(top==-1){
        printf("\nNothing to display,its empty");
    }
    else{
        printf("\nThe stack elements are:\n");
        for(int i=top;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    }
}

int main()
{
    int choice;
    do{
        printf("\nEnter choice:\n1.Push\n2.Pop\n3.Display\n0.Exit\n\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    push();
                    break;
            case 2:
                    pop();
                    break;
            case 3:
                    display();
                    break;
            case 0:
                    printf("\nExiting .....");
                    break;   
            default:
                    printf("\nEnter correct choice");
        }
    }while(choice!=0);
    return 0;
}
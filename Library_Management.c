#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct library
{
    char bookname[100];
    char author[100];
    int edition;
    int current_pos;
    char* username;
}library;
typedef struct user
{
    char name[100];
    int istaken;
   // int overdue;
    //int number;
    //int date_taken;
    //int date_return;
    int cur_date;
    char* Bookname;
}user;
int search(char book[100],library* L,char author[100],int ed,user* U,int count)
{  
    //library*a=Library;
   // printf("inside funct\n");
    for(int i=0;i<2;i++)
    { 
       // printf("inside loop\n");
       // printf("%s\n",L[i].bookname);
       // printf("%s\n",book);
       int c=strcmp(L[i].bookname,book);
       int d=strcmp(L[i].author,author);
        if(c==0 && d==0 && ed==L[i].edition && L[i].current_pos==0 && U[count].istaken==0)
        {
            printf("%s %s %d is available do you want to take\npress 1 else 0 :\t",L[i].bookname,L[i].author,L[i].edition);
            int k;
            scanf("%d",&k);
            if(k==1)
             { 
              L[i].current_pos=1;
              U[count].istaken=1;
              L[i].username=U[count].name;
              U[count].Bookname=L[i].bookname;
              printf("return date %d\n",U[count].cur_date+7);
              printf("book taken\n");

              return(0);
             }
            else{
                printf("book not taken\n");
                return(0);
            }
        }
        else if(L[i].current_pos==1)
        {
            printf("the book is taken");
        }
        else if(U[count].istaken==1)
        {
            printf("you have already taken a book\nyou can only take one book \n");
        }
        
    }
        
    printf("book not available\n");
}
int main()
{   
    library Library[2]={{"ab","cd",1,0,NULL},{"ef","gh",1,0,NULL}};
    user User[100];
    int n;
    int count=0;
    char book[100];
    char author[100];
    int edition;
    while(1)
    {
    printf("1.new user\n2.account already exist\n");
    scanf("%d",&n);
    
    switch(n)
    {
        case 1: printf("enter name:");
                scanf("%s",&User[count].name);
                printf("\nenter todays date:\t");
                scanf("%d",&User[count].cur_date);
                printf("\nenter book u want:\t");
                scanf("%s",&book);
                printf("\nenter the author:\t");
                scanf("%s",&author);
                printf("\nenter edition:\t");
                scanf("%d",&edition);
               // printf("%s\n",book);
               // printf("%s\n",Library[count].bookname);
                search(book,Library,author,edition,User,count);
                count++;
                break;
        }
    }
}



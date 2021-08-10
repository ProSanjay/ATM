#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
struct node
{
    int data;
    struct node *next;
}*root,*p,*r;
struct node *top=NULL;
void push();
void display();
int amt;

int main()
{
int ch,pin,x,bal,password;
char ans ,act[34],account[45],user[45];
printf("Enter account no.=");
scanf("%s",account);
printf("Enter pin no.=");
scanf("%d",&password);
printf("Enter your balance=");
scanf("%d",&bal);
do
{
printf("1:Deposite\n");
printf("2:Withdraw\n");
printf("3:Balance enquiry\n");
printf("4:Transfer\n");
printf("5:Mini statement\n");
printf("Enter your choice=");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter pin no.=");
scanf("%d",&pin);
if(pin==password)
{
 printf("Enter deposite amount=");
 scanf("%d",&amt);
 bal=bal+amt;
 printf("Deposite succesfully\n");

 }
 else
{
 printf("Invalid pin\n");
 }
 break;
case 2:
printf("Enter pin no.=");
scanf("%d",&pin);
if(pin==password)
{
  printf("Enter amount=");
  scanf("%d",&amt);
  if(amt>bal)
  {
   printf("Insufficint balance\n");
   }
  else
  {
   bal=bal-amt;
   printf("Withdraw succesfully\n");
   }
   push();
   }
   else
   {
    printf("Invalid pin\n");
    }
    break;
case 3:
printf("Enter your pin=");
scanf("%d",&pin);
if(pin==password)
{
 printf("Your balance=%d",bal);
 }
 else
 {
  printf("Invalid pin\n");
  }
  break;
case 4:
printf("Enter pin no.=");
scanf("%d",&pin);
if(pin==password)
{
  printf("Enter transfer amount=");
  scanf("%d",&amt);
  printf("Enter account number to which you want to transfer=");
  scanf("%s",user);
   if(amt>bal)
  {
   printf("Insufficint balance\n");
   }
  else
  {
   bal=bal-amt;
   printf("transfer succesfully\n");
   }
   push();
}

else
{
 printf("Invalid pin\n");
 }
 break;
case 5:
    display();
    break;
 default:
 printf("Wrong choice\n");
 }
  printf("press n to exit or press any key to continue..\n");

 }while(getch()!='n');
 return 0;
}
void push()
{
  p=(struct node*)malloc(sizeof(struct node));
  p->data=amt;
  if(top==NULL)
    { p->next=NULL;
    top=p;
              }
 else
{
  p->next=top;
  top=p;
  }
}

void display()
{   time_t t;
time(&t);
    p=top;
    if(top==NULL)
    {
        printf("Stack is empty\n");
    }
    else{ printf("Ministatement is \n");

        while( p!=NULL)
        {
        printf(" withdraw amounnt %drs at %s in HDFC bank\n",p->data,ctime(&t));
            p=p->next;
        }
    }
}

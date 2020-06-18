#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct book
{
char code[20];
char name[20];
char date[20];
int cost;
}b;
int seat=60;
void insert_details();//for inserting movie details
void viewAll();//for viewing all data inserted
void find();//for finding data
void book_ticket();//for booking tickets
void old_record();//for viewing old records of users,booked tickets
int main()
{
int ch;
do
{
printf("\n===========================================================================\n");
printf("\n");
printf("\t Movie Ticket booking");
printf("\n");
printf("\t BY SHARVANI AND SEJAL");
printf("\n===========================================================================\n");
printf("\nPress <1> Insert Movie");
printf("\nPress <2> View All Movies");
printf("\nPress <3> To Find Movie");
printf("\nPress <4> Book Ticket");
printf("\nPress <5> View All Transactions");
printf("\nPress <0> Exit ");
printf("\nEnter your choice");
scanf("%d",&ch);
switch(ch)
{
case 1:
insert_details();
break;
case 2:
system("cls");
viewAll();
break;
case 3:
find();
break;
case 4:
book_ticket();
break;
case 5:
old_record();
break;
case 0:
exit(0);
break;
default:
printf("wrong choice!");
}
}while(ch!=0);
}
void insert_details()
{
FILE *fp;
struct book b;
printf("Enter the movie code :");
scanf("%s",b.code);
printf("Enter name of the movie :");
scanf("%s",b.name);
printf("Enter the release date :");
scanf("%s",b.date);
printf("Enter the ticket price :");
scanf("%d",&b.cost);
fp=fopen("C:\\Users\\HP\\Desktop\\data.txt","a");
if(fp == NULL)
{
printf("File not found");
}
else
{
fprintf(fp,"%s %s %s %d \n",b.code,b.name,b.date,b.cost);
printf("Record insert successful");
}
printf("\n");
fclose(fp);
}
void find()
{
struct book b;
FILE *fp;
char ch[20];
printf("Enter the movie code :");
scanf("%s",ch);
//system("clear");
fp=fopen("C:\\Users\\HP\\Desktop\\data.txt","r");
if(fp == NULL)
{
printf("File not found");
exit(1);
}
else
{
while(!feof(fp))
{
fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
if(strcmp(b.code,ch)==0)
{
//printf("%s /%s /%s %d\n",b.code,b.name,b.date,b.cost);
printf("\n Record Found\n");
printf("\n\tMovie code ::%s",b.code);
printf("\n\tMovie name ::%s",b.name);
printf("\n\tMovie Release date ::%s",b.date);
printf("\n\tPrice of the ticket ::%d",b.cost);
break;
}
}
}
fclose(fp);
}
void viewAll()
{
char ch;
FILE *fp;
fp=fopen("C:\\Users\\HP\\Desktop\\data.txt","r");
if(fp == NULL)
{
printf("File not found");
exit(1);
}
else
{
system("cls");
  do
    { 
        
        char c = fgetc(fp); 
  
        
        if (feof(fp)) 
            break ; 
  
        printf("%c", c); 
    }  while(1); 
}
fclose(fp);
}
//for booking ticket
void book_ticket()
{
struct book b;
FILE *fp;
FILE *ufp;
int total_seat,mobile,total_amount;
char name[20];
char ch;//used to display all movies
char movie_code[20];//for searching
//display all movies by default for the movie code
fp=fopen("C:\\Users\\HP\\Desktop\\data.txt","r");
if(fp == NULL)
{
printf("File not found");
exit(1);
}
else
{
system("cls");
while((!feof(fp)))
{
	ch=fgetc(fp);
printf("%c",ch);
}
}
fclose(fp);
//display ends
printf("\n To book ticket of your choice(Enter movie code as first letter of movie)");
printf("\nEnter Movie Code :");
scanf("%s",movie_code);
//system("clear")
fp=fopen("C:\\Users\\HP\\Desktop\\data.txt","r");
if(fp == NULL)
{
printf("File not found");
exit(1);
}
else
{
while(!feof(fp))
{
fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
if(strcmp(b.code,movie_code)==0)
{
//printf("%s /%s /%s %d\n",b.code,b.name,b.date,b.cost);
printf("\n Record Found\n");
printf("\n\tMovie code ::%s",b.code);
printf("\n\tMovie name ::%s",b.name);
printf("\n\tMovie Release date ::%s",b.date);
printf("\n\tPrice of the ticket ::%d",b.cost);
break;
}
}
}
printf("\n Fill Details");
printf("\n Enter your name :");
scanf("%s",name);
printf("\n Enter your mobile number :");
scanf("%d",&mobile);
printf("\n Enter the number of tickets :");
scanf("%d",&total_seat);
total_amount=b.cost*total_seat;
printf("\n*****Enjoy the Movie*****");
printf("\n\t\t\tName :%s",name);
printf("\n\t\tMobile number :%d",mobile);
printf("\n\t\tMovie name :%s",b.name);
printf("\n\t\tTotal number of seats :%d",total_seat);
printf("\n\t\tCost per ticket :%d",b.cost);
printf("\n\t\tTotal amount :%d",total_amount);
ufp=fopen("C:\\Users\\HP\\Desktop\\oldtransaction.dat","a");
if(fp == NULL)
{
printf("File not found");
}
else
{
fprintf(ufp,"%s %d %d %d %s %d \n",name,mobile,total_seat,total_amount,b.name,b.cost);
printf("\nRecord insert successful to the old record file");
}
printf("\n");
fclose(ufp);
fclose(fp);
}
void old_record()
{
char ch;
FILE *fp;
//system("clear")
fp=fopen("C:\\Users\\HP\\Desktop\\oldtransaction.txt","r");
if(fp == NULL)
{
printf("File not found");
exit(1);
}
else
{
system("cls");
while((ch = fgetc(fp)!=EOF))
printf("%c",ch);
}
fclose(fp);
}

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAX 100 //Capacity of hotel

int rooms_occ=0;//To count the number of rooms occupied 
struct node{
	int guest_id; //guest id
    char name[20];//Name of the  guest
    char addr[30];//Address of the guest
    int age; // Age of the guest
    int room_number; // Room Number
   struct node *link;
};
struct node *start=NULL;
struct node *checkin(struct node *start);   
struct node *checkout(struct node *start );
struct node *edit_info(struct node *start,int guestid);
struct node *checkguestlist(struct node *start);
struct node *searchlist(struct node *start,int guestid);
struct node *check_if_room_available(struct node *start,int room_num);
int main(){
    int choice,guestid,room_num;
    
    printf("Welcome !!");
    
    while(1)
    {
		printf("\nENTER THE CHOICE");
		printf("\n1.CHECK IN\n2.CHECK OUT\n3.EDIT GUEST INFO\n4.VIEW GUEST LIST\n5.SEARCH GUEST\n6.CHECK AVAILABILITY OF ROOM\n0.EXIT\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				start=checkin(start);
				break;
			case 2:
				start=checkout(start);
				break;
			case 3:
				printf("\nENTER GUEST ID\n");
				scanf("%d",&guestid);
				start=edit_info(start,guestid);
				break;
			case 4:
				start=checkguestlist(start);
				break;
			case 5:
				printf("\nENTER GUEST ID\n");
				scanf("%d",&guestid);
				start=searchlist(start,guestid);
				break;
			case 6:
				printf("\nENTER ROOM NUMBER\n");
				scanf("%d",&room_num);
				start=check_if_room_available(start,room_num);
				break;
			case 0:
				exit(1);
			default:
			printf("wrong choice");
		}
	}
	
return 0;
}

struct node *edit_info(struct node *start,int guestid)
{
	if(start==NULL)
		return start;
	struct node* temp;
	char alias[40];
	int a;
	temp = start;
	while(temp!=NULL){
		if(temp->guest_id == guestid){
			printf("\n Enter the New name: ");
			scanf("%s",alias);
			strcpy(temp->name,alias);
			printf("\n Enter the new address: ");
			scanf("%[^\n]%*c", alias);
			strcpy(temp->addr,alias);
			printf("\n Enter the new age: ");
			scanf("%d",&a);
			temp->age = a;
			printf("\n Enter the new room number: ");
			scanf("%d",&a);
			temp->room_number = a;
			return start;
		}
		temp=temp->link;
	}
	printf("\n Guest id didn't match our records");
	return start;	
}

struct node *checkout(struct node *start ){
	int guest;
	printf("\nEnter the guest id: ");
	scanf("%d",&guest);
	struct node *temp;
	temp = start;
	struct node * p;
	p = (struct node *)malloc(sizeof(struct node));
	if(start == NULL){
		printf("\n You need to checkin first in order to checkout! ");
		return start;
	}

	if(temp->guest_id==guest)
	{
		temp==NULL;
		printf("\nHi %s !\n Thank you so much for choosing to stay at our place while in  %s. We hope you had a great time here and enjoyed your stay.", temp->name, temp->addr);
		return start;
	}
	while (temp!=NULL)
	{
		if(temp->link->guest_id == guest){
			p = temp->link;
			temp->link = temp->link->link;
			free(p);
			printf("\n Hi %s !\n Thank you so much for choosing to stay at our place while in  %s. We hope you had a great time here and enjoyed your stay.", p->name, p->addr);
			return start;
		}
		temp = temp->link;
	}
	printf("\nGuest id didn't match our records\n");
	return start;
}
		
	

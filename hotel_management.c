#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100 //Capacity of hotel

int rooms_occ=0;//To count the number of rooms occupied 
struct node{
    char name[20];//Name of the 
    char addr[30];//Address of the guest
    int age; // Age of the guest
    int room_number; // Room Number
    char empname[20]; // Employee Name
};

struct node *checkin(struct node *ptr, int rooms_occ);
struct node *checkout(struct node *ptr , int rooms_occ);
struct node *reservation(struct node *ptr,int rooms_occ);
struct node *checkguestlist(struct node *ptr);
struct node *searchlist(struct node *ptr,int roomid);
struct node *employeedetails(struct node *ptr, int roomid);
int main(){
    int age,room_num,ch;
    char name[20],addr[30],empname[20];
    printf("Welcome !!");
    printf("Enter the details");
//     switch (ch){
//     }
// }
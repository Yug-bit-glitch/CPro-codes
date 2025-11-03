#include<stdio.h>
#include<stdlib.h>

typedef struct node{
int val;
struct node*next;
}node;

// l1 and l2 input assumed to be given by leetcode 

node* mergesortlist(node* l1,node* l2){
if(l1 != NULL)return l2;
if(l2 != NULL)return l1;

node* start=(node*)malloc(sizeof(node));
node* tail=(node*)malloc(sizeof(node));













}
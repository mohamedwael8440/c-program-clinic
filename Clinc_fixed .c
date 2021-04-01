#include <stdio.h>
#include <stdlib.h>

typedef unsigned int u16;
typedef signed int u32;
void addnode(void);
void LL_DisplayNodes(void);
struct Node * LL_SearchByID(u16 );
void display_default(void);
void reservation(int );
void cancel(int );


typedef struct {
	u16 id;
	u16 age;
	u16 gender[8];
	u32 name[10];
	char slots[5][100];
	struct Node *nptr;
}Node;

Node *head=NULL;
Node *tail=NULL;

struct reserv
{
   char time[100];
   int id;

};
struct reserv s1 = {"2pm to 2:30pm",10};
struct reserv s2 = {"2:30pm to 3pm",20};
struct reserv s3 = {"3pm to 3:30pm",30};
struct reserv s4 = {"4pm to 4:30pm",40};
struct reserv s5 = {"4:30pm to 5pm",50};
struct reserv choice ;
struct reserv reserved ={"reserved",00};

struct reserv *ptr_slot=NULL;
void main(void){
while(1){
   char mode;
   u16 p ,pass,flag=0;
   int id,feature,i,key,user;
   Node *ptr;

   printf("\ntype A for admin and B for user\n");
   scanf("%c",&mode);

 if(mode=='A')
	{
for (p = 0; p <3; p++)
		{              printf("ENTER ADMIN PASSWORD\n");
					   scanf ("%d",&pass);
					   if(pass == 1234)
					   {
						    printf("\n please select the number of feature you want from the following \n \n1: add patient record \n 2: Edit patient record \n3: Reserve and cancel reservation\n\n");
	                        scanf("%d",&feature);

							switch(feature)
	        {
                        case(1) :
                          addnode();
                          break;

						case(2) :
                if(head != NULL)
				{
                          printf("enter id to edit your record \n");
                          scanf("%d",&key);
                          ptr = LL_SearchByID(key);
                          printf("please enter  age edited\n");
	                      scanf("%d",&ptr->age);
	                      printf("please enter user name edited\n");
               for(i=0;i<8;i++)
                        {
                          scanf("%c",&(ptr->name[i]));
                        }
               printf("please enter gender edited\n");
               for(i=0;i<7;i++)
                       {
                         scanf("%c",&(ptr->gender[i]));
                       }
				}

               else
			   {
                printf("no nodes entered yet please select feature 1 \n");
               }
                break;

                       case(3) :
                        reserve_cancel();
                        break ;


                      default :
                       printf("please enter number from the listed above\n");
                       break;
				}
						   flag = 1;
						   break;
					   }

					   else if (p<2)
					   {
						   printf("Try again: ");
					   }
		}


		if (flag == 0)
	      {
		printf("Incorrect password for 3 times, No more tries\n");
		       }
	}

 else if(mode=='B' && head!=NULL)
 {
	 printf("select a feature \n 1. View patient record. \n 2. View todays reservations.\n");
	 printf("\n << reserved appointment will show (reserved :00)instead of time and id >>\n");
	scanf("%d",&user);
	switch(user)
	    {

    case(1) :
        LL_DisplayNodes();
        break;
    case(2) :
        display_default();
        break;
    default :
        printf("please enter 1 or 2\n");
    break;

	    }
 }
  else if(mode=='B' && head==NULL)
  {
     printf("no data saved yet to show\n\n");
  }
}}





void addnode(void)
{   int i=0,id;
	Node *ptr,*availability;
	ptr=(Node*)malloc(sizeof(Node));
    printf("please enter id to check if it is availabile\n");
	scanf("%d",&id);
availability=LL_SearchByID(id);
if (availability==NULL){
	printf("Enter user name 7 characters : \n");
    	for(i=0;i<8;i++)
        {
            scanf("%c",&(ptr->name[i]));
        }
    printf("please enter id again \n");
	scanf("%d",&ptr->id);
    printf("please enter  age\n");
	scanf("%d",&ptr->age);
    printf("please enter gender (malee/female) 5 characters\n");

for(i=0;i<7;i++)
        {
            scanf("%c",&(ptr->gender[i]));
        }
	if(head==NULL)
	{
		head=ptr;
		tail=ptr;
		ptr->nptr=NULL;
	}
	else
        {

		tail->nptr=ptr;
		tail=ptr;
		ptr->nptr=NULL;
	}

}
else{    printf("id already registered\n");
	}
}

void LL_DisplayNodes(void)
{
	Node * ptr;
	u16 i=0;
	ptr=head;
	while(ptr!=NULL)
	{
		printf("\n The ID is : %d \n",ptr->id);
		printf("\nThe age is : %d \n",ptr->age);
		printf("The name is : ");
		for(i=0;i<8;i++)
		{
			printf("%c",ptr->name[i]);
		}
			printf("\n gender : ");
		for(i=0;i<7;i++)
		{
			printf("%c",ptr->gender[i]);
		}
		ptr=ptr->nptr;
    }
}

struct Node * LL_SearchByID(u16 key)
{
    Node * ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->id==key)
        {
            return ptr;
        }
        ptr=ptr->nptr;
    }
    return NULL;
}

void  reserve_cancel (void)
{

int ch,key;

 printf("select from\n 1) reservation\n 2) cancel reservation \n");
 scanf("%d",&ch);
switch(ch)
{
   case(1):

       display_default();
       printf("\n\nplease select appointment by entering provided id in the list and memorize it \n ");
       scanf("%d",&key);

      if(key==10)
      {   ptr_slot=&s1;
          reservation(key);
          display_default();
      }
       else if(key==20)
      {
        ptr_slot=&s2;
        reservation(key);
        display_default();
      }
      else  if(key==30)
      {   ptr_slot=&s3;
          reservation(key);
          display_default();
      }
        else if(key==40)
      {
          ptr_slot=&s4;
          reservation(key);
          display_default();
      }
       else if(key==50)
      {
          ptr_slot=&s5;
          reservation(key);
          display_default();

      }
      break;

case(2):

       printf("\n enter id to cancel \n ");
       scanf("%d",&key);

      if(key==10 && ptr_slot!=NULL)
      {
          cancel(key);
          display_default();
      }
       else if(key==20 && ptr_slot!=NULL)
      {

        cancel(key);
        display_default();
      }
      else  if(key==30 && ptr_slot!=NULL)
      {
          cancel(key);
          display_default();
      }
        else if(key==40 && ptr_slot!=NULL)
      {

          cancel(key);
          display_default();
      }
       else if(key==50 && ptr_slot!=NULL)
      {

          cancel(key);
          display_default();

      }
       else{
            printf("you did not reserve appointment yet\n\n");
        }
      break;

       default :
    printf("please enter correct id");
    break;

}
}

void display_default(void)
{
       printf("\nslot1 id %d : %s\n",s1.id,s1.time);
       printf("slot2 id %d : %s\n",s2.id,s2.time);
       printf("slot3 id %d : %s\n",s3.id,s3.time);
       printf("slot4 id %d : %s\n",s4.id,s4.time);
       printf("slot5 id %d : %s\n\n",s5.id,s5.time);
}

void reservation(int key)
{
    if(key==10)
    {
        choice=s1;
        s1=reserved;
    }
   else if(key==20)
    {// static struct reserv *ptr=&s2;
        choice=s2;
        s2=reserved;
// ptr->time="reserved";
    }
   else if(key==30)
    {
        choice=s3;
        s3=reserved;
       // s3.time={"reserved"};
    }
   else if(key==40)
    {
       choice=s4;
       s4=reserved;
    }
     else if(key==50)
    {
       choice=s5;
       s5=reserved;
    }
}


    void cancel(int key)
{
    if(key==10)
    {
        s1=choice;
    }
   else if(key==20)
    {
        s2=choice;
    }
   else if(key==30)
    {
        s3=choice;

    }
   else if(key==40)
    {
       s4=choice;

    }
     else if(key==50)
    {
       s5=choice;
}
}





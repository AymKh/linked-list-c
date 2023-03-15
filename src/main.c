#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "stuff.h"


// list struct

typedef struct node
{
	int value;
	struct node *next;
}node;

typedef struct 
{
	node *head;	
}list;




// ************************************basic list functions*******************************************

	list *make_list(void)
	{
		list *l = (list*)malloc(sizeof(list));
		l->head = NULL;
		return l;
	}
	int list_size(list *l)
	{
		node *temp = (node*)malloc(sizeof(node));

		temp = l->head;
		int size = 0;

		while(temp != NULL)
		{
			temp = temp->next;
			size++;
		}
		return size;
	}


	int list_is_empty(list *l)
	{
		if (l->head == NULL)
		{
			return 1;
		}
		return 0;
	}

	void print_list(list* l)
	{
		node *temp = NULL;
		temp = l->head;
		
			if (l->head != NULL)
			{
												
					printf("\n");color(11);
					printf("\t#\n");
					printf("\t|\n");
					printf("\t+---> ");
					while(temp != NULL)
					{
						color(11);
						printf(" [ ");color(15);printf("%d",temp->value);color(11);printf(" ] --> ");
						temp = temp->next;
					}color(12);
					printf(" NULL\n\n");
					color(15);
					
			}else{
				color(12);
				printf("\n\tList is empty ! \n");
				color(15);
			}
						
	}

// *******************************************************************************

void get_int(int *x)
{
	printf("\n\n");
	printf("\tInt to insert : ");scanf("%d",x);

}

// ***************************************add head****************************************

	void add_head(list *l,int x)
	{
		node *temp = (node*)malloc(sizeof(node));		
			
				temp->value = x;
				temp->next = l->head;
				l->head = temp;		
	}



	void insert_into_list_head(list *l,int x)
	{
		get_int(&x);
		add_head(l,x);
	}
// ************************************add tail*******************************************
	void add_tail(list *l,int x)
	{
		node* temp = (node*)malloc(sizeof(node));
		node* count = NULL;

		if (list_size(l) == 0)
		{
			add_head(l,x);
		}else
		{
			count = l->head;
			while(count->next != NULL)
			{
				count = count->next;
			}
			temp->value = x;
			temp->next = NULL;
			count->next = temp;
		}
	}

	void insert_into_list_tail(list *l,int x)
	{
		get_int(&x);
		add_tail(l,x);
	}

// ************************************add custom*******************************************

	void get_pos(int *pos)
	{
		printf("\n\tPosition  :  ");scanf("%d",pos);
	}



	void add_custom(list *l,int x,int pos)
	{
		node *temp =(node*)malloc(sizeof(node));
		node *prev =(node*)malloc(sizeof(node));
		node *nextel =(node*)malloc(sizeof(node));
		int position =2;

		
		if ( (pos == 1)||(pos == 0) )
		{
			add_head(l,x);
		}else if (pos >list_size(l))
		{
			color(12);
			printf("\n\tList is too short ! \n\n");
			color(15);
		}else{
				
			prev = l->head;
			nextel = prev->next;

			while(position != pos)
			{
				prev = nextel;
				nextel = prev->next;
				position += 1;
			}

			temp->value =x;
			prev->next =temp;
			temp->next=nextel;

		}	
	}

	void insert_into_list_custom(list *l,int x,int pos)
	{
		get_int(&x);
		get_pos(&pos);
		add_custom(l,x,pos);
	}

// *********************************delet*************************************


	void delete_head(list *l)
	{
		node *temp =NULL;

		if (list_is_empty(l)==1)
		{
			color(12);
			printf("\n\tLIST IS EMPTY ALREADY ! \n");
			color(15);
		}else
		if (list_size(l)==1)
		{
			l->head =NULL;
			
		}else{
			temp =l->head;
			l->head =temp->next;
			temp =NULL;
			free(temp);
		}
	}

	void delete_tail(list *l)
	{
		node *temp =NULL;
		node *prev =NULL;
		

		if (list_size(l)==1)
		{
			delete_head(l);
		}else
		if (list_is_empty(l) == 1)
		{
			color(12);
			printf("\n\tCan't delete tail, list is empty ! \n");
			color(15);
		}
		else{
			prev = l->head;
			temp=prev->next;
			while(temp->next != NULL)
			{
				prev = temp;
				temp = prev->next;
			}

			free (prev->next);
			prev->next =NULL;
		}
		
	}

	 void get_pos_del(int *posdel)
	 {
	 	printf("\n\tPostion of element to delete : ");scanf("%d",posdel);
	 }


	void delete_custom(list *l,int posdel)
	{
		node* safe = NULL;
		node* dell = NULL;	
		int position =2;
		if (list_is_empty(l) != 1)
		{		
			if (posdel == 1)
				{
					delete_head(l);
				}else if (posdel == list_size(l))
				{
					delete_tail(l);
				}else if (posdel > list_size(l))
				{
					color(12);
					printf("\n\tList is too short to reach that position ! \n");
					color(15);
				}else{
					safe = l->head;
					dell = safe->next;

					while(position != posdel)
					{
						safe = dell;
						dell = safe->next;
					}

					safe->next = dell->next;
					dell = NULL;
					free(dell);
				}
		 }
	}

	void delete_custom_pos(list *l,int posdel)
	{
		get_pos_del(&posdel);
		delete_custom(l,posdel);
	}

// *************************************SEARCH******************************************

	void get_int_search(int *s)
	{
		printf("\n\tInt to look for : ");scanf("%d",s);
	}

	void search(list *l, int s)
	{
		node* temp = NULL;
		temp = l->head;

		if (list_is_empty(l) != 1)
		{
			if (temp->value == s)
			{
				printf("\n\tElement found ! (head)\n");
			}else{
				while( (temp != NULL) || (temp->value != s) )
				{
					temp = temp->next;
				}

				if (temp->value == s)
				{
					printf("\n\tElement found !\n");
				}else{
					color(12);
					printf("\n\tNOT FOUND ! \n");
					color(15);
				}
			}
		}else{
			color(12);
			printf("\n\tList is empty ! \n");
			color(15);
		}
	}

	void search_int(list *l,int s)
	{
		get_int_search(&s);
		search(l,s);
	}


// *********************************MAX MIN*************************************

	int max_list(list *l)
	{
		node *temp =l->head;
		int max;

		if (list_is_empty(l)==1)
		{
			max =0;
		}else
		if (list_size(l) == 1)
		{
			max = temp->value;
		}else{
			max = temp->value;
			while(temp !=NULL)
			{
				if (temp->value > max)
				{
					max = temp->value;
					temp = temp->next;
				}else{
					temp = temp->next;
				}
			}
		}

		return max;
	}


	int min_list(list *l)
	{
		node *temp =l->head;
		int min;

		if (list_is_empty(l)==1)
		{
			min =0;
		}else
		if (list_size(l) == 1)
		{
			min = temp->value;
		}else{
			min = temp->value;
			while(temp !=NULL)
			{
				if (temp->value < min)
				{
					min = temp->value;
					temp = temp->next;
				}else{
					temp = temp->next;
				}
			}
		}

		return min;
	}
// *****************************REVERSE*******************************************

	void reverse_list(list *l,list *ltemp)
	{
		node *temp =NULL;
		temp =l->head;

		if (list_is_empty(l) == 1)
		{
			color(12);
			printf("\n\tCan't reverse ! list is empty\n");
			color(15);
		}else if (list_size(l) == 1)
		{
			color(12);
			printf("\n\tList has only one int, thereverse will be the same result --_--\n");
			color(15);
		}else{
			while(temp != NULL)
			{
				add_head(ltemp,temp->value);
				temp = temp->next;
			}
		}
	}

	void print_reversed_list(list *ltemp)
	{
		node *temp = ltemp->head;
						printf("\n");color(11);
						printf("\t#\n");
						printf("\t|\n");
						printf("\t+---> ");

						while(temp != NULL)
						{
							color(11);
							printf(" [ ");color(15);printf("%d",temp->value);color(11);printf(" ] --> ");
							temp = temp->next;
						}color(12);
						printf(" NULL\n\n");
						color(15);
	}

// *******************************************************************************

 void get_choice(int *choice)
 {
 	printf("\n");
 	printf("\t> ");scanf("%d",choice);
 }



// *******************************************************************************


main(void)
{
	system("MODE 100,40");//resizing ourput console


	list *l = make_list();//list of ints
	list *ltemp =make_list();//temp list used to reverse l
	int x;//int to add to list
	int pos;//position for insert custom
	int posdel;//positoin of element to be deleted
	int s;//element to look for
	int choice;//user's choice

	
	// ------------------------------------------------------------
	


	do
	{
		header();
		menu();
		get_choice(&choice);

		switch(choice)
		{
			case 1: insert_into_list_head(l,x);
					added_success();
					getch();					
				break;


			case 2: insert_into_list_tail(l,x);
					added_success();
					getch();
				break;


			case 3: insert_into_list_custom(l,x,pos);
					added_success();
					getch();
				break;



		/////////////////////////////////////////////////////////////

			case 4: delete_head(l);
					del_success();
					getch();
				break;

			case 5: delete_tail(l);
					del_success();
					getch();
				break;

			case 6: delete_custom_pos(l,posdel);
					del_success();
					getch();
				break;

		/////////////////////////////////////////////////////////////

			case 7: search_int(l,s);
					getch();
				break;

			case 8: print_list(l);
					getch();
				break;

			case 9: reverse_list(l,ltemp);
					print_reversed_list(ltemp);
					getch();
				break;

			case 10: printf("\n\tMax : %d\n\n",max_list(l));
					 printf("\n\tMin : %d",min_list(l));
					 getch();
				break;

			case 11: exit(1);
				break;
		}


	} while (choice != 11);

}

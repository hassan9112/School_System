/*
 * Author: Hassan Hisham Hussain
 * Group: 90
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/* STUDENT DATA */
struct student
{
	int id;           //student ID
	char name[50];    //Student Name
	int age;          //Student Age
	float gpa;        //Student GPA
}s;
/* CREATE A NODE */
struct node
{
	struct student data; //node that contains student's data
	struct node *next;  // a pointer to the next node
};

struct node *head=NULL; //initialization of the linked list head
/*ADD A STUDENT TO THE LINKED LIST*/
void AddStudent(const struct student *const ptr)
{
	/*create new node*/
	struct node *link = (struct node*)malloc(sizeof(struct node));
	/*set all the node variables to zero*/
	link->data.id=0;
	link->data.age=0;
	for(int i=0;i<50;i++)
	{
		link->data.name[i]='\0';
	}
	link->data.gpa=0;
	/*Enter student data into an empty new node */
	printf("Enter student ID: ");scanf("%d",&link->data.id);
	printf("Enter student Name: ");scanf("%s",link->data.name);
	printf("Enter student Age: ");scanf("%d",&link->data.age);
	printf("Enter student GPA: ");scanf("%f",&link->data.gpa);
	struct node *ptr1=head;
	/*Check if the ID is already reserved*/
	while(ptr1!=NULL)
	{
		if(link->data.id==ptr1->data.id)
		{
			free(link);
			printf("\nSorry, this ID is already taken\n");
			return;
		}
		else
		{
			ptr1=ptr1->next;
		}
	}
	struct node *current=NULL;
     /*Assign the data to a node in the linked list at the end*/
	struct node *p1=head;
	if(head==NULL)
	{
		head=link;
		link->next=NULL;
	}
	else
	{
		while (p1->next!=NULL)
		{
			p1=p1->next;
		}
		current=link;

		p1->next=current;
	}
}
/*DISPLAY STUDENTS DATA*/
void displayStudents(void)
{
	/*create pointer to structure that itirates the whole list */
	struct node *p1=head;
	/*empty list*/
	if(head==NULL)
	{
		printf("The list is empty \n");
	}
	while (p1!=NULL)
	{
		printf("\n\nStudent ID : %d",p1->data.id);
		printf("\nStudent Name : %s",p1->data.name);
		printf("\nStudent Age : %d",p1->data.age);
		printf("\nStudent GPA : %f\n",p1->data.gpa);
		p1=p1->next;
	}
}
/*SEARCH STUDENT BY ID*/
void search_student(int id)
{
	struct node *p1=head;
	if (head==NULL)
	{
		printf("This list is Empty\n");
		return;
	}
	while (p1!=NULL)
	{
		if(p1->data.id==id)
		{
			printf("\n\nStudent ID : %d",p1->data.id);
			printf("\nStudent Name : %s",p1->data.name);
			printf("\nStudent Age : %d",p1->data.age);
			printf("\nStudent GPA : %f \n",p1->data.gpa);
			return;
		}
		else
		{
			p1=p1->next;
		}
	}
	printf("This ID does not exist \n");
}
/*CALCULATE THE AVERAGE GPA OF ALL STUDENTS*/
float calculateAverageGPA(void)
{
	float sum=0;
	int count=0;
	float avg;
	struct node *p1=head;
	if (head==NULL)
	{
		printf("The List is Empty\n");
	}
	else
	{
		while(p1!=NULL)
		{
			sum=sum+p1->data.gpa;
			p1=p1->next;
			count++;
		}
		avg=sum/count;
	}
	return avg;
}
/*UPDATE STUDENT DATA*/
void UpdateStudentByID(int id)
{
	struct node *ptr=head;
	while (ptr!=NULL)
	{
		if (ptr->data.id==id)
		{
			setvbuf(stdout, NULL, _IONBF, 0); setvbuf(stderr, NULL, _IONBF, 0);
			int x;
			printf("Please Enter what do you want to change in student: \n"
					"1.ID \n"
					"2.Name \n"
					"3.Age \n"
					"4.GPA \n"
					"5.All the student data\n"
					"Enter choice:");
			scanf("%d",&x);
			switch(x)
			{
			case 1:
				int id_new;
				printf("Please Enter the new ID:");
				scanf("%d",&id_new);
				ptr->data.id=id_new;
				printf("Student's ID has been successfully updated\n");
				break;
			case 2:
				for(int i=0;i<50;i++)
				{
					ptr->data.name[i]='\0';
				}
				printf("Please Enter the new Name:");
				scanf("%s",ptr->data.name);
				printf("Student's name has been successfully updated\n");
				break;
			case 3:
				int age_new;
				printf("Please Enter the new Age:");
				scanf("%d",&age_new);
				ptr->data.age=age_new;
				printf("Student's Age has been successfully updated\n");
				break;
			case 4:
				float gpa_new;
				printf("Please Enter the new GPA:");
				scanf("%f",&gpa_new);
				ptr->data.gpa=gpa_new;
				printf("Student's GPA has been successfully updated\n");
				break;
			case 5:
				printf("Enter new ID:");
				scanf("%d",&id_new);
				ptr->data.id=id_new;
				printf("Enter new Name:");
				scanf("%s",ptr->data.name);
				printf("Enter new Age:");
				scanf("%d",&age_new);
				ptr->data.age=age_new;
				printf("Enter new GPA:");
				scanf("%f",&gpa_new);
				ptr->data.gpa=gpa_new;
				printf("Student's data has been successfully updated\n");
				break;

			}
			break;
		}
		else
		{
			ptr=ptr->next;
		}
	 }
}
/*SEARCH STUDENT WITH THE HIGHEST GPA*/
void searchHighestGPA(void)
{
	struct node *max = (struct node*)malloc(sizeof(struct node));//ceate a new node to store highest GPA student data
	struct node *max_ptr=max;//create a pointer to structure to that node
	struct node *current=head;
	if (head==NULL)
	{
		printf("This list is Empty");
	}
	else
	{
		while(current!=NULL)
		{
			if(current->data.gpa>max_ptr->data.gpa)
			{
				max_ptr->data=current->data;
				max->data=max_ptr->data;
			}
			current=current->next;
		}
		search_student(max->data.id);
	}

}
/*DELETE A CERTAIN STUDENT BY ID*/
void DeleteStudentByID(int data)
{
	int pos = 0;
	struct node *current = NULL;
	struct node *prev = NULL;
	struct node * delete_node = NULL;
	if(head==NULL)
	{
		printf("There's no Students to delete");
		return;
	}
	else
	{
		/*Check head node*/
		if(head->data.id == data)
		{
			delete_node = head;
			head = head->next;
			printf("Student has been successfully removed\n");
			free(delete_node);
			return;
		}
		/*search in the rest of the list*/
		pos++;
		current = head->next;
		prev = head;
		while(current != NULL)
		{
			if(current->data.id == data)
			{
				//element found
				delete_node = current;
				prev->next = current->next;
				printf("Student has been successfully removed\n");
				free(delete_node);
				return;
			}
			prev = current;
			current = current->next;
			pos++;
		}
		/*invalid ID*/
		if(delete_node==NULL)
		{
			printf("This ID doesn't exist\n");
		}
	}
}

/*MAIN FUNCTION*/
int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0); setvbuf(stderr, NULL, _IONBF, 0);
	for(;;)
	{
		printf("---------------------------------------------\n"
				"1.Add Student.\n"
				"2.Display Student.\n"
				"3.Search Student.\n"
				"4.Update Student By ID.\n"
				"5.Delete Student\n"
				"6.Calculate Average GPA.\n"
				"7.Search Highest GPA.\n"
				"8.Exit.\n"
				"---------------------------------------------\n");
		int num;
		printf("Enter a Choice :");
		scanf("%d",&num);
		printf("---------------------------------------------\n");
		switch(num)
		{
		case 1:
			AddStudent(&s);//add student data
			break;
		case 2:
			displayStudents();//display all students in the list
			break;
		case 3:
			int id_Search;
			printf("Please enter the id of the student you want to get :- \n");
			scanf("%d",&id_Search);//take ID from user
			search_student(id_Search);//get student's data
			break;
		case 4:
			int id;
			printf("Please Enter the ID you want to update :");
			scanf("%d",&id);//take ID from user
			UpdateStudentByID(id);//ask what to change exactly in student's data ana change it
			break;
		case 5:
			int id_delete;
			printf("Please Enter the ID you want to delete :");
			scanf("%d",&id_delete);
			DeleteStudentByID(id_delete);//remove student from the list
			break;
		case 6:
			float x = calculateAverageGPA();//save the result in a variable
			printf("\n Average GPA = %f \n",x);
			break;
		case 7:
			searchHighestGPA();//print the data of the student with the highest GPA
			break;
		case 8:
			return 0;
		}
	}

}



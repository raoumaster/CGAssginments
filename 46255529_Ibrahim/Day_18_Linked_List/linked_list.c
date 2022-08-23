/* Program to
--read a text file and store the words in a singly linked list.
--display the list which is created
--searches for a word and in the list and returns the number of occurences of the word.
--searches for a word and deletes the first node containing the word.
--create a duplicate of the original list
--deletes the entire list.*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 512

//Singly Linked List
struct Node
    {
        char data[MAX]; //Data is stored in Strings
        struct Node *next; //Pointer to the Next Node
    };
struct Node *head = NULL;//Header Pointer for First Node
struct Node *newNode = NULL; //Pointer for New Node which is created
struct Node *temp = NULL;//Temporary Pointer 
int count = 0; //Counter for Number of Nodes

//Displaying the Given Linked List
void display()
{
    printf("The Linked List is: \n");
    temp = head;
    while(temp != NULL)
    {
        printf("%s\n",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//Counting the Number of Nodes
void count_nodes()
{
    temp = head;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("The Given Linked List Contains %d Nodes\n",count);
}

//Deleting all the nodes
void delete_all()
{
    temp = head;
    while(temp->next != NULL)
    {
        newNode = temp;
        temp = temp->next;
        free(newNode);
    }
    free(temp);
}

//Search and Print the number of Occurences
int searchList(char word[MAX])
{
    int count_occ = 0; //Count the Number of Occurences
    temp = head;
    while(temp != NULL)
    {
        if((strcmp(temp->data,word)) == 0)
        {
            count_occ++;
        }
        temp = temp->next;
    }
    return count_occ;
}

//Search String and Delete that String
void deleteSearch(char word[MAX])
{
    temp = head; 
    struct Node *prevNode = NULL; //Previous Node to store the value
    if(temp != NULL && (strcmp(temp->data,word)) == 0)
    {
        temp = temp->next;
        display();
        return;
    }
    while(temp != NULL && (strcmp(temp->data,word)) != 0)
    {
        prevNode = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        return;
    }
    prevNode->next = temp->next;
    free(temp);
    display();
}

//Duplicate the given Linked List
struct Node *duplicate(struct Node *head)
{
    if(head == NULL)
    {
        return NULL;
    }
    else
    {
        newNode = (struct Node*)calloc(1,sizeof(struct Node));
        strcpy(newNode->data,head->data);
        //newNode->data = node->data
        newNode->next = duplicate(head->next);
        return newNode;
    }
}

int main()
{
    //Linked List Demo

    char URL[MAX];
    char str[MAX]; //User Input to Search the given String
    char str1[MAX];
    FILE *fp;
    fp = fopen("test.txt","rt");
    if(fp == NULL)
    {
        printf("File doesn't Exist");
        exit(EXIT_FAILURE);
    }

    while((fscanf(fp,"%s",URL)) != EOF)
    {
        //Allocate Memory to the NewNode and copy the url
        newNode = (struct Node*)calloc(1,sizeof(struct Node));
        //Copy the Contents to the new Node
        strcpy(newNode->data,URL);
        newNode->next = 0; //Allocating 0 so it isn't stored in any random value

        if(newNode == NULL)
        {
            fclose(fp);
            printf("Memory Allocation Failure");
            exit(EXIT_FAILURE);
        }

        if(head == 0)
        {
            head = temp = newNode;
        }
        else
        {
            for(temp = head; temp->next != NULL; temp = temp->next);//Bring the Pointer to the last node
            temp->next = newNode; //Add the node to the last
            temp = temp->next; // Move the Value to the next variable
        }
    }
    fclose(fp);

    //Printing the values
    display();

    //Counting the Number of Nodes
    count_nodes();

    //Search and print the number of Occurences
    printf("Enter the String you want to search:");
    gets(str);
    printf("The word %s occurs %d Times\n",str,searchList(str));
    printf("\n");

    //Search and Delete the First Occurence
    printf("Enter String and Delete from Linked List:");
    gets(str1);
    deleteSearch(str1);

    //Duplicate a Given String
    struct Node *dup = duplicate(head);
    printf("The String has been Duplicated Successfully\n");
    display(dup);

    //Deleting the nodes
    delete_all();
    return 0;
}

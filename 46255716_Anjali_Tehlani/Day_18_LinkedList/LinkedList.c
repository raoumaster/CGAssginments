#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

//Structure of the Node
typedef struct link{
        char *name;
        struct link *nextlink;
}link,temp;

//Printing the Linked List
void printLinkedList(link *i)
{
       printf("%s\n",i->name);
       if(i->nextlink != NULL)
       {
                printLinkedList(i->nextlink);
       }
}

//Reading from file and converting it into Linked List
link* fReader(FILE *file)
{
        link *i = malloc(sizeof(link));
        char islandName[20];
        int fileRead = fscanf(file,"%s",islandName);
        if(fileRead != EOF){
                i->name = strdup(islandName);
                i->nextlink = fReader(file);
        }
        if(fileRead == EOF) {
                return NULL;
        }
        return i;
}

//Search string from the Linked List and return no. of occurences
int searchFromList(char word[MAX],link *i)
{
       int count=0,val;
       link *temp = i;

       while(temp != NULL)
       {
               if ((strcmp(temp->name,word)) == 0)
	       {
                 count++;
               }
               temp = temp->nextlink;
        }
        return count;
}

//Search string from list and delete that string from Linked List
void deleteStr(char word[MAX],link *i)
{
       link *temp = i;
       link *prev = NULL;
       link *print = i;
 
       if(temp !=NULL && (strcmp(temp->name,word))==0)
       {
                temp = temp->nextlink;
                printLinkedList(temp);
                return;
       }

       while(temp != NULL && (strcmp(temp->name,word)) != 0)
       {
                prev = temp;
                temp = temp->nextlink;
       }

       if(temp == NULL)
       {
                return;
       }

       prev->nextlink = temp->nextlink;
       free(temp);
       printLinkedList(print);
}

//Creating duplicate of the Linked List
link* dupList(link *i)
{
        if(i == NULL)
        {
                return NULL;
        }
        else
        {
                link* newnode = malloc(sizeof(link));
                newnode->name = i->name;
                newnode->nextlink = dup(i->nextlink);
		return newnode;
        }
}

//Deleting Linked List
void freeList(link *i)
{
       link *prev = i;
       while(i != NULL)
       {
           i = i->nextlink;
           free(prev);
           prev = i;
       }
       printf("\nList is deleted");
}

int main(){
        FILE *x = fopen("a.txt","r");
        link *i = fReader(x);

        char str1[MAX];
        char str2[MAX];
        printLinkedList(i);

        printf("Enter the word that to be search in the List : ");
        gets(str1);
        printf("%d\n",searchFromList(str1,i));
        printf("Enter the string to delete from Linked List : ");
        gets(str2);
        deleteStr(str2,i);
        printf("\n\n This is Duplicate List : \n\n");
        link *duplicate = dupList(i);
        printLinkedList(duplicate);
        freeList(i);
        fclose(x);
}
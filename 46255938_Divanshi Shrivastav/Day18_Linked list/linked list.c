//Linked list Assignment


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20



//structure of node
typedef struct link{
        char *name;
        struct link *nextlink;
}link,temp;



//printing linked list
void printLink(link *i){
        printf("%s\n",i->name);

	if(i->nextlink != NULL){
                printLink(i->nextlink);
        }
}

//reading from file and converting into linked list
link* fileReader(FILE *file){
        link *i = malloc(sizeof(link));
        char islandName[20];
        int fileRead = fscanf(file,"%s",islandName);
        if(fileRead != EOF){
                i->name = strdup(islandName);
                i->nextlink = fileReader(file);
        }
        if(fileRead == EOF) {
                return NULL;
        }
        return i;
}


//search string from linked list and return no of occurences
int searchList(char word[MAX],link *i){
        int count=0,val;
        link *temp=i;



       while(temp != NULL)
        {
		if ((strcmp(temp->name,word)) == 0){

			count++;
                }
                temp = temp->nextlink;
        }
        return count;
}

//search string from list and delete that string from linked list
void dtsr(char word[MAX],link *i){
        link *temp = i;
        link *prev = NULL;



       link *print = i;

	  if(temp !=NULL && (strcmp(temp->name,word))==0){
                temp = temp->nextlink;

		 printLink(temp);
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

        printLink(print);
}

//creating duplicate of the linked list
link* dupli(link *i)
{
        if(i == NULL)
        {
                return NULL;
        }
        else
        {
                link* newnode = malloc(sizeof(link));
                newnode->name = i->name;

	        newnode->nextlink = dupli(i->nextlink);

	        return newnode;
        }
}


//deleting whole linked list
void freell(link *i)
{
        link *prev = i;


		while(i != NULL)
        {
                i = i->nextlink;
                free(prev);
                prev = i;
        }
        printf("\nlist freed");
}

int main(){
        FILE *x = fopen("demo.txt","r");
        link *i = fileReader(x);
        char str1[MAX];
        char str2[MAX];
        printLink(i);
        printf("enter the word: ");
        gets(str1);
        printf("%d\n",searchList(str1,i));
        printf("Enter string to delete: ");
        gets(str2);
        dtsr(str2,i);
        printf("\n\nThis is a duplicate list\n\n");
        link *duplicate = dupli(i);
        printLink(duplicate);
        freell(i);
        fclose(x);
}
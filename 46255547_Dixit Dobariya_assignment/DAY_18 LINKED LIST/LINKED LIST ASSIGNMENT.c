/*
Write an application that performs few linked list operations on words from a file.
The file name is accepted as command line argumment.   
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20



//node formation
typedef struct link{
        char *name;
        struct link *nextlink;
}link,temp;



//LL/02
void printLink(link *i){
        printf("%s\n",i->name);



       if(i->nextlink != NULL){
                printLink(i->nextlink);
        }
}



/* LL/01
Write a function to read a text file and store the words in a
singly linked list. You may assume that the maximum length
of a word will be of 20 characters. The addition to the list
will be at the end.
*/
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



//LL/03
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


//LL/05
//search string from list and delete that string from linked list
void delStr(char word[MAX],link *i){
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


//LL/05
//creating duplicate of the linked list
link* duplicate(link *i)
{
        if(i == NULL)
        {
                return NULL;
        }
        else
        {
                link* newnode = malloc(sizeof(link));
                newnode->name = i->name;



               newnode->nextlink = duplicate(i->nextlink);



               return newnode;
        }
}


//LL/06
//deleting whole linked list
void freelist(link *i)
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


//Driver Program for linked list
int main(){
        FILE *x = fopen("a.txt","r");
        link *i = fileReader(x);
        char str1[MAX];
        char str2[MAX];
        printLink(i);
        printf("enter word to be search in the list: ");
        gets(str1);
        printf("%d\n",searchList(str1,i));
        printf("enter string to delete from linked list: ");
        gets(str2);
        delStr(str2,i);
        printf("\n\nThis is a duplicate list\n\n");
        link *duplicate = dup(i);
        printLink(duplicate);
        freelist(i);
        fclose(x);
}
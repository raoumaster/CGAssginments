/*
    Q1. Write a function to read a text file and store the words in a singly linked list. The addition to the list will be at the end.
    Q2. Write a function to display the list which is created.
    Q3. Write a function which searches for a word and in the list and returns the number of occurences of the word.
    Q4. Write a function which searches for a word and deletes the first node containing the word.
    Q5. Write a function to create a duplicate of the original list.
    Q6. Write a function which deletes the entire list. 
*/

#include <stdio.h>  
#include <stdlib.h> 
#include <string.h>
#define MAX 20

//Create structure for linked list node
struct node   
{  
    char word[MAX];  
    struct node *next;  
};  

//Create node for start
struct node *start;

//Inserting words into linked list
void insert(char* word) {  
    struct node *ptr = (struct node*)malloc(sizeof(struct node));   //Assign memory to ptr
    struct node *temp; 
    
    if(ptr == NULL) {  
        printf("Not able to push the element into Linked List!\n");   
    }  
    else {  
        strcpy(ptr -> word, word);
        
        if(start == NULL) {         
            ptr -> next = NULL;  
            start = ptr;  
        }   
        else {  
            temp = start;  
            while (temp -> next != NULL) {  
                temp = temp -> next;  
            }  
            temp -> next = ptr;  
            ptr -> next = NULL;  
        }  
    }  
} 

//Read file and store using insert function
void read_store(FILE *src) {
    char word[100];
    
    //If file is not present
    if (src == NULL) {  
        printf("No such file!\n"); 
    }

    //Reading each word
    while (fscanf(src, "%s", word) == 1)
        insert(word);
        
    fclose(src);
}

//Display the Linked list
void display(struct node* ptr) {  
    //If linked list is empty
    if(ptr == NULL) {  
        printf("Linked list is Empty!\n");  
    }  
    else {  
        printf("Printing Linked List elements: \n");  
        while(ptr != NULL)  
        {  
            printf("%s\n", ptr -> word);  
            ptr = ptr -> next;  
        }  
    }  
}

//Count number of occurences of word in Linked List
int word_occurences() {
    struct node *ptr;  
    ptr = start;  
    char word[MAX];
    int word_count = 0;
    
    printf("\nEnter word want to be search: ");
    scanf("%s", word);
    
    if (start == NULL) {  
        printf("Linked List is Empty.");  
    }
    else {
        while(ptr != NULL) {   
            if(strcmp(word, ptr -> word) == 0)
                word_count++;
            
            ptr = ptr -> next; 
        } 
    }
    
    return word_count;
}

//Delete first occurence of word
void delete_node() {  
    char word[MAX];
    struct node *ptr, *temp; 
    temp = start;
    
    printf("\nEnter word want to be search and delete: ");
    scanf("%s", word);
    
    if (temp != NULL && (strcmp(word, temp -> word) == 0)) {
        start = temp -> next;   //changed head
        free(temp); //free old head
        return;
    }
 
    while (temp != NULL && (strcmp(word, temp -> word) != 0)) {
        ptr = temp;
        temp = temp->next;
    }
 
    //If key was not present in linked list
    if (temp == NULL){
        printf("Word is not present in list!\n\n");
        return;
    }
 
    //Unlink the node from linked list
    ptr -> next = temp -> next;
 
    free(temp);
}  

//Create a duplicate of list
struct node* duplicate_ll(struct node* ptr) {
	if(ptr == NULL) {
		return NULL;
	}	
	else {
		struct node* newNode = (struct node*)malloc(sizeof(struct node));
		strcpy(newNode -> word, ptr -> word);
		newNode -> next = duplicate_ll(ptr -> next);

		return newNode;
	}
}

//Delete entire list
void delete_all(struct node* ptr) {
    struct node* temp;
    while(ptr != NULL) {
        temp = ptr;
        ptr = ptr -> next;
        free(temp);
    }
}

int main(int argc, char* argv[]){
    //open file
    FILE* src = fopen(argv[1], "r");
    struct node *ptr;
    struct node* duplicate;
    
    //Reading file and store words into Linked List
    printf("Reading file and store words into Linked List...\n\n");
    read_store(src);
    printf("Words were stored into Linked List!\n\n");
    
    //Disp the Linked List
    display(start);
    
    //Display Total number of occurences of word in list
    printf("Total Word Occurences: %d\n", word_occurences());
    
    //Delete first occurence of word
    delete_node();
    printf("\nList after delete the node: \n");
    display(start);
    
    //Duplicate the Linked List
	  duplicate = duplicate_ll(start);
	  printf("\nThe Duplicated list is: \n");
	  display(duplicate);
	
    //Delete entire list
    delete_all(start);
    printf("\nEntire list is deleted.");
	
	  return 0;
}

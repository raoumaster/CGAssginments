/*
    Read text file and store lines into stack.
    Display stack data structure.
    Find size of longest line.
    Create output file consist same data as source but last line come first.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define LINE_SIZE 80
#define STACK_SIZE 50

//for pushing data into stack
void push(char stack[STACK_SIZE][LINE_SIZE], int *top, char line[LINE_SIZE]) {
    if(*top == STACK_SIZE -1)
        printf("\n Stack is Full.\n");        
    else {
        *top = *top + 1;
        strcpy(stack[*top], line);
    }
}

//for reading source file
void readFile(char *source, char stack[STACK_SIZE][LINE_SIZE], int *top) {
    char line[LINE_SIZE];
    
    FILE* src = fopen(source, "r");
    
    while ((fgets(line, LINE_SIZE, src)) != NULL)
        push(stack, top, line);
        
    printf("All lines are Pushed in Stack.\n\n");
    fclose(src);
}

//for display stack data structure
int displayStack(char stack[STACK_SIZE][LINE_SIZE], int *top){
    for(int i = *top; i >=0 ; i--) {
	    printf("%s", stack[i]);
    }
    return *top+1;
}

//for finding longest line
int longestLine(){
    char line[80];
    int lengthCurrentLine, lengthLongestLine = 0;
    int currentLineNo = 1, longestLineNo;
    
    FILE* src = fopen("src.txt", "r");
    
    while ((fgets(line, 100, src)) != NULL){
        lengthCurrentLine = strlen(line);
        
        if(lengthCurrentLine > lengthLongestLine) {
            lengthLongestLine = lengthCurrentLine;
            longestLineNo = currentLineNo;
        }
        currentLineNo++;
    }
    fclose(src);
    
    printf("\n%d no. line is longest.\n", longestLineNo);
    
    return lengthLongestLine;
}

//for writing data into other file
void writeFile(char *output, char stack[STACK_SIZE][LINE_SIZE], int *top) {
    FILE *out = fopen(output, "w+");
    
    for(int i = *top; i >=0 ; --i){
        fputs(stack[i], out);
    }
    fclose(out);
}

int main(int argc, char *argv[])
{
    char stack[STACK_SIZE][LINE_SIZE], line[LINE_SIZE]; //define stack array
    int top = -1;   // Initialize Stack Top element
    
    //Reading data from source file and store lines into stack
    printf("Reading the file and Pushing into the Stack.....\n\n");
    readFile(argv[1], stack, &top);
    
    //Display stack data structure with total size 
    printf("Items of Stack:\n");
    printf("\nTotal lines are in stack: %d.\n", displayStack(stack, &top));
    
    //find longest line from file
    int lengthLongestLine = longestLine();
    printf("Size of longest line is: %d.\n\n", lengthLongestLine);
    
    //Writing data of source into output filr but last come first
    printf("Writing data into other file.....\n\n");
    writeFile(argv[2], stack, &top);
    printf("Writing into other file done.\n");
          
    return 0;
}

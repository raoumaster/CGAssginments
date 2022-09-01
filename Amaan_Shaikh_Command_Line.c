/* To get the server name and port number from the user and get the required functions according to the requirement*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Defining the constants and assigning the value*/
#define MAX_RANGE 1023 // Maximum Port number Range
#define MAX_LENGTH 30 // Maximum user input
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

 

// For taking the input from the user
int val_input(char *input){ 
//server1:80 server2:423 server3:25 server4:154 
    char *sname = NULL;
    char *portnum = NULL;
    char token[MAX_LENGTH];
    int portNo;
    
    int serverLen;
    int portLen;
  
    int flag1 = 1, flag2 = 1;
    
    strcpy(token,input);
    
    sname = strtok(token, ":"); 
    portnum = strtok(NULL, ":"); 
    serverLen = strlen(sname);
    portLen = strlen(portnum);
    
    // Q2 Validating the server name whether its alphanumeric or not
    for(int i = 0; i < serverLen; i++){
        if(!isalpha(sname[i])){
            flag1 = 0;
            break;
        }
    }
    //Q2 Validating the port number whether it is only digit or not
    for(int i = 0; i < portLen; i++){
        if(!isdigit(portnum[i])){
            flag2 = 0;
            break;
        }
    }
    
   //Q2 checking server port number if in range of 1024
   if(flag1 && flag2){
        // Validating range of port number
        if(atoi(portnum)>0 && atoi(portnum)<= MAX_RANGE){
            return (EXIT_FAILURE);
        }
    }
    return(EXIT_SUCCESS);
}

//Q3  Displaying the contents
char* display(char *input){

    char token[MAX_LENGTH];
    char *sname = NULL;
    char *portnum = NULL;
    char *name = NULL;
    int serverLen;
    
    strcpy(token,input);
    sname = strtok(token, ":");
    portnum = strtok(NULL, ":");
    
    printf("\nServer Name: %s\t Port No: %s\n", sname, portnum);
    serverLen = strlen(sname);
    name = (char*) calloc((serverLen+1), sizeof(char));
    strcpy(name, sname);
    return name;
}
    
int main(int argc, char *argv[]){
    int i, value;
    char *fullstring[MAX_LENGTH];
    char *name = NULL;
    char str[MAX_LENGTH];

    // Q1 Checking total numbers of valid arguments 
    if(argc < 4){
        printf("\nPlease provide more then 3 arguments!!!");
        exit(EXIT_FAILURE);     
    }
    
    for(i = 1; i < argc; i++){
        value = val_input(argv[i]);
        if(value == 1){
            exit(EXIT_FAILURE);
        }
        printf("Second funcation direct print:-");
        name = display(argv[i]);
        fullstring[i] = name;
    }
    
   
   for(i = 1; i < argc; i++){
        printf("\nprintf :- %s", fullstring[i]);
    }
    printf("\n Hi I am ");
    for (int i=0; i<argc; i++) {
        printf("free:- %s\n",fullstring[i]);
        free(fullstring[i]);
    }
    printf("\nsizeof:-  %ld", sizeof(fullstring));
    return 0;
}
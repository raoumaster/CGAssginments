#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 

#define SIZE_STRUCTURE(x) sizeof(x)
#define NAME_SIZE 80

 

typedef struct {
    int age;
    float weight;
    char *name;
} person;

 

void freefunc(person *ptr){
    free(ptr);
    ptr = NULL;
}

 

void display(person *ptr, int n){
    printf("\nDisplaying Information:\n");
    for(int i = 0; i < n; ++i){
       printf("Name: %s\tAge: %d\tweight: %f\n", (ptr+i)->name, (ptr+i)->age, (ptr+i)->weight);
    }
}

 

person* copy(person *ptr, int n){
    person *cp = NULL; //declare pointer to structure
    cp = malloc(n * SIZE_STRUCTURE(person));
    memcpy(cp,(ptr+n-1),SIZE_STRUCTURE(person));
    display(cp, 1);
    
    freefunc(cp);
}

 

int main(){
    person *ptr = NULL;
    int i, n;
    int studentAge = 0; //declare var to store student age
    float studentweight = 0; //declare var to store student roll number
    char studentName[NAME_SIZE] = {0}; //declare array to store student name
    
    printf("\nEnter the no of employee\n");
    scanf("%d", &n);
    ptr = malloc(n * SIZE_STRUCTURE(person));//Allocate memory for structure pointer
    if (ptr == NULL)
        return 0;
    
    for(i = 0; i <n; i++){
        printf("Enter %d Employee age, weight and name respectively: ", i+1);
        scanf("%d %f", &studentAge, &studentweight);
        (ptr+i)->age = studentAge;
        (ptr+i)->weight = studentweight;
        getchar();
        fgets(studentName, NAME_SIZE, stdin);
        (ptr+i)->name = malloc(NAME_SIZE);
        if((ptr+i) == NULL){
            printf("Failed to Allocate Memory");
            return 0;
        }
        strncpy((ptr+i)->name, studentName, NAME_SIZE);
    }
    
    display(ptr, n);
    copy(ptr, n);
    freefunc(ptr);
}

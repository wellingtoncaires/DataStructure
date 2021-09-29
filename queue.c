#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Person {
    int id;
    char name[20];
    int age;
    struct Person *next;
}Person;

struct Person *list, *firstPointer, *auxiliar;
int idGen = 0;
int queueSize = 0;

int validAnswer(){
    char answer;
    do{
        printf("\n\n Would you like to continue [Y/N]: ");
        fflush(stdin);
        scanf("%c", &answer);
        answer = toupper(answer);
    }while(answer != 'Y' && answer != 'N');
    if(answer == 'Y'){
        system("cls");
        return 0;
    }else{
        return 1;
    }
}

void enterData(){
    printf("\n Enter user data:\n");
    idGen++;
    auxiliar = (Person*) malloc(sizeof(Person));
    auxiliar->id = idGen;
    printf("\n Inform user name: ");
    scanf("%s", &auxiliar->name);
    printf(" Inform user age: ");
    scanf("%d", &auxiliar->age);
}

void enqueue(){
    queueSize++;
    enterData();
    if(firstPointer == NULL){
        auxiliar->next = NULL;
        list = auxiliar;
        firstPointer = auxiliar;
    }else {
        auxiliar->next = NULL;
        list->next = auxiliar;
        list = auxiliar;
    }

}

void sequeue(){
    auxiliar = firstPointer;
    if(auxiliar == NULL){
        printf("\n There is no user registered.");
    }else {
        printf("\n Users Registered:");
        while(auxiliar != NULL){
            printf("\n ID = %d     Name = %s   Age = %d", auxiliar->id, auxiliar->name, auxiliar->age);
            auxiliar=auxiliar->next;
        }
    }
}

void dequeue(){
    queueSize--;
    auxiliar = firstPointer;
    if(auxiliar == NULL){
        printf("\n There is no user registered.");
    }else {
        firstPointer = auxiliar->next;
        free(auxiliar);
    }
}

int main(){

    list = NULL;
    firstPointer = NULL;
    auxiliar = NULL;
    int id;

    do{
        int option;
        system("cls");
        printf("\n            Queue");
        printf("\n----------------------------\n");
        printf("\n Choose option:");
        printf("\n 1: Insert new user");
        printf("\n 2: Show users");
        printf("\n 3: Remove user");
        printf("\n");
        scanf("%d", &option);

        switch(option){
            case 1: system("cls");
                if (queueSize == 4){
                    printf("\n Stackoverflow");
                    return;
                }
                enqueue();
                break;
            case 2: system("cls");
                sequeue();
                break;
            case 3: system("cls");
                dequeue();
                break;
            default:
                printf("\n Invalid option");
        }

    }while(validAnswer() == 0 && queueSize < 5);
    // Simulate memory size with a int number
}


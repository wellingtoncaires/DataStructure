#include<stdio.h>
#include<stdlib.h>


typedef struct Person{
    int id;
    char name[20];
    int age;
    struct Person *next, *back;
}Person;

struct Person *list, *firstPointer, *lastPointer, *auxiliar, *upUser, *ax2, *ax3;
int idGen = 0;

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

void createUser(){
    enterData();
    if(firstPointer == NULL){
        auxiliar->next = NULL;
        auxiliar->back = NULL;
        list = auxiliar;
        firstPointer = auxiliar;
        lastPointer = auxiliar;
    }else {
        auxiliar->next = NULL;
        auxiliar->back = list;
        list->next = auxiliar;
        list = auxiliar;
        lastPointer = list;
    }
}

void findAll(){
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

void findById(int id){
    auxiliar = firstPointer;
    int notFound = 0;
    if(auxiliar == NULL){
        printf("\n There is no user registered.");
        notFound = 1;
    }else {
        while(auxiliar != NULL){
            if(auxiliar->id == id){
                printf("\n User searched:");
                printf("\n ID = %d     Name = %s   Age = %d", auxiliar->id, auxiliar->name, auxiliar->age);
                notFound = 1;
                break;
            }
            auxiliar = auxiliar->next;
        }
    }
    if(notFound == 0){
        printf("\n ID: %d not found.", id);
    }
}

void updateUser(int id){
    auxiliar = firstPointer;
    int notFound = 0;
    if(auxiliar == NULL){
        printf("\n There is no user registered.");
        notFound = 1;
    }else{
        while(auxiliar != NULL){
            if(auxiliar->id == id){
                int option;
                printf("\n What would you like to update? %s:", auxiliar->name);
                printf("\n 1: Name:");
                printf("\n 2: Age:");
                printf("\n 3: Name and age:");
                printf("\n");
                scanf("%d", &option);
                switch(option){
                    case 1: system("cls");
                        printf("\n Inform the new name: ");
                        scanf("%s", &auxiliar->name);
                    break;
                    case 2: system("cls");
                        printf("\n Inform the new age: ");
                        scanf("%d", &auxiliar->age);
                        break;
                    case 3: system("cls");
                        printf("\n Inform the new name: ");
                        scanf("%s", &auxiliar->name);
                        printf(" Inform the new age: ");
                        scanf("%d", &auxiliar->age);
                        break;
                    default: system("cls");
                        printf("\n Invalid option.");
                        break;
                }
                notFound = 1;
                break;
            }
            auxiliar = auxiliar->next;
        }
    }
    if(notFound == 0){
        printf("\n ID: %d not found", id);
    }
}

void deleteUser(int id){
    auxiliar = firstPointer;
    int notFound = 0;
    if(auxiliar == NULL){
        printf("\n There is no user registered.");
        notFound = 1;
    }else {
        while(auxiliar != NULL){
            if(auxiliar->id == id){
                if(auxiliar->next == NULL){
                    if(auxiliar == firstPointer){
                        firstPointer = NULL;
                    } else {
                        ax2->next = NULL;
                        list = ax2;
                        lastPointer = ax2;
                    }
                }else {
                    auxiliar = auxiliar->next;
                    auxiliar->back = ax2;
                    auxiliar = ax2->next;
                    ax2->next = auxiliar->next;
                }

                notFound = 1;
                free(auxiliar);
                break;
                return;
            }
            ax2 = auxiliar;
            auxiliar = auxiliar->next;
        }
    }
    if(notFound == 0){
        printf("\n ID: %d not found.", id);
    }
}

void classInsert(int enter){
    enterData();
    auxiliar->next = NULL;
    auxiliar->back = NULL;

    if(firstPointer == NULL){
        list = auxiliar;
        firstPointer = auxiliar;
    }else {
        int count = 0;
        ax2 = firstPointer;
        while(ax2 != NULL){
            if(strcmp(ax2->name, auxiliar->name) >= 0){
                if(count > 0){
                    auxiliar->next = ax2->next;
                    ax2->next = auxiliar;
                    auxiliar->back = ax2;
                    ax2 = auxiliar->next;
                    ax2->back = auxiliar;
                }else {
                    auxiliar->next = ax2;
                    ax2->back = auxiliar;
                    firstPointer = auxiliar;
                }
                return;
                break;
            }
            ax3 = ax2;
            ax2 = ax2->next;
            count++;
        }
        list->next = auxiliar;
        list = auxiliar;
    }
}


int main(){

    list = NULL;
    firstPointer = NULL;
    lastPointer = NULL;
    auxiliar = NULL;
    ax2 = NULL;
    ax3 = NULL;

    int id;

     do{
        int option;
        system("cls");
        printf("\n Double linked List");
        printf("\n----------------------------\n");
        printf("\n Choose option:");
        printf("\n 1: Create a new user");
        printf("\n 2: Show all users");
        printf("\n 3: Search an user");
        printf("\n 4: Update user data");
        printf("\n 5: Delete an user");
        printf("\n");
        scanf("%d", &option);

        switch(option){
            case 1: system("cls");
                classInsert(0);
//                createUser();
                break;
            case 2: system("cls");
                findAll();
                break;
            case 3: system("cls");
                printf("\n Inform user ID: ");
                scanf("%d", &id);
                findById(id);
                break;
            case 4: system("cls");
                printf("\n Inform user ID: ");
                scanf("%d", &id);
                updateUser(id);
                break;
            case 5: system("cls");
                printf("\n Inform user ID to be deleted: ");
                scanf("%d", &id);
                deleteUser(id);
                break;
            default:
                printf("\n Invalid option");
        }
    }while(validAnswer() == 0);

}

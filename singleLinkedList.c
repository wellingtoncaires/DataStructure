#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Person {
    int id;
    char name[20];
    int age;
    struct Person *next;
}Person;

struct Person *list, *firstPointer, *auxiliar, *ax2, *ax3;
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

void classInsert(){
    enterData();
    auxiliar->next = NULL;
    if(firstPointer == NULL){
        list = auxiliar;
        firstPointer = auxiliar;
    }else {
        int count = 0;
        ax2 = firstPointer;
        while(ax2 != NULL){
            if(strcmp(ax2->name, auxiliar->name) >= 0){
                if(count > 0){
                    ax3->next = auxiliar;
                    auxiliar->next = ax2;
                }else {
                    auxiliar->next = ax2;
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

void createUser(){
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
                    }
                }else {
                    if(auxiliar == firstPointer){
                        firstPointer = auxiliar->next;
                    }else {
                        ax2->next = auxiliar->next;
                    }
                }

                notFound = 1;
                free(auxiliar);
                break;
            }

            ax2 = auxiliar;
            auxiliar = auxiliar->next;
        }
    }
    if(notFound == 0){
        printf("\n ID: %d not found.", id);
    }
}

void selectHalfList(){
    auxiliar = firstPointer;
    float counter = 0;
    if(auxiliar == NULL){
        printf("\n There is no user registered.");
    }else {
        while(auxiliar != NULL){
            auxiliar = auxiliar->next;
            counter++;
        }
        auxiliar = firstPointer;
        float siz = counter / 2;
        for(int i = 0; i < siz; i++){
            printf("\n ID = %d     Name = %s   Age = %d", auxiliar->id, auxiliar->name, auxiliar->age);
            auxiliar = auxiliar->next;
        }
    }
}

void removeEven(int id){
    auxiliar = firstPointer;
    int counter = 0;
    int notFound = 0;
    if(auxiliar == NULL){
        printf("\n There is no user registered.");
    }else {
        while(auxiliar != NULL){
            counter++;
            if(auxiliar->id == id){

                if(counter % 2 == 0){
                    printf("\n Not authorized deletion , the ID %d is placed at position %d:", id, counter);
                }else {
                    deleteUser(id);
                    printf("\n Deleted succesfully");
                }
                notFound = 1;
                break;
                return;
            }
            auxiliar = auxiliar->next;
        }
    }
    if(notFound == 0){
        printf("\n ID: %d not found", id);
    }
}

int main(){

    list = NULL;
    firstPointer = NULL;
    auxiliar = NULL;
    ax2 = NULL;
    ax3 = NULL;
    int id;

    do{
        int option;
        system("cls");
        printf("\n Single linked List");
        printf("\n----------------------------\n");
        printf("\n Choose option:");
        printf("\n 1: Create a new user");
        printf("\n 2: Show all users");
        printf("\n 3: Search an user");
        printf("\n 4: Update user data");
        printf("\n 5: Delete an user");
        printf("\n 6: Show partial list");
        printf("\n 7: Delete only if user is placed at odd position");
        printf("\n");
        scanf("%d", &option);

        switch(option){
            case 1: system("cls");
                classInsert();
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
            case 6: system("cls");
                selectHalfList();
                break;
            case 7: system("cls");
                printf("\n Inform user ID to be deleted by checking place: ");
                scanf("%d", &id);
                removeEven(id);
                break;
            default:
                printf("\n Invalid option");
        }
    }while(validAnswer() == 0);

}

#include<stdio.h>
#include<stdlib.h>

typedef struct Person{
    int id;
    char name[20];
    int age;
    struct Person *up, *down;
}Person;

struct Person *top, *auxiliar;
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
    auxiliar->up = NULL;
    auxiliar->down = NULL;
}

void push(){
    enterData();
    if(top == NULL){
        top = auxiliar;
    }else {
        auxiliar->down = top;
        top->up = auxiliar;
        top = auxiliar;
    }
}

void show(){
    auxiliar = top;
    if(auxiliar == NULL){
        printf("\n There is no user registered.");
    }else {
        printf("\n Users Registered:");
        while(auxiliar != NULL){
            printf("\n ID = %d     Name = %s   Age = %d", auxiliar->id, auxiliar->name, auxiliar->age);
            auxiliar=auxiliar->down;
        }
    }
}

void pop(){
    if(top == NULL){
        printf("\n There is no user registered.");
    }else if(top->down == NULL){
        free(top);
        top = NULL;
    }else {
        auxiliar = top;
        top = auxiliar->down;
        top->up = NULL;
        free(auxiliar);
        printf("\n Deleted succesfully");
    }
}

void topRegister(){
    if(top == NULL){
        printf("\n There is no user registered.");
    }else {
        printf("\n Last register: ");
        printf("\n ID = %d     Name = %s   Age = %d", top->id, top->name, top->age);
    }
}

int main(){

    do {
        if(idGen > 9){
            printf("\n STACKOVERFLOW");
            break;
        }else {
            int option;
            system("cls");
            printf("\n Stack");
            printf("\n----------------------------\n");
        printf("\n Choose option:");
            printf("\n 1: Create a new user");
            printf("\n 2: Show all users");
            printf("\n 3: Show last register");
            printf("\n 4: Delete an user");

            printf("\n");
            scanf("%d", &option);

            switch(option){
                case 1: system("cls");
                    push();
                    break;
                case 2: system("cls");
                    show();
                    break;
                case 3: system("cls");
                    topRegister();
                    break;
                case 4: system("cls");
                    pop();
                    break;
                default:
                    printf("\n Invalid option");
            }
        }
    }while(validAnswer() == 0 );
}

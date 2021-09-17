#include<stdio.h>
#include<stdlib.h>

typedef struct Person{
    char name[20];
    int age;
}Person;

void main() {

    Person *a,*b,*c;
    a = NULL;
    b = NULL;
    c = NULL;

    a=(Person*)malloc(sizeof(Person));
    scanf("%s", &a->name);
    scanf("%d", &a->age);

    b=(Person*)malloc(sizeof(Person));
    scanf("%s", &b->name);
    scanf("%d", &b->age);

    c=(Person*)malloc(sizeof(Person));
    scanf("%s", &c->name);
    scanf("%d", &c->age);

    printf("A name = %s; A age = %d", a->name, a->age);
    printf("B name = %s; B age = %d", b->name, b->age);
    printf("C name = %s; C age = %d", c->name, c->age);
    system("pause");
}

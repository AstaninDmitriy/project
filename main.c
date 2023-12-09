#include <stdio.h>
#include <stdlib.h>

void arr(int **mass, int *size);
void insert(int **mass, int num, int index, int *size);
void append(int **mass, int num, int *size);
void del(int **mass, int *size, int index);

int main() {
    int *mass = NULL;
    int size;
    int command;
    int index;
    int num;


    while (1) {
        printf("\n");
        printf("                  MENU                  \n");
        printf("----------------------------------------\n");
        printf("0 - Завершить программу.\n");
        printf("1 - Заполнить массив данными.\n");
        printf("2 - Вставка эл. по индексу(insert).\n");
        printf("3 - Вставка эл. в конец массива(append).\n");
        printf("4 - Удаление элемента по индексу(del).\n");
        printf("----------------------------------------\n");
        printf("\n");
        printf("Введите номер действия - ");

        scanf("%d", &command);

        if (command == 0) {
            free(mass);  // Free the allocated memory before exiting
            break;
        } 
        else if (command == 1) {
            if(mass == NULL){
                arr(&mass, &size);
            } else {
                printf("Массив уже создан!\n");
                printf("\n");
            }
            
        } 
        else if(command == 2) {
            if(mass == NULL){
                printf("\n");
                printf("Массива не существует!\n");
                printf("\n");
            } else {
                printf("Введите число которое нужно добавить - ");
                scanf("%d", &num);
                printf("Введите индекс по которому нужно добавить число(от 1 до %d) - ", size);
                scanf("%d", &index);
                insert(&mass, num, index, &size);
            }
        } 
        else if(command == 3){
            if(mass == NULL){
                printf("\n");
                printf("Массива не существует!\n");
                printf("\n");
            } else {
                printf("Ввете число которое довавить в конец масссива - ");
                scanf("%d", &num);
                append(&mass, num, &size);

            }
        } else if(command == 4){
            if(mass == NULL){
                printf("\n");
                printf("Массива не существует!\n");
                printf("\n");
            } else {
                printf("Введите индекс числа который нужно убрать из массива - ");
                scanf("%d", &index);
                del(&mass, &size, index);
            }
        }
    }

    return 0;
}

void arr(int **mass, int *size) {
    int n;
    char ch;
    printf("Введите размерность массива - ");
    printf("\n");
    
    if(scanf("%d%c", &n, &ch) == 2 && ch == '\n'){
        *mass = (int *)malloc(n * sizeof(int));
        *size = n;
        printf("Введите элементы массива:\n");
        for (int i = 0; i < n; i++) {
            scanf("%d", &(*mass)[i]);
        }
        printf("\n");
        printf("Ваш массив:\n");

        for (int i = 0; i < n; i++) {
            printf("%d ", (*mass)[i]);

        }
    } else {
        printf("Не корректные данные!\n");
        printf("\n");
        return;
    }
}

void insert(int **mass, int num, int index, int *size) {
    if (index < 1 || index > *size + 1) {
        printf("Некорректный индекс. Вставка невозможна.\n");
        return;
    }

    *mass = (int *)realloc(*mass, (*size + 1) * sizeof(int));
    
    for (int i = *size; i >= index - 1; i--) {
        (*mass)[i] = (*mass)[i - 1];
    }

    (*mass)[index] = num;
    (*size)++;

    printf("Обновленный массив:\n");
    for (int i = 0; i < *size + 1; i++) {
        printf("%d ", (*mass)[i]);
    }
    printf("\n");
}

void append(int **mass, int num, int *size) {

    *mass = (int*)realloc(*mass, (*size + 1) * sizeof(int));

    (*mass)[*size] = num;

    (*size)++;
    printf("Обновленный массив:\n");
    for (int i = 0; i < *size; i++) {
        printf("%d ", (*mass)[i]);
    }
    printf("\n");
}

void del(int **mass, int *size, int index) {
    if (index < 1 || index > *size) {
        printf("Некорректный индекс. Удаление невозможно.\n");
        return;
    }

    for (int i = index - 1; i < *size - 1; i++) {
        (*mass)[i] = (*mass)[i + 1];
    }

    *mass = (int *)realloc(*mass, (*size - 1) * sizeof(int));
    (*size)--;

    printf("Обновленный массив:\n");
    for (int i = 0; i < *size; i++) {
        printf("%d ", (*mass)[i]);
    }
    printf("\n");
}
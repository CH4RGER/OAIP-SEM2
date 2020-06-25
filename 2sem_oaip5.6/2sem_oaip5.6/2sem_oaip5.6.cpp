#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <locale.h>
#include <ctype.h>
#include <Windows.h>
#include <iostream>
using namespace std;

struct Stack {
    int info;
    Stack* next;
};

int Sum(Stack* list);
int amount_of_el(Stack* list);
void Sred(Stack* list);
Stack* CreateStack(int size);
Stack* AddStack(Stack* list, int N);
//void DeleteStack(Stack* list);
void StackView(Stack* list);
void printList(Stack* list);
void switchMaxAndMin(Stack* list);
void Sort_p(Stack** list);
Stack* Pop(Stack* list, int* out);
Stack* Push(Stack* list, int in);


void main() {
    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_CTYPE, "Russian");
    system("cls");
    int menu = 0;
    Stack* begin = NULL;

    system("cls");
    puts("\tМеню программы:");
    puts("1 – Создание стека из случайных чисел");
    puts("2 – просмотр стека");
    puts("3 – добавление элемента в стек");
    puts("4 – Индивидуальное задание");
    puts("5 - Сортировка перестановкой ");
    puts("6 – ВЫХОД ");
 
    while (menu != 6) {
        puts("\tВыберите пункт меню");
        puts("\tДля вызова меню нажмите '0'");
        scanf_s("%d", &menu);
        switch (menu) {
        case 1: {
            int size;
            puts("Создание стека");
            puts("Введите количество элементов стека");
            cin >> size;
            begin = CreateStack(size);
            puts("Созданный стек");
            StackView(begin);
            puts("\nСоздан новый список!\n");
            
            break;
        }
        case 2: {
            puts("Просмотр стека");
            StackView(begin);
            puts("\nВыполнен просмотр списка!\n");
            
            break;
        }
        case 3: {
            int N;
            puts("Добавление элемента в стек");
            puts("Введите количество элементов стека для добавления");
            cin >> N;
            begin = AddStack(begin, N);
            puts("\nСписок дополнен!\n");
            
            break;
        }
        case 4: {
             Sred(begin);
            
                puts("Поменять местами максимальный и минимальный элемент");
                switchMaxAndMin(begin);
                printList(begin);
                    
                
                break;

            
        }
        case 5: {
            int el = 100;
            begin = Push(begin, el);
            Sort_p(&begin);
            begin = Pop(begin, &el);
            printList(begin);
            break;
        }

        case 6: {
            exit(0);
        }
        case 0: {
            puts("\tМеню программы:");
            puts("1 – Создание стека из случайных чисел");
            puts("2 – просмотр стека");
            puts("3 – добавление элемента в стек");
            puts("4 – Создать список из случайных целых чисел и поменять местами элементы, содержащие максимальное и минимальное значения.");
            puts("5 - Сортировка перестановкой ");
            puts("6 – ВЫХОД ");
            break;
        }
        default: {
            puts("\tНеобходимо выбрать из предложенного списка!\n\tДля вызова списка нажмите любую клавишу.\n");
            
            break;
        }
        }
    }
    /*DeleteStack(begin);*/
}

Stack* CreateStack(int size) {
    Stack* first = NULL, * tmp = NULL;

    for (int i = 0; i < size; i++) {
        tmp = first;
        first = new Stack;
        first->next = tmp;
        first->info = rand() % 100;
    }

    return first;
}

Stack* AddStack(Stack* begin, int N) {
    Stack* tmp = begin;
    for (int i = 0; i < N; i++) {
        tmp = begin;
        begin = new Stack;
        begin->next = tmp;
        begin->info = rand() % 100;
        //printf_s("%d - %d\n", i + 1, begin->info);
        cout << begin->info << endl;
    }
    return begin;
}

void StackView(Stack* list) {
   /* int i = 1;*/
    if (list == NULL) {
        puts("Список пуст!");
        return;
    }
    while (list) {
        cout << list->info << endl;
        list = list->next;
       /* i++;*/
    }
}


int Sum(Stack* list) {

    int sum = 0;
    if (list == NULL) {
        puts("Список пуст!");
        return 0;
    }
    while (list) {
        sum += list->info;

        list = list->next;
    }


    return sum;
}
int amount_of_el(Stack* list) {
    int amount = 0;
    if (list == NULL) {
        puts("Список пуст!");
        return 0;
    }
    while (list) {
        amount ++;
        list = list->next;
    }
    return amount;
}

void Sred(Stack* list) {
    int count = 0;
    int sum = Sum(list);
    int amount = amount_of_el(list);
    while (list) {
        if (list->info >= sum / amount)
            count++;
        list = list->next;
    }
    cout << count<< endl;
}


//void DeleteStack(Stack* list) {
//    Stack* tmp;
//    while (list) {
//        tmp = list;
//        list = list->next;
//        delete tmp;
//    }
//}

void switchMaxAndMin(Stack* list)
{
    Stack* origin = list;
    int max = list->info;
    int min = list->info;

    //нахождение мах и мин
    while (list) {
        if (list->info > max) {
            max = list->info;
        }

        if (list->info < min) {
            min = list->info;
        }
        list = list->next;

    }
    printf("Минимальное значение элемента:%d\nМаксимальное значение элемента:%d\n", min, max);
    list = origin;
    //replacing max with min and min with max
    while (list) {
        if (list->info == max) {
            list->info = min;
        }
        else if (list->info == min) {
            list->info = max;
        }
        list = list->next;
    }
   
}

void printList(Stack* list)
{
    int i = 1;
    while (list) {
        printf("%d. %d\n", i, list->info);
        list = list->next;
        i++;
    }
}

void Sort_p(Stack** list) {

    Stack* t = NULL, * t1, * r;
    if ((*list)->next->next == NULL) return;
    do {
        for (t1 = *list; t1->next->next != t; t1 = t1->next)
            if (t1->next->info > t1->next->next->info) {
                r = t1->next->next;
                t1->next->next = r->next;
                r->next = t1->next;
                t1->next = r;
            }
        t = t1->next;
    } while ((*list)->next->next != t);
}

Stack* Push(Stack* list, int in) {
    Stack* t = new Stack; // Захватываем память для элемента
    t->info = in; // Формируем информационную часть
    t->next = list; // Формируем адресную часть
    return t;
}

Stack* Pop(Stack* list, int* out) {
    Stack* t = list; // Устанавливаем указатель t на вершину p
    *out = list->info;
    list = list->next; // Переставляем вершину p на следующий
    delete t; // Удаляем бывшую вершину t
    return list; // Возвращаем новую вершину p
}

#include <iostream>
#include <Windows.h>


//Поменять местами максимальный и минимальный эллемент

using namespace std;

struct queue {
    int info;
    queue* next, * prev;
}*head, * tail;

queue* push_head(queue* list, int x) {
    queue* t = new queue;
    if (head == NULL) {
        t->next = t->prev = NULL;
        t->info = x;
        head = tail = t;
    }
    else {
        t->prev = NULL;
        t->next = list;
        t->info = x;
        list->prev = t;
    }
    return t;
}

queue* push_tail(queue* list, int x) {
    queue* t = new queue;
    if (tail == NULL) {
        t->next = t->prev = NULL;
        t->info = x;
        head = tail = t;
    }
    else {
        t->next = NULL;
        t->prev = list;
        t->info = x;
        list->next = t;
       
    }
    return t;
}


queue* findmax(queue* list) {
    int max = fabs(list->info);
    while (list) {
        if (list->info > max) {
            max = list->info;
        }
        list = list->next;
    }
    return max;
}


void view_head(queue* list) {
    while (list != NULL) {
        cout << list->info << " ";
        list = list->next;
    }
    cout << endl;
}
void view_tail(queue* list) {
    while (list != NULL) {
        cout << list->info << " ";
        list = list->prev;
    }
    cout << endl;
}

void switchMaxAndMin(queue* list)
{
    queue* origin = list;
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
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_CTYPE, "Russian");
    int x;
    int menu = 0;
    while (true) {
        puts("Выберите пункт меню");
        puts("\tМеню программы:");
        puts("1 – Добавление элемента в начало очереди");
        puts("2 – Добавление элемента в конец очереди");
        puts("3 – Просмотр очереди сначала");
        puts("4 – Просмотр очереди с конца");
        puts("5 - Индивидуальное задание ");
        puts("6 – ВЫХОД ");
        scanf_s("%d", &menu);
        switch (menu) {
        case 1: {
            
            cout << "Введите число : ";
            cin >> x;
            head = push_head(head, x);
            break;
        }
        case 2: {
           
            cout << "Введите число : ";
            cin >> x;
            tail = push_tail(tail, x);
            break;
        }
        case 3: {
            
            puts("Просмотр очереди сначала");
            view_head(head);
            break;
        }
        case 4: {

            puts("Просмотр очереди с конца");
            view_tail(tail);
            break;

        }
        case 5: {

            puts("Поменять местами максимальный и минимальный элемент");
            switchMaxAndMin(head);
            view_head(head);
            break;
        }

        case 6: {

            exit(0);
        }
        
        default: {

            puts("\tНеобходимо выбрать из предложенного списка!\n\tДля вызова списка нажмите любую клавишу.\n");
            break;
        }
        }
    }
   
}
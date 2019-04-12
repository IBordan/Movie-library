#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#define N 60


typedef struct kin_info
{
        char name_film[N];
        char regis[N];
        int kol_prokata;
        int year;
        int prodol;
}kin_info; // структура данных.

typedef struct Node
{
        kin_info gi;
        struct Node *next;
}Node; // структура односвязного списка.
//Функции :
int get_number_of_elements(Node* head); // Количество записанных фильмов
int check_is_already_have(Node* head, char name_film[N]); //Проверка на существующие группы.
void vvod_informacii(Node* any, Node* head); //Ввод информации.
void vivod_vsei_informacii(Node* head); //Вывод всей информации.
void push(Node **head); // Запись информации в начало списка данных.
void pop(Node **head); // Удаление информации из начала списка данных.
void zagruzka_is_faila(Node **head); //Загрузка из файла.
void push_back(Node *head); // Запись информации в конец списка данных.
void insert(Node *head, unsigned n); // Добавление за опредиленным номером в списке.
void pop_back(Node *head); // Удаление информации из конца списка данных.
void deleteNth(Node *head, unsigned n); // Удаление элемента за опредиленным номером в списке.
void changeData(Node *head); // Изменения данных.
void enter_nazvanie(Node *any, Node *head); //Ввод названия фильма.
void enter_regis(Node *any); // Ввод режиссёра.
void enter_kol_prokata(Node *any); // Ввод кол-ва проката.
void enter_year_vupuska(Node *any); // Ввод года выпуска.
void enter_prodol_filma(Node *any); // Ввода продолжительсности фильма.
void pois_po_prodol_filma(Node *head); // Поиск по продолжительсности фильма.
void poist_po_regis(Node *head); // Поиск по режессеру.
void zagruzka_v_fail(Node *head); // Загрузка в файл.
void poisk_god(Node *head); // Поиск по году.
void sort_kol_prokata(Node *head); // Сортировка по количеству проката.
void swap_elementov(Node *first, Node *second); // Функция обмена элементов.

int main()
{
    Node *head = NULL;
    int number_of_Nodes;
    int kod;
    head = NULL;
    number_of_Nodes = 0;
    setlocale(LC_ALL, "Rus");
    system("mode con cols=150 lines=70");
    puts("\t\t|----------------------------------------|");
    puts("\t\t|            Курсовая работа             |");
    puts("\t\t|----------------------------------------|");
    puts("\t\t|        Cтудента группы АИ - 174        |");
    puts("\t\t|----------------------------------------|");
    puts("\t\t|           Игоря Бордана                |");
    puts("\t\t|----------------------------------------|");
    puts("\t\t|              3  Вариант                |");
    puts("\t\t|----------------------------------------|");
    char buffer[10];

    while(1){
        puts("\n\t\t\t      |Выбор действия:|\n");
        puts("1.Добавить новый фильм в базу данных.");
        puts("2.Удалить фильм из базы данных.");
        puts("3.Количество фильмов в базе данных.");
        puts("4.Изменение данных о фильме.");
        puts("5.Поиск фильма по заданному времени.");
        puts("6.Поиск фильма по режиссёру.");
        puts("7.Поиск фильма по году выпуска.");
        puts("8.Сортировка фильмов по количеству проката в кинотеатрах.");
        puts("9.Вывод всех фильмов на экран.");
        puts("10.Загрузить данные в файл.");
        puts("11.Получить данные из файла.");
        puts("12.Выход.\n");
        printf("|Введите номер действия| ");
        gets(buffer);

                            system("cls");
        printf("\n ");
        kod = atoi(buffer);
        switch(kod){
            case 1: {
                if(number_of_Nodes!=0){
                    puts("Выберите пожалуйста местоположения фильма в базе данных.");
                    puts("1.Сделать фильм первым в списке.");
                    puts("2.Сделать фильм последним в списке.");
                    puts("3.Выбрать самостоятельно номер в списке,для фильма.");
                    gets(buffer);
                    kod = atoi(buffer);
                    switch(kod){
                        case 1: {
                            push(&head);
                            number_of_Nodes++;

                            system("cls");
                        }break;
                        case 2:{
                             push_back(head);
                             number_of_Nodes++;

                        }break;
                        case 3: {
                            puts("Введите номер позиции:");
                            gets(buffer);
                            kod = atoi(buffer);
                            if(kod<=0){
                                puts("Номера начинаются с 1, пожалуйста, не вводите 0 и другие символы.");

                            system("cls");
                            }
                            else if(kod<2){
                                push(&head);
                                number_of_Nodes++;
                            }
                            else if(kod>number_of_Nodes){
                                push_back(head);
                                number_of_Nodes++;
                            }

                            else {
                                insert(head, kod);
                                number_of_Nodes++;
                            }
                        } break;
                        default: puts("Несуществующая команда.");

                            system("cls");
                    }
                }

                else{
                    push(&head);
                    number_of_Nodes++;
                }



} break; //Конец кода операции ввода
            case 2:{
                if(number_of_Nodes == 0)

                            puts("Список фильмов пуст, удалять нечего.");


                else{
                    if(number_of_Nodes==1) {
                        pop(&head);
                        number_of_Nodes--;
                    }
                    else{
                    puts("Выберите опцию для удаления:");
                    puts("1.Удалить первый фильм в списке.");
                    puts("2.Удалить последний фильм в списке.");
                    puts("3.Выбрать номер фильма в списке,для удаления.");
                    gets(buffer);
                    kod = atoi(buffer);
                    switch(kod){
                        case 1: pop(&head); break;
                        case 2: pop_back(head); break;
                        case 3: {

                            puts("Введите номер позиции, которую хотите удалить:");
                            gets(buffer);
                            kod = atoi(buffer);
                            if(kod<=0){
                                puts("Номера начинаются с 1, пожалуйста, не вводите 0 и другие символы.");
                            }

                            else if(kod>number_of_Nodes){
                                pop_back(head);
                                number_of_Nodes--;

                            }

                            else if(kod<2){
                                pop(&head);

                            }

                            else{
                                number_of_Nodes--;
                                deleteNth(head, kod);
                            }



                         } break;
                         default: puts("Невозможная команда");
                    }
                    }
                }




            }; break; //Конец операции удаления
            case 3: printf("Количество фильмов в базе данных = |%d|\n\n\n\n\n", get_number_of_elements(head));
            printf("Что бы продолжить нажмите любую клавишу");
            getch();
            system("cls");
            break;



            case 4: changeData(head); break;
            case 5: pois_po_prodol_filma(head); break;
            case 6: poist_po_regis(head); break;
            case 7: poisk_god(head); break;
            case 8: sort_kol_prokata(head); break;
            case 9: vivod_vsei_informacii(head); break;
            case 10: zagruzka_v_fail(head); break;
            case 11: {
                zagruzka_is_faila(&head);
                number_of_Nodes = get_number_of_elements(head);
            }break;
            case 12: return 0; break;
            default: printf("Невозможная команда.\n\n\n\n");
        }

    }

    return 0;
}

void vvod_informacii(Node* any, Node* head){


   enter_nazvanie(any, head);
 enter_regis(any);
 enter_kol_prokata(any);
 enter_year_vupuska(any);
 enter_prodol_filma(any);


}

void vivod_vsei_informacii(Node* head){
    kin_info tmp;
    puts("|-------------------------------------------------------------------------------------------------------------|");
    printf(" |№ |Название фильма|  Режиссёр     |  Количество проката в кинотеатрах|  Продолжительность фильма| Год выпуска|\n");
    puts(" |--|---------------|---------------|----------------------------------|--------------------------|------------|");

    int y=1;
    while(head!=NULL){
        tmp = head->gi;
        printf(" |%d.|%-12s   |%-12s   |%-15d                   |%-4d                      |%-4d        |\n",y,tmp.name_film,tmp.regis,tmp.kol_prokata,tmp.prodol,tmp.year);
        puts(" |--|---------------|---------------|----------------------------------|--------------------------|------------|");
        head= head->next;
        y++;
    }
 puts("Все данные выведены, нажмите любую клавишу,что бы продолжить.");
 getch();
 system("cls");
}

int get_number_of_elements(Node* head)// функция получения кол-ва записаных фильмов
{
    int i= 0;
    while(head!=NULL){
        i++;
        head = head->next;
    }


    return i;

}

int check_is_already_have(Node* head, char name_film[N])//проверка на существующие фильмы
{
    while(head!=NULL){
        if(strcmp(head->gi.name_film, name_film)==0){
            return 0;
        }

        head = head->next;
    }


    return 1;

}


void push(Node **head){ //// функция записи инфо в начало списка данных
    Node *tmp = (Node*) malloc(sizeof(Node));
    vvod_informacii(tmp, *head);
    tmp->next = (*head);
    (*head) = tmp;

}

void pop(Node **head)// функция удаления инфо из начала списка данных)
{
    Node* prev = NULL;
    if((*head) == NULL){
        puts("Пустая очередь, нечего удалять.");
        return;
    }
    prev = (*head);
    (*head) = (*head)->next;
    free(prev);
}

void push_back(Node *head) // функция записи инфо в конец списка данных
{

    Node *tmp = (Node*) malloc(sizeof(Node));
    vvod_informacii(tmp, head);

    while(head->next!=NULL){
        head = head->next;
    }
    head->next = tmp;



}


void pop_back(Node *head)//функция удаления инфо из конца списка данных
{

    Node* tmp = head->next;

    while(tmp->next!=NULL){
        head= head->next;
        tmp= tmp->next;
    }
    head->next = NULL;
    free(tmp);
}

void insert(Node *head, unsigned n){ // функция добавленния за опредиленным номером в списке
    unsigned i = 2;
    Node* tmp = NULL;
    tmp = (Node*) malloc(sizeof(Node));
    vvod_informacii(tmp, head);
    while(i<n){
        head = head->next;
        i++;
    }
    tmp->next = head->next;
    head->next = tmp;
}

void deleteNth(Node *head, unsigned n)// функция удаленние элемента за опредиленным номером в списке
{
    unsigned i=2;
    while(i<n){
        head=head->next;
        i++;
    }
    Node* deleteble = head->next;
    head->next = deleteble->next;
    free(deleteble);
}


void changeData(Node *head){ // функция изменения данных
    Node *any = head;
    char buffer[N];
    int kod;
    kin_info tmp;
    puts("|-------------------------------------------------------------------------------------------------------------|");
    printf(" |№ |Название фильма|  Режиссёр     |  Количество проката в кинотеатрах|  Продолжительность фильма| Год выпуска|\n");
    puts(" |--|---------------|---------------|----------------------------------|--------------------------|------------|");

    int y=1;
    while(head!=NULL){
        tmp = head->gi;
        printf(" |%d.|%-12s   |%-12s   |%-15d                   |%-4d                      |%-4d        |\n",y,tmp.name_film,tmp.regis,tmp.kol_prokata,tmp.prodol,tmp.year);
        puts(" |--|---------------|---------------|----------------------------------|--------------------------|------------|");
        head= head->next;
        y++;
    }

    puts("Введите название фильма, данные о котором вы хотите изменить");
    gets(buffer);
    while(any!=NULL&&strcmp(buffer, any->gi.name_film)){
        any=any->next;

    }
    if(any==NULL){
        puts("Такого фильма нет в базе данных,проверьте правильность написания названия фильма.");
        return;

        system("cls");
        return ;
    }
    while(1){
        puts("Вы меняете фильм c такими данными:");
        puts("|-------------------------------------------------------------------------------------------------------------|");
    printf(" |№ |Название фильма|  Режиссёр     |  Количество проката в кинотеатрах|  Продолжительность фильма| Год выпуска|\n");
    puts(" |--|---------------|---------------|----------------------------------|--------------------------|------------|");

        printf(" |%d.|%-12s   |%-12s   |%-15d                   |%-4d                      |%-4d        |\n",y,any->gi.name_film,any->gi.regis,any->gi.kol_prokata,any->gi.prodol,any->gi.year);
        puts(" |--|---------------|---------------|----------------------------------|--------------------------|------------|");
        puts("1.Чтобы изменить название фильма.");
        puts("2.Чтобы изменить режиссёра.");
        puts("3.Чтобы изменить количество проката.");
        puts("4.Чтобы изменить продолжительсноть фильма.");
        puts("5.Чтобы изменить год выпуска фильма.");
        puts("6.Чтобы прекратить изменения.");
        gets(buffer);
        kod = atoi(buffer);


    system("cls");
        printf("\n\n\n\n\n");
        switch(kod){
            case 1: enter_nazvanie(any, head); break;
            case 2: enter_regis(any); break;
            case 3: enter_kol_prokata(any); break;
            case 4: enter_prodol_filma(any); break;
            case 5: enter_year_vupuska(any); break;
            case 6: return; break;
            default: puts("Неверный код");
        }

    system("cls");
    }

}

void enter_nazvanie(Node *any, Node *head){
    char buffer[N];
    int k =1;
    printf("Введите название фильма: ");
    while(k==1){
        gets(buffer);
        if(strcmp(buffer, any->gi.name_film)==0)
            return;
        if(check_is_already_have(head, buffer)== 0)
            puts("Фильм с данным названием уже есть, введите фильм с другим названием.");
        else{
            k = 0;
            strcpy(any->gi.name_film, buffer);
        }
    }

}

void enter_regis(Node* any){
     printf("Введите фамилию режиссёра: ");
    gets(any->gi.regis);

}

void enter_prodol_filma(Node* any){
    char buffer[N];
    int k =1;
    int tmp;
    while(k==1){
            printf("Введите продолжительность фильма: (в минутах) ");
            gets(buffer);
            tmp = atoi(buffer);
            if(tmp<1)
                puts("Невозможные данные.(Продолжительность фильма не может быть меньше 1 минуты).Введите корректные данные");
            else{
                k=0;
                any->gi.prodol = tmp;
            }
    }
}

void enter_kol_prokata(Node* any){
    char buffer[N];
    int k =1;
    int tmp;
    while(k==1){
            printf("Введите количество проката : ");
            gets(buffer);
            tmp = atoi(buffer);
            if((tmp<1) || (tmp>999999999999999))
                puts("\n Вы ввели неверные данные,попробуйте еще раз."
                     "\n Скорее всего Вы ввели не цифры (а буквы например), или же вышли за рамки допустимого проката."
                     "\n Минимальное количество проката 1 (Какой - бы не был плохой фильм, он как минимум 1 раз выходит в прокат),максимальное кол-во 999999999999."
                     "\n+----------------------------------------------------------------------------------------------------------------------------------------+\n\n");
            else{
                k=0;
                any->gi.kol_prokata = tmp;
            }
    }

}


void enter_year_vupuska(Node* any){
    char buffer[N];
    int k =1;
    int tmp;
    while(k==1){
            printf( "Введите год выпуска фильма: ");
            gets(buffer);
            tmp = atoi(buffer);
            if((tmp<1850) || (tmp>2100))
                puts("\n\n\t\t\t\t Вы ввели неверные данные,попробуйте еще раз."
                     "\n\t\t\t\t Скорее всего Вы ввели не цифры (а буквы например), или же вышли за рамки допустимого года."
                     "\n\t\t\t\t Минимальный год 1850 (создание 1-го фильма),максимальный 2100."
                     "\n\t\t\t\t+-----------------------------------------------------------------------------+\n\n");


            else{
                k=0;
                any->gi.year = tmp;
            }
    }

}


void pois_po_prodol_filma(Node *head){
    int doo;
    int y;
    char boffer[10];
    puts("Введите промежуток фильма, который вам нужен");
    printf("До скольки минут длится интересующий Вас фильм: ");
    gets(boffer);
    doo = atoi(boffer);
    printf(" |№ |Название фильма|Режиссёр       |Количество проката в кинотеатрах  |Продолжительность фильма  |Год выпуска |\n");
    while(head!=NULL){
            if(head->gi.prodol<=doo)
                printf(" |%d.|%-12s   |%-12s   |%-15d                   |%-4d                      |%-4d        |\n",y,head->gi.name_film,head->gi.regis,head->gi.kol_prokata,head->gi.prodol,head->gi.year);
            head=head->next;
            y++;
    }

 printf("Что бы продолжить нажмите любую клавишу");
 getch();
 system("cls");
    printf("\n\n\n\n\n\n\n\n\n");
}



void poist_po_regis(Node *head){

    char tmp[N];
    int y;
    printf("Введите фамилию интересующего вас режессера: ");
    gets(tmp);
     puts("|-------------------------------------------------------------------------------------------------------------|");
    printf(" |№ |Название фильма|  Режиссёр     |  Количество проката в кинотеатрах|  Продолжительность фильма| Год выпуска|\n");
    puts(" |--|---------------|---------------|----------------------------------|--------------------------|------------|");

    while(head!=NULL){
            if(strcmp(tmp, head->gi.regis)==0)
                printf(" |%d.|%-12s   |%-12s   |%-15d                   |%-4d                      |%-4d        |\n",y,head->gi.name_film,head->gi.regis,head->gi.kol_prokata,head->gi.prodol,head->gi.year);
            head=head->next;
            y++;
    }

 printf("Что бы продолжить нажмите любую клавишу");
 getch();
 system("cls");

    printf("\n\n\n\n\n\n\n\n\n");
}

void zagruzka_v_fail(Node *head){
    FILE* fp = fopen("bd.bin", "wb");
    kin_info tmp;

    if(fp==NULL){
        puts("Неудалось открыть файл");
        return;
    }

    while(head!=NULL){
        tmp = head->gi;
        fwrite(&tmp, sizeof(kin_info), 1, fp);
        head = head->next;
    }
    puts("Данные загруженны.");
     printf("Что бы продолжить нажмите любую клавишу");
 getch();
 system("cls");
    fclose(fp);
    return;
}

void zagruzka_is_faila(Node **head){
    char buff[10];
    int y;
    FILE* fp = fopen("bd.bin", "rb");
    Node* tmp;
    Node* tmp1;
    kin_info tmp_info;
   while(fread(&tmp_info, sizeof(kin_info), 1, fp)){
        tmp = (Node*) malloc(sizeof(Node));
        tmp->gi = tmp_info;
        if(check_is_already_have(*head, tmp->gi.name_film) == 0){
            tmp1 = (*head);
            puts("Из файла вводится фильм с уже существующим названием:");
            printf(" |№ |Название фильма|  Режиссёр     |  Количество проката в кинотеатрах|  Продолжительность фильма| Год выпуска|\n");
            while(strcmp(tmp1->gi.name_film, tmp->gi.name_film)!=0){
                tmp1 = tmp1->next;
            }
            puts(" |--|---------------|---------------|----------------------------------|--------------------------|------------|\n");
            puts("В программе:");
            printf(" |%d.|%-12s   |%-12s   |%-15d                   |%-4d                      |%-4d        |\n",y,tmp1->gi.name_film,tmp1->gi.regis,tmp1->gi.kol_prokata,tmp1->gi.prodol,tmp1->gi.year);
            puts(" |--|---------------|---------------|----------------------------------|--------------------------|------------|\n");
            puts("В файле:");
            printf(" |%d.|%-12s   |%-12s   |%-15d                   |%-4d                      |%-4d        |\n",y,tmp->gi.name_film,tmp->gi.regis,tmp->gi.kol_prokata,tmp->gi.prodol,tmp->gi.year);
            puts(" |--|---------------|---------------|----------------------------------|--------------------------|------------|");
            puts("Если хотите заменить, введите 1, если хотите оставить введённый в файл элемент, введите другой символ");
            gets(buff);
            if(atoi(buff)==1){
                swap_elementov(tmp, tmp1);
             }
            free(tmp);
            y++;

        }
        else{
            tmp->next = (*head);
            (*head) = tmp;

        }

    }
    puts("Данные были успешно выгружены из файла!");
    puts("Что бы продолжить нажмите любую клавишу.");
    getch();
    system("cls");
    fclose(fp);
}

void swap_elementov(Node *first, Node *second){
    kin_info tmp;
    tmp = first->gi;
    first->gi = second->gi;
    second->gi = tmp;
    }

void sort_kol_prokata(Node *head){
    Node* tmp_ptr;

    while(head!=NULL){
        tmp_ptr = head->next;
        while(tmp_ptr!=NULL){
            if(head->gi.kol_prokata<tmp_ptr->gi.kol_prokata)
                swap_elementov(head, tmp_ptr);
            tmp_ptr = tmp_ptr->next;
        }

        head = head->next;
    }

    puts("Сортировка закончена.");
    puts("Что бы увидеть результат нажмите цифру '9'");
}


void poisk_god(Node *head){
    int ot;
    int doo;
    int y;
    char boffer[10];
    puts("Введите промежуток лет который вам нужен для поиска определенного фильма.");
    printf("От: ");
    gets(boffer);
    ot = atoi(boffer);
    printf("До: ");
    gets(boffer);
    doo = atoi(boffer);
    printf(" |№ |Название фильма|  Режиссёр     |  Количество проката в кинотеатрах|  Продолжительность фильма| Год выпуска|\n");
    while(head!=NULL){
            if(head->gi.year>=ot&&head->gi.year<=doo)
                printf(" |%d.|%-12s   |%-12s   |%-15d                   |%-4d                      |%-4d        |\n",y,head->gi.name_film,head->gi.regis,head->gi.kol_prokata,head->gi.prodol,head->gi.year);
            head=head->next;
            y++;
    }
printf("Что бы продолжить нажмите любую клавишу");
 getch();
 system("cls");
    printf("\n\n\n\n\n\n\n\n\n");
}

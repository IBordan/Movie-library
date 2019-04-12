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
}kin_info; // ��������� ������.

typedef struct Node
{
        kin_info gi;
        struct Node *next;
}Node; // ��������� ������������ ������.
//������� :
int get_number_of_elements(Node* head); // ���������� ���������� �������
int check_is_already_have(Node* head, char name_film[N]); //�������� �� ������������ ������.
void vvod_informacii(Node* any, Node* head); //���� ����������.
void vivod_vsei_informacii(Node* head); //����� ���� ����������.
void push(Node **head); // ������ ���������� � ������ ������ ������.
void pop(Node **head); // �������� ���������� �� ������ ������ ������.
void zagruzka_is_faila(Node **head); //�������� �� �����.
void push_back(Node *head); // ������ ���������� � ����� ������ ������.
void insert(Node *head, unsigned n); // ���������� �� ������������ ������� � ������.
void pop_back(Node *head); // �������� ���������� �� ����� ������ ������.
void deleteNth(Node *head, unsigned n); // �������� �������� �� ������������ ������� � ������.
void changeData(Node *head); // ��������� ������.
void enter_nazvanie(Node *any, Node *head); //���� �������� ������.
void enter_regis(Node *any); // ���� ��������.
void enter_kol_prokata(Node *any); // ���� ���-�� �������.
void enter_year_vupuska(Node *any); // ���� ���� �������.
void enter_prodol_filma(Node *any); // ����� ������������������ ������.
void pois_po_prodol_filma(Node *head); // ����� �� ������������������ ������.
void poist_po_regis(Node *head); // ����� �� ���������.
void zagruzka_v_fail(Node *head); // �������� � ����.
void poisk_god(Node *head); // ����� �� ����.
void sort_kol_prokata(Node *head); // ���������� �� ���������� �������.
void swap_elementov(Node *first, Node *second); // ������� ������ ���������.

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
    puts("\t\t|            �������� ������             |");
    puts("\t\t|----------------------------------------|");
    puts("\t\t|        C������� ������ �� - 174        |");
    puts("\t\t|----------------------------------------|");
    puts("\t\t|           ����� �������                |");
    puts("\t\t|----------------------------------------|");
    puts("\t\t|              3  �������                |");
    puts("\t\t|----------------------------------------|");
    char buffer[10];

    while(1){
        puts("\n\t\t\t      |����� ��������:|\n");
        puts("1.�������� ����� ����� � ���� ������.");
        puts("2.������� ����� �� ���� ������.");
        puts("3.���������� ������� � ���� ������.");
        puts("4.��������� ������ � ������.");
        puts("5.����� ������ �� ��������� �������.");
        puts("6.����� ������ �� ��������.");
        puts("7.����� ������ �� ���� �������.");
        puts("8.���������� ������� �� ���������� ������� � �����������.");
        puts("9.����� ���� ������� �� �����.");
        puts("10.��������� ������ � ����.");
        puts("11.�������� ������ �� �����.");
        puts("12.�����.\n");
        printf("|������� ����� ��������| ");
        gets(buffer);

                            system("cls");
        printf("\n ");
        kod = atoi(buffer);
        switch(kod){
            case 1: {
                if(number_of_Nodes!=0){
                    puts("�������� ���������� �������������� ������ � ���� ������.");
                    puts("1.������� ����� ������ � ������.");
                    puts("2.������� ����� ��������� � ������.");
                    puts("3.������� �������������� ����� � ������,��� ������.");
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
                            puts("������� ����� �������:");
                            gets(buffer);
                            kod = atoi(buffer);
                            if(kod<=0){
                                puts("������ ���������� � 1, ����������, �� ������� 0 � ������ �������.");

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
                        default: puts("�������������� �������.");

                            system("cls");
                    }
                }

                else{
                    push(&head);
                    number_of_Nodes++;
                }



} break; //����� ���� �������� �����
            case 2:{
                if(number_of_Nodes == 0)

                            puts("������ ������� ����, ������� ������.");


                else{
                    if(number_of_Nodes==1) {
                        pop(&head);
                        number_of_Nodes--;
                    }
                    else{
                    puts("�������� ����� ��� ��������:");
                    puts("1.������� ������ ����� � ������.");
                    puts("2.������� ��������� ����� � ������.");
                    puts("3.������� ����� ������ � ������,��� ��������.");
                    gets(buffer);
                    kod = atoi(buffer);
                    switch(kod){
                        case 1: pop(&head); break;
                        case 2: pop_back(head); break;
                        case 3: {

                            puts("������� ����� �������, ������� ������ �������:");
                            gets(buffer);
                            kod = atoi(buffer);
                            if(kod<=0){
                                puts("������ ���������� � 1, ����������, �� ������� 0 � ������ �������.");
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
                         default: puts("����������� �������");
                    }
                    }
                }




            }; break; //����� �������� ��������
            case 3: printf("���������� ������� � ���� ������ = |%d|\n\n\n\n\n", get_number_of_elements(head));
            printf("��� �� ���������� ������� ����� �������");
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
            default: printf("����������� �������.\n\n\n\n");
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
    printf(" |� |�������� ������|  �������     |  ���������� ������� � �����������|  ����������������� ������| ��� �������|\n");
    puts(" |--|---------------|---------------|----------------------------------|--------------------------|------------|");

    int y=1;
    while(head!=NULL){
        tmp = head->gi;
        printf(" |%d.|%-12s   |%-12s   |%-15d                   |%-4d                      |%-4d        |\n",y,tmp.name_film,tmp.regis,tmp.kol_prokata,tmp.prodol,tmp.year);
        puts(" |--|---------------|---------------|----------------------------------|--------------------------|------------|");
        head= head->next;
        y++;
    }
 puts("��� ������ ��������, ������� ����� �������,��� �� ����������.");
 getch();
 system("cls");
}

int get_number_of_elements(Node* head)// ������� ��������� ���-�� ��������� �������
{
    int i= 0;
    while(head!=NULL){
        i++;
        head = head->next;
    }


    return i;

}

int check_is_already_have(Node* head, char name_film[N])//�������� �� ������������ ������
{
    while(head!=NULL){
        if(strcmp(head->gi.name_film, name_film)==0){
            return 0;
        }

        head = head->next;
    }


    return 1;

}


void push(Node **head){ //// ������� ������ ���� � ������ ������ ������
    Node *tmp = (Node*) malloc(sizeof(Node));
    vvod_informacii(tmp, *head);
    tmp->next = (*head);
    (*head) = tmp;

}

void pop(Node **head)// ������� �������� ���� �� ������ ������ ������)
{
    Node* prev = NULL;
    if((*head) == NULL){
        puts("������ �������, ������ �������.");
        return;
    }
    prev = (*head);
    (*head) = (*head)->next;
    free(prev);
}

void push_back(Node *head) // ������� ������ ���� � ����� ������ ������
{

    Node *tmp = (Node*) malloc(sizeof(Node));
    vvod_informacii(tmp, head);

    while(head->next!=NULL){
        head = head->next;
    }
    head->next = tmp;



}


void pop_back(Node *head)//������� �������� ���� �� ����� ������ ������
{

    Node* tmp = head->next;

    while(tmp->next!=NULL){
        head= head->next;
        tmp= tmp->next;
    }
    head->next = NULL;
    free(tmp);
}

void insert(Node *head, unsigned n){ // ������� ����������� �� ������������ ������� � ������
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

void deleteNth(Node *head, unsigned n)// ������� ��������� �������� �� ������������ ������� � ������
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


void changeData(Node *head){ // ������� ��������� ������
    Node *any = head;
    char buffer[N];
    int kod;
    kin_info tmp;
    puts("|-------------------------------------------------------------------------------------------------------------|");
    printf(" |� |�������� ������|  �������     |  ���������� ������� � �����������|  ����������������� ������| ��� �������|\n");
    puts(" |--|---------------|---------------|----------------------------------|--------------------------|------------|");

    int y=1;
    while(head!=NULL){
        tmp = head->gi;
        printf(" |%d.|%-12s   |%-12s   |%-15d                   |%-4d                      |%-4d        |\n",y,tmp.name_film,tmp.regis,tmp.kol_prokata,tmp.prodol,tmp.year);
        puts(" |--|---------------|---------------|----------------------------------|--------------------------|------------|");
        head= head->next;
        y++;
    }

    puts("������� �������� ������, ������ � ������� �� ������ ��������");
    gets(buffer);
    while(any!=NULL&&strcmp(buffer, any->gi.name_film)){
        any=any->next;

    }
    if(any==NULL){
        puts("������ ������ ��� � ���� ������,��������� ������������ ��������� �������� ������.");
        return;

        system("cls");
        return ;
    }
    while(1){
        puts("�� ������� ����� c ������ �������:");
        puts("|-------------------------------------------------------------------------------------------------------------|");
    printf(" |� |�������� ������|  �������     |  ���������� ������� � �����������|  ����������������� ������| ��� �������|\n");
    puts(" |--|---------------|---------------|----------------------------------|--------------------------|------------|");

        printf(" |%d.|%-12s   |%-12s   |%-15d                   |%-4d                      |%-4d        |\n",y,any->gi.name_film,any->gi.regis,any->gi.kol_prokata,any->gi.prodol,any->gi.year);
        puts(" |--|---------------|---------------|----------------------------------|--------------------------|------------|");
        puts("1.����� �������� �������� ������.");
        puts("2.����� �������� ��������.");
        puts("3.����� �������� ���������� �������.");
        puts("4.����� �������� ����������������� ������.");
        puts("5.����� �������� ��� ������� ������.");
        puts("6.����� ���������� ���������.");
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
            default: puts("�������� ���");
        }

    system("cls");
    }

}

void enter_nazvanie(Node *any, Node *head){
    char buffer[N];
    int k =1;
    printf("������� �������� ������: ");
    while(k==1){
        gets(buffer);
        if(strcmp(buffer, any->gi.name_film)==0)
            return;
        if(check_is_already_have(head, buffer)== 0)
            puts("����� � ������ ��������� ��� ����, ������� ����� � ������ ���������.");
        else{
            k = 0;
            strcpy(any->gi.name_film, buffer);
        }
    }

}

void enter_regis(Node* any){
     printf("������� ������� ��������: ");
    gets(any->gi.regis);

}

void enter_prodol_filma(Node* any){
    char buffer[N];
    int k =1;
    int tmp;
    while(k==1){
            printf("������� ����������������� ������: (� �������) ");
            gets(buffer);
            tmp = atoi(buffer);
            if(tmp<1)
                puts("����������� ������.(����������������� ������ �� ����� ���� ������ 1 ������).������� ���������� ������");
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
            printf("������� ���������� ������� : ");
            gets(buffer);
            tmp = atoi(buffer);
            if((tmp<1) || (tmp>999999999999999))
                puts("\n �� ����� �������� ������,���������� ��� ���."
                     "\n ������ ����� �� ����� �� ����� (� ����� ��������), ��� �� ����� �� ����� ����������� �������."
                     "\n ����������� ���������� ������� 1 (����� - �� �� ��� ������ �����, �� ��� ������� 1 ��� ������� � ������),������������ ���-�� 999999999999."
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
            printf( "������� ��� ������� ������: ");
            gets(buffer);
            tmp = atoi(buffer);
            if((tmp<1850) || (tmp>2100))
                puts("\n\n\t\t\t\t �� ����� �������� ������,���������� ��� ���."
                     "\n\t\t\t\t ������ ����� �� ����� �� ����� (� ����� ��������), ��� �� ����� �� ����� ����������� ����."
                     "\n\t\t\t\t ����������� ��� 1850 (�������� 1-�� ������),������������ 2100."
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
    puts("������� ���������� ������, ������� ��� �����");
    printf("�� ������� ����� ������ ������������ ��� �����: ");
    gets(boffer);
    doo = atoi(boffer);
    printf(" |� |�������� ������|�������       |���������� ������� � �����������  |����������������� ������  |��� ������� |\n");
    while(head!=NULL){
            if(head->gi.prodol<=doo)
                printf(" |%d.|%-12s   |%-12s   |%-15d                   |%-4d                      |%-4d        |\n",y,head->gi.name_film,head->gi.regis,head->gi.kol_prokata,head->gi.prodol,head->gi.year);
            head=head->next;
            y++;
    }

 printf("��� �� ���������� ������� ����� �������");
 getch();
 system("cls");
    printf("\n\n\n\n\n\n\n\n\n");
}



void poist_po_regis(Node *head){

    char tmp[N];
    int y;
    printf("������� ������� ������������� ��� ���������: ");
    gets(tmp);
     puts("|-------------------------------------------------------------------------------------------------------------|");
    printf(" |� |�������� ������|  �������     |  ���������� ������� � �����������|  ����������������� ������| ��� �������|\n");
    puts(" |--|---------------|---------------|----------------------------------|--------------------------|------------|");

    while(head!=NULL){
            if(strcmp(tmp, head->gi.regis)==0)
                printf(" |%d.|%-12s   |%-12s   |%-15d                   |%-4d                      |%-4d        |\n",y,head->gi.name_film,head->gi.regis,head->gi.kol_prokata,head->gi.prodol,head->gi.year);
            head=head->next;
            y++;
    }

 printf("��� �� ���������� ������� ����� �������");
 getch();
 system("cls");

    printf("\n\n\n\n\n\n\n\n\n");
}

void zagruzka_v_fail(Node *head){
    FILE* fp = fopen("bd.bin", "wb");
    kin_info tmp;

    if(fp==NULL){
        puts("��������� ������� ����");
        return;
    }

    while(head!=NULL){
        tmp = head->gi;
        fwrite(&tmp, sizeof(kin_info), 1, fp);
        head = head->next;
    }
    puts("������ ����������.");
     printf("��� �� ���������� ������� ����� �������");
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
            puts("�� ����� �������� ����� � ��� ������������ ���������:");
            printf(" |� |�������� ������|  �������     |  ���������� ������� � �����������|  ����������������� ������| ��� �������|\n");
            while(strcmp(tmp1->gi.name_film, tmp->gi.name_film)!=0){
                tmp1 = tmp1->next;
            }
            puts(" |--|---------------|---------------|----------------------------------|--------------------------|------------|\n");
            puts("� ���������:");
            printf(" |%d.|%-12s   |%-12s   |%-15d                   |%-4d                      |%-4d        |\n",y,tmp1->gi.name_film,tmp1->gi.regis,tmp1->gi.kol_prokata,tmp1->gi.prodol,tmp1->gi.year);
            puts(" |--|---------------|---------------|----------------------------------|--------------------------|------------|\n");
            puts("� �����:");
            printf(" |%d.|%-12s   |%-12s   |%-15d                   |%-4d                      |%-4d        |\n",y,tmp->gi.name_film,tmp->gi.regis,tmp->gi.kol_prokata,tmp->gi.prodol,tmp->gi.year);
            puts(" |--|---------------|---------------|----------------------------------|--------------------------|------------|");
            puts("���� ������ ��������, ������� 1, ���� ������ �������� �������� � ���� �������, ������� ������ ������");
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
    puts("������ ���� ������� ��������� �� �����!");
    puts("��� �� ���������� ������� ����� �������.");
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

    puts("���������� ���������.");
    puts("��� �� ������� ��������� ������� ����� '9'");
}


void poisk_god(Node *head){
    int ot;
    int doo;
    int y;
    char boffer[10];
    puts("������� ���������� ��� ������� ��� ����� ��� ������ ������������� ������.");
    printf("��: ");
    gets(boffer);
    ot = atoi(boffer);
    printf("��: ");
    gets(boffer);
    doo = atoi(boffer);
    printf(" |� |�������� ������|  �������     |  ���������� ������� � �����������|  ����������������� ������| ��� �������|\n");
    while(head!=NULL){
            if(head->gi.year>=ot&&head->gi.year<=doo)
                printf(" |%d.|%-12s   |%-12s   |%-15d                   |%-4d                      |%-4d        |\n",y,head->gi.name_film,head->gi.regis,head->gi.kol_prokata,head->gi.prodol,head->gi.year);
            head=head->next;
            y++;
    }
printf("��� �� ���������� ������� ����� �������");
 getch();
 system("cls");
    printf("\n\n\n\n\n\n\n\n\n");
}

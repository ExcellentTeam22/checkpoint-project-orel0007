#include <termios.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


#define NAMES_SIZE 31
#define PHONE_NUMBERS_SIZE 15
#define TOTAL_CONTACTS 100
#define MIN(x, y) (((x) < (y)) ? (x) : (y))



struct contact{
    char fname[NAMES_SIZE];
    char lname[NAMES_SIZE];
    char telep[PHONE_NUMBERS_SIZE];
    char cellp[PHONE_NUMBERS_SIZE];
};


struct Node {
    struct contact _data;
    struct Node *_next_fname;
    struct Node *_next_lname;
    struct Node *_next_telep;
    struct Node *_next_cellp;
};

struct Node *head_fname = NULL;
struct Node *head_lname = NULL;
struct Node *head_telep = NULL;
struct Node *head_cellp = NULL;

int sort_num = 1;

struct contact A[TOTAL_CONTACTS];
void insert_sort_node(struct Node *new_node);
void getInput(char *dest, int max_size);
void show_results();
void clrscr(void);
void gotoxy(int x, int y);
void insert(void);
void delet(void);
void edit(void);
void search(void);
void searchf(void);
void searchl(void);
void searchp(void);
void searchc(void);
void list(void);
void list2(void);
void sort(void);
void sortf(void);
void sortl(void);
void sortp(void);
void sortc(void);
void help(void);
int last;
int size;


void getInput(char *dest, int max_size) {
    size_t len = 0, len_size = 0;
    char *input = NULL;
    len_size = getline(&input, &len, stdin);
    len_size = MIN(len_size, max_size);
    input[len_size - 1] = '\0';
    strncpy(dest, input, len_size);
    free(input);
}


void insert_sort_node(struct Node *new_node){
    struct Node *temp = head_fname;
    if(strcmp(temp->_data.fname, new_node->_data.fname) > 0){
        new_node->_next_fname = head_fname;
        head_fname = new_node;
    }
    else{
        while(temp->_next_fname != NULL && strcmp(temp->_next_fname->_data.fname, new_node->_data.fname) < 0){
            temp = temp->_next_fname;
        }
        new_node->_next_fname = temp->_next_fname;
        temp->_next_fname = new_node;
    }
    temp = head_lname;
    if(strcmp(temp->_data.lname, new_node->_data.lname) > 0){
        new_node->_next_fname = head_lname;
        head_lname = new_node;
    }
    else{
        while(temp->_next_lname != NULL && strcmp(temp->_next_lname->_data.lname, new_node->_data.lname) < 0){
            temp = temp->_next_lname;
        }
        new_node->_next_lname = temp->_next_lname;
        temp->_next_lname = new_node;
    }

    temp = head_cellp;
    if(strcmp(temp->_data.cellp, new_node->_data.cellp) > 0){
        new_node->_next_cellp = head_cellp;
        head_cellp = new_node;
    }
    else{
        while(temp->_next_cellp != NULL && strcmp(temp->_next_cellp->_data.cellp, new_node->_data.cellp) < 0){
            temp = temp->_next_cellp;
        }
        new_node->_next_cellp = temp->_next_cellp;
        temp->_next_cellp = new_node;
    }

    temp = head_telep;
    if(strcmp(temp->_data.telep, new_node->_data.telep) > 0){
        new_node->_next_telep = head_telep;
        head_telep = new_node;
    }
    else{
        while(temp->_next_telep != NULL && strcmp(temp->_next_telep->_data.telep, new_node->_data.telep) < 0){
            temp = temp->_next_telep;
        }
        new_node->_next_telep = temp->_next_telep;
        temp->_next_telep = new_node;
    }
    printf("end insert");
}


int main()
{
    int count=1;
    char n;
    while(count) {
        clrscr();
        printf("\n|Phone Book12<::>Home|\n");
        printf("--------------------------------------------------------------------------------\n");
        printf("Welcome to PHONE BOOK2022!\nYou have inserted ( %d ) contacts.\n\n",last);
        printf("\t[1] |--> Insert\n");
        printf("\t[2] |--> Delete\n");
        printf("\t[3] |--> Edit\n");
        printf("\t[4] |--> Search\n");
        printf("\t[5] |--> Show All\n");
        printf("\t[6] |--> Sort\n");
        printf("\t[7] |--> Help\n");
        printf("\t[8] |--> Exit\n");
        printf("\n\tPlease Enter Your Choice (1-8): ");
        n = getc(stdin);
        getc(stdin);
        switch(n) {
            case '1':
                insert();
                break;
            case '2':
                delet();
                break;
            case '3':
                edit();
                break;
            case '4':
                search();
                break;
            case '5':
                list();
                break;
            case '6':
                sort();
                break;
            case '7':
                help();
                break;
            case '8':
                exit(1);
                break;
            default:
                printf("\nThere is no item with symbol \"%c\".Please enter a number between 1-8!\nPress any key to continue...",n);
                getc(stdin);
                getc(stdin);
                break;
        }//End of swicth
    }
    return 0;
}//End of main function!

void insert(void)
{
    char ans='y';
    char *string = NULL;
    size_t len=0;
    size_t len_size=0;
    clrscr();
    printf("\nPhone Book12<::>Insert Contacts");
    printf("\n--------------------------------------------------------------------------------");
    //string = (char *)malloc(31); Do not need this.
    while(ans=='y'){
        struct Node *newContactNode = malloc(sizeof(struct Node));
        newContactNode->_next_fname = NULL;
        newContactNode->_next_lname = NULL;
        newContactNode->_next_telep = NULL;
        newContactNode->_next_cellp = NULL;

        printf("\n\nData of Contact %2.2d{\n",last+1);
        printf("\n\t  1-F.Name: ");
        getInput(newContactNode->_data.fname, NAMES_SIZE);
        printf("\t  2-L.Name: ");
        getInput(newContactNode->_data.lname, NAMES_SIZE);

        printf("\t  3-Tele.P: ");
        getInput(newContactNode->_data.telep, PHONE_NUMBERS_SIZE);

        printf("\t  4-Cell.P: ");
        getInput(newContactNode->_data.cellp, PHONE_NUMBERS_SIZE);
        if (!head_fname) {
            head_fname = newContactNode;
            head_lname = newContactNode;
            head_telep = newContactNode;
            head_cellp = newContactNode;
        }
        else
            insert_sort_node(newContactNode);
        printf("\n|-->Data Recorded!}");
        printf("\n\t\t\tNext Contact?(y/n) Answer:");
        ans = getc(stdin);
        getc(stdin);
        last++;
    }
    free(string); //my fix
    printf("\n\nYou have inserted ( %d ) contact!\nPress a key to return main page & continue program|-->",last);
    getc(stdin);
}

void delet(void)
{
    char dfname_string[NAMES_SIZE], dlname_string[NAMES_SIZE];// changed the size of dfname and dlname
    size_t len=0;
    size_t len_size=0;
    register int i,j,find=0;
    char ch;
    clrscr();
    printf("\nPhone Book12<::>Delete Contacts");
    printf("\n--------------------------------------------------------------------------------");
    printf ("\n::Enter data of the contact that you want delete it,please:");
    printf("\n\n  ::Enter first name: ");

    getInput(dfname_string,NAMES_SIZE);
    printf("\n  ::Enter last name: ");
    getInput(dlname_string, NAMES_SIZE);

    struct Node *run = head_fname;
    struct Node *prev = head_fname;
    if(strcmp(run->_data.fname,dfname_string) == 0 && strcmp(run->_data.lname,dlname_string) == 0){
        head_fname = head_fname->_next_fname;
    }
    else{
        while (run != NULL) {
            if (strcmp(dfname_string, run->_data.fname) == 0 && strcmp(dlname_string, run->_data.lname) == 0) {
                printf("\nContact was found! Details:");
                printf("\n\t   F.Name:%s\n\t   L.name:%s\n\t   Tele.P:%s\n\t   Cell.P:%s\n\t   }",run->_data.fname,run->_data.lname,run->_data.telep,run->_data.cellp);
                printf("\n\nAre you sure you want to delete this contact?(y/n)");
                ch = getc(stdin);
                getc(stdin);
                if(ch == 'y'){
                    if (prev == head_fname)
                        head_fname = NULL;
                    else
                        prev->_next_fname = run->_next_fname;
                    find = 1;
                    break;
                }
            }
            prev = run;
            run = run->_next_fname;
        }
    }
    run = head_lname;
    prev = head_lname;
    if(strcmp(run->_data.fname,dfname_string) == 0 && strcmp(run->_data.lname,dlname_string) == 0){
        head_lname = head_lname->_next_lname;
    }
    else{
        while (run != NULL) {
            if (strcmp(dfname_string, run->_data.fname) == 0 && strcmp(dlname_string, run->_data.lname) == 0) {
                printf("\nContact was found! Details:");
                printf("\n\t   F.Name:%s\n\t   L.name:%s\n\t   Tele.P:%s\n\t   Cell.P:%s\n\t   }",
                       run->_data.fname,run->_data.lname,run->_data.telep,run->_data.cellp);
                printf("\n\nAre you sure you want to delete this contact?(y/n)");
                if (prev == head_lname) {
                    head_lname = NULL;
                } else {
                    prev->_next_lname = run->_next_lname;
                }
                find = 1;
                break;
            }
            prev = run;
            run = run->_next_lname;
        }
    }

    run = head_telep;
    prev = head_telep;
    if(strcmp(run->_data.fname,dfname_string) == 0 && strcmp(run->_data.lname,dlname_string) == 0){
        head_telep = head_telep->_next_telep;
    }
    else{
        while (run != NULL) {
            if (strcmp(dfname_string, run->_data.fname) == 0 && strcmp(dlname_string, run->_data.lname) == 0) {
                printf("\nContact was found! Details:");
                printf("\n\t   F.Name:%s\n\t   L.name:%s\n\t   Tele.P:%s\n\t   Cell.P:%s\n\t"
                       "   }",run->_data.fname,run->_data.lname,run->_data.telep,run->_data.cellp);
                printf("\n\nAre you sure you want to delete this contact?(y/n)");
                if (prev == head_telep) {
                    head_telep = NULL;
                } else {
                    prev->_next_telep = run->_next_telep;
                    //free(run);
                }
                find = 1;
                break;
            }
            prev = run;
            run = run->_next_telep;
        }
    }

    run = head_cellp;
    prev = head_cellp;
    if(strcmp(run->_data.fname,dfname_string) == 0 && strcmp(run->_data.lname,dlname_string) == 0){
        head_cellp = head_cellp->_next_cellp;
    }
    else{
        while (run != NULL) {
            if (strcmp(dfname_string, run->_data.fname) == 0 && strcmp(dlname_string, run->_data.lname) == 0) {
                printf("\nContact was found! Details:");
                printf("\n\t   F.Name:%s\n\t   L.name:%s\n\t   Tele.P:%s\n\t   Cell.P:%s\n\t   }"
                       ,run->_data.fname,run->_data.lname,run->_data.telep,run->_data.cellp);
                printf("\n\nAre you sure you want to delete this contact?(y/n)");
                if (prev == head_cellp) {
                    head_cellp = NULL;
                } else {
                    prev->_next_cellp = run->_next_cellp;
                    //free(run);
                }
                find = 1;
                break;
            }
            prev = run;
            run = run->_next_cellp;
        }
    }
    if (find==0)
        printf("\t\t\n<<This contact does not exist in this list or program can not delete it.>>");
    else
        printf("\t\t\n<<Target contact was successfully deleted from list!>>");
    printf("\n\n\nPress a key to return main page & continue program|-->");
    getc(stdin);
}

void edit()
{
    char input[31];
    char dfname[NAMES_SIZE], dlname[NAMES_SIZE];
    size_t len=0;
    size_t len_size=0;
    register int i,j,find=0;
    char ch;
    clrscr();
    printf("\nPhone Book12<::>Edit Contacts");
    printf("\n--------------------------------------------------------------------------------");
    printf ("\n::Enter data of the contact that you want edit it,please:");

    printf("\n\n  ::Enter first name: ");
    getInput(dfname, NAMES_SIZE);
    printf("\n  ::Enter last name: ");
    getInput(dlname, NAMES_SIZE);

    for (i=0; i < last; i++) {
        if (strcmp (dfname, A[i].fname) == 0 && strcmp (dlname, A[i].lname) == 0 ) {
            printf("\nContact found! Details:");
            printf("\n\nCantact %2.2d{",i+1);
            printf("\n\t   F.Name:%s\n\t   L.name:%s\n\t   Tele.P:%s\n\t   Cell.P:%s\n\t   }",A[i].fname,A[i].lname,A[i].telep,A[i].cellp);
            printf("\n\nDo you want edit it?(y/n) ");
            ch = getc(stdin);
            getc(stdin);
            if(ch=='y'){
                printf("\n::Enter NEW data for this contact...");
                printf("\n >|Enter new first name: ");
                getInput(A[i].fname, NAMES_SIZE);
                printf(" >|Enter new last name: ");
                getInput(A[i].lname, NAMES_SIZE);
                printf(" >|Enter new telephone number: ");
                getInput(A[i].telep, NAMES_SIZE);
                printf(" >|Enter new cellphone number: ");
                getInput(A[i].cellp, NAMES_SIZE);

                find=1;
                break;
            }
        }
    }
    if (find==0)
        printf("\t\t\n<<This contact does not exist or you chose not to Edit it.>>");
    else
        printf("\t\t\n<<Target contact was successfully updated!>>");
    printf("\n\n\n   ::Press a key to return main page & continue program|-->");
    getc(stdin);
}

void search(void)
{
    char ch;
    clrscr();
    printf("\nPhone Book12<::>$earch Contacts");
    printf("\n--------------------------------------------------------------------------------");
    printf("\nChoose search type,please:\n\n");
    printf("\t[1] |--> Search by first name\n");
    printf("\t[2] |--> Search by last name\n");
    printf("\t[3] |--> Search by phone number\n");
    printf("\t[4] |--> Search by cellphone number\n");
    printf("\t[5] |--> Main Menu\n");
    printf("\n\t::Enter a number (1-5): ");
    ch = getc(stdin);
    getc(stdin);
    printf("\n--------------------------------------------------------------------------------");
    switch(ch) {
        case '1':
            searchf();
            break;
        case '2':
            searchl();
            break;
        case '3':
            searchp();
            break;
        case '4':
            searchc();
            break;
        case '5':
        default:
            return;
    }
}

void searchf(void)
{
    char fname[NAMES_SIZE];
    register int i,find=0;
    size_t len=0, len_size=0;
    printf("Enter a first name to search:");
    len_size = getline(&fname,&len,stdin);
    getInput(fname, NAMES_SIZE);
    printf("\n::search %s:", fname);
    struct Node *temp = head_fname;
    while(temp!= NULL){
        printf("\n::compare to  %s:", temp->_data.fname);
        if (strcmp(fname, temp->_data.fname) == 0){
            find = 1;
            break;
        }
        temp = temp->_next_fname;
    }
    if(find==0)
        printf("\t\n<<Not Find!There is no contact with this name in phone book.>>");
    else {
        printf("\t\n<<Target contact found! Details:>>");
        printf("\n\nCantact %2.2d{",i+1);
        printf("\n\t   F.Name:%s\n\t   L.name:%s\n\t   Tele.P:%s\n\t   Cell.P:%s\n\t   }",A[i].fname,A[i].lname,A[i].telep,A[i].cellp);
    }
    printf("\nPress a key to search another contact.");
    getc(stdin);
    search();
}

void searchl(void)
{
    char *lname[NAMES_SIZE];
    register int i,find=0;
    size_t len=0;
    size_t len_size=0;
    printf("\n::Enter a last name to search:");
    getInput(lname,NAMES_SIZE);
    struct Node *temp = head_lname;
    while(temp!= NULL){
        printf("\n::compare to  %s:", temp->_data.lname);
        if (strcmp(lname, temp->_data.lname) == 0){
            find = 1;
            break;
        }
        temp = temp->_next_lname;
    }
    if(find==0)
        printf("\t\n<<Not Find!There is not contact with tish name in phone book.>>");
    else {
        printf("\t\n<<Target contact found! Details:>>");
        printf("\n\nCantact %2.2d{",i+1);
        printf("\n\t   F.Name:%s\n\t   L.name:%s\n\t   Tele.P:%s\n\t   Cell.P:%s\n\t   }",A[i].fname,A[i].lname,A[i].telep,A[i].cellp);
    }
    printf("\nPress a key to search another contact.");
    getc(stdin);
    search();
}

void searchp(void)
{

    char *phone = NULL;
    int i,find=0;
    char telep[PHONE_NUMBERS_SIZE];
    size_t len=0;
    size_t len_size=0;
    printf("\n::Enter a phone number to search:");
    getInput(telep,NAMES_SIZE);
    struct Node *temp = head_telep;
    while(temp!= NULL){
        printf("\n::compare to  %s:", temp->_data.telep);
        if (strcmp(telep, temp->_data.telep) == 0){
            find = 1;
            break;
        }
        temp = temp->_next_telep;
    }
    if(find==0)
        printf("\t\n<<Not Found!There is not contact with tish phone number  in phone book.>>");
    else{
        printf("\t\n<<Target contact found! Details:>>");
        printf("\n\nCantact %2.2d{",i+1);
        printf("\n\t   F.Name:%s\n\t   L.name:%s\n\t   Tele.P:%s\n\t   Cell.P:%s\n\t   }",A[i].fname,A[i].lname,A[i].telep,A[i].cellp);
    }
    printf("\nPress a key to search another contact.");
    getc(stdin);
    search();
}

void searchc(void)
{
    char *phone = NULL;
    char cell[PHONE_NUMBERS_SIZE];
    int i,find=0;
    size_t len=0;
    size_t len_size=0;
    printf("\n::Enter a cellphone number to search:");
    getInput(cell,NAMES_SIZE);
    struct Node *temp = head_telep;
    while(temp!= NULL){
        printf("\n::compare to  %s:", temp->_data.cellp);
        if (strcmp(cell, temp->_data.cellp) == 0){
            find = 1;
            break;
        }
        temp = temp->_next_cellp;
    }
    if(find==0)
        printf("\t\n<<Not Find!There is not contact with tish cellphone number in phone book.>>");
    else {
        printf("\t\n<<Target contact found! Details:>>");
        printf("\n\nCantact %2.2d{",i+1);
        printf("\n\t   F.Name:%s\n\t   L.name:%s\n\t   Tele.P:%s\n\t   Cell.P:%s\n\t   }",A[i].fname,A[i].lname,A[i].telep,A[i].cellp);
    }
    printf("\nPress a key to search another contact.");
    getc(stdin);
    search();
}

void sort(void)
{
    char ch;
    clrscr();
    printf("\nPhone Book12<::>$earch Contacts");
    printf("\n--------------------------------------------------------------------------------");
    printf("\nChoose sort type,please:\n\n");
    printf("\t[1] |--> Sort by first name\n");
    printf("\t[2] |--> Sort by last name\n");
    printf("\t[3] |--> Sort by phone number\n");
    printf("\t[4] |--> Sort by cellphone number\n");
    printf("\t[5] |--> Main Menu\n");
    printf("\n\t::Enter a number (1-5): ");
    ch = getc(stdin);
    getc(stdin);
    printf("\n--------------------------------------------------------------------------------");
    switch(ch){
        case '1':
            sort_num =1;
            break;
        case '2':
            sort_num =2;
            break;
        case '3':
            sort_num =3;
            break;
        case '4':
            sort_num =4;
        case '5':
        default:
            return ;
    }
}



void list()
{
    register int i;
    clrscr();
    printf("\nPhone Book12<::>All Contacts List");
    printf("\n--------------------------------------------------------------------------------\n");
    gotoxy(1,4);
    printf("Row       ");
    gotoxy(9,4);
    printf("First Name   ");
    gotoxy(27,4);
    printf("Last Name   ");
    gotoxy(44,4);
    printf("Telephone   ");
    gotoxy(60,4);
    printf("Cellphone   ");
    printf("\n--------------------------------------------------------------------------------\n");
    show_results();
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\t\t    **********End Of list!**********");
    printf("\n\n\n   ::Press a key to return main page & continue program.|-->");
    getc(stdin);
}

void show_results(){
    int i=0;
    struct Node *run;
    if (sort_num == 1)
        run= head_fname;
    else if(sort_num== 2)
        run= head_lname;
    else if(sort_num== 3)
        run= head_telep;
    else if(sort_num == 4)
        run= head_cellp;
    while (run != NULL) {
        gotoxy(1, i + 6);
        printf("%3.3d", i + 1);
        gotoxy(9, i + 6);
        printf("%s", run->_data.fname);
        gotoxy(28, i + 6);
        printf("%s", run->_data.lname);
        gotoxy(44, i + 6);
        printf("%s", run->_data.telep);
        gotoxy(60, i + 6);
        printf("%s", run->_data.cellp);
        ++i;
        if (sort_num == 0)
            run = run->_next_fname;
        else if(sort_num == 1)
            run = run->_next_lname;
        else if(sort_num == 2)
            run = run->_next_telep;
        else if(sort_num == 3)
            run = run->_next_cellp;
    }
}

void help(void)
{
    clrscr();
    gotoxy(26,1);
    printf("--------------------------");
    gotoxy(26,2);
    printf("|Welcome To Phone Book12!|");
    gotoxy(26,3);
    printf("--------------------------");
    gotoxy(1,5);
    printf("PhoneBook12>>[Help & Instructions] \n");
    printf("--------------------------------------------------------------------------------\n");
    printf("\nAbout Phonebook12\n *Version: 2.5\n *Valence: 50 Contacts(MAX)\n  *By: Morteza Zakeri (2011-12)");
    printf("\n\nThis program allows you to have a list of your contacts.\nIt also allows you to have your listing added or deleted from your list.\nOther features of this program include:\nSearch,edit,sort & list.\n\n   ::Press a key to return main page & continue program.|-->");
    getc(stdin);
}

void clrscr()
{
    system("clear");
}

void gotoxy(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}



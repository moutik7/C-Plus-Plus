

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Bank.h"
using namespace std;
using namespace sdds;
int noOfRecs(FILE* fptr);
void readAccounts(Bank& L, FILE* fptr);
int main()
{
    FILE* fptr = fopen("accounts.csv", "r");
    Bank b[4];
    Bank L;
    int i;
    b[0].initialize("", 10);
    b[1].initialize(nullptr, 20);
    b[2].initialize("something", 0);
    b[3].initialize("something", -1);
    for (i = 0; i < 4; i++)
    {
        b[i].display();
        b[i].clear();
    }
    L.initialize("Seneca Bank & Trust", noOfRecs(fptr));
    readAccounts(L, fptr);
    L.display();
    L.display(true);
    L.clear();
    fclose(fptr);
}
int noOfRecs(FILE* fptr)
{
    int no = 0;
    int newline = 0;
    while ((newline = fgetc(fptr)) != EOF)
    {
        no += (newline == '\n');
    }
    rewind(fptr);
    return no;
}
void readAccounts(Bank& L, FILE* fptr)
{
    int noOfRecs = ::noOfRecs(fptr);
    int accNo;
    double balance;
    int days;
    for (int i = 0; i < noOfRecs; i++)
    {
        fscanf(fptr, "%d,%lf,%d\n", &accNo, &balance, &days);
        L.addAccount(accNo, balance, days);
    }
}


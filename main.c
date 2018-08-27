#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define nameMaxLength 20
struct student* root = NULL;

struct student{
    int studentID;
    char firstName[nameMaxLength+1];
    char lastName[nameMaxLength+1];
    float scores;
    char zipCode[6];
    struct student *left;
    struct student *right;
};

int main() {

	int menuInput,numRecords;
    menuInput=1;


    puts("Please indicate the number of records you want to enter (min 5):");
    scanf("%d",&numRecords);
    printf("----------------------------------------\n");
    insert(numRecords);

        while (menuInput!= 0)
    {
        printf("----------------------------------------\n");
        puts("Print records (press 1) ");
        puts("Add a new record (press 2) ");
        puts("Delete Record(s) (press 3) ");
        puts("Search by zip code (press 4) ");
        puts("Search by score range (press 5) ");
        puts("Find median score (press 6)  ");
        puts("Exit the program (press 0) ");
        printf("\nEnter your choice: ");
        scanf("%d",&menuInput);
        printf("----------------------------------------\n");
        switch(menuInput)
        {

        case 1:
            printf("Student Records:\n\n");
            printRecords(root);
            printf("\n");
            break;

        case 2:
            addRecords();
            break;
/*
        case 3:
            deleteRecord();
            break;
*/
        case 4:
            searchZip();
            break;

        case 5:
            searchSRange();
            break;
/*
        case 6:
            medianScore();
            break;*/
        case 0:
            exit(0);
            break;
        }


    }

    return 0;
}

void insert(int numRecords) {

	int i;
    puts("Please input records of students (enter a new line after each record), with following format:\nstudent ID first name last name score zip code\n");
        for(i=0;i<numRecords;i++)
    {
        struct student* temp;
        struct student* temp1;
        struct student* temp2;
        temp=(struct student*)malloc(sizeof(struct student));
        float tempScore;
        int tempID;
        temp=(struct student*)malloc(sizeof(struct student));
        scanf("%d%s%s%f%s",&tempID,temp->firstName,temp->lastName,&tempScore,temp->zipCode);
        temp->scores=tempScore;
        temp->studentID=tempID;
        temp->left=NULL;
        temp->right=NULL;

        if (root==NULL){
            root=temp;
        }
        else{
            temp1=root;
            while(temp1!=NULL){
                temp2=temp1;
                if((temp->studentID)<(temp1->studentID)){
                    temp1=temp1->left;
                }
                else{
                    temp1=temp1->right;
                }
            }
            if ((temp->studentID)<(temp2->studentID)){
                temp2->left=temp;

            }
            else{
                temp2->right=temp;
            }
        }
        temp1=NULL;
        temp2=NULL;
        temp=NULL;
    }
}

 void printRecords(struct student* temp){

   if (temp){

   printf("Student ID: %d\t\tFirstname: %s\tLastname: %s\tScore: %0.2f\tZipCode: %s\n",temp->studentID,temp->firstName,temp->lastName,temp->scores,temp->zipCode);
   printRecords(temp->left);
   printRecords(temp->right);
   }
}

void addRecords()
{
    int addNumber;
    puts("Please enter the number of records you want to add: ");
    scanf("%d",&addNumber);


    printf("----------------------------------------\n");
    insert(addNumber);
    printf("\nThe records were added!\nThe updated list is:\n\n");
    printRecords(root);
}

void searchZip()
{
    char givenZip[6];
    printf("\n");
    printf("Please enter the zip that you want to search in student records: \n");
    scanf("%s",&givenZip);
    printf("----------------------------------------\n\n");
    searchRecords(givenZip,root);


}

 void searchRecords(char givenZip,struct student* temp){

   if (temp){
   if(strcmp(givenZip,temp->zipCode)==0){
    printf("Student ID: %d\t\tFirstname: %s\tLastname: %s\tScore: %0.2f\tZipCode: %s\n",temp->studentID,temp->firstName,temp->lastName,temp->scores,temp->zipCode);
   }
searchRecords(givenZip,temp->right);
   searchRecords(givenZip,temp->left);
}

 }

void searchSRange()
{
    float maxScore, minScore;
    struct student *temp=root;
    printf("Please enter the Min Score Range: \n");
    scanf("%f",&minScore);
    printf("Please enter the Max Score Range: \n");
    scanf("%f",&maxScore);

    printf("----------------------------------------\n\n");
    searchScore(maxScore,minScore,root);

}

void searchScore(float maxScore, float minScore, struct student* temp){
if(temp==NULL){
    return;
    }

    if(((temp->scores)>minScore)&&((temp->scores)<maxScore)){
        printf("Student ID: %d\t\tFirstname: %s\tLastname: %s\tScore: %0.2f\tZipCode: %s\n",temp->studentID,temp->firstName,temp->lastName,temp->scores,temp->zipCode);
    }
      searchScore(maxScore,minScore,temp->left);
    searchScore(maxScore,minScore,temp->right);




}

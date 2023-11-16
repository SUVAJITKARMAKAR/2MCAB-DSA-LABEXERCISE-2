// DOMAIN - SOCIAL NETWORKING SITE
// SCENARIO - 


// HEADER FILE SECTION 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// STRUCTURE TO REPRESENT THE APPLICAITON RECORD
struct Social
{
    char userName[50];
    float followers;
    int following;
    struct Social* next;
};

// FUNCTION TO CREATE A NEW USER NODE 
struct Social* createUser(char userName[], float followers, int following) 

{
    printf("\n");
    printf("-------------------------------\n");
    struct Social* newUser = (struct Social*)malloc(sizeof(struct Social));
    strcpy(newUser->userName, userName);
    newUser->followers = followers;
    newUser->following = following;
    newUser->next = NULL;
    return newUser;
}

// INSERTING THE BEGINNING OF THE LINKED LIST OF THE USER LIST 
struct Social* insertUser(struct Social* head, char userName[], float followers, int following) 
{
    struct Social* newUser = createUser(userName, followers, following);
    newUser->next = head;
    return newUser;
}

// LIST OF USERS 
void displayUsers(struct Social* head) 
{
    struct Social* current = head;
    printf("\n");
    printf("-------------------------------\n");
    printf("USER INFORMATION LIST -> \n");
    while (current != NULL) 
    {
        printf("USER NAME -> %s, ACCOUNT FOLLOWERS -> %f, ACCOUNT FOLLOWING -> %d\n", current->userName, current->followers, current->following);
        current = current->next;
        printf("\n");
    }
}

// FREE MEMORY ALLOCAIONS
void freeUserList(struct Social* head) 
{
    struct Social* current = head;
    while (current != NULL) 
    {
        struct Social* temp = current;
        current = current->next;
        free(temp);
    }
}

void main() 
{
    struct Social* userList = NULL;

    int choice;
    do 
    {
        printf("APPLICATION MENU:\n");
        printf("1. ADD USER INFORMATION\n");
        printf("2. DISPLAY USER INFORMATION\n");
        printf("CHOICE ->  ");
        scanf("%d", &choice);

        printf("\n");

        switch (choice) 
        {
            case 1:
            {
                char userName[50];
                float followers;
                int following;

                printf("ENTER THE USERNAME -> ");
                scanf(" %[^\n]", userName);  
                printf("ACCOUNT FOLLOWERS -> ");
                scanf("%f", &followers);
                printf("ACCOUNT FOLLOWING -> ");
                scanf("%d", &following);

                userList = insertUser(userList, userName, followers, following);
                break;
            }
            case 2:
            {
                displayUsers(userList);
                break;
            }
            default:
                printf("PLEASE PICK YOUR CORRECT OPTION\n");
        }
    } while (choice != 2);

    freeUserList(userList);

}
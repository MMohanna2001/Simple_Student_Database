/*
 *Author: Mohamed Ahmed Mohanna     Mohamedmohanna@gmail.com
 *
 *
 * This the src file that that will be used
 * to interface and navigate through the database
 */
#include <stdio.h>
#include <stdlib.h>
#include "STD.h"
#include "SDB.h"
#include "SDBAPP.h"
/***************************************************************************/
//main application
void SDB_APP()
{
    SDB_init(); //initialize database
    uint8 input;
    while(1)
    {
        printf("\n\n************************************************************************\n");
        printf("\n");
        printf("Enter Your Choice \n"
               "1. To add entry, enter 1\n"
               "2. To get used size in database, enter 2\n"
               "3. To read student data, enter 3\n"
               "4. To get the list of all student IDs, enter 4\n"
               "5. To check is ID is existed, enter 5\n"
               "6. To delete student data, enter 6\n"
               "7. To check is database is full, enter 7\n"
               "8. To Update an Existing Entry, enter 8\n"
               "9. To exit enter 0\n\n");
        printf("...............\n");
        printf("Please Enter Your Choice: ");
        fflush(stdin);
        scanf("%d",&input);
        printf("\n");
        SDB_action(input);
        }
    }
/***************************************************************************/
//action to be performed depending on the user's input
void SDB_action(uint8 choice)
{
    uint32 input_ID;
    uint8 ID_count = 0;
    uint32 * ID_list;
  switch(choice)
  {
    case 0 : exit(0); break; //exit the whole program
    case 1 :
        if(SDB_AddEntry())
            printf("Student Entry added successfully\n");
        else
            printf("Entry Failed");

        break;
    case 2 : printf("There is a total of %d Students in the Database\n",SDB_GetUsedSize()); break;
    case 3 :
        printf("Please Input The Desired ID: ");
        scanf("%d",&input_ID);
        SDB_ReadEntry(input_ID);
        break;
    case 4:
        SDB_GetList(&ID_count,ID_list);
        for(uint8 i = 0; i < ID_count; i++)
            {
                printf("The %d ID : %d \n", i + 1, ID_list[i]);
            }
            break;
    case 5:
        printf("Please Enter The ID you need to check: ");
        scanf("%d",&input_ID);
        SDB_IsIdExist(input_ID);
        break;
    case 6 :
         printf("Please Enter The ID you need to delete: ");
         scanf("%d",&input_ID);
         SDB_DeletEntry(input_ID);
         break;
    case 7 :
        if(SDB_IsFull())
            printf("DataBase is Full\n");
        else
            printf("There is still room in the DataBase \n");
            break;
    case 8 :
        printf("Please Enter The ID you need to Update: ");
        scanf("%d",&input_ID);
        if(SDB_update(input_ID))
            printf("Update Successful.\n\n");
        else
           printf("Update Failed.\n\n");
           break;
    default : printf("Please Make a Valid Choice\n"); break;

  }
}

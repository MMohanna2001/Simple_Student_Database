/*
 *Author: Mohamed Ahmed Mohanna     Mohamedmohanna@gmail.com
 *
 *
 * This the src file that contains the functions that will be used to store and
 * manipulate student's information
 */
#include "SDB.h"
#include <stdio.h>
#include <stdlib.h>
uint8 listsize = 0; //Global Variable for the database size
student *SDB = NULL; //Array of Structure Representing the database
/***************************************************************************/
//Initializing the database
void SDB_init()
{
    printf("Student Database\n");
    printf("************************************************************************\n");
    //Loop for adding students until reaching the minimum threshold
    while (listsize < MIN_STUDENT_SIZE)
    {
        SDB_AddEntry();
    }
}
/***************************************************************************/
//Check if the database is full
bool SDB_IsFull(void)
{
    return listsize >= MAX_STUDENT_SIZE;
    //will return true only if the database size is equal to the maximum threshold
}
/***************************************************************************/
//Get the number of entries currently used in the database.
uint8 SDB_GetUsedSize(void)
{
    return  listsize ; //database size
}
/***************************************************************************/
//Add a new entry to the database.
bool SDB_AddEntry(void)
{
    if(listsize >= 10) //if full will not add any more entries
    {
        printf("Cannot Add, The DataBase Has The Maximum Number of Entries\n ");
        return false;
    }
    else
    {
        printf("************************************************************************\n");
        printf("\n");
        student entry;
        printf("Enter the values of the %d Student\n", listsize+1); //number of student being added
        printf("..................................\n");
        printf("Enter The Student ID: ");
        scanf("%d",&(entry.Student_ID));
        for (uint8 i = 0; i < listsize; i++)
        {
            if(entry.Student_ID == SDB[i].Student_ID) //if id existed, entry will not be added
            {
                printf("ID already Exists. \n");
                return false;
            }
        }
        printf("Enter The Student Year: ");
        scanf("%d",&(entry.Student_year));
        if(entry.Student_year < 1 || entry.Student_year > 12 ) //if year is out of range entry will not be added
        {
            printf("Student Year Should Lie between Year 1 and Year 12\n");
            return false;
        }
        printf("Enter The Student's Course 1 ID: ");
        scanf("%d",&(entry.Course1_ID));
        printf("Enter The Student's Course 1 Grade: ");
        scanf("%d",&(entry.Course1_grade));
        if(entry.Course1_grade < 0 || entry.Course1_grade > 100) //if grade is not valid will not be added
        {
            printf("Student's Grade should be a number between 0 and 100\n");
            return false;
        }
        printf("Enter The Student's Course 2 ID: ");
        scanf("%d",&(entry.Course2_ID));
        if(entry.Course2_ID == entry.Course1_ID )
        {
            printf("Course Already Entered\n");
            return false;
        }
        printf("Enter The Student's Course 2 Grade: ");
        scanf("%d",&(entry.Course2_grade));
        if(entry.Course2_grade < 0 || entry.Course2_grade > 100)
        {
            printf("Student's Grade should be a number between 0 and 100\n");
            return false;
        }
        printf("Enter The Student's Course 3 ID: ");
        scanf("%d",&(entry.Course3_ID));
        if(entry.Course3_ID == entry.Course1_ID || entry.Course3_ID == entry.Course2_ID )
        {
            printf("Course Already Entered\n");
            return false;
        }
        printf("Enter The Student's Course 3 Grade: ");
        scanf("%d",&(entry.Course3_grade));
        if(entry.Course3_grade < 0 || entry.Course3_grade > 100)
        {
            printf("Student's Grade should be a number between 0 and 100\n");
            return false;
        }
        SDB = (student *)realloc(SDB, (listsize + 1) * sizeof(student)); //reallocating memory for the new student information
        SDB[listsize] = entry; // adding the new student entry to the database
        listsize++; //increasing the database size
        return true;
    }
}
void SDB_DeletEntry(uint32 id)
{
    if(listsize <= MIN_STUDENT_SIZE) //if database has only elements
    {
        printf("Database is has only three entries cannot delete\n");
        printf("Deletion Failed\n");
        return;
    }
    uint32 removeindex; //index of the entry to be deleted
    uint32 i;
    uint32 j;
    //search for the desired ID
    for (i = 0; i < listsize; i++)
    {
        if(SDB[i].Student_ID == id)
        {
            removeindex = i;
            break;
        }
    }
    //if not found
    if (i == listsize)
    {
        printf("Entry does not exist\n");
        printf("Deletion Failed\n");
        return;
    }
    student temp[listsize - 1]; //temporary array to store elements that will not be deleted
    //copying all the elements before the before the one to be deleted
    for (j = 0; j < removeindex ; j++)
    {
        temp[j] = SDB[j];
    }
    //copying all the elements after the before the one to be deleted
    for (uint32 k = removeindex + 1 ; k < listsize; k++)
    {
        temp[j] = SDB[k] ;
        j++;
    }
    free(SDB); //clear the data base
    listsize--; //decrease the size of the database
    SDB = (student *)malloc((listsize) * sizeof(student)); //allocate the memory of the database with the new size
    //copying the elements of temporary array back to the SDB
    for (i = 0; i < listsize; i++)
    {
        SDB[i] = temp[i];
    }
    printf("Deletion Successful\n");
}
/***************************************************************************/
// Read an entry from the database by ID.
bool SDB_ReadEntry(uint32 id)
{
    printf("\n");
    //searching for the desired ID
    for (uint32 i = 0; i < listsize; i++)
    {
        if(SDB[i].Student_ID == id) //if found
        {
        printf("Student ID: %d\n",SDB[i].Student_ID);
        printf("Student Year: %d\n",SDB[i].Student_year);
        printf("Course 1 ID:%d\tCourse 3 Grade:%d\n",SDB[i].Course1_ID,SDB[i].Course1_grade);
        printf("Course 2 ID:%d\tCourse 3 Grade:%d\n",SDB[i].Course2_ID,SDB[i].Course2_grade);
        printf("Course 3 ID:%d\tCourse 3 Grade:%d\n",SDB[i].Course3_ID,SDB[i].Course3_grade);
        return true;
        }
    }
        printf("Entry does not exist\n");
        return false;
}
/***************************************************************************/
// Get a list of IDs of all entries in the database.
void SDB_GetList (uint8 * count, uint32 * list)
{
    *count = listsize; //storing the the database size in the count variable
    *list = (uint32 *)malloc(listsize * sizeof(uint32)); //allocating memory of the list of IDs
    for(int i = 0; i < listsize; i++)
    {
        list[i] = SDB[i].Student_ID;
    }
}
/***************************************************************************/
//Check if an ID exists in the database.
bool SDB_IsIdExist (uint32 id)
{
    //searching for the desired ID
    for (uint32 i = 0; i < listsize; i++)
    {
        if(SDB[i].Student_ID == id) //if found
        {
            printf("Entered ID Exists\n");
            return true;
        }
    }
    printf("The Entered ID Does Not Exists\n");
    return false;
}
/***************************************************************************/
// Update an entry in the database by ID.
bool SDB_update(uint32 id)
{
    //searching for the desired ID
    for (uint8 i = 0; i < listsize; i++)
    {
      if(SDB[i].Student_ID == id)
      {
        //Same Restrictions as Adding a new entry
        printf("************************************************************************\n");
        printf("\n");
        student entry;
        printf("Enter the values of the %d Student\n", i + 1);
        printf("..................................\n");
        printf("Enter The Student Year: ");
        scanf("%d",&(SDB[i].Student_year));
        if(SDB[i].Student_year < 1 || SDB[i].Student_year > 12 )
        {
            printf("Student Year Should Lie between Year 1 and Year 12\n");
            return false;
        }
        printf("Enter The Student's Course 1 ID: ");
        scanf("%d",&(SDB[i].Course1_ID));
        printf("Enter The Student's Course 1 Grade: ");
        scanf("%d",&(SDB[i].Course1_grade));
        if(SDB[i].Course1_grade < 0 || SDB[i].Course1_grade > 100)
        {
            printf("Student's Grade should be a number between 0 and 100\n");
            return false;
        }
        printf("Enter The Student's Course 2 ID: ");
        scanf("%d",&(SDB[i].Course2_ID));
        if(SDB[i].Course2_ID == SDB[i].Course1_ID )
        {
            printf("Course Already Entered\n");
            return false;
        }
        printf("Enter The Student's Course 2 Grade: ");
        scanf("%d",&(SDB[i].Course2_grade));
        if(SDB[i].Course2_grade < 0 || SDB[i].Course2_grade > 100)
        {
            printf("Student's Grade should be a number between 0 and 100\n");
            return false;
        }
        printf("Enter The Student's Course 3 ID: ");
        scanf("%d",&(SDB[i].Course3_ID));
        if(SDB[i].Course3_ID == SDB[i].Course1_ID || SDB[i].Course3_ID == SDB[i].Course2_ID )
        {
            printf("Course Already Entered\n");
            return false;
        }
        printf("Enter The Student's Course 3 Grade: ");
        scanf("%d",&(SDB[i].Course3_grade));
        if(SDB[i].Course3_grade < 0 || SDB[i].Course3_grade > 100)
        {
            printf("Student's Grade should be a number between 0 and 100\n");
            return false;
        }
        }
        return true;
    }
        printf("Entry does not exist\n");
        return ;
}



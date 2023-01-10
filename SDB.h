/*
 *Author: Mohamed Ahmed Mohanna     Mohamedmohanna@gmail.com
 *
 *
 * This header file contains the definition of a simple database structure
 * that will be used to store a student's information along with prototypes of
 * functions that will be used in order to manipulate such information
*/
#ifndef SBD_H
#define SBD_H
#include "STD.h" //Standard Types File
#define MAX_STUDENT_SIZE 10 //Maximum Number of Students in the Database
#define MIN_STUDENT_SIZE 3  //Minimum Number of Students in the Database
typedef struct SimpleDb
{
 uint32 Student_ID;
 uint32 Student_year;
 uint32 Course1_ID;
 uint32 Course1_grade;
 uint32 Course2_ID;
 uint32 Course2_grade;
 uint32 Course3_ID;
 uint32 Course3_grade;

} student;
void SDB_init(); //Initialize the database
bool SDB_IsFull(void); // Check if the database is full
uint8 SDB_GetUsedSize(void); // Get the number of entries currently used in the database.
bool SDB_AddEntry(void); // Add a new entry to the database.
void SDB_DeletEntry(uint32 id); // Delete an entry from the database by ID.
bool SDB_ReadEntry(uint32 id); // Read an entry from the database by ID.
void SDB_GetList (uint8 *count, uint32 *list); // Get a list of IDs of all entries in the database.
bool SDB_IsIdExist (uint32 id); // Check if an ID exists in the database.
bool SDB_update(uint32 id); // Update an entry in the database by ID.



#endif // SBD_H

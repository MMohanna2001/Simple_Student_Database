/*
 *Author: Mohamed Ahmed Mohanna     Mohamedmohanna@gmail.com
 *
 *
 * This header file defines several standard data types using the keyword typedef
 * that can be used in different parts of this program. The purpose of this
 * file is to provide a single location where these data types are defined,
 * so that they can be easily used in different parts of the program
 * without having to define them repeatedly.
*/
#ifndef STD_H
#define STD_H

typedef unsigned char uint8;
typedef char int8;
typedef unsigned short uint16;
typedef short int16;
typedef unsigned int uint32;
typedef unsigned int* uint32_ptr;
typedef int int32;
typedef enum {false, true} bool;

#endif // STD_H

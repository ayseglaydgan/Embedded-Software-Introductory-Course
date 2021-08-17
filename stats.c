/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief Definitions of functions which are written for Coursera Course Assignment Week1
 *
 * This file includes the main parts of all functions.
 *
 * @author Aysegul Aydogan
 * @date 16.08.2021
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  int max_value = 0;
  /* Statistics and Printing Functions Go Here */
  print_array(test, SIZE);
  sort_array(test, SIZE);
  printf("\nsorted***********\n");
  print_array(test,SIZE);
  max_value = find_maximum(test,SIZE);
  printf("\nMax Value: %d\n", max_value);
  

}

void print_array(unsigned char* arr, int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%u ",arr[i]);
  } 
}
void swap(unsigned char* a, unsigned char* b)
{
  unsigned char temp = *a;
  *a = *b;
  *b = temp;
}

void sort_array(unsigned char* arr, int size)
{
  int i, j, min;
  for (int i = 0; i < size - 1; i++)
  {
    min = i;
    for (int j = i + 1; j < size ; j++)
    {
      if (arr[j] < arr[min])
      {
        min = j;
      }
      
    }
    swap(&arr[min],&arr[i]);
  }
  
}
unsigned char find_maximum(unsigned char* arr, int size)
{
  sort_array(arr, size);
  return arr[size-1];
}

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
 * @date 17.08.2021
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
  printf("Original Array : ");
  print_array(test, SIZE);
  printf("\n");
  sort_array(test, SIZE);
  printf("\nSorted Array : ");
  print_array(test,SIZE);
  printf("\n");
  print_statistics(test,SIZE);

}

void print_array (unsigned int arrayLength, unsigned char *arrayElement) {
  //It provides additional details as to what the computer is doing and what drivers and software it is loading during startup.
  #ifdef VERBOSE
    for(int i=0;i<arrayLength;i++){
    	PRINTF("\tElement %d --> %d\n", i, (int)(*(arrayElement + i)));
    }
  #endif
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
      if (arr[j] > arr[min])
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
  return arr[0];
}

unsigned char find_minimum(unsigned char* arr, int size)
{
  sort_array(arr, size);
  return arr[size - 1];
}

float find_mean(unsigned char* arr, int size)
{
  float total = 0;
  float average = 0;
  for (int i = 0; i < size; i++)
  {
    total += (float)arr[i];
    
  }
  average = total / size;
  return average;
}

float find_median(unsigned char* arr, int size)
{
  float median = 0;
  if (size % 2 == 0) //even 
  {
    int m1 = size / 2;

    median = ((float)arr[m1-1] + (float)arr[m1]) / 2;
  }
  else
  {
    int m = (size + 1) / 2;
    median = (float)arr[m];
  }
  return median;
  
}

void print_statistics(unsigned char* arr, int size)
{
  int max_value = 0;
  int min_value = 0;
  float average = 0;
  float median = 0;
  max_value = find_maximum(arr, size);
  printf("\nMax Value: %d\n", max_value);
  min_value = find_minimum(arr, size);
  printf("\nMin Value: %d\n", min_value);
  average = find_mean(arr, size);
  printf("\nMean: %f\n",average);
  median = find_median(arr, size);
  printf("\nMedian: %f\n", median);
}
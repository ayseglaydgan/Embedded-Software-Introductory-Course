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
 * @file stats.h 
 * @brief Declarations of functions which are written for Coursera Course Assignment Week1 
 *
 * Most of the functions doing some calculations on a dataset statistical aspects and rest of them prints the results.
 * swap function is added by me to make it easy to sorting
 *
 * @author Aysegul Aydogan
 * @date 17.08.2021
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief prints the statistics of an array including minimum, maximum, mean, and median
 *
 * @param unsigned char* for achiving the array, and the size of array. Because this function calls all statistical functions in main
 *
 * @return no return needed
 */
void print_statistics(unsigned char* arr, int size);

/**
 * @brief prints the all elements in array
 *
 * @param unsigned char* for achiving the array, and the size of array.
 *
 * @return no return needed
 */
void print_array(unsigned char* arr, int size);

/**
 * @brief firstly calls the sort_array function then finds the middle value of sorted array
 *
 * @param unsigned char* for achiving the array, and the size of array.
 *
 * @return median
 */
float find_median(unsigned char* arr, int size);
 
/**
 * @brief finds the average of dataset
 *
 * @param unsigned char* for achiving the array, and the size of array.
 *
 * @return mean
 */
float find_mean(unsigned char* arr, int size);

/**
 * @brief calls sort_array funciton then 0th element of sorted array is max
 *
 * @param unsigned char* for achiving the array, and the size of array.
 *
 * @return maximum
 */
unsigned char find_maximum(unsigned char* arr, int size);

/**
 * @brief calls sort_array funciton then sizeth element of sorted array is min
 *
 * @param unsigned char* for achiving the array, and the size of array.
 *
 * @return minimum
 */
unsigned char find_minimum(unsigned char* arr, int size);

/**
 * @brief swaps the elements 
 *
 * @param unsigned char*a and unsigned char*b to swap between them
 *
 * @return no return needded.
 */
void swap(unsigned char* a, unsigned char* b);

/**
 * @brief sorts the array from largest to smallest
 *
 * @param unsigned char* for achiving the array, and the size of array.
 *
 * @return no return needded.
 */
void sort_array(unsigned char* arr, int size);



#endif /* __STATS_H__ */

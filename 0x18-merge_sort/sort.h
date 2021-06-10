#ifndef _SORT_H_
#define _SORT_H_

void print_array(const int *array, size_t size);
void merge_driver(int *array, int *temp, int start, int end);
void merge(int *array, int *temp, int start, int mid, int end);
void merge_sort(int *array, size_t size);

#endif

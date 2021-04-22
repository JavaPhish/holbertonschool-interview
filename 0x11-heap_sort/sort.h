#ifndef SORT_H
#define SORT_H

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void sift_down(int *array, int heap_len, int start, int len);

#endif
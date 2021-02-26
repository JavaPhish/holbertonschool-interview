#ifndef SLIDE_LINE
#define SLIDE_LINE

#define SLIDE_LEFT   'L'
#define SLIDE_RIGHT   'R'

int slide_line(int *line, size_t size, int direction);
int slide_left(int *line, size_t size);
int slide_right(int *line, size_t size);

#endif

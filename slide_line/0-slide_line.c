#include "slide_line.h"

/**
 * slide_line - Slides and merges an array of integers to the left or right
 * @line: Pointer to an array of integers
 * @size: Size of the array
 * @direction: Direction to slide and merge (SLIDE_LEFT or SLIDE_RIGHT)
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
    size_t i, j, start, step;
    int merged[size];

    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
        return (0);
    for (i = 0; i < size; i++)
        merged[i] = 0;

    if (direction == SLIDE_LEFT)
    {
        start = 0;
        step = 1;
    }
    else
    {
        start = size - 1;
        step = -1;
    }

    for (i = start; i < size; i += step)
    {
        if (line[i] == 0)
            continue;

        j = i;
        while (j + step >= 0 && j + step < size && line[j + step] == 0)
        {
            line[j + step] = line[j];
            line[j] = 0;
            j += step;
        }

        if (j + step >= 0 && j + step < size &&
            line[j + step] == line[j] && !merged[j + step])
        {
            line[j + step] += line[j];
            line[j] = 0;
            merged[j + step] = 1;
        }
    }

    return (1);
}

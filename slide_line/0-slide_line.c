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
    size_t i, insert_pos;
    int temp[size];

    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
        return (0);

    /* Initialize the temporary array */
    for (i = 0; i < size; i++)
        temp[i] = 0;

    /* Slide and merge logic */
    if (direction == SLIDE_LEFT)
    {
        insert_pos = 0;
        for (i = 0; i < size; i++)
        {
            if (line[i] != 0)
            {
                if (temp[insert_pos] == 0)
                    temp[insert_pos] = line[i];
                else if (temp[insert_pos] == line[i])
                {
                    temp[insert_pos] += line[i];
                    insert_pos++;
                }
                else
                {
                    insert_pos++;
                    temp[insert_pos] = line[i];
                }
            }
        }
    }
    else /* SLIDE_RIGHT */
    {
        insert_pos = size - 1;
        for (i = size; i-- > 0;)
        {
            if (line[i] != 0)
            {
                if (temp[insert_pos] == 0)
                    temp[insert_pos] = line[i];
                else if (temp[insert_pos] == line[i])
                {
                    temp[insert_pos] += line[i];
                    insert_pos--;
                }
                else
                {
                    insert_pos--;
                    temp[insert_pos] = line[i];
                }
            }
        }
    }

    /* Copy the result back to the original line array */
    for (i = 0; i < size; i++)
        line[i] = temp[i];

    return (1);
}

#include "monty.h"
/**
 *is_ascii - checks if a character is within the ASCII range
 * @c: character to check
 * Return: 1 if ASCII, 0 otherwise
 */
int is_ascii(int c)
{
	return (c >= 0 && c <= 127);
}

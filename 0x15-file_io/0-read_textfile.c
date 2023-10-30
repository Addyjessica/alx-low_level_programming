#include "main.h"

/**
 * read_textfile -  Program reads a text file and writes out the letters
 * @filename: filename.
 * @letters: numbers of letters printed.
 *
 * Return: numbers of letter printed and 0  if it fails
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int a;
	ssize_t n, m;
	char *point;

	if (!filename)
		return (0);

	a = open(filename, O_RDONLY);

	if (a == -1)
		return (0);

	point = malloc(sizeof(char) * (letters));
	if (!point)
		return (0);

	n = read(a, point, letters);
	m = write(STDOUT_FILENO, point, n);

	close(a);

	free(point);

	return (m);
}

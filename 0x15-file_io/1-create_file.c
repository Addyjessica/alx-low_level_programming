#include "main.h"

/**
 * create_file - Program creates a file
 * @filename: filename.
 * @text_content: content writed in the file
 *
 * Return: 1 if (success) and -1 if it fails
 */
int create_file(const char *filename, char *text_content)
{
	int a;
	int n;
	int r;

	if (!filename)
		return (-1);

	a = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (a == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (n = 0; text_content[n]; n++)
		;

	r = write(a, text_content, n);

	if (r == -1)
		return (-1);

	close(a);

	return (1);
}

#include "main.h"

/**
 * append_text_to_file - This program appends text at the end of a file
 * @filename: filename.
 * @text_content: added content.
 *
 * Return: 1 if success and -1 if it fails
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int a;
	int n;
	int b;

	if (!filename)
		return (-1);

	a = open(filename, O_WRONLY | O_APPEND);

	if (a == -1)
		return (-1);

	if (text_content)
	{
		for (n = 0; text_content[n]; n++)
			;

		b = write(a, text_content, n);

		if (b == -1)
			return (-1);
	}

	close(a);

	return (1);
}

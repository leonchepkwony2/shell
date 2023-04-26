#include "myShell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: on Success 1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * display_prompt - clear screen for the first time and move cursor to top
 * Return: void
 */
void display_prompt(void)
{
	static int first_time = 1;

	if (first_time)
	{
		const char* (CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J");

		write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, _strlen(CLEAR_SCREEN_ANSI));
		first_time = 0;
	}
	char username[100], hostname[100];

	getlogin_r(username, sizeof(username));
	gethostname(hostname, sizeof(hostname));
	for (int i = 0; i < _strlen(username); i++)
	{
		_putchar(username[i]);
	}
	_putchar('@');
	for (int i = 0; i < strlen(hostname); i++)
	{
		_putchar(hostname[i]);
	}
	_putchar(':');
	_putchar('~');
	_putchar('$');
	_putchar(' ');
}

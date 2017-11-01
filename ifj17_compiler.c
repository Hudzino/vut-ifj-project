/**
 * Project: Implementace překladače imperativního jazyka IFJ17.
 *
 * @brief Main file of compiler.
 * @author Timotej Halás <xhalas10@stud.fit.vutbr.cz>
 * @author Dominik Harmim <xharmi00@stud.fit.vutbr.cz>
 */


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "error.h"
#include "scanner.h"
#include "analysis.h"


/**
 * Main function.
 *
 * @return EXIT_SUCCESS (0), if compilation was seccessful, appropriate error code otherwise.
 */
int main(void)
{
	// FIXME: This is only for scanner (get_next_token function) testing.
	// Example usage of scanner.

	set_source_file(stdin);

#if 1 // if 1 test for analysis else test for scanner
	printf("Result of analysis was %d.\n", analyse());
#else
	Token token;
	Dynamic_string string;
	if (!dynamic_string_init(&string))
	{
		return ERROR_OTHER;
	}
	set_dynamic_string(&string);

	int code;

	while (true)
	{

		if (code = get_next_token(&token))
		{
			fprintf(stderr, "Scanner error!\n");
			dynamic_string_free(&string);

			return code; // scanner error occurred
		}

		if (token.type == TOKEN_TYPE_EOL)
		{
			continue;
		}

		printf("Token type is %d.\n", token.type);

		if (token.type == TOKEN_TYPE_KEYWORD)
		{
			printf("Token keyword is %d.\n", token.attribute.keyword);
		}
		else if (token.type == TOKEN_TYPE_IDENTIFIER)
		{
			printf("Token identifier is %s.\n", token.attribute.string->str);
		}
		else if (token.type == TOKEN_TYPE_INT_NUMBER)
		{
			printf("Token int is %d.\n", token.attribute.integer);
		}
		else if (token.type == TOKEN_TYPE_DOUBLE_NUMBER)
		{
			printf("Token double is %f.\n", token.attribute.decimal);
		}
		else if (token.type == TOKEN_TYPE_STRING)
		{
			printf("Token string is %s.\n", token.attribute.string->str);
		}
	}

	dynamic_string_free(&string);
#endif // 0

	return EXIT_SUCCESS; // compilation was successful
}

#include "cmdparser.h"

#include <stddef.h>
#include <string.h>
#include <stdlib.h>

void command_parser_new(command_parser_t* parser, const char* _s) {
	if(!parser) {
		return;
	}

	parser->original_string = calloc(strlen(_s) + 1, 1);
	memcpy(parser->original_string, _s, strlen(_s));

	parser->argc = 0;


	char* ptr = parser->original_string;
	// Count arguments
	while(*ptr++ == ' ')
		;
	while(*ptr++) {
		if(*ptr == ' ' || *ptr == 0) {
			if(parser->original_string != ptr - 1) {
				parser->argc++;
			}

			while(*ptr++ == ' ')
				;
			ptr--;
		}
	}

	
	parser->argv = calloc(parser->argc, sizeof(char*));
	
	char* prev = parser->original_string;
	ptr = prev;

	size_t cur = 0;

	// Parse
	while(*ptr++ == ' ')
		;

	prev = ptr - 1;
	while(*ptr++) {
		if(*ptr == ' ' || *ptr == 0) {
			size_t len = ptr - prev;

			parser->argv[cur] = calloc(len + 1, 1);

			memcpy(parser->argv[cur], prev, len);

			cur++;

			while(*ptr++ == ' ')
				;

			prev = --ptr;
		}
	}
}

void command_parser_destroy(command_parser_t* parser) {
	free(parser->original_string);

	for(int i = 0; i < parser->argc; i++) {
		free(parser->argv[i]);
	}

	free(parser->argv);
}


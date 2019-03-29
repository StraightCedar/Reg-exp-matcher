#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "regexp.h"

int main(void) {
	int result;
	char * regexp = "C.";
	char * text = "ABCCDE";

	result = match(regexp, text);
	printf("regexp = '%s', text = '%s', result = %d\n", regexp, text, result);
}

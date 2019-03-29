#include "regexp.h"

// Beautiful Code Chapt.1 Regular expression matcher

// doxygen reference
// https://qiita.com/wakaba130/items/faa6671bd5c954cb2d02

static int matchhere(const char * const regexp, const char * const text);
static int matchstar(const int c, const char * const regexp, const char *text);

/*	
	regexp - regular expressions
		c --> a character
		. --> matches any single character
		^ --> start
		$ --> end
		* --> 0 or more occurrences of the pattern to its left
	text - string
return: -1 = not matched, not less than 0 = index of matched character.
*/
int match(const char * const regexp, const char * text) {
	const char * const p_org_text = text;

	if ('^' == regexp[0]) return(matchhere(regexp + 1, text));
	do {
		if (matchhere(regexp, text)) return(text - p_org_text);
	} while ('\0' != *text++);
	return(-1);
}

static int matchhere(const char * const regexp, const char * const text) {
	if ('\0' == regexp[0]) return(1);
	if ('*' == regexp[1]) return(matchstar(regexp[0], regexp + 2, text));
	if ('$' == regexp[0] && '\0' == regexp[1]) return('\0' == *text);
	if ('\0' != *text && ('.' == regexp[0] || *text == regexp[0])) return(matchhere(regexp + 1, text + 1));
	return(0);
}

static int matchstar(const int c, const char * const regexp, const char *text) {
	do {
		if (matchhere(regexp, text)) return(1);
	} while ('\0' != *text && (c == *text++ || '.' == c));
	return(0);
}

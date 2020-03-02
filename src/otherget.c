//
// Created by anonymus-raccoon on 3/2/20.
//

#include "xml.h"

char *xml_gettmpstring(node *n, const char *key, char *def)
{
	char *ret = xml_gettempprop(n, key);
	return ret ? ret : def;
}
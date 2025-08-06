#include <stdlib.h>
#include "huffman.h"

/**
 * symbol_create - Creates a symbol_t structure
 * @data: The character data of the symbol
 * @freq: The frequency of the symbol
 * Return: Pointer to the created symbol_t structure, or NULL on failure
 */

symbol_t *symbol_create(char data, size_t freq)
{
	symbol_t *new_symbol;

	new_symbol = malloc(sizeof(symbol_t));
	if (!new_symbol)
		return (NULL);

	new_symbol->data = data;
	new_symbol->freq = freq;

	return (new_symbol);
}

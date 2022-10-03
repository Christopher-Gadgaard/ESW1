#include "linkedList.h"
#include "listNode.c"
#include <stdint.h>
#include <stdlib.h>

typedef struct linkedList {
	uint16_t size;
	
}linkedList_st_t;

linkedList_t linkedList_create(void)
{
	linkedList_t _newLinkedList = calloc(sizeof(linkedList_st_t), 1);

	if (NULL == _newLinkedList)
		return NULL;

	return _newLinkedList;
}

linkedList_listReturnCode_t destroy(linkedList_t self)
{
	if (self != NULL)
	{
		free(self);
	}
}

linkedList_listReturnCode_t push(linkedList_t list, void* item)
{

}

void* linkedList_pull(linkedList_t list);

linkedList_listReturnCode_t linkedList_containsItem(linkedList_t list, void* item);

linkedList_listReturnCode_t linkedList_removeItem(linkedList_t list, void* item);

void* linkedList_peekItemByIndex(linkedList_t list, uint16_t index);

int linkedList_length(linkedList_t list);

void linkedList_clear(linkedList_t list);

linkedList_iterator_t linkedList_getIterator(linkedList_t list);

void* linkedList_iteratorNext(linkedList_t list, linkedList_iterator_t* iterator);
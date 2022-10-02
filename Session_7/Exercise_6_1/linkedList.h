#pragma once

typedef enum {
	OK,
	EMPTY,
	NOT_FOUND,
	FULL,
	FOUND
}linkedList_ListReturnCode_t;

typedef struct linkedList* linkedList_t;

linkedList_t linkedList_create(void);
linkedList_ListReturnCode_t destroy(linkedList_t self);
linkedList_ListReturnCode_t push(void item)
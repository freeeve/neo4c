#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

#include "neo4c.h"

bool
neo_cursor_has_next(neo_cursor *cursor) {
  return cursor->head != NULL;
}

void 
neo_elem_free(neo_elem *elem) {
  if(elem->data) {
    free(elem->data);
  }
  free(elem);
}

bool
neo_cursor_next(neo_cursor *cursor) {
  neo_elem *tmp = cursor->head;
  cursor->head = cursor->head->next;
  neo_elem_free(tmp);
  return true;
}

void
neo_cursor_init(neo_cursor *cursor) {
  cursor->head = NULL;
  cursor->tail = NULL;
}

void
neo_cursor_add_result(neo_cursor *cursor, neo_data *data) {
  if(cursor->head == NULL) {
    cursor->head = malloc(sizeof(neo_elem));
    cursor->head->data = data;
    cursor->head->next = NULL;
    cursor->tail = cursor->head;
  } else {
    cursor->tail->next = malloc(sizeof(neo_cursor));
    cursor->tail = cursor->tail->next;
    cursor->tail->next = NULL;
    cursor->tail->data = data;
  }
}

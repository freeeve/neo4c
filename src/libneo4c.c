#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

#include "neo4c.h"

bool
neo_cursor_has_next(neo_cursor *cursor)
{
  printf("%d\n", cursor->next != NULL);
  return cursor->next != NULL;
}

bool
neo_cursor_next(neo_cursor *cursor)
{
  cursor = cursor->next;
}

void
neo_cursor_init(neo_cursor *cursor)
{
  cursor->next = NULL;
}

void
neo_cursor_add_result(neo_cursor *cursor, neo_data *data)
{
  if(cursor->data == NULL)
  {
    cursor->data = data;
  } else {
    cursor->next = malloc(sizeof(neo_cursor));
    cursor = cursor->next;
  }
}

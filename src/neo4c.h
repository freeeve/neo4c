typedef struct neo_data {
  void *data;
  struct neo_data *head;
  struct neo_data *tail;
} neo_data;

typedef struct neo_elem {
  neo_data *data;
  struct neo_elem *next;
} neo_elem;

typedef struct neo_cursor {
  struct neo_elem *head;
  struct neo_elem *tail;
} neo_cursor;

bool neo_cursor_has_next(neo_cursor *cursor);

bool neo_cursor_next(neo_cursor *cursor);

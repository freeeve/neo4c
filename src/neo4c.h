typedef struct neo_data {
  void *data;
  struct neo_data *next;
} neo_data;

typedef struct neo_cursor {
  neo_data *data;
  struct neo_cursor *next;
} neo_cursor;

bool neo_cursor_has_next(neo_cursor *cursor);

bool neo_cursor_next(neo_cursor *cursor);

typedef struct neo_rest {
  char *hostname;
} neo_rest;

void neo_rest_init(neo_rest *conn);

bool neo_rest_query(neo_rest *conn, neo_cursor *cursor, char *query);

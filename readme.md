## neo4c
**I see what you did there... you changed the `j` to a `c`...** No, this is not neo4j rewritten in C...

A *driver* for neo4j for C, which uses the REST protocol, focusing on Cypher support. *It is far from complete--in fact, 
it's not even usable in an unstable manner, yet.*
The goals of the library are to provide some wrappers to libcurl and a json library to allow neo4j-specific
utility functions.

### usage

#### a quick example
```C
#include <neo4c.h>

int main(int argc, char **argv) {
  // create a neo_rest connection
  neo_rest conn;
  neo_cursor cursor;

  // create a cypher query
  char *query = "start n=node(*) return n";

  // execute the query and return a cursor to the results
  neo_rest_query(&conn, &cursor, query);

  // need to remember to clean up your stuff
  neo_cursor_destroy(&cursor);
  neo_rest_destroy(&conn);
}
```

#### query parameters
```C
  // set an id...
  uint64_t id = 1;

  // printf style parameter setting
  char *query = "start n=node({id}) return n;"
  
  // currently, the parameters must be in the order they are in the query
  // this seems idiomatic for C people, but...
  // if anyone has a good C syntax for map support, please let me know
  neo_rest_query(&conn, &cursor, query, id)
```

### dependencies
* libcurl >= 7.15
* json-c >= 0.9 (this might go away or change--still playing with it)
* libcheck >= 0.9 (for `make check` unit tests)


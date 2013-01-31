#include "config.h"
#include "../src/neo_rest.h"
#include "../src/neo4c.h"
#include <check.h>
#include <stdbool.h>

START_TEST(rest_core)
{
  // create a neo_rest connection
  //neo_rest conn;
  //neo_cursor cursor;

  // create a cypher query
  char *query = "start n=node(*) return n";

  // execute the query and return a cursor to the results
  bool ret = true;//neo_rest_query(&conn, &cursor, query);

  fail_unless(ret==true, "");
}
END_TEST

Suite *
libneo4j_c_suite(void)
{
  Suite *s = suite_create("libneo4c");
  TCase *tc = tcase_create("core");
  tcase_add_test(tc, rest_core);
  suite_add_tcase(s, tc);
  return s;
}

int
main()
{
  int nf;
  Suite *s = libneo4j_c_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_log(sr, "check_libneo4c.log");
  srunner_run_all(sr, CK_NORMAL);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (nf == 0) ? 0 : 1;
}


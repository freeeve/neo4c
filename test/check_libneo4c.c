#include "config.h"
#include <check.h>
#include <stdbool.h>
#include "../src/neo4c.h"
#include "../src/neo_rest.h"

START_TEST(rest_core)
{
  neo_rest conn;
  neo_cursor cursor;

  neo_rest_init(&conn);
  neo_cursor_init(&cursor);

  char *query = "start n=node(*) return n";
  bool ret = neo_rest_query(&conn, &cursor, query);
  fail_unless(ret==true, "return value is false");
}
END_TEST

START_TEST(rest_simple)
{
  neo_rest conn;
  neo_cursor cursor;

  neo_rest_init(&conn);
  neo_cursor_init(&cursor);

  char *query = "start n=node(*) return n";
  bool ret = neo_rest_query(&conn, &cursor, query);
  fail_unless(ret==true, "return value is false");
  //neo_cursor_add_result(&cursor, NULL);
  while(neo_cursor_has_next(&cursor) == true) 
  {
    bool cursor_ret = neo_cursor_next(&cursor);
    fail_unless(cursor_ret == true, "cursor return value is false");

    // get data...
  }
  fail_unless(neo_cursor_has_next(&cursor) == false, "cursor has next after loop");
  fail_unless(ret==true, "return value is false");
}
END_TEST

Suite *
libneo4j_c_suite(void)
{
  Suite *s = suite_create("libneo4c");
  TCase *tc = tcase_create("core");
  tcase_add_test(tc, rest_core);
  tcase_add_test(tc, rest_simple);
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


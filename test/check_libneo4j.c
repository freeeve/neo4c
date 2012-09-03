#include "config.h"
#include <check.h>

/*
 * Core test suite
 */
START_TEST(test_core)
{
  fail_unless(1==1, "core test suite");
}
END_TEST

Suite *
libneo4j_c_suite(void)
{
  Suite *s = suite_create("libneo4j-c");
  TCase *tc = tcase_create("core");
  tcase_add_test(tc, test_core);
  suite_add_tcase(s, tc);
  return s;
}

/*
 * Main
 */
int
main()
{
  int nf;
  Suite *s = libneo4j_c_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_log(sr, "check_neo4j_c.log");
  srunner_run_all(sr, CK_NORMAL);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);
  //suite_free(s);
  return (nf == 0) ? 0 : 1;
}


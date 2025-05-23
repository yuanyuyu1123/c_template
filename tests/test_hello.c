#include <check.h>
#include <stdlib.h>

// 测试用例1
START_TEST(test_hello_world) {
}

END_TEST

// 测试套件创建
Suite *hello_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Hello");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_hello_world);
    suite_add_tcase(s, tc_core);

    return s;
}

// 主函数
int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = hello_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
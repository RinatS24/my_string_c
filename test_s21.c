#include <stdio.h>
#include <string.h>

#include "s21_string.h"

START_TEST(s_strstr) {
  ck_assert_ptr_eq(s21_strstr("hello world", "world"),
                   strstr("hello world", "world"));
  ck_assert_ptr_eq(s21_strstr("hello world", "planet"),
                   strstr("hello world", "planet"));
  ck_assert_ptr_eq(s21_strstr("hello", ""), strstr("hello", ""));
  ck_assert_ptr_eq(s21_strstr("", "hello"), strstr("", "hello"));
}
END_TEST

START_TEST(s_strrchr) {
  ck_assert_ptr_eq(s21_strrchr("hello world", 'o'),
                   strrchr("hello world", 'o'));
  ck_assert_ptr_eq(s21_strrchr("hello world", 'p'),
                   strrchr("hello world", 'p'));
  ck_assert_ptr_eq(s21_strrchr("hello world", '\0'),
                   strrchr("hello world", '\0'));
  ck_assert_ptr_eq(s21_strrchr("", 'p'), strrchr("", 'p'));
}
END_TEST

START_TEST(s_strcspn) {
  ck_assert_int_eq(s21_strcspn("hello world", "ow"),
                   strcspn("hello world", "ow"));
  ck_assert_int_eq(s21_strcspn("hello world", "xyz"),
                   strcspn("hello world", "xyz"));
  ck_assert_int_eq(s21_strcspn("", "a"), strcspn("", "a"));
  ck_assert_int_eq(s21_strcspn("hello world", ""), strcspn("hello world", ""));
}
END_TEST

START_TEST(s_memchr) {
  ck_assert_ptr_eq(s21_memchr("abcdef", 'c', 6), memchr("abcdef", 'c', 6));
  ck_assert_ptr_eq(s21_memchr("abcdef", 'z', 6), memchr("abcdef", 'z', 6));
  ck_assert_ptr_eq(s21_memchr("hello\0world", '\0', 6),
                   memchr("hello\0world", '\0', 6));
  ck_assert_ptr_eq(s21_memchr("abcdef", '\0', 6), memchr("abcdef", '\0', 6));
}
END_TEST

START_TEST(s_memset) {
  char buffer1[10] = {0};
  char buffer2[10] = {0};
  ck_assert_mem_eq(s21_memset(buffer1, 'A', 5), memset(buffer2, 'A', 5), 10);
  ck_assert_mem_eq(s21_memset(buffer1, 0, 10), memset(buffer2, 0, 10), 10);
}
END_TEST

START_TEST(s_strchr) {
  ck_assert_ptr_eq(s21_strchr("hello", 'e'), strchr("hello", 'e'));
  ck_assert_ptr_eq(s21_strchr("hello", 'z'), strchr("hello", 'z'));
  ck_assert_ptr_eq(s21_strchr("hello", '\0'), strchr("hello", '\0'));
}
END_TEST

START_TEST(s_memcpy) {
  char dest[20];
  ck_assert_ptr_eq(s21_memcpy(dest, "hello world", 12),
                   memcpy(dest, "hello world", 12));
  ck_assert_ptr_eq(s21_memcpy(dest, "hello world", 0),
                   memcpy(dest, "hello world", 0));
  char ddest[10];
  ck_assert_ptr_eq(s21_memcpy(ddest, "hello world", 5),
                   memcpy(ddest, "hello world", 5));
}
END_TEST

START_TEST(s_strncat) {
  char dest1[20] = "Hello, ";
  char src1[] = "World!";
  ck_assert_ptr_eq(s21_strncat(dest1, src1, 7), strncat(dest1, src1, 7));

  char dest2[20] = "Hello";
  char src2[] = " World";
  ck_assert_ptr_eq(s21_strncat(dest2, src2, 3), strncat(dest2, src2, 3));

  char dest3[20] = "Hello";
  char src3[] = "";
  ck_assert_ptr_eq(s21_strncat(dest3, src3, 3), strncat(dest3, src3, 3));

  char dest4[20] = "";
  char src4[] = "World";
  ck_assert_ptr_eq(s21_strncat(dest4, src4, 5), strncat(dest4, src4, 5));
}
END_TEST

START_TEST(s_strpbrk) {
  ck_assert_ptr_eq(s21_strpbrk("hello world", "hlow"),
                   strpbrk("hello world", "hlow"));
  ck_assert_ptr_eq(s21_strpbrk("hello world", ""), strpbrk("hello world", ""));
  ck_assert_ptr_eq(s21_strpbrk("", "hello world"), strpbrk("", "hello world"));
}
END_TEST

START_TEST(s_strlen) {
  ck_assert_int_eq(s21_strlen("hello world"), strlen("hello world"));
  ck_assert_int_eq(s21_strlen(""), strlen(""));
  ck_assert_int_eq(s21_strlen("\0"), strlen("\0"));
  ck_assert_int_eq(s21_strlen("fhHfS245G"), strlen("fhHfS245G"));
}
END_TEST

START_TEST(s_strtok) {
  char str1[] = "hello world";
  char* token1 = s21_strtok(str1, " ");

  char str2[] = "hello world";
  char* token2 = strtok(str2, " ");

  ck_assert_str_eq(token1, token2);

  token1 = s21_strtok(NULL, " ");
  token2 = strtok(NULL, " ");

  ck_assert_str_eq(token1, token2);
}
END_TEST

START_TEST(s_memcmp) {
  ck_assert_int_eq(s21_memcmp("hello", "hello", 5),
                   memcmp("hello", "hello", 5));
  ck_assert_int_eq(s21_memcmp("12345", "13348", 5),
                   memcmp("12345", "13348", 5));
}
END_TEST

START_TEST(s_strncpy) {
  char dest1[20];
  ck_assert_ptr_eq(s21_strncpy(dest1, "hello", 6), strncpy(dest1, "hello", 6));
  char dest2[20];
  ck_assert_ptr_eq(s21_strncpy(dest2, "", 1), strncpy(dest2, "", 1));
  char dest3[20];
  ck_assert_ptr_eq(s21_strncpy(dest3, "\0", 1), strncpy(dest3, "\0", 1));
}
END_TEST

START_TEST(s_strncmp) {
  ck_assert_int_eq(s21_strncmp("hello world", "hello world", 12),
                   strncmp("hello world", "hello world", 12));
  ck_assert_int_eq(s21_strncmp("hello", "world", 5),
                   strncmp("hello", "world", 5));
  ck_assert_int_eq(s21_strncmp("hello", "", 5), strncmp("hello", "", 5));
}
END_TEST

START_TEST(s_strerror) {
  ck_assert_str_eq(s21_strerror(0), strerror(0));
  ck_assert_str_eq(s21_strerror(2), strerror(2));
  ck_assert_str_eq(s21_strerror(3), strerror(3));
  ck_assert_str_eq(s21_strerror(1479836), strerror(1479836));
}
END_TEST

Suite* my_string_suite(void) {
  Suite* suite = suite_create("S21_String");
  TCase* tcase = tcase_create("Core");

  tcase_add_test(tcase, s_strstr);
  tcase_add_test(tcase, s_strrchr);
  tcase_add_test(tcase, s_strcspn);
  tcase_add_test(tcase, s_memchr);
  tcase_add_test(tcase, s_memset);
  tcase_add_test(tcase, s_strchr);
  tcase_add_test(tcase, s_memcpy);
  tcase_add_test(tcase, s_strncat);
  tcase_add_test(tcase, s_strpbrk);
  tcase_add_test(tcase, s_strlen);
  tcase_add_test(tcase, s_strtok);
  tcase_add_test(tcase, s_memcmp);
  tcase_add_test(tcase, s_strncpy);
  tcase_add_test(tcase, s_strncmp);
  tcase_add_test(tcase, s_strerror);

  suite_add_tcase(suite, tcase);
  return suite;
}
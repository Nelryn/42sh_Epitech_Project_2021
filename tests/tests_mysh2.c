/*
** EPITECH PROJECT, 2021
** tests_mysh2.c
** File description:
** tests_mysh2
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(cpy, copy_str)
{
    char *test1 = cpy("hello word", 0);
    char *test2 = cpy("hello word", 6);

    cr_assert_str_eq(test1, "hello word");
    cr_assert_str_eq(test2, "word");
    free(test1);
    free(test2);
}

Test(check, check_char)
{
    int t1 = check("cd;pwd");
    int t2 = check("cat<toto");
    int t3 = check("cd>hello");
    int t4 = check("ls>>file");
    int t5 = check("ls&&cd");
    int t6 = check("ls|grep");
    int t7 = check("repeat");
    int t8 = check("ls");

    cr_assert_eq(t1, 1);
    cr_assert_eq(t2, 1);
    cr_assert_eq(t3, 1);
    cr_assert_eq(t4, 1);
    cr_assert_eq(t5, 1);
    cr_assert_eq(t6, 1);
    cr_assert_eq(t7, 1);
    cr_assert_eq(t8, 0);
}
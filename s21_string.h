#ifndef S21_STRING_H
#define S21_STRING_H

#include <stddef.h>
#include <check.h>
#define NULL ((void *)0)

#ifdef __APPLE__
#define ERRORS { \
    "No error", \
    "Operation not permitted", \
    "No such file or directory", \
    "No such process", \
    "Interrupted system call", \
    "Input/output error", \
    "No such device or address", \
    "Argument list too long", \
    "Exec format error", \
    "Bad file descriptor", \
    "No child processes", \
    "Resource temporarily unavailable", \
    "Out of memory", \
    "Permission denied", \
    "Bad address", \
    "Block device required", \
    "Device or resource busy", \
    "File exists", \
    "Cross-device link", \
    "No such device", \
    "Not a directory", \
    "Is a directory", \
    "Invalid argument", \
    "Too many open files in system", \
    "Too many open files", \
    "Inappropriate ioctl for device", \
    "Text file busy", \
    "File too large", \
    "No space left on device", \
    "Illegal seek", \
    "Read-only file system", \
    "Too many links", \
    "Broken pipe", \
    "Numerical argument out of domain", \
    "Result too large", \
    "Resource deadlock avoided" \
}
#define NUM_ERRORS 35
#elif __linux__
#define ERRORS { \
    "Success", \
    "Operation not permitted", \
    "No such file or directory", \
    "No such process", \
    "Interrupted system call", \
    "I/O error", \
    "No such device or address", \
    "Argument list too long", \
    "Exec format error", \
    "Bad file descriptor", \
    "No child processes", \
    "Resource temporarily unavailable", \
    "Cannot allocate memory", \
    "Permission denied", \
    "Bad address", \
    "Block device required", \
    "Device or resource busy", \
    "File exists", \
    "Invalid cross-device link", \
    "No such device", \
    "Not a directory", \
    "Is a directory", \
    "Invalid argument", \
    "Too many open files in system", \
    "Too many open files", \
    "Inappropriate ioctl for device", \
    "Text file busy", \
    "File too large", \
    "No space left on device", \
    "Illegal seek", \
    "Read-only file system", \
    "Too many links", \
    "Broken pipe", \
    "Numerical argument out of domain", \
    "Result too large" \
}
#define NUM_ERRORS 35
#else
#error "Unsupported operating system"
#endif

char *s21_strpbrk(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, size_t n);
size_t s21_strlen(const char *str);
char *s21_strchr(const char *str, int c);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strncpy(char *dest, const char *src, size_t n);
char *s21_strncat(char *dest, const char *src, size_t n);
int s21_strcmp(const char *str1, const char *str2);
int s21_memcmp(const void *str1, const void *str2, size_t n);
void *s21_memcpy(void *dest, const void *src, size_t n);
void *s21_memset(void *str, int c, size_t n);
void *s21_memchr(const void *str, int c, size_t n);
size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
char *s21_strtok(char *str, const char *delim);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
int strncmp(const char *str1, const char *str2, size_t n);

int s21_sprintf(char *str, const char *format, ...);

#endif // S21_STRING_H

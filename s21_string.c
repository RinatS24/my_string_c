#include "s21_string.h"

#include <stdio.h>
// s21_strstr
char *s21_strstr(const char *haystack, const char *needle) {
  if (haystack != NULL && needle != NULL) {
    if (*needle == '\0') return (char *)haystack;

    while (*haystack) {
      if (*haystack == *needle) {
        const char *start = haystack;
        const char *sub = needle;

        while (*start && *sub && (*start == *sub)) {
          ++start;
          ++sub;
        }

        if (*sub == '\0') return (char *)haystack;
      }
      ++haystack;
    }
  }
  return NULL;
}

// s21_strrchr
char *s21_strrchr(const char *str, int c) {
  const char *last_occurrence = NULL;
  while (*str) {
    if (*str == (char)c) {
      last_occurrence = str;
    }
    str++;
  }
  if (c == '\0') return (char *)str;

  return (char *)last_occurrence;
}

// s21_strcspn
size_t s21_strcspn(const char *str1, const char *str2) {
  int count = 0;
  if (str1 && str2) {
    while (*str1) {
      const char *temp = str2;
      while (*temp) {
        if (*str1 == *temp) {
          return count;
        }
        temp++;
      }
      str1++;
      count++;
    }
  }
  return count;
}

// s21_memchr
void *s21_memchr(const void *s, int c, size_t n) {
  const unsigned char *p = (const unsigned char *)s;
  for (size_t i = 0; i < n; i++) {
    if (p[i] == (unsigned char)c) {
      return (void *)(p + i);
    }
  }
  return NULL;
}

// s21_memset
void *s21_memset(void *s, int c, size_t n) {
  unsigned char *p = s;
  for (size_t i = 0; i < n; i++) {
    p[i] = (unsigned char)c;
  }
  return s;
}

// s21_strchr
char *s21_strchr(const char *s, int c) {
  while (*s) {
    if (*s == c) return (char *)s;
    s++;
  }
  if (c == '\0') return (char *)s;
  return NULL;
}

//  s21_memcpy
void *s21_memcpy(void *dest, const void *src, size_t n) {
  unsigned char *d = (unsigned char *)dest;
  const unsigned char *s = (const unsigned char *)src;
  while (n--) {
    *d++ = *s++;
  }
  return dest;
}

// s21_strncat
char *s21_strncat(char *dest, const char *src, size_t n) {
  char *ptr = dest + s21_strlen(dest);
  while (n-- && *src) {
    *ptr++ = *src++;
  }
  *ptr = '\0';
  return dest;
}

// s21_strpbrk
char *s21_strpbrk(const char *str1, const char *str2) {
  while (*str1) {
    const char *s = str2;
    while (*s) {
      if (*str1 == *s) {
        return (char *)str1;
      }
      s++;
    }
    str1++;
  }
  return NULL;
}
// s21_strlen
size_t s21_strlen(const char *str) {
  const char *s = str;
  while (*s) {
    s++;
  }
  return s - str;
}
// s21_strtok
char *s21_strtok(char *str, const char *delim) {
  static char *last = NULL;
  if (str == NULL) {
    str = last;
  }

  while (*str && s21_strchr(delim, *str)) {
    str++;
  }

  if (*str == '\0') {
    last = NULL;
    return NULL;
  }

  char *token_start = str;

  while (*str && !s21_strchr(delim, *str)) {
    str++;
  }

  if (*str) {
    *str = '\0';
    last = str + 1;
  } else {
    last = NULL;
  }

  return token_start;
}
// s21_memcmp
int s21_memcmp(const void *str1, const void *str2, size_t n) {
  const unsigned char *s1 = (const unsigned char *)str1;
  const unsigned char *s2 = (const unsigned char *)str2;
  while (n--) {
    if (*s1 != *s2) {
      return (int)*s1 - (int)*s2;
    }
    s1++;
    s2++;
  }
  return 0;
}
// s21_strncpy
char *s21_strncpy(char *dest, const char *src, size_t n) {
  char *original_dest = dest;
  while (n && *src) {
    *dest++ = *src++;
    n--;
  }
  while (n) {
    *dest++ = '\0';
    n--;
  }
  return original_dest;
}
// s21_strncmp
int s21_strncmp(const char *str1, const char *str2, size_t n) {
  while (n--) {
    if (*str1 != *str2) {
      return (unsigned char)(*str1) - (unsigned char)(*str2);
    }
    if (*str1 == '\0') {
      return 0;
    }
    str1++;
    str2++;
  }
  return 0;
}

char *s21_strerror(int errnum) {
  static const char *error_messages[] = ERRORS;
  static char buffer[100];
  if (errnum < 0 || errnum >= NUM_ERRORS) {
    sprintf(buffer, "Unknown error %d", errnum);
    return buffer;
  }
  return (char *)error_messages[errnum];
}
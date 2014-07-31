#ifndef DATATYPES_H
#define DATATYPES_H

    #include <vector>
    using namespace std;

    typedef struct
    {
        unsigned short  p1;
        unsigned long   p2;
    } TTEST_STRUCT_1;

    typedef struct
    {
        unsigned char   p1;
        char*           p2;
        unsigned long   p3;
        unsigned long   p4;
    } TTEST_STRUCT_2;

    typedef struct
    {
        char*           p1;
        char*           p2;
    } TTEST_STRUCT_3;

    typedef struct
    {
        unsigned char   p1;
        unsigned long   p2;
    } TTEST_STRUCT_4;

    typedef struct
    {
        unsigned char   p1;
        std::vector<TTEST_STRUCT_1> p2;
    } TTEST_STRUCT_5;

#endif // DATATYPES_H

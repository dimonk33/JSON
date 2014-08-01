#ifndef CJSONPACKER_H
#define CJSONPACKER_H

#include <string>
#include "datatypes.h"

using namespace std;

class CJsonPacker
{
public:
                    CJsonPacker     (void);
                    ~CJsonPacker    ();

    void            setBuf          (char*              buf,
                                     unsigned short     buf_size);
    unsigned short  packStruct      (TTEST_STRUCT_1*    data);
    unsigned short  packStruct      (char*              buf,
                                     unsigned short     buf_size,
                                     TTEST_STRUCT_1*    data);
    unsigned short  packStruct      (TTEST_STRUCT_2*    data);
    unsigned short  packStruct      (TTEST_STRUCT_3*    data);
    unsigned short  packStruct      (TTEST_STRUCT_4*    data);
    unsigned short  packStruct      (TTEST_STRUCT_5*    data);

private:
    typedef enum _TYPE_CONV
    {
        NONE,
        STRUCT1,
        STRUCT2,
        STRUCT3,
        STRUCT4,
        STRUCT5
    } TTYPE_CONV;

    char*           out_buf;
    unsigned short  out_len;
    unsigned short  out_buf_size;
    TTYPE_CONV      cur_type;
    unsigned short  cur_idx;
    std::string     cur_json;

    unsigned short  addInt          (char*              buf,
                                     unsigned short     buf_len,
                                     char*              name,
                                     int                val);
    unsigned short  addStr          (char*              buf,
                                     unsigned short     buf_len,
                                     char*              name,
                                     char*              val);
    unsigned short  putBuf          (char*              json);

};

#endif // CJSONPACKER_H

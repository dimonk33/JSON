#ifndef CJSONPARSER_H
#define CJSONPARSER_H

#include "datatypes.h"

class CJsonParser
{
public:
                    CJsonParser     (void);
                    ~CJsonParser    ();

    void            setBuf          (char*              buf,
                                     unsigned short     buf_size);
    unsigned short  packStruct1     (TTEST_STRUCT_1*    data);
    unsigned short  packStruct1     (char*              buf,
                                     unsigned short     buf_size,
                                     TTEST_STRUCT_1*    data);
    unsigned short  packStruct2     (TTEST_STRUCT_2*    data);
    unsigned short  packStruct3     (TTEST_STRUCT_3*    data);
    unsigned short  packStruct4     (TTEST_STRUCT_4*    data);
    unsigned short  packStruct5     (TTEST_STRUCT_5*    data);

private:
    char*           out_buf;
    unsigned short  out_len;
    unsigned short  out_buf_size;

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

#endif // CJSONPARCER_H

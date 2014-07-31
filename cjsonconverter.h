#ifndef CJSONCONVERTER_H
#define CJSONCONVERTER_H

#include "datatypes.h"

class CJsonConverter
{
public:
                    CJsonConverter     (void);
                    ~CJsonConverter    ();

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
    enum
    {

    };

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

#endif // CJSONCONVERTER_H

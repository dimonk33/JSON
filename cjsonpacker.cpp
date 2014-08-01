#include <string.h>
#include "frozen.h"
#include "cjsonpacker.h"

CJsonPacker::CJsonPacker(void)
{
    out_buf = 0;
    out_len = 0;
    out_buf_size = 0;

    cur_json = string();
    cur_idx = 0;
    cur_type = NONE;

}

CJsonPacker::~CJsonPacker()
{

}

void CJsonPacker::setBuf(char* buf, unsigned short buf_size)
{
    out_buf = buf;
    out_len = 0;
    out_buf_size = buf_size;
}

unsigned short CJsonPacker::packStruct(TTEST_STRUCT_1* data)
{
    if (!out_buf)
        return 0;

    if (cur_type != STRUCT1)
    {
        unsigned short  i = 0;
        char            jstr[64];

        i += json_emit_raw_str	(&jstr[i], sizeof(jstr) - i, "{");
        i += addInt             (&jstr[i], sizeof(jstr) - i, "struct1_p1", data->p1);
        i += json_emit_raw_str	(&jstr[i], sizeof(jstr) - i, ",");
        i += addInt             (&jstr[i], sizeof(jstr) - i, "struct1_p2", data->p2);
        i += json_emit_raw_str	(&jstr[i], sizeof(jstr) - i, "}");

        cur_json = string(jstr);
        cur_idx = 0;
        cur_type = STRUCT1;
    }

    cur_idx += putBuf((char*)cur_json.c_str() + cur_idx);

    return (cur_idx == cur_json.length());
}

unsigned short CJsonPacker::packStruct(char* buf, unsigned short buf_size, TTEST_STRUCT_1* data)
{
    if (!buf)
        return 0;

    unsigned short  i = 0;

    i += json_emit_raw_str	(&buf[i], buf_size - i, "{");
    i += addInt             (&buf[i], buf_size - i, "struct1_p1", data->p1);
    i += json_emit_raw_str	(&buf[i], buf_size - i, ",");
    i += addInt             (&buf[i], buf_size - i, "struct1_p2", data->p2);
    i += json_emit_raw_str	(&buf[i], buf_size - i, "}");

    return i;
}

unsigned short CJsonPacker::packStruct(TTEST_STRUCT_2* data)
{
    if (!out_buf)
        return 0;

    if (cur_type != STRUCT2)
    {
        unsigned short  i = 0;
        char            jstr[255];

        i += json_emit_raw_str	(&jstr[i], sizeof(jstr) - i, "{");
        i += addInt             (&jstr[i], sizeof(jstr) - i, "struct2_p1", data->p1);
        i += json_emit_raw_str	(&jstr[i], sizeof(jstr) - i, ",");
        i += addStr             (&jstr[i], sizeof(jstr) - i, "struct2_p2", data->p2);
        i += json_emit_raw_str	(&jstr[i], sizeof(jstr) - i, ",");
        i += addInt             (&jstr[i], sizeof(jstr) - i, "struct2_p3", data->p3);
        i += json_emit_raw_str	(&jstr[i], sizeof(jstr) - i, ",");
        i += addInt             (&jstr[i], sizeof(jstr) - i, "struct2_p4", data->p4);
        i += json_emit_raw_str	(&jstr[i], sizeof(jstr) - i, "}");

        cur_json = string(jstr);
        cur_idx = 0;
        cur_type = STRUCT2;
    }

    cur_idx += putBuf((char*)cur_json.c_str() + cur_idx);

    return (cur_idx == cur_json.length());
}

unsigned short CJsonPacker::packStruct(TTEST_STRUCT_3* data)
{
    if (!out_buf)
        return 0;

    if (cur_type != STRUCT3)
    {
        unsigned short  i = 0;
        char            jstr[255];

        i += json_emit_raw_str	(&jstr[i], sizeof(jstr) - i, "{");
        i += addStr             (&jstr[i], sizeof(jstr) - i, "struct3_p1", data->p1);
        i += json_emit_raw_str	(&jstr[i], sizeof(jstr) - i, ",");
        i += addStr             (&jstr[i], sizeof(jstr) - i, "struct3_p2", data->p2);
        i += json_emit_raw_str	(&jstr[i], sizeof(jstr) - i, "}");

        cur_json = string(jstr);
        cur_idx = 0;
        cur_type = STRUCT3;
    }

    cur_idx += putBuf((char*)cur_json.c_str() + cur_idx);

    return (cur_idx == cur_json.length());
}

unsigned short CJsonPacker::packStruct(TTEST_STRUCT_4* data)
{
    if (!out_buf)
        return 0;

    if (cur_type != STRUCT4)
    {
        unsigned short  i = 0;
        char            jstr[64];

        i += json_emit_raw_str	(&jstr[i], sizeof(jstr) - i, "{");
        i += addInt             (&jstr[i], sizeof(jstr) - i, "struct4_p1", data->p1);
        i += json_emit_raw_str	(&jstr[i], sizeof(jstr) - i, ",");
        i += addInt             (&jstr[i], sizeof(jstr) - i, "struct4_p2", data->p2);
        i += json_emit_raw_str	(&jstr[i], sizeof(jstr) - i, "}");

        cur_json = string(jstr);
        cur_idx = 0;
        cur_type = STRUCT4;
    }

    cur_idx += putBuf((char*)cur_json.c_str() + cur_idx);

    return (cur_idx == cur_json.length());
}

unsigned short CJsonPacker::packStruct(TTEST_STRUCT_5* data)
{
    if (!out_buf)
        return 0;

    if (cur_type != STRUCT5)
    {
        unsigned short  i = 0;
        char            jstr[512];

        i += json_emit_raw_str      (&jstr[i], sizeof(jstr) - i, "{");
        i += addInt                 (&jstr[i], sizeof(jstr) - i, "struct5_p1", data->p1);
        i += json_emit_raw_str      (&jstr[i], sizeof(jstr) - i, ",");
        i += json_emit_quoted_str	(&jstr[i], sizeof(jstr) - i, "struct5_p2");
        i += json_emit_raw_str		(&jstr[i], sizeof(jstr) - i, ":");
        i += json_emit_raw_str      (&jstr[i], sizeof(jstr) - i, "[");
        for (int j = 0; j < data->p2.size(); j++)
        {
            i += packStruct(&jstr[i], sizeof(jstr) - i, &data->p2.at(j));
            i += json_emit_raw_str	(&jstr[i], sizeof(jstr) - i, ",");
        }
        if (data->p2.size())
            i--;
        i += json_emit_raw_str      (&jstr[i], sizeof(jstr) - i, "]");
        i += json_emit_raw_str      (&jstr[i], sizeof(jstr) - i, "}");

        cur_json = string(jstr);
        cur_idx = 0;
        cur_type = STRUCT5;
    }

    cur_idx += putBuf((char*)cur_json.c_str() + cur_idx);

    return (cur_idx == cur_json.length());
}

unsigned short CJsonPacker::putBuf(char* json)
{
    int i = json_emit_raw_str(out_buf + out_len, out_buf_size - out_len, json);
    if (i < 0)
    {
        *(out_buf + out_buf_size - 1) = '\0';
        i = out_buf_size - out_len - 1;
    }
    out_len += i;
    return (unsigned short)i;
}

unsigned short CJsonPacker::addInt(char* buf, unsigned short buf_len, char* name, int val)
{
    unsigned short i = 0;
    i += json_emit_quoted_str	(buf + i, buf_len - i, name);
    i += json_emit_raw_str		(buf + i, buf_len - i, ":");
    i += json_emit_int      	(buf + i, buf_len - i, val);
    return i;
}

unsigned short CJsonPacker::addStr(char* buf, unsigned short buf_len, char* name, char* val)
{
    unsigned short i = 0;
    i += json_emit_quoted_str	(buf + i, buf_len - i, name);
    i += json_emit_raw_str		(buf + i, buf_len - i, ":");
    i += json_emit_quoted_str   (buf + i, buf_len - i, val);
    return i;
}

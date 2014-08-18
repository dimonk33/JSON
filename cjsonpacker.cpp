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

bool CJsonPacker::packStruct(TTEST_STRUCT_1* data)
{
    if (!out_buf)
        return false;

    if (cur_type != STRUCT1)
    {
        unsigned short  i = 0;
        char            jstr[64];

        cur_idx = 0;
        cur_json.clear();
        cur_type = STRUCT1;

        i += json_emit_raw_str	(jstr, sizeof(jstr), "{");
        cur_json.append(jstr);
        i += addInt             (jstr, sizeof(jstr), "struct1_p1", data->p1);
        cur_json.append(jstr);
        i += json_emit_raw_str	(jstr, sizeof(jstr), ",");
        cur_json.append(jstr);
        i += addInt             (jstr, sizeof(jstr), "struct1_p2", data->p2);
        cur_json.append(jstr);
        i += json_emit_raw_str	(jstr, sizeof(jstr), "},");
        cur_json.append(jstr);
    }

    return putBuf();
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
    i += json_emit_raw_str	(&buf[i], buf_size - i, "},");

    return i;
}

bool CJsonPacker::packStruct(TTEST_STRUCT_2* data)
{
    if (!out_buf)
        return false;

    if (cur_type != STRUCT2)
    {
        unsigned short  i = 0;
        char            jstr[64];

        cur_idx = 0;
        cur_json.clear();
        cur_type = STRUCT2;

        i += json_emit_raw_str	(jstr, sizeof(jstr), "{");
        cur_json.append(jstr);
        i += addInt             (jstr, sizeof(jstr), "struct2_p1", data->p1);
        cur_json.append(jstr);
        i += json_emit_raw_str	(jstr, sizeof(jstr), ",");
        cur_json.append(jstr);
        i += addStr             (jstr, sizeof(jstr), "struct2_p2", data->p2);
        cur_json.append(jstr);
        i += json_emit_raw_str	(jstr, sizeof(jstr), ",");
        cur_json.append(jstr);
        i += addInt             (jstr, sizeof(jstr), "struct2_p3", data->p3);
        cur_json.append(jstr);
        i += json_emit_raw_str	(jstr, sizeof(jstr), ",");
        cur_json.append(jstr);
        i += addInt             (jstr, sizeof(jstr), "struct2_p4", data->p4);
        cur_json.append(jstr);
        i += json_emit_raw_str	(jstr, sizeof(jstr), "},");
        cur_json.append(jstr);
    }

    return putBuf();
}

bool CJsonPacker::packStruct(TTEST_STRUCT_3* data)
{
    if (!out_buf)
        return false;

    if (cur_type != STRUCT3)
    {
        unsigned short  i = 0;
        char            jstr[64];

        cur_idx = 0;
        cur_json.clear();
        cur_type = STRUCT3;

        i += json_emit_raw_str	(jstr, sizeof(jstr), "{");
        cur_json.append(jstr);
        i += addStr             (jstr, sizeof(jstr), "struct3_p1", data->p1);
        cur_json.append(jstr);
        i += json_emit_raw_str	(jstr, sizeof(jstr), ",");
        cur_json.append(jstr);
        i += addStr             (jstr, sizeof(jstr), "struct3_p2", data->p2);
        cur_json.append(jstr);
        i += json_emit_raw_str	(jstr, sizeof(jstr), "},");
        cur_json.append(jstr);
    }

    return putBuf();
}

bool CJsonPacker::packStruct(TTEST_STRUCT_4* data)
{
    if (!out_buf)
        return false;

    if (cur_type != STRUCT4)
    {
        unsigned short  i = 0;
        char            jstr[64];

        cur_idx = 0;
        cur_json.clear();
        cur_type = STRUCT4;

        i += json_emit_raw_str	(jstr, sizeof(jstr), "{");
        cur_json.append(jstr);
        i += addInt             (jstr, sizeof(jstr), "struct4_p1", data->p1);
        cur_json.append(jstr);
        i += json_emit_raw_str	(jstr, sizeof(jstr), ",");
        cur_json.append(jstr);
        i += addInt             (jstr, sizeof(jstr), "struct4_p2", data->p2);
        cur_json.append(jstr);
        i += json_emit_raw_str	(jstr, sizeof(jstr), "},");
        cur_json.append(jstr);
    }

    return putBuf();
}

bool CJsonPacker::packStruct(TTEST_STRUCT_5* data)
{
    if (!out_buf)
        return false;

    if (cur_type != STRUCT5)
    {
        unsigned short  i = 0;
        char            jstr[128];

        cur_idx = 0;
        cur_json.clear();
        cur_type = STRUCT5;

        i += json_emit_raw_str      (jstr, sizeof(jstr), "{");
        cur_json.append(jstr);
        i += addInt                 (jstr, sizeof(jstr), "struct5_p1", data->p1);
        cur_json.append(jstr);
        i += json_emit_raw_str      (jstr, sizeof(jstr), ",");
        cur_json.append(jstr);
        i += json_emit_quoted_str	(jstr, sizeof(jstr), "struct5_p2");
        cur_json.append(jstr);
        i += json_emit_raw_str		(jstr, sizeof(jstr), ":");
        cur_json.append(jstr);
        i += json_emit_raw_str      (jstr, sizeof(jstr), "[");
        cur_json.append(jstr);
        if (data->p2.size())
        {
            for (int j = 0; j < data->p2.size(); j++)
            {
                i += packStruct(jstr, sizeof(jstr), &data->p2.at(j));
                cur_json.append(jstr);
            }
            cur_json.resize(cur_json.size() - 1);
            i--;
        }
        i += json_emit_raw_str      (jstr, sizeof(jstr), "]");
        cur_json.append(jstr);
        i += json_emit_raw_str      (jstr, sizeof(jstr), "},");
        cur_json.append(jstr);
    }

    return putBuf();
}

bool CJsonPacker::putBuf(void)
{
    int i = json_emit_raw_str(out_buf + out_len, out_buf_size - out_len, (char*)cur_json.c_str() + cur_idx);
    if (i < 0)
    {
        *(out_buf + out_buf_size - 1) = '\0';
        i = out_buf_size - out_len - 1;
    }
    else
        cur_type = NONE;
    cur_idx += i;
    out_len += i;

    return (cur_idx != cur_json.length());
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

#include "message.h"
int max_count_prefix=10;
Message::Message(string buf)
{
    unparse_buf=buf;
    prefix=new string[max_count_prefix];
    value=new string[max_count_prefix];
    real_size=0;
}
Message::Message(const Message &obj)
{
    unparse_buf=obj.unparse_buf;
    real_size=obj.real_size;
    prefix=new string[max_count_prefix];
    value=new string[max_count_prefix];
    for (int i=0;i<real_size;i++)
    {
        prefix[i]=obj.prefix[i];
        value[i]=obj.value[i];
    }
}
IMessage* Message::Copy()
{
    IMessage* newmes=new Message(*this);
    return newmes;
}


void Message::ReplacePart(string _prefix,string _value)
{
    int flag=0;
    for(int i=0;i<real_size;i++)
    {
        if (prefix[i]==_prefix)
        {
            value[i]=_value;flag=1;
        }
    }
    if (flag==0)
        AddPart(_prefix,_value);
}


void Message::AddPart(string _prefix,string _value)
{
    prefix[real_size]=_prefix;
    value[real_size]=_value;
    real_size++;
}


string Message::GetPart(string prefix)
{
    for (int i=0;i<real_size;i++)
    {
        if (this->prefix[i]==prefix)
        {
            return this->value[i];
        }
    }
    return "";
}


void Message::Parse()
{
    int i=0,j;
    string str;
    j=real_size;
    while (unparse_buf[i]!='#')
        i++;
    for(i;i<unparse_buf.length();i++)
    {
        if(unparse_buf[i]=='#')
        {
            continue;
        }
        while((unparse_buf[i]!='/')&&(unparse_buf[i]!='\0'))
        {
            prefix[j]=prefix[j]+unparse_buf[i];
            i++;
        }
        i++;
        while((unparse_buf[i]!='#')&&(unparse_buf[i]!='\0'))
        {
            value[j]=value[j]+unparse_buf[i];
            i++;
        }
        j++;
    }
    real_size=j;
}


string Message::Unparse()
{
    string str;
    for (int i=0;i<real_size;i++)
        str=str+'#'+prefix[i]+'/'+value[i];
    return str;
}


Message::~Message()
{
    delete [] value;
    delete [] prefix;
}

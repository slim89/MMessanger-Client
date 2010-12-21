#include "message.h"

Message::Message(QString buf)
{
    unparse_buf=buf;
    state=false;
}
int Message::NumOfPair()
{
    return key_value.size();
}
Message::Message(const Message &obj)
{
    unparse_buf=obj.unparse_buf;
    key_value=obj.key_value;
    state=obj.state;
}
IMessage* Message::Clone()
{
    IMessage* newmes=new Message(*this);
    return newmes;
}

void Message::ReplacePart(QString _prefix,QString _value)
{
    key_value[_prefix]=_value;
}


void Message::AddPart(QString _prefix,QString _value)
{
    key_value[_prefix]=_value;
}


QString Message::GetPart(QString _prefix)
{
    return key_value[_prefix];
}


void Message::Parse()//Modified by Andrey 16/12/2010  //Correct by Dmitry 16/12/2010
{
    int i=1;
    QString key,value;
   /* while (unparse_buf[i]!='#')// Править
    {
        if (unparse_buf[i]!='\0')//не актуально!!!!!!!ПРАВИТЬ!!!!!!!!!!!!!!!!!!
            i++;
        else
        {
            state=true;
            return;
        }
    }
    */
    //for(;i<unparse_buf.length();i++)
    while(i<unparse_buf.length())
    {
        if((unparse_buf[i]=='#') && (unparse_buf[i+1]=='\''))//экранируем тело сообщения и конец сообщения ' и / соттветственно
        {
            i++;
            continue;
        }
        while((unparse_buf[i]!='/'))
        {
            key+=unparse_buf[i];
            i++;
        }
        i++;
        while(((unparse_buf[i]!='#')||(unparse_buf[i+1]=='\''))&&(i!=unparse_buf.length()))
        {
            value+=unparse_buf[i];
            i++;
        }
        key_value[key]=value;
        key.clear();
        value.clear();
        if(i!=unparse_buf.length())
        {
            i++;
        }
    }
    state=true;
}


QString Message::Unparse()
{
    QString str;
    QMapIterator<QString, QString> it(key_value);
    while (it.hasNext())
    {
        it.next();
        str+='#'+it.key()+'/'+it.value();
    }
    return (str +"#/");//добавляем конец сообщения
}


Message::~Message()
{
    key_value.clear();
}

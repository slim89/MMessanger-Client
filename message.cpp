#include "message.h"

//CONSTRUCTOR-------------------------------------------------------
Message::Message(QString buf)
{
    unparse_buf=buf;
}

//NUMOFPAIR---------------------------------------------------------
int Message::NumOfPair()
{
    return key_value.size();
}

//CONSTRUCTOR OF COPY-----------------------------------------------
Message::Message(const Message &obj)
{
    unparse_buf=obj.unparse_buf;
    key_value=obj.key_value;
}

//CLONE-------------------------------------------------------------
IMessage* Message::Clone()
{
    IMessage* newmes=new Message(*this);
    return newmes;
}

//REPLACEPART-------------------------------------------------------
void Message::ReplacePart(QString _prefix,QString _value)
{
    key_value[_prefix]=_value;
}

//ADDPART-----------------------------------------------------------
void Message::AddPart(QString _prefix,QString _value)
{
    key_value[_prefix]=_value;
}

//GETPART-----------------------------------------------------------
QString Message::GetPart(QString _prefix)
{
    return key_value[_prefix];
}

//PARSE-------------------------------------------------------------
void Message::Parse()//Modified by Andrey 16/12/2010  //Correct by Dmitry 16/12/2010
{
    int i=1;
    QString key,value;
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
}

//UNPARSE------------------------------------------------------------
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
//DELETE PART
void Message::Delete(QString _prefix)
{
     qCritical()<<"DELETE PART";
     key_value.remove(_prefix);


}

//DESTRUCTOR---------------------------------------------------------
Message::~Message()
{
    key_value.clear();
}

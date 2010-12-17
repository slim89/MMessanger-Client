#ifndef MESSAGE_H
#define MESSAGE_H
#include <QString>
#include <QMap>
#include <QDebug>
#include <QObject>
class IMessage: public QObject
{
    Q_OBJECT
    public:
        //explicit IMessage(QObject *parent = 0);
        virtual void ReplacePart(QString,QString)=0;
        virtual void AddPart(QString,QString)=0;
        virtual QString GetPart(QString)=0;
        virtual void Parse()=0;
        virtual QString Unparse()=0;
        virtual IMessage* Clone()=0;
};

class Message:public IMessage
{
    protected:
        QString unparse_buf;
        QMap<QString, QString> key_value;
        bool state;
    public:
        void ReplacePart(QString,QString);
        Message(QString buf="");
        Message(const Message &);
        IMessage* Clone();
        void AddPart(QString,QString);
        QString GetPart(QString);
        void Parse();
        QString Unparse();
        int NumOfPair();
        ~Message();
};
#endif // MESSAGE_H

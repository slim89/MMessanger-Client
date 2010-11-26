#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <iostream>
using namespace std;

//class AQueue;
class IMessage
{
    public:
        virtual void ReplacePart(string,string)=0;
        virtual void AddPart(string,string)=0;
        virtual string GetPart(string)=0;
        virtual void Parse()=0;
        virtual string Unparse()=0;
        virtual IMessage* Copy()=0;
};
class Message:public IMessage
{
    protected:
        string unparse_buf;
        string* prefix;
        string* value;
        int real_size;
    public:
        void ReplacePart(string,string);
        Message(string);
        Message(const Message &);
        IMessage* Copy();
        void AddPart(string,string);
        string GetPart(string);
        void Write();
        void Parse();
        string Unparse();
        ~Message();
};

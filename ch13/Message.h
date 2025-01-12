#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <set>
#include <string>

using namespace std;

class Message;

class Folder
{
    private:
        set<Message *> messages;
        void add_to_Messages(const Folder &);
        void remove_from_Messages();
    public:
        void addMsg(Message *);
        void remMsg(Message *);
        Folder(const Folder &);
        Folder & operator=(const Folder &);
        ~Folder();
}
;

class Message
{
    friend class Folder;
    private:
        string contents;
        set<Folder*> folders;
        void add_to_Folders(const Message&);
        void remove_from_Folders();
    public:
        explicit Message(const string &str = ""): 
            contents(str) {}
        Message(const Message &);
        Message& operator=(const Message &);
        Message(Message &&);
        Message& operator=(Message &&);
        ~Message();
        void save(Folder &);
        void remove(Folder &);
        void move_Folders(Message *);
};

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
    for (auto f: m.folders)
    {
        f->addMsg(this);
    }
}

void Message::remove_from_Folders()
{
    for (auto f: folders)
    {
        f->remMsg(this);
    }
}

void Message::move_Folders(Message *m)
{
    folders = std::move(m->folders);
    for (auto f : folders)
    {
        f->remMsg(m);
        f->addMsg(this);
    }
    m->folders.clear();
}

Message::Message(const Message &m)
    :contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

Message::~Message()
{
    remove_from_Folders();
}

Message & Message::operator=(const Message &rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

Message::Message(Message &&m) :
    contents(std::move(m.contents))
{
    move_Folders(&m);
}

Message& Message::operator=(Message &&rhs)
{
    if (this != &rhs)
    {
        remove_from_Folders();
        contents = std::move(rhs.contents);
        move_Folders(&rhs);
    }
    return *this;
}

void Folder::addMsg(Message *m)
{
    messages.insert(m);
}

void Folder::remMsg(Message *m)
{
    messages.erase(m);
}

void Folder::add_to_Messages(const Folder &f)
{
    for (auto m : f.messages)
    {
        m->save(*this);
    }
}

void Folder::remove_from_Messages()
{
    while (!messages.empty())
        (*messages.begin())->remove(*this);
}

Folder::Folder(const Folder &f) : messages(f.messages)
{
    add_to_Messages(f);
}

Folder & Folder::operator=(const Folder &rhs)
{
    remove_from_Messages();
    messages = rhs.messages;
    add_to_Messages(rhs);
    return *this;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}

#endif
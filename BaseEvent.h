#ifndef CBASEEVENT_H
#define CBASEEVENT_H

#include <QEvent>

#include <typeinfo>

class CBaseEvent: public QEvent

{
public:
    CBaseEvent();
    virtual ~CBaseEvent();


    virtual std::string getType() = 0;
    virtual CBaseEvent* copy() = 0;

    template<class Event>
    static std::string Type()
    {
        return typeid(Event).name();
    }

};


#endif // CBASEEVENT_H

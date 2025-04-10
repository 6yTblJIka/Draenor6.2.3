////////////////////////////////////////////////////////////////////////////////
//
// Project-Hellscream https://hellscream.org
// Copyright (C) 2018-2020 Project-Hellscream-6.2
// Discord https://discord.gg/CWCF3C9
//
////////////////////////////////////////////////////////////////////////////////

#ifndef __EVENTPROCESSOR_H
#define __EVENTPROCESSOR_H

#include "Define.h"
#include "Common.h"

// Note. All times are in milliseconds here.

class BasicEvent
{
    public:
        BasicEvent() { to_Abort = false; }
        virtual ~BasicEvent() {}                              // override destructor to perform some actions on event removal


        // this method executes when the event is triggered
        // return false if event does not want to be deleted
        // e_time is execution time, p_time is update interval
        virtual bool Execute(uint64 /*e_time*/, uint32 /*p_time*/) { return true; }

        virtual bool IsDeletable() const { return true; }   // this event can be safely deleted

        virtual void Abort(uint64 /*e_time*/) {}            // this method executes when the event is aborted

        bool to_Abort;                                      // set by externals when the event is aborted, aborted events don't execute
        // and get Abort call when deleted

        // these can be used for time offset control
        uint64 m_addTime;                                   // time when the event was added to queue, filled by event handler
        uint64 m_execTime;                                  // planned time of next execution, filled by event handler
};

class GenericDelayedEvent : public BasicEvent
{
public:
    GenericDelayedEvent(std::function<void()> p_Lambda) :
        BasicEvent(), m_Lambda(p_Lambda) {}

    virtual ~GenericDelayedEvent() { }

    virtual bool Execute(uint64 /*p_EndTime*/, uint32 /*p_Time*/)
    {
        m_Lambda();
        return true;
    }

    virtual void Abort(uint64 p_EndTime) { }

private:
    std::function<void()> m_Lambda;
};

typedef std::multimap<uint64, BasicEvent*> EventList;

class EventProcessor
{
    public:
        EventProcessor();
        ~EventProcessor();

        void Update(uint32 p_time);
        void KillAllEvents(bool force);
        void AddEvent(BasicEvent* Event, uint64 e_time, bool set_addtime = true);
        uint64 CalculateTime(uint64 t_offset) const;
    protected:
        uint64 m_time;
        EventList m_events;
        bool m_aborting;
};
#endif

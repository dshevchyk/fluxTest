#ifndef CBASESTORE_H
#define CBASESTORE_H

class CBaseEvent;
class IFilter;
class CBaseStore
{
public:
    CBaseStore();
    virtual ~CBaseStore();
    typedef std::map<int, IFilter* > BaseFiltersMap_t;

    virtual void Handle(CBaseEvent* event);
    virtual void AddFilter(IFilter* filter);
protected:
    BaseFiltersMap_t m_mapFilters;
};

#endif // CBASESTORE_H

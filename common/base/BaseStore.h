#ifndef CBASESTORE_H
#define CBASESTORE_H

#include <array>
#include <functional>

class CBaseEvent;
class IFilter;
class IExecutor;
class CBaseStore
{
public:
    virtual ~CBaseStore();
    //typedef std::map<int, IFilter* > BaseFiltersMap_t;
    virtual void Handle(const std::shared_ptr<CBaseEvent>& event);
    virtual void AddFilter(IFilter* filter);
    virtual void Execute(std::function<void(void)> callback);
protected:
    CBaseStore();
protected:
    //BaseFiltersMap_t m_mapFilters;
    std::array<IFilter*, 1000> m_arrayFilters = {nullptr};
    std::shared_ptr<IExecutor> m_pExecutor;
};


class CAsynkStore: public CBaseStore
{
protected:
    CAsynkStore();
};

#endif // CBASESTORE_H

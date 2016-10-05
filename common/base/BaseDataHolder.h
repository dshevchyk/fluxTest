#ifndef CBASEDATAHOLDER_H
#define CBASEDATAHOLDER_H

#include <mutex>
#include <memory>

#define POKER_DATA_HOLDER_PROPERTY(Type, name, Getter, Setter, DefaultValue)\
public:\
    void Setter( const Type& value ){\
        m_##name = value;\
    }\
    const Type& Getter() const {\
        return m_##name;\
    }\
private:\
    Type m_##name = DefaultValue;\



struct BaseDataHolder
{
    std::mutex m_Mutex;
};

template<class DataType>
class CPReadDataHolder
{
public:
    CPReadDataHolder(DataType *pData): m_pData(pData) { m_pData->m_Mutex.lock(); }
    CPReadDataHolder(const CPReadDataHolder &pd) { m_pData = pd.m_pData; m_pData->m_Mutex.lock(); }
    virtual ~CPReadDataHolder(void) { m_pData->m_Mutex.unlock(); }

    const DataType * data() const { return m_pData; }

    const DataType *operator->() const { return m_pData; }
protected:
    DataType* m_pData;
};


template<class DataType>
class CPWriteDataHolder
{
public:
    CPWriteDataHolder(DataType *pData): m_pData(pData) {
        m_pData->m_Mutex.lock();
    };
    CPWriteDataHolder(const CPWriteDataHolder &pd) {
        m_pData = pd.m_pData;
        m_pData->m_Mutex.lock();
    }
    virtual ~CPWriteDataHolder(void) { m_pData->m_Mutex.unlock(); }

    DataType * data() const { return m_pData; }

    DataType *operator->() const { return m_pData; }
protected:
    DataType* m_pData;
};


template<class DataHolderType>
class CDataHolder
{
public:

    using WriteDataHolderType = CPWriteDataHolder<DataHolderType>;
    using ReadDataHolderType = CPReadDataHolder<DataHolderType>;
    using WriteDataHolderPtr = std::shared_ptr<WriteDataHolderType>;
    using ReadDataHolderPtr = std::shared_ptr<ReadDataHolderType>;
    CDataHolder(): m_pData(new DataHolderType())
    {

    }
    ReadDataHolderPtr GetReadData(){
        return std::make_shared<ReadDataHolderType>(CPReadDataHolder<DataHolderType>(m_pData));
    }
protected:
    WriteDataHolderPtr GetWriteData(){
        return std::make_shared<WriteDataHolderType>(m_pData);
    }
private:
    DataHolderType* m_pData;

};


#endif // CBASEDATAHOLDER_H

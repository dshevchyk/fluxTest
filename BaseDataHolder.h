#ifndef CBASEDATAHOLDER_H
#define CBASEDATAHOLDER_H

#include <QReadWriteLock>
#include <QQuickItem>

#include "EventThreadInvoker.h"

#define POKER_UI_PROPERTY(Type, QmlName, Setter, NotifySignal, DefaultValue)\
public:\
    Q_PROPERTY(Type QmlName READ Get##QmlName WRITE Setter NOTIFY NotifySignal)\
    void Setter( const Type& value ){\
        Invoke([this, value]()\
        {\
            m_##QmlName = value;\
            emit NotifySignal();\
        });\
    }\
private:\
    Type m_##QmlName = DefaultValue;\
    Type Get##QmlName(){\
        return m_##QmlName;\
    }\


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

class CBaseUiModel:  public CQtEventThreadInvoker<QQuickItem>
{
    Q_OBJECT
public:


    CBaseUiModel(): CQtEventThreadInvoker<QQuickItem>(nullptr)
    {
        moveToThread(QApplication::instance()->thread());
    }
};

struct BaseDataHolder
{
    QReadWriteLock m_Mutex;
};

template<class DataType>
class CPReadDataHolder
{
public:
    CPReadDataHolder(DataType *pData): m_pData(pData) { m_pData->m_Mutex.lockForRead(); };
    CPReadDataHolder(const CPReadDataHolder &pd) { m_pData = pd.m_pData; m_pData->m_Mutex.lockForRead(); }
    virtual ~CPReadDataHolder(void) { m_pData->m_Mutex.unlock(); };

    const DataType * data() const { return m_pData; }

protected:
    DataType* m_pData;
};


template<class DataType>
class CPWriteDataHolder
{
public:
    CPWriteDataHolder(DataType *pData): m_pData(pData) {
        m_pData->m_Mutex.lockForWrite();
    };
    CPWriteDataHolder(const CPWriteDataHolder &pd) {
        m_pData = pd.m_pData;
        m_pData->m_Mutex.lockForWrite();
    }
    virtual ~CPWriteDataHolder(void) { m_pData->m_Mutex.unlock(); }

    DataType * data() const { return m_pData; }

protected:
    DataType* m_pData;
};


template<class ModelType>
class CUiModelHolder
{

public:
    ~CUiModelHolder()
    {
        m_UiData->deleteLater();
    }
    ModelType* ui()
    {
        return m_UiData;
    }
private:
    ModelType* m_UiData = new ModelType();
};

template<class DataHolderType>
class CDataHolder
{
public:
    using WriteDataHolderPtr = std::shared_ptr<CPWriteDataHolder<DataHolderType>>;
    using ReadDataHolderPtr = std::shared_ptr<CPReadDataHolder<DataHolderType>>;
    CDataHolder(): m_pData(new DataHolderType())
    {

    }
    ReadDataHolderPtr GetReadData(){
        return std::make_shared<CPReadDataHolder<DataHolderType>>(CPReadDataHolder<DataHolderType>(m_pData));
    }
protected:
    WriteDataHolderPtr GetWriteData(){
        return std::make_shared<CPWriteDataHolder<DataHolderType>>(m_pData);
    }


private:
    DataHolderType* m_pData;

};


#endif // CBASEEVENT_H

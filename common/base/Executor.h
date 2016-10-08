#ifndef IEXECUTOR_H
#define IEXECUTOR_H

class IExecutor
{
public:
    typedef std::function<void(void)> Callback;
    virtual void Execute(const Callback &callback) = 0;
protected:
};

class CSyncExecutor: public IExecutor
{
public:
    void Execute(const IExecutor::Callback &callback) override
    {
        callback();
    }
protected:
};



#endif // IEXECUTOR_H

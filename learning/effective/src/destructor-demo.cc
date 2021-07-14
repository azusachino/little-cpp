#include <vector>
#include <exception>
#include <cstdlib>

class Widget
{
public:
    Widget() = default;
    ~Widget()
    {
        throw std::bad_exception();
    }
};

void doSomething()
{
    std::vector<Widget> v; // v destructs here
    // 在两个异常同时存在的情况下，程序若不是结束执行
}

class DBConnection
{
public:
    static DBConnection create();

    void close();
};

class DBConn
{
public:
    DBConn(DBConnection db) : db(db) {}

    ~DBConn() // ensure connection closed
    {
        db.close();
    }

private:
    DBConnection db;
};

void doSomething2()
{
    DBConn dbc(DBConnection::create());
    // 方法结束之后，dbc对象被销毁，自动为DBConnection对象调用close
}

DBConn::~DBConn()
{
    try
    {
        db.close();
    }
    catch (std::exception &e)
    {
        std::abort();
    }
}

class DBConnNew
{
public:
    void close()
    {
        db.close();
        closed = true;
    }
    ~DBConnNew()
    {
        if (!closed)
        {
            try
            {
                db.close();
            }
            catch (std::exception &e)
            {
                // ignored exception, do some record
            }
        }
    }

private:
    DBConnection db;
    bool closed;
};
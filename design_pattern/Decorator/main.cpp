#include <iostream>
using namespace std;

void print(char* str)
{
    cout<<"├───────────────────────────────"<<endl
        <<"│"<<str<<":"<<endl;
}

// 定义一个抽象基类absTable（Component）
class absTable
{
public:
    virtual void putTable() = 0;
};

// 定义具体的表格absTable(ConcreteComponent)
class BaseTable:public absTable
{
public:
    virtual void putTable()
    {
        print("姓名");
        print("性别");
        print("学历");
        print("年龄");
        cout<<"└───────────────────────────────"<<endl;
    }
};

// 定义抽象Decorator
class Decorator:public absTable
{
public:
    Decorator(absTable* concrateTb):mpAbsTable(concrateTb){}

    virtual void putTable()
    {
        mpAbsTable->putTable();
    }
private:
    absTable* mpAbsTable;
};

// 定义具体的装饰EnglishDcrt、CurWage、Experience（ConcreteDecoratorA、B、C)
class EnglishDcrt:public Decorator
{
public:
    EnglishDcrt(absTable* pTb):Decorator(pTb){}

    virtual void putTable()
    {
        print("英语等级");
        Decorator::putTable();
    }
};

class CurWage:public Decorator
{
public:
    CurWage(absTable* pTb):Decorator(pTb){}

    virtual void putTable()
    {
        print("当前薪水");
        Decorator::putTable();
    }
};

class Experience:public Decorator
{
public:
    Experience(absTable* pTb):Decorator(pTb){}

    virtual void putTable()
    {
        print("项目经验");
        Decorator::putTable();
    }
};

//动态的给一个对象添加一些额外的职责！
//层层包装，增强功能。这就是装饰模式的要旨！
//接口稳定不变！
int main()
{
    BaseTable pro1;
    cout<<"初始表格："<<endl<<endl;
    pro1.putTable();

    cout<<"新表格1："<<endl<<endl;
    EnglishDcrt eng(&pro1);
    eng.putTable();

    cout<<"新表格2："<<endl<<endl;
    CurWage wg(&eng);
    wg.putTable();

    cout<<"新表格3："<<endl<<endl;
    Experience ex(&wg);
    ex.putTable();
}
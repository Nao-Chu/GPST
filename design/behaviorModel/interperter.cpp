/********************************************************************
    > File Name: interperter.cpp
    > Author: zzp
    > Created Time: 2020年03月18日 星期三 19时11分54秒
 *******************************************************************/

#include<iostream>
using namespace std;

class Context
{
public:
	Context(int num)
	{
		m_num = num;
	}
	int getNum()
	{
		return m_num;
	}
	int getRes()
	{
		return m_res;
	}
	void setNum(int num)
	{
		m_num = num;
	}
	void setRes(int res)
	{
		m_res = res;
	}

private:
	int m_num;
	int m_res;
};

class Expression
{
public:
	Expression(Context *context)
	{
		m_context = context;
	}
	virtual void interpreter() = 0;

protected:
	Context *m_context;
};

class PlusExpression : public Expression
{
public:
	PlusExpression(Context *context) : Expression(context)
	{
	}
	virtual void interpreter()
	{
		m_context->setRes(m_context->getNum() + 1);
		m_context->setNum(m_context->getNum() + 1);
	}
};

class MinusExpression : public Expression
{
public:
	MinusExpression(Context *context) : Expression(context)
	{
	}
	virtual void interpreter()
	{
		m_context->setRes(m_context->getNum() - 1);
		m_context->setNum(m_context->getNum() - 1);
	}
};

class ResultExpression
{
public:
	void doing(Expression *m_e,Context *m_c)
	{
		m_e->interpreter();
		cout << m_c->getRes() << endl;
	}
};

int main()
{
	Context *context = new Context(10);
	ResultExpression *re = new ResultExpression();

	Expression *plusExpre = new PlusExpression(context);
	Expression *minusExpre = new MinusExpression(context);

	re->doing(plusExpre,context);
	re->doing(minusExpre,context);

	delete minusExpre;
	delete plusExpre;
	delete re;
	delete context;
	return 0;
}

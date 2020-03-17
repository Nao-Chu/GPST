/********************************************************************
    > File Name: command.cpp
    > Author: zzp
    > Created Time: 2020年03月17日 星期二 23时38分42秒
 *******************************************************************/

#include<iostream>
#include<list>
using namespace std;

class Doctor
{
public:
	void treat_eye()
	{
		cout << "treat_eye" << endl;
	}

	void treat_nose()
	{
		cout << "treat_nose" << endl;
	}
};

class Command
{
public:
	virtual void treat() = 0;
};

class CommandTreatEye : public Command
{
public:
	CommandTreatEye(Doctor *doctor)
	{
		m_doctor = doctor;
	}
	virtual void treat()
	{
		m_doctor->treat_eye();
	}
private:
	Doctor *m_doctor;
};

class CommandTreatNose : public Command
{
public:
	CommandTreatNose(Doctor *doctor)
	{
		m_doctor = doctor;
	}
	virtual void treat()
	{
		m_doctor->treat_nose();
	}
private:
	Doctor *m_doctor;
};

class BeautyNurse
{
public:
	BeautyNurse()
	{
		m_list.clear();
	}
	void setCommand(Command *command)
	{
		m_list.push_back(command);
	}
	void SubmittedCase()
	{
		list<Command *>::iterator it = m_list.begin();
		for (it = m_list.begin(); it != m_list.end(); it++)
		{
			(*it)->treat();
		}
	}
private:
	list<Command *> m_list;
};

int main()
{
	Doctor *doctor = new Doctor;
	Command *command1 = new CommandTreatNose(doctor);
	Command *command2 = new CommandTreatEye(doctor);
	BeautyNurse *beautynurse = new BeautyNurse();
	beautynurse->setCommand(command1);
	beautynurse->setCommand(command2);
	beautynurse->setCommand(command1);
	beautynurse->SubmittedCase();

	delete beautynurse;
	delete command2;
	delete command1;
	delete doctor;

	return 0;
}

int main01()
{
	Doctor *doctor = new Doctor;
	CommandTreatEye *eye = new CommandTreatEye(doctor);
	eye->treat();
	CommandTreatNose *nose = new CommandTreatNose(doctor);
	nose->treat();
	return 0;
}

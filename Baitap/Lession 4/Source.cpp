#include <conio.h>
#include <cstdio>
#include <iostream>

class StateBase
{
public:
	virtual StateBase* GetNextState() = 0;
	virtual StateBase* GetPreviousState() = 0;
	virtual    char* ToString() = 0;
};
class Locked : public StateBase
{
public:
	virtual StateBase* GetNextState();
	virtual StateBase* GetPreviousState();
	virtual    char* ToString() {
		return " Locked";
	}
};

class Closed : public StateBase
{
public:
	virtual StateBase* GetNextState();
	virtual StateBase* GetPreviousState();
	virtual    char* ToString() {
		return "Closed";
	}
};

class Opened : public StateBase
{
public:
	virtual StateBase* GetNextState();
	virtual StateBase* GetPreviousState();
	virtual    char* ToString() {
		return "Opened";
	}
};


StateBase* Locked::GetNextState() {
	return new Closed();
}
StateBase* Locked::GetPreviousState() {
	return new Closed();
}

StateBase* Closed::GetNextState() {
	return new Opened();
}
StateBase* Closed::GetPreviousState() {
	return new Locked();
}

StateBase* Opened::GetNextState() {
	return new Closed();
}
StateBase* Opened::GetPreviousState() {
	return new Closed();
}

class Door
{
public:
	Door() {}
	Door(StateBase* pContext) {
		m_pState = pContext;
	}
	~Door() {
		delete m_pState;
	}
	void StateChanged1() {
		if (m_pState) {
			StateBase* pState = m_pState->GetNextState();
			delete m_pState;
			m_pState = pState;
		}
	}void StateChanged2() {
		if (m_pState) {
			StateBase* pState = m_pState->GetPreviousState();
			delete m_pState;
			m_pState = pState;
		}
	}
	char* GetStateName() {
		return m_pState->ToString();
	}
protected:
	StateBase* m_pState;
};



void main()
{

	Door objSun(new Closed);
	printf("The door is %s !!!\n\n", objSun.GetStateName());

	objSun.StateChanged1();
	printf("Next State is %s !!!\n\n", objSun.GetStateName());

	objSun.StateChanged2();objSun.StateChanged2();
	printf("Previous State is %s !!!\n\n", objSun.GetStateName());


	system("pause");

}
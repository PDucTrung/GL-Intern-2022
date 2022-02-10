#include <conio.h>
#include <cstdio>
#include <iostream>

class StateBase
{
public:
	virtual StateBase* GetNextState() = 0;
	virtual StateBase* GetNextState2() = 0;
	virtual    char* ToString() = 0;
};
class Locked : public StateBase
{
public:
	virtual StateBase* GetNextState();
	virtual StateBase* GetNextState2();
	virtual    char* ToString() {
		return " Locked";
	}
};

class Closed : public StateBase
{
public:
	virtual StateBase* GetNextState();
	virtual StateBase* GetNextState2();
	virtual    char* ToString() {
		return "Closed";
	}
};

class Opened : public StateBase
{
public:
	virtual StateBase* GetNextState();
	virtual StateBase* GetNextState2();
	virtual    char* ToString() {
		return "Opened";
	}
};


StateBase* Locked::GetNextState() {
	return new Closed();
}
StateBase* Locked::GetNextState2() {
	return new Closed();
}

StateBase* Closed::GetNextState() {
	return new Opened();
}
StateBase* Closed::GetNextState2() {
	return new Locked();
}

StateBase* Opened::GetNextState() {
	return new Closed();
}
StateBase* Opened::GetNextState2() {
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
			StateBase* pState = m_pState->GetNextState2();
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

	Door objDoor(new Closed);
	printf("The door is %s !!!\n\n", objDoor.GetStateName());

	objDoor.StateChanged1();
	printf("The door is %s !!!\n\n", objDoor.GetStateName());

	objDoor.StateChanged2();objDoor.StateChanged2();
	printf("The door is %s !!!\n\n", objDoor.GetStateName());

	system("pause");

}

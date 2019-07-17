
//System Include Files


//Own Include Files
#include "CMyStateMachine.h"

//Method Implementations

CMyStateMachine::CMyStateMachine()
{
  this->m_State = ISIDLE;
}

t_state CMyStateMachine::getState()
{
	return this->m_State;
}

void CMyStateMachine::setState(t_state CurrentState)
{
	this->m_State = CurrentState;
}

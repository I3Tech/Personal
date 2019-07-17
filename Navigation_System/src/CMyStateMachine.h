

#ifndef CMYSTATEMACHINE_H
#define CMYSTATEMACHINE_H

typedef enum {ISIDLE, ISWAITING_DB_NAME, ISWAITING_DB_BEGIN, ISWAITING_ATTR_NAME, ISWAITING_NAME_SEP,ISWAITING_VALUE, IS_WAITING_END} t_state;

class CMyStateMachine {

private:
	t_state m_State;
public:
	CMyStateMachine();
	void setState(t_state CurrentState);
	t_state getState();
};
/********************
 **  CLASS END
 *********************/
#endif /* CMYSTATEMACHINE_H */

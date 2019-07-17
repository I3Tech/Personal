

#ifndef CGPSSENSOR_H_
#define CGPSSENSOR_H_

/*Include Standard Libraries here*/
#include "CWaypoint.h"

class CGPSSensor : public CWaypoint
{
public:
	/*
	 * Constructor    --> CGPSSensor
	 * Description --> No parameters to initialize. Do nothing
	 * @param input : NONE
	 * @param output: NONE
	 */
    CGPSSensor();

    /*
     * Function    --> getCurrentPosition()
     * Description --> To get the current position ( latitude and longitude) of a place
     *                 by the user
     * @param input : NONE
     * @param output: CWaypoint -> Current Position
     */
    CWaypoint getCurrentPosition();
};

#endif /* CGPSSENSOR_H_ */

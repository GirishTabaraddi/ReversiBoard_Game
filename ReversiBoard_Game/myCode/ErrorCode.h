/**
 * ErrorCode.h
 *
 *  Created on: 14-Nov-2023
 *      Author: Girish
 */

#ifndef ERRORCODE_H_
#define ERRORCODE_H_

typedef enum
{
	RC_INIT,
	RC_OK,
	RC_BADPARAM,
	RC_NOMEMORY,
	RC_INVALID_MOVE,
	RC_STONE_AVAILABLE,
	RC_NO_STONE,
	RC_STATE_UNAVAILABLE,
	RC_ERROR

}RC_t;



#endif /* ERRORCODE_H_ */

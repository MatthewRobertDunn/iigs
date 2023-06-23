#ifndef TOOLBOX_H
#define TOOLBOX_H

#asm
TOOL MACRO INDEX, ERROR
		LDX	INDEX         ; load tool call #
		JSL	$E10000        ; go to dispatcher
		STA	ERROR;
	MACEND

PULL_LONG MACRO RESULT
		PLA				   ;pull first 16bits of result
		STA RESULT 
		PLA				   ;second 16bits of result
		LDX #2 
		STA RESULT, X
	MACEND

PUSH_LONG MACRO RESULT
		LDX #2
		PHA
		LDA RESULT, X
		LDA RESULT
		PHA
	MACEND

#endasm


void CheckToolError(unsigned int tool_error)
{
	if(tool_error){
		#asm
			LDA %%tool_error
			BRK
		#endasm
	}
}
	
int _tool(unsigned int tool) {
	unsigned int tool_error = 0x001;
	#asm
		LDX	%%tool         ; load tool call #
		JSL	$E10000        ; go to dispatcher
		STA	%%tool_error;
	#endasm
	CheckToolError(tool_error);
	return 1;
}

int _TLStartUp(void){
	return _tool(0x201);
}


unsigned int userId = 0;
//returns a userID
unsigned int _MMStartup(void){
	unsigned int tool = 0x202;
	unsigned int tool_error = 0x001;
	unsigned int result = 0;
	#asm
		PEA #0  ;16 bit result
		TOOL	%%tool, %%tool_error
		PLA				   ;pull first 16bits of result
		STA %%result 
	#endasm
	CheckToolError(tool_error);

	userId = result;
	return result;
}

int _HLock(unsigned long handle) {
	unsigned int tool = 0x2002;
	unsigned int tool_error = 0x001;
	#asm
		PUSH_LONG %%handle
		TOOL	%%tool, %%tool_error
	#endasm
	CheckToolError(tool_error);
	return 1;
	
}


unsigned long _GetHandleSize (unsigned long handle) {
	unsigned int tool = 0x1802;
	unsigned int tool_error = 0x001;
	unsigned long result = 0;
	
	#asm
		PUSH_LONG %%result	; Leave space for result
		PUSH_LONG %%handle
		TOOL %%tool, %%tool_error
		PULL_LONG %%result;
	#endasm
	CheckToolError(tool_error);
	return result;
}

unsigned char ** _newHandle(unsigned long numberBytes) {
	unsigned int tool = 0x902;
	unsigned int tool_error = 0x001;
	unsigned char ** result = 0;
	unsigned int attributes = 0x8000;
	unsigned int uid = userId;
	unsigned long actualBytes = 0;
	
	#asm
		PUSH_LONG %%result	; Leave space for result
		PUSH_LONG %%numberBytes
		PEI %%uid
		PEI %%attributes
		PUSH_LONG %%result ; Unused
		TOOL %%tool, %%tool_error
		PULL_LONG %%result;
	#endasm
	CheckToolError(tool_error);
	
	actualBytes = _GetHandleSize((unsigned long)result);
	
	if(numberBytes != actualBytes) {
		CheckToolError(0x99);
	}

	if(*result == 0) {
		CheckToolError(0x999);
	}
	
	//_HLock(result);
	return result;
}

unsigned long _multiply(int x, int y) {
	unsigned int tool = 0x90B;
	unsigned int tool_error = 0x001;
	unsigned long result = 0;
	#asm
		PEA #0  ;Push immediate two 16bit words to leave space for result
		PEA #0
		PEI %%x ;Our two parameters
		PEI %%y
		;LDX	%%tool         ; load tool call #
		;JSL	$E10000        ; go to dispatcher
		TOOL	%%tool, %%tool_error
		PULL_LONG	%%result
	#endasm
	CheckToolError(tool_error);
	return result;
}

#endif
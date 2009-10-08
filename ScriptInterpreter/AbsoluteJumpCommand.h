#pragma once
#include "ICommand.h"
#include "CommandsDictionary.h"


class CAbsoluteJumpCommand : public IScriptCommand
{
public:
	CAbsoluteJumpCommand(void);
	~CAbsoluteJumpCommand(void);

protected:
	virtual ECommandResult OnCommandImplementation(IN int ContextLine, IN std::string CommandWord, IN std::vector<std::string> CommandArguments, OUT void *&Element, OUT EElementType &ElementType);
};

#pragma once

class CBaseGameEntity;

class CState
{
public:
	CState() {}
	~CState() {}
	virtual void Enter(CBaseGameEntity*) = 0;
	virtual void Execute(CBaseGameEntity*) = 0;
	virtual void Exit(CBaseGameEntity*) = 0;
};


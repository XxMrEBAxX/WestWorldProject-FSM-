#pragma once
#include <string>

class CState;
class CBaseGameEntity
{
public:
	CBaseGameEntity() {}
	~CBaseGameEntity() {}
	virtual void update() = 0;
	virtual void changeState(CState*) = 0;
#pragma region CMiner
	virtual int GetGoldCarried() = 0;
	virtual void SetGoldCarried(int) = 0;
	//
	virtual int GetMoneyInBank() = 0;
	virtual void SetMoneyInBank(int) = 0;
	//
	virtual int GetThirst() = 0;
	virtual void SetThirst(int) = 0;
	//
	virtual int GetFatigue() = 0;
	virtual void SetFatigue(int) = 0;
	//
	virtual std::string GetName() = 0;
#pragma endregion
};


#pragma once
#include "CState.h"
#include "CBaseGameEntity.h"

class CMiner;
class CEnterMineAndForNugget : public CState
{
	CEnterMineAndForNugget() {}
public:
	static CEnterMineAndForNugget* getInstance();
	void Enter(CBaseGameEntity* miner);
	void Execute(CBaseGameEntity* miner);
	void Exit(CBaseGameEntity* miner);
};

class CVisitBankAndDepositGold : public CState
{
	CVisitBankAndDepositGold() {}
public:
	static CVisitBankAndDepositGold* getInstance();
	void Enter(CBaseGameEntity* miner);
	void Execute(CBaseGameEntity* miner);
	void Exit(CBaseGameEntity* miner);
};

class CGoHomeAndSleepTilRested : public CState
{
	CGoHomeAndSleepTilRested() {}
public:
	static CGoHomeAndSleepTilRested* getInstance();
	void Enter(CBaseGameEntity* miner);
	void Execute(CBaseGameEntity* miner);
	void Exit(CBaseGameEntity* miner);
};

class CQuenchThirst : public CState
{
	CQuenchThirst() {}
public:
	static CQuenchThirst* getInstance();
	void Enter(CBaseGameEntity* miner);
	void Execute(CBaseGameEntity* miner);
	void Exit(CBaseGameEntity* miner);
};



#include "CMinerStates.h"
#include "CBaseGameEntity.h"
#include <iostream>

using namespace std;

CEnterMineAndForNugget* CEnterMineAndForNugget::getInstance()
{
	static CEnterMineAndForNugget* instance = NULL;
	if (instance == nullptr)
		instance = new CEnterMineAndForNugget();
	return instance;
}

void CEnterMineAndForNugget::Enter(CBaseGameEntity* miner)
{
	cout << miner->GetName() + ": Arrived Mine." << endl;
}

void CEnterMineAndForNugget::Execute(CBaseGameEntity* miner)
{
	// is tired? is thirst? is have many gold?
	if (miner->GetFatigue() >= 10)
	{
		cout << miner->GetName() + ": I tired. go back my home." << endl;
		miner->changeState(CGoHomeAndSleepTilRested::getInstance());

		return;
	}
	else if (miner->GetThirst() >= 10)
	{
		cout << miner->GetName() + ": I thirst. i need to drink water." << endl;
		miner->changeState(CQuenchThirst::getInstance());

		return;
	}
	else if (miner->GetGoldCarried() >= 10)
	{
		cout << miner->GetName() + ": I mined many goldes. i go bank." << endl;
		miner->changeState(CVisitBankAndDepositGold::getInstance());

		return;
	}

	// mine
	miner->SetFatigue(miner->GetFatigue() + 1);
	miner->SetGoldCarried(miner->GetGoldCarried() + 2);
	cout << miner->GetName() + ": mine Gold Nugget from Mine. Gold : " << miner->GetGoldCarried() << endl;

}

void CEnterMineAndForNugget::Exit(CBaseGameEntity* miner)
{
	cout << miner->GetName() + ": Exit Mine." << endl;
}

//

CVisitBankAndDepositGold* CVisitBankAndDepositGold::getInstance()
{
	static CVisitBankAndDepositGold* instance = NULL;
	if (instance == nullptr)
		instance = new CVisitBankAndDepositGold();
	return instance;
}

void CVisitBankAndDepositGold::Enter(CBaseGameEntity* miner)
{
	cout << miner->GetName() + ": Visit Bank." << endl;
}

void CVisitBankAndDepositGold::Execute(CBaseGameEntity* miner)
{
	miner->SetMoneyInBank(miner->GetMoneyInBank() + miner->GetGoldCarried());
	miner->SetGoldCarried(0);
	cout << miner->GetName() + ": Current My Money is " << miner->GetMoneyInBank() << endl;
	miner->changeState(CEnterMineAndForNugget::getInstance());
}

void CVisitBankAndDepositGold::Exit(CBaseGameEntity* miner)
{
	cout << miner->GetName() + ": Exit Bank." << endl;
}

//

CGoHomeAndSleepTilRested* CGoHomeAndSleepTilRested::getInstance()
{
	static CGoHomeAndSleepTilRested* instance = NULL;
	if (instance == nullptr)
		instance = new CGoHomeAndSleepTilRested();
	return instance;
}

void CGoHomeAndSleepTilRested::Enter(CBaseGameEntity* miner)
{
	cout << miner->GetName() + ": Back Home." << endl;
}

void CGoHomeAndSleepTilRested::Execute(CBaseGameEntity* miner)
{
	miner->SetFatigue(0);
	cout << miner->GetName() + ": I recovery Fatigue." << endl;

	if (miner->GetThirst() >= 10)
	{
		cout << miner->GetName() + ": I thirst. i need to drink water." << endl;
		miner->changeState(CQuenchThirst::getInstance());

		return;
	}

	miner->changeState(CEnterMineAndForNugget::getInstance());
}

void CGoHomeAndSleepTilRested::Exit(CBaseGameEntity* miner)
{
	cout << miner->GetName() + ": Leave Home." << endl;
}

//

CQuenchThirst* CQuenchThirst::getInstance()
{
	static CQuenchThirst* instance = NULL;
	if (instance == nullptr)
		instance = new CQuenchThirst();
	return instance;
}

void CQuenchThirst::Enter(CBaseGameEntity* miner)
{
	cout << miner->GetName() + ": Visit Drink Bar." << endl;
}

void CQuenchThirst::Execute(CBaseGameEntity* miner)
{
	miner->SetThirst(0);
	cout << miner->GetName() + ": I recovery Thirst." << endl;

	if (miner->GetFatigue() >= 10)
	{
		cout << miner->GetName() + ": I tired. go back my home." << endl;
		miner->changeState(CGoHomeAndSleepTilRested::getInstance());

		return;
	}
	miner->changeState(CEnterMineAndForNugget::getInstance());
}

void CQuenchThirst::Exit(CBaseGameEntity* miner)
{
	cout << miner->GetName() + ": Exit Drink Bar." << endl;
}

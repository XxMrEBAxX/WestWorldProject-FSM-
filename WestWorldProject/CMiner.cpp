#include "CMiner.h"
#include "CState.h"
#include <iostream>

using namespace std;

void CMiner::update()
{
	m_pCurState->Execute(this);
	m_iThirst += 1;
}

void CMiner::changeState(CState* newState)
{
	m_pCurState->Exit(this);
	m_pCurState = newState;
	m_pCurState->Enter(this);
}

int CMiner::GetGoldCarried()
{
	return m_iGoldCarried;
}

void CMiner::SetGoldCarried(int gold)
{
	m_iGoldCarried = gold;
}

int CMiner::GetMoneyInBank()
{
	return m_iMoneyInBank;
}

void CMiner::SetMoneyInBank(int money)
{
	m_iMoneyInBank = money;
}

int CMiner::GetThirst()
{
	return m_iThirst;
}

void CMiner::SetThirst(int thirst)
{
	m_iThirst = thirst;
}

int CMiner::GetFatigue()
{
	return m_iFatigue;
}

void CMiner::SetFatigue(int fatigue)
{
	m_iFatigue = fatigue;
}

string CMiner::GetName()
{
	return name;
}

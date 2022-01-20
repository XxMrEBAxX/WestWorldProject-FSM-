#pragma once
#include "CBaseGameEntity.h"
#include "CMinerStates.h"
#include <string>

using namespace std;

enum location_type
{
	NONE = -1,
	Mine,
	Bank,
	Home,
	Water,
	MAX
};
class CMiner : public CBaseGameEntity
{
	CState* m_pCurState;
	location_type m_Location;
	int m_iGoldCarried;
	int m_iMoneyInBank;
	int m_iThirst; // 목마름
	int m_iFatigue; // 피로도

	string name;
public:
	CMiner(CState* state, string name) : m_iGoldCarried(0), m_iMoneyInBank(0), m_iThirst(0), m_iFatigue(0), m_pCurState(state)
	{
		this->name = name;
	}
	virtual ~CMiner() {}
	void update();
	void changeState(CState* newState);
	#pragma region GetterSetter
	int GetGoldCarried();
	void SetGoldCarried(int);
	//
	int GetMoneyInBank();
	void SetMoneyInBank(int);
	//
	int GetThirst();
	void SetThirst(int);
	//
	int GetFatigue();
	void SetFatigue(int);
	//
	string GetName();
	#pragma endregion

};


#include "GSPlay.h"
#include "GSIntro.h"
#include "GSMenu.h"
#include "GameStatebase.h"
#include"GSScore.h"
#include "GSOption.h"

GameStateBase::GameStateBase(StateType stateType) : m_stateType(stateType)
{}

std::shared_ptr<GameStateBase> GameStateBase::CreateState(StateType stt)
{
	std::shared_ptr<GameStateBase> s = nullptr;
	switch (stt)
	{
	case StateType::STATE_INVALID:
		break;
	case StateType::STATE_INTRO:
		s = std::make_shared<GSIntro>();
		break;
	case StateType::STATE_MENU:
		s = std::make_shared<GSMenu>();
		break;
	case StateType::STATE_PLAY:
		s = std::make_shared<GSPlay>();
		break;
	case StateType::STATE_OPTION:
		s = std::make_shared<GSOption>();
		break;
	case StateType::STATE_HIGHSCORE:
		s = std::make_shared<GSScore>();
		break;
	default:
		break;
	}
	return s;
}

StateType GameStateBase::GetGameStateType()
{
	return m_stateType;
}
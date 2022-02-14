#include "GSOption.h"
#include "GameButton.h"

GSOption::GSOption() : GameStateBase(StateType::STATE_OPTION),
    m_background(nullptr), m_listButton(std::list<std::shared_ptr<GameButton>>{})
{
}

GSOption::~GSOption()
{
}


void GSOption::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_option.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);
	
	// button music on
	texture = ResourceManagers::GetInstance()->GetTexture("btn_music.tga");
	std::shared_ptr<GameButton> button2 = std::make_shared<GameButton>(model, shader, texture);
	button2->Set2DPosition(Globals::screenWidth - 350, (float)Globals::screenHeight / 2);
	button2->SetSize(50, 50);
	m_listButton.push_back(button2);

	// button music off
	texture = ResourceManagers::GetInstance()->GetTexture("btn_music_off.tga");
	std::shared_ptr<GameButton> button3 = std::make_shared<GameButton>(model, shader, texture);
	button3->Set2DPosition(Globals::screenWidth - 280, (float)Globals::screenHeight / 2);
	button3->SetSize(50, 50);
	m_listButton.push_back(button3);

	// button help
	texture = ResourceManagers::GetInstance()->GetTexture("btn_help.tga");
	std::shared_ptr<GameButton> button4 = std::make_shared<GameButton>(model, shader, texture);
	button4->Set2DPosition(Globals::screenWidth - 210, (float)Globals::screenHeight / 2);
	button4->SetSize(50, 50);
	m_listButton.push_back(button4);

	// but restart
	texture = ResourceManagers::GetInstance()->GetTexture("btn_restart.tga");
	std::shared_ptr<GameButton> button5 = std::make_shared<GameButton>(model, shader, texture);
	button5->Set2DPosition(Globals::screenWidth - 140, (float)Globals::screenHeight / 2);
	button5->SetSize(50, 50);
	m_listButton.push_back(button5);

	// but sfx on
	//texture = ResourceManagers::GetInstance()->GetTexture("btn_settings.tga");
	//std::shared_ptr<GameButton> button2 = std::make_shared<GameButton>(model, shader, texture);
	//button2->Set2DPosition(Globals::screenWidth - 120, 50);
	//button2->SetSize(50, 50);
	//button2->SetOnClick([]() {
	//	GameStateMachine::GetInstance()->ChangeState(StateType::STATE_OPTION);
	//	});
	//m_listButton.push_back(button2);

	// button close
	texture = ResourceManagers::GetInstance()->GetTexture("btn_close.tga");
	std::shared_ptr<GameButton>  button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 50, 50);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);
}

void GSOption::Exit()
{
}


void GSOption::Pause()
{
}

void GSOption::Resume()
{
}


void GSOption::HandleEvents()
{
}

void GSOption::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSOption::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSOption::HandleMouseMoveEvents(int x, int y)
{
}

void GSOption::Update(float deltaTime)
{
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSOption::Draw()
{
	m_background->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
}
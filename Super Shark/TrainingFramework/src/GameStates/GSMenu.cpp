#include "GSMenu.h"
#include "Camera.h"
#include "../Soloud/soloud.h"
#include "../Soloud/soloud_wav.h"
#include "String.h"

GSMenu::GSMenu() : GameStateBase(StateType::STATE_MENU), 
	m_background(nullptr), m_listButton(std::list<std::shared_ptr<GameButton>>{}), m_textGameName(nullptr)
{
}


GSMenu::~GSMenu()
{
}



void GSMenu::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_main_menu2.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);
	
	// play button
	texture = ResourceManagers::GetInstance()->GetTexture("btn_play.tga");
	std::shared_ptr<GameButton> button_play = std::make_shared<GameButton>(model, shader, texture);
	button_play->Set2DPosition(50, 645);
	button_play->SetSize(40, 40);
	button_play->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY);
		});
	m_listButton.push_back(button_play);

	//high score button
	texture = ResourceManagers::GetInstance()->GetTexture("btn_scroce.tga");
	std::shared_ptr<GameButton> button_HighScore = std::make_shared<GameButton>(model, shader, texture);
	button_HighScore->Set2DPosition(350, 645);
	button_HighScore->SetSize(40, 40);
	button_HighScore->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_HIGHSCORE);
		});
	m_listButton.push_back(button_HighScore);

	//setting
	texture = ResourceManagers::GetInstance()->GetTexture("btn_settings.tga");
	std::shared_ptr<GameButton> button_op = std::make_shared<GameButton>(model, shader, texture);
	button_op->Set2DPosition(300, 645);
	button_op->SetSize(40, 40);
	button_op->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_OPTION);
		});
	m_listButton.push_back(button_op);
	
	// exit button
	texture = ResourceManagers::GetInstance()->GetTexture("btn_close.tga");
	std::shared_ptr<GameButton> button_close = std::make_shared<GameButton>(model, shader, texture);
	button_close->Set2DPosition(Globals::screenWidth - 50, 50);
	button_close->SetSize(40, 40);
	button_close->SetOnClick([]() {
		exit(0);
		});
	m_listButton.push_back(button_close);

	// game title
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");
	m_textGameName = std::make_shared< Text>(shader, font, "Flappy Shark", Vector4(0.5f, 0.5f, 0.0f, 1.0f), 1.7f);
	m_textGameName->Set2DPosition(Vector2(100, 300));
	
	//sound
	ResourceManagers::GetInstance()->PlaySound("soundtrack3");
}

void GSMenu::Exit()
{
}


void GSMenu::Pause()
{
}

void GSMenu::Resume()
{
}


void GSMenu::HandleEvents()
{
}

void GSMenu::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSMenu::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSMenu::HandleMouseMoveEvents(int x, int y)
{
}

void GSMenu::Update(float deltaTime)
{
	m_background->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSMenu::Draw()
{
	m_background->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	m_textGameName->Draw();
	
}

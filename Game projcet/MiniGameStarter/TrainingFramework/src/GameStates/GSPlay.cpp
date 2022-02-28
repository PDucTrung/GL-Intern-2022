#include "GSPlay.h"
#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "GameButton.h"
#include "../GSOption.h"
#include "../SpriteAnimation.h"

GSPlay::GSPlay()
{
}


GSPlay::~GSPlay()
{
}


void GSPlay::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_play3.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	// but pause
	texture = ResourceManagers::GetInstance()->GetTexture("btn_pause.tga");
	std::shared_ptr<GameButton>  button3 = std::make_shared<GameButton>(model, shader, texture);
	button3->Set2DPosition(Globals::screenWidth - 120, 50);
	button3->SetSize(50, 50);
	button3->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_OPTION);
		});
	m_listButton.push_back(button3);

	// button close
	texture = ResourceManagers::GetInstance()->GetTexture("btn_close.tga");
	std::shared_ptr<GameButton>  button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 50, 50);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);

	// score
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");
	m_score = std::make_shared< Text>(shader, font, "score: 0", TextColor::RED, 1.0);
	m_score->Set2DPosition(Vector2(5, 25));

	//shark
	shader = ResourceManagers::GetInstance()->GetShader("Animation");
	texture = ResourceManagers::GetInstance()->GetTexture("shark2.tga");
	std::shared_ptr<SpriteAnimation>  shark = std::make_shared<SpriteAnimation>(model, shader, texture, 1, 0.1f);
	shark->Set2DPosition(100, 380);
	shark->SetSize(250, 150);
	m_listAnimation.push_back(shark);

	shader = ResourceManagers::GetInstance()->GetShader("Animation");
	texture = ResourceManagers::GetInstance()->GetTexture("coin.tga");
	std::shared_ptr<SpriteAnimation>  coin = std::make_shared<SpriteAnimation>(model, shader, texture, 18, 0.1f);
	coin->Set2DPosition(240, 380);
	coin->SetSize(150, 150);
	m_listAnimation.push_back(coin);

	//coral
	shader = ResourceManagers::GetInstance()->GetShader("Animation");
	texture = ResourceManagers::GetInstance()->GetTexture("coral2.tga");
	std::shared_ptr<SpriteAnimation>  coral = std::make_shared<SpriteAnimation>(model, shader, texture, 1, 0.1f);
	coral->Set2DPosition(240, 620);
	coral->SetSize(250, 620);
	m_listAnimation.push_back(coral);

	//monter
	shader = ResourceManagers::GetInstance()->GetShader("Animation");
	texture = ResourceManagers::GetInstance()->GetTexture("chr3.tga");
	std::shared_ptr<SpriteAnimation>  monter = std::make_shared<SpriteAnimation>(model, shader, texture, 1, 0.1f);
	monter->Set2DPosition(240, 150);
	monter->SetSize(250, 620);
	m_listAnimation.push_back(monter);
}

void GSPlay::Exit()
{
}


void GSPlay::Pause()
{
}

void GSPlay::Resume()
{
}


void GSPlay::HandleEvents()
{
}

void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
	if (key == 32) {
		std::cout << "space" << std::endl;
	}
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSPlay::HandleMouseMoveEvents(int x, int y)
{
}

void GSPlay::Update(float deltaTime)
{
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
	for (auto it : m_listAnimation)
	{
		it->Update(deltaTime);
	}
}

void GSPlay::Draw()
{
	m_background->Draw();
	m_score->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	for (auto it : m_listAnimation)
	{
		it->Draw();
	}
}

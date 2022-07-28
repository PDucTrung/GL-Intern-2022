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
#include <string>
#include<fstream>
#include "Animation.h"
#include"GameStateMachine.h"
#include"Singleton.h"
using namespace std;

GSPlay::GSPlay() :m_time(0.0f)
{
}


GSPlay::~GSPlay()
{
}

int GSPlay::inFile(std::string fileName) {
	ifstream k(fileName);
	string max;
	k >> max;
	max.reserve();
	int n = atoi(max.c_str());
	int Number = 0, i = 0, result;
	while (n != 0)
	{
		result = n % 10;
		n /= 10;
		Number += result * pow(2, i);
		++i;
	}
	return (Number-2)/5;
}
void GSPlay::outFile(std::string Name, int Max) {
	int temp = Max * 5 + 2; // tự quy ước
	string s = "";
	while (temp != 0) {
		int temp1 = temp % 2;
		temp /= 2;
		s += std::to_string(temp1);
	}
	ofstream file(Name);
	//s.reserve();
	file << s;
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
	// tube dow
	texture = ResourceManagers::GetInstance()->GetTexture("chr5.tga");
	m_tube1_dow = std::make_shared<Sprite2D>(model, shader, texture);
	m_tube1_dow->Set2DPosition(tube1_x, tube_y + tube1_height/2);
	m_tube1_dow->SetSize(tube_width, tube1_height);

	m_tube2_dow = std::make_shared<Sprite2D>(model, shader, texture);
	m_tube2_dow->Set2DPosition(tube2_x, tube_y + tube2_height/2);
	m_tube2_dow->SetSize(tube_width, tube2_height);

	m_tube3_dow = std::make_shared<Sprite2D>(model, shader, texture);
	m_tube3_dow->Set2DPosition(tube3_x, tube_y + tube3_height/2);
	m_tube3_dow->SetSize(tube_width, tube3_height);
	// tube up
	texture = ResourceManagers::GetInstance()->GetTexture("coral2.tga");
	m_tube1_up = std::make_shared<Sprite2D>(model, shader, texture);
	m_tube1_up->Set2DPosition(tube1_x, tube1_height + d_2tube + (700-tube1_height-d_2tube)/2);
	m_tube1_up->SetSize(tube_width, 700 - tube1_height - d_2tube);

	m_tube2_up = std::make_shared<Sprite2D>(model, shader, texture);
	m_tube2_up->Set2DPosition(tube2_x, tube2_height + d_2tube + (700 - tube2_height - d_2tube) / 2);
	m_tube2_up->SetSize(tube_width, 700 - tube2_height - d_2tube);

	m_tube3_up = std::make_shared<Sprite2D>(model, shader, texture);
	m_tube3_up->Set2DPosition(tube3_x, tube3_height + d_2tube + (700 - tube3_height - d_2tube) / 2);
	m_tube3_up->SetSize(tube_width,700 - tube3_height - d_2tube);
	
	// sand
	texture = ResourceManagers::GetInstance()->GetTexture("floor.tga");
	m_sand = std::make_shared<Sprite2D>(model, shader, texture);
	m_sand->Set2DPosition(0, 670);
	m_sand->SetSize(800, 60);
	// button prev
	texture = ResourceManagers::GetInstance()->GetTexture("btn_prev.tga");
	std::shared_ptr<GameButton>  button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(50, 50);
	button->SetSize(40, 40);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_MENU);
		});
	m_listButton.push_back(button);
	
	//button replay
	texture = ResourceManagers::GetInstance()->GetTexture("btn_restart.tga");
	std::shared_ptr<GameButton>  button_replay = std::make_shared<GameButton>(model, shader, texture);
	button_replay->Set2DPosition(350, 50);
	button_replay->SetSize(40, 40);
	button_replay->SetOnClick([]() {

		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY);
		});
	m_listButton.push_back(button_replay);
	// score
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");

	

	//string text_MaxScore = convert_int_to_string(inFile("src/hightscore.txt"));
	
	m_score = std::make_shared< Text>(shader, font, "Score: " + std::to_string(score), TextColor::WHITE, 0.8);
	m_score->Set2DPosition(Vector2(5, 20));

	m_text_Highscore = std::make_shared<Text>(shader, font, "Highest Score: " + std::to_string(inFile("src/highscore.txt")), TextColor::WHITE, 0.8);
	m_text_Highscore->Set2DPosition(Vector2(200, 20));

	// shark 
	texture = ResourceManagers::GetInstance()->GetTexture("Shark3.tga");
	shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");

	m_Shark = std::make_shared<Animation>(model, shader, texture, 1, 0.1f);
	m_Shark->Set2DPosition(x_Shark, y_Shark);
	m_Shark->SetSize(Shark_width, Shark_height);
	
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
	if (bIsPressed == true) {
		switch (key)
		{
		case ' ':
			keyPressed |= KEY_UP;
			
			
			break;
		default:
			break;
		}
	}
	else {
		switch (key)
		{
		case ' ':
			keyPressed ^= KEY_UP;
			break;
		default:
			break;
		}
	}
	
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if(button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSPlay::HandleMouseMoveEvents(int x, int y)
{
}
////collision handling
bool GSPlay::Check_collision() {
	
	if ((m_Shark->Get_position_y() - Shark_height/2) <= 0) {
		return true;
	}
	if ((m_Shark->Get_position_y() + Shark_height / 2) >= 640) {
		return true;
	}
	if (m_Shark->Get_position_x() + Shark_width / 2 >= m_tube1_dow->Get_position_x() - tube_width / 2 &&
		m_Shark->Get_position_x() - Shark_width / 2 <= m_tube1_dow->Get_position_x() + tube_width / 2) {
		if (m_Shark->Get_position_y() - Shark_height / 2 <= m_tube1_dow->Get_position_y() * 2) {
			return true;
		}
		else if (m_Shark->Get_position_y() + Shark_height / 2 >= m_tube1_dow->Get_position_y() * 2 + d_2tube) {
			return true;
		}
	}
	if (m_Shark->Get_position_x() + Shark_width / 2 >= m_tube2_dow->Get_position_x() - tube_width / 2 &&
		m_Shark->Get_position_x() - Shark_width / 2 <= m_tube2_dow->Get_position_x() + tube_width / 2) {
		if (m_Shark->Get_position_y() - Shark_height / 2 <= m_tube2_dow->Get_position_y() * 2) {
			return true;
		}
		else if (m_Shark->Get_position_y() + Shark_height / 2 >= m_tube2_dow->Get_position_y() * 2 + d_2tube) {
			return true;
		}
	}
	if (m_Shark->Get_position_x() + Shark_width / 2 >= m_tube3_dow->Get_position_x() - tube_width / 2 &&
		m_Shark->Get_position_x() - Shark_width / 2 <= m_tube3_dow->Get_position_x() + tube_width / 2) {
		if (m_Shark->Get_position_y() - Shark_height / 2 <= m_tube3_dow->Get_position_y() * 2) {
			return true;
		}
		else if (m_Shark->Get_position_y() + Shark_height / 2 >= m_tube3_dow->Get_position_y() * 2 + d_2tube) {
			return true;
		}
	}
	return false;
}
void GSPlay::Update(float deltaTime)
{
	//collision handling
	if (Check_collision() == false) {
		//move screen
		m_tube1_dow->Move(deltaTime, Vector2(-1, 0), velocity);
		m_tube2_dow->Move(deltaTime, Vector2(-1, 0), velocity);
		m_tube3_dow->Move(deltaTime, Vector2(-1, 0), velocity);
		m_tube1_up->Move(deltaTime, Vector2(-1, 0), velocity);
		m_tube2_up->Move(deltaTime, Vector2(-1, 0), velocity);
		m_tube3_up->Move(deltaTime, Vector2(-1, 0), velocity);

		// refresh tube
		if (m_tube1_dow->Is_Out_Of_Screen(tube_width)) {
			int temp_tube1_height = 100 + rand() % 400;
			tube1_x = 550;
			m_tube1_dow->Reset_position_dow(temp_tube1_height, tube1_x);
			m_tube1_up->Reset_position_up(temp_tube1_height);

			m_tube1_dow->Reset_size_dow(temp_tube1_height);
			m_tube1_up->Reset_size_up(temp_tube1_height);

			tube1_pass = false;

		}
		if (m_tube2_dow->Is_Out_Of_Screen(tube_width)) {
			int temp_tube2_height = 100 + rand() % 400;
			tube2_x = 550;
			m_tube2_dow->Reset_position_dow(temp_tube2_height, tube2_x);
			m_tube2_up->Reset_position_up(temp_tube2_height);

			m_tube2_dow->Reset_size_dow(temp_tube2_height);
			m_tube2_up->Reset_size_up(temp_tube2_height);

			tube2_pass = false;

		}
		if (m_tube3_dow->Is_Out_Of_Screen(tube_width)) {
			int temp_tube3_height = 100 + rand() % 400;
			tube3_x = 550;
			m_tube3_dow->Reset_position_dow(temp_tube3_height, tube3_x);
			m_tube3_up->Reset_position_up(temp_tube3_height);

			m_tube3_dow->Reset_size_dow(temp_tube3_height);
			m_tube3_up->Reset_size_up(temp_tube3_height);

			tube3_pass = false;

		}
		//update score. shark pass tube -> score++
		if (m_Shark->Get_position_x() >= m_tube1_dow->Get_position_x() + tube_width && tube1_pass == false) {
			score += 1;
			tube1_pass = true;
			auto shader = ResourceManagers::GetInstance()->GetShader("TextShader");
			std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");
		
			m_score = std::make_shared< Text>(shader, font, "Score: " + std::to_string(score), TextColor::WHITE, 0.8);
			m_score->Set2DPosition(Vector2(5, 20));
			
		}
		if (m_Shark->Get_position_x() >= m_tube2_dow->Get_position_x() + tube_width && tube2_pass == false) {
			score += 1;
			tube2_pass = true;
			auto shader = ResourceManagers::GetInstance()->GetShader("TextShader");
			std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");
			
			m_score = std::make_shared< Text>(shader, font, "Score: " + std::to_string(score), TextColor::WHITE, 0.8);
			m_score->Set2DPosition(Vector2(5, 20));
			
		}
		if (m_Shark->Get_position_x() >= m_tube3_dow->Get_position_x() + tube_width && tube3_pass == false) {
			score += 1;
			tube3_pass = true;
			auto shader = ResourceManagers::GetInstance()->GetShader("TextShader");
			std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");
			
			
			m_score = std::make_shared< Text>(shader, font, "Score: " + std::to_string(score), TextColor::WHITE, 0.8);
			m_score->Set2DPosition(Vector2(5, 20));
		
		}
		
		//move shark
		if (keyPressed & KEY_UP) {
			//move up shark.
			y_Shark -= 0.5;
			m_Shark->Set2DPosition(x_Shark, y_Shark);
		}
		
		if (!keyPressed) {
			y_Shark += 1.0;
			x_Shark = x_Shark;
			m_Shark->Set2DPosition(x_Shark, y_Shark);
		}
		for (auto it : m_listButton)
		{
			it->Update(deltaTime);
		}
		m_Shark->Update(deltaTime);
		m_time += deltaTime;
	}
	else{	
		auto shader = ResourceManagers::GetInstance()->GetShader("TextShader");
		std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");
		
		m_score = std::make_shared< Text>(shader, font, "Game over", TextColor::WHITE, 1.0);
		m_score->Set2DPosition(Vector2(150, 350));
		
		if (score > inFile("src/highscore.txt")) {
			outFile("src/highscore.txt", score);
		}
	}
	
}

void GSPlay::Draw()
{
	m_background->Draw();

	m_tube1_dow->Draw();
	m_tube2_dow->Draw();
	m_tube3_dow->Draw();

	m_tube1_up->Draw();
	m_tube2_up->Draw();
	m_tube3_up->Draw();

	m_Shark->Draw();

	m_score->Draw();
	m_sand->Draw();
	//m_text_Highscore->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	
}
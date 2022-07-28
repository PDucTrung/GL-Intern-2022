#pragma once
#include "GameStateBase.h"
#include <iostream>

#include<vector>
#include<fstream>

class Sprite2D;
class Sprite3D;
class Text;
class GameButton;
class Animation;

class GSPlay :
	public GameStateBase
{
public:
	GSPlay();
	~GSPlay();

	void	Init() override;
	void	Exit() override;

	void	Pause() override;
	void	Resume() override;

	void	HandleEvents() override;
	void	HandleKeyEvents(int key, bool bIsPressed) override;
	void	HandleTouchEvents(int x, int y, bool bIsPressed) override;
	void	HandleMouseMoveEvents(int x, int y) override;
	void	Update(float deltaTime) override;
	void	Draw() override;

	bool Check_collision();

	int inFile(std::string fileName);

	void outFile(std::string fileName, int Max_score);

	

private:
	std::shared_ptr<Sprite2D>	m_background;

	std::shared_ptr<Sprite2D>	m_tube1_dow;
	std::shared_ptr<Sprite2D>	m_tube2_dow;
	std::shared_ptr<Sprite2D>	m_tube3_dow;

	std::shared_ptr<Sprite2D>	m_tube1_up;
	std::shared_ptr<Sprite2D>	m_tube2_up;
	std::shared_ptr<Sprite2D>	m_tube3_up;

	std::shared_ptr<Animation>	m_Shark; //shark
	std::shared_ptr<Sprite2D>	m_sand;
	std::shared_ptr<Text>		m_text_Highscore;
	std::shared_ptr<Text>		m_score;
	std::list<std::shared_ptr<GameButton>>	m_listButton;

	
	

	float velocity = 100;

	int x_Shark = 50;
	float y_Shark = 350.0;

	int Shark_width = 40;
	int Shark_height = 40;

	int	tube1_x = 400;
	int	tube2_x = 600;
	int	tube3_x = 800;
	int	tube_y = 0;

	int d_2tube = 200;

	int score = 0;

	int tube_width = 50;
	int tube1_height = (100 + rand() % 400);
	int tube2_height = (100 + rand() % 400);
	int tube3_height = (100 + rand() % 400);

	bool tube1_pass = false;
	bool tube2_pass = false;
	bool tube3_pass = false;

	GLfloat m_time;
};


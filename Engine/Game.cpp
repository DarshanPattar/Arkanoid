/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	ball(Vec2(100, 100), Vec2(200, 200)),
	walls(7, 7, gfx.ScreenWidth - 7, gfx.ScreenHeight - 7),
	Soundpad(L"Sounds\\arkpad.wav"),
	SoundBrick(L"Sounds\\arkbrick.wav"),
	B(Rect(200, 400, 500, 500), Colors::Blue),
	paddle(Vec2(gfx.ScreenWidth/2, gfx.ScreenHeight-100.f), 50.f, 10.f)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float dt = ft.Mark();

	ball.Update(dt);
	paddle.Update(dt, wnd.kbd);

	if (B.DoBallCollision(ball)) {
		SoundBrick.Play();
	}
	if (ball.DoWallCollision(walls)) {
		Soundpad.Play();
	}
	paddle.DoWallCollision(walls);
	if (paddle.DoBallCollsion(ball)) {
		Soundpad.Play();
	}

}

void Game::ComposeFrame()
{
	ball.Draw(gfx);
	B.Draw(gfx);
	paddle.Draw(gfx);
}

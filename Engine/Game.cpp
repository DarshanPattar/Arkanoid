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
	ball(Vec2(300, 300), Vec2(300, 300)),
	walls(7, 7, gfx.ScreenWidth - 7, gfx.ScreenHeight - 7),
	Soundpad(L"Sounds\\arkpad.wav"),
	SoundBrick(L"Sounds\\arkbrick.wav"),
	paddle(Vec2(gfx.ScreenWidth/2, gfx.ScreenHeight-100.f), 50.f, 10.f)
{
	Color colors[5] = { Colors::Blue, Colors::Cyan, Colors::Green, Colors::Magenta, Colors::LightGray };
	const Vec2 topleft(1, 1);

	int i = 0;
	for (int y = 0; y < nBricksDown; y++) {
		const Color c = colors[y];
		for (int x = 0; x < nBricksAcross; x++) {

			Vec2 tl = Vec2(topleft.x + x * brickWidth,topleft.y + y * brickHeight);
			Vec2 br = Vec2(topleft.x + ((x + 1) * brickWidth),topleft.y + ((y + 1) * brickHeight));

			Rect r = Rect(tl.x, tl.y, br.x, br.y);

			bricks[i] = Brick(r, c);
			i++;
		}
	}

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


	for (Brick& brick : bricks) {
		if (brick.DoBallCollision(ball)) {
			SoundBrick.Play();
			break;
		}
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

	for (const Brick& brick : bricks) {
		brick.Draw(gfx);
	}

	ball.Draw(gfx);
	paddle.Draw(gfx);
}

#include "Penguins.h"
#include "InputManager.h"
#include "Camera.h"
#include "Error.h"
#include "Bullet.h"
#include "Game.h"

#define PENGUIM_LINEAR_SPEED (50)
#define PENGUIM_CANNON_ANGLE (20)
#define PENGUIM_HP (100)
#define PENGUIM_MAX_SPEED (30.)
#define PENGUIM_ACELERACAO (1.1)
#define PENGUIM_VEC_ANGULAR (0.2)
#define PENGUIM_BULLET_SPEED 125
#define PENGUIM_BULLET_MAX_DISTANCE 500
#define PENGUIM_BULLET_FRAMETIME 0.5
#define PENGUIM_BULLET_FRAME_COUNT 4


Penguins* Penguins::player= nullptr;

Penguins::Penguins(float x, float y):GameObject(),bodySP("img/penguin.png"), cannonSp("img/cubngun.png"), speed(), linearSpeed(PENGUIM_LINEAR_SPEED), cannonAngle(PENGUIM_CANNON_ANGLE), hp(PENGUIM_HP)
{
	player= this;
	box.x= x;
	box.y= y;
	box.w= bodySP.GetWidth();
	box.h= bodySP.GetHeight();
	Camera::Follow(this);
}

Penguins::~Penguins()
{
	player = nullptr;
}

void Penguins::Update(float dt)
{
	InputManager &inputManager= InputManager::GetInstance();
	if(inputManager.IsKeyDown('w') || inputManager.IsKeyDown('W'))
	{
		speed+= Vec2(1, 0) + speed*PENGUIM_ACELERACAO*dt;//se o penguim não se mover olhar aqui
		if(PENGUIM_MAX_SPEED < speed.Magnitude() )
		{
			speed.Normalize();
			speed= speed * PENGUIM_MAX_SPEED;
		}
	}
	if(inputManager.IsKeyDown('s') || inputManager.IsKeyDown('S'))
	{
		speed-= Vec2(1, 0) + speed*PENGUIM_ACELERACAO*dt;//se o penguim não se mover olhar aqui
		if(PENGUIM_MAX_SPEED < speed.Magnitude() )
		{
			speed.Normalize();
			speed= speed * PENGUIM_MAX_SPEED;
		}
	}
	box= box + speed;
	if(inputManager.IsMouseDown('a')|| inputManager.IsKeyDown('A'))
	{
		rotation+= PENGUIM_VEC_ANGULAR*dt;
	}
	if(inputManager.IsMouseDown('d')|| inputManager.IsKeyDown('D'))
	{
		rotation-= PENGUIM_VEC_ANGULAR*dt;
	}
	cannonAngle= (Vec2(inputManager.GetMouseX(), inputManager.GetMouseY())-(box.Center()-Camera::pos)).Inclination()*CONVERSAO_GRAUS_RADIANOS;
	cannonAngle -= rotation;
}
void Penguins::Render(void)
{
	bodySP.Render(box.x-Camera::pos.x, box.y-Camera::pos.y, rotation*CONVERSAO_GRAUS_RADIANOS);
	cannonSp.Render(box.x-Camera::pos.x, box.y-Camera::pos.y, cannonAngle);
}
bool Penguins::IsDead(void)
{
	return (0>=hp);
}
void Penguins::Shoot(void)
{
	REPORT_I_WAS_HERE;
	Bullet* bullet= new Bullet(
				box.x-Camera::pos.x,
				box.y-Camera::pos.y,
				(Camera::pos-box).Inclination(),
				PENGUIM_BULLET_SPEED,
				PENGUIM_BULLET_MAX_DISTANCE,
				PENGUIM_BULLET_FRAMETIME,
				PENGUIM_BULLET_FRAME_COUNT,
				"penguinbullet.png"
			);
	REPORT_I_WAS_HERE;
	Game::GetInstance().GetState().AddObject(bullet);
	REPORT_I_WAS_HERE;
}


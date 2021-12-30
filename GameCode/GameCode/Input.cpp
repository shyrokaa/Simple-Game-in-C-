#include"Input.h"
#include"Engine.h"

Input::Input()
{
	m_Keystates = SDL_GetKeyboardState(nullptr);
}

void Input::Listen()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{

		case SDL_QUIT:Engine::GetInstance()->Quit(); 
			break;

		case SDL_KEYDOWN:KeyDown();
			break;

		case SDL_KEYUP:KeyUP();
			break;


		}
	}
}

bool Input::GetKeyDown(SDL_Scancode key)
{
	if (m_Keystates[key] == 1)
		return true;
	return false;
}

int Input::GetAxisKey(Axis axis)
{
	switch (axis)
	{
	case HORIZONTAL:
		if (GetKeyDown(SDL_SCANCODE_D) || GetKeyDown(SDL_SCANCODE_RIGHT))
			return 1;
		if (GetKeyDown(SDL_SCANCODE_A) || GetKeyDown(SDL_SCANCODE_LEFT))
			return -1;
		break;

	case VERTICAL:
		if (GetKeyDown(SDL_SCANCODE_W) || GetKeyDown(SDL_SCANCODE_UP))
			return 1;
		if (GetKeyDown(SDL_SCANCODE_S) || GetKeyDown(SDL_SCANCODE_DOWN))
			return -1;
		break;

	default:
		return 0;
		break;
	}
}

void Input::KeyUP()
{
	m_Keystates = SDL_GetKeyboardState(nullptr);
}

void Input::KeyDown()
{
	m_Keystates = SDL_GetKeyboardState(nullptr);
}
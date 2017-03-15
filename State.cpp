#include "State.h"
#include "Face.h"
#include "RectOp.h"
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

#define STATE_RENDER_X 0//esse valores calculam o offset em relação ao canto superior esquedo da imagem daquilo que será renderizado
#define STATE_RENDER_Y 0
State::State(void): bg("img/ocean.jpg")
{
	quitRequested=false;
}

State::~State(void)
{
	objectArray.clear();;
}

void State::Input(void)
{

	SDL_Event event;
	int mouseX, mouseY;

	// Obtenha as coordenadas do mouse
	SDL_GetMouseState(&mouseX, &mouseY);

	// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
	while (SDL_PollEvent(&event))
	{

		// Se o evento for quit, setar a flag para terminação
		if(event.type == SDL_QUIT) {
			quitRequested = true;
		}

		// Se o evento for clique...
		if(event.type == SDL_MOUSEBUTTONDOWN) {

			// Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
			for(int i = objectArray.size() - 1; i >= 0; --i) {
				// Obtem o ponteiro e casta pra Face.
				Face* face = (Face*) objectArray[i].get();
				// Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
				// O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
				// ao usar get(), violamos esse princípio e estamos menos seguros.
				// Esse código, assim como a classe Face, é provisório. Futuramente, para
				// chamar funções de GameObjects, use objectArray[i]->função() direto.

//				if(face->box.IsInside((float)mouseX, (float)mouseY)) {
				if(Vec2(mouseX, mouseY).IsInRect(face->box)) {
					// Aplica dano
					face->Damage(rand() % 10 + 10);
					// Sai do loop (só queremos acertar um)
					break;
				}
			}
		}
		if( event.type == SDL_KEYDOWN ) {
			// Se a tecla for ESC, setar a flag de quit
			if( event.key.keysym.sym == SDLK_ESCAPE ) {
				quitRequested = true;
			}
			// Se não, crie um objeto
			else {
				AddObject((float)mouseX, (float)mouseY);
			}
		}
	}
}


//void State::Update(float dt)
void State::Update()
{
	Input();
	for(int cont=0; cont < objectArray.size(); cont++)
	{
		if(objectArray.at(cont)->IsDead())
		{
			objectArray.erase(objectArray.begin()+cont);
		}
	}
}

void State::Render(void)
{
	//renderizar o bg
	bg.Render(STATE_RENDER_X, STATE_RENDER_Y);
}

bool State::QuitRequested()
{
	return quitRequested;
}
//AddObject recebe ints ou floats???
void State::AddObject(float mouseX, float mouseY)
{
	//[TODO] ver o q é pra fazer aqui
//	objectArray.push_back(std::unique_ptr<GameObject>(new Face(mouseX, mouseY)));
//	objectArray.push_back(new Face(mouseX, mouseY));
}

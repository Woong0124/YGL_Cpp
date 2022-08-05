#include "Texture.h"
#include "Engine.h"

Texture::Texture(std::string Filename, int R, int G, int B)
{
	MySurface = SDL_LoadBMP(Filename.c_str());
	SDL_SetColorKey(MySurface, 1, SDL_MapRGB(MySurface->format, R, G, B));

	MyTexture = SDL_CreateTextureFromSurface(GameEngine->MyRenderer, MySurface);
}

Texture::~Texture()
{
	SDL_FreeSurface(MySurface);
	SDL_DestroyTexture(MyTexture);
}

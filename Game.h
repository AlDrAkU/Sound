#pragma once
#include "SoundEffect.h"
#include "SoundStream.h"
#include "Texture.h"

class Game
{
public:
	explicit Game( const Window& window );
	Game( const Game& other ) = delete;
	Game& operator=( const Game& other ) = delete;
	~Game();

	void Update( float elapsedSec );
	void Draw( );

	// Event handling
	void ProcessKeyDownEvent( const SDL_KeyboardEvent& e );
	void ProcessKeyUpEvent( const SDL_KeyboardEvent& e );
	void ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e );
	void ProcessMouseDownEvent( const SDL_MouseButtonEvent& e );
	void ProcessMouseUpEvent( const SDL_MouseButtonEvent& e );

private:
	// DATA MEMBERS
	Window m_Window;
	SoundStream m_sndStream1;
	SoundStream m_sndStream2;
	SoundEffect m_sndEffect1;
	SoundEffect m_sndEffect2;

	//Which test series
	bool m_StreamTest{ true };
	Texture m_StreamMenuText;
	Texture m_EffectMenuText;


	// FUNCTIONS
	void Initialize( );
	void Cleanup( );
	void ClearBackground( );

	void DrawMenu( );
	void SwitchTest( );
	void TestStreams( const SDL_KeyboardEvent& e );
	void TestEffects( const SDL_KeyboardEvent& e );

};
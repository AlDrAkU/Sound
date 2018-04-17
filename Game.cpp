#include "stdafx.h"
#include "Game.h"


Game::Game( const Window& window ) 
	:m_Window{ window }
	,m_StreamMenuText{ "Resources/Images/StreamsMenu.png" }
	,m_EffectMenuText { "Resources/Images/EffectsMenu.png" }
	, m_sndEffect1{ "Resources/Audio/laser.ogg" }
	, m_sndEffect2{ "Resources/Audio/jingles.ogg" }
	, m_sndStream1{"Resources/Audio/DonkeyKong.mp3"}
	, m_sndStream2{"Resources/Audio/Mario.mp3"}
{
	Initialize( );
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
}

void Game::Cleanup( )
{
}

void Game::Update( float elapsedSec )
{
}

void Game::Draw( )
{
	ClearBackground( );
	DrawMenu( );
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	switch ( e.keysym.sym )
	{
	case SDLK_RIGHT:
	case SDLK_LEFT:
		SwitchTest( );
		break;
	default:
		// Handle user request
		if ( m_StreamTest )
		{
			TestStreams( e );
		}
		else
		{
			TestEffects( e );
		}
	}
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
}

void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{
}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
}

void Game::ProcessMouseUpEvent( const SDL_MouseButtonEvent& e )
{
}

void Game::ClearBackground( )
{
	glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}

void Game::DrawMenu( )
{
	if ( m_StreamTest )
	{
		m_StreamMenuText.Draw( );
	}
	else
	{
		m_EffectMenuText.Draw( );
	}
}

void Game::SwitchTest( )
{
	if ( m_StreamTest )
	{

		// TODO: User switches to the "Effect test", stop the music
		if (m_sndStream1.IsPlaying || m_sndStream2.IsPlaying)
		{
			m_sndStream1.Stop();
			m_sndStream2.Stop();
		}

	}
	else
	{
		// TODO: User switches to the "Stream test", stop the effects
		
			m_sndEffect1.StopAll();
			m_sndEffect2.StopAll();

	}
	m_StreamTest = !m_StreamTest;
}

void Game::TestStreams( const SDL_KeyboardEvent& e )
{
	// TODO: Fulfil the user requests in the "Stream test" menu 
	switch ( e.keysym.sym )
	{
	case SDLK_1:
	case SDLK_KP_1:
		// Play Donkey Kong repeated
		m_sndStream1.Play(true);
		break;
	case SDLK_2:
	case SDLK_KP_2:
		// Play Mario
		m_sndStream2.Play(false);
		break;
	case SDLK_p:
		// Pause 
		SoundStream::Pause();
		break;
	case SDLK_r:
		// Resume 
		SoundStream::Resume();

		break;
	case SDLK_s:
		// Stop
		SoundStream::Stop();
		

		break;
	case SDLK_UP:
		// Change volume
		SoundStream::SetVolume(SoundStream::GetVolume() + 1);
		

	break;
	case SDLK_DOWN:
		// Change volume
		SoundStream::SetVolume(SoundStream::GetVolume() - 1);
		
	break;
	}
}

void Game::TestEffects( const SDL_KeyboardEvent& e )
{
	// TODO: Fulfil the user requests in the "Effect test" menu 
	switch ( e.keysym.sym )
	{
	case SDLK_1:
	case SDLK_KP_1:
		// Play laser (repeated)
		m_sndEffect1.Play(true);
		break;
	case SDLK_2:
	case SDLK_KP_2:
		// Play jingles (a number of times)
		m_sndEffect2.Play(4);
		break;
	case SDLK_p:
		// Pause 
		SoundEffect::PauseAll();
		

		break;
	case SDLK_r:
		// Resume
		SoundEffect::ResumeAll();
		break;
	case SDLK_s:
		// Stop
		SoundEffect::StopAll();
		
		break;
	case SDLK_UP:
		// Change volume
		m_sndEffect1.SetVolume(m_sndEffect1.GetVolume() + 1);
		m_sndEffect2.SetVolume(m_sndEffect2.GetVolume() + 1);
		break;
	case SDLK_DOWN:
		// Change volume
		m_sndEffect1.SetVolume(m_sndEffect1.GetVolume() - 1);
		m_sndEffect2.SetVolume(m_sndEffect2.GetVolume() - 1);
		break;
	}
}


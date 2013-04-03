// ---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
#include <mmsystem.h>
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;

class B
{
public:
	// ...
	bool isFinished() const
	{
		return m_isFinished;
	}

	void cycle()
	{
		// ...
	}

private:
	// ...
	bool m_isFinished;

};

class A
{
public:
	void poll(B& b)
	{

		if (b.isFinished())
		{
			// Do something
			MessageBoxA(NULL, "bb", "oo", MB_OK);
		}
	}
};

A a;
B b;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner)
{

	b.cycle();
	a.poll(b);

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	wchar_t *wav_handle;
	HRSRC h = FindResource(HInstance, L"IDR_WAVE1", L"WAV");
	HGLOBAL h1 = LoadResource(HInstance, h);
	wav_handle = (wchar_t *)LockResource(h1);
	sndPlaySound(wav_handle, SND_MEMORY | SND_ASYNC | SND_LOOP);

	// BitmapListAnimation1 = new TBitmapListAnimation();
}

// ---------------------------------------------------------------------------

enum GameState
{
	GAME_STATE_LOGO = 0, GAME_STATE_TRAILER, GAME_STATE_MAIN_MENU,
	GAME_STATE_INGAME, GAME_STATE_SETTINGS_MENU,
};

static int gameState = GAME_STATE_LOGO;

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
	System::WideChar &KeyChar, TShiftState Shift)
{

	switch (gameState)
	{
	case GAME_STATE_LOGO:
		{
			if (Key == VK_RETURN)
			{
				BitmapListAnimation1->Stop();
				BitmapListAnimation2->Start();
				gameState = GAME_STATE_TRAILER;
			}
			break;
		}
	case GAME_STATE_TRAILER:
		{
			if (Key == VK_UP)
			{
				BitmapListAnimation3->Stop();
				BitmapListAnimation2->Start();
			}
			if (Key == VK_DOWN)
			{
				BitmapListAnimation2->Stop();
				BitmapListAnimation3->Start();
			}
			if (Key == VK_RETURN)
			{
				BitmapListAnimation2->Stop();
				BitmapListAnimation3->Stop();
				BitmapListAnimation4->Start();
				gameState = GAME_STATE_MAIN_MENU;
			}
			break;
		}
	case GAME_STATE_MAIN_MENU:
		{
			break;
		}
	case GAME_STATE_INGAME:
		{
			break;
		}
	case GAME_STATE_SETTINGS_MENU:
		{
			break;
		}
	defaut:
		{
			break;
		}
	}

	if (Key == VK_ESCAPE)
		exit(0);
}
// ---------------------------------------------------------------------------

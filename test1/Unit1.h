// ---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Ani.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <FMX.Media.hpp>

// ---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published: // IDE-managed Components

	TImage *Image1;
	TBitmapListAnimation *BitmapListAnimation1;
	TMediaPlayer *MediaPlayer1;
	TBitmapListAnimation *BitmapListAnimation2;
	TBitmapListAnimation *BitmapListAnimation3;
	TBitmapListAnimation *BitmapListAnimation4;

	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
		System::WideChar &KeyChar, TShiftState Shift);

private: // User declarations
		public : // User declarations
	__fastcall TForm1(TComponent* Owner);

};

// ---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
// ---------------------------------------------------------------------------
#endif

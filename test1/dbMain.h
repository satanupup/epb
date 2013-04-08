// ---------------------------------------------------------------------------

#ifndef dbMainH
#define dbMainH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.Types.hpp>

#include "sqlite3.h"
#include <FMX.Edit.hpp>
#include <string>

// ---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published: // IDE-managed Components
	TListBox *ListBox1;
	TEdit *Edit1;
	TButton *chadd;
	TEdit *Edit2;
	TButton *chdelete;

	void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
		System::WideChar &KeyChar, TShiftState Shift);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ListBox1Click(TObject *Sender);
	void __fastcall chaddClick(TObject *Sender);
	void __fastcall chdeleteClick(TObject *Sender);

private: // User declarations

	void btntest();
	void dbcharadd(System::UnicodeString str1);
	void dbview();
	void dbchardelete(System::UnicodeString str1);

public: // User declarations
	__fastcall TForm1(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
// ---------------------------------------------------------------------------

#endif

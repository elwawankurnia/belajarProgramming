//---------------------------------------------------------------------------

#ifndef tugasSekolahH
#define tugasSekolahH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include "perfgrap.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TPanel *Panel1;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label8;
	TButton *Button4;
	TMemo *MemoHasil;
	TImage *ImageGrafik;
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

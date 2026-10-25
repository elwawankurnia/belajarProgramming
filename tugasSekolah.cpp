//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <math.h>

#include "tugasSekolah.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "perfgrap"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	exit(0);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Edit1->Text = "";
	Edit2->Text = "";
	Edit3->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
    double a = Edit1->Text.ToDouble();
	double b = Edit2->Text.ToDouble();
	double c = Edit3->Text.ToDouble();

// --- BAGIAN B: MENGGAMBAR GRAFIK PARABOLA X, Y ---
       // --- BAGIAN B: MENGGAMBAR GRAFIK PARABOLA X, Y (SKALA DIPERKECIL) ---
    TCanvas *cv = ImageGrafik->Canvas;
    int w = ImageGrafik->Width;
    int h = ImageGrafik->Height;

    // Bersihkan Canvas (Beri warna latar belakang putih)
    cv->Brush->Color = clWhite;
    cv->FillRect(Rect(0, 0, w, h));

    // Hitung koordinat titik puncak matematika (Vertex) sebagai acuan visual
    // Rumus X puncak = -b / (2a)
    double xp = -b / (2.0 * a);
    // Rumus Y puncak = (a * xp^2) + (b * xp) + c
    double yp = (a * xp * xp) + (b * xp) + c;

    // Titik pusat grafik diletakkan di tengah TImage
    int centerX = w / 2;
    // Sumbu Y digeser berdasarkan posisi Y puncak agar kurva melengkung di dalam layar
    int centerY = h / 2 + (int)(yp * 2.0);

    // PERKECIL SKALA: Mengubah pengali menjadi lebih kecil agar grafik muat
    // 1 unit matematika sekarang hanya memakan 2 sampai 4 piksel layar
    double skalaX = 4.0;
    double skalaY = 2.0;

    // Gambar Garis Sumbu X dan Y Baru (Warna Abu-abu)
    cv->Pen->Color = clSilver;
    cv->Pen->Width = 1;
    if (centerY >= 0 && centerY < h) {
        cv->MoveTo(0, centerY); cv->LineTo(w, centerY); // Garis horizontal Sumbu X
    }
    if (centerX >= 0 && centerX < w) {
        cv->MoveTo(centerX, 0); cv->LineTo(centerX, h); // Garis vertikal Sumbu Y
    }

    // Mulai menggambar kurva parabola
    cv->Pen->Color = clBlue;
    cv->Pen->Width = 2;

    bool firstPoint = true;

    // Rentang X matematika diperlebar agar bentuk melengkung parabola lebih terlihat
    for (double x = -50.0; x <= 50.0; x += 0.2)
    {
        double y = (a * x * x) + (b * x) + c;

        // Konversi ke piksel dengan memperhitungkan pergeseran titik puncak (xp)
        int pixelX = centerX + (int)((x - xp) * skalaX);
        int pixelY = centerY - (int)(y * skalaY);

        // Gambar garis hanya jika koordinat X berada di dalam lebar komponen TImage
        if (pixelX >= 0 && pixelX < w)
        {
            if (firstPoint) {
                cv->MoveTo(pixelX, pixelY);
                firstPoint = false;
            } else {
                cv->LineTo(pixelX, pixelY);
            }
        }
    }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
    {
    // 1. Bersihkan layar memo hasil terlebih dahulu
    MemoHasil->Lines->Clear();

    // 2. Ambil nilai a, b, c dari input TEdit (Konversi dari Text ke Double)
	double a = Edit1->Text.ToDouble();
	double b = Edit2->Text.ToDouble();
	double c = Edit3->Text.ToDouble();

    // 3. Validasi jika nilai a adalah 0 (Bukan persamaan kuadrat)
    if (a == 0) {
        MemoHasil->Lines->Add("Error: Nilai 'a' tidak boleh 0!");

    }

    // 4. Hitung Diskriminan
    double d = (b * b) - (4 * a * c);

    // Variabel pembantu untuk memformat teks output
    String pesan;

    if (d > 0) {
        // Akar real dan berbeda
        double sqrt_d = sqrt(d);
        double x1 = (-b + sqrt_d) / (2 * a);
        double x2 = (-b - sqrt_d) / (2 * a);

        MemoHasil->Lines->Add("Akar-akar bersifat Real dan Berbeda:");

        pesan.sprintf(_D("x1 = %.6f"), x1);
        MemoHasil->Lines->Add(pesan);

        pesan.sprintf(_D("x2 = %.6f"), x2);
        MemoHasil->Lines->Add(pesan);
    }
    else if (d == 0) {
        // Akar real dan kembar
        double x = -b / (2 * a);

        MemoHasil->Lines->Add("Akar-akar bersifat Real dan Sama (Kembar):");

        pesan.sprintf(_D("x1 = x2 = %.6f"), x);
        MemoHasil->Lines->Add(pesan);
    }
    else {
        // Akar kompleks/imajiner
        double sqrt_d = sqrt(-d);
        double realPart = -b / (2 * a);
        double imagPart = sqrt_d / (2 * a);

        MemoHasil->Lines->Add("Akar-akar bersifat Kompleks / Imajiner:");

        pesan.sprintf(_D("x1 = %.6f + i%.6f"), realPart, imagPart);
        MemoHasil->Lines->Add(pesan);

        pesan.sprintf(_D("x2 = %.6f - i%.6f"), realPart, imagPart);
        MemoHasil->Lines->Add(pesan);
    }
}
}
//---------------------------------------------------------------------------



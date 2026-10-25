object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Tugas Sekolah'
  ClientHeight = 480
  ClientWidth = 733
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Button1: TButton
    Left = 8
    Top = 432
    Width = 75
    Height = 25
    Caption = 'clear'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 96
    Top = 432
    Width = 75
    Height = 25
    Caption = 'execute'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 650
    Top = 432
    Width = 75
    Height = 25
    Caption = 'keluar'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Panel1: TPanel
    Left = 16
    Top = 8
    Width = 709
    Height = 409
    TabOrder = 3
    object Label1: TLabel
      Left = 34
      Top = 19
      Width = 33
      Height = 15
      Caption = 'Nilai a'
    end
    object Label2: TLabel
      Left = 34
      Top = 56
      Width = 34
      Height = 15
      Caption = 'Nilai b'
    end
    object Label3: TLabel
      Left = 34
      Top = 93
      Width = 33
      Height = 15
      Caption = 'Nilai c'
    end
    object Label8: TLabel
      Left = 12
      Top = 197
      Width = 232
      Height = 180
      Caption = 
        'Keterangan :'#13#10'============================='#13#10'Mencari nilai dari ' +
        'akar persamaan kuadrat. '#13#10'Berdasarkan koefisien a, b, dan c '#13#10'da' +
        'ri suatu persamaan kuadrat, '#13#10'tentukan dan tampilkan akarnya.'#13#10'P' +
        'ersamaan kuadrat adalah '#13#10'persamaan polinomial derajat dua, '#13#10'ya' +
        'ng ditulis dalam bentuk ax'#178' + bx + c = 0, '#13#10'di mana a tidak sama' +
        ' dengan nol.'#13#10'grafik akan ditampilkan dalam diagram  x,y.'#13#10'=====' +
        '========================'
    end
    object ImageGrafik: TImage
      Left = 272
      Top = 19
      Width = 417
      Height = 295
      IncrementalDisplay = True
    end
    object Edit1: TEdit
      Left = 121
      Top = 16
      Width = 75
      Height = 23
      TabOrder = 0
    end
    object Edit2: TEdit
      Left = 121
      Top = 53
      Width = 75
      Height = 23
      TabOrder = 1
    end
    object Edit3: TEdit
      Left = 121
      Top = 90
      Width = 75
      Height = 23
      TabOrder = 2
    end
    object MemoHasil: TMemo
      Left = 272
      Top = 320
      Width = 417
      Height = 81
      Lines.Strings = (
        'MemoHasil')
      TabOrder = 3
    end
  end
  object Button4: TButton
    Left = 185
    Top = 432
    Width = 75
    Height = 25
    Caption = 'grafik'
    TabOrder = 4
    OnClick = Button4Click
  end
end

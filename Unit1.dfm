object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'MST_Kruskal'#39's and Prim'#39's algorithms Made by W.R_Chen'
  ClientHeight = 384
  ClientWidth = 838
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 233
    Top = 0
    Height = 384
    ExplicitLeft = 384
    ExplicitTop = 272
    ExplicitHeight = 100
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 233
    Height = 384
    Align = alLeft
    TabOrder = 0
    ExplicitLeft = 48
    ExplicitTop = 8
    object Label1: TLabel
      Left = 56
      Top = 8
      Width = 48
      Height = 13
      Caption = 'G = (V, E)'
    end
    object Label2: TLabel
      Left = 16
      Top = 35
      Width = 31
      Height = 13
      Caption = '| V | ='
    end
    object Label3: TLabel
      Left = 16
      Top = 64
      Width = 42
      Height = 13
      Caption = 'Range ='
    end
    object Label4: TLabel
      Left = 16
      Top = 96
      Width = 42
      Height = 13
      Caption = 'if w(e) >'
    end
    object Label5: TLabel
      Left = 16
      Top = 123
      Width = 69
      Height = 13
      Caption = 'w(e) = MAX->'
    end
    object Label6: TLabel
      Left = 16
      Top = 224
      Width = 58
      Height = 13
      Caption = 'MST Solvers'
    end
    object CheckBox1: TCheckBox
      Left = 16
      Top = 155
      Width = 97
      Height = 17
      Caption = 'Echo Print G'
      Checked = True
      State = cbChecked
      TabOrder = 0
    end
    object Edit1: TEdit
      Left = 106
      Top = 32
      Width = 121
      Height = 21
      TabOrder = 1
      Text = '10'
    end
    object Edit2: TEdit
      Left = 106
      Top = 61
      Width = 121
      Height = 21
      TabOrder = 2
      Text = '1000'
    end
    object Edit3: TEdit
      Left = 106
      Top = 93
      Width = 121
      Height = 21
      TabOrder = 3
      Text = '200'
    end
    object Edit4: TEdit
      Left = 106
      Top = 120
      Width = 121
      Height = 21
      TabOrder = 4
      Text = '99999'
    end
    object Button1: TButton
      Left = 16
      Top = 193
      Width = 75
      Height = 25
      Caption = 'Generate G'
      TabOrder = 5
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 135
      Top = 193
      Width = 75
      Height = 25
      Caption = 'Read G'
      TabOrder = 6
      OnClick = Button2Click
    end
    object CheckBox2: TCheckBox
      Left = 16
      Top = 296
      Width = 169
      Height = 17
      Caption = 'Echo Print Edges in MST'
      Checked = True
      State = cbChecked
      TabOrder = 7
    end
    object Button3: TButton
      Left = 16
      Top = 265
      Width = 75
      Height = 25
      Caption = 'Kruskal'
      TabOrder = 8
      OnClick = Button3Click
    end
    object Button4: TButton
      Left = 135
      Top = 265
      Width = 75
      Height = 25
      Caption = 'Prim'
      TabOrder = 9
      OnClick = Button4Click
    end
  end
  object PageControl1: TPageControl
    Left = 236
    Top = 0
    Width = 602
    Height = 384
    ActivePage = TabSheet2
    Align = alClient
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = 'MST Found'
      ExplicitWidth = 565
      ExplicitHeight = 580
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 594
        Height = 356
        Align = alClient
        Lines.Strings = (
          'Memo1')
        TabOrder = 0
        ExplicitLeft = 192
        ExplicitTop = 248
        ExplicitWidth = 185
        ExplicitHeight = 89
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Grapg in Adjacent Matrix'
      ImageIndex = 1
      ExplicitWidth = 565
      ExplicitHeight = 580
      object StringGrid1: TStringGrid
        Left = 0
        Top = 0
        Width = 594
        Height = 356
        Align = alClient
        TabOrder = 0
        ExplicitLeft = 120
        ExplicitTop = 232
        ExplicitWidth = 320
        ExplicitHeight = 120
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Edges Matrix'
      ImageIndex = 2
      ExplicitWidth = 565
      ExplicitHeight = 580
      object StringGrid2: TStringGrid
        Left = 0
        Top = 0
        Width = 594
        Height = 356
        Align = alClient
        TabOrder = 0
        ExplicitLeft = 128
        ExplicitTop = 240
        ExplicitWidth = 320
        ExplicitHeight = 120
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 120
    Top = 328
  end
end

object ma: Tma
  Left = 235
  Top = 64
  Width = 633
  Height = 483
  AutoSize = True
  Caption = '11'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 224
    Top = 320
    Width = 169
    Height = 49
    TabOrder = 0
    object Label1: TLabel
      Left = 8
      Top = 8
      Width = 24
      Height = 13
      Caption = 'Host'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label3: TLabel
      Left = 96
      Top = 8
      Width = 19
      Height = 13
      Caption = 'end'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label4: TLabel
      Left = 136
      Top = 8
      Width = 30
      Height = 13
      Caption = 'Name'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ip: TEdit
      Left = 8
      Top = 24
      Width = 89
      Height = 21
      TabOrder = 0
      Text = '192.168.0.1'
    end
    object end_ip: TEdit
      Left = 96
      Top = 24
      Width = 25
      Height = 21
      Enabled = False
      TabOrder = 1
      Text = '255'
    end
    object GetName: TCheckBox
      Left = 136
      Top = 24
      Width = 17
      Height = 17
      Checked = True
      State = cbChecked
      TabOrder = 2
    end
  end
  object Panel3: TPanel
    Left = 400
    Top = 320
    Width = 169
    Height = 129
    TabOrder = 1
    object gethostip: TButton
      Left = 8
      Top = 8
      Width = 75
      Height = 25
      Caption = 'Host<-->IP'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = gethostipClick
    end
    object skan: TButton
      Left = 8
      Top = 72
      Width = 49
      Height = 25
      Caption = 'Skan ip'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      OnClick = skanClick
    end
    object trace: TButton
      Left = 112
      Top = 40
      Width = 49
      Height = 25
      Caption = 'Tracert'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      OnClick = traceClick
    end
    object Button5: TButton
      Left = 88
      Top = 72
      Width = 75
      Height = 25
      Caption = 'ARP Table'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
      OnClick = Button5Click
    end
    object Button6: TButton
      Left = 88
      Top = 8
      Width = 75
      Height = 25
      Caption = 'Ping'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 4
      OnClick = Button6Click
    end
    object sp: TButton
      Left = 8
      Top = 96
      Width = 75
      Height = 25
      Caption = 'Sckan ports'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 5
      OnClick = spClick
    end
    object Button3: TButton
      Left = 8
      Top = 40
      Width = 33
      Height = 25
      Caption = 'cmd'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 6
      OnClick = Button3Click
    end
    object Button7: TButton
      Left = 88
      Top = 96
      Width = 75
      Height = 25
      Caption = #1074' '#1092#1072#1081#1083
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 7
      OnClick = Button7Click
    end
    object CheckBox1: TCheckBox
      Left = 64
      Top = 72
      Width = 17
      Height = 17
      TabOrder = 8
    end
    object Button1: TButton
      Left = 40
      Top = 40
      Width = 33
      Height = 25
      Caption = 'ipc'
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 9
      OnClick = Button1Click
    end
    object Button10: TButton
      Left = 72
      Top = 40
      Width = 33
      Height = 25
      Caption = 'nsl'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 10
      OnClick = Button10Click
    end
  end
  object bar: TProgressBar
    Left = 224
    Top = 296
    Width = 401
    Height = 17
    Min = 0
    Max = 100
    TabOrder = 2
  end
  object Panel5: TPanel
    Left = 224
    Top = 376
    Width = 169
    Height = 73
    TabOrder = 3
    object Label5: TLabel
      Left = 8
      Top = 32
      Width = 67
      Height = 13
      Caption = #1089#1090#1072#1088#1090'     '#1089#1090#1086#1087
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object port_start: TEdit
      Left = 8
      Top = 48
      Width = 41
      Height = 21
      TabOrder = 0
      Text = '1'
    end
    object port_end: TEdit
      Left = 48
      Top = 48
      Width = 41
      Height = 21
      TabOrder = 1
      Text = '1024'
    end
    object C_netbios: TCheckBox
      Left = 96
      Top = 56
      Width = 65
      Height = 17
      Caption = 'Netbios'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
    end
    object C_http: TCheckBox
      Left = 96
      Top = 8
      Width = 41
      Height = 17
      Caption = 'http'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
    end
    object C_telnet: TCheckBox
      Left = 96
      Top = 24
      Width = 57
      Height = 17
      Caption = 'telnet'
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      State = cbChecked
      TabOrder = 4
    end
    object C_ftp: TCheckBox
      Left = 96
      Top = 40
      Width = 41
      Height = 17
      Caption = 'ftp'
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      State = cbChecked
      TabOrder = 5
    end
    object C_mail: TCheckBox
      Left = 40
      Top = 8
      Width = 49
      Height = 17
      Caption = 'mail'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 6
    end
  end
  object Panel6: TPanel
    Left = 0
    Top = 344
    Width = 217
    Height = 105
    TabOrder = 4
    object Label2: TLabel
      Left = 56
      Top = 8
      Width = 15
      Height = 13
      Caption = 'out'
    end
    object Label6: TLabel
      Left = 80
      Top = 8
      Width = 8
      Height = 13
      Caption = 'in'
    end
    object Label7: TLabel
      Left = 96
      Top = 8
      Width = 16
      Height = 13
      Caption = 'self'
    end
    object C_tcp: TCheckBox
      Left = 8
      Top = 24
      Width = 41
      Height = 17
      Caption = 'TCP'
      Checked = True
      State = cbChecked
      TabOrder = 0
      OnClick = C_tcpClick
    end
    object C_icmp: TCheckBox
      Left = 8
      Top = 40
      Width = 49
      Height = 17
      Caption = 'ICMP'
      Checked = True
      State = cbChecked
      TabOrder = 1
      OnClick = C_icmpClick
    end
    object C_igmp: TCheckBox
      Left = 8
      Top = 56
      Width = 49
      Height = 17
      Caption = 'IGMP'
      Checked = True
      State = cbChecked
      TabOrder = 2
      OnClick = C_igmpClick
    end
    object C_udp: TCheckBox
      Left = 8
      Top = 72
      Width = 49
      Height = 17
      Caption = 'UDP'
      Checked = True
      State = cbChecked
      TabOrder = 3
      OnClick = C_udpClick
    end
    object tcp_out: TCheckBox
      Left = 56
      Top = 24
      Width = 17
      Height = 17
      Checked = True
      State = cbChecked
      TabOrder = 4
    end
    object tcp_in: TCheckBox
      Left = 80
      Top = 24
      Width = 17
      Height = 17
      Checked = True
      State = cbChecked
      TabOrder = 5
    end
    object icmp_out: TCheckBox
      Left = 56
      Top = 40
      Width = 17
      Height = 17
      Checked = True
      State = cbChecked
      TabOrder = 6
    end
    object icmp_in: TCheckBox
      Left = 80
      Top = 40
      Width = 17
      Height = 17
      Checked = True
      State = cbChecked
      TabOrder = 7
    end
    object igmp_out: TCheckBox
      Left = 56
      Top = 56
      Width = 17
      Height = 17
      Checked = True
      State = cbChecked
      TabOrder = 8
    end
    object igmp_in: TCheckBox
      Left = 80
      Top = 56
      Width = 17
      Height = 17
      Checked = True
      State = cbChecked
      TabOrder = 9
    end
    object udp_out: TCheckBox
      Left = 56
      Top = 72
      Width = 17
      Height = 17
      Checked = True
      State = cbChecked
      TabOrder = 10
    end
    object udp_in: TCheckBox
      Left = 80
      Top = 72
      Width = 17
      Height = 17
      Checked = True
      State = cbChecked
      TabOrder = 11
    end
    object tcp_self: TCheckBox
      Left = 96
      Top = 24
      Width = 17
      Height = 17
      Checked = True
      State = cbChecked
      TabOrder = 12
      OnClick = tcp_selfClick
    end
    object icmp_self: TCheckBox
      Left = 96
      Top = 40
      Width = 17
      Height = 17
      Checked = True
      State = cbChecked
      TabOrder = 13
      OnClick = icmp_selfClick
    end
    object igmp_self: TCheckBox
      Left = 96
      Top = 56
      Width = 17
      Height = 17
      Checked = True
      State = cbChecked
      TabOrder = 14
      OnClick = igmp_selfClick
    end
    object udp_self: TCheckBox
      Left = 96
      Top = 72
      Width = 17
      Height = 17
      Checked = True
      State = cbChecked
      TabOrder = 15
      OnClick = udp_selfClick
    end
    object tabl: TCheckBox
      Left = 112
      Top = 56
      Width = 65
      Height = 17
      Caption = #1058#1072#1073#1083#1080#1094#1072
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      State = cbChecked
      TabOrder = 16
    end
    object golova: TCheckBox
      Left = 112
      Top = 72
      Width = 73
      Height = 17
      Caption = #1047#1072#1075#1086#1083#1086#1074#1086#1082
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 17
    end
    object alien: TCheckBox
      Left = 112
      Top = 24
      Width = 49
      Height = 17
      Caption = 'alien'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 18
      OnClick = alienClick
    end
    object Button2: TButton
      Left = 184
      Top = 8
      Width = 25
      Height = 25
      Caption = 'C'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 19
      OnClick = Button2Click
    end
    object Button9: TButton
      Left = 184
      Top = 32
      Width = 25
      Height = 25
      Caption = 'C'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 20
      OnClick = Button9Click
    end
  end
  object Panel8: TPanel
    Left = 0
    Top = 0
    Width = 625
    Height = 289
    TabOrder = 5
    object logos: TMemo
      Left = 1
      Top = 1
      Width = 623
      Height = 287
      Align = alClient
      Color = clMenuText
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clLime
      Font.Height = -11
      Font.Name = 'Courier'
      Font.Style = []
      ParentFont = False
      ScrollBars = ssVertical
      TabOrder = 0
    end
  end
  object Panel9: TPanel
    Left = 0
    Top = 296
    Width = 217
    Height = 41
    TabOrder = 6
    object Kontrol: TButton
      Left = 8
      Top = 8
      Width = 75
      Height = 25
      Caption = #1050#1086#1085#1090#1088#1086#1083#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = KontrolClick
    end
    object vis: TCheckBox
      Left = 88
      Top = 8
      Width = 41
      Height = 17
      Caption = #1042#1080#1076
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      State = cbChecked
      TabOrder = 1
      OnClick = CheckBox1Click
    end
    object Button4: TButton
      Left = 136
      Top = 8
      Width = 75
      Height = 25
      Caption = #1074' '#1092#1072#1081#1083
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      OnClick = Button4Click
    end
  end
  object Panel1: TPanel
    Left = 576
    Top = 320
    Width = 49
    Height = 129
    TabOrder = 7
    object SpeedButton1: TSpeedButton
      Left = 16
      Top = 72
      Width = 23
      Height = 22
      Caption = '...'
      OnClick = SpeedButton1Click
    end
    object Button8: TButton
      Left = 8
      Top = 8
      Width = 33
      Height = 33
      TabOrder = 0
      OnClick = Button8Click
    end
  end
  object ImageList1: TImageList
    Left = 184
    Top = 176
    Bitmap = {
      494C010103000400040010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000001000000001002000000000000010
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000DEDEDE21CCCC
      CC33E5E5E51AF8F8F807FEFEFE01000000000000000000000000000000000000
      00000000000000000000000000000000000000000000F7F7F708FBFBFB04FEFE
      FE01000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FEFEFE012DAED9FF0C87
      B1F3326B7FCD676767998C8C8C73BFBFBF40E0E0E01FF4F4F40BFEFEFE010000
      000000000000000000000000000000000000FEFEFE0181A7B47E6B6B6B949999
      9966C7C7C738E5E5E51AF8F8F807FEFEFE010000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FEFEFE0152BEE2FF71D7
      FFFF71D7FFFF71D7FFFF47C0ECFF0EA1D2FF25728CDA606060A08181817FB3B3
      B34CDADADA25FBFBFB040000000000000000FEFEFE0167C3E2FF6DD3FFFF37B7
      E6FF0E91BEF7326B7ECD6565659A8C8C8C73BFBFBF40E0E0E01FF4F4F40BFEFE
      FE01000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000A8E4A500A8E4A500A8E4A500A8E4A50000000000000000000000
      00000000000000000000000000000000000000000000FEFEFE0131AFD9FF7AE0
      FFFF7AE0FFFF7AE0FFFF7AE0FFFF7AE0FFFF7AE0FFFF7AE0FFFF5CCEF2FF1FAB
      D9FF26738CD9DEDEDE210000000000000000FEFEFE014CBDECFFA9E9FFFF76DC
      FFFF76DCFFFF76DCFFFF76DCFFFF4AC4ECFF0FA2D2FF25718BDA5F5F5FA08888
      8877F0F0F00F0000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000A8E4A500A8E4A500A8E4A500A8E4A500A8E4A500A8E4A500000000000000
      00000000000000000000000000000000000000000000FEFEFE0126AAD6FF83E9
      FFFF83E9FFFF83E9FFFF83E9FFFF83E9FFFF83E9FFFF83E9FFFF83E9FFFF83E9
      FFFF1AA6D9FFCBCBCB340000000000000000FEFEFE0177D0FAFFF7FDFFFF80E6
      FFFF80E6FFFF80E6FFFF80E6FFFF80E6FFFF80E6FFFF80E6FFFF80E6FFFF1A8A
      ACEEB9B9B9460000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000A8E4
      A500A8E4A500A8E4A500A8E4A500A8E4A500A8E4A500A8E4A500A8E4A5000000
      00000000000000000000000000000000000000000000FEFEFE0127AAD9FF8BF1
      FFFF8BF1FFFF8BF1FFFF8BF1FFFF8BF1FFFF8BF1FFFF8BF1FFFF8BF1FFFF8BF1
      FFFF44BFE6FFB0B0B04F0000000000000000FEFEFE0180D3FBFF80CCE6FF8AF0
      FFFF8AF0FFFF8AF0FFFF8AF0FFFF8AF0FFFF8AF0FFFF8AF0FFFF8AF0FFFF9DF9
      FCFF6B6B6B94F7F7F70800000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000A8E4
      A500A8E4A500A8E4A500A8E4A500A8E4A500A8E4A500A8E4A500A8E4A5000000
      00000000000000000000000000000000000000000000FEFEFE012BACD9FF94FA
      FFFF94FAFFFF94FAFFFF94FAFFFF94FAFFFF94FAFFFF94FAFFFF94FAFFFF94FA
      FFFF77D9F2FF9292926DFEFEFE0100000000FEFEFE018BD8FDFF30B1E4FFA8FB
      FFFF94FAFFFF94FAFFFF94FAFFFF94FAFFFF94FAFFFF94FAFFFF94FAFFFFBBFF
      FFFF236F88DCCECECE3100000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000A8E4
      A500A8E4A500A8E4A500A8E4A500A8E4A500A8E4A500A8E4A500A8E4A5000000
      00000000000000000000000000000000000000000000FDFDFD025DC1E6FF9EFF
      FFFF9EFFFFFF9EFFFFFF9EFFFFFF9EFFFFFF9EFFFFFF9EFFFFFF9EFFFFFF9EFF
      FFFFB2F2FFFF78787888FEFEFE0100000000FEFEFE018CD8FFFF66CCFFFFF3FF
      FFFFA3FFFFFFA3FFFFFFA3FFFFFFA3FFFFFFA3FFFFFFA3FFFFFFA3FFFFFFCEFF
      FFFF9BE6F2FF7D7D7D82FBFBFB04000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000A8E4
      A500A8E4A500A8E4A500A8E4A500A8E4A500A8E4A500A8E4A500A8E4A5000000
      00000000000000000000000000000000000000000000D6E9EF2967C7E9FFE1FA
      FFFFCBFDFFFFBCFFFFFFBAFFFFFFBAFFFFFFBAFFFFFFBAFFFFFFBAFFFFFFBAFF
      FFFFBDF2FFFF6666669AF9F9F90600000000F6F6F6099AE2FFFF74DAFFFF4AC3
      ECFF5EC4E6FF80CCE6FFDFF2F9FFCBFFFFFFC0FFFFFFC0FFFFFFC0FFFFFFE1FF
      FFFFE1FFFFFF356575CADEDEDE21000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000A8E4A500A8E4A500A8E4A500A8E4A500A8E4A500A8E4A500000000000000
      00000000000000000000000000000000000000000000B7DDEA48A1F4FFFF8FF5
      FFFF6CDFF2FF37BCDFFF6AC4E2FFD5FFFFFFD3FFFFFFD3FFFFFFD3FFFFFFD3FF
      FFFFCAF2FFFF436A77BCEFEFEF1000000000B7DDEA4897ECFFFF85EBFFFF85EB
      FFFF85EBFFFF85EBFFFF85EBFFFF68C5E2FFF5FFFFFFEDFFFFFFE5FFFFFFF4FF
      FFFFF4FFFFFF89D2E9FF9B9B9B64FEFEFE010000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000A8E4A500A8E4A500A8E4A500A8E4A50000000000000000000000
      00000000000000000000000000000000000000000000BBE1EE44ACFDFFFF99FF
      FFFF99FFFFFF99FFFFFF8FF9FCFF23ACD6FF5EBFDFFFACDEEFFFF8FEFFFFF4FF
      FFFFDEF5FFFF327F98CDEAEAEA1500000000B7DDEA48A8FAFFFF96FCFFFF96FC
      FFFF96FCFFFF96FCFFFF96FCFFFF96FCFFFF96FCFFFF8DF6FCFF5FD8ECFF2892
      B5E670C6E2FFBFE6F2FFD7D7D728000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000E3F4FCFF99FF
      FFFF99FFFFFF99FFFFFF97D6ECFF63BBD9D888D0E9FFC4E8F5FFD7FCFFFFB6FE
      FFFF418EA8BEBCD8E243FDFDFD0200000000DEF1F721CCFBFFFF99FFFFFF99FF
      FFFF99FFFFFFD7FBFFFFC3FCFFFFAEFEFFFF99FFFFFF99FFFFFF99FFFFFF6E6E
      6E91FEFEFE010000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000007DC9E3824DB7
      DAF180CCE6FFBFE6F2FFCAD3D635FEFEFE010000000000000000FEFEFE01FEFE
      FE01FEFEFE01000000000000000000000000000000007BCBE6FFE1FDFFFFC3FE
      FFFFD5FEFFFF5B94A7A4FBFBFB04CDE9F33279C5DF8667BEDCC56BC4E2FFE1E1
      E11E000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FEFEFE01DEF1
      F721B8DEEB47FBFBFB0400000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000100000000100010000000000800000000000000000000000
      000000000000000000000000FFFFFF00FFFFFFFFFFFF0000FFFFC1FF8FFF0000
      FFFF801F00FF0000FFFF8003000F0000F87F800300070000F03F800300070000
      E01F800300030000E01F800100030000E01F800100010000E01F800100010000
      F03F800100000000F87F800100010000FFFFC00100070000FFFFC0C7800F0000
      FFFFFFFFC3FF0000FFFFFFFFFFFF000000000000000000000000000000000000
      000000000000}
  end
  object TimerBar: TTimer
    Left = 112
    Top = 48
  end
end

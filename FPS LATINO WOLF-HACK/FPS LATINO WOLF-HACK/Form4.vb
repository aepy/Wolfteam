Imports System.Net
Imports System.IO
Imports System.Text
Imports System.Security.Cryptography
Public Class Form4

    Dim client As New WebClient

    Private Declare Function GetAsyncKeyState Lib "user32" (ByVal vKey As Long) As Integer
    Private Sub Form4_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        'Dim p As Process = Process.GetProcessesByName("WolfTeam.bin")(0)
        'For Each moz As System.Diagnostics.ProcessModule In p.Modules
        '    If moz.FileName.IndexOf("csh") <> -1 Then
        '        csh.Text = moz.BaseAddress.ToString
        '    End If
        'Next
        'For Each moz1 As System.Diagnostics.ProcessModule In p.Modules
        '    If moz1.FileName.IndexOf("WolfTeam.bin") <> -1 Then
        '        bin.Text = moz1.BaseAddress.ToString
        '    End If
        'Next
        ''client.DownloadString("http://peliculascorp.tk/count.php?action=add")
    End Sub

    Private Sub Up_Down_Tick(sender As Object, e As EventArgs) Handles Up_Down.Tick
        If GetAsyncKeyState(Keys.Down) = -32767 Then
            If Label1.ForeColor = Color.DeepSkyBlue Then
                Label1.ForeColor = Color.White
                Label2.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label2.ForeColor = Color.DeepSkyBlue Then
                Label2.ForeColor = Color.White
                Label3.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label3.ForeColor = Color.DeepSkyBlue Then
                Label3.ForeColor = Color.White
                Label4.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label4.ForeColor = Color.DeepSkyBlue Then
                Label4.ForeColor = Color.White
                Label5.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label5.ForeColor = Color.DeepSkyBlue Then
                Label5.ForeColor = Color.White
                Label6.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label6.ForeColor = Color.DeepSkyBlue Then
                Label6.ForeColor = Color.White
                Label7.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label7.ForeColor = Color.DeepSkyBlue Then
                Label7.ForeColor = Color.White
                Label8.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label8.ForeColor = Color.DeepSkyBlue Then
                Label8.ForeColor = Color.White
                Label9.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label9.ForeColor = Color.DeepSkyBlue Then
                Label9.ForeColor = Color.White
                Label10.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label10.ForeColor = Color.DeepSkyBlue Then
                Label10.ForeColor = Color.White
                Label11.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label11.ForeColor = Color.DeepSkyBlue Then
                Label11.ForeColor = Color.White
                Label12.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label12.ForeColor = Color.DeepSkyBlue Then
                Label12.ForeColor = Color.White
                Label13.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label13.ForeColor = Color.DeepSkyBlue Then
                Label13.ForeColor = Color.White
                Label14.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label14.ForeColor = Color.DeepSkyBlue Then
                Label14.ForeColor = Color.White
                Label15.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label15.ForeColor = Color.DeepSkyBlue Then
                Label15.ForeColor = Color.White
                Label49.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label49.ForeColor = Color.DeepSkyBlue Then
                Label49.ForeColor = Color.White
                Label52.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label52.ForeColor = Color.DeepSkyBlue Then
                Label52.ForeColor = Color.White
                Label60.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label60.ForeColor = Color.DeepSkyBlue Then
                Label60.ForeColor = Color.White
                Label54.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label54.ForeColor = Color.DeepSkyBlue Then
                Label54.ForeColor = Color.White
                Label56.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label56.ForeColor = Color.DeepSkyBlue Then
                Label56.ForeColor = Color.White
                Label57.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label57.ForeColor = Color.DeepSkyBlue Then
                Label57.ForeColor = Color.White
                Label64.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label64.ForeColor = Color.DeepSkyBlue Then
                Label64.ForeColor = Color.White
                Label16.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label16.ForeColor = Color.DeepSkyBlue Then
                Label16.ForeColor = Color.White
                Label17.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label17.ForeColor = Color.DeepSkyBlue Then
                Label17.ForeColor = Color.White
                Label37.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label37.ForeColor = Color.DeepSkyBlue Then
                Label37.ForeColor = Color.White
                Label40.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label40.ForeColor = Color.DeepSkyBlue Then
                Label40.ForeColor = Color.White
                Label42.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label42.ForeColor = Color.DeepSkyBlue Then
                Label42.ForeColor = Color.White
                Label43.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label43.ForeColor = Color.DeepSkyBlue Then
                Label43.ForeColor = Color.White
                Label46.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label46.ForeColor = Color.DeepSkyBlue Then
                Label46.ForeColor = Color.White
                Label48.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label48.ForeColor = Color.DeepSkyBlue Then
                Label48.ForeColor = Color.White
                Label62.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label62.ForeColor = Color.DeepSkyBlue Then
                Label62.ForeColor = Color.White
                Label35.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label35.ForeColor = Color.DeepSkyBlue Then
                Label35.ForeColor = Color.White
                Label1.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
        End If

        '--------------------Dowm--------------------
        ' UP Code
        '-------------------- UP --------------------

        If GetAsyncKeyState(Keys.Up) = -32767 Then
            If Label35.ForeColor = Color.DeepSkyBlue Then
                Label35.ForeColor = Color.White
                Label62.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label62.ForeColor = Color.DeepSkyBlue Then
                Label62.ForeColor = Color.White
                Label48.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label48.ForeColor = Color.DeepSkyBlue Then
                Label48.ForeColor = Color.White
                Label46.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label46.ForeColor = Color.DeepSkyBlue Then
                Label46.ForeColor = Color.White
                Label43.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label43.ForeColor = Color.DeepSkyBlue Then
                Label43.ForeColor = Color.White
                Label42.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label42.ForeColor = Color.DeepSkyBlue Then
                Label42.ForeColor = Color.White
                Label40.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label40.ForeColor = Color.DeepSkyBlue Then
                Label40.ForeColor = Color.White
                Label37.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label37.ForeColor = Color.DeepSkyBlue Then
                Label37.ForeColor = Color.White
                Label17.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label17.ForeColor = Color.DeepSkyBlue Then
                Label17.ForeColor = Color.White
                Label16.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label16.ForeColor = Color.DeepSkyBlue Then
                Label16.ForeColor = Color.White
                Label64.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label64.ForeColor = Color.DeepSkyBlue Then
                Label64.ForeColor = Color.White
                Label57.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label57.ForeColor = Color.DeepSkyBlue Then
                Label57.ForeColor = Color.White
                Label56.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label56.ForeColor = Color.DeepSkyBlue Then
                Label56.ForeColor = Color.White
                Label54.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label54.ForeColor = Color.DeepSkyBlue Then
                Label54.ForeColor = Color.White
                Label60.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label60.ForeColor = Color.DeepSkyBlue Then
                Label60.ForeColor = Color.White
                Label52.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label52.ForeColor = Color.DeepSkyBlue Then
                Label52.ForeColor = Color.White
                Label49.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label49.ForeColor = Color.DeepSkyBlue Then
                Label49.ForeColor = Color.White
                Label15.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label15.ForeColor = Color.DeepSkyBlue Then
                Label15.ForeColor = Color.White
                Label14.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label14.ForeColor = Color.DeepSkyBlue Then
                Label14.ForeColor = Color.White
                Label13.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label13.ForeColor = Color.DeepSkyBlue Then
                Label13.ForeColor = Color.White
                Label12.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label12.ForeColor = Color.DeepSkyBlue Then
                Label12.ForeColor = Color.White
                Label11.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label11.ForeColor = Color.DeepSkyBlue Then
                Label11.ForeColor = Color.White
                Label10.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label10.ForeColor = Color.DeepSkyBlue Then
                Label10.ForeColor = Color.White
                Label9.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label9.ForeColor = Color.DeepSkyBlue Then
                Label9.ForeColor = Color.White
                Label8.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label8.ForeColor = Color.DeepSkyBlue Then
                Label8.ForeColor = Color.White
                Label7.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label7.ForeColor = Color.DeepSkyBlue Then
                Label7.ForeColor = Color.White
                Label6.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label6.ForeColor = Color.DeepSkyBlue Then
                Label6.ForeColor = Color.White
                Label5.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label5.ForeColor = Color.DeepSkyBlue Then
                Label5.ForeColor = Color.White
                Label4.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label4.ForeColor = Color.DeepSkyBlue Then
                Label4.ForeColor = Color.White
                Label3.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label3.ForeColor = Color.DeepSkyBlue Then
                Label3.ForeColor = Color.White
                Label2.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label2.ForeColor = Color.DeepSkyBlue Then
                Label2.ForeColor = Color.White
                Label1.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
            If Label1.ForeColor = Color.DeepSkyBlue Then
                Label1.ForeColor = Color.White
                Label35.ForeColor = Color.DeepSkyBlue
                Exit Sub
            End If
        End If
    End Sub

    
    ' Dim Respawn0 As Integer = &H78DA0 'l
    ' Dim Recoil As Integer = &H825F3 'l
    'Dim Wallshot As Integer = &H4FAE0 'l
    ' Dim NameEsp As Integer = &H378AC6 'l

    ' Dim RespWhereDie As Integer = &H102E35 'l

    'Dim NoFall As Integer = &H106B43 'l
    'Dim RapidFire As Integer = &H12E2AB 'l
    'Dim Reload1 As Integer = &H127823 'l
    ' Dim AutoFire As Integer = &H127F25 'l
    ' Dim Reload2 As Integer = &H12C1FE 'l
    'Dim InfAmmo1 As Integer = &H132245 'l
    'Dim InfAmmo2 As Integer = &H13228C 'l
    'Dim Spread As Integer = &H1453C3 'l
    'Dim WeaponSP As Integer = &H1746F3 'l
    'Dim WolfView As Integer = &H17B55B 'l
    ' Dim Wolfagarre As Integer = &H101A66 'l
    'Dim Jump As Integer = &H42320C 'l

    'Dim SpeedHack As Integer = &HB6301 'l
    '###################################
    '#-----------FPSLATINO.NET----------#
    '#----------Hecho por Aero-------------#
    '#--------WolfTeam Logger 2017-------------#
    '####################################


    '@@@@@@@@@@ CShell @@@@@@@@@@
    Dim NameEsp As Integer = &H375366
    Dim Respawn0 As Integer = &H791E0
    Dim Recoil As Integer = &H82A63
    Dim SpeedHack As Integer = &HB6BD1
    Dim NoFall As Integer = &H1066F3
    Dim RapidFire As Integer = &H12DA6B
    Dim Reload1 As Integer = &H126FF3
    Dim Reload2 As Integer = &H12B9BE
    Dim Infiniteammo1 As Integer = &H131955
    Dim Infiniteammo2 As Integer = &H13199C
    Dim Spread As Integer = &H144203
    Dim WeaponSP As Integer = &H173823
    Dim RespWhereDie As Integer = &H1029E5
    Dim Autofire As Integer = &H1276F5
    Dim Jumpspeed As Integer = &H41DBF4
    Dim WolfView As Integer = &H17A61B
    Dim Wolfagarre As Integer = &H101606
    '@@@@@@@@@@ BIN @@@@@@@@@@
    Dim Wallshot As Integer = &H4F970


    Dim RegresBase As Integer = &H6D9B2C 'l
    Dim Gravity As Integer = &H1050AD 'l
    Dim CrossHair As Integer = &H6D9F70 'l
    Dim WolfAttack As Integer = &H422934 'l
    Dim WolfDash As Integer = &H565CD 'l
    Dim WolfDashGL As Integer = &H1DD25 'l
    Dim CamaraBug As Integer = &H178B40 '
    Dim CamaraBugv2 As Integer = &H71FEC '
    Dim WolfBalls As Integer = &H6DA5F4 '
    Dim HP399 As Integer = &H57AB9 'l
    Dim FlyHack3 As Integer = &H55870 'l

    Dim MatarHit As Integer = &H21536 '
    Dim Inmortalidad As Integer = &H2DFD4 '

    Dim GodMode1 As Integer = &H82445 '&H21554       'obj 'D9 45 08 D9 45 FC F7 C2
    Dim GodMode2 As Integer = &H2DF44 '&H2DD64       'obj 'D9 45 08 D9 9E ?? ?? ?? ?? 8B 0D ?? ?? ?? ?? 8B 11 8B 42 6C FF D0 D9 9E ?? ?? ?? ?? D9 45 08 B3
    Dim FreezePlayers As Integer = &HE667 '

    Dim SiempreHS As Integer = &H82775 '
    Dim TeamKill As Integer = &H5A80E '
    Dim WolfHack As Integer = &H6C38A8 '&H6C38A8 '09 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 01 00 00 00 00 00 00 00 A8 5F D3 07 00 00 00 00 00 00 00 00 00 00 00 00 00 00 80 3F CE B3 55 0A C0 A8 B7 39 CF B3 55 0A C8 A8 B7 39 00 00 00
    Dim ModeHack1 As Integer = &H63F724
    Dim ModeHack2 As Integer = &H6AC7AC


    'Private Sub Left_Right_Tick(sender As Object, e As EventArgs) Handles Left_Right.Tick
    '    If GetAsyncKeyState(Keys.Right) = -32767 Then
    '        If Label1.ForeColor = Color.DeepSkyBlue Then
    '            Label18.ForeColor = Color.Green
    '            Label18.Text = "[1/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + NameEsp, "2268606836") 'NameEsp On
    '            Exit Sub
    '        End If
    '        If Label2.ForeColor = Color.DeepSkyBlue Then
    '            Label19.ForeColor = Color.Green
    '            Label19.Text = "[1/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + Respawn0, "1574503796") 'Respawn 0 On
    '            Exit Sub
    '        End If
    '        If Label3.ForeColor = Color.DeepSkyBlue Then
    '            Label20.ForeColor = Color.Green
    '            Label20.Text = "[1/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + Recoil, "2665025140") 'No Recoil On
    '            Exit Sub
    '        End If
    '        If Label4.ForeColor = Color.DeepSkyBlue Then
    '            Label21.ForeColor = Color.Green
    '            Label21.Text = "[1/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + NoFall, "2654543220") 'No Fall Damage On
    '            Exit Sub
    '        End If
    '        If Label5.ForeColor = Color.DeepSkyBlue Then
    '            Label22.ForeColor = Color.Green
    '            Label22.Text = "[1/1]"
    '            WriteLong("Wolfteam.bin", csh.Text + SpeedHack, "98110580") 'Speed Hack x4 On
    '            Exit Sub
    '        End If
    '        If Label6.ForeColor = Color.DeepSkyBlue Then
    '            Label23.ForeColor = Color.Green
    '            Label23.Text = "[1/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + RapidFire, "1574503796") 'Rapid Fire On
    '            Exit Sub
    '        End If
    '        If Label7.ForeColor = Color.DeepSkyBlue Then
    '            Label24.ForeColor = Color.Green
    '            Label24.Text = "[1/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + Reload1, "2257258100") 'No Reload 1 On
    '            WriteLong("WolfTeam.bin", csh.Text + Reload2, "2257258100") 'No Reload 2 On
    '            Exit Sub
    '        End If
    '        If Label8.ForeColor = Color.DeepSkyBlue Then
    '            Label25.ForeColor = Color.Green
    '            Label25.Text = "[1/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + Infiniteammo1, "4252861286") 'Inf Ammo 1 On
    '            WriteLong("WolfTeam.bin", csh.Text + Infiniteammo2, "4252861286") 'Inf Ammo 2 On
    '            Exit Sub
    '        End If
    '        If Label9.ForeColor = Color.DeepSkyBlue Then
    '            Label26.ForeColor = Color.Green
    '            Label26.Text = "[1/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + Spread, "1301090420") 'No Spread On
    '            Exit Sub
    '        End If
    '        If Label10.ForeColor = Color.DeepSkyBlue Then
    '            Label27.ForeColor = Color.Green
    '            Label27.Text = "[1/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + WeaponSP, "3071218292") 'Weapon SP On
    '            Exit Sub
    '        End If
    '        If Label11.ForeColor = Color.DeepSkyBlue Then
    '            Label28.ForeColor = Color.Green
    '            Label28.Text = "[1/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + RespWhereDie, "3897951979") 'RespWhereDie On
    '            Exit Sub
    '        End If
    '        If Label12.ForeColor = Color.DeepSkyBlue Then
    '            Label29.ForeColor = Color.Green
    '            Label29.Text = "[1/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + AutoFire, "6951147") 'Auto Fire On
    '            Exit Sub
    '        End If
    '        If Label13.ForeColor = Color.DeepSkyBlue Then
    '            Label30.ForeColor = Color.Green
    '            Label30.Text = "[1/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + WolfView, "2341280884") 'Wolf view On
    '            Exit Sub
    '        End If
    '        If Label14.ForeColor = Color.DeepSkyBlue Then
    '            Label31.ForeColor = Color.Green
    '            Label31.Text = "[1/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + Gravity, "5") 'No Gravity On
    '            Exit Sub
    '        End If
    '        If Label15.ForeColor = Color.DeepSkyBlue Then
    '            Label32.ForeColor = Color.Green
    '            Label32.Text = "[1/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + WolfDash, "28312949") 'Wolf Dash On
    '            Exit Sub
    '        End If

    '        If Label49.ForeColor = Color.DeepSkyBlue Then
    '            Label51.ForeColor = Color.Green
    '            Label51.Text = "[1/1]"
    '            WolfGL.Enabled = True 'Wolf Dash GL On
    '            Exit Sub
    '        End If
    '        If Label52.ForeColor = Color.DeepSkyBlue Then
    '            Label53.ForeColor = Color.Green
    '            Label53.Text = "[1/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + Wolfagarre, "845022581") 'Wolf Dash Agarre On
    '            Exit Sub
    '        End If

    '        If Label60.ForeColor = Color.DeepSkyBlue Then
    '            Label61.ForeColor = Color.Green
    '            Label61.Text = "[1/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + WolfAttack, "1167867904") 'Wolf Attack Speed On
    '            Exit Sub
    '        End If

    '        If Label54.ForeColor = Color.DeepSkyBlue Then
    '            Label55.ForeColor = Color.Green
    '            Label55.Text = "[1/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + HP399, "4169338485") 'HP 399 On
    '            Exit Sub
    '        End If
    '        If Label56.ForeColor = Color.DeepSkyBlue Then
    '            Label58.ForeColor = Color.Green
    '            Label58.Text = "[1/1]"
    '            Team_Kill.Enabled = True
    '            Exit Sub
    '        End If
    '        If Label57.ForeColor = Color.DeepSkyBlue Then
    '            Label59.ForeColor = Color.Green
    '            Label59.Text = "[1/1]"
    '            Frezzer_All.Enabled = True
    '            Exit Sub
    '        End If

    '        If Label64.ForeColor = Color.DeepSkyBlue Then
    '            Label65.ForeColor = Color.Green
    '            Label65.Text = "[1/1]"
    '            FlyHack.Enabled = True 'Fly Hack On
    '            Exit Sub
    '        End If

    '        If Label16.ForeColor = Color.DeepSkyBlue And Label33.Text = "[0/3]" Then
    '            Label33.ForeColor = Color.Green
    '            Label33.Text = "[1/3]"
    '            WriteLong("WolfTeam.bin", csh.Text + Jumpspeed, "1065353216") 'Jump x1 On
    '            Exit Sub
    '        End If
    '        If Label16.ForeColor = Color.DeepSkyBlue And Label33.Text = "[1/3]" Then
    '            Label33.ForeColor = Color.Green
    '            Label33.Text = "[2/3]"
    '            WriteLong("WolfTeam.bin", csh.Text + Jumpspeed, "1072064102") 'Jump x2 On
    '            Exit Sub
    '        End If
    '        If Label16.ForeColor = Color.DeepSkyBlue And Label33.Text = "[2/3]" Then
    '            Label33.ForeColor = Color.Green
    '            Label33.Text = "[3/3]"
    '            WriteLong("WolfTeam.bin", csh.Text + Jumpspeed, "1075419546") 'Jump x3 On
    '            Exit Sub
    '        End If
    '        If Label17.ForeColor = Color.DeepSkyBlue Then
    '            Label34.ForeColor = Color.Green
    '            Label34.Text = "[1/1]"
    '            Siempre_HS.Enabled = True
    '            Exit Sub
    '        End If
    '        If Label37.ForeColor = Color.DeepSkyBlue Then
    '            Label38.ForeColor = Color.Green
    '            Label38.Text = "[1/1]"
    '            Regresar_Base.Enabled = True
    '            Exit Sub
    '        End If
    '        If Label40.ForeColor = Color.DeepSkyBlue Then
    '            Label41.ForeColor = Color.Green
    '            Label41.Text = "[1/1]"
    '            cross.Enabled = True
    '            Exit Sub
    '        End If
    '        If Label42.ForeColor = Color.DeepSkyBlue Then
    '            Label44.ForeColor = Color.Green
    '            Label44.Text = "[1/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + CamaraBug, "2665023604") 'Camara Bug on
    '            Exit Sub
    '        End If
    '        If Label43.ForeColor = Color.DeepSkyBlue Then
    '            Label45.ForeColor = Color.Green
    '            Label45.Text = "[1/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + CamaraBugv2, "2665032052") 'Camara Bug v2 on
    '            Exit Sub
    '        End If
    '        If Label46.ForeColor = Color.DeepSkyBlue Then
    '            Label47.ForeColor = Color.Green
    '            Label47.Text = "[1/1]"
    '            Inmor.Enabled = True
    '            Exit Sub
    '        End If
    '        If Label48.ForeColor = Color.DeepSkyBlue Then
    '            Label50.ForeColor = Color.Green
    '            Label50.Text = "[1/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + WolfBalls, "999999999") 'Wolf Balls On
    '            Exit Sub
    '        End If

    '        If Label62.ForeColor = Color.DeepSkyBlue Then
    '            Label63.ForeColor = Color.Green
    '            Label63.Text = "[1/1]"
    '            Matar1Hit.Enabled = True 'Matar de 1 Hit
    '            Exit Sub
    '        End If

    '        If Label35.ForeColor = Color.DeepSkyBlue Then
    '            Label36.ForeColor = Color.Green
    '            Label36.Text = "[1/1]"
    '            Process.Start("http://fpslatino.net")
    '            Exit Sub
    '        End If
    '    End If
    '    '---------------Encendido Arriba---------------
    '    ' Aqui Cambian las Opciones
    '    '--------------- Apagado  Abajo ---------------

    '    If GetAsyncKeyState(Keys.Left) = -32767 Then
    '        If Label1.ForeColor = Color.DeepSkyBlue Then
    '            Label18.ForeColor = Color.Red
    '            Label18.Text = "[0/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + NameEsp, "2268606837") 'NameESP Off           
    '            Exit Sub
    '        End If
    '        If Label2.ForeColor = Color.DeepSkyBlue Then
    '            Label19.ForeColor = Color.Red
    '            Label19.Text = "[0/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + Respawn0, "1574503797") 'Respawn 0 Off
    '            Exit Sub
    '        End If
    '        If Label3.ForeColor = Color.DeepSkyBlue Then
    '            Label20.ForeColor = Color.Red
    '            Label20.Text = "[0/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + Recoil, "2665025141") 'No Recoil Off
    '            Exit Sub
    '        End If
    '        If Label4.ForeColor = Color.DeepSkyBlue Then
    '            Label21.ForeColor = Color.Red
    '            Label21.Text = "[0/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + NoFall, "2654543221") 'No Fall Damage Off
    '            Exit Sub
    '        End If
    '        If Label5.ForeColor = Color.DeepSkyBlue Then
    '            Label22.ForeColor = Color.Red
    '            Label22.Text = "[0/1]"
    '            WriteLong("Wolfteam.bin", csh.Text + SpeedHack, "98110581") 'Speed Hack x4 Off
    '            Exit Sub
    '        End If
    '        If Label6.ForeColor = Color.DeepSkyBlue Then
    '            Label23.ForeColor = Color.Red
    '            Label23.Text = "[0/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + RapidFire, "1574503797") 'Rapid Fire Off
    '            Exit Sub
    '        End If
    '        If Label7.ForeColor = Color.DeepSkyBlue Then
    '            Label24.ForeColor = Color.Red
    '            Label24.Text = "[0/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + Reload1, "2257258101") 'No Reload 1 Off
    '            WriteLong("WolfTeam.bin", csh.Text + Reload2, "2257258101") 'No Reload 2 Off
    '            Exit Sub
    '        End If
    '        If Label8.ForeColor = Color.DeepSkyBlue Then
    '            Label25.ForeColor = Color.Red
    '            Label25.Text = "[0/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + Infiniteammo1, "4236084070") 'Inf Ammo 1 Off
    '            WriteLong("WolfTeam.bin", csh.Text + Infiniteammo2, "4236084070") 'Inf Ammo 2 Off
    '            Exit Sub
    '        End If
    '        If Label9.ForeColor = Color.DeepSkyBlue Then
    '            Label26.ForeColor = Color.Red
    '            Label26.Text = "[0/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + Spread, "1301090421") 'No Spread Off
    '            Exit Sub
    '        End If
    '        If Label10.ForeColor = Color.DeepSkyBlue Then
    '            Label27.ForeColor = Color.Red
    '            Label27.Text = "[0/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + WeaponSP, "3071218293") 'Weapon SP Off
    '            Exit Sub
    '        End If
    '        If Label11.ForeColor = Color.DeepSkyBlue Then
    '            Label28.ForeColor = Color.Red
    '            Label28.Text = "[0/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + RespWhereDie, "3897951860") 'RespWhereDie Off
    '            Exit Sub
    '        End If
    '        If Label12.ForeColor = Color.DeepSkyBlue Then
    '            Label29.ForeColor = Color.Red
    '            Label29.Text = "[0/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + AutoFire, "6951029") 'Auto Fire Off
    '            Exit Sub
    '        End If
    '        If Label13.ForeColor = Color.DeepSkyBlue Then
    '            Label30.ForeColor = Color.Red
    '            Label30.Text = "[0/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + WolfView, "2341280885") 'Wolf View
    '            Exit Sub
    '        End If
    '        If Label14.ForeColor = Color.DeepSkyBlue Then
    '            Label31.ForeColor = Color.Red
    '            Label31.Text = "[0/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + Gravity, "1967244534") 'No Gravity Off
    '            Exit Sub
    '        End If
    '        If Label15.ForeColor = Color.DeepSkyBlue Then
    '            Label32.ForeColor = Color.Red
    '            Label32.Text = "[0/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + WolfDash, "28312948") 'Wolf Dash Off
    '            Exit Sub
    '        End If

    '        If Label49.ForeColor = Color.DeepSkyBlue Then
    '            Label51.ForeColor = Color.Red
    '            Label51.Text = "[0/1]"
    '            WolfGL.Enabled = False
    '            WriteLong("WolfTeam.bin", obj.Text + WolfDashGL, "378215540") 'Wolf Dash Giro Off
    '            Exit Sub
    '        End If
    '        If Label52.ForeColor = Color.DeepSkyBlue Then
    '            Label53.ForeColor = Color.Red
    '            Label53.Text = "[0/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + Wolfagarre, "845022580") 'Wolf Dash Agarre Off
    '            Exit Sub
    '        End If

    '        If Label60.ForeColor = Color.DeepSkyBlue Then
    '            Label61.ForeColor = Color.Red
    '            Label61.Text = "[0/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + WolfAttack, "1145569280") 'Wolf Attack Speed Off
    '            Exit Sub
    '        End If

    '        If Label54.ForeColor = Color.DeepSkyBlue Then
    '            Label55.ForeColor = Color.Green
    '            Label55.Text = "[0/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + HP399, "4169338484") 'HP 399 Off
    '            Exit Sub
    '        End If
    '        If Label56.ForeColor = Color.DeepSkyBlue Then
    '            Label58.ForeColor = Color.Red
    '            Label58.Text = "[0/1]"
    '            Team_Kill.Enabled = False
    '            WriteLong("WolfTeam.bin", obj.Text + TeamKill, "410318469") 'TeamKill Off
    '            Exit Sub
    '        End If
    '        If Label57.ForeColor = Color.DeepSkyBlue Then
    '            Label59.ForeColor = Color.Red
    '            Label59.Text = "[0/1]"
    '            Frezzer_All.Enabled = False
    '            WriteLong("WolfTeam.bin", obj.Text + FreezePlayers, "1574503797") 'Frezzer All Off
    '            Exit Sub
    '        End If

    '        If Label64.ForeColor = Color.DeepSkyBlue Then
    '            Label65.ForeColor = Color.Red
    '            Label65.Text = "[0/1]"
    '            FlyHack.Enabled = False
    '            WritePointerInteger("Wolfteam.bin", csh.Text + FlyHack3, "0", &H358) 'Fly Hack Off

    '            Exit Sub
    '        End If

    '        If Label16.ForeColor = Color.DeepSkyBlue Then
    '            Label33.ForeColor = Color.Red
    '            Label33.Text = "[0/3]"
    '            WriteLong("WolfTeam.bin", csh.Text + Jumpspeed, "1062165545") 'Jump Off
    '            Exit Sub
    '        End If
    '        If Label17.ForeColor = Color.DeepSkyBlue Then
    '            Label34.ForeColor = Color.Red
    '            Label34.Text = "[0/1]"
    '            Siempre_HS.Enabled = False
    '            WriteLong("Wolfteam.bin", obj.Text + SiempreHS, "1566490674") 'always Hs off
    '            Exit Sub
    '        End If
    '        If Label37.ForeColor = Color.DeepSkyBlue Then
    '            Label38.ForeColor = Color.Red
    '            Label38.Text = "[0/1]"
    '            Regresar_Base.Enabled = False
    '            WriteLong("WolfTeam.bin", csh.Text + RegresBase, "1") 'Regresar Base [T] Off
    '            Exit Sub
    '        End If
    '        If Label40.ForeColor = Color.DeepSkyBlue Then
    '            Label41.ForeColor = Color.Red
    '            Label41.Text = "[0/1]"
    '            cross.Enabled = False
    '            WriteLong("wolfteam.bin", csh.Text + CrossHair, "1574503797") 'CrossHair Off
    '            Exit Sub
    '        End If
    '        If Label42.ForeColor = Color.DeepSkyBlue Then
    '            Label44.ForeColor = Color.Red
    '            Label44.Text = "[0/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + CamaraBug, "2665023605") 'Camara Bug Off
    '            Exit Sub
    '        End If
    '        If Label43.ForeColor = Color.DeepSkyBlue Then
    '            Label45.ForeColor = Color.Red
    '            Label45.Text = "[0/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + CamaraBugv2, "2665032053") 'Camara Bug v2 Off
    '            Exit Sub
    '        End If
    '        If Label46.ForeColor = Color.DeepSkyBlue Then
    '            Label47.ForeColor = Color.Red
    '            Label47.Text = "[0/1]"
    '            Inmor.Enabled = False
    '            WriteLong("WolfTeam.bin", obj.Text + Inmortalidad, "3641198041") 'Inmortalidad Off
    '            Exit Sub
    '        End If
    '        If Label48.ForeColor = Color.DeepSkyBlue Then
    '            Label50.ForeColor = Color.Red
    '            Label50.Text = "[0/1]"
    '            WriteLong("WolfTeam.bin", csh.Text + WolfBalls, "0") 'Wolf Balls Off
    '            Exit Sub
    '        End If

    '        If Label62.ForeColor = Color.DeepSkyBlue Then
    '            Label63.ForeColor = Color.Red
    '            Label63.Text = "[0/1]"
    '            Matar1Hit.Enabled = False
    '            WriteLong("WolfTeam.bin", obj.Text + MatarHit, "2251820149") 'Matar de 1 Hit Off
    '            Exit Sub
    '        End If

    '        If Label35.ForeColor = Color.DeepSkyBlue Then
    '            Label36.ForeColor = Color.Red
    '            Label36.Text = "[0/1]"
    '            'Link Off
    '            Exit Sub
    '        End If
    '    End If
    'End Sub

    Private Sub INSERT_Tick(sender As Object, e As EventArgs) Handles INSERT.Tick
        If GetAsyncKeyState(Keys.Insert) = -32767 Then
            If Label1.Visible = False Then
                Label1.Visible = True
                Me.Show()
                Exit Sub
            End If
            If Label1.Visible = True Then
                Label1.Visible = False
                Me.Hide()
                Exit Sub
            End If
        End If
        If GetAsyncKeyState(Keys.Delete) = -32767 Then
            Form1.Close()
            Form3.Close()
            Me.Close()
            Application.Exit()
            Exit Sub
        End If
    End Sub

    Private Sub D3D_Effect_Tick(sender As Object, e As EventArgs) Handles D3D_Effect.Tick
        Try
            Interaction.AppActivate("Wolfteam.bin")
            Me.TopMost = True
        Catch
            Me.TopMost = True
        End Try
        System.Windows.Forms.Cursor.Hide()
    End Sub

    Private Sub Form4_Paint(sender As Object, e As PaintEventArgs) Handles MyBase.Paint
        e.Graphics.DrawRectangle(New Pen(Brushes.White, 0.1), New Rectangle(0, 0, Me.Width - 1, Me.Height - 1))
    End Sub

    Private Sub Siempre_HS_Tick(sender As Object, e As EventArgs) Handles Siempre_HS.Tick
        If GetAsyncKeyState(Keys.E) = -32767 Then
            Dim p As Process = Process.GetProcessesByName("Wolfteam.bin")(0)
            For Each moz As System.Diagnostics.ProcessModule In p.Modules
                If moz.FileName.IndexOf("obj") <> -1 Then
                    obj.Text = moz.BaseAddress.ToString
                End If
            Next
            WriteLong("Wolfteam.bin", obj.Text + SiempreHS, "1566441904") 'always Hs on
        Else
            If GetAsyncKeyState(Keys.F) = -32767 Then
                Dim p As Process = Process.GetProcessesByName("Wolfteam.bin")(0)
                For Each moz As System.Diagnostics.ProcessModule In p.Modules
                    If moz.FileName.IndexOf("obj") <> -1 Then
                        obj.Text = moz.BaseAddress.ToString
                    End If
                Next
                WriteLong("Wolfteam.bin", obj.Text + SiempreHS, "1566490674") 'always Hs off
                Exit Sub
            End If
        End If
    End Sub

    Private Sub Regresar_Base_Tick(sender As Object, e As EventArgs) Handles Regresar_Base.Tick
        If GetAsyncKeyState(Keys.T) = -32767 Then
            WriteLong("WolfTeam.bin", csh.Text + RegresBase, "2") 'Regresar Base [Q]
        End If
    End Sub

    Private Sub cross_Tick(sender As Object, e As EventArgs) Handles cross.Tick
        WriteLong("wolfteam.bin", csh.Text + CrossHair, "666666666") 'CrossHair On
    End Sub

    Private Sub Inmor_Tick(sender As Object, e As EventArgs) Handles Inmor.Tick
        If GetAsyncKeyState(Keys.O) = -32767 Then
            Dim p As Process = Process.GetProcessesByName("Wolfteam.bin")(0)
            For Each moz As System.Diagnostics.ProcessModule In p.Modules
                If moz.FileName.IndexOf("obj") <> -1 Then
                    obj.Text = moz.BaseAddress.ToString
                End If
            Next
            WriteLong("Wolfteam.bin", obj.Text + Inmortalidad, "3641198040") 'Inmortalidad On
        End If
    End Sub

    Private Sub Team_Kill_Tick(sender As Object, e As EventArgs) Handles Team_Kill.Tick
        If GetAsyncKeyState(Keys.K) = -32767 Then
            Dim p As Process = Process.GetProcessesByName("Wolfteam.bin")(0)
            For Each moz As System.Diagnostics.ProcessModule In p.Modules
                If moz.FileName.IndexOf("obj") <> -1 Then
                    obj.Text = moz.BaseAddress.ToString
                End If
            Next
            WriteLong("WolfTeam.bin", obj.Text + TeamKill, "418117253") 'TeamKill On
        End If
    End Sub

    Private Sub WolfGL_Tick(sender As Object, e As EventArgs) Handles WolfGL.Tick
        If GetAsyncKeyState(Keys.H) = -32767 Then
            Dim p As Process = Process.GetProcessesByName("Wolfteam.bin")(0)
            For Each moz As System.Diagnostics.ProcessModule In p.Modules
                If moz.FileName.IndexOf("obj") <> -1 Then
                    obj.Text = moz.BaseAddress.ToString
                End If
            Next
            WriteLong("WolfTeam.bin", obj.Text + WolfDashGL, "378215541") 'Wolf Dash Giro On
        End If
    End Sub

    Private Sub Frezzer_All_Tick(sender As Object, e As EventArgs) Handles Frezzer_All.Tick
        If GetAsyncKeyState(Keys.P) = -32767 Then
            Dim p As Process = Process.GetProcessesByName("Wolfteam.bin")(0)
            For Each moz As System.Diagnostics.ProcessModule In p.Modules
                If moz.FileName.IndexOf("obj") <> -1 Then
                    obj.Text = moz.BaseAddress.ToString
                End If
            Next
            WriteLong("WolfTeam.bin", obj.Text + FreezePlayers, "1574503796") 'Frezzer All On
        End If
    End Sub

    Private Sub Matar1Hit_Tick(sender As Object, e As EventArgs) Handles Matar1Hit.Tick
        If GetAsyncKeyState(Keys.L) = -32767 Then
            Dim p As Process = Process.GetProcessesByName("Wolfteam.bin")(0)
            For Each moz As System.Diagnostics.ProcessModule In p.Modules
                If moz.FileName.IndexOf("obj") <> -1 Then
                    obj.Text = moz.BaseAddress.ToString
                End If
            Next
            WriteLong("WolfTeam.bin", obj.Text + MatarHit, "2251820148") 'Matar de 1 Hit On
        End If
    End Sub

    Private Sub Form4_FormClosing(sender As Object, e As FormClosingEventArgs) Handles MyBase.FormClosing
        Try
            ' client.DownloadString("http://peliculascorp.tk/count.php?action=take")
        Catch ex As Exception
        End Try
    End Sub

    Private Sub FlyHack_Tick(sender As Object, e As EventArgs) Handles FlyHack.Tick
        If GetAsyncKeyState(Keys.V) = -32767 Then
            WritePointerInteger("Wolfteam.bin", csh.Text + FlyHack3, "1", &H358) 'Fly Hack On
        End If
    End Sub

    Private Sub Label7_Click(sender As Object, e As EventArgs) Handles Label7.Click

    End Sub
End Class

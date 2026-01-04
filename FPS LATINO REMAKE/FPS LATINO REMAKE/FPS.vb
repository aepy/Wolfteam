Public Class FPS
    'Private Declare Function GetAsyncKeyState Lib "user32" (ByVal vKey As Long) As Integer
    'Private Sub FPS_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
    '    Dim p As Process = Process.GetProcessesByName("WolfTeam.bin")(0)
    '    For Each moz As System.Diagnostics.ProcessModule In p.Modules
    '        If moz.FileName.IndexOf("csh") <> -1 Then
    '            csh.Text = moz.BaseAddress.ToString
    '        End If
    '    Next
    '    For Each moz1 As System.Diagnostics.ProcessModule In p.Modules
    '        If moz1.FileName.IndexOf("WolfTeam.bin") <> -1 Then
    '            bin.Text = moz1.BaseAddress.ToString
    '        End If
    '    Next
    'End Sub

    'Private Sub Esconde_Menu_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Esconde_Menu.Tick
    '    If GetAsyncKeyState(Keys.Insert) = -32767 Then
    '        If Label1.Visible = False Then
    '            Label1.Visible = True
    '            Me.Show()
    '            Exit Sub
    '        End If
    '        If Label1.Visible = True Then
    '            Label1.Visible = False
    '            Me.Hide()
    '            Exit Sub
    '        End If
    '    End If
    '    If GetAsyncKeyState(Keys.Delete) = -32767 Then
    '        Application.Exit()
    '        Exit Sub
    '    End If
    'End Sub

    'Private Sub Navegacion_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Navegacion.Tick
    '    If GetAsyncKeyState(Keys.Down) = -32767 Then
    '        If Label3.ForeColor = Color.DeepSkyBlue Then
    '            Label3.ForeColor = Color.White
    '            Label6.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label6.ForeColor = Color.DeepSkyBlue Then
    '            Label6.ForeColor = Color.White
    '            Label8.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label8.ForeColor = Color.DeepSkyBlue Then
    '            Label8.ForeColor = Color.White
    '            Label10.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label10.ForeColor = Color.DeepSkyBlue Then
    '            Label10.ForeColor = Color.White
    '            Label12.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label12.ForeColor = Color.DeepSkyBlue Then
    '            Label12.ForeColor = Color.White
    '            Label14.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label14.ForeColor = Color.DeepSkyBlue Then
    '            Label14.ForeColor = Color.White
    '            Label16.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label16.ForeColor = Color.DeepSkyBlue Then
    '            Label16.ForeColor = Color.White
    '            Label17.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label17.ForeColor = Color.DeepSkyBlue Then
    '            Label17.ForeColor = Color.White
    '            Label19.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label19.ForeColor = Color.DeepSkyBlue Then
    '            Label19.ForeColor = Color.White
    '            Label21.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label21.ForeColor = Color.DeepSkyBlue Then
    '            Label21.ForeColor = Color.White
    '            Label23.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label23.ForeColor = Color.DeepSkyBlue Then
    '            Label23.ForeColor = Color.White
    '            Label25.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label25.ForeColor = Color.DeepSkyBlue Then
    '            Label25.ForeColor = Color.White
    '            Label27.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label27.ForeColor = Color.DeepSkyBlue Then
    '            Label27.ForeColor = Color.White
    '            Label29.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label29.ForeColor = Color.DeepSkyBlue Then
    '            Label29.ForeColor = Color.White
    '            Label31.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label31.ForeColor = Color.DeepSkyBlue Then
    '            Label31.ForeColor = Color.White
    '            Label33.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label33.ForeColor = Color.DeepSkyBlue Then
    '            Label33.ForeColor = Color.White
    '            Label35.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label35.ForeColor = Color.DeepSkyBlue Then
    '            Label35.ForeColor = Color.White
    '            Label37.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label37.ForeColor = Color.DeepSkyBlue Then
    '            Label37.ForeColor = Color.White
    '            Label38.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label38.ForeColor = Color.DeepSkyBlue Then
    '            Label38.ForeColor = Color.White
    '            Label40.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label40.ForeColor = Color.DeepSkyBlue Then
    '            Label40.ForeColor = Color.White
    '            Label42.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label42.ForeColor = Color.DeepSkyBlue Then
    '            Label42.ForeColor = Color.White
    '            Label44.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label44.ForeColor = Color.DeepSkyBlue Then
    '            Label44.ForeColor = Color.White
    '            Label46.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label46.ForeColor = Color.DeepSkyBlue Then
    '            Label46.ForeColor = Color.White
    '            Label3.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '    End If
    '    '----------------------Dowm-------------------
    '    ' UP Code
    '    '-------------------UP-------------------
    '    If GetAsyncKeyState(Keys.Up) = -32767 Then
    '        If Label3.ForeColor = Color.DeepSkyBlue Then
    '            Label3.ForeColor = Color.White
    '            Label46.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label6.ForeColor = Color.DeepSkyBlue Then
    '            Label6.ForeColor = Color.White
    '            Label3.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label8.ForeColor = Color.DeepSkyBlue Then
    '            Label8.ForeColor = Color.White
    '            Label6.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label10.ForeColor = Color.DeepSkyBlue Then
    '            Label10.ForeColor = Color.White
    '            Label8.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label12.ForeColor = Color.DeepSkyBlue Then
    '            Label12.ForeColor = Color.White
    '            Label10.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label14.ForeColor = Color.DeepSkyBlue Then
    '            Label14.ForeColor = Color.White
    '            Label12.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label16.ForeColor = Color.DeepSkyBlue Then
    '            Label16.ForeColor = Color.White
    '            Label14.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label17.ForeColor = Color.DeepSkyBlue Then
    '            Label17.ForeColor = Color.White
    '            Label16.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label19.ForeColor = Color.DeepSkyBlue Then
    '            Label19.ForeColor = Color.White
    '            Label17.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label21.ForeColor = Color.DeepSkyBlue Then
    '            Label21.ForeColor = Color.White
    '            Label19.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label23.ForeColor = Color.DeepSkyBlue Then
    '            Label23.ForeColor = Color.White
    '            Label21.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label25.ForeColor = Color.DeepSkyBlue Then
    '            Label25.ForeColor = Color.White
    '            Label23.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label27.ForeColor = Color.DeepSkyBlue Then
    '            Label27.ForeColor = Color.White
    '            Label25.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label29.ForeColor = Color.DeepSkyBlue Then
    '            Label29.ForeColor = Color.White
    '            Label27.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label31.ForeColor = Color.DeepSkyBlue Then
    '            Label31.ForeColor = Color.White
    '            Label29.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label33.ForeColor = Color.DeepSkyBlue Then
    '            Label33.ForeColor = Color.White
    '            Label31.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label35.ForeColor = Color.DeepSkyBlue Then
    '            Label35.ForeColor = Color.White
    '            Label33.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label37.ForeColor = Color.DeepSkyBlue Then
    '            Label37.ForeColor = Color.White
    '            Label35.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label38.ForeColor = Color.DeepSkyBlue Then
    '            Label38.ForeColor = Color.White
    '            Label37.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label40.ForeColor = Color.DeepSkyBlue Then
    '            Label40.ForeColor = Color.White
    '            Label38.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label42.ForeColor = Color.DeepSkyBlue Then
    '            Label42.ForeColor = Color.White
    '            Label40.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label44.ForeColor = Color.DeepSkyBlue Then
    '            Label44.ForeColor = Color.White
    '            Label42.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '        If Label46.ForeColor = Color.DeepSkyBlue Then
    '            Label46.ForeColor = Color.White
    '            Label44.ForeColor = Color.DeepSkyBlue
    '            Exit Sub
    '        End If
    '    End If
    'End Sub



    'Dim WolfDash As Integer = &H566AD
    'Dim Respawn0 As Integer = &H79440
    'Dim Recoil As Integer = &H82DC3
    'Dim Aimbot As Integer = &HB6801
    'Dim Wallshot As Integer = &H4F970 'F6 C4 41 75 15 ?? ?? ?? ?? F6 C4 41 75 0C
    'Dim NameEsp As Integer = &H36E716
    'Dim CrossHair As Integer = &H6C32E8
    'Dim RespWhereDie As Integer = &H101455
    'Dim Gravity As Integer = &H1036CD
    'Dim NoFall As Integer = &H105163
    'Dim RapidFire As Integer = &H12C5CB
    'Dim Reload1 As Integer = &H125D33
    'Dim AutoFire As Integer = &H126435
    'Dim Reload2 As Integer = &H12A51E
    'Dim InfAmmo1 As Integer = &H1302D5
    'Dim InfAmmo2 As Integer = &H13031C
    'Dim Spread As Integer = &H1428C3
    'Dim WeaponSP As Integer = &H171F03
    'Dim WolfView As Integer = &H178E8B
    'Dim Jump As Integer = &H415B54

    'Dim GodMode1 As Integer = &H21554       'obj
    'Dim GodMode2 As Integer = &H2DD64       'obj
    'Dim FreezePlayers As Integer = &HE647   'obj
    'Dim DashGiro As Integer = &H1DDB5       'obj
    'Dim DashSpeed As Integer = &H642E04

    'Dim SiempreHS As Integer = &HE647       'obj
    'Dim SuperAimbot As Integer = &H2146D    'obj  
    'Dim WolfBalls As Integer = &H6C396C
    'Dim TeamKill As Integer = &H5A14E 'obj


    'Private Sub Activacion_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Activacion.Tick

    '    If GetAsyncKeyState(Keys.Right) = -32767 Then
    '        If Label3.ForeColor = Color.DeepSkyBlue Then
    '            Label4.ForeColor = Color.Green
    '            Label4.Text = "[ON]"
    '            WriteLong("WolfTeam.bin", csh.Text + NameEsp, "2268606836") 'name esp
    '            Exit Sub
    '        End If
    '        If Label6.ForeColor = Color.DeepSkyBlue Then
    '            Label5.ForeColor = Color.Green
    '            Label5.Text = "[ON]"
    '            WriteLong("WolfTeam.bin", csh.Text + CrossHair, "999999999") 'crosshair
    '            Exit Sub
    '        End If
    '        If Label8.ForeColor = Color.DeepSkyBlue Then
    '            Label7.ForeColor = Color.Green
    '            Label7.Text = "[ON]"
    '            WriteLong("WolfTeam.bin", csh.Text + InfAmmo1, "4252861286") ' inf ammo
    '            WriteLong("WolfTeam.bin", csh.Text + InfAmmo2, "4252861286") ' inf ammo2
    '            Exit Sub
    '        End If
    '        If Label10.ForeColor = Color.DeepSkyBlue Then
    '            Label9.ForeColor = Color.Green
    '            Label9.Text = "[ON]"
    '            WriteLong("WolfTeam.bin", csh.Text + Recoil, "2665025140") 'recoil
    '            Exit Sub
    '        End If
    '        If Label12.ForeColor = Color.DeepSkyBlue Then
    '            Label11.ForeColor = Color.Green
    '            Label11.Text = "[ON]"
    '            WriteLong("WolfTeam.bin", csh.Text + Spread, "1301090420") 'spread
    '            Exit Sub
    '        End If
    '        If Label14.ForeColor = Color.DeepSkyBlue Then
    '            Label13.ForeColor = Color.Green
    '            Label13.Text = "[ON]"
    '            WriteLong("WolfTeam.bin", csh.Text + RapidFire, "1574503796") 'rapidfire
    '            Exit Sub
    '        End If
    '        If Label16.ForeColor = Color.DeepSkyBlue Then
    '            Label15.ForeColor = Color.Green
    '            Label15.Text = "[ON]"
    '            WriteLong("WolfTeam.bin", csh.Text + WeaponSP, "3071218292") 'weapon Sp
    '            Exit Sub
    '        End If
    '        If Label17.ForeColor = Color.DeepSkyBlue Then
    '            Label2.ForeColor = Color.Green
    '            Label2.Text = "[ON]"
    '            S_aimbot.Enabled = True
    '            Exit Sub
    '        End If
    '        If Label19.ForeColor = Color.DeepSkyBlue Then
    '            Label18.ForeColor = Color.Green
    '            Label18.Text = "[ON]"
    '            WolfDash_t.Enabled = True
    '            'WriteLong("WolfTeam.bin", csh.Text + WolfDash, "28312949") 'Wolfdash
    '            Exit Sub
    '        End If
    '        If Label21.ForeColor = Color.DeepSkyBlue Then
    '            Label20.ForeColor = Color.Green
    '            Label20.Text = "[ON]"
    '            WriteLong("WolfTeam.bin", csh.Text + Respawn0, "1574503796") 'respaw Zero
    '            Exit Sub
    '        End If
    '        If Label23.ForeColor = Color.DeepSkyBlue Then
    '            Label22.ForeColor = Color.Green
    '            Label22.Text = "[ON]"
    '            WriteLong("WolfTeam.bin", csh.Text + NoFall, "2654543220") 'nofall Damage
    '            Exit Sub
    '        End If
    '        If Label25.ForeColor = Color.DeepSkyBlue Then
    '            Label24.ForeColor = Color.Green
    '            Label24.Text = "[ON]"
    '            WriteLong("WolfTeam.bin", csh.Text + Reload1, "2257258100") 'Reload
    '            WriteLong("WolfTeam.bin", csh.Text + Reload2, "2257258100") 'Reload
    '            Exit Sub
    '        End If
    '        If Label27.ForeColor = Color.DeepSkyBlue Then
    '            Label26.ForeColor = Color.Green
    '            Label26.Text = "[ON]"
    '            WriteLong("WolfTeam.bin", csh.Text + RespWhereDie, "3897951979") 'respaw where die
    '            Exit Sub
    '        End If
    '        If Label29.ForeColor = Color.DeepSkyBlue Then
    '            Label28.ForeColor = Color.Green
    '            Label28.Text = "[ON]"
    '            WriteLong("WolfTeam.bin", csh.Text + WolfView, "2341280884") 'Wolfview
    '            Exit Sub
    '        End If
    '        If Label31.ForeColor = Color.DeepSkyBlue Then
    '            Label30.ForeColor = Color.Green
    '            Label30.Text = "[ON]"
    '            WriteLong("WolfTeam.bin", csh.Text + AutoFire, "6951147") 'Autofire
    '            Exit Sub
    '        End If
    '        If Label33.ForeColor = Color.DeepSkyBlue Then
    '            Label32.ForeColor = Color.Green
    '            Label32.Text = "[ON]"
    '            WriteLong("WolfTeam.bin", bin.Text + Wallshot, "5") 'Wallshot
    '            Exit Sub
    '        End If
    '        If Label35.ForeColor = Color.DeepSkyBlue Then
    '            Label34.ForeColor = Color.Green
    '            Label34.Text = "[ON]"
    '            WriteLong("WolfTeam.bin", csh.Text + Gravity, "5") 'No gravity
    '            Exit Sub
    '        End If
    '        If Label37.ForeColor = Color.DeepSkyBlue Then
    '            Label36.ForeColor = Color.Green
    '            Label36.Text = "[ON]"
    '            WriteLong("WolfTeam.bin", csh.Text + Jump, "1065353216") 'Jumphack
    '            Exit Sub
    '        End If
    '        If Label38.ForeColor = Color.DeepSkyBlue Then
    '            Label39.ForeColor = Color.Green
    '            Label39.Text = "[ON]"
    '            GodMode_t.Enabled = True
    '            Exit Sub
    '        End If
    '        If Label40.ForeColor = Color.DeepSkyBlue Then
    '            Label41.ForeColor = Color.Green
    '            Label41.Text = "[ON]"
    '            Congelar_pj.Enabled = True
    '            Exit Sub
    '        End If
    '        If Label42.ForeColor = Color.DeepSkyBlue Then
    '            Label43.ForeColor = Color.Green
    '            Label43.Text = "[ON]"
    '            Siempre_HS.Enabled = True
    '            Exit Sub
    '        End If
    '        If Label44.ForeColor = Color.DeepSkyBlue Then
    '            Label45.ForeColor = Color.Green
    '            Label45.Text = "[ON]"
    '            WriteLong("Wolfteam.bin", csh.Text + WolfBalls, "999999999") 'WolfBalls ON
    '            Exit Sub
    '        End If
    '        If Label46.ForeColor = Color.DeepSkyBlue Then
    '            Label47.ForeColor = Color.Green
    '            Label47.Text = "[ON]"
    '            Matar_equipo.Enabled = True
    '            Exit Sub
    '        End If
    '    End If
    '    '----------------------encendido arriba-------------------
    '    ' Aqui cambian las opciones
    '    '-------------------apagado abajo-------------------
    '    If GetAsyncKeyState(Keys.Left) = -32767 Then
    '        If Label3.ForeColor = Color.DeepSkyBlue Then
    '            Label4.ForeColor = Color.Red
    '            Label4.Text = "[OFF]"
    '            WriteLong("WolfTeam.bin", csh.Text + NameEsp, "2268606837") 'name esp
    '            Exit Sub
    '        End If
    '        If Label6.ForeColor = Color.DeepSkyBlue Then
    '            Label5.ForeColor = Color.Red
    '            Label5.Text = "[OFF]"
    '            WriteLong("WolfTeam.bin", csh.Text + CrossHair, "1") 'crosshair
    '            Exit Sub
    '        End If
    '        If Label8.ForeColor = Color.DeepSkyBlue Then
    '            Label7.ForeColor = Color.Red
    '            Label7.Text = "[OFF]"
    '            WriteLong("WolfTeam.bin", csh.Text + InfAmmo1, "4236084070") ' inf ammo
    '            WriteLong("WolfTeam.bin", csh.Text + InfAmmo2, "4236084070") ' inf ammo2
    '            Exit Sub
    '        End If
    '        If Label10.ForeColor = Color.DeepSkyBlue Then
    '            Label9.ForeColor = Color.Red
    '            Label9.Text = "[OFF]"
    '            WriteLong("WolfTeam.bin", csh.Text + Recoil, "2665025141") 'recoil
    '            Exit Sub
    '        End If
    '        If Label12.ForeColor = Color.DeepSkyBlue Then
    '            Label11.ForeColor = Color.Red
    '            Label11.Text = "[OFF]"
    '            WriteLong("WolfTeam.bin", csh.Text + Spread, "1301090421") 'spread
    '            Exit Sub
    '        End If
    '        If Label14.ForeColor = Color.DeepSkyBlue Then
    '            Label13.ForeColor = Color.Red
    '            Label13.Text = "[OFF]"
    '            WriteLong("WolfTeam.bin", csh.Text + RapidFire, "1574503797") 'rapidfire
    '            Exit Sub
    '        End If
    '        If Label16.ForeColor = Color.DeepSkyBlue Then
    '            Label15.ForeColor = Color.Red
    '            Label15.Text = "[OFF]"
    '            WriteLong("WolfTeam.bin", csh.Text + WeaponSP, "3071218293") 'weapon Sp
    '            Exit Sub
    '        End If
    '        If Label17.ForeColor = Color.DeepSkyBlue Then
    '            Label2.ForeColor = Color.Red
    '            Label2.Text = "[OFF]"
    '            S_aimbot.Enabled = False
    '            'WriteLong("WolfTeam.bin", obj.Text + Aimbot, "2251820149") 'Aimbot
    '            Exit Sub
    '        End If
    '        If Label19.ForeColor = Color.DeepSkyBlue Then
    '            Label18.ForeColor = Color.Red
    '            Label18.Text = "[OFF]"
    '            WolfDash_t.Enabled = False
    '            'WriteLong("WolfTeam.bin", csh.Text + WolfDash, "28312948") 'Wolfdash
    '            Exit Sub
    '        End If
    '        If Label21.ForeColor = Color.DeepSkyBlue Then
    '            Label20.ForeColor = Color.Red
    '            Label20.Text = "[OFF]"
    '            WriteLong("WolfTeam.bin", csh.Text + Respawn0, "1574503797") 'respaw Zero
    '            Exit Sub
    '        End If
    '        If Label23.ForeColor = Color.DeepSkyBlue Then
    '            Label22.ForeColor = Color.Red
    '            Label22.Text = "[OFF]"
    '            WriteLong("WolfTeam.bin", csh.Text + NoFall, "2654543221") 'nofall Damage
    '            Exit Sub
    '        End If
    '        If Label25.ForeColor = Color.DeepSkyBlue Then
    '            Label24.ForeColor = Color.Red
    '            Label24.Text = "[OFF]"
    '            WriteLong("WolfTeam.bin", csh.Text + Reload1, "2257258101") 'Reload
    '            WriteLong("WolfTeam.bin", csh.Text + Reload2, "2257258101") 'Reload
    '            Exit Sub
    '        End If
    '        If Label27.ForeColor = Color.DeepSkyBlue Then
    '            Label26.ForeColor = Color.Red
    '            Label26.Text = "[OFF]"
    '            WriteLong("WolfTeam.bin", csh.Text + RespWhereDie, "3897951860") 'respaw where die
    '            Exit Sub
    '        End If
    '        If Label29.ForeColor = Color.DeepSkyBlue Then
    '            Label28.ForeColor = Color.Red
    '            Label28.Text = "[OFF]"
    '            WriteLong("WolfTeam.bin", csh.Text + WolfView, "2341280885") 'Wolfview
    '            Exit Sub
    '        End If
    '        If Label31.ForeColor = Color.DeepSkyBlue Then
    '            Label30.ForeColor = Color.Red
    '            Label30.Text = "[OFF]"
    '            WriteLong("WolfTeam.bin", csh.Text + AutoFire, "6951029") 'Autofire
    '            Exit Sub
    '        End If
    '        If Label33.ForeColor = Color.DeepSkyBlue Then
    '            Label32.ForeColor = Color.Red
    '            Label32.Text = "[OFF]"
    '            WriteLong("WolfTeam.bin", bin.Text + Wallshot, "1967244534") 'Wallshot
    '            Exit Sub
    '        End If
    '        If Label35.ForeColor = Color.DeepSkyBlue Then
    '            Label34.ForeColor = Color.Red
    '            Label34.Text = "[OFF]"
    '            WriteLong("WolfTeam.bin", csh.Text + Gravity, "1967244534") 'gravity
    '            Exit Sub
    '        End If
    '        If Label37.ForeColor = Color.DeepSkyBlue Then
    '            Label36.ForeColor = Color.Red
    '            Label36.Text = "[OFF]"
    '            WriteLong("WolfTeam.bin", csh.Text + Jump, "1062165545") 'Jump
    '            Exit Sub
    '        End If
    '        If Label38.ForeColor = Color.DeepSkyBlue Then
    '            Label39.ForeColor = Color.Red
    '            Label39.Text = "[OFF]"
    '            GodMode_t.Enabled = False
    '            Exit Sub
    '        End If
    '        If Label40.ForeColor = Color.DeepSkyBlue Then
    '            Label41.ForeColor = Color.Red
    '            Label41.Text = "[OFF]"
    '            Congelar_pj.Enabled = False
    '            Exit Sub
    '        End If
    '        If Label42.ForeColor = Color.DeepSkyBlue Then
    '            Label43.ForeColor = Color.Red
    '            Label43.Text = "[OFF]"
    '            Siempre_HS.Enabled = False
    '            Exit Sub
    '        End If
    '        If Label44.ForeColor = Color.DeepSkyBlue Then
    '            Label45.ForeColor = Color.Red
    '            Label45.Text = "[OFF]"
    '            WriteLong("Wolfteam.bin", csh.Text + &H6C396C, "0") 'WolfBalls OFF
    '            Exit Sub
    '        End If
    '        If Label46.ForeColor = Color.DeepSkyBlue Then
    '            Label47.ForeColor = Color.Red
    '            Label47.Text = "[OFF]"
    '            Matar_equipo.Enabled = False
    '            Exit Sub
    '        End If
    '    End If
    'End Sub


    'Private Sub D3D_Effect_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles D3D_Effect.Tick
    '    Try
    '        Interaction.AppActivate("Wolfteam.bin")
    '        Me.TopMost = True
    '    Catch
    '        Me.TopMost = True
    '    End Try
    '    System.Windows.Forms.Cursor.Hide()
    'End Sub

    'Private Sub S_aimbot_Tick(sender As Object, e As EventArgs) Handles S_aimbot.Tick
    '    If GetAsyncKeyState(Keys.F1) = -32767 Then
    '        Dim p As Process = Process.GetProcessesByName("WolfTeam.bin")(0)
    '        For Each moz As System.Diagnostics.ProcessModule In p.Modules
    '            If moz.FileName.IndexOf("obj") <> -1 Then
    '                obj.Text = moz.BaseAddress.ToString
    '            End If
    '        Next
    '        WriteLong("Wolfteam.bin", obj.Text + SuperAimbot, "2251820148") 'super aimbot
    '        Exit Sub
    '    End If
    'End Sub

    'Private Sub WolfDash_t_Tick(sender As Object, e As EventArgs) Handles WolfDash_t.Tick
    '    If GetAsyncKeyState(Keys.F2) = -32767 Then
    '        Dim p As Process = Process.GetProcessesByName("Wolfteam.bin")(0)
    '        For Each moz As System.Diagnostics.ProcessModule In p.Modules
    '            If moz.FileName.IndexOf("obj") <> -1 Then
    '                obj.Text = moz.BaseAddress.ToString
    '            End If
    '        Next
    '        WritePointerInteger("Wolfteam.bin", csh.Text + DashSpeed, "19610", &H18) 'dash pointer
    '        WriteLong("Wolfteam.bin", csh.Text + WolfDash, "28312949") 'dash
    '        WriteLong("Wolfteam.bin", csh.Text + WolfView, "2341280884") 'wolfview
    '        WriteLong("Wolfteam.bin", obj.Text + DashGiro, "378215541") 'giro del dash
    '        Exit Sub
    '    End If
    'End Sub

    'Private Sub GodMode_t_Tick(sender As Object, e As EventArgs) Handles GodMode_t.Tick
    '    If GetAsyncKeyState(Keys.F3) = -32767 Then
    '        Dim p As Process = Process.GetProcessesByName("Wolfteam.bin")(0)
    '        For Each moz As System.Diagnostics.ProcessModule In p.Modules
    '            If moz.FileName.IndexOf("obj") <> -1 Then
    '                obj.Text = moz.BaseAddress.ToString
    '            End If
    '        Next
    '        WriteLong("Wolfteam.bin", obj.Text + GodMode1, "3641198040") 'godmode
    '        WriteLong("Wolfteam.bin", obj.Text + GodMode2, "3641198040") 'godmode
    '        Exit Sub
    '    End If
    'End Sub

    'Private Sub Congelar_pj_Tick(sender As Object, e As EventArgs) Handles Congelar_pj.Tick
    '    If GetAsyncKeyState(Keys.F4) = -32767 Then
    '        Dim p As Process = Process.GetProcessesByName("Wolfteam.bin")(0)
    '        For Each moz As System.Diagnostics.ProcessModule In p.Modules
    '            If moz.FileName.IndexOf("obj") <> -1 Then
    '                obj.Text = moz.BaseAddress.ToString
    '            End If
    '        Next
    '        WriteLong("Wolfteam.bin", obj.Text + FreezePlayers, "1574503796") 'freeze all player
    '        Exit Sub
    '    End If
    'End Sub

    'Private Sub Siempre_HS_Tick(sender As Object, e As EventArgs) Handles Siempre_HS.Tick
    '    If GetAsyncKeyState(Keys.F5) = -32767 Then
    '        Dim p As Process = Process.GetProcessesByName("Wolfteam.bin")(0)
    '        For Each moz As System.Diagnostics.ProcessModule In p.Modules
    '            If moz.FileName.IndexOf("obj") <> -1 Then
    '                obj.Text = moz.BaseAddress.ToString
    '            End If
    '        Next
    '        WriteLong("Wolfteam.bin", obj.Text + SiempreHS, "1574503796") 'always Hs
    '        Exit Sub
    '    End If
    'End Sub

    'Private Sub NyX_Theme1_Click(sender As Object, e As EventArgs) Handles NyX_Theme1.Click

    'End Sub

    'Private Sub Matar_equipo_Tick(sender As Object, e As EventArgs) Handles Matar_equipo.Tick
    '    If GetAsyncKeyState(Keys.F6) = -32767 Then
    '        Dim p As Process = Process.GetProcessesByName("Wolfteam.bin")(0)
    '        For Each moz As System.Diagnostics.ProcessModule In p.Modules
    '            If moz.FileName.IndexOf("obj") <> -1 Then
    '                obj.Text = moz.BaseAddress.ToString
    '            End If
    '        Next
    '        WriteLong("Wolfteam.bin", obj.Text + TeamKill, "418117253") 'teamkill
    '        Exit Sub
    '    End If
    'End Sub

    'Private Sub Label34_Click(sender As Object, e As EventArgs) Handles Label34.Click

    'End Sub

    'Private Sub Label51_Click(sender As Object, e As EventArgs) Handles Label51.Click

    'End Sub
End Class

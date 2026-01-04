Public Class Loader

    ' Private Sub NyX_Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles NyX_Button1.Click
    'System.Diagnostics.Process.Start("C:\Game\SoftnyxGame\WolfTeamLS\NyxLauncher.exe")
    ' NyX_Button1.Text = "Esperando por WolfTeam"
    'Timer1.Start()
    ' End Sub


    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick
        Dim p As Process()
        p = Process.GetProcessesByName("xxd-0.xem") '("Wolfteam.bin")
        If p.Count = 1 Then
            Timer1.Stop()
            Me.Finalize()
            Nosand.Show()
            Nosand2.Show()
        End If
    End Sub

    Private Sub NyX_Theme1_Click(sender As Object, e As EventArgs) Handles NyX_Theme1.Click

    End Sub
End Class
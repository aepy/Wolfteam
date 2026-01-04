Public Class Form2

    Public CONTADOR As Integer
    Private Sub FlatProgressBar1_Click(sender As Object, e As EventArgs) Handles FlatProgressBar1.Click
        FlatProgressBar1.Value = 0.0
        FlatProgressBar1.Maximum = 100
        Timer1.Interval = 200
        Timer1.Enabled = True
    End Sub

    Private Sub Timer1_Tick(sender As Object, e As EventArgs) Handles Timer1.Tick
        If CONTADOR < 100 Then
            FlatProgressBar1.Value = CONTADOR
            CONTADOR = CONTADOR + 1
        Else
            Timer1.Enabled = False
            Me.Finalize()
            Form3.Close()
            Form4.Show()
        End If
    End Sub
End Class
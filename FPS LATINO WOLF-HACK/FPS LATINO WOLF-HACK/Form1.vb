Imports System.Net
Imports System.IO
Imports System.Text
Imports System.Security.Cryptography
Public Class Form1
    Dim client As New WebClient

    Public CONTADOR As Integer

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        ' users.Text = client.DownloadString("http://peliculascorp.tk/users.txt")
    End Sub

    Private Sub ProgressBar1_Click(sender As Object, e As EventArgs)
        ProgressBar1.Value = 0.0
        ProgressBar1.Maximum = 100
        Timer1.Interval = 200
    End Sub

    Private Sub Timer1_Tick(sender As Object, e As EventArgs) Handles Timer1.Tick
        'Dim Request As HttpWebRequest = WebRequest.Create("https://pastebin.com/raw/LEqAC5d7")
        'Dim response As HttpWebResponse = Request.GetResponse
        'Dim resReader As New StreamReader(response.GetResponseStream)
        'Dim str As String = resReader.ReadToEnd
        'Dim Codigo As String = "16ACTIVO"
        'If str.Contains(Codigo.Trim) Then
        Timer1.Enabled = False
        Timer2.Enabled = True
        Button1.Visible = False
        'Else
        '    Timer1.Stop()
        '    FlatAlertBox2.Visible = True
        '    Button2.Visible = False
        '    Button3.Visible = False
        '    ProgressBar1.Visible = False
        '    Button1.Text = "Click Para Actualizar"
        'End If
    End Sub

    Private Sub Timer2_Tick(sender As Object, e As EventArgs) Handles Timer2.Tick
        If CONTADOR < 100 Then
            ProgressBar1.Value = CONTADOR
            CONTADOR = CONTADOR + 1
        Else
            Timer1.Enabled = False
            ProgressBar1.Visible = False
            FlatAlertBox1.Visible = True
            Button2.Visible = False
            Button3.Text = "Esperando por zula_BE"
            Timer3.Enabled = True
        End If
    End Sub

    Private Sub Timer3_Tick(sender As Object, e As EventArgs) Handles Timer3.Tick
        Dim p As Process()
        p = Process.GetProcessesByName("zula_BE")
        If p.Count = 1 Then
            Timer2.Enabled = False
            Me.Finalize()
            Form2.Show()
            Form3.Show()
        End If
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Process.Start("http://fpslatino.net/forum/main-forum/wolf-team/latino-softnyx")
    End Sub
End Class

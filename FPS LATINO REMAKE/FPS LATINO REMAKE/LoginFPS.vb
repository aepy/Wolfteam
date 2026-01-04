Imports System.Net
Imports System.IO
Imports System.Text
Imports System.Security.Cryptography
Public Class LoginFPS
    Dim data As String
    Public Function Login(ByVal Username As String, ByVal Password As String)
        data = "username=" & Username & "&password=&o=&do=login&vb_login_md5password=" & Password & "&vb_login_md5password_utf=" & MD5(Password)
        Try
            Dim request As HttpWebRequest = WebRequest.Create("http://fpslatino.net/auth/login")
            request.Method = WebRequestMethods.Http.Post
            request.ContentType = "application/x-www-form-urlencoded"
            request.ContentLength = data.Length
            Dim rStream As New StreamWriter(request.GetRequestStream)
            rStream.Write(data)
            rStream.Flush()
            rStream.Close()
            Dim response As HttpWebResponse = request.GetResponse
            Dim resReader As New StreamReader(response.GetResponseStream)
            Dim str As String = resReader.ReadToEnd
            If str.Contains("Iniciando Sesión...") Then
                Return True
            Else
                Return False
            End If
            response.Close()
        Catch ex As Exception
            Return False
        End Try
    End Function
    Friend Function MD5(ByVal number As String) As String
        Dim ASCIIenc As New ASCIIEncoding
        Dim strReturn As String = String.Empty
        Dim ByteSourceText() As Byte = ASCIIenc.GetBytes(number)
        Dim Md5Hash As New MD5CryptoServiceProvider
        Dim ByteHash() As Byte = Md5Hash.ComputeHash(ByteSourceText)
        For Each b As Byte In ByteHash
            strReturn &= b.ToString("x2")
        Next
        Return strReturn
    End Function

    Private Sub LinkLabel2_LinkClicked(ByVal sender As System.Object, ByVal e As System.Windows.Forms.LinkLabelLinkClickedEventArgs) Handles LinkLabel2.LinkClicked
        System.Diagnostics.Process.Start("http://fpslatino.net/lostpw")
    End Sub
    Private Sub LinkLabel1_LinkClicked(ByVal sender As System.Object, ByVal e As System.Windows.Forms.LinkLabelLinkClickedEventArgs) Handles LinkLabel1.LinkClicked
        System.Diagnostics.Process.Start("http://fpslatino.net/register")
    End Sub
    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim Request As HttpWebRequest = WebRequest.Create("http://pastebin.com/raw/KBHncLLS")
        Dim response As HttpWebResponse = Request.GetResponse
        Dim resReader As New StreamReader(response.GetResponseStream)
        Dim str As String = resReader.ReadToEnd
        Dim Codigo As String = "2ACTIVO"
        If Login(TextBox1.Text, TextBox2.Text) = True Then
            If str.Contains(Codigo.Trim) Then
                Loader.Show()
                Me.Hide()
            Else
                MsgBox("Versión incompatible, descargue nueva versión!", 0, "Atención!")
                System.Diagnostics.Process.Start("http://fpslatino.net/")
            End If
        Else
            MsgBox("Usuario o Contraseña incorrecta! Si no tienes cuenta, dale en 'Crear nueva cuenta'", 0, "Error")
        End If
    End Sub

    Private Sub Button1_Click_1(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click

    End Sub

    Private Sub LoginFPS_Load(sender As Object, e As EventArgs) Handles MyBase.Load

    End Sub
End Class
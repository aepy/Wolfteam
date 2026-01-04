Imports Microsoft.VisualBasic
Imports Microsoft.VisualBasic.CompilerServices
Imports System
Imports System.Collections
Imports System.Collections.Generic
Imports System.ComponentModel
Imports System.Diagnostics
Imports System.Drawing
Imports System.IO
Imports System.Runtime.CompilerServices
Imports System.Windows.Forms
Imports System.Environment
Public Class Form3

    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick
        Try
            Dim folderPath As String = Environment.GetFolderPath(SpecialFolder.Windows)
            FileSystem.FileClose(New Integer() {1})
            FileSystem.FileClose(New Integer() {2})
            If My.Computer.FileSystem.FileExists((folderPath & "\BEDaisy.sys")) Then
                FileSystem.FileOpen(1, (folderPath & "\BEDaisy.sys"), OpenMode.Append, OpenAccess.ReadWrite, OpenShare.LockReadWrite, -1)

            Else
                File.WriteAllBytes((folderPath & "\BEDaisy.sys"), New Byte() {0})
                FileSystem.FileOpen(1, (folderPath & "\BEDaisy.sys"), OpenMode.Append, OpenAccess.ReadWrite, OpenShare.LockReadWrite, -1)
                ' Label1.Text = ("Erişim Engellendi ")
            End If
            If My.Computer.FileSystem.FileExists((folderPath & "\BEService.sys")) Then
                FileSystem.FileOpen(2, (folderPath & "\BEService.sys"), OpenMode.Append, OpenAccess.ReadWrite, OpenShare.LockReadWrite, -1)

            Else
                File.WriteAllBytes((folderPath & "\BEService.sys"), New Byte() {0})
                FileSystem.FileOpen(2, (folderPath & "\BEService.sys"), OpenMode.Append, OpenAccess.ReadWrite, OpenShare.LockReadWrite, -1)
                ' Label2.Text = ("Erişim Engellendi")
            End If
        Catch exception1 As Exception
            ProjectData.SetProjectError(exception1)
            Dim ex As Exception = exception1
            ProjectData.SetProjectError(ex)
            Dim exception As Exception = ex
            ProjectData.ClearProjectError()
            ProjectData.ClearProjectError()
        End Try
        ' Dim p As Process()
        ' p = Process.GetProcessesByName("zula_be.bin") 'set wolfteam process
        ' If p.Count = 1 Then ' if wolfteam process detected
        '  Label1.Text = ("XignCode Clear Bypass")
        '   Label2.Text = ("XignCode Clear Bypass")
        ' End If
    End Sub
End Class
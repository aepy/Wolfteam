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


Public Class Nosand
    Const PROCESS_ALL_ACCESS = &H1F0FF
    'Private Declare Function OpenProcess Lib "kernel32" (ByVal dwDesiredAccess As Integer, ByVal bInheritHandle As Integer, ByVal dwProcessId As Integer) As Integer
    'Private Declare Function FreeLibrary Lib "kernel32" (ByVal hLibModule As Long) As Long
    'Private Declare Function LoadLibrary Lib "kernel32" Alias "LoadLibraryA" (ByVal lpLibFileName As String) As Long
    'Private Declare Function GetProcAddress Lib "kernel32" (ByVal hModule As Long, ByVal lpProcName As String) As Long
    'Declare Function VirtualProtect Lib "kernel32" (ByVal lpAddress As IntPtr, ByVal dwSize As Integer, ByVal flNewProtect As Integer, ByRef lpflOldProtect As UInteger) As Boolean
    'Public Declare Function VirtualProtectEx Lib "kernel32" (ByVal hProcess As IntPtr, ByVal lpAddress As IntPtr, ByVal dwSize As Long, ByVal flNewProtect As Long, ByVal lpflOldProtect As Long) As Long
    ''  Private Declare Function CallWindowProc Lib "user32" Alias "CallWindowProcA" (ByVal lpPrevWndFunc As Long, ByVal hWnd As Long, ByVal Msg As Any, ByVal wParam As Any, ByVal lParam As Any) As Long

    'Private Function DriverBypass(ByVal pID As Integer) As Boolean

    'End Function
    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick
        Try
            Dim folderPath As String = Environment.GetFolderPath(SpecialFolder.Windows)
            FileSystem.FileClose(New Integer() {1})
            FileSystem.FileClose(New Integer() {2})
            If My.Computer.FileSystem.FileExists((folderPath & "\xspirit.sys")) Then
                FileSystem.FileOpen(1, (folderPath & "\xspirit.sys"), OpenMode.Append, OpenAccess.ReadWrite, OpenShare.LockReadWrite, -1)

            Else
                File.WriteAllBytes((folderPath & "\xspirit.sys"), New Byte() {0})
                FileSystem.FileOpen(1, (folderPath & "\xspirit.sys"), OpenMode.Append, OpenAccess.ReadWrite, OpenShare.LockReadWrite, -1)
                Label4.Text = ("Erişim Engellendi ")
            End If
            If My.Computer.FileSystem.FileExists((folderPath & "\xhunter1.sys")) Then
                FileSystem.FileOpen(2, (folderPath & "\xhunter1.sys"), OpenMode.Append, OpenAccess.ReadWrite, OpenShare.LockReadWrite, -1)

            Else
                File.WriteAllBytes((folderPath & "\xhunter1.sys"), New Byte() {0})
                FileSystem.FileOpen(2, (folderPath & "\xhunter1.sys"), OpenMode.Append, OpenAccess.ReadWrite, OpenShare.LockReadWrite, -1)
                Label5.Text = ("Erişim Engellendi")
            End If
        Catch exception1 As Exception
            ProjectData.SetProjectError(exception1)
            Dim ex As Exception = exception1
            ProjectData.SetProjectError(ex)
            Dim exception As Exception = ex
            ProjectData.ClearProjectError()
            ProjectData.ClearProjectError()
        End Try
        Timer1.Enabled = False
        Me.Finalize()
        Nosand2.Close()
        FPS.Show()
        'Dim advapi As String
        'Dim pi As Process()

        'pi = Process.GetProcessesByName("Wolfteam.bin") 'set wolfteam process

        'Dim dwOld As UInteger = 0
        'Dim p As Process = Process.GetProcessesByName("WolfTeam.bin")(0)
        'Dim hProcess As IntPtr = OpenProcess(PROCESS_ALL_ACCESS, False, p.Id)
        'For Each moz As System.Diagnostics.ProcessModule In p.Modules
        '    If moz.FileName.IndexOf("advapi32.dll") <> -1 Then
        '        advapi.Text = moz.BaseAddress.ToString
        '        VirtualProtectEx(hProcess, advapi.Text, 4096, &H40, dwOld)
        '        WriteLong("Wolfteam.bin", advapi.Text, "2332036290")
        '    End If
        'Next




        ' Dim hMod As Long = LoadLibrary("advapi32.dll")

        'Dim dwSSA As Integer = GetProcAddress(hMod, "StartServiceA")
        'Dim dwOSW As Integer = GetProcAddress(hMod, "OpenServiceW")


        ' Dim wByte As Array = {&HC2, &HC, &H0}

        ' WriteLong("WolfTeam.bin", advapi.Text, "2332036290")
        ' WriteLong("WolfTeam.bin", advapi.Text, "2332036290")

        ' If p.Count = 1 Then ' if wolfteam process detected
        Label4.Text = ("XignCode Clear Bypass")
            Label5.Text = ("XignCode Clear Bypass")

    End Sub
End Class
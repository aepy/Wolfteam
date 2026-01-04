<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Loader
    Inherits System.Windows.Forms.Form

    'Form reemplaza a Dispose para limpiar la lista de componentes.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Requerido por el Diseñador de Windows Forms
    Private components As System.ComponentModel.IContainer

    'NOTA: el Diseñador de Windows Forms necesita el siguiente procedimiento
    'Se puede modificar usando el Diseñador de Windows Forms.  
    'No lo modifique con el editor de código.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(Loader))
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.NyX_Theme1 = New FPS_LATINO_REMAKE.NYX_Theme()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.NyX_ControlBox1 = New FPS_LATINO_REMAKE.NYX_ControlBox()
        Me.NyX_Theme1.SuspendLayout()
        Me.SuspendLayout()
        '
        'Timer1
        '
        Me.Timer1.Enabled = True
        '
        'NyX_Theme1
        '
        Me.NyX_Theme1.Animated = True
        Me.NyX_Theme1.BorderStyle = System.Windows.Forms.FormBorderStyle.None
        Me.NyX_Theme1.Colors = New FPS_LATINO_REMAKE.Bloom(-1) {}
        Me.NyX_Theme1.Controls.Add(Me.Label1)
        Me.NyX_Theme1.Controls.Add(Me.NyX_ControlBox1)
        Me.NyX_Theme1.Customization = ""
        Me.NyX_Theme1.Dock = System.Windows.Forms.DockStyle.Fill
        Me.NyX_Theme1.Font = New System.Drawing.Font("Arial", 9.0!)
        Me.NyX_Theme1.Image = Nothing
        Me.NyX_Theme1.Location = New System.Drawing.Point(0, 0)
        Me.NyX_Theme1.Margin = New System.Windows.Forms.Padding(4)
        Me.NyX_Theme1.Movable = True
        Me.NyX_Theme1.Name = "NyX_Theme1"
        Me.NyX_Theme1.NoRounding = False
        Me.NyX_Theme1.Sizable = True
        Me.NyX_Theme1.Size = New System.Drawing.Size(329, 120)
        Me.NyX_Theme1.SmartBounds = True
        Me.NyX_Theme1.StartPosition = System.Windows.Forms.FormStartPosition.WindowsDefaultLocation
        Me.NyX_Theme1.TabIndex = 0
        Me.NyX_Theme1.Text = "Loader"
        Me.NyX_Theme1.TransparencyKey = System.Drawing.Color.Fuchsia
        Me.NyX_Theme1.Transparent = False
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.BackColor = System.Drawing.Color.Transparent
        Me.Label1.Font = New System.Drawing.Font("Arial", 14.0!)
        Me.Label1.ForeColor = System.Drawing.Color.FromArgb(CType(CType(192, Byte), Integer), CType(CType(0, Byte), Integer), CType(CType(0, Byte), Integer))
        Me.Label1.Location = New System.Drawing.Point(12, 51)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(284, 27)
        Me.Label1.TabIndex = 1
        Me.Label1.Text = "Esperando por WolfTeam"
        '
        'NyX_ControlBox1
        '
        Me.NyX_ControlBox1.Colors = New FPS_LATINO_REMAKE.Bloom(-1) {}
        Me.NyX_ControlBox1.Customization = ""
        Me.NyX_ControlBox1.Font = New System.Drawing.Font("Verdana", 8.0!)
        Me.NyX_ControlBox1.Image = Nothing
        Me.NyX_ControlBox1.Location = New System.Drawing.Point(249, 2)
        Me.NyX_ControlBox1.Margin = New System.Windows.Forms.Padding(4)
        Me.NyX_ControlBox1.Name = "NyX_ControlBox1"
        Me.NyX_ControlBox1.NoRounding = False
        Me.NyX_ControlBox1.Size = New System.Drawing.Size(61, 25)
        Me.NyX_ControlBox1.TabIndex = 0
        Me.NyX_ControlBox1.Text = "NyX_ControlBox1"
        Me.NyX_ControlBox1.Transparent = False
        '
        'Loader
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(8.0!, 16.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(329, 120)
        Me.Controls.Add(Me.NyX_Theme1)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None
        Me.Icon = CType(resources.GetObject("$this.Icon"), System.Drawing.Icon)
        Me.Margin = New System.Windows.Forms.Padding(4)
        Me.Name = "Loader"
        Me.ShowIcon = False
        Me.ShowInTaskbar = False
        Me.TransparencyKey = System.Drawing.Color.Fuchsia
        Me.NyX_Theme1.ResumeLayout(False)
        Me.NyX_Theme1.PerformLayout()
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents NyX_Theme1 As FPS_LATINO_REMAKE.NYX_Theme
    Friend WithEvents NyX_ControlBox1 As FPS_LATINO_REMAKE.NYX_ControlBox
    Friend WithEvents Timer1 As System.Windows.Forms.Timer
    Friend WithEvents Label1 As System.Windows.Forms.Label
End Class

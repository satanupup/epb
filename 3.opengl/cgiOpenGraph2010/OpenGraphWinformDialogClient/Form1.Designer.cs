namespace OpenGraphWinformDialogClient
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.viewToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.selectAllToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.unselectAllToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.reverseSelectToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator6 = new System.Windows.Forms.ToolStripSeparator();
            this.showAxesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.drawToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.drawNodesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.drawLinesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.drawTrianglesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.drawQuadsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.clearToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.modeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.defaultToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.trackToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.rotateToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openGLUserControl = new OpenGraphWinformDialogClient.OpenGLUserControl();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.viewToolStripMenuItem,
            this.drawToolStripMenuItem,
            this.modeToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(839, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // viewToolStripMenuItem
            // 
            this.viewToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.selectAllToolStripMenuItem,
            this.unselectAllToolStripMenuItem,
            this.reverseSelectToolStripMenuItem,
            this.toolStripSeparator6,
            this.showAxesToolStripMenuItem});
            this.viewToolStripMenuItem.Name = "viewToolStripMenuItem";
            this.viewToolStripMenuItem.Size = new System.Drawing.Size(44, 20);
            this.viewToolStripMenuItem.Text = "View";
            // 
            // selectAllToolStripMenuItem
            // 
            this.selectAllToolStripMenuItem.Name = "selectAllToolStripMenuItem";
            this.selectAllToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.selectAllToolStripMenuItem.Text = "Select All";
            this.selectAllToolStripMenuItem.Click += new System.EventHandler(this.selectAllToolStripMenuItem_Click);
            // 
            // unselectAllToolStripMenuItem
            // 
            this.unselectAllToolStripMenuItem.Name = "unselectAllToolStripMenuItem";
            this.unselectAllToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.unselectAllToolStripMenuItem.Text = "Unselect All";
            this.unselectAllToolStripMenuItem.Click += new System.EventHandler(this.unselectAllToolStripMenuItem_Click);
            // 
            // reverseSelectToolStripMenuItem
            // 
            this.reverseSelectToolStripMenuItem.Name = "reverseSelectToolStripMenuItem";
            this.reverseSelectToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.reverseSelectToolStripMenuItem.Text = "Reverse Select";
            this.reverseSelectToolStripMenuItem.Click += new System.EventHandler(this.reverseSelectToolStripMenuItem_Click);
            // 
            // toolStripSeparator6
            // 
            this.toolStripSeparator6.Name = "toolStripSeparator6";
            this.toolStripSeparator6.Size = new System.Drawing.Size(149, 6);
            // 
            // showAxesToolStripMenuItem
            // 
            this.showAxesToolStripMenuItem.Name = "showAxesToolStripMenuItem";
            this.showAxesToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.showAxesToolStripMenuItem.Text = "Show Axes";
            this.showAxesToolStripMenuItem.Click += new System.EventHandler(this.showAxesToolStripMenuItem_Click);
            // 
            // drawToolStripMenuItem
            // 
            this.drawToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.drawNodesToolStripMenuItem,
            this.drawLinesToolStripMenuItem,
            this.drawTrianglesToolStripMenuItem,
            this.drawQuadsToolStripMenuItem,
            this.toolStripSeparator2,
            this.clearToolStripMenuItem});
            this.drawToolStripMenuItem.Name = "drawToolStripMenuItem";
            this.drawToolStripMenuItem.Size = new System.Drawing.Size(46, 20);
            this.drawToolStripMenuItem.Text = "Draw";
            // 
            // drawNodesToolStripMenuItem
            // 
            this.drawNodesToolStripMenuItem.Name = "drawNodesToolStripMenuItem";
            this.drawNodesToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.drawNodesToolStripMenuItem.Text = "Draw Nodes";
            this.drawNodesToolStripMenuItem.Click += new System.EventHandler(this.drawNodesToolStripMenuItem_Click);
            // 
            // drawLinesToolStripMenuItem
            // 
            this.drawLinesToolStripMenuItem.Name = "drawLinesToolStripMenuItem";
            this.drawLinesToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.drawLinesToolStripMenuItem.Text = "Draw Lines";
            this.drawLinesToolStripMenuItem.Click += new System.EventHandler(this.drawLinesToolStripMenuItem_Click);
            // 
            // drawTrianglesToolStripMenuItem
            // 
            this.drawTrianglesToolStripMenuItem.Name = "drawTrianglesToolStripMenuItem";
            this.drawTrianglesToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.drawTrianglesToolStripMenuItem.Text = "Draw Triangles";
            this.drawTrianglesToolStripMenuItem.Click += new System.EventHandler(this.drawTrianglesToolStripMenuItem_Click);
            // 
            // drawQuadsToolStripMenuItem
            // 
            this.drawQuadsToolStripMenuItem.Name = "drawQuadsToolStripMenuItem";
            this.drawQuadsToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.drawQuadsToolStripMenuItem.Text = "Draw Quads";
            this.drawQuadsToolStripMenuItem.Click += new System.EventHandler(this.drawQuadsToolStripMenuItem_Click);
            // 
            // clearToolStripMenuItem
            // 
            this.clearToolStripMenuItem.Name = "clearToolStripMenuItem";
            this.clearToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.clearToolStripMenuItem.Text = "Clear";
            this.clearToolStripMenuItem.Click += new System.EventHandler(this.clearToolStripMenuItem_Click);
            // 
            // modeToolStripMenuItem
            // 
            this.modeToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.defaultToolStripMenuItem,
            this.trackToolStripMenuItem,
            this.rotateToolStripMenuItem});
            this.modeToolStripMenuItem.Name = "modeToolStripMenuItem";
            this.modeToolStripMenuItem.Size = new System.Drawing.Size(50, 20);
            this.modeToolStripMenuItem.Text = "Mode";
            // 
            // defaultToolStripMenuItem
            // 
            this.defaultToolStripMenuItem.Name = "defaultToolStripMenuItem";
            this.defaultToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.defaultToolStripMenuItem.Text = "Default";
            this.defaultToolStripMenuItem.Click += new System.EventHandler(this.defaultToolStripMenuItem_Click);
            // 
            // trackToolStripMenuItem
            // 
            this.trackToolStripMenuItem.Name = "trackToolStripMenuItem";
            this.trackToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.trackToolStripMenuItem.Text = "Track";
            this.trackToolStripMenuItem.Click += new System.EventHandler(this.trackToolStripMenuItem_Click);
            // 
            // rotateToolStripMenuItem
            // 
            this.rotateToolStripMenuItem.Name = "rotateToolStripMenuItem";
            this.rotateToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.rotateToolStripMenuItem.Text = "Rotate";
            this.rotateToolStripMenuItem.Click += new System.EventHandler(this.rotateToolStripMenuItem_Click);
            // 
            // openGLUserControl
            // 
            this.openGLUserControl.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.openGLUserControl.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.openGLUserControl.Location = new System.Drawing.Point(107, 27);
            this.openGLUserControl.Name = "openGLUserControl";
            this.openGLUserControl.Size = new System.Drawing.Size(700, 476);
            this.openGLUserControl.TabIndex = 1;
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(149, 6);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(839, 539);
            this.Controls.Add(this.openGLUserControl);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.Resize += new System.EventHandler(this.Form1_Resize);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem modeToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem defaultToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem trackToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem drawToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem drawNodesToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem drawLinesToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem drawTrianglesToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem rotateToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem viewToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem selectAllToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem unselectAllToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem reverseSelectToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem drawQuadsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem clearToolStripMenuItem;
        private OpenGLUserControl openGLUserControl;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator6;
        private System.Windows.Forms.ToolStripMenuItem showAxesToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
    }
}


////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2002-2013 Computations & Graphics, Inc. 
// 
// All rights reserved.
//
// Author: Junlin Xu
//
//////////////////////////////////////////////////////////////////////////

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;

namespace OpenGraphWinformDialogClient
{
    public partial class OpenGLUserControl : UserControl
    {
        public delegate void OpenGLUserControl_MouseWheel_Type(object sender, MouseEventArgs e);
        public delegate void OpenGLUserControl_Load_Type(object sender, EventArgs e);
        public delegate void OpenGLUserControl_Resize_Type(object sender, EventArgs e);
        public delegate void OpenGLUserControl_MouseDown_Type(object sender, MouseEventArgs e);
        public delegate void OpenGLUserControl_MouseMove_Type(object sender, MouseEventArgs e);
        public delegate void OpenGLUserControl_Paint_Type(object sender, PaintEventArgs e);

        public OpenGLUserControl_MouseWheel_Type MouseWheel_CallBack = null;
        public OpenGLUserControl_Load_Type Load_CallBack = null;
        public OpenGLUserControl_Resize_Type Resize_CallBack = null;
        public OpenGLUserControl_MouseDown_Type MouseDown_CallBack = null;
        public OpenGLUserControl_MouseMove_Type MouseMove_CallBack = null;
        public OpenGLUserControl_Paint_Type Paint_CallBack = null;

        public OpenGLUserControl()
        {
            InitializeComponent();
            this.MouseWheel += new MouseEventHandler(OpenGLUserControl_MouseWheel);
        }


        private void OpenGLUserControl_MouseWheel(object sender, MouseEventArgs e)
        {
            if (MouseWheel_CallBack != null)
            {
                MouseWheel_CallBack(sender, e);
            }
        }

        private void OpenGLUserControl_Load(object sender, EventArgs e)
        {
            if (Load_CallBack != null)
            {
                Load_CallBack(sender, e);
            }
        }

        private void OpenGLUserControl_Resize(object sender, EventArgs e)
        {
            if (Resize_CallBack != null)
            {
                Resize_CallBack(sender, e);
            }

        }

        private void OpenGLUserControl_MouseDown(object sender, MouseEventArgs e)
        {
            if (MouseDown_CallBack != null)
            {
                MouseDown_CallBack(sender, e);
            }
        }

        private void OpenGLUserControl_MouseMove(object sender, MouseEventArgs e)
        {
            if (MouseMove_CallBack != null)
            {
                MouseMove_CallBack(sender, e);
            }
        }

        private void OpenGLUserControl_Paint(object sender, PaintEventArgs e)
        {
            if (Paint_CallBack != null)
            {
                Paint_CallBack(sender, e);
            }

        }
    }
}

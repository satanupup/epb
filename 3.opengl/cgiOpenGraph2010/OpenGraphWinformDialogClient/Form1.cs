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
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using NSOpenGraphLib_Cli;

namespace OpenGraphWinformDialogClient
{
    public partial class Form1 : Form
    {
        COpenGraph_Cli _openGraph_Cli = new COpenGraph_Cli();
        private int m_nCx = 0;
        private int m_nCy = 0;
        private bool m_bShowAxes = true;

        public Form1()
        {
            InitializeComponent();

            openGLUserControl.Load_CallBack = this.Delegate_Load;
            openGLUserControl.MouseMove_CallBack = this.Delegate_MouseMove;
            openGLUserControl.MouseDown_CallBack = this.Delegate_MouseDown;
            openGLUserControl.Paint_CallBack = this.Delegate_Paint;
            openGLUserControl.Resize_CallBack = this.Delegate_Resize;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void Form1_Resize(object sender, EventArgs e)
        {
            m_nCx = this.openGLUserControl.Width;
            m_nCy = this.openGLUserControl.Height;
            _openGraph_Cli.SetWindowSize(m_nCx, m_nCy);
            _openGraph_Cli.Render();
        }


        private void Delegate_Load(object sender, EventArgs e)
        {
            _openGraph_Cli.Initialize(openGLUserControl.Handle);
            m_nCx = this.openGLUserControl.Width;
            m_nCy = this.openGLUserControl.Height;
            _openGraph_Cli.SetWindowSize(m_nCx, m_nCy);
            _openGraph_Cli.Render();
            _openGraph_Cli.SetMode(COpenGraph_Cli.Mode.modeNONE);

        }

        private void Delegate_MouseMove(object sender, MouseEventArgs e)
        {
            _openGraph_Cli.OnSetCursor();
            if (e.Button == MouseButtons.Left)
            {
                CRect_Cli rect = new CRect_Cli();
                CPoint_Cli pt = new CPoint_Cli();
                pt.X = e.X;
                pt.Y = e.Y;

                uint nFlags = (int)COpenGraph_Cli.ButtonFlag.flagMK_LBUTTON;
                if (_openGraph_Cli != null)
                {
                    _openGraph_Cli.OnMouseMove(nFlags, pt);
                }
            }
        }

        private void Delegate_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                CRect_Cli rect = new CRect_Cli();
                CPoint_Cli pt = new CPoint_Cli();
                pt.X = e.X;
                pt.Y = e.Y;
                uint nFlags = 0;
                if (_openGraph_Cli != null)
                {
                    _openGraph_Cli.OnLButtonDown(ref rect, nFlags, pt);
                }
            }
        }

        private void Delegate_Paint(object sender, PaintEventArgs e)
        {
            if (_openGraph_Cli != null)
            {
                _openGraph_Cli.Render();
            }
        }

        private void Delegate_Resize(object sender, EventArgs e)
        {
            if (_openGraph_Cli != null)
            {
                m_nCx = this.ClientSize.Width;
                m_nCy = this.ClientSize.Height - menuStrip1.Height;
                _openGraph_Cli.SetWindowSize(m_nCx, m_nCy);
            }
        }


        // view -----------------------------------------------

        private void selectAllToolStripMenuItem_Click(object sender, EventArgs e)
        {
            _openGraph_Cli.SelectAll();
            _openGraph_Cli.Render();
        }

        private void unselectAllToolStripMenuItem_Click(object sender, EventArgs e)
        {
            _openGraph_Cli.UnSelectAll();
            _openGraph_Cli.Render();
        }

        private void reverseSelectToolStripMenuItem_Click(object sender, EventArgs e)
        {
            _openGraph_Cli.ReverseSelectAll();
            _openGraph_Cli.Render();
        }


        // draw -------------------------------------------------------
        private void drawNodesToolStripMenuItem_Click(object sender, EventArgs e)
        {
            int fontId = _openGraph_Cli.AddFont("Times New Roman", 30, 0, 0);
            Random random = new Random();

            const int nNodes = 400;
            const int nBatches = 10;
            const int nNodesPerBatch = nNodes / nBatches;
            for (int j = 0; j < nBatches; j++)
            {
                CColor_Cli color = new CColor_Cli((byte)(random.Next(0, 256)), (byte)(random.Next(0, 256)), (byte)(random.Next(0, 256)));
                CColor_Cli colorSelected = new CColor_Cli(255, 0, 0);
                List<CPointf_Cli> pPt = new List<CPointf_Cli>();
                List<int> pId = new List<int>();
                int nSize = (random.Next(0, 256) % 8);
                string strTag;
                strTag = string.Format("Tag_{0}", j);
                for (int i = 0; i < nNodesPerBatch; i++)
                {
                    double x = ((double)random.Next(0, 256) / 256 - 0.5) * 4;
                    double y = ((double)random.Next(0, 256) / 256 - 0.5) * 4;
                    double z = ((double)random.Next(0, 256) / 256 - 0.5) * 4;
                    string strText;
                    int id = j * nNodesPerBatch + i + 1;
                    strText = string.Format("{0}", id);
                    if (i % 2 == 0)
                    {
                        _openGraph_Cli.AddText(id, 0, new CPointf_Cli(x, y, z), strText, new CColor_Cli(125, 123, 0), colorSelected,
                                                    CTextAlignment_Cli.ALIGN_LEFT | CTextAlignment_Cli.ALIGN_BOTTOM, CStatus_Cli.STATUS_UNSELECTED);
                    }
                    else
                    {
                        _openGraph_Cli.AddText(id, fontId, new CPointf_Cli(x, y, z), strText, new CColor_Cli(0, 123, 123), colorSelected,
                            CTextAlignment_Cli.ALIGN_LEFT | CTextAlignment_Cli.ALIGN_BOTTOM, CStatus_Cli.STATUS_UNSELECTED);
                    }
                    pId.Add(id);
                    pPt.Add(new CPointf_Cli(x, y, z));
                }
                List<CIdentity_Cli> pIdentity = new List<CIdentity_Cli>();
                // for performance reason, you should send in your data in batches
                _openGraph_Cli.AddNodes(ref pIdentity, pId, pPt, nSize, color, colorSelected, CStatus_Cli.STATUS_UNSELECTED, strTag, null);
            }

            //CIdentity_Cli^ AddNode(int id,CPointf_Cli^ pt, int nSize, CColor_Cli^ color,CColor_Cli^ colorSelected, int nStatus, String^ tag, String^ userData);
            _openGraph_Cli.AddNode(99999, new CPointf_Cli(), 15, new CColor_Cli(255, 255, 0), new CColor_Cli(0, 255, 255), 0, null, null);
            _openGraph_Cli.AddText(99999, 0, new CPointf_Cli(), "99999", new CColor_Cli(125, 123, 0), new CColor_Cli(0, 255, 255),
                CTextAlignment_Cli.ALIGN_LEFT | CTextAlignment_Cli.ALIGN_BOTTOM, CStatus_Cli.STATUS_UNSELECTED);


            _openGraph_Cli.Render();
        }

        private void drawLinesToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Random random = new Random();
            
            const int nNodes = 300;
            const int nBatches = 30;
            const int nLinesPerBatch = nNodes / nBatches;
            for (int j = 0; j < nBatches; j++)
            {
                CColor_Cli color = new CColor_Cli(((byte)random.Next(0, 256)), ((byte)random.Next(0, 256)), ((byte)random.Next(0, 256)));
                CColor_Cli colorSelected = new CColor_Cli(255, 0, 0);
                List<CPointf_Cli> pPt1 = new List<CPointf_Cli>();
                List<CPointf_Cli> pPt2 = new List<CPointf_Cli>();
                List<int> pId = new List<int>();
                int nSize = (random.Next(0, 256) % 8);
                string strTag;
                strTag = string.Format("Tag_{0}", j);
                for (int i = 0; i < nLinesPerBatch; i++)
                {
                    double x1 = ((double)random.Next(0, 256) / 256 - 0.5) * 4;
                    double y1 = ((double)random.Next(0, 256) / 256 - 0.5) * 4;
                    double z1 = ((double)random.Next(0, 256) / 256 - 0.5) * 4;
                    double x2 = ((double)random.Next(0, 256) / 256 - 0.3) * 4;
                    double y2 = ((double)random.Next(0, 256) / 256 - 0.2) * 4;
                    double z2 = ((double)random.Next(0, 256) / 256 - 0.4) * 4;
                    int id = j * nLinesPerBatch + i + 1;
                    pId.Add(id);
                    pPt1.Add(new CPointf_Cli(x1, y1, z1));
                    pPt2.Add(new CPointf_Cli(x2, y2, z2));

                    string strText;
                    strText = string.Format("{0}", id);
                    CPointf_Cli pos = new CPointf_Cli((pPt1[i].X + pPt2[i].X) / 2, (pPt1[i].Y + pPt2[i].Y) / 2, (pPt1[i].Z + pPt2[i].Z) / 2);
                    _openGraph_Cli.AddText(id, 0, pos, strText, new CColor_Cli(255, 0, 0), colorSelected,
                                        CTextAlignment_Cli.ALIGN_LEFT | CTextAlignment_Cli.ALIGN_BOTTOM, CStatus_Cli.STATUS_UNSELECTED);
                }
                List<CIdentity_Cli> pIdentity = new List<CIdentity_Cli>();
                // for performance reason, you should send in your data in batches
                _openGraph_Cli.AddLines(ref pIdentity, pId, pPt1, pPt2, nSize, color, colorSelected, 0, strTag, null);
            }

            _openGraph_Cli.AddLine(99999, new CPointf_Cli(-2, 0, 0), new CPointf_Cli(2, 0, 0), 15, new CColor_Cli(255, 255, 0), new CColor_Cli(0, 255, 255), 0, null, null);
            _openGraph_Cli.AddText(99999, 0, new CPointf_Cli(0, 0, 0), "99999", new CColor_Cli(125, 123, 0), new CColor_Cli(0, 123, 0),
                CTextAlignment_Cli.ALIGN_LEFT | CTextAlignment_Cli.ALIGN_BOTTOM, CStatus_Cli.STATUS_UNSELECTED);

            _openGraph_Cli.Render();
        }

        private void drawTrianglesToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Random random = new Random();
            CPointf_Cli[] pt = { new CPointf_Cli(0.5, 0, -0.5), new CPointf_Cli(0.5, 0, 0.5), new CPointf_Cli(-0.5, 0, 0.5), new CPointf_Cli(0, 2, 0) };
            CColor_Cli colorSelected = new CColor_Cli(255, 255, 0);
            string strTag = "";

            _openGraph_Cli.AddTriangle(1, pt[0], pt[1], pt[2], new CColor_Cli(123, 0, 123), colorSelected, 1, 0, strTag, null);
            _openGraph_Cli.AddTriangle(2, pt[0], pt[1], pt[3], new CColor_Cli(65, 0, 0), colorSelected, 1, 0, strTag, null);
            _openGraph_Cli.AddTriangle(3, pt[0], pt[3], pt[2], new CColor_Cli(123, 0, 0), colorSelected, 1, 0, strTag, null);
            _openGraph_Cli.AddTriangle(4, pt[2], pt[3], pt[1], new CColor_Cli(225, 0, 0), colorSelected, 1, 0, strTag, null);

            // two transparent triangle
            List<CPointf_Cli> pt1 = new List<CPointf_Cli>();
            pt1.Add(new CPointf_Cli(-1.5, -1.5, 1));
            pt1.Add(new CPointf_Cli(-1.5, -1.5, 1));

            List<CPointf_Cli> pt2 = new List<CPointf_Cli>();
            pt2.Add(new CPointf_Cli(1.2, 1.5, 1));
            pt2.Add(new CPointf_Cli(1.2, 1.5, 1));

            List<CPointf_Cli> pt3 = new List<CPointf_Cli>();
            pt3.Add(new CPointf_Cli(-2, 2.2, 1));
            pt3.Add(new CPointf_Cli(2, 0.2, 1));

            List<int> ids = new List<int>();
            ids.Add(5);
            ids.Add(6);

            List<CIdentity_Cli> identity = new List<CIdentity_Cli>();
            _openGraph_Cli.AddTriangles(ref identity, ids, pt1, pt2, pt3, new CColor_Cli(0, 0, 255), colorSelected, 0.5f, 0, strTag, null);
            _openGraph_Cli.AddText(5, 0, new CPointf_Cli((-1.5 + 1.2 + -2) / 3, (-1.5 + 1.5 + 2.2)/3, (1.0 + 1 + 1)/3), "5", new CColor_Cli(125, 123, 0), colorSelected,
                CTextAlignment_Cli.ALIGN_LEFT | CTextAlignment_Cli.ALIGN_BOTTOM, CStatus_Cli.STATUS_UNSELECTED);
            _openGraph_Cli.AddText(6, 0, new CPointf_Cli((-1.5 + 1.2 + 2) / 3.0, (-1.5 + 1.5 + 0.2)/3.0, (1 + 1 + 1)/3.0), "6", new CColor_Cli(125, 123, 0), colorSelected,
                CTextAlignment_Cli.ALIGN_LEFT | CTextAlignment_Cli.ALIGN_BOTTOM, CStatus_Cli.STATUS_UNSELECTED);

            _openGraph_Cli.Render();
        }


        private void BoxPts(ref CPointf_Cli[] pt, CPointf_Cli ptCenter, double fDeltaX, double fDeltaY, double fDeltaZ)
        {
            pt[0].X = ptCenter.X + fDeltaX / 2.0;
            pt[0].Y = ptCenter.Y + fDeltaY / 2.0;
            pt[0].Z = ptCenter.Z + fDeltaZ / 2.0;
            CPointf_Cli.Copy(pt[1], pt[0]);    // jxu: import, CPointf_Cli is reference type
            pt[1].X = ptCenter.X - fDeltaX / 2.0;
            CPointf_Cli.Copy(pt[2], pt[1]); 
            pt[2].Y = ptCenter.Y - fDeltaY / 2.0;
            CPointf_Cli.Copy(pt[3], pt[2]); 
            pt[3].X = pt[0].X;

            for (int i = 0; i < 4; i++)
            {
                CPointf_Cli.Copy(pt[i + 4], pt[i]); 
                pt[i + 4].Z = ptCenter.Z - fDeltaZ / 2.0;
            }

        }

        private void drawQuadsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            CColor_Cli colorSelected = new CColor_Cli(123, 0, 255);
            string strTag = "";
            CPointf_Cli[] pt = new CPointf_Cli[8];
            for (int i = 0; i < 8; i++ )
            {
                pt[i] = new CPointf_Cli(0, 0, 0);
            }
            CColor_Cli color = new CColor_Cli((byte)(0.8 * 255), 0, 0);
            BoxPts(ref pt, new CPointf_Cli(0, 0, 0), 0.5, 2, 1);
            _openGraph_Cli.AddQuad(1, pt[1], pt[0], pt[4], pt[5], new CColor_Cli(65, 0, 0), colorSelected, 1, 0, strTag, null);
            _openGraph_Cli.AddQuad(2, pt[3], pt[2], pt[6], pt[7], new CColor_Cli(65, 0, 0), colorSelected, 1, 0, strTag, null);
            _openGraph_Cli.AddQuad(3, pt[2], pt[1], pt[5], pt[6], new CColor_Cli(123, 0, 0), colorSelected, 1, 0, strTag, null);
            _openGraph_Cli.AddQuad(4, pt[0], pt[3], pt[7], pt[4], new CColor_Cli(123, 0, 0), colorSelected, 1, 0, strTag, null);
            _openGraph_Cli.AddQuad(5, pt[0], pt[1], pt[2], pt[3], new CColor_Cli(225, 0, 0), colorSelected, 1, 0, strTag, null);
            _openGraph_Cli.AddQuad(6, pt[7], pt[6], pt[5], pt[4], new CColor_Cli(225, 0, 0), colorSelected, 1, 0, strTag, null);

            List<CPointf_Cli> pt1 = new List<CPointf_Cli>();
            pt1.Add(new CPointf_Cli(-1.5, -1.5, 10));
            pt1.Add(new CPointf_Cli(0, -1.5, 10));

            List<CPointf_Cli> pt2 = new List<CPointf_Cli>();
            pt2.Add(new CPointf_Cli(0, -1.5, 10));
            pt2.Add(new CPointf_Cli(1.5, -1.5, 10));

            List<CPointf_Cli> pt3 = new List<CPointf_Cli>();
            pt3.Add(new CPointf_Cli(0, 1.5, 10));
            pt3.Add(new CPointf_Cli(1.5, 1.5, 10));

            List<CPointf_Cli> pt4 = new List<CPointf_Cli>();
            pt4.Add(new CPointf_Cli(-1.5, 1.5, 10));
            pt4.Add(new CPointf_Cli(0, 1.5, 10));

            List<int> ids = new List<int>();
            ids.Add(7);
            ids.Add(8);
            List<CIdentity_Cli> identity = new List<CIdentity_Cli>();
            _openGraph_Cli.AddQuads(ref identity, ids, pt1, pt2, pt3, pt4, new CColor_Cli(0, 0, 255), colorSelected, 0.5f, 0, strTag, null);
            _openGraph_Cli.AddText(5, 0, new CPointf_Cli(-0.75, 0, 10), "7", new CColor_Cli(125, 123, 0), colorSelected,
                CTextAlignment_Cli.ALIGN_LEFT | CTextAlignment_Cli.ALIGN_BOTTOM, CStatus_Cli.STATUS_UNSELECTED);
            _openGraph_Cli.AddText(5, 0, new CPointf_Cli(0.75, 0, 10), "8", new CColor_Cli(125, 123, 0), colorSelected,
                CTextAlignment_Cli.ALIGN_LEFT | CTextAlignment_Cli.ALIGN_BOTTOM, CStatus_Cli.STATUS_UNSELECTED);

            _openGraph_Cli.Render();
        }

        private void clearToolStripMenuItem_Click(object sender, EventArgs e)
        {
            _openGraph_Cli.Clear();
            _openGraph_Cli.Render();
        }

        // mode ---------------------------------------

        private void defaultToolStripMenuItem_Click(object sender, EventArgs e)
        {
            _openGraph_Cli.SetMode(COpenGraph_Cli.Mode.modeNONE);
        }

        private void trackToolStripMenuItem_Click(object sender, EventArgs e)
        {
            _openGraph_Cli.SetMode(COpenGraph_Cli.Mode.modeTRACK);
        }

        private void rotateToolStripMenuItem_Click(object sender, EventArgs e)
        {
            _openGraph_Cli.SetMode(COpenGraph_Cli.Mode.modeROTATE);
        }

        private void showAxesToolStripMenuItem_Click(object sender, EventArgs e)
        {
            m_bShowAxes = !m_bShowAxes;
            _openGraph_Cli.ShowAxes(m_bShowAxes);
            _openGraph_Cli.Render();
        }

    }

}
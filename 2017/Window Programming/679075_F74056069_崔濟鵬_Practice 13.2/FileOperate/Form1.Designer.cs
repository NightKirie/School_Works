namespace FileOperate
{
    partial class Form1
    {
        /// <summary>
        /// 設計工具所需的變數。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清除任何使用中的資源。
        /// </summary>
        /// <param name="disposing">如果應該處置 Managed 資源則為 true，否則為 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 設計工具產生的程式碼

        /// <summary>
        /// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
        /// 修改這個方法的內容。
        /// </summary>
        private void InitializeComponent()
        {
            this.btnCreate = new System.Windows.Forms.Button();
            this.txtInput = new System.Windows.Forms.TextBox();
            this.txtSource = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.btnSave = new System.Windows.Forms.Button();
            this.btnMove = new System.Windows.Forms.Button();
            this.txtOutput = new System.Windows.Forms.TextBox();
            this.btnWriteBin = new System.Windows.Forms.Button();
            this.btnReadBin = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnCreate
            // 
            this.btnCreate.Location = new System.Drawing.Point(139, 209);
            this.btnCreate.Name = "btnCreate";
            this.btnCreate.Size = new System.Drawing.Size(62, 22);
            this.btnCreate.TabIndex = 23;
            this.btnCreate.Text = "建立";
            this.btnCreate.UseVisualStyleBackColor = true;
            this.btnCreate.Click += new System.EventHandler(this.btnCreate_Click);
            // 
            // txtInput
            // 
            this.txtInput.Location = new System.Drawing.Point(13, 34);
            this.txtInput.Multiline = true;
            this.txtInput.Name = "txtInput";
            this.txtInput.Size = new System.Drawing.Size(224, 96);
            this.txtInput.TabIndex = 22;
            // 
            // txtSource
            // 
            this.txtSource.Font = new System.Drawing.Font("新細明體", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.txtSource.Location = new System.Drawing.Point(182, 156);
            this.txtSource.Name = "txtSource";
            this.txtSource.Size = new System.Drawing.Size(271, 23);
            this.txtSource.TabIndex = 20;
            this.txtSource.Text = "..\\..\\..\\";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(101, 158);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(61, 13);
            this.label1.TabIndex = 18;
            this.label1.Text = "目的路徑 :";
            // 
            // btnSave
            // 
            this.btnSave.Location = new System.Drawing.Point(234, 209);
            this.btnSave.Name = "btnSave";
            this.btnSave.Size = new System.Drawing.Size(62, 22);
            this.btnSave.TabIndex = 24;
            this.btnSave.Text = "存檔";
            this.btnSave.UseVisualStyleBackColor = true;
            this.btnSave.Click += new System.EventHandler(this.btnSave_Click);
            // 
            // btnMove
            // 
            this.btnMove.Location = new System.Drawing.Point(334, 209);
            this.btnMove.Name = "btnMove";
            this.btnMove.Size = new System.Drawing.Size(62, 22);
            this.btnMove.TabIndex = 25;
            this.btnMove.Text = "搬移";
            this.btnMove.UseVisualStyleBackColor = true;
            this.btnMove.Click += new System.EventHandler(this.btnMove_Click);
            // 
            // txtOutput
            // 
            this.txtOutput.Location = new System.Drawing.Point(274, 34);
            this.txtOutput.Multiline = true;
            this.txtOutput.Name = "txtOutput";
            this.txtOutput.ReadOnly = true;
            this.txtOutput.Size = new System.Drawing.Size(224, 96);
            this.txtOutput.TabIndex = 26;
            // 
            // btnWriteBin
            // 
            this.btnWriteBin.Location = new System.Drawing.Point(139, 283);
            this.btnWriteBin.Name = "btnWriteBin";
            this.btnWriteBin.Size = new System.Drawing.Size(119, 22);
            this.btnWriteBin.TabIndex = 27;
            this.btnWriteBin.Text = "寫入二進位檔";
            this.btnWriteBin.UseVisualStyleBackColor = true;
            this.btnWriteBin.Click += new System.EventHandler(this.btnWriteBin_Click);
            // 
            // btnReadBin
            // 
            this.btnReadBin.Location = new System.Drawing.Point(274, 283);
            this.btnReadBin.Name = "btnReadBin";
            this.btnReadBin.Size = new System.Drawing.Size(122, 22);
            this.btnReadBin.TabIndex = 28;
            this.btnReadBin.Text = "從二進位檔讀出";
            this.btnReadBin.UseVisualStyleBackColor = true;
            this.btnReadBin.Click += new System.EventHandler(this.btnReadBin_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(522, 352);
            this.Controls.Add(this.btnReadBin);
            this.Controls.Add(this.btnWriteBin);
            this.Controls.Add(this.txtOutput);
            this.Controls.Add(this.btnMove);
            this.Controls.Add(this.btnSave);
            this.Controls.Add(this.btnCreate);
            this.Controls.Add(this.txtInput);
            this.Controls.Add(this.txtSource);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "檔案操作";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Button btnCreate;
        private System.Windows.Forms.TextBox txtInput;
        private System.Windows.Forms.TextBox txtSource;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btnSave;
        private System.Windows.Forms.Button btnMove;
        private System.Windows.Forms.TextBox txtOutput;
        private System.Windows.Forms.Button btnWriteBin;
        private System.Windows.Forms.Button btnReadBin;
    }
}


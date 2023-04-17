//USB Gamepad Uygulaması v1.01, 11.06.2010
//Umut Erkal, www.uerkal.com
//Proje dosyalarını gönül rahatlığıyla kullanabilirsiniz.

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Microsoft.DirectX;
using Microsoft.DirectX.DirectInput;

//Eklenecek referans dosyaları (DirectX SDK):
//C:\Windows\Microsoft.NET\DirectX for Managed Code\1.0.2902.0\Microsoft.DirectX.dll
//C:\Windows\Microsoft.NET\DirectX for Managed Code\1.0.2902.0\Microsoft.DirectX.DirectInput.dll

namespace Gamepad
{
    public partial class frmGamepad : Form
    {
        public frmGamepad()
        {
            InitializeComponent();
        }

        Device joystick;
        JoystickState joystickState;
        Byte[] joystickButtons;
        Int32[] jPOV0;

        private void frmGamepad_Load(object sender, EventArgs e)
        {
            DeviceList gamepadListesi = Manager.GetDevices(DeviceClass.GameControl, EnumDevicesFlags.AttachedOnly);
            if (gamepadListesi.Count > 0)
            {
                foreach (DeviceInstance deviceInstance in gamepadListesi)
                {
                    joystick = new Device(deviceInstance.InstanceGuid);
                    joystick.SetCooperativeLevel(this, CooperativeLevelFlags.Background | CooperativeLevelFlags.NonExclusive);
                    break;
                }

                joystick.SetDataFormat(DeviceDataFormat.Joystick);
                joystick.Acquire();

                Timer tmr = new Timer();
                tmr.Interval = 100;
                tmr.Enabled = true;
                tmr.Tick += new EventHandler(tmr_Tick);
                tmr.Start();
            }
        }

        void tmr_Tick(object sender, EventArgs e)
        {
            joystick.Poll();
            joystickState = joystick.CurrentJoystickState;
            joystickButtons = joystickState.GetButtons();
            jPOV0 = joystickState.GetPointOfView();

            //Axis - Rotation
            lblXAxis.Text = joystickState.X.ToString();
            lblYAxis.Text = joystickState.Y.ToString();
            lblZAxis.Text = joystickState.Z.ToString();
            lblXRotation.Text = joystickState.Rx.ToString();
            lblYRotation.Text = joystickState.Ry.ToString();

            //Butonlar
            lblBtn0.Text = joystickButtons[0].ToString();
            lblBtn1.Text = joystickButtons[1].ToString();
            double sayi = 0.01;
            if (joystickButtons[1] == 128)
            {
                if (serialPort1.IsOpen == true)
                {
                    sayi += 0.1;
                    int tr1Deger = (int)sayi;
                    string deger = tr1Deger.ToString();
                    serialPort1.Write("D" + deger);
                
                }
            }
            if (joystickButtons[3] == 128)
            {
                if (serialPort1.IsOpen == true)
                {
                    sayi -= 0.1;
                    int tr1Deger = (int)sayi;
                    string deger = tr1Deger.ToString();
                    serialPort1.Write("D" + deger);

                }
            }

            lblBtn2.Text = joystickButtons[2].ToString();
            lblBtn3.Text = joystickButtons[3].ToString();
            lblBtn4.Text = joystickButtons[4].ToString();
            lblBtn5.Text = joystickButtons[5].ToString();
            lblBtn6.Text = joystickButtons[6].ToString();
            lblBtn7.Text = joystickButtons[7].ToString();
            lblBtn8.Text = joystickButtons[8].ToString();
            lblBtn9.Text = joystickButtons[9].ToString();
            lblBtn10.Text = joystickButtons[10].ToString();
            lblBtn11.Text = joystickButtons[11].ToString();

            //Point of View
            lblPOV0.Text = jPOV0[0].ToString();
        }

        private void frmGamepad_FormClosing(object sender, FormClosingEventArgs e)
        {
            joystick.Unacquire();
        }

        private void btnBaglan_Click(object sender, EventArgs e)
        {
            try
            {
                serialPort1.PortName = textBox1.Text;
                serialPort1.BaudRate = 9600;
                serialPort1.Open();
                if (serialPort1.IsOpen)
                {
                    
                    lblBaglanti.Text = "Bağlanıldı";
                }
            }
            catch
            {
                lblBaglanti.Text = "Bağlanılamadı";
            }
        }
    }
}
Step 1) How to install Keil uVision for the ARM, MDK-Lite (32KB) Edition


We are using Keil uVision IDE, and we are writing software in C. 
These programs only run on Windows (XP, Vista, 7 or 8.)
 There is a way to install software on a Macintosh so Windows and its applications will run on the Macintosh, see running Keil and TExaS on a Macintosh.
 We are really sorry, but there are no solutions for Linux. The Lite version of Keil application does not require a serial number or license key.

1) Go to https://www.keil.com/demo/eval/armv4.htm. Enter your contact information with valid address, phone and email. Set your Company to your school, your company, or your personal business. Set your devices to TM4C123 or TM4C1294. Fill in all fields of this form. It should not cost any money, and you can select or not select whether you want email from ARM. ARM does provide support for Keil via its ARM University. So if you have any Keil-specific questions you could register and post them at http://www.arm.com/university/

2) Right-click on mdk474.exe and download this 590M file to your computer. There is a Keil version 5, but these examples were tested on Keil version 4.7x.

3) Execute the mdk474.exe file, installing the application some place easy to find, like C:\Keil or D:\Keil. You will need to find the Keil directory because the TExaS example files will be loaded into this same directory.

After you have run the mdk474.exe installer, you will not need this file. However you can use this file to install Keil on additional computers.


Step 2) TExaS Lab Graders for all Labs
We have written DLL extensions to the Keil uVision IDE that will evaluate your lab solutions. We have named this set of DLLs as Test EXecute and Simulate or TExaS. There is also an application called TExaSdisplay that provides interaction with your serial port software running on the LaunchPad. TExaSdisplay is like HyperTerminal or PuTTy but much simpler and adds grading for Labs 5 and 11. The application TExaSdisplay also provides a simple oscilloscope and voltmeter, which is a voltage versus time graphical plot measured from PD3. For those students who did not purchase the optional Nokia display, TExaSdisplay also simulates the graphics display used in Lab 15. You will need to first install Keil before installing TExaS. You will find the lab starter projects in the Keil\Labware folder, and you will find the example projects in the Keil\TExaSware folder. If you have installed TExaS before and you are using this installer to upgrade to the newest version of TExaS, we suggest you backup any software you have edited/written before installing TExaS.

1) Download TExaS for Labs 2, 5-15 saving the 46M file on your computer.

2) Execute the TExaS_Install.exe file to install TExaS, which will add files to the Keil directory.

A slide show of the process to download and install TExaS can be seen at slide show.

Step 3) Windows drivers for the LaunchPad board
Once Keil and TExaS are installed you will need to install the windows drivers for your Texas Instruments microcontroller board. The process is the same for both the TM4C123 and the TM4C1294 LaunchPads. You will need the actual physical LaunchPad board to complete this step. So if you have ordered your board and it hasn't yet arrived, bookmark this page and come back once your board arrives. Installing drivers can be tricky so here are two alternative methods to installing drivers.

Method 1 uses drivers that were saved on your hard drive when you installed TExaS in step 2). These slide shows demonstrate the process to install windows drivers for the LaunchPad board specific for your operating system: Windows XP, Windows Vista, Windows 7, and Windows 8.

Method 2 uses the official Texas Instruments web site where you can download the drivers, and read the Stellaris Driver Installation Guide (Rev. C) on how to download.
; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDlg_GaoLuWenDuInfo
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "GaoLuCeWen.h"
LastPage=0

ClassCount=6
Class1=CGaoLuCeWenApp
Class2=CGaoLuCeWenDoc
Class3=CGaoLuCeWenView
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Class5=CAboutDlg
Class6=CDlg_GaoLuWenDuInfo
Resource3=IDD_Dlg_GaoLuWenDuInfo

[CLS:CGaoLuCeWenApp]
Type=0
HeaderFile=GaoLuCeWen.h
ImplementationFile=GaoLuCeWen.cpp
Filter=N

[CLS:CGaoLuCeWenDoc]
Type=0
HeaderFile=GaoLuCeWenDoc.h
ImplementationFile=GaoLuCeWenDoc.cpp
Filter=N

[CLS:CGaoLuCeWenView]
Type=0
HeaderFile=GaoLuCeWenView.h
ImplementationFile=GaoLuCeWenView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CGaoLuCeWenView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_MENUITEM32772




[CLS:CAboutDlg]
Type=0
HeaderFile=GaoLuCeWen.cpp
ImplementationFile=GaoLuCeWen.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
Command17=ID_M_GaoLuWenDu
CommandCount=17

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_Dlg_GaoLuWenDuInfo]
Type=1
Class=CDlg_GaoLuWenDuInfo
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LIST1,SysListView32,1350631425
Control4=IDC_BTN_BaoCunDaoShuJvKu,button,1342242816

[CLS:CDlg_GaoLuWenDuInfo]
Type=0
HeaderFile=Dlg_GaoLuWenDuInfo.h
ImplementationFile=Dlg_GaoLuWenDuInfo.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_BTN_BaoCunDaoShuJvKu


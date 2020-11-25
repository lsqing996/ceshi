; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDlg_WenDuInfoModi
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "GaoLuWenDuJianCe.h"
LastPage=0

ClassCount=9
Class1=CGaoLuWenDuJianCeApp
Class2=CGaoLuWenDuJianCeDoc
Class3=CGaoLuWenDuJianCeView
Class4=CMainFrame

ResourceCount=6
Resource1=IDD_ABOUTBOX
Resource2=IDD_DlgWenDuInfo
Class5=CAboutDlg
Class6=CDlgWenDuInfo
Resource3=IDD_DlgAppe
Class7=CDlg_WenDuInfoAppe
Resource4=IDD_DlgModi
Class8=CDlg_WenDuInfoModi
Resource5=IDR_MAINFRAME
Class9=CDlg_WenDuInfoDele
Resource6=IDD_DlgDele

[CLS:CGaoLuWenDuJianCeApp]
Type=0
HeaderFile=GaoLuWenDuJianCe.h
ImplementationFile=GaoLuWenDuJianCe.cpp
Filter=N

[CLS:CGaoLuWenDuJianCeDoc]
Type=0
HeaderFile=GaoLuWenDuJianCeDoc.h
ImplementationFile=GaoLuWenDuJianCeDoc.cpp
Filter=N

[CLS:CGaoLuWenDuJianCeView]
Type=0
HeaderFile=GaoLuWenDuJianCeView.h
ImplementationFile=GaoLuWenDuJianCeView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CGaoLuWenDuJianCeView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_M_WenDuInfo




[CLS:CAboutDlg]
Type=0
HeaderFile=GaoLuWenDuJianCe.cpp
ImplementationFile=GaoLuWenDuJianCe.cpp
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
Command17=ID_M_WenDuInfo
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

[DLG:IDD_DlgWenDuInfo]
Type=1
Class=CDlgWenDuInfo
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LIST1,SysListView32,1350631425
Control4=IDC_BTN_Appe,button,1342242816
Control5=IDC_BTN_Modi,button,1342242816
Control6=IDC_BTN_Dele,button,1342242816

[CLS:CDlgWenDuInfo]
Type=0
HeaderFile=DlgWenDuInfo.h
ImplementationFile=DlgWenDuInfo.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDlgWenDuInfo

[DLG:IDD_DlgAppe]
Type=1
Class=CDlg_WenDuInfoAppe
ControlCount=20
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_EDT_RDO,edit,1350631552
Control12=IDC_EDT_WDT1,edit,1350631552
Control13=IDC_EDT_WDT2,edit,1350631552
Control14=IDC_EDT_WDT3,edit,1350631552
Control15=IDC_EDT_WDT4,edit,1350631552
Control16=IDC_EDT_WDT5,edit,1350631552
Control17=IDC_EDT_WDT6,edit,1350631552
Control18=IDC_EDT_WDT7,edit,1350631552
Control19=IDC_STATIC,static,1342308352
Control20=IDC_EDT_WDT8,edit,1350631552

[CLS:CDlg_WenDuInfoAppe]
Type=0
HeaderFile=Dlg_WenDuInfoAppe.h
ImplementationFile=Dlg_WenDuInfoAppe.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_DlgModi]
Type=1
Class=CDlg_WenDuInfoModi
ControlCount=20
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_EDT_RDO,edit,1350633600
Control12=IDC_EDT_WDT1,edit,1350631552
Control13=IDC_EDT_WDT2,edit,1350631552
Control14=IDC_EDT_WDT3,edit,1350631552
Control15=IDC_EDT_WDT4,edit,1350631552
Control16=IDC_EDT_WDT5,edit,1350631552
Control17=IDC_EDT_WDT6,edit,1350631552
Control18=IDC_EDT_WDT7,edit,1350631552
Control19=IDC_STATIC,static,1342308352
Control20=IDC_EDT_WDT8,edit,1350631552

[CLS:CDlg_WenDuInfoModi]
Type=0
HeaderFile=Dlg_WenDuInfoModi.h
ImplementationFile=Dlg_WenDuInfoModi.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_DlgDele]
Type=1
Class=CDlg_WenDuInfoDele
ControlCount=20
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_EDT_RDO,edit,1350631552
Control12=IDC_EDT_WDT1,edit,1350631552
Control13=IDC_EDT_WDT2,edit,1350631552
Control14=IDC_EDT_WDT3,edit,1350631552
Control15=IDC_EDT_WDT4,edit,1350631552
Control16=IDC_EDT_WDT5,edit,1350631552
Control17=IDC_EDT_WDT6,edit,1350631552
Control18=IDC_EDT_WDT7,edit,1350631552
Control19=IDC_STATIC,static,1342308352
Control20=IDC_EDT_WDT8,edit,1350631552

[CLS:CDlg_WenDuInfoDele]
Type=0
HeaderFile=Dlg_WenDuInfoDele.h
ImplementationFile=Dlg_WenDuInfoDele.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC


; ..\LIB\WINSPOOL.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

ADVANCEDSETUPDIALOG PROTO :DWORD,:DWORD,:DWORD,:DWORD
AbortPrinter PROTO :DWORD
AddFormA PROTO :DWORD,:DWORD,:DWORD
AddForm equ <AddFormA>

AddJobA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AddJob equ <AddJobA>

AddMonitorA PROTO :DWORD,:DWORD,:DWORD
AddMonitor equ <AddMonitorA>

AddPerMachineConnectionA PROTO :DWORD,:DWORD,:DWORD,:DWORD
AddPerMachineConnection equ <AddPerMachineConnectionA>

AddPortA PROTO :DWORD,:DWORD,:DWORD
AddPort equ <AddPortA>

AddPortExA PROTO :DWORD,:DWORD,:DWORD,:DWORD
AddPortEx equ <AddPortExA>

AddPrintProcessorA PROTO :DWORD,:DWORD,:DWORD,:DWORD
AddPrintProcessor equ <AddPrintProcessorA>

AddPrintProvidorA PROTO :DWORD,:DWORD,:DWORD
AddPrintProvidor equ <AddPrintProvidorA>

AddPrinterA PROTO :DWORD,:DWORD,:DWORD
AddPrinter equ <AddPrinterA>

AddPrinterConnectionA PROTO :DWORD
AddPrinterConnection equ <AddPrinterConnectionA>

AddPrinterConnectionUI PROTO :DWORD,:DWORD,:DWORD
AddPrinterDriverA PROTO :DWORD,:DWORD,:DWORD
AddPrinterDriver equ <AddPrinterDriverA>

AddPrinterDriverExA PROTO :DWORD,:DWORD,:DWORD,:DWORD
AddPrinterDriverEx equ <AddPrinterDriverExA>

AdvancedDocumentPropertiesA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AdvancedDocumentProperties equ <AdvancedDocumentPropertiesA>

AdvancedSetupDialog PROTO :DWORD,:DWORD,:DWORD,:DWORD
ClosePrinter PROTO :DWORD
ClusterSplClose PROTO :DWORD
ClusterSplIsAlive PROTO :DWORD
ClusterSplOpen PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ConfigurePortA PROTO :DWORD,:DWORD,:DWORD
ConfigurePort equ <ConfigurePortA>

ConnectToPrinterDlg PROTO :DWORD,:DWORD
ConvertAnsiDevModeToUnicodeDevmode PROTO :DWORD,:DWORD,:DWORD,:DWORD
ConvertUnicodeDevModeToAnsiDevmode PROTO :DWORD,:DWORD,:DWORD,:DWORD
CreatePrinterIC PROTO :DWORD,:DWORD
DEVICECAPABILITIES PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DEVICEMODE PROTO :DWORD,:DWORD,:DWORD,:DWORD
DeleteFormA PROTO :DWORD,:DWORD
DeleteForm equ <DeleteFormA>

DeleteMonitorA PROTO :DWORD,:DWORD,:DWORD
DeleteMonitor equ <DeleteMonitorA>

DeletePerMachineConnectionA PROTO :DWORD,:DWORD
DeletePerMachineConnection equ <DeletePerMachineConnectionA>

DeletePortA PROTO :DWORD,:DWORD,:DWORD
DeletePort equ <DeletePortA>

DeletePrintProcessorA PROTO :DWORD,:DWORD,:DWORD
DeletePrintProcessor equ <DeletePrintProcessorA>

DeletePrintProvidorA PROTO :DWORD,:DWORD,:DWORD
DeletePrintProvidor equ <DeletePrintProvidorA>

DeletePrinter PROTO :DWORD
DeletePrinterConnectionA PROTO :DWORD
DeletePrinterConnection equ <DeletePrinterConnectionA>

DeletePrinterDataA PROTO :DWORD,:DWORD
DeletePrinterData equ <DeletePrinterDataA>

DeletePrinterDataExA PROTO :DWORD,:DWORD,:DWORD
DeletePrinterDataEx equ <DeletePrinterDataExA>

DeletePrinterDriverA PROTO :DWORD,:DWORD,:DWORD
DeletePrinterDriver equ <DeletePrinterDriverA>

DeletePrinterDriverExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DeletePrinterDriverEx equ <DeletePrinterDriverExA>

DeletePrinterIC PROTO :DWORD
DeletePrinterKeyA PROTO :DWORD,:DWORD
DeletePrinterKey equ <DeletePrinterKeyA>

DevQueryPrint PROTO :DWORD,:DWORD,:DWORD
DevQueryPrintEx PROTO :DWORD
DeviceCapabilitiesA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DeviceCapabilities equ <DeviceCapabilitiesA>

DeviceMode PROTO :DWORD,:DWORD,:DWORD,:DWORD
DevicePropertySheets PROTO :DWORD,:DWORD
DocumentEvent PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DocumentPropertiesA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DocumentProperties equ <DocumentPropertiesA>

DocumentPropertySheets PROTO :DWORD,:DWORD
EXTDEVICEMODE PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EndDocPrinter PROTO :DWORD
EndPagePrinter PROTO :DWORD
EnumFormsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumForms equ <EnumFormsA>

EnumJobsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumJobs equ <EnumJobsA>

EnumMonitorsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumMonitors equ <EnumMonitorsA>

EnumPerMachineConnectionsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumPerMachineConnections equ <EnumPerMachineConnectionsA>

EnumPortsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumPorts equ <EnumPortsA>

EnumPrintProcessorDatatypesA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumPrintProcessorDatatypes equ <EnumPrintProcessorDatatypesA>

EnumPrintProcessorsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumPrintProcessors equ <EnumPrintProcessorsA>

EnumPrinterDataA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumPrinterData equ <EnumPrinterDataA>

EnumPrinterDataExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumPrinterDataEx equ <EnumPrinterDataExA>

EnumPrinterDriversA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumPrinterDrivers equ <EnumPrinterDriversA>

EnumPrinterKeyA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumPrinterKey equ <EnumPrinterKeyA>

EnumPrinterPropertySheets PROTO :DWORD,:DWORD,:DWORD,:DWORD
EnumPrintersA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumPrinters equ <EnumPrintersA>

ExtDeviceMode PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FindClosePrinterChangeNotification PROTO :DWORD
FindFirstPrinterChangeNotification PROTO :DWORD,:DWORD,:DWORD,:DWORD
FindNextPrinterChangeNotification PROTO :DWORD,:DWORD,:DWORD,:DWORD
FreePrinterNotifyInfo PROTO :DWORD
GetDefaultPrinterA PROTO :DWORD,:DWORD
GetDefaultPrinter equ <GetDefaultPrinterA>

GetFormA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetForm equ <GetFormA>

GetJobA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetJob equ <GetJobA>

GetPrintProcessorDirectoryA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetPrintProcessorDirectory equ <GetPrintProcessorDirectoryA>

GetPrinterA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetPrinter equ <GetPrinterA>

GetPrinterDataA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetPrinterData equ <GetPrinterDataA>

GetPrinterDataExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetPrinterDataEx equ <GetPrinterDataExA>

GetPrinterDriverA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetPrinterDriver equ <GetPrinterDriverA>

GetPrinterDriverDirectoryA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetPrinterDriverDirectory equ <GetPrinterDriverDirectoryA>

GetPrinterHTMLViewA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetPrinterHTMLView equ <GetPrinterHTMLViewA>

GetPrinterWebInformation PROTO :DWORD,:DWORD,:DWORD,:DWORD
InitializeDll PROTO :DWORD,:DWORD,:DWORD
LoadPrinterDriver PROTO :DWORD
OpenPrinterA PROTO :DWORD,:DWORD,:DWORD
OpenPrinter equ <OpenPrinterA>

PlayGdiScriptOnPrinterIC PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PrinterMessageBoxA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PrinterMessageBox equ <PrinterMessageBoxA>

PrinterProperties PROTO :DWORD,:DWORD
QueryRemoteFonts PROTO :DWORD,:DWORD,:DWORD
QuerySpoolMode PROTO :DWORD,:DWORD,:DWORD
ReadPrinter PROTO :DWORD,:DWORD,:DWORD,:DWORD
ResetPrinterA PROTO :DWORD,:DWORD
ResetPrinter equ <ResetPrinterA>

ScheduleJob PROTO :DWORD,:DWORD
SeekPrinter PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetAllocFailCount PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetDefaultPrinterA PROTO :DWORD
SetDefaultPrinter equ <SetDefaultPrinterA>

SetFormA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetForm equ <SetFormA>

SetJobA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetJob equ <SetJobA>

SetPortA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetPort equ <SetPortA>

SetPrinterA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetPrinter equ <SetPrinterA>

SetPrinterDataA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetPrinterData equ <SetPrinterDataA>

SetPrinterDataExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetPrinterDataEx equ <SetPrinterDataExA>

SetPrinterHTMLViewA PROTO :DWORD,:DWORD,:DWORD
SetPrinterHTMLView equ <SetPrinterHTMLViewA>

SpoolerInit PROTO
SpoolerPrinterEvent PROTO :DWORD,:DWORD,:DWORD,:DWORD
StartDocDlgA PROTO :DWORD,:DWORD
StartDocDlg equ <StartDocDlgA>

StartDocPrinterA PROTO :DWORD,:DWORD,:DWORD
StartDocPrinter equ <StartDocPrinterA>

StartPagePrinter PROTO :DWORD
WaitForPrinterChange PROTO :DWORD,:DWORD
WritePrinter PROTO :DWORD,:DWORD,:DWORD,:DWORD


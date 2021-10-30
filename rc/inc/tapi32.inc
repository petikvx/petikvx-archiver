; ..\LIB\TAPI32.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~~

GetTheFunctionPtr PROTO :DWORD,:DWORD
lineAccept PROTO :DWORD,:DWORD,:DWORD
lineAddProviderA PROTO :DWORD,:DWORD,:DWORD
lineAddProvider equ <lineAddProviderA>

lineAddToConference PROTO :DWORD,:DWORD
lineAgentSpecific PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineAnswer PROTO :DWORD,:DWORD,:DWORD
lineBlindTransferA PROTO :DWORD,:DWORD,:DWORD
lineBlindTransfer equ <lineBlindTransferA>

lineClose PROTO :DWORD
lineCompleteCall PROTO :DWORD,:DWORD,:DWORD,:DWORD
lineCompleteTransfer PROTO :DWORD,:DWORD,:DWORD,:DWORD
lineConfigDialogA PROTO :DWORD,:DWORD,:DWORD
lineConfigDialog equ <lineConfigDialogA>

lineConfigDialogEditA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineConfigDialogEdit equ <lineConfigDialogEditA>

lineConfigProvider PROTO :DWORD,:DWORD
lineDeallocateCall PROTO :DWORD
lineDevSpecific PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineDevSpecificFeature PROTO :DWORD,:DWORD,:DWORD,:DWORD
lineDialA PROTO :DWORD,:DWORD,:DWORD
lineDial equ <lineDialA>

lineDrop PROTO :DWORD,:DWORD,:DWORD
lineForwardA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineForward equ <lineForwardA>

lineGatherDigitsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineGatherDigits equ <lineGatherDigitsA>

lineGenerateDigitsA PROTO :DWORD,:DWORD,:DWORD,:DWORD
lineGenerateDigits equ <lineGenerateDigitsA>

lineGenerateTone PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineGetAddressCapsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineGetAddressCaps equ <lineGetAddressCapsA>

lineGetAddressIDA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineGetAddressID equ <lineGetAddressIDA>

lineGetAddressStatusA PROTO :DWORD,:DWORD,:DWORD
lineGetAddressStatus equ <lineGetAddressStatusA>

lineGetAgentActivityListA PROTO :DWORD,:DWORD,:DWORD
lineGetAgentActivityList equ <lineGetAgentActivityListA>

lineGetAgentCapsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineGetAgentCaps equ <lineGetAgentCapsA>

lineGetAgentGroupListA PROTO :DWORD,:DWORD,:DWORD
lineGetAgentGroupList equ <lineGetAgentGroupListA>

lineGetAgentStatusA PROTO :DWORD,:DWORD,:DWORD
lineGetAgentStatus equ <lineGetAgentStatusA>

lineGetAppPriorityA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineGetAppPriority equ <lineGetAppPriorityA>

lineGetCallInfoA PROTO :DWORD,:DWORD
lineGetCallInfo equ <lineGetCallInfoA>

lineGetCallStatus PROTO :DWORD,:DWORD
lineGetConfRelatedCalls PROTO :DWORD,:DWORD
lineGetCountryA PROTO :DWORD,:DWORD,:DWORD
lineGetCountry equ <lineGetCountryA>

lineGetDevCapsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineGetDevCaps equ <lineGetDevCapsA>

lineGetDevConfigA PROTO :DWORD,:DWORD,:DWORD
lineGetDevConfig equ <lineGetDevConfigA>

lineGetIDA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineGetID equ <lineGetIDA>

lineGetIconA PROTO :DWORD,:DWORD,:DWORD
lineGetIcon equ <lineGetIconA>

lineGetLineDevStatusA PROTO :DWORD,:DWORD
lineGetLineDevStatus equ <lineGetLineDevStatusA>

lineGetMessage PROTO :DWORD,:DWORD,:DWORD
lineGetNewCalls PROTO :DWORD,:DWORD,:DWORD,:DWORD
lineGetNumRings PROTO :DWORD,:DWORD,:DWORD
lineGetProviderListA PROTO :DWORD,:DWORD
lineGetProviderList equ <lineGetProviderListA>

lineGetRequestA PROTO :DWORD,:DWORD,:DWORD
lineGetRequest equ <lineGetRequestA>

lineGetStatusMessages PROTO :DWORD,:DWORD,:DWORD
lineGetTranslateCapsA PROTO :DWORD,:DWORD,:DWORD
lineGetTranslateCaps equ <lineGetTranslateCapsA>

lineHandoffA PROTO :DWORD,:DWORD,:DWORD
lineHandoff equ <lineHandoffA>

lineHold PROTO :DWORD
lineInitialize PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineInitializeExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineInitializeEx equ <lineInitializeExA>

lineMakeCallA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineMakeCall equ <lineMakeCallA>

lineMonitorDigits PROTO :DWORD,:DWORD
lineMonitorMedia PROTO :DWORD,:DWORD
lineMonitorTones PROTO :DWORD,:DWORD,:DWORD
lineNegotiateAPIVersion PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineNegotiateExtVersion PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineOpenA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineOpen equ <lineOpenA>

lineParkA PROTO :DWORD,:DWORD,:DWORD,:DWORD
linePark equ <lineParkA>

linePickupA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
linePickup equ <linePickupA>

linePrepareAddToConferenceA PROTO :DWORD,:DWORD,:DWORD
linePrepareAddToConference equ <linePrepareAddToConferenceA>

lineProxyMessage PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineProxyResponse PROTO :DWORD,:DWORD,:DWORD
lineRedirectA PROTO :DWORD,:DWORD,:DWORD
lineRedirect equ <lineRedirectA>

lineRegisterRequestRecipient PROTO :DWORD,:DWORD,:DWORD,:DWORD
lineReleaseUserUserInfo PROTO :DWORD
lineRemoveFromConference PROTO :DWORD
lineRemoveProvider PROTO :DWORD,:DWORD
lineSecureCall PROTO :DWORD
lineSendUserUserInfo PROTO :DWORD,:DWORD,:DWORD
lineSetAgentActivity PROTO :DWORD,:DWORD,:DWORD
lineSetAgentGroup PROTO :DWORD,:DWORD,:DWORD
lineSetAgentState PROTO :DWORD,:DWORD,:DWORD,:DWORD
lineSetAppPriorityA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineSetAppPriority equ <lineSetAppPriorityA>

lineSetAppSpecific PROTO :DWORD,:DWORD
lineSetCallData PROTO :DWORD,:DWORD,:DWORD
lineSetCallParams PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineSetCallPrivilege PROTO :DWORD,:DWORD
lineSetCallQualityOfService PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineSetCallTreatment PROTO :DWORD,:DWORD
lineSetCurrentLocation PROTO :DWORD,:DWORD
lineSetDevConfigA PROTO :DWORD,:DWORD,:DWORD,:DWORD
lineSetDevConfig equ <lineSetDevConfigA>

lineSetLineDevStatus PROTO :DWORD,:DWORD,:DWORD
lineSetMediaControl PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineSetMediaMode PROTO :DWORD,:DWORD
lineSetNumRings PROTO :DWORD,:DWORD,:DWORD
lineSetStatusMessages PROTO :DWORD,:DWORD,:DWORD
lineSetTerminal PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineSetTollListA PROTO :DWORD,:DWORD,:DWORD,:DWORD
lineSetTollList equ <lineSetTollListA>

lineSetupConferenceA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineSetupConference equ <lineSetupConferenceA>

lineSetupTransferA PROTO :DWORD,:DWORD,:DWORD
lineSetupTransfer equ <lineSetupTransferA>

lineShutdown PROTO :DWORD
lineSwapHold PROTO :DWORD,:DWORD
lineTranslateAddressA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineTranslateAddress equ <lineTranslateAddressA>

lineTranslateDialogA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineTranslateDialog equ <lineTranslateDialogA>

lineUncompleteCall PROTO :DWORD,:DWORD
lineUnhold PROTO :DWORD
lineUnparkA PROTO :DWORD,:DWORD,:DWORD,:DWORD
lineUnpark equ <lineUnparkA>

phoneClose PROTO :DWORD
phoneConfigDialogA PROTO :DWORD,:DWORD,:DWORD
phoneConfigDialog equ <phoneConfigDialogA>

phoneDevSpecific PROTO :DWORD,:DWORD,:DWORD
phoneGetButtonInfoA PROTO :DWORD,:DWORD,:DWORD
phoneGetButtonInfo equ <phoneGetButtonInfoA>

phoneGetData PROTO :DWORD,:DWORD,:DWORD,:DWORD
phoneGetDevCapsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
phoneGetDevCaps equ <phoneGetDevCapsA>

phoneGetDisplay PROTO :DWORD,:DWORD
phoneGetGain PROTO :DWORD,:DWORD,:DWORD
phoneGetHookSwitch PROTO :DWORD,:DWORD
phoneGetIDA PROTO :DWORD,:DWORD,:DWORD
phoneGetID equ <phoneGetIDA>

phoneGetIconA PROTO :DWORD,:DWORD,:DWORD
phoneGetIcon equ <phoneGetIconA>

phoneGetLamp PROTO :DWORD,:DWORD,:DWORD
phoneGetMessage PROTO :DWORD,:DWORD,:DWORD
phoneGetRing PROTO :DWORD,:DWORD,:DWORD
phoneGetStatusA PROTO :DWORD,:DWORD
phoneGetStatus equ <phoneGetStatusA>

phoneGetStatusMessages PROTO :DWORD,:DWORD,:DWORD,:DWORD
phoneGetVolume PROTO :DWORD,:DWORD,:DWORD
phoneInitialize PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
phoneInitializeExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
phoneInitializeEx equ <phoneInitializeExA>

phoneNegotiateAPIVersion PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
phoneNegotiateExtVersion PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
phoneOpen PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
phoneSetButtonInfoA PROTO :DWORD,:DWORD,:DWORD
phoneSetButtonInfo equ <phoneSetButtonInfoA>

phoneSetData PROTO :DWORD,:DWORD,:DWORD,:DWORD
phoneSetDisplay PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
phoneSetGain PROTO :DWORD,:DWORD,:DWORD
phoneSetHookSwitch PROTO :DWORD,:DWORD,:DWORD
phoneSetLamp PROTO :DWORD,:DWORD,:DWORD
phoneSetRing PROTO :DWORD,:DWORD,:DWORD
phoneSetStatusMessages PROTO :DWORD,:DWORD,:DWORD,:DWORD
phoneSetVolume PROTO :DWORD,:DWORD,:DWORD
phoneShutdown PROTO :DWORD
tapiGetLocationInfoA PROTO :DWORD,:DWORD
tapiGetLocationInfo equ <tapiGetLocationInfoA>

tapiPlaySound PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
tapiRequestDrop PROTO :DWORD,:DWORD
tapiRequestMakeCallA PROTO :DWORD,:DWORD,:DWORD,:DWORD
tapiRequestMakeCall equ <tapiRequestMakeCallA>

tapiRequestMediaCallA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
tapiRequestMediaCall equ <tapiRequestMediaCallA>



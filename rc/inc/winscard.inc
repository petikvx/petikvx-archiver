; ..\LIB\WINSCARD.LIB PROTOTYPES
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

SCardAddReaderToGroupA PROTO :DWORD,:DWORD,:DWORD
SCardAddReaderToGroup equ <SCardAddReaderToGroupA>

SCardBeginTransaction PROTO :DWORD
SCardCancel PROTO :DWORD
SCardConnectA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SCardConnect equ <SCardConnectA>

SCardControl PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SCardDisconnect PROTO :DWORD,:DWORD
SCardEndTransaction PROTO :DWORD,:DWORD
SCardEstablishContext PROTO :DWORD,:DWORD,:DWORD,:DWORD
SCardForgetCardTypeA PROTO :DWORD,:DWORD
SCardForgetCardType equ <SCardForgetCardTypeA>

SCardForgetReaderA PROTO :DWORD,:DWORD
SCardForgetReader equ <SCardForgetReaderA>

SCardForgetReaderGroupA PROTO :DWORD,:DWORD
SCardForgetReaderGroup equ <SCardForgetReaderGroupA>

SCardFreeMemory PROTO :DWORD,:DWORD
SCardGetAttrib PROTO :DWORD,:DWORD,:DWORD,:DWORD
SCardGetProviderIdA PROTO :DWORD,:DWORD,:DWORD
SCardGetProviderId equ <SCardGetProviderIdA>

SCardGetStatusChangeA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SCardGetStatusChange equ <SCardGetStatusChangeA>

SCardIntroduceCardTypeA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SCardIntroduceCardType equ <SCardIntroduceCardTypeA>

SCardIntroduceReaderA PROTO :DWORD,:DWORD,:DWORD
SCardIntroduceReader equ <SCardIntroduceReaderA>

SCardIntroduceReaderGroupA PROTO :DWORD,:DWORD
SCardIntroduceReaderGroup equ <SCardIntroduceReaderGroupA>

SCardListCardsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SCardListCards equ <SCardListCardsA>

SCardListInterfacesA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SCardListInterfaces equ <SCardListInterfacesA>

SCardListReaderGroupsA PROTO :DWORD,:DWORD,:DWORD
SCardListReaderGroups equ <SCardListReaderGroupsA>

SCardListReadersA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SCardListReaders equ <SCardListReadersA>

SCardLocateCardsA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SCardLocateCards equ <SCardLocateCardsA>

SCardReconnect PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SCardReleaseContext PROTO :DWORD
SCardRemoveReaderFromGroupA PROTO :DWORD,:DWORD,:DWORD
SCardRemoveReaderFromGroup equ <SCardRemoveReaderFromGroupA>

SCardSetAttrib PROTO :DWORD,:DWORD,:DWORD,:DWORD
SCardState PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SCardStatusA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SCardStatus equ <SCardStatusA>

SCardTransmit PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD


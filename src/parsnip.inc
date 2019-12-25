#define db .db
_FindAlphaDn    = 4A47h
_FindAlphaUp    = 4A44h
_RclAns         = 4AD7h
_ChkFindSym     = 42F1h
_DispHL         = 4507h
_CreateTempStr  = 4324h
_SetParserHook  = 5026h
_CreateVar      = 4E70h
_CreateAppVar   = 4E6Ah
_CreatePict     = 4333h
_EnoughMem      = 42FDh
_InsertMem      = 42F7h
_Get_Tok_Strng  = 4594h
_DelMem         = 4357h
_JForceCmdNoChar= 4027h
_JError         = 44D7h
_DelVarArc      = 4FC6h
_CreateStrng    = 4327h
_CreateReal     = 430Fh
_SetXXXXOP2     = 4792h
_Arc_Unarc      = 4FD8h
_ConvKeyToTok   = 4A02h
_GetKeyRetOff   = 500Bh
_RunIndicOff    = 4570h
_DeleteTempPrograms = 5041h
_MemChk         = 42E5h
_clrTxtShd      = 454Ch
_saveCmdShadow  = 4573h
_PutS           = 450Ah
_OP5ToOP1       = 413Bh
_OP1ToOP5       = 4153h
_NewLine        = 452Eh
_HomeUp         = 4558h
_ClrScrnFull    = 4546h
appErr1         = 984Dh
appErr2         = 985Ah
cxErrorEP       = 8595h
curRow          = 844Bh
curCol          = 844Ch
kbdScanCode     = 843Fh
basic_prog      = 9652h
progStart       = 965Bh
parsePtr        = 965Dh
progEnd         = 965Fh
parserHookPtr   = 9BACh
OP5             = 84A4h
OP4             = 8499h
OP3             = 848Eh
OP2             = 8483h
intmask         = %00001011
invlogic        = 2
gflags          = 33
flags           = 89F0h
OP1             = 8478h
saveSScreen     = 86ECh
textShadow      = 8508h
plotSScreen     = 9340h
gbuf            = plotSScreen
appBackUpScreen = 9872h

progPtr         = 9830h
FPS             = 9824h
OPS             = 9828h
#define rMov9ToOP1    20h
#define rFindSym    10h
moduleExec      = 86ECh
tok_NegRelPtr   = $EE


;===============================================================
;RAM used by Parsnip:
;     108 bytes for pointer vars stored in smallEditRAM
;      10 bytes for TempWords stored in OP6 and 1 byte of OP5
;       2 bytes for text position stored in OP6
;      10 bytes for Status stored in iMathPtr1
;===============================================================
smallEditRAM        = 90D3h  ;108 bytes
pvars               = smallEditRAM
ThetaPrimeVar       = pvars+53*2  ;913Dh ;

iMathPtr1           = 84D3h  ;10 bytes
iMathPtr2           = 84D5h
iMathPtr3           = 84D7h
iMathPtr4           = 84D9h
iMathPtr5           = 84DBh
VATPtr              = iMathPtr1
VATPtr_next         = iMathPtr2
OP6                 = 84AFh  ;11 bytes
cmdShadow           = 966Eh  ;128 bytes
pTemp               = 982Eh ;bottom of named vars VAT

TempWord1   = OP6-1       ;2       2
TempWord2   = TempWord1+2 ;2       4
TempWord3   = TempWord2+2 ;2       6
TempWord4   = TempWord3+2 ;2       8
TempWord5   = TempWord4+2 ;2      10
textRow     = TempWord5+2 ;1      11
textCol     = textRow+1   ;1      12

TextPauseTime=appErr2         ;1
GrayBufPtr  = TextPauseTime+1 ;2
Ans         = GrayBufPtr+2    ;2
OutputLogic = Ans+2           ;1
SPSave      = OutputLogic+2   ;2

BufPtr              = 84E7h

parseError  = 84EBh           ;2
FontPointer = parseError+2    ;2

GrayMask    = 8080h   ;2
GrayRotate  = GrayMask+2    ;1 upper 5 bits are for text modes
gbuf_temp   = GrayRotate+2  ;2
;seed1       = gbuf_temp+2   ;2
;seed2       = seed1+2       ;2
main_menu_cursor    = gbuf_temp+2
main_menu_cursor_max= main_menu_cursor+1
main_menu_index     = main_menu_cursor_max+1
k_save      = main_menu_index+2
k_count     = k_save+1
k_delay     = k_count+1
qmarkvar    = k_delay+1
operandstack_ptr     = qmarkvar+2
operandstack_bottom  = operandstack_ptr+2
operandstack_top     = operandstack_bottom+2
opstack_ptr          = operandstack_top+2
heap_ptr             = opstack_ptr+2
heap_bottom          = heap_ptr+2
heap_top             = heap_bottom+2



size_of_buffer  = qmarkvar+2
start_of_prog   = size_of_buffer+2
end_of_src      = start_of_prog
data_top        = end_of_src
buffer_top      = data_top


ramCode       = 8100h
SetLinePix    = ramCode
interruptLoc  = 8A8Ah
tempSwapArea  = 82A5h
TSA           = 82A5h

type_param_end= 0
type_ui8      = 1
type_ui16     = 2
type_ui32     = 3
type_fixed88  = 4
type_fixed1616= 5
type_var      = 6
type_true     = 7
type_false    = 8
type_tstr_ref = 9
type_raw      = 10
type_str      = 11
type_str_ref  = 12
type_single   = 13
type_xfloat   = 14

X_CONST_0     = 6
X_CONST_1     = 7
X_CONST_PI    = 0
X_CONST_e     = 1
;==============================
;Flags
;==============================
InternalFlag    = 33
SlowTextFlag    =   0
IntActiveFlag   =   1
FactorialFlag   =   2
errorChecking   =   3
grayFlag        =   4   ;this determines the checker pattern for the next gray object drawn
bit32           =   5   ;This determines if the output was 32-bit or not
Mod2nd          =   6
grayMode        =   7   ;This determines the checker pattern for grayscale mode

CursorFlags     = 12
CursorActive    =   3

UserFlags       = 34
InvertTextFlag  =   0
InvertLCDFlag   =   1
OnBlockFlag     =   2
baseInput       =   3
pxlBoundsRes    =   4
SignedText      =   5
;    =   6
;    =   7

ParticleFlag    = 35
InternalFlag2   = 35
Xis0            = 0
inputflag       = 0
Xis95           = 1
Yis0            = 2
Yis63           = 3
OffScrn         = 4
usingfloat      = 5


onFlags         = 9        ;on key flags
onInterrupt     =   4      ;1=on key interrupt request

curFlags        = 12       ;Cursor
fmtEdit         =   0      ;1=format number for editing
curAble         =   2      ;1=cursor flash is enabled
curOn           =   3      ;1=cursor is showing
curLock         =   4      ;1=cursor is locked off
cmdVirgin       =   5      ;1=nothing has been typed in cmd bfr
;----------------------------------------------------------------------
indicFlags        = 18         ;Indicator flags
indicRun          =   0        ;1=run indicator ON
shiftFlags        = 18         ;[2nd] and [ALPHA] flags
shift2nd          =   3        ;1=[2nd] has been pressed
shiftAlpha        =   4        ;1=[ALPHA] has been pressed
shiftLwrAlph      =   5        ;1=lower case, 0=upper case
shiftALock        =   6        ;1=alpha lock has been pressed
shiftKeepAlph     =   7        ;1=cannot cancel alpha shift
